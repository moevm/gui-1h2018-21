#ifndef USERNAMEBUTTON_H
#define USERNAMEBUTTON_H

#include <QPushButton>

class UserNameButton : public QPushButton
{
    Q_OBJECT
private:
    QString text;
public:
    UserNameButton(QString, QWidget* parent = nullptr);
    virtual ~UserNameButton() { };

signals:
    void userNameButtonSignal(QString);

public slots:
    void clickedUserNameButton();
};

#endif // USERNAMEBUTTON_H
