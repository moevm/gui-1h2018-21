#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include "registrationwindow.h"
#include "userchoicewindow.h"
#include "mainmenuwindow.h"
#include "model.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QObject *parent = nullptr);

private slots:
    void regConfirmed();
    void addNewUserButtonClicked();
    void userNameButtonClicked();

private:
    UserChoiceWindow *UChoiceWindow;
    RegistrationWindow *regWindow;
    MainMenuWindow *mainWindow;

    QSize windowHeight;
    QSize windowWidth;
    Model *model;
};

#endif // GAMECONTROLLER_H
