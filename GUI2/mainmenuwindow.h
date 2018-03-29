#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include <QWidget>

namespace Ui {
class MainMenuWindow;
}

class MainMenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuWindow(QWidget *parent = nullptr);
    int getWidth();
    int getHeight();
    ~MainMenuWindow();

private:
    Ui::MainMenuWindow *ui;
    QPixmap _pixmapBg;
    void paintEvent(QPaintEvent *e);
};

#endif // MAINMENUWINDOW_H
