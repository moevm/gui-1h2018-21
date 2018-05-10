#include "userchoicewindow.h"
#include "ui_userchoicewindow.h"

#include <iostream>

UserChoiceWindow::UserChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserChoiceWindow)
{
    ui->setupUi(this);
    _pixmapBg.load(":/resource/img/BG2.jpg");
    scrollArea = new QScrollArea(ui->widget_2);
    scrollAreaWidget = new QWidget;
    newUserButton = new QPushButton("Add new", this);
    scrollAreaWidgetLayout = new QVBoxLayout(scrollAreaWidget);

    QGraphicsDropShadowEffect *effectNewUserButton = new QGraphicsDropShadowEffect;
    effectNewUserButton->setBlurRadius(2);
    effectNewUserButton->setXOffset(3);
    effectNewUserButton->setYOffset(2);
    effectNewUserButton->setColor(Qt::black);

    newUserButton->setStyleSheet("padding: 5px; background-color: rgb(213, 163, 207); font: bold; border-radius: 8px; border: 3px solid rgb(112, 38, 103); ");
    newUserButton->setCursor(QCursor(Qt::PointingHandCursor));
    newUserButton->setMaximumWidth(96);
    newUserButton->setMinimumWidth(96);
    newUserButton->setGraphicsEffect(effectNewUserButton);


    scrollAreaWidget->setStyleSheet("background-color: rgb(232, 160, 171); border: 0px;");
    scrollArea->setStyleSheet("border: 0px; background-color: rgb(232, 160, 171); ");
    scrollArea->setMinimumHeight(100);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setWidgetResizable(true);

    ui->widget_2->layout()->addWidget(scrollArea);
    ui->widget_2->layout()->addWidget(newUserButton);
    ui->widget_2->layout()->setAlignment(newUserButton, Qt::AlignCenter);

    connect(newUserButton, SIGNAL(clicked()), this, SLOT(addUserButtonClicked()));
}

UserChoiceWindow::~UserChoiceWindow()
{
    delete ui;
}

void UserChoiceWindow::addUserNameButton(std::string userName){

    QString qUserName = QString::fromStdString(userName);


    QGraphicsDropShadowEffect *effectWidget = new QGraphicsDropShadowEffect;
    QGraphicsDropShadowEffect *effectLabel = new QGraphicsDropShadowEffect;

    QPushButton *userNameButton = new QPushButton(qUserName, this);

    effectWidget->setBlurRadius(5);
    effectWidget->setXOffset(5);
    effectWidget->setYOffset(5);
    effectWidget->setColor(Qt::black);

    effectLabel->setBlurRadius(2);
    effectLabel->setXOffset(2);
    effectLabel->setYOffset(2);
    effectLabel->setColor(Qt::black);



    userNameButton->setStyleSheet("color:rgb(203, 232, 193); font-size: 21px; font: bold; shadow: 2px");
    userNameButton->setCursor(QCursor(Qt::PointingHandCursor));

    ui->widget_2->setGraphicsEffect(effectWidget);
    ui->label->setGraphicsEffect(effectLabel);

    scrollAreaWidgetLayout->addWidget(userNameButton);
    scrollAreaWidget->adjustSize();


    connect(userNameButton, SIGNAL(clicked()), SLOT(userNameButtonClicked()));
}

void UserChoiceWindow::addUserButtonClicked(){
    emit addUserButtonSignal();
}

void UserChoiceWindow::userNameButtonClicked(){
    emit userNameButtonSignal(clickedUserName);
}

void UserChoiceWindow::paintEvent(QPaintEvent *e)
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

