/**
 * nLine
 * 
 * Copyright (c) 2024 Wahtari GmbH
 * All rights reserved
 */

// Qt imports.
#include <QDirIterator>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QStringLiteral>
#include <QUrl>

// A debug function to print all files contained within the Qt resource system.
// Sometimes, it is just not clear where certain files are added, so this can help.
void printQtResources(bool ignoreQtProject=false) {
    QDirIterator it(":", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QFileInfo next = it.nextFileInfo();
        if (next.isDir() || (ignoreQtProject && next.filePath().startsWith(":/qt-project.org"))) {
            continue;
        }
        qDebug() << next.filePath();
    }
}

int main(int argc, char *argv[]) {
    // Do not remove.
    printQtResources(true);

    // Create the application from the args.
    // Must be a QApplication so we can use charts.
    QApplication app(argc, argv);

    // Create the engine.
    QQmlApplicationEngine engine;

    // Connect to the object creaton failed signal.
    // Quit, if such an error occurs.
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection
    );

    // Load the main qml file.
    engine.load(QUrl(QString::fromStdString("./Main.qml")));

    // Run the app.
    return app.exec();
}
