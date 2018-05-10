#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QWidget>
#include <string>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    std::string getNewName();
    ~RegistrationWindow();

signals:
    void regButtonSignal();

private slots:
    void regButtonClicked();
    void nickNameInputed(QString nick);

private:
    Ui::RegistrationWindow *ui;
    std::string newName;
    QPixmap _pixmapBg;

    void paintEvent(QPaintEvent *e);
};

#endif // REGISTRATIONWINDOW_H
