#ifndef EVENTSMANAGEMENT_H
#define EVENTSMANAGEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class EventsManagement
{
public:
    EventsManagement();
    EventsManagement(QString,QString,QString,QString,QString,int,int);
    EventsManagement(int,QString,QString,QString,QString,QString,int,int);


    //getters
    int get_EventID();
    QString get_EventName();
    QString get_Begin_Date();
    QString get_End_Date();
    QString get_Event_Address();
    QString get_Event_Description();
    int     get_nbr_event_particepents();
    int     get_ID_EventManger();

    //setters

    void set_IDevent(int idevent);
    void set_EventName(QString EventName);
    void set_Begin_Date(QString BeginDate );
    void set_End_Date(QString EndDate);
    void set_Event_Address(QString AddressEvent);
    void set_Event_Description(QString EventDescription);
    void set_nbr_event_particepents(int ParticipentsNumber);
    void set_ID_EventManger(int ManagerID);


    //functions


     QSqlQueryModel *DisplayEventsTable();

     bool DeleteEvent(int IdEvent);

     bool AddEvent();

     bool UpdateEvent(int id);

     bool SearchEvent(int id,EventsManagement *E);

     //to display event managers IDS on combobox

     QSqlQueryModel *DisplayEventManagerIDsOnComboBox();


      QSqlQueryModel *DisplayEventsTableByEventName();

      QSqlQueryModel *DisplayEventsTableByNumberOfParticipents();

      QSqlQueryModel *DisplayEventsTableByEventID();

      QSqlQueryModel *DisplayEventsSearchByEventID(int event_id);











private:
     int EventID;
    QString Event_Name;
    QString Begin_Date;
    QString End_Date;
    QString Event_Address;
    QString Event_Description;
    int nbr_event_particepents;
    int ID_EventManger;
};

#endif // EVENTSMANAGEMENT_H
