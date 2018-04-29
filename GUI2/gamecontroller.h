#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QKeyEvent>
#include "registrationwindow.h"
#include "userchoicewindow.h"
#include "mainmenuwindow.h"
#include "gamescreenview.h"
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
    void openGameScreen();

private:
    UserChoiceWindow *uChoiceWindow;
    RegistrationWindow *regWindow;
    MainMenuWindow *mainWindow;
    GameScreenView *gameScreen;

    QSize windowHeight;
    QSize windowWidth;
    Model *model;
};

#endif // GAMECONTROLLER_H
