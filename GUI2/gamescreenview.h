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
#include "winlabelitem.h"
#include <stdlib.h>
#include <time.h>
#include "numberitem.h"

class GameScreenView: public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameScreenView(QWidget *parent = 0);
    int getDesktopHeight();
    int getDesktopWidth();
    int getFinalScore();
    int getSceneLength();
    void setSceneLength(int len);
    void putScoreCounter();
    void putCoins();
    void changeScoreCounter();
    void wheelEvent(QWheelEvent * event);
    virtual ~GameScreenView();


public slots:
    void updateCoinImage();
    void updateSceneState();
    void updateAcceleration();

signals:
    void escPressed();

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *scoreItemGroup;
    CarItem *car;
    WinLabelItem *winLabel;
    QTimer *coinTimer;
    QTimer *sceneTimer;
    QTimer *accelerationTimer;
    QPixmap sceneBackground;
    std::vector<CoinItem*> coins;
    std::vector<NumberItem*> scoreNumsVector;

    int sceneMovementSpeed;
    int sceneAcceleration;
    int coinsNumber;
    int finalScore;
    int currentScore;
    int coinPoints;
    int sceneTimerRate;
    int accelerationTimerRate;
    unsigned int coinVecIndex;
    int sceneLength;
    int scoreLength;
    bool upCarMovementIsBlocked;
    bool downCarMovementIsBlocked;


    void keyPressEvent(QKeyEvent *keyEvent);
};

#endif // GAMESCREENVIEW_H
