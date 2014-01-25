TARGET = QSqlTableModel_with_QML
QT += qml quick sql
CONFIG += c++11

HEADERS = \
    dbhelper.h \
    proxyqsqltablemodel.h
SOURCES = main.cpp \
    dbhelper.cpp \
    proxyqsqltablemodel.cpp
RESOURCES += QSqlTableModel_with_QML.qrc

target.path = $${OUT_PWD}
INSTALLS += target

OTHER_FILES += \
    ./qml/*.qml \


