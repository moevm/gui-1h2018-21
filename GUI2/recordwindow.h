#ifndef RECORDWINDOW_H
#define RECORDWINDOW_H

#include <QWidget>
#include <string>
#include <QScrollArea>
#include <QLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QPainter>
#include <QGraphicsEffect>

namespace Ui {
class RecordWindow;
}

class RecordWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RecordWindow(QWidget *parent = nullptr);
    void addUserName(std::string userName);
    ~RecordWindow();

private slots:
    //void exitToMenuButtonClicked();

signals:
   // void exitFromRecords();

private:
    Ui::RecordWindow *ui;
    QPixmap _pixmapBg;
    QWidget *scrollAreaWidget;
    QScrollArea *scrollArea;
    QVBoxLayout *scrollAreaWidgetLayout;

    void paintEvent(QPaintEvent *e);
};

#endif // RECORDWINDOW_H
