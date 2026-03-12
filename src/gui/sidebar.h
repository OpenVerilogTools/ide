#pragma once

#include <QDir>
#include <QFileSystemModel>
#include <QString>
#include <QTreeView>

class SideBar : public QTreeView {
   public:
    explicit SideBar(QWidget* parent = nullptr, const QString& dir = ".");

    void openPath(const QString& path);

   private:
    QDir dir_;
    QFileSystemModel* model_;
};