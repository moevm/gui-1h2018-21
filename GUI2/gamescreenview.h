#ifndef GAMESCREENVIEW_H
#define GAMESCREENVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QApplication>
#include <vector>
#include <QScrollBar>
#include "caritem.h"
#include "coinitem.h"

class GameScreenView: public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameScreenView(QWidget *parent = 0);
    int getDesktopHeight();
    int getDesktopWidth();
    void setSceneLength(int len);
    int getSceneLength();
    ~GameScreenView();

public slots:
    void updateCoinImage();
    void updateSceneState();

private:
    QGraphicsScene *scene;
    CarItem *car;
    QTimer *coinTimer;
    QTimer *sceneTimer;
    QPixmap sceneBackground;
    std::vector<CoinItem*> coins;

    int sceneMovementSpeed;
    int coinsNumber;
    int currentScore;
    int coinPoints;
    int sceneTimerRate;
    unsigned int coinVecIndex;
    int sceneLenght;
    void keyPressEvent(QKeyEvent *keyEvent);
};

#endif // GAMESCREENVIEW_H
