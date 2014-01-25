// ListElementDelegate.qml
import QtQuick 2.0

Rectangle {
    id: listElementDelegate
    //anchors.top: parent.bottom
    width: parent.width
    height: 25
    property alias firstName: firstName.text
    property alias lastName: lastName.text
    signal deleteItem()
    Text {
        id: firstName
    }
    Text {
        id: seperator
        text: ", "
        anchors.left: firstName.right
    }
    Text {
        id: lastName
        anchors.left: seperator.right
    }

}
