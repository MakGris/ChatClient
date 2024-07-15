#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Авторизация");
    setFixedSize(400, 200);
    mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);
    mainLayout = new QGridLayout(mainWidget);

    lb_login = new QLabel("Введите Login", mainWidget);
    mainLayout->addWidget(lb_login, 0, 0, 1, 2);

    le_login = new QLineEdit(mainWidget);
    connect(le_login,&QLineEdit::textChanged, this, &MainWindow::line_edit_changed);
    mainLayout->addWidget(le_login, 1, 0, 1, 2);

    lb_password = new QLabel("Введите пароль", mainWidget);
    mainLayout->addWidget(lb_password, 2, 0, 1, 2);

    le_password = new QLineEdit(mainWidget);
    connect(le_password, &QLineEdit::textChanged, this, &MainWindow::line_edit_changed);
    mainLayout->addWidget(le_password, 3, 0, 1, 2);

    bt_close = new QPushButton("Закрыть", mainWidget);
    mainLayout->addWidget(bt_close, 4, 0);

    bt_enter = new QPushButton("Войти", mainWidget);
    mainLayout->addWidget(bt_enter, 4, 1);
    bt_enter->setEnabled(false);
    connect(bt_close, &QPushButton::clicked, this, &MainWindow::on_pb_exit_clicked);
    connect(bt_enter, &QPushButton::clicked, this, &MainWindow::on_pb_enter_clicked);
    processNetwork = new ProcessNetwork(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_exit_clicked()
{
    close();
}

void MainWindow::on_pb_enter_clicked()
{
    QByteArray pack {};
    pack.append(ProcessNetwork::package_type::auth);
    pack.append(le_login->selectionLength());
    pack.append(le_login->text().toUtf8());
    pack.append(le_password->selectionLength());
    pack.append(le_password->text().toUtf8());
    processNetwork->send_message(pack);


}

void MainWindow::line_edit_changed(QString text)
{
    if (le_login->text().isEmpty() || le_password->text().isEmpty()) {
        bt_enter->setEnabled(false);
    } else {
        bt_enter->setEnabled(true);
    }
}



