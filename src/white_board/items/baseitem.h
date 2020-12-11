#ifndef BASEITEM_H
#define BASEITEM_H

#include <QGraphicsItem>

class BaseItem : public QGraphicsItem
{
public:
    explicit BaseItem(QGraphicsItem *parent = Q_NULLPTR);
    virtual ~BaseItem();
};

#endif // BASEITEM_H
