# qml-import-test
A minimal reproducible example of an issue regarding module imports from javascript resources.  

## Build
- Navigate to the root of this project
- `cmake -B "build" -S .`
- `make -C build`

## Run
- `build/qmlImportTest-app`

## Output
```
qml: Calling A from Main
qml: Calling B from A
qml: Hello from B
qml: Calling B from Main
qml: Hello from B
```
Now modify the message printed inside `B.test()` and **restart the app without building**
```
qml: Calling A from Main
qml: Calling B from A
qml: Hello from B
qml: Calling B from Main
qml: Hello from B, MODIFIED
```
Expected to see both messages of B being modified, but only the one loaded from within the main module has been updated.
