QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/CommandProcessors/CommandProcessor1.cpp \
        src/CommandProcessors/CommandProcessor2.cpp \
        src/CommandProcessors/CommandProcessor3.cpp \
        src/CommandProcessors/CommandProcessor4.cpp \
        src/CommandProcessors/CommandProcessor5.cpp \
        src/CommandProcessors/CommandProcessor6.cpp \
        src/CommandProcessors/CommandProcessor7.cpp \
        src/CommandProcessors/CommandProcessorFactory.cpp \
        src/EndOfFileException.cpp \
        src/Shapes/ShapeFactory.cpp \
        src/SyntaxError.cpp \
        src/InvalidParams.cpp \
        src/Shapes/Circle.cpp \
        src/InputHandler.cpp \
        src/Point.cpp \
        src/Shapes/Polygon.cpp \
        src/Shapes/Rectangle.cpp \
        src/Shapes/Shape.cpp \
        src/Shapes/Triangle.cpp \
        src/main.cpp

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/include/Shapes
INCLUDEPATH += $$PWD/include/CommandProcessors

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    include/SyntaxError.h \
    include/InvalidParams.h \
    include/Shapes/Circle.h \
    include/InputHandler.h \
    include/Point.h \
    include/Shapes/Polygon.h \
    include/Shapes/Rectangle.h \
    include/Shapes/Shape.h \
    include/Shapes/Triangle.h \
    include/CommandProcessors/CommandProcessorFactory.h \
    include/CommandProcessors/CommandProcessor.h \
    include/CommandProcessors/CommandProcessor1.h \
    include/CommandProcessors/CommandProcessor2.h \
    include/CommandProcessors/CommandProcessor3.h \
    include/CommandProcessors/CommandProcessor4.h \
    include/CommandProcessors/CommandProcessor5.h \
    include/CommandProcessors/CommandProcessor6.h \
    include/CommandProcessors/CommandProcessor7.h \
    include/Shapes/ShapeFactory.h \
    include/EndOfFileException.h
