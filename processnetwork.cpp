#include "processnetwork.h"

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

}

void ProcessNetwork::process_error()
{

}

