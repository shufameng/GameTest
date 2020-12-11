#ifndef SFMWIDGET_H
#define SFMWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QResizeEvent>
#include <QLineF>

//
class SFMWidget_LoadingWidget : public QWidget {
    Q_OBJECT
public:
    explicit SFMWidget_LoadingWidget(QWidget *parent = nullptr) : QWidget(parent), m_angle(0.0) {
        m_timer.setInterval(20);
        m_timer.setSingleShot(false);
        connect(&m_timer, &QTimer::timeout, this, &SFMWidget_LoadingWidget::onTimerTimeout);
    }
public slots:
    void startLoadingAnimation() {
        m_timer.start();
    }

    void stopLoadingAnimation() {
        m_timer.stop();
    }

private slots:
    void onTimerTimeout() {
        m_angle -= 5.0;
        update();
    }

protected:
    void paintEvent(QPaintEvent *) override {

        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing);
        QBrush brush(Qt::SolidPattern);
        brush.setColor(QColor(100, 100, 100, 100));
        painter.setBrush(brush);
        painter.setPen(Qt::NoPen);
        painter.drawRect(rect());

        QPoint pt = rect().center();
        QPen pen(Qt::SolidLine);
        pen.setColor(QColor(0, 169, 244));
        pen.setWidth(20);
        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawEllipse(pt, 40, 40);

        QLineF line;
        line.setPoints(pt, pt + QPoint(0, 40));
        line.setAngle(m_angle);

        painter.setPen(Qt::NoPen);
        brush.setColor(QColor(255, 0, 0));
        painter.setBrush(brush);
        painter.drawEllipse(line.p2(), 10, 10);
    }

    QTimer m_timer;
    qreal m_angle;
};

//
class SFMWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SFMWidget(QWidget *parent = nullptr);
    ~SFMWidget();

public slots:
    void createLoadingWidget();
    void startLoading();
    void finishLoading();
protected:
    void resizeEvent(QResizeEvent *e) override;

signals:


private:
    SFMWidget_LoadingWidget *m_loadingWidget;
};

#endif // SFMWIDGET_H
