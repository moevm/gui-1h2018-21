#include "gamecontroller.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

GameController::GameController(QObject *parent) : QObject(parent) {
    regWindow = new RegistrationWindow();
    mainWindow = new MainMenuWindow();
    uChoiceWindow = new UserChoiceWindow();
    gameScreen= new GameScreenView();
    recWindow = new RecordWindow();
    model = new Model();

    std::vector<std::string> userNamesVec = model->getUserNames();
    std::vector<std::string> userHighscores = model->getHighscores();

        if(userNamesVec.size() != 0) {

            uChoiceWindow->show();
            for(int i = 0; i < userNamesVec.size(); i++) {
                uChoiceWindow->addUserNameButton(userNamesVec[i]);
                recWindow->addUserName(userNamesVec[i] + "              " + userHighscores[i]);
            }
        }
        else {
            regWindow->show();
        }

    connect(regWindow, SIGNAL(regButtonSignal()), this, SLOT(regConfirmed()));
    connect(uChoiceWindow, SIGNAL(addUserButtonSignal()), SLOT(addNewUserButtonClicked()));
    connect(uChoiceWindow, SIGNAL(userNameButtonSignal()), SLOT(userNameButtonClicked()));
    connect(mainWindow, SIGNAL(goButtonSignal()), SLOT(openGameScreen()));
    connect(mainWindow, SIGNAL(recordButtonSignal()), SLOT(openRecords()));
    connect(recWindow, SIGNAL(exitFromRecordsSignal()), SLOT(openMainWindow()));
}

void GameController::openMainWindow() {
    mainWindow->move(recWindow->pos());
    recWindow->close();
    mainWindow->show();
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

void GameController::openRecords() {
    recWindow->move(mainWindow->pos());
    mainWindow->close();
    recWindow->show();
}

void GameController::addNewUserButtonClicked() { // pushing button "Enter" in registration window
    regWindow->resize(uChoiceWindow->width(), uChoiceWindow->height());
    regWindow->move(uChoiceWindow->pos());
    uChoiceWindow->close();
    regWindow->show();
}

void GameController::userNameButtonClicked() { // click to name of the user in user choice window
    mainWindow->resize(uChoiceWindow->width(), uChoiceWindow->height());
    mainWindow->move(uChoiceWindow->pos());
    uChoiceWindow->close();
    //mainWindow->drawCurrentUserName(std::string("dsfdsf")); - TO DO
    mainWindow->show();
}

void GameController::openGameScreen() { // click to name of the user in user choice window
    mainWindow->close();
    gameScreen->showFullScreen();
}

