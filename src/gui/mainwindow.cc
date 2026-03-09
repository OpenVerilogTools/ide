#include "mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("IDE");
    resize(800, 600);

    QLabel* label = new QLabel("OpenVerilogTools", this);
    setCentralWidget(label);
}
