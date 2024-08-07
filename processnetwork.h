#ifndef PROCESSNETWORK_H
#define PROCESSNETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>


class ProcessNetwork : public QObject
{
    Q_OBJECT
public:
    explicit ProcessNetwork(QObject *parent = nullptr);
    enum package_type {auth, message};
    void send_message(QByteArray pack);

private:
    QTcpSocket *client{};
    const int server_port = 9999;
    QString server_address_string = "127.0.0.1";



private slots:
    void connected();
    void ready_read();
    void process_error();

signals:
};

#endif // PROCESSNETWORK_H
