#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

class customWidget : public QWidget
{
    Q_OBJECT
public:
    explicit customWidget(QWidget *parent = nullptr);
    ~customWidget();
signals:

public slots:
};

#endif // CUSTOMWIDGET_H
