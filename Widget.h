#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWebSockets/QWebSocket>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget();
private slots:
    void onConnection();
private:
    QWebSocket m_socket;
    QLabel *m_pLabel;
};
#endif // WIDGET_H
