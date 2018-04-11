#include "gamecontroller.h"
#include <QDebug>
#include <iostream>
#include <vector>
#include <string>


GameController::GameController(QObject *parent) : QObject(parent) {
    regWindow = new RegistrationWindow();
    mainWindow = new MainMenuWindow();
    model = new Model();


    bool usersAvaliable = false; // наличие зарегистрированных пользователей проверяется через модель(базу данных)

    if(!usersAvaliable) {
        regWindow->show();
    }
    else {
        //userChoiceWindow->show    вывод окна выбора пользователя
    }

    connect(regWindow, SIGNAL(regButtonSignal()), this, SLOT(regConfirmed()));
}

void GameController::regConfirmed() {
    mainWindow->resize(regWindow->getWidth(), regWindow->getHeight());
    mainWindow->move(regWindow->pos());
    regWindow->close();
    mainWindow->show();
}
