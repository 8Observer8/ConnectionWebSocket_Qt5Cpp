#include <QtWidgets/QVBoxLayout>
#include <QtCore/QDebug>
#include "Widget.h"

Widget::Widget()
{
    setWindowTitle("Qt C++ Client");
    resize(300, 300);
    QFont font("Arial", 14);
    QVBoxLayout *vbox = new QVBoxLayout(this);
    m_pLabel = new QLabel("Please, wait for connection...", this);
    m_pLabel->setFont(font);
    vbox->addWidget(m_pLabel);
    vbox->addStretch(1);
    connect(&m_socket, &QWebSocket::connected, this, &Widget::onConnection);
//    m_socket.open(QUrl("ws://localhost:3000"));
    m_socket.open(QUrl("wss://connection-websocket-js.herokuapp.com"));
}

void Widget::onConnection()
{
    QString message = "Client was connected to server";
    qDebug() << message;
    m_pLabel->setText(message);
}
