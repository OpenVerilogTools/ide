#include "sidebar.h"

SideBar::SideBar(QWidget* parent, const QString& dir) : QTreeView(parent), dir_(dir) {
    model_ = new QFileSystemModel(this);
    model_->setRootPath(dir);

    setModel(model_);
    setRootIndex(model_->index(dir));
}

void SideBar::openPath(const QString& path) {
    dir_ = QDir(path);  // https://doc.qt.io/qt-6/qdir.html

    if (!dir_.exists()) {
        qWarning("Cannot find the example directory");
        return;
    }

    setRootIndex(model_->index(path));
}