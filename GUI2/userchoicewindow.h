#ifndef USERCHOICEWINDOW_H
#define USERCHOICEWINDOW_H

#include <QWidget>
#include <string>
#include <QScrollArea>
#include <QLayout>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsEffect>
#include <QPushButton>

namespace Ui {
class UserChoiceWindow;
}

class UserChoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserChoiceWindow(QWidget *parent = nullptr);
    void addUserNameButton(std::string userName);
    ~UserChoiceWindow();

private slots:
    void addUserButtonClicked();
    void userNameButtonClicked();

signals:
    void addUserButtonSignal();
    void userNameButtonSignal();

private:
    Ui::UserChoiceWindow *ui;
    QPixmap _pixmapBg;
    QWidget *scrollAreaWidget;
    QScrollArea *scrollArea;
    QVBoxLayout *scrollAreaWidgetLayout;
    QPushButton *newUserButton;
    std::string clickedUserName;
    void paintEvent(QPaintEvent *e);
};
#endif // USERCHOICEWINDOW_H
