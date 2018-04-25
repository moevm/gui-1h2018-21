#ifndef GAMESCREENVIEW_H
#define GAMESCREENVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>

class GameScreenView: public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameScreenView(QWidget *parent = 0);
    ~GameScreenView();

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapCar;
    void keyPressEvent(QKeyEvent *keyEvent);
};

#endif // GAMESCREENVIEW_H
