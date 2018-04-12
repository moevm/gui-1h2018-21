#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"
#include <QPainter>
#include <QGraphicsDropShadowEffect>

MainMenuWindow::MainMenuWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MainMenuWindow)
{
  ui->setupUi(this);
  _pixmapBg.load(":/resource/img/mainBG.jpg");

  QGraphicsDropShadowEffect *effectWidget = new QGraphicsDropShadowEffect;
  QGraphicsDropShadowEffect *effectLabel = new QGraphicsDropShadowEffect;
  QGraphicsDropShadowEffect *effectButton1 = new QGraphicsDropShadowEffect;
  QGraphicsDropShadowEffect *effectButton2 = new QGraphicsDropShadowEffect;
  QGraphicsDropShadowEffect *effectButton3 = new QGraphicsDropShadowEffect;

  effectWidget->setBlurRadius(5);
  effectWidget->setXOffset(3);
  effectWidget->setYOffset(3);
  effectWidget->setColor(QColor(255, 0, 255));

  effectLabel->setBlurRadius(2);
  effectLabel->setXOffset(2);
  effectLabel->setYOffset(2);
  effectLabel->setColor(Qt::black);

  effectButton1->setBlurRadius(2);
  effectButton1->setXOffset(3);
  effectButton1->setYOffset(2);
  effectButton1->setColor(Qt::black);


  effectButton2->setBlurRadius(2);
  effectButton2->setXOffset(3);
  effectButton2->setYOffset(2);
  effectButton2->setColor(Qt::black);


  effectButton3->setBlurRadius(2);
  effectButton3->setXOffset(3);
  effectButton3->setYOffset(2);
  effectButton3->setColor(Qt::black);

  ui->widget_2->setGraphicsEffect(effectWidget);
  ui->label->setGraphicsEffect(effectLabel);
  ui->pushButton->setGraphicsEffect(effectButton1);
  ui->pushButton_2->setGraphicsEffect(effectButton2);
  ui->pushButton_3->setGraphicsEffect(effectButton3);

}

MainMenuWindow::~MainMenuWindow()
{
    delete ui;
}

void MainMenuWindow::drawCurrentUserName(std::string userName){ // to do
    QString qUserName = QString::fromStdString(userName);
    //ui->label_2->setText(qUserName);
}


void MainMenuWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    auto winSize = size();
    auto pixmapRatio = (float)_pixmapBg.width() / _pixmapBg.height();
    auto windowRatio = (float)winSize.width() / winSize.height();

    if(pixmapRatio > windowRatio) {
        auto newWidth = (int)(winSize.height() * pixmapRatio);
        auto offset = (newWidth - winSize.width()) / -2;
        painter.drawPixmap(offset, 0, newWidth, winSize.height(), _pixmapBg);
    }
    else {
        auto newHeight = (int)(winSize.width() / pixmapRatio);
        painter.drawPixmap(0, 0, winSize.width(), newHeight, _pixmapBg);
    }
}
