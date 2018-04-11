#include "gamecontroller.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

GameController::GameController(QObject *parent) : QObject(parent) {
    regWindow = new RegistrationWindow();
    mainWindow = new MainMenuWindow();
    UChoiceWindow = new UserChoiceWindow();
    model = new Model();

    bool usersAvaliable = false; // наличие зарегистрированных пользователей проверяется через модель(базу данных)

    if(!usersAvaliable) {
        //regWindow->show();
        UChoiceWindow->show();
        std::string max = "max";
        std::string max1 = "12345678901234567890";

        UChoiceWindow->addUserNameButton(max);
        UChoiceWindow->addUserNameButton(max);
        UChoiceWindow->addUserNameButton(max);
        UChoiceWindow->addUserNameButton(max);
        UChoiceWindow->addUserNameButton(max1);
    }
    else {
        //UChoiceWindow->show();
    }

    connect(regWindow, SIGNAL(regButtonSignal()), this, SLOT(regConfirmed()));
    connect(UChoiceWindow, SIGNAL(addUserButtonSignal()), SLOT(addNewUserButtonClicked()));
    connect(UChoiceWindow, SIGNAL(userNameButtonSignal()), SLOT(userNameButtonClicked()));
}

void GameController::regConfirmed() {

    if(regWindow->getNewName().size() < 3 || regWindow->getNewName().length() > 20 || model->regUser(regWindow->getNewName())){
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
    mainWindow->drawCurrentUserName(std::string("dsfdsf"));
    mainWindow->show();
}
