#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_content_scroll_area();
    setup_task_scroll_area();
}

void MainWindow::setup_content_scroll_area()
{
    QWidget *widget_for_adding_vbox_in_scroll_area = new QWidget();
    vbox_for_text_labels = new QVBoxLayout();
    vbox_for_text_labels->setAlignment(Qt::AlignTop);
    widget_for_adding_vbox_in_scroll_area->setLayout(vbox_for_text_labels);
    ui->content_scroll_area->setWidget(widget_for_adding_vbox_in_scroll_area);
}

void MainWindow::setup_task_scroll_area()
{
    QWidget *widget_for_adding_vbox_in_scroll_area = new QWidget();
    vbox_for_checkboxes = new QVBoxLayout();
    vbox_for_checkboxes->setAlignment(Qt::AlignTop);
    widget_for_adding_vbox_in_scroll_area->setLayout(vbox_for_checkboxes);
    ui->todo_scroll_area->setWidget(widget_for_adding_vbox_in_scroll_area);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    command_line = ui->command_line;
    QString qtext = command_line->toPlainText();

    if (qtext.startsWith(":todo"))
    {
        QCheckBox *cb = new QCheckBox();
        cb->setText(qtext);
        cb->setStyleSheet("color:black; background-color: lightgrey; border: 2px solid black; border-radius: 5px; padding: 10px; font-size: 16px;");
        vbox_for_checkboxes->addWidget(cb);
    }
    else if (qtext.startsWith(":today")) {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if (qtext.startsWith(":cal")) {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QLabel *l = new QLabel();
        l->setText(qtext);
        l->setStyleSheet("color:black; background-color: lightgrey; border: 2px solid black; border-radius: 5px; padding: 10px; font-size: 16px;");
        vbox_for_text_labels->addWidget(l);
    }
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    qDebug() << date << "\n";
}

