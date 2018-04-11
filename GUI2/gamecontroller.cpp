#include "gamecontroller.h"
#include <QDebug>
#include <iostream>
#include <vector>
#include <string>
#include <QMessageBox>


GameController::GameController(QObject *parent) : QObject(parent) {
    regWindow = new RegistrationWindow();
    mainWindow = new MainMenuWindow();
    UChoiceWindow = new UserChoiceWindow();
    model = new Model();
    std::vector userNamesVec = model-<getUserNames();

    if(userNamesVec.size() != 0) {
        UChoiceWindow->show();
        for(int i = 0; i < userNamesVec.size(); i){
            UChoiceWindow->addUserNameButton(userNamesVec[i]);
        }
    }
    else {
        regWindow->show();
    }

    connect(regWindow, SIGNAL(regButtonSignal()), this, SLOT(regConfirmed()));
    connect(UChoiceWindow, SIGNAL(addUserButtonSignal()), SLOT(addNewUserButtonClicked()));
    connect(UChoiceWindow, SIGNAL(userNameButtonSignal()), SLOT(userNameButtonClicked()));
}

void GameController::regConfirmed() {

    if(regWindow->getNewName().size() < 3 || regWindow->getNewName().length() > 20 || model->userExists(regWindow->getNewName())){
        QMessageBox::information(0, "Incorrect name", "Check your nickname!\n-It should be 3-20 symbols length.\n-There can't be players with the same nickname.");
        return;
    } else {
    model->regUser(regWindow->getNewName());
    mainWindow->resize(regWindow->width(), regWindow->height());
    mainWindow->move(regWindow->pos());
    regWindow->close();
    mainWindow->show();
    }
}

void GameController::addNewUserButtonClicked() {
    regWindow->resize(UChoiceWindow->width(), UChoiceWindow->height());
    regWindow->move(UChoiceWindow->pos());
    UChoiceWindow->close();
    regWindow->show();

}

void GameController::userNameButtonClicked() {
    mainWindow->resize(UChoiceWindow->width(), UChoiceWindow->height());
    mainWindow->move(UChoiceWindow->pos());
    UChoiceWindow->close();
    //mainWindow->drawCurrentUserName(std::string("dsfdsf")); - TO DO
    mainWindow->show();
}
