import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import A
import B

ApplicationWindow {
    id: root

    width: 1920
    height: 1080
    visible: true

    // Application initialization.
    Component.onCompleted: {
        console.log("Calling A from Main")
        A.test()
        console.log("Calling B from Main")
        B.test()
    }
}
