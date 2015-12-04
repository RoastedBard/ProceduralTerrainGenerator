#include "LoadShaders.h"
#include "Terrain.h"
#include <glm\glm.hpp>
#include <iostream>
#include <qmessagebox.h>

Terrain::Terrain(void)
{
    _scaleFactor = 50;
}


Terrain::~Terrain(void)
{
    glDeleteVertexArrays(1, &_oglData.vertexArrayObject);
    glDeleteBuffers(1, &_oglData.vertexBufferObject);
    glDeleteBuffers(1, &_oglData.colorBufferObject);
    glDeleteBuffers(1, &_oglData.elementBufferObject);
    glDeleteProgram(_oglData.shaderProgramId);
}

void Terrain::loadHeightMapFromFile(QString filename)
{
    if(!_heightMap.load(filename))
    {
        return;
    }
}

void Terrain::loadHeightMapFromImage(QImage image)
{
    _heightMap = image;
}

void Terrain::initTerrainData()
{
    int heightsSize = _heightMap.height();

    _heights.resize(heightsSize);
    for(int i = 0; i < _heights.size(); i++)
        _heights[i].resize(heightsSize);

    _maxHeight = 0;

    for(int i = 0; i < _heights.size(); i++)
    {
        for(int j = 0; j < _heights.size(); j++)
        {
            uint h = qRed(_heightMap.pixel(i, j));
            
            float height = ((float)h / 255.0) * _scaleFactor;

            if(height > _maxHeight)
                _maxHeight = height;

            Vertex3f vert(i, height, j);
            _terrainMeshVertices.push_back(vert);
        }
    }

    _computeIndices();
    _orderIndices();
}

void Terrain::_computeIndices()
{
    int indexArraySize = _heightMap.height();

    _indices.resize(indexArraySize);
    for(int i = 0; i < indexArraySize; i++)
        _indices[i].resize(indexArraySize);

    int n = 0;

    for(int i = 0; i < _indices.size(); i++)
    {
        for(int j = 0; j < _indices.size(); j++)
        {
            _indices[i][j] = n;
            n++;
        }
    }
}

void Terrain::_orderIndices()
{
    _restartIndex = _indices.back().back() + 1;

    _indexBufferSize = (_indices.size() * 2) * (_indices.size() - 1);

    _indexBuffer.resize(_indexBufferSize);

    int n = 0; //indexBuffer counter

    for(int i = 0; i < _indices.size() - 1; i++)
    {
        for(int j = 0; j < _indices.size() - 1; j++)
        {
            _indexBuffer[n] = _indices[i][j]; n++;
            _indexBuffer[n] = _indices[i + 1][j]; n++;
        }

        _indexBuffer[n] = _restartIndex; n++;
    }
}

std::vector<unsigned int> Terrain::getIndexBuffer() const
{
    return _indexBuffer;
}

int Terrain::getRestartIndex() const
{
    return _restartIndex;
}

int Terrain::getIndexBufferSize() const
{
    return _indexBufferSize;
}

std::vector<Vertex3f> Terrain::getTerrainMeshVertices() const
{
    return _terrainMeshVertices;
}

void Terrain::setScaleFactor(int scaleFactor)
{
    if(scaleFactor < 1)
        _scaleFactor = 1;
    else
        _scaleFactor = scaleFactor;
}

void Terrain::setMvp(glm::mat4 mvp)
{
    _MVP = mvp;
}

void Terrain::init()
{
    glGenVertexArrays(1, &_oglData.vertexArrayObject);
    glBindVertexArray(_oglData.vertexArrayObject);

    glGenBuffers(1, &_oglData.vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, _oglData.vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex3f) * _terrainMeshVertices.size(), &_terrainMeshVertices.front(), GL_STATIC_DRAW);

    glGenBuffers(1, &_oglData.elementBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _oglData.elementBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * _indexBuffer.size(), &_indexBuffer.front(), GL_STATIC_DRAW);

    _oglData.shaderProgramId = _loadShaders("vertex.txt", "fragment.txt");

    _oglData.mvpId = glGetUniformLocation(_oglData.shaderProgramId, "MVP");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);

    glDepthFunc(GL_LESS);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_PRIMITIVE_RESTART);
    glPrimitiveRestartIndex(_restartIndex);
}

void Terrain::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Set up the viewing transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-100.0f); //Centre volume and move back
    //glRotatef(-m_xRotation, 0.0f, 1.0f, 0.0f);
    //glRotatef(-m_yRotation, 1.0f, 0.0f, 0.0f);
    //glTranslatef(-32.0f,-32.0f,-32.0f); //Centre volume and move back

    glUseProgram(_oglData.shaderProgramId);

    glUniformMatrix4fv(_oglData.mvpId, 1, GL_FALSE, &_MVP[0][0]);

    GLuint maxHeightId = glGetUniformLocation(_oglData.shaderProgramId, "maxHeight");
    glUniform1f(maxHeightId, _maxHeight);

    glBindBuffer(GL_ARRAY_BUFFER, _oglData.vertexBufferObject);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _oglData.elementBufferObject);
    
    glDrawElements(GL_TRIANGLE_STRIP, _indexBufferSize, GL_UNSIGNED_INT, NULL);

    glDisableVertexAttribArray(0);
}

void Terrain::cleanUp()
{
    glDeleteVertexArrays(1, &_oglData.vertexArrayObject);
    glDeleteBuffers(1, &_oglData.vertexBufferObject);
    glDeleteBuffers(1, &_oglData.colorBufferObject);
    glDeleteBuffers(1, &_oglData.elementBufferObject);
    glDeleteProgram(_oglData.shaderProgramId);
}
