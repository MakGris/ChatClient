#include "processnetwork.h"
#include "iostream"
#include <QMessageBox>
using namespace std;
ProcessNetwork::ProcessNetwork(QObject *parent)
    : QObject{parent}
{
    QHostAddress server_address(server_address_string);
    client = new QTcpSocket(this);
    client->connect(client, &QTcpSocket::connected, this, &ProcessNetwork::connected);
    client->connect(client, &QTcpSocket::readyRead, this, &ProcessNetwork::ready_read);
    client->connectToHost(server_address, server_port);
}

void ProcessNetwork::send_message(QByteArray pack)
{
    client->write(pack);
}

void ProcessNetwork::connected()
{




}

void ProcessNetwork::ready_read()
{

    QByteArray byteArray = client->readAll();
    int packType = byteArray.left(4).toInt();
    byteArray = byteArray.remove(0, 4);
    if (packType == 0) {

        bool authentification = *(byteArray.left(1).data());
        if (authentification == true) {
        emit authOkey();

        } else {
            QMessageBox msgBox;
            msgBox.setText("Authentification error");
            msgBox.exec();
        }
    }


}

void ProcessNetwork::process_error()
{

}

