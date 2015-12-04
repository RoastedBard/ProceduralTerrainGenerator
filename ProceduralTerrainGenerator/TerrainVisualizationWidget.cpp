#include "TerrainVisualizationWidget.h"
#include <qmessagebox.h>

TerrainVisualizationWidget::TerrainVisualizationWidget(QWidget *parent) : QGLWidget(parent)
{
	_isTerrainLoaded = false;

	_terrain = NULL;

    _keyPressed = KEY_RELEASED;

    this->format().setSwapInterval(1);

	setMouseTracking(true);
	installEventFilter(this);

	_fps = 1.f / 60.f;

	connect(&_timer, SIGNAL(timeout()), this, SLOT(updateCamera()));
    _timer.setInterval(16);
}


TerrainVisualizationWidget::~TerrainVisualizationWidget(void)
{
	//delete _terrain;
}

void TerrainVisualizationWidget::updateCamera()
{
	QPoint p = mapFromGlobal(QCursor::pos());

	_camera.computeMatrices(p.x(), p.y(), _fps, _keyPressed);

	glm::mat4 ViewMatrix = _camera.getViewMatrix();
	glm::mat4 ProjectionMatrix = _camera.getProjectionMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0);

    _terrain->setMvp(ProjectionMatrix * ViewMatrix * ModelMatrix);

	QPoint center = mapToGlobal(QPoint(this->width() / 2, this->height() / 2));
	QCursor::setPos(center);

	updateGL();
}

void TerrainVisualizationWidget::startTraveling()
{
	if(_terrain == NULL)
	{
		QMessageBox::information(this, "Error", "Build terrain first!");
		return;
	}

	_timer.start();
	setFocus();
}

void TerrainVisualizationWidget::stopTraveling()
{
	_timer.stop();
	clearFocus();
}

bool TerrainVisualizationWidget::eventFilter(QObject *object, QEvent *e)
{
	if(object == this)
	{
		QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);

		if(e->type() == QKeyEvent::KeyPress)
		{
            if(keyEvent->key() == Qt::Key_W)
			{
                _keyPressed = KEY_PRESSED_UP;
			}
            if(keyEvent->key() == Qt::Key_S)
			{
                _keyPressed = KEY_PRESSED_DOWN;
			}
            if(keyEvent->key() == Qt::Key_A)
			{
                _keyPressed = KEY_PRESSED_LEFT;
			}
            if(keyEvent->key() == Qt::Key_D)
			{
                _keyPressed = KEY_PRESSED_RIGHT;
			}
            if(keyEvent->key() == Qt::Key_1)
			{
				glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); //wireframe
			}
            if(keyEvent->key() == Qt::Key_2)
			{
				glPolygonMode( GL_FRONT_AND_BACK, GL_FILL ); //Normal mode
			}
            if(keyEvent->key() == Qt::Key_Escape)
			{
				stopTraveling();
			}
			return true;
		}

		if(e->type() == QKeyEvent::KeyRelease)
		{
            if(keyEvent->key() == Qt::Key_W ||
               keyEvent->key() == Qt::Key_S ||
               keyEvent->key() == Qt::Key_A ||
               keyEvent->key() == Qt::Key_D)
			   _keyPressed = KEY_RELEASED;

			return true;
		}
	}

	return QWidget::event(e);
}

void TerrainVisualizationWidget::setTerrain(Terrain *terrain)
{
	if(_terrain != NULL)
	{
		_terrain->cleanUp();
        _terrain = NULL;
	}

    _terrain = terrain;
}

void TerrainVisualizationWidget::paintGL()
{
	if(_terrain == NULL)
		return;

	_terrain->draw();
}

void TerrainVisualizationWidget::initializeGL()
{
	glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) 
    {
        return;
    }

	glViewport(0, 0, this->width(), this->height());

	_camera.setScreenDimension(this->width(), this->height());

	glClearColor(3/255.f, 144/255.f, 255, 0.0f);

	if(_terrain != NULL)
	_terrain->init();
}
