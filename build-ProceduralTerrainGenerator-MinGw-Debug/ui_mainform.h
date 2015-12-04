/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include "terrainvisualizationwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QAction *actionSave_Heightmap;
    QAction *actionLoad_Heightmap;
    QWidget *centralWidget;
    QTabWidget *viewTabWidget;
    QWidget *heightmapViewTab;
    QLabel *heightMapLabel;
    QWidget *terrainViewTab;
    TerrainVisualizationWidget *terrainViewWidget;
    QTabWidget *attributesTabWidget;
    QWidget *heightMapAttributesTab;
    QFrame *frame_2;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *aSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *sStartSpinBox;
    QLabel *label_3;
    QDoubleSpinBox *lambdaSpinBox;
    QLabel *label_4;
    QDoubleSpinBox *muSpinBox;
    QLabel *label_5;
    QDoubleSpinBox *sigmaSpinBox;
    QLabel *label_6;
    QDoubleSpinBox *epsilonSpinBox;
    QLabel *label_7;
    QDoubleSpinBox *etaSpinBox;
    QLabel *label_8;
    QDoubleSpinBox *gammaSpinBox;
    QComboBox *randomGeneratorComboBox;
    QFrame *frame;
    QLabel *label_9;
    QSpinBox *noiseZoomFactorSpinBox;
    QLabel *label_10;
    QSpinBox *SizeOfHeightmapSpinBox;
    QPushButton *generateHeightmapButton;
    QWidget *terrainAttributesTab;
    QFrame *frame_3;
    QLabel *label_11;
    QSpinBox *scaleFactorSpinBox;
    QFrame *frame_4;
    QPushButton *travelButton;
    QCheckBox *fullscreenCheckBox;
    QPushButton *buildTerrainPushButton;
    QFrame *frame_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->setEnabled(true);
        MainForm->resize(993, 655);
        MainForm->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainForm->setDocumentMode(false);
        MainForm->setTabShape(QTabWidget::Rounded);
        actionSave_Heightmap = new QAction(MainForm);
        actionSave_Heightmap->setObjectName(QString::fromUtf8("actionSave_Heightmap"));
        actionSave_Heightmap->setCheckable(true);
        actionLoad_Heightmap = new QAction(MainForm);
        actionLoad_Heightmap->setObjectName(QString::fromUtf8("actionLoad_Heightmap"));
        actionLoad_Heightmap->setCheckable(true);
        centralWidget = new QWidget(MainForm);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        viewTabWidget = new QTabWidget(centralWidget);
        viewTabWidget->setObjectName(QString::fromUtf8("viewTabWidget"));
        viewTabWidget->setGeometry(QRect(5, 11, 800, 620));
        viewTabWidget->setTabShape(QTabWidget::Triangular);
        heightmapViewTab = new QWidget();
        heightmapViewTab->setObjectName(QString::fromUtf8("heightmapViewTab"));
        heightMapLabel = new QLabel(heightmapViewTab);
        heightMapLabel->setObjectName(QString::fromUtf8("heightMapLabel"));
        heightMapLabel->setGeometry(QRect(0, -1, 800, 600));
        heightMapLabel->setAlignment(Qt::AlignCenter);
        viewTabWidget->addTab(heightmapViewTab, QString());
        terrainViewTab = new QWidget();
        terrainViewTab->setObjectName(QString::fromUtf8("terrainViewTab"));
        terrainViewWidget = new TerrainVisualizationWidget(terrainViewTab);
        terrainViewWidget->setObjectName(QString::fromUtf8("terrainViewWidget"));
        terrainViewWidget->setGeometry(QRect(0, -1, 800, 600));
        terrainViewWidget->setMouseTracking(false);
        terrainViewWidget->setFocusPolicy(Qt::NoFocus);
        terrainViewWidget->setAutoFillBackground(false);
        viewTabWidget->addTab(terrainViewTab, QString());
        attributesTabWidget = new QTabWidget(centralWidget);
        attributesTabWidget->setObjectName(QString::fromUtf8("attributesTabWidget"));
        attributesTabWidget->setGeometry(QRect(810, 11, 181, 620));
        attributesTabWidget->setLayoutDirection(Qt::LeftToRight);
        attributesTabWidget->setTabPosition(QTabWidget::North);
        attributesTabWidget->setTabShape(QTabWidget::Triangular);
        attributesTabWidget->setElideMode(Qt::ElideRight);
        attributesTabWidget->setUsesScrollButtons(false);
        attributesTabWidget->setDocumentMode(false);
        attributesTabWidget->setTabsClosable(false);
        attributesTabWidget->setMovable(true);
        heightMapAttributesTab = new QWidget();
        heightMapAttributesTab->setObjectName(QString::fromUtf8("heightMapAttributesTab"));
        frame_2 = new QFrame(heightMapAttributesTab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(8, 34, 159, 254));
        frame_2->setLayoutDirection(Qt::LeftToRight);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        layoutWidget = new QWidget(frame_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 145, 232));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        aSpinBox = new QDoubleSpinBox(layoutWidget);
        aSpinBox->setObjectName(QString::fromUtf8("aSpinBox"));
        aSpinBox->setEnabled(false);
        aSpinBox->setDecimals(5);
        aSpinBox->setValue(12.3457);

        formLayout->setWidget(0, QFormLayout::FieldRole, aSpinBox);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        label_2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sStartSpinBox = new QDoubleSpinBox(layoutWidget);
        sStartSpinBox->setObjectName(QString::fromUtf8("sStartSpinBox"));
        sStartSpinBox->setEnabled(false);
        sStartSpinBox->setDecimals(5);
        sStartSpinBox->setValue(0.56789);

        formLayout->setWidget(1, QFormLayout::FieldRole, sStartSpinBox);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lambdaSpinBox = new QDoubleSpinBox(layoutWidget);
        lambdaSpinBox->setObjectName(QString::fromUtf8("lambdaSpinBox"));
        lambdaSpinBox->setEnabled(false);
        lambdaSpinBox->setDecimals(5);

        formLayout->setWidget(2, QFormLayout::FieldRole, lambdaSpinBox);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        muSpinBox = new QDoubleSpinBox(layoutWidget);
        muSpinBox->setObjectName(QString::fromUtf8("muSpinBox"));
        muSpinBox->setEnabled(false);
        muSpinBox->setDecimals(5);

        formLayout->setWidget(3, QFormLayout::FieldRole, muSpinBox);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        sigmaSpinBox = new QDoubleSpinBox(layoutWidget);
        sigmaSpinBox->setObjectName(QString::fromUtf8("sigmaSpinBox"));
        sigmaSpinBox->setEnabled(false);
        sigmaSpinBox->setDecimals(5);

        formLayout->setWidget(4, QFormLayout::FieldRole, sigmaSpinBox);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        epsilonSpinBox = new QDoubleSpinBox(layoutWidget);
        epsilonSpinBox->setObjectName(QString::fromUtf8("epsilonSpinBox"));
        epsilonSpinBox->setEnabled(false);
        epsilonSpinBox->setDecimals(5);

        formLayout->setWidget(5, QFormLayout::FieldRole, epsilonSpinBox);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        etaSpinBox = new QDoubleSpinBox(layoutWidget);
        etaSpinBox->setObjectName(QString::fromUtf8("etaSpinBox"));
        etaSpinBox->setEnabled(false);
        etaSpinBox->setDecimals(5);

        formLayout->setWidget(6, QFormLayout::FieldRole, etaSpinBox);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        gammaSpinBox = new QDoubleSpinBox(layoutWidget);
        gammaSpinBox->setObjectName(QString::fromUtf8("gammaSpinBox"));
        gammaSpinBox->setEnabled(false);
        gammaSpinBox->setDecimals(5);

        formLayout->setWidget(7, QFormLayout::FieldRole, gammaSpinBox);

        randomGeneratorComboBox = new QComboBox(heightMapAttributesTab);
        randomGeneratorComboBox->setObjectName(QString::fromUtf8("randomGeneratorComboBox"));
        randomGeneratorComboBox->setGeometry(QRect(8, 8, 159, 20));
        randomGeneratorComboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
        randomGeneratorComboBox->setFrame(true);
        frame = new QFrame(heightMapAttributesTab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(8, 294, 159, 109));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(33, 6, 88, 22));
        noiseZoomFactorSpinBox = new QSpinBox(frame);
        noiseZoomFactorSpinBox->setObjectName(QString::fromUtf8("noiseZoomFactorSpinBox"));
        noiseZoomFactorSpinBox->setGeometry(QRect(20, 30, 121, 19));
        noiseZoomFactorSpinBox->setMinimum(2);
        noiseZoomFactorSpinBox->setMaximum(512);
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(32, 55, 91, 22));
        SizeOfHeightmapSpinBox = new QSpinBox(frame);
        SizeOfHeightmapSpinBox->setObjectName(QString::fromUtf8("SizeOfHeightmapSpinBox"));
        SizeOfHeightmapSpinBox->setGeometry(QRect(20, 80, 121, 19));
        SizeOfHeightmapSpinBox->setMinimum(2);
        SizeOfHeightmapSpinBox->setMaximum(512);
        generateHeightmapButton = new QPushButton(heightMapAttributesTab);
        generateHeightmapButton->setObjectName(QString::fromUtf8("generateHeightmapButton"));
        generateHeightmapButton->setGeometry(QRect(8, 550, 159, 40));
        attributesTabWidget->addTab(heightMapAttributesTab, QString());
        terrainAttributesTab = new QWidget();
        terrainAttributesTab->setObjectName(QString::fromUtf8("terrainAttributesTab"));
        frame_3 = new QFrame(terrainAttributesTab);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(7, 8, 159, 59));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Plain);
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(53, 6, 88, 22));
        scaleFactorSpinBox = new QSpinBox(frame_3);
        scaleFactorSpinBox->setObjectName(QString::fromUtf8("scaleFactorSpinBox"));
        scaleFactorSpinBox->setGeometry(QRect(20, 30, 121, 19));
        scaleFactorSpinBox->setMinimum(1);
        scaleFactorSpinBox->setMaximum(100);
        frame_4 = new QFrame(terrainAttributesTab);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(7, 77, 159, 89));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Plain);
        travelButton = new QPushButton(frame_4);
        travelButton->setObjectName(QString::fromUtf8("travelButton"));
        travelButton->setGeometry(QRect(10, 10, 136, 40));
        fullscreenCheckBox = new QCheckBox(frame_4);
        fullscreenCheckBox->setObjectName(QString::fromUtf8("fullscreenCheckBox"));
        fullscreenCheckBox->setGeometry(QRect(45, 63, 70, 17));
        buildTerrainPushButton = new QPushButton(terrainAttributesTab);
        buildTerrainPushButton->setObjectName(QString::fromUtf8("buildTerrainPushButton"));
        buildTerrainPushButton->setGeometry(QRect(8, 550, 159, 40));
        frame_5 = new QFrame(terrainAttributesTab);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(7, 176, 159, 63));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Plain);
        pushButton_4 = new QPushButton(frame_5);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(31, 9, 44, 44));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_4->setFont(font2);
        pushButton_4->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QtTerrainGenerator/Resources/Translate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(30, 30));
        pushButton_5 = new QPushButton(frame_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(81, 9, 43, 44));
        attributesTabWidget->addTab(terrainAttributesTab, QString());
        MainForm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainForm);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 993, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainForm->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave_Heightmap);
        menuFile->addAction(actionLoad_Heightmap);

        retranslateUi(MainForm);
        QObject::connect(actionSave_Heightmap, SIGNAL(triggered()), MainForm, SLOT(_saveHeightmap()));
        QObject::connect(actionLoad_Heightmap, SIGNAL(triggered()), MainForm, SLOT(_loadHeightMap()));

        viewTabWidget->setCurrentIndex(0);
        attributesTabWidget->setCurrentIndex(0);
        randomGeneratorComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "QtTerrainGenerator", 0, QApplication::UnicodeUTF8));
        actionSave_Heightmap->setText(QApplication::translate("MainForm", "Save Heightmap", 0, QApplication::UnicodeUTF8));
        actionLoad_Heightmap->setText(QApplication::translate("MainForm", "Load Heightmap", 0, QApplication::UnicodeUTF8));
        heightMapLabel->setText(QString());
        viewTabWidget->setTabText(viewTabWidget->indexOf(heightmapViewTab), QApplication::translate("MainForm", "Heightmap View", 0, QApplication::UnicodeUTF8));
        viewTabWidget->setTabText(viewTabWidget->indexOf(terrainViewTab), QApplication::translate("MainForm", "Terrain View", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        attributesTabWidget->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("MainForm", "A", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainForm", "Si", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainForm", "\316\273", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainForm", "\316\274", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainForm", "\317\203", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainForm", "\316\265", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainForm", "\316\267", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainForm", "\316\263", 0, QApplication::UnicodeUTF8));
        randomGeneratorComboBox->clear();
        randomGeneratorComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainForm", "\320\240\320\260\320\262\320\275\320\276\320\274\320\265\321\200\320\275\321\213\320\265 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\265 \321\207\320\270\321\201\320\273\320\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainForm", "\320\235\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265 \320\275\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\320\265 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\265 \321\207\320\270\321\201\320\273\320\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainForm", "\320\255\320\272\321\201\320\277\320\276\320\275\320\265\320\275\321\206\320\270\320\260\320\273\321\214\320\275\321\213\320\265 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\265 \321\207\320\270\321\201\320\273\320\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainForm", "\320\233\320\276\320\263\320\260\321\200\320\270\321\204\320\274\320\270\321\207\320\265\321\201\320\272\320\270 \320\275\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\320\265 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\265 \321\207\320\270\321\201\320\273\320\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainForm", "\320\224\320\266\320\276\320\275\321\201\320\276\320\275\320\260 S\320\262", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainForm", "\320\224\320\266\320\276\320\275\321\201\320\276\320\275\320\260 Su", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("MainForm", "Noise zoom factor", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainForm", "Size of heightmap", 0, QApplication::UnicodeUTF8));
        generateHeightmapButton->setText(QApplication::translate("MainForm", "Generate Heightmap", 0, QApplication::UnicodeUTF8));
        attributesTabWidget->setTabText(attributesTabWidget->indexOf(heightMapAttributesTab), QApplication::translate("MainForm", "Heightmap Attributes", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainForm", "Scale factor", 0, QApplication::UnicodeUTF8));
        travelButton->setText(QApplication::translate("MainForm", "Travel", 0, QApplication::UnicodeUTF8));
        fullscreenCheckBox->setText(QApplication::translate("MainForm", "Fullscreen", 0, QApplication::UnicodeUTF8));
        buildTerrainPushButton->setText(QApplication::translate("MainForm", "Build Terrain", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        attributesTabWidget->setTabText(attributesTabWidget->indexOf(terrainAttributesTab), QApplication::translate("MainForm", "Terrain Attributes", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainForm", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
