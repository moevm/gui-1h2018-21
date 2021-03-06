#include "gamecontroller.h"
#include <iostream>
#include <QMessageBox>

using namespace std;

GameController::GameController(QObject *parent) : QObject(parent) {
    regWindow = new RegistrationWindow();
    mainWindow = new MainMenuWindow();
    delete mainWindow;

    mainWindow = new MainMenuWindow();
    uChoiceWindow = new UserChoiceWindow();
    recWindow = new RecordWindow();
    model = new Model();

    userNamesVec = model->getUserNames();
    userHighscores = model->getHighscores();

    if(userNamesVec.size() != 0) {
        uChoiceWindow->show();
        for(int i = 0; i < userNamesVec.size(); i++) {
                uChoiceWindow->addUserNameButton(userNamesVec[i]);
        }
    }
    else {
        regWindow->show();
    }

    connect(regWindow, SIGNAL(regButtonSignal()), this, SLOT(regConfirmed()));
    connect(uChoiceWindow, SIGNAL(addUserButtonSignal()), SLOT(addNewUserButtonClicked()));
    connect(uChoiceWindow, SIGNAL(userNameButtonSignal(std::string)), this, SLOT(userNameButtonClicked(std::string)));
    connect(mainWindow, SIGNAL(goButtonSignal()), SLOT(openGameScreen()));
    connect(mainWindow, SIGNAL(recordButtonSignal()), SLOT(openRecords()));
    connect(recWindow, SIGNAL(exitFromRecordsSignal()), SLOT(openMainWindow()));

}

void GameController::openMainWindow() {
    mainWindow->resize(recWindow->width(),  recWindow->height());
    mainWindow->move(recWindow->pos());
    recWindow->close();
    mainWindow->show();
}

void GameController::backToMenuFromGameScreen()
{
    model->updateRecord(currentUserName, to_string(gameScreen->getFinalScore()));
    gameScreen->disconnect();
    delete gameScreen;
    mainWindow->show();
}

void GameController::regConfirmed() {

    if(regWindow->getNewName().size() < 3 || regWindow->getNewName().length() > 20 || model->userExists(regWindow->getNewName())){
        QMessageBox::information(0, "Incorrect name", "Check your nickname!\n-It should be 3-20 symbols length.\n-There can't be players with the same nickname.");
        return;
    } else {
    model->regUser(regWindow->getNewName());
    this->currentUserName = regWindow->getNewName();
    mainWindow->resize(regWindow->width(), regWindow->height());
    mainWindow->move(regWindow->pos());
    regWindow->close();
    mainWindow->show();
    }
}

void GameController::openRecords() {

    recWindow->cleanRecords();
    std::vector<std::string> userNamesVec = model->getUserNames();
    std::vector<std::string> userHighscores = model->getHighscores();

    for(int i = 0; i < userNamesVec.size(); i++) {
        for(int j = 0; j < userNamesVec.size() - i - 1; j++) {
            if(stoi(userHighscores[j + 1]) >= stoi(userHighscores[j])) {
                swap(userHighscores[j], userHighscores[j + 1]);
                swap(userNamesVec[j], userNamesVec[j + 1]);
            }
        }
    }


    for(int i = 0; i < userNamesVec.size(); i++) {
        recWindow->addUserName(userNamesVec[i] + "   " + userHighscores[i]);
    }

    recWindow->resize(mainWindow->width(),  mainWindow->height());
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

void GameController::userNameButtonClicked(std::string clickedUserName) { // click to name of the user in user choice window

    currentUserName = clickedUserName;

    mainWindow->resize(uChoiceWindow->width(), uChoiceWindow->height());
    mainWindow->move(uChoiceWindow->pos());
    uChoiceWindow->close();
    //mainWindow->drawCurrentUserName(std::string("dsfdsf")); - TO DO
    mainWindow->show();
}

void GameController::openGameScreen() { // click to name of the user in user choice window

    gameScreen= new GameScreenView();
    connect(gameScreen, SIGNAL(escPressed()), SLOT(backToMenuFromGameScreen()));
    mainWindow->close();
    gameScreen->showFullScreen();
}

