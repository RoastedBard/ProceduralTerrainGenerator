#ifndef MAINFORM_H
#define MAINFORM_H

#include <QtGui/QMainWindow>
#include "ui_mainform.h"
#include "PerlinNoise.h"
#include "Generators/RandomGeneratorsManager.h"

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    MainForm(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~MainForm();

private slots:
    void _generateHeightmapButtonClicked();
    void _randomGeneratorsComboBoxIndexChanged();
    void _buildTerrainButtonClicked();
    void _travelButtonCLicked();
    void _saveHeightmap();
    void _loadHeightMap();

private:
    void _sendDataToRandomGenerator();

private:
    PerlinNoise _perlinNoise;
    RandomGeneratorsManager _rndMngr;
    Terrain *_terrain;

private:
    Ui::MainForm ui;
};

#endif // MAINFORM_H
