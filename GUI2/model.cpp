#include "model.h"
#include <QDebug>

Model::Model() {
    dataBase = QSqlDatabase::addDatabase("QMYSQL");
    dataBase.setHostName("127.0.0.1");
    dataBase.setDatabaseName("game");
    dataBase.setUserName("root");
    dataBase.setPassword("root");

    if(!dataBase.open()) {
        qDebug() << dataBase.lastError().text();
    }
    else {
        qDebug() << "Success";
    }
}

bool Model::userExists(std::string str) {
    QSqlQuery query = QSqlQuery("SELECT user_name FROM highscores");

    while(query.next()) {
        if(query.value(0) == QString::fromStdString(str)) {
            return true; //if user exists
        }
    }

    return false; //if user does not exist
}

std::vector <std::string> Model::getUserNames() {
    QSqlQuery query = QSqlQuery("SELECT user_name FROM highscores");

    std::vector <std::string> userNames;

    while(query.next()) {
        QString string = query.value(0).toString();
        userNames.push_back(string.toStdString());
    }

    return userNames;
}

void Model::regUser(std::string str) {
    QSqlQuery query = QSqlQuery(dataBase);

    //prepare query to execution
    query.prepare("INSERT INTO highscores (user_name, high_score)"
               "VALUES (:user_name, :high_score)");
    query.bindValue(":user_name", QString::fromStdString(str));
    query.bindValue(":high_score", 0);
    query.exec();
}



