# Define the target name.
set(MODULE_TARGET A)

# Define a new static library target.
qt_add_library(${MODULE_TARGET} STATIC)

# Create a new QML module.
qt_add_qml_module(${MODULE_TARGET}
    URI A
    QML_FILES A.js
    RESOURCES qmldir
    NO_GENERATE_QMLDIR
    NO_CACHEGEN
)
