#include "customwidget.h"
#include <QDebug>

customWidget::customWidget(QWidget *parent) : QWidget(parent)
{

}

customWidget::~customWidget()
{
    qDebug()<<__LINE__<<__FUNCTION__;
}
