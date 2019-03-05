#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include "customwidget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout* hLayout = new QHBoxLayout();
    m_stackedWidget = new QStackedWidget(this);
    hLayout->addWidget(m_stackedWidget);

    QHBoxLayout* hLayout2 = new QHBoxLayout();
    QPushButton* pBtn = new QPushButton(this);
    this->connect(pBtn,&QPushButton::clicked,this,&Widget::s_switch);
    hLayout2->addWidget(pBtn);

    QVBoxLayout* vLayout = new QVBoxLayout();
    vLayout->addLayout(hLayout);
    vLayout->addLayout(hLayout2);
    setLayout(vLayout);
    m_curWidget = NULL;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::s_switch()
{
    qDebug()<<__LINE__<<__FUNCTION__;
    customWidget* widget = new customWidget(this);
    QPalette pal(widget->palette());

    //设置背景黑色
    if(m_bFlag)
    {
        pal.setColor(QPalette::Background, Qt::red);
        m_bFlag = false;
    }
    else {
        m_bFlag = true;
        pal.setColor(QPalette::Background, Qt::green);
    }

    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    qDebug()<<__LINE__<<__FUNCTION__<<m_stackedWidget->count();
    if(m_stackedWidget->count() == 0)
    {
        m_stackedWidget->insertWidget(0,widget);
        m_stackedWidget->setCurrentIndex(0);
    }
    else {
//        int last_index = m_stackedWidget->indexOf(m_curWidget);
//        qDebug()<<__LINE__<<__FUNCTION__<<last_index;
//        if(last_index == 0)
//        {
            m_stackedWidget->insertWidget(1,widget);
            m_stackedWidget->setCurrentIndex(1);
//        }
//        else {
//            m_stackedWidget->insertWidget(0,widget);
//            m_stackedWidget->setCurrentIndex(0);
//        }
        m_stackedWidget->removeWidget(m_curWidget);
    }
    if(m_curWidget)
        m_curWidget->deleteLater();
    m_curWidget = widget;
}
