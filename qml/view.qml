import QtQuick 2.0

ListView {
    id: listView
    width: 270; height: 480
    model: cppPersonsModel
    delegate: ListElementDelegate {
        id: listItem
        firstName: firstname
        lastName: lastname
        onDeleteItem: listView.model.remove(index)
    }
}



