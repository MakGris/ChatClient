#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QListView>
#include <QTextEdit>
#include <QHBoxLayout>>
#include "processnetwork.h"

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
    ~MainWindow();

private slots:
    void on_pb_exit_clicked();
    void on_pb_enter_clicked();
    void line_edit_changed(QString text);
    void authComplete();


private:
    Ui::MainWindow *ui;
    //Окно авторизации
    QLabel      *lb_login           {};
    QLabel      *lb_password        {};
    QLineEdit   *le_login           {};
    QLineEdit   *le_password        {};
    QPushButton *bt_close           {};
    QPushButton *bt_enter           {};
    QWidget     *mainWidget         {};
    QGridLayout *mainLayout         {};
    ProcessNetwork *processNetwork  {};
    char* toChar(int data);
    //Главное окно чата
    QWidget     *mainChatWidget     {};
    QGridLayout *mainChatLayout     {};
    QHBoxLayout *sendHLayout        {};
    QLineEdit   *le_sendMessage     {};
    QListView   *lv_userList        {};
    QTextEdit   *te_chatText        {};
    QPushButton *bt_sendMessage     {};




signals:

};


#endif // MAINWINDOW_H
