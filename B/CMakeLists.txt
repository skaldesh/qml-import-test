# Define the target name.
set(MODULE_TARGET B)

# Define a new static library target.
qt_add_library(${MODULE_TARGET} STATIC)

# Create a new QML module.
qt_add_qml_module(${MODULE_TARGET}
    URI B
    QML_FILES B.js
    RESOURCES qmldir
    NO_GENERATE_QMLDIR
    NO_CACHEGEN
)
