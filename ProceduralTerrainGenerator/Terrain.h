#pragma once
#include "OpenGLData.h"
#include "Vertex3f.h"
#include <vector>
#include <qimage.h>
#include <glm\glm.hpp>

class Terrain
{
public:
    void					  loadHeightMapFromImage(QImage image);
    void					  loadHeightMapFromFile(QString filename);
    void                      initTerrainData();
    std::vector<Vertex3f>     getTerrainMeshVertices() const;
    void                      setScaleFactor(int scaleFactor);
    int                       getRestartIndex() const;
    std::vector<unsigned int> getIndexBuffer() const;
    int                       getIndexBufferSize() const;
    void                      setMvp(glm::mat4 mvp);
    void					  cleanUp();

public:
    void init();
    void draw();

public:
    Terrain(void);
    ~Terrain(void);

private:
    void _computeIndices();
    void _orderIndices();

private:
    QImage                                 _heightMap;
    std::vector< std::vector<float> >        _heights;
    std::vector<Vertex3f>                  _terrainMeshVertices;
    int                                    _scaleFactor;
    std::vector< std::vector<unsigned int> > _indices;
    std::vector<unsigned int>              _indexBuffer;
    int                                    _restartIndex;
    int                                    _indexBufferSize;
    OGLData                                _oglData;
    glm::mat4                              _MVP;
    float                                  _maxHeight;
    glm::vec4                              _ambient;

};

