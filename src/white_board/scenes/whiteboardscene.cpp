#include "whiteboardscene.h"

WhiteBoardScene::WhiteBoardScene(QObject *parent) :
    QGraphicsScene(parent),
    m_isLButtonOnPress(false)
{

}

WhiteBoardScene::~WhiteBoardScene()
{

}

void WhiteBoardScene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (Qt::LeftButton == e->button()) {

        m_isLButtonOnPress = true;

        QPointF sp = e->scenePos();
        switch (m_currentTool) {

        case Pen:
        {

        }
            break;

        case Eraser:
        {

        }
            break;
        default:
            break;
        }
    }
}

void WhiteBoardScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{

}

void WhiteBoardScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{

}
