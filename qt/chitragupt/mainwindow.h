#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setup_content_scroll_area();
    void setup_task_scroll_area();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::MainWindow *ui;
    QVBoxLayout *vbox_for_text_labels;
    QVBoxLayout *vbox_for_checkboxes;
    QPlainTextEdit *command_line;
};
#endif // MAINWINDOW_H
