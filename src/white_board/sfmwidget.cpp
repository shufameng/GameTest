#include "sfmwidget.h"


SFMWidget::SFMWidget(QWidget *parent) :
    QWidget(parent),
    m_loadingWidget(nullptr)
{

}

SFMWidget::~SFMWidget()
{

}

void SFMWidget::createLoadingWidget()
{
    if (!m_loadingWidget) {
        m_loadingWidget = new SFMWidget_LoadingWidget(this);
        m_loadingWidget->hide();
    }
}

void SFMWidget::startLoading()
{
    if (m_loadingWidget) {
        m_loadingWidget->show();
        m_loadingWidget->resize(size());
        m_loadingWidget->move(0, 0);
        m_loadingWidget->startLoadingAnimation();
    }
}

void SFMWidget::finishLoading()
{
    if (m_loadingWidget) {
        m_loadingWidget->close();
        m_loadingWidget->stopLoadingAnimation();
    }
}

void SFMWidget::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);

    if (m_loadingWidget) {
        m_loadingWidget->resize(e->size());
    }
}


