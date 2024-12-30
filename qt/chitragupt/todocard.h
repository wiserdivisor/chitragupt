#ifndef TODOCARD_H
#define TODOCARD_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>


class TodoCard : public QWidget {
public:
    explicit TodoCard(
        QString description,
        QStringList taglist,
        QWidget *parent = nullptr) : QWidget(parent){

        QVBoxLayout *vl = new QVBoxLayout();

        QCheckBox *cb = new QCheckBox();
        cb->setText("Pending");
        cb->setStyleSheet("color:black; background-color: lightgrey; border: 2px solid black; border-radius: 5px; padding: 10px; font-size: 16px;");
        vl->addWidget(cb);

        QLabel *l = new QLabel();
        l->setText(description);
        l->setWordWrap(true);
        l->setStyleSheet("color:black; background-color: lightgrey; border: 2px solid black; border-radius: 5px; padding: 10px; font-size: 16px;");
        vl->addWidget(l);

        float len = taglist.size();
        int howManyHBoxes = ceil(len/5);
        qDebug() << howManyHBoxes;
        QHBoxLayout *hl = new QHBoxLayout();
        for(const QString &x : taglist) {
            QLabel *t = new QLabel();
            t->setText(x);
            t->setStyleSheet("color:black; background-color: lightblue; border: 2px solid black; border-radius: 5px; padding: 2px; font-size: 12px;");
            hl->addWidget(t);
        }
        vl->addLayout(hl);
        setLayout(vl);
        setStyleSheet("background-color: coral; border: 2px solid black; border-radius: 5px; padding: 2px;");
    }
};

#endif // TODOCARD_H
