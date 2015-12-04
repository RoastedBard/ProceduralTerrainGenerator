#pragma once

#include "Terrain.h"
#include "Camera.h"
#include "Enumerations.h"
#include <QGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <qtimer.h>
#include <qelapsedtimer.h>
#include <memory.h>

class TerrainVisualizationWidget : public QGLWidget
{
    Q_OBJECT
public:
    TerrainVisualizationWidget(QWidget *parent = 0);
    ~TerrainVisualizationWidget(void);

public:
    void paintGL();
    void initializeGL();

public:
    void setTerrain(Terrain *terrain);

public:
    void stopTraveling();
    void startTraveling();

public slots:
    void updateCamera();

protected:
    bool eventFilter(QObject *object, QEvent *e);

private:
    Terrain* _terrain;
    Camera   _camera;

private:
    bool     _isTerrainLoaded;
    int           _keyPressed;
    QTimer        _timer;
    float         _fps;
};

