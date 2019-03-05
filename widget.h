#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void s_switch();
private:
    Ui::Widget *ui;
    QStackedWidget* m_stackedWidget;
    QWidget* m_curWidget;
    bool m_bFlag;
};

#endif // WIDGET_H
