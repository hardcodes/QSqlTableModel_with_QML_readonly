# QSqlTableModel_with_QML_readonly

If you use widgets in Qt, it can be quite easy to use SQL databases. If you use QML with Qt the story gets an aftertaste. Things that were easy before are not anymore.

## A new king in town

With QML the rules (or shall I say roles?) have changed. If you present a `QSqlTableModel` to a QML view via `QQmlContext::setContextProperty`, the result is something like that’s all Greek to me.

If you write your own C++ classes that should expose data to the QML world, you will face the `Q_PROPERTY` or `Q_INVOKABLE` macro. Those macros provide the glue between both worlds, or in other words: things known to the property system can be reached in the QML world. For whatever reason a `QSqlTableModel` does not build the needed property bindings on its own. Thus the QML world does not know anything about those objects or at least not enough or the C++ world does not know how to respond to questions from the QML side.

The keyword is roles here. Those are the vocabulary that QML uses to squeeze some data out of a C++ object. Since Qt does not do the job for you, we will find a way to do it on our own. The fact that you have to do something on your own is battlesome but does not change the situation in the end. If you want to use any descendants of `QAbstractItemModel`, that’s your way to go.

## build and run

This is a desktop project, on OSX just clone, build and run in QtCreator - no jumping through hoops needed.