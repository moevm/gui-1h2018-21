#ifndef MODEL_H
#define MODEL_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <string>

class Model {

private:
   QSqlDatabase dataBase;

public:
   Model();

   bool regUser(std::string& str);
};


#endif // MODEL_H
