#ifndef MODEL_H
#define MODEL_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <string>
#include <vector>

class Model {

private:
   QSqlDatabase dataBase;

public:
   Model();

   bool userExists(std::string str);
   void regUser(std::string str);
   std::vector <std::string> getUserNames();


};


#endif // MODEL_H
