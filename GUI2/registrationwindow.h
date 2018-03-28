#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QWidget>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    int getWidth();
    int getHeight();
    ~RegistrationWindow();

signals:
    void regButtonSignal();

private slots:
    void regButtonClicked();

private:
    Ui::RegistrationWindow *ui;
    QPixmap _pixmapBg;

    void paintEvent(QPaintEvent *e);
};

#endif // REGISTRATIONWINDOW_H
