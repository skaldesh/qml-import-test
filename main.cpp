/**
 * nLine
 * 
 * Copyright (c) 2024 Wahtari GmbH
 * All rights reserved
 */

// Qt imports.
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QStringLiteral>
#include <QUrl>

int main(int argc, char *argv[]) {
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
