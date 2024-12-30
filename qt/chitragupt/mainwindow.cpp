#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_content_scroll_area();
    setup_task_scroll_area();
    connect(ui->command_line, &CommandPlainTextEdit::enterPressed, this, &MainWindow::executeCommand);
    connect(ui->command_line, &CommandPlainTextEdit::shiftEnterPressed, this, &MainWindow::newlineCommand);
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

void MainWindow::newlineCommand()
{
    QFont f("Segoe UI",12);
    ui->command_line->setFont(f);
    ui->command_line->appendPlainText("");
}

void MainWindow::executeCommand()
{
    command_line = ui->command_line;
    QString qtext = command_line->toPlainText();
    if(qtext.isEmpty()){
        return;
    }
    int firstSpaceChar = qtext.indexOf(" ");
    QString command = qtext.mid(0,firstSpaceChar);
    QString content = qtext.mid(firstSpaceChar+1);

    int firstNewlineChar = content.indexOf("\n");
    QString tagline = content.mid(0,firstNewlineChar);
    QStringList taglist = tagline.split(" ",Qt::SkipEmptyParts);
    QString content_body = content.mid(firstNewlineChar+1);

    int command_id = Commands[command];
    switch(command_id) {
        case 0: { // :todo
            TodoCard *tc = new TodoCard(content_body, taglist);
            vbox_for_checkboxes->addWidget(tc);
            break;
        };
        case 1: { // :log
            QLabel *l = new QLabel();
            l->setText(content_body);
            l->setStyleSheet("color:black; background-color: lightgrey; border: 2px solid black; border-radius: 5px; padding: 10px; font-size: 16px;");
            l->setWordWrap(true);
            vbox_for_text_labels->addWidget(l);
        };
        case 2: { // :today
            ui->stackedWidget->setCurrentIndex(0);
            break;
        };
        case 3: { // :cal
            ui->stackedWidget->setCurrentIndex(1);
            break;
        };
        default: { // invalid input
            // just does nothing.
            // break
        };
    }
    ui->command_line->clear();
    return;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    qDebug() << date << "\n";
}

