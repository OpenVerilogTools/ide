#pragma once

#include <QTextEdit.h>

class TextEditor : public QTextEdit {
public:
    explicit TextEditor(QWidget* parent = nullptr) : QTextEdit(parent) {};
private:

};