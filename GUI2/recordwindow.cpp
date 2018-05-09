#include "recordwindow.h"
#include "ui_recordwindow.h"


RecordWindow::RecordWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordWindow)
{
    ui->setupUi(this);
    _pixmapBg.load(":/resource/img/mainBG.jpg");

    scrollArea = new QScrollArea(ui->widget_2);
    scrollAreaWidget = new QWidget;
    scrollAreaWidgetLayout = new QVBoxLayout(scrollAreaWidget);
    exitButton = new QPushButton("Back");

    QGraphicsDropShadowEffect *effectExitButton = new QGraphicsDropShadowEffect;
    effectExitButton->setBlurRadius(2);
    effectExitButton->setXOffset(3);
    effectExitButton->setYOffset(2);
    effectExitButton->setColor(Qt::black);

    exitButton->setMaximumWidth(96);
    exitButton->setMinimumWidth(96);
    exitButton->setGraphicsEffect(effectExitButton);
    exitButton->setCursor(QCursor(Qt::PointingHandCursor));

    scrollAreaWidget->setStyleSheet("background-color: rgb(0, 99, 121); border: 0px;");
    scrollArea->setStyleSheet("border: 0px; background-color: rgb(232, 160, 171); ");
    scrollArea->setMinimumHeight(100);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(scrollAreaWidget);
    scrollArea->setWidgetResizable(true);

    ui->widget_2->layout()->addWidget(scrollArea);
    ui->widget_2->layout()->addWidget(exitButton);
    ui->widget_2->layout()->setAlignment(exitButton, Qt::AlignCenter);

    connect(exitButton, SIGNAL(clicked()), this, SLOT(exitFromRecordsClicked()));
}

RecordWindow::~RecordWindow()
{
    delete ui;
}

void RecordWindow::exitFromRecordsClicked() {
    emit exitFromRecordsSignal();
}

void RecordWindow::addUserName(std::string userName){

    QString qUserName = QString::fromStdString(userName);

    QGraphicsDropShadowEffect *effectWidget = new QGraphicsDropShadowEffect;
    QGraphicsDropShadowEffect *effectLabel = new QGraphicsDropShadowEffect;

    QLabel *usName = new QLabel(qUserName, this);


    effectWidget->setBlurRadius(5);
    effectWidget->setXOffset(3);
    effectWidget->setYOffset(3);
    effectWidget->setColor(QColor(255, 0, 255));

    effectLabel->setBlurRadius(2);
    effectLabel->setXOffset(2);
    effectLabel->setYOffset(2);
    effectLabel->setColor(Qt::black);

    usName->setStyleSheet("color:rgb(203, 232, 193); font-size: 21px; font: bold; shadow: 2px");

    //ui->exitButton->setGraphicsEffect(effectExitButton);
    ui->widget_2->setGraphicsEffect(effectWidget);
    ui->label->setGraphicsEffect(effectLabel);

    scrollAreaWidgetLayout->setAlignment(Qt::AlignCenter);
    scrollAreaWidgetLayout->addWidget(usName);
    scrollAreaWidget->adjustSize();


}

void RecordWindow::paintEvent(QPaintEvent *e)
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
