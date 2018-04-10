#ifndef DASHBOARDITEM_H
#define DASHBOARDITEM_H

#include <QGraphicsProxyWidget>
#include <QWidget>
#include <QLabel>

class DashboardItem : public QWidget
{
    Q_OBJECT
public:
    explicit DashboardItem(QString aktivitaet, QString icon, QString text, QString runtxt, QWidget *parent = 0);
    ~DashboardItem();
    QString getRuntxt() { return m_runtxt; }
    QString getText() { return m_textLabel->text(); }
    QString getIcon() { return m_widgetIcon; }
    QString getDefaultText() { return m_defaultText; }

    void setRuntxt(QString runtxt) { m_runtxt = runtxt; }
    void setText(QString value) { m_textLabel->setText(value); }

signals:
    void updateItems();

//public slots:
//    void removeItem();

private:
    QString m_runtxt = "";
    QString m_widgetIcon;
    QString m_defaultText;
    QLabel *m_textLabel;
};

#endif // DASHBOARDITEM_H
