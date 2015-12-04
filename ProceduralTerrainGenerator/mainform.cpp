#include "mainform.h"
#include "Generators\RandomType.h"
#include <qmessagebox.h>
#include <qfiledialog.h>

MainForm::MainForm(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);

    ui.terrainViewWidget->updateGL();

    _terrain = NULL;

    connect(ui.generateHeightmapButton, SIGNAL(clicked()), this, SLOT(_generateHeightmapButtonClicked()));
    connect(ui.randomGeneratorComboBox, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(_randomGeneratorsComboBoxIndexChanged()));
    connect(ui.buildTerrainPushButton, SIGNAL(clicked()), this, SLOT(_buildTerrainButtonClicked()));
    connect(ui.travelButton, SIGNAL(clicked()), this, SLOT(_travelButtonCLicked()));
}

MainForm::~MainForm()
{
}

void MainForm::_sendDataToRandomGenerator()
{
    switch(ui.randomGeneratorComboBox->currentIndex())
    {
    case UNIFORM_RANDOM_GENERATOR:
        _rndMngr.uniformRndGen.setStartConditions(ui.aSpinBox->value(), ui.sStartSpinBox->value());
        break;

    case NORMAL_RANDOM_GENERATOR:
        _rndMngr.normalRndGen.setStartConditions(ui.aSpinBox->value(), ui.sStartSpinBox->value());
        break;

    case EXPONENTIAL_RANDOM_GENERATOR:
        _rndMngr.expRndGen.setStartConditions(ui.lambdaSpinBox->value(), ui.muSpinBox->value(), ui.aSpinBox->value(), ui.sStartSpinBox->value());
        break;

    case LOGARIFM_RANDOM_GENERATOR:
        _rndMngr.logRndGen.setStartConditions(ui.sigmaSpinBox->value(), ui.muSpinBox->value(), ui.aSpinBox->value(), ui.sStartSpinBox->value());
        break;

    case JOHNSON_SV_RANDOM_GENERATOR:
        _rndMngr.johnsonSvRndGen.setStartConditions(ui.lambdaSpinBox->value(), ui.etaSpinBox->value(), ui.epsilonSpinBox->value(), ui.gammaSpinBox->value(), ui.aSpinBox->value(), ui.sStartSpinBox->value());
        break;

    case JOHNSON_SU_RANDOM_GENERATOR:
        _rndMngr.johnsonSuRndGen.setStartConditions(ui.lambdaSpinBox->value(), ui.etaSpinBox->value(), ui.epsilonSpinBox->value(), ui.gammaSpinBox->value(), ui.aSpinBox->value(), ui.sStartSpinBox->value());
        break;
    }
}

void MainForm::_generateHeightmapButtonClicked()
{
    int selectedGenerator = ui.randomGeneratorComboBox->currentIndex();

    if (selectedGenerator == -1)
    {
        QMessageBox::information(this, "Error", tr("Choose generator type!"));
        return;
    }

    ui.viewTabWidget->setCurrentIndex(0);

    _sendDataToRandomGenerator();

    QImage perlinTexture = _perlinNoise.generatePerlinNoise(ui.SizeOfHeightmapSpinBox->value(), ui.noiseZoomFactorSpinBox->value(), _rndMngr.getCurrent(selectedGenerator));
    ui.heightMapLabel->setPixmap(QPixmap::fromImage(perlinTexture));
}

void MainForm::_buildTerrainButtonClicked()
{
    if(ui.heightMapLabel->pixmap() == NULL)
    {
        QMessageBox::information(this, "Error", "You should generate a heightmap first!");
        return;
    }

    _terrain = new Terrain();

    _terrain->setScaleFactor(ui.scaleFactorSpinBox->value());
    _terrain->loadHeightMapFromImage(ui.heightMapLabel->pixmap()->toImage());
    _terrain->initTerrainData();

    ui.terrainViewWidget->setTerrain(_terrain);

    ui.terrainViewWidget->initializeGL();
    ui.terrainViewWidget->updateCamera();

    ui.viewTabWidget->setCurrentIndex(1);
}

void MainForm::_travelButtonCLicked()
{
    ui.terrainViewWidget->startTraveling();
}

void MainForm::_saveHeightmap()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save heightmap"), "://", "Image files (*.png)");

    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    ui.heightMapLabel->pixmap()->save(&file, "PNG");
    file.close();
}

void MainForm::_loadHeightMap()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open heightmap"), "://", "Image files (*.png)");

    QPixmap pix(filename);

    ui.heightMapLabel->setPixmap(pix);
}

void MainForm::_randomGeneratorsComboBoxIndexChanged()
{
    if (ui.randomGeneratorComboBox->currentIndex() == UNIFORM_RANDOM_GENERATOR || ui.randomGeneratorComboBox->currentIndex() == NORMAL_RANDOM_GENERATOR)
    {
        ui.aSpinBox->setEnabled(true);
        ui.sStartSpinBox->setEnabled(true);
        ui.lambdaSpinBox->setEnabled(false);
        ui.muSpinBox->setEnabled(false);
        ui.sigmaSpinBox->setEnabled(false);
        ui.epsilonSpinBox->setEnabled(false);
        ui.etaSpinBox->setEnabled(false);
        ui.gammaSpinBox->setEnabled(false);
    }
    else if (ui.randomGeneratorComboBox->currentIndex() == EXPONENTIAL_RANDOM_GENERATOR)
    {
        ui.aSpinBox->setEnabled(true);
        ui.sStartSpinBox->setEnabled(true);
        ui.lambdaSpinBox->setEnabled(true);
        ui.muSpinBox->setEnabled(true);
        ui.sigmaSpinBox->setEnabled(false);
        ui.epsilonSpinBox->setEnabled(false);
        ui.etaSpinBox->setEnabled(false);
        ui.gammaSpinBox->setEnabled(false);
    }
    else if (ui.randomGeneratorComboBox->currentIndex() == LOGARIFM_RANDOM_GENERATOR)
    {
        ui.aSpinBox->setEnabled(true);
        ui.sStartSpinBox->setEnabled(true);
        ui.lambdaSpinBox->setEnabled(false);
        ui.muSpinBox->setEnabled(true);
        ui.sigmaSpinBox->setEnabled(true);
        ui.epsilonSpinBox->setEnabled(false);
        ui.etaSpinBox->setEnabled(false);
        ui.gammaSpinBox->setEnabled(false);
    }
    else if (ui.randomGeneratorComboBox->currentIndex() == JOHNSON_SV_RANDOM_GENERATOR || ui.randomGeneratorComboBox->currentIndex() == JOHNSON_SU_RANDOM_GENERATOR)
    {
        ui.aSpinBox->setEnabled(true);
        ui.sStartSpinBox->setEnabled(true);
        ui.lambdaSpinBox->setEnabled(true);
        ui.muSpinBox->setEnabled(false);
        ui.sigmaSpinBox->setEnabled(false);
        ui.epsilonSpinBox->setEnabled(true);
        ui.etaSpinBox->setEnabled(true);
        ui.gammaSpinBox->setEnabled(true);
    }
}
