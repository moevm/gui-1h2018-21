#include "model.h"
#include <QDebug>

Model::Model() {
    dataBase = QSqlDatabase::addDatabase("QSQLITE");
    dataBase.setDatabaseName("records.db");

    if(!dataBase.open()) {
        qDebug() << dataBase.lastError().text();
    }
    else {
        qDebug() << "Success";
    }

    QSqlQuery query = QSqlQuery(dataBase);
    if(!query.exec("select * from highscores")) {
        if(!query.exec("CREATE TABLE highscores (user_name VARCHAR(45) PRIMARY KEY "
                       "UNIQUE NOT NULL, high_score INTEGER(11) NOT NULL DEFAULT 0)"))
        {
            qDebug() << "Failed to create table";
        }
    }
}

void Model::updateRecord(std::string user_name, std::string str) {
    QSqlQuery query = QSqlQuery(dataBase);
    if(!query.exec("UPDATE highscores SET high_score = "
               + QString::fromStdString(str) + " WHERE user_name = '"
                   + QString::fromStdString(user_name) + "'"))
    {
        qDebug() << query.lastError().text();
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
    QSqlQuery query = QSqlQuery("SELECT * FROM highscores");

    std::vector <std::string> userNames;

    while(query.next()) {
        QString string = query.value(0).toString();
        userNames.push_back(string.toStdString());
    }

    return userNames;
}

std::vector <std::string> Model::getHighscores() {
    QSqlQuery query = QSqlQuery("SELECT * FROM highscores");

    std::vector <std::string> highScores;

    while(query.next()) {
        QString string = query.value(1).toString();
        highScores.push_back(string.toStdString());
    }

    return highScores;
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



