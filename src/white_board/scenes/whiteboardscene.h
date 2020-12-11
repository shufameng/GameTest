#ifndef WHITEBOARDSCENE_H
#define WHITEBOARDSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QUndoStack>

class WhiteBoardScene : public QGraphicsScene
{
    Q_OBJECT

public:

    enum Tool {
        Pen = 0,
        Eraser
    };

    explicit WhiteBoardScene(QObject *parent = Q_NULLPTR);
    virtual ~WhiteBoardScene();

signals:
    void canUndoChanged(bool);
    void canRedoChanged(bool);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e) override;


private:
    Tool m_currentTool;
    bool m_isLButtonOnPress;
    QPen m_toolPen;
    QBrush m_toolBrush;
    int m_eraserWidth;
    QUndoStack m_undoStack;
};

#endif // WHITEBOARDSCENE_H
