#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("nouha");//inserer nom de l'utilisateur
db.setPassword("nouha");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
