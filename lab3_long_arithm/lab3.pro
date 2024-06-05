QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/CalculatorCommands/CalculatorEvalCommand.cpp \
    src/Expression.cpp \
    src/Invokers/GUI_Invoker.cpp \
    src/InputWidgets.cpp \
    src/Functions/Operators.cpp \
    src/LongFloat.cpp \
    src/main.cpp \
    src/MainWindow.cpp

HEADERS += \
    include/CalculatorCommands/CalculatorEvalCommand.h \
    include/Command.h \
    include/Errors/InvalidNumberError.h \
    include/Errors/InvalidOperandError.h \
    include/Errors/InvalidOperatorError.h \
    include/Errors/StackEmptyError.h \
    include/Errors/SyntaxError.h \
    include/Errors/ZeroDivisionError.h \
    include/Expression.h \
    include/Functions/Functions.h \
    include/Functions/Operators.h \
    include/Invokers/Invoker.h \
    include/Invokers/Calculator.h \
    include/Invokers/GUI_Invoker.h \
    include/GUICommands/GUIBackCommand.h \
    include/GUICommands/GUIClearCommand.h \
    include/GUICommands/GUIDeleteCommand.h \
    include/GUICommands/GUIEvalCommand.h \
    include/GUICommands/GUIMemoryCommands/GUIMemoryArithmeticCommand.h \
    include/GUICommands/GUIMemoryCommands/GUIMemoryClearCommand.h \
    include/GUICommands/GUIMemoryCommands/GUIMemoryMinusCommand.h \
    include/GUICommands/GUIMemoryCommands/GUIMemoryPlusCommand.h \
    include/GUICommands/GUIMemoryCommands/GUIMemoryReadCommand.h \
    include/GUICommands/GUISaveExprCommand.h \
    include/InputWidgets.h \
    include/LongFloat.h \
    include/MainWindow.h \
    include/Singleton.h \

FORMS += \
    MainWindow.ui

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/include/GUICommands
INCLUDEPATH += $$PWD/include/GUICommands/GUIMemoryCommands
INCLUDEPATH += $$PWD/include/CalculatorCommands
INCLUDEPATH += $$PWD/include/Invokers
INCLUDEPATH += $$PWD/include/Functions
INCLUDEPATH += $$PWD/include/Errors

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
