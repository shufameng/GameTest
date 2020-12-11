#ifndef ERASEITEMSCOMMAND_H
#define ERASEITEMSCOMMAND_H

#include <QUndoCommand>
#include <QGraphicsScene>
#include <QGraphicsItem>

class EraseItemsCommand : public QUndoCommand
{
public:
    EraseItemsCommand(QGraphicsScene *scene, QUndoCommand *parent = Q_NULLPTR);
};

#endif // ERASEITEMSCOMMAND_H
