#-------------------------------------------------
#
# Project created by QtCreator 2014-03-14T09:14:26
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProceduralTerrainGenerator
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    TerrainVisualizationWidget.cpp \
    Terrain.cpp \
    PerlinNoise.cpp \
    LoadShaders.cpp \
    Camera.cpp \
    Generators/UniformRandomGenerator.cpp \
    Generators/RandomGeneratorsManager.cpp \
    Generators/NormalRandomGenerator.cpp \
    Generators/LogarifmNormalRandomGenerator.cpp \
    Generators/JohnsonSVRandomGenerator.cpp \
    Generators/JohnsonSURandomGenerator.cpp \
    Generators/ExponentalRandomGenerator.cpp

HEADERS  += mainform.h \
    TerrainVisualizationWidget.h \
    Vertex3f.h \
    Terrain.h \
    PerlinNoise.h \
    OpenGLData.h \
    LoadShaders.h \
    Enumerations.h \
    Camera.h \
    Generators/UniformRandomGenerator.h \
    Generators/RandomType.h \
    Generators/RandomGeneratorsManager.h \
    Generators/NormalRandomGenerator.h \
    Generators/LogarifmNormalRandomGenerator.h \
    Generators/JohnsonSVRandomGenerator.h \
    Generators/JohnsonSURandomGenerator.h \
    Generators/IRandomGenerator.h \
    Generators/ExponentalRandomGenerator.h

FORMS    += \
    mainform.ui

LIBS += -llibglew32

RESOURCES += \
    mainform.qrc

INCLUDEPATH += D:\LIBS\glm
