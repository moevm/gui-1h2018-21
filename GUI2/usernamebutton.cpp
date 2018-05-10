#include "usernamebutton.h"

UserNameButton::UserNameButton(QString ButtonText, QWidget *parent ) : QPushButton(ButtonText, parent)
{
    text = ButtonText;
    connect(this, SIGNAL(clicked()), this, SLOT(clickedUserNameButton()));
}


void UserNameButton::clickedUserNameButton()
{
    emit(userNameButtonSignal(text));
}

