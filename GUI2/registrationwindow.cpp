#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include <QPixmap>
#include <QPainter>
#include <QGraphicsEffect>


RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    _pixmapBg.load(":/resource/img/BG2.jpg");
    QGraphicsDropShadowEffect *effectWidget = new QGraphicsDropShadowEffect;
    QGraphicsDropShadowEffect *effectLabel = new QGraphicsDropShadowEffect;
    QGraphicsDropShadowEffect *effectRegButton = new QGraphicsDropShadowEffect;

    effectWidget->setBlurRadius(5);
    effectWidget->setXOffset(5);
    effectWidget->setYOffset(5);
    effectWidget->setColor(Qt::black);

    effectLabel->setBlurRadius(2);
    effectLabel->setXOffset(2);
    effectLabel->setYOffset(2);
    effectLabel->setColor(Qt::black);

    effectRegButton->setBlurRadius(2);
    effectRegButton->setXOffset(3);
    effectRegButton->setYOffset(2);
    effectRegButton->setColor(Qt::black);

    ui->widget_2->setGraphicsEffect(effectWidget);
    ui->label->setGraphicsEffect(effectLabel);
    ui->regButton->setGraphicsEffect(effectRegButton);


    connect(ui->regButton, SIGNAL(clicked()), this, SLOT(regButtonClicked()));
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::regButtonClicked(){
    emit regButtonSignal();
}

int RegistrationWindow::getWidth(){
    return size().width();
}

int RegistrationWindow::getHeight(){
    return size().height();
}

void RegistrationWindow::paintEvent(QPaintEvent *e)
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
