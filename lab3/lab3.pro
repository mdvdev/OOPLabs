QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/EvalCommand.cpp \
    src/InputWidgets.cpp \
    src/MathFunctions.cpp \
    src/main.cpp \
    src/MainWindow.cpp

HEADERS += \
    include/Calculator.h \
    include/CalculatorEvalCommand.h \
    include/Command.h \
    include/Expression.h \
    include/GUIDeleteCommand.h \
    include/GUIEvalCommand.h \
    include/GUISaveExprCommand.h \
    include/GUI_Invoker.h \
    include/InputWidgets.h \
    include/Invoker.h \
    include/MainWindow.h \
    include/MathFunctions.h

FORMS += \
    MainWindow.ui

INCLUDEPATH += $$PWD/include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
