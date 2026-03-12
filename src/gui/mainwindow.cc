#include "mainwindow.h"

#include <QLabel>
#include <QSplitter>

#include "sidebar.h"
#include "texteditor.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("IDE");
    resize(800, 600);

    QLabel* label = new QLabel("OpenVerilogTools");

    QSplitter* sidebarSplitter = new QSplitter;
    SideBar* sidebar = new SideBar(sidebarSplitter);

    QSplitter* editorSplitter = new QSplitter(Qt::Vertical);
    TextEditor* textEditor = new TextEditor(editorSplitter);

    sidebarSplitter->addWidget(sidebar);
    sidebarSplitter->addWidget(editorSplitter);

    editorSplitter->addWidget(textEditor);
    editorSplitter->addWidget(label); // placeholder for terminal

    setCentralWidget(sidebarSplitter);
}
