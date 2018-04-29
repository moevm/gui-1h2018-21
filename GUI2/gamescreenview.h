#ifndef GAMESCREENVIEW_H
#define GAMESCREENVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QApplication>
#include "caritem.h"

class GameScreenView: public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameScreenView(QWidget *parent = 0);
    int getDesktopHeight();
    void setSceneLength(int len);
    int getSceneLength();
    ~GameScreenView();

private:
    QGraphicsScene *scene;
    CarItem *car;
    QPixmap sceneBackground;
    int sceneLenght;
    void keyPressEvent(QKeyEvent *keyEvent);
};

#endif // GAMESCREENVIEW_H
