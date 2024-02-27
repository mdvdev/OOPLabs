QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Circle.cpp \
        CircleController.cpp \
        InputHandler.cpp \
        Point.cpp \
        Polygon.cpp \
        PolygonController.cpp \
        Rectangle.cpp \
        RectangleController.cpp \
        Shape.cpp \
        ShapeControllerFactory.cpp \
        Triangle.cpp \
        TriangleController.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Circle.h \
    CircleController.h \
    Exception.h \
    InputHandler.h \
    Point.h \
    Polygon.h \
    PolygonController.h \
    Rectangle.h \
    RectangleController.h \
    Shape.h \
    ShapeController.h \
    ShapeControllerFactory.h \
    ShapeType.h \
    Triangle.h \
    TriangleController.h
