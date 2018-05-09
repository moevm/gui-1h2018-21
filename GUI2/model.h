#ifndef MODEL_H
#define MODEL_H

#include <QtSql>
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
   std::vector <std::string> getHighscores();

};


#endif // MODEL_H
