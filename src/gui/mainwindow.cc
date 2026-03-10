#include "mainwindow.h"

#include <QLabel>
#include <QSplitter>

#include "sidebar.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("IDE");
    resize(800, 600);

    QLabel* label = new QLabel("OpenVerilogTools");

    QSplitter* splitter = new QSplitter;
    SideBar* sidebar = new SideBar(splitter);

    splitter->addWidget(sidebar);
    splitter->addWidget(label);

    setCentralWidget(splitter);
}
