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

//sign up or sign in method
bool Model::regUser(std::string& str) {
    QSqlQuery query = QSqlQuery(dataBase);

    while(query.next()) {
        if(query.value(0) == QString::fromStdString(str)) {
            return true; //if sign in
        }
    }

    //prepare query to execution
    query.prepare("INSERT INTO highscores (user_name)"
               "VALUES (:user_name)");
    query.bindValue(":user_name", QString::fromStdString(str));
    query.exec();

    return false; //if sign up
}
