#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QKeyEvent>
#include "windows/registrationwindow.h"
#include "windows/userchoicewindow.h"
#include "windows/mainmenuwindow.h"
#include "windows/recordwindow.h"
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
    void userNameButtonClicked(std::string);
    void openGameScreen();
    void openRecords();
    void openMainWindow();
    void backToMenuFromGameScreen();

private:
    UserChoiceWindow *uChoiceWindow;
    RegistrationWindow *regWindow;
    MainMenuWindow *mainWindow;
    RecordWindow *recWindow;
    GameScreenView *gameScreen;

    std::vector<std::string> userNamesVec;
    std::vector<std::string> userHighscores;
    std::string currentUserName;
    Model *model;
};

#endif // GAMECONTROLLER_H
