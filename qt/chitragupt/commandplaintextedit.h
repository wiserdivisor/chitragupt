#ifndef COMMANDPLAINTEXTEDIT_H
#define COMMANDPLAINTEXTEDIT_H

#include <QPlainTextEdit>
#include <QKeyEvent>

class CommandPlainTextEdit : public QPlainTextEdit {
    Q_OBJECT
public:
    explicit CommandPlainTextEdit(QWidget *parent = nullptr) : QPlainTextEdit(parent) {}
signals:
    void enterPressed();
    void shiftEnterPressed();
protected:
    void keyPressEvent(QKeyEvent *event) override {
        if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
            if(event->modifiers() & Qt::ShiftModifier) {
                emit shiftEnterPressed();
            } else {
                emit enterPressed();
            }
        } else {
            QPlainTextEdit::keyPressEvent(event);
        }
    }

};

#endif // COMMANDPLAINTEXTEDIT_H
