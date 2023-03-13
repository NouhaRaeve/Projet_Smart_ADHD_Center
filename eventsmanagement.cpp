#include "eventsmanagement.h"

struct MonthData {
    int events;
    int participants;
};




// constructors
EventsManagement::EventsManagement()
{
         Event_Name="";
         Begin_Date="";
         End_Date="";
         Event_Address="";
         Event_Description="";
         nbr_event_particepents=0;
         ID_EventManger=0;
}
EventsManagement::EventsManagement(QString eventname,QString begindate,QString enddate,QString eventaddress,QString eventdescription,int participentsnumber,int idmanager)
{
         this->Event_Name=eventname;
         this->Begin_Date=begindate;
         this->End_Date=enddate;
         this->Event_Address=eventaddress;
         this->Event_Description=eventdescription;
         this->nbr_event_particepents=participentsnumber;
         this->ID_EventManger=idmanager;
}
EventsManagement::EventsManagement(int id,QString eventname,QString begindate,QString enddate,QString eventaddress,QString eventdescription,int participentsnumber,int idmanager)
{
         this->EventID=id;
         this->Event_Name=eventname;
         this->Begin_Date=begindate;
         this->End_Date=enddate;
         this->Event_Address=eventaddress;
         this->Event_Description=eventdescription;
         this->nbr_event_particepents=participentsnumber;
         this->ID_EventManger=idmanager;
}

//setters functions
void EventsManagement::set_IDevent(int idevent)
{
 this->EventID=idevent;
}
void EventsManagement::set_EventName(QString EventName)
{
this->Event_Name=EventName;
}
void EventsManagement::set_Begin_Date(QString BeginDate)
{
    this->Begin_Date=BeginDate;
}
void EventsManagement::set_End_Date(QString EndDate)
{
    this->End_Date=EndDate;
}
void EventsManagement::set_Event_Description(QString EventDescription)
{
    this->Event_Description=EventDescription;
}
void EventsManagement::set_nbr_event_particepents(int ParticipentsNumber)
{
    this->nbr_event_particepents=ParticipentsNumber;
}
void EventsManagement::set_ID_EventManger(int ManagerID)
{
    this->ID_EventManger=ManagerID;
}
void EventsManagement::set_Event_Address(QString AddressEvent)
{
    this->Event_Address=AddressEvent;
}



//getters functions

int EventsManagement::get_EventID()
{
 return EventID;
}
QString EventsManagement::get_EventName()
{
    return Event_Name;
}
QString EventsManagement::get_Begin_Date()
{
    return Begin_Date;
}
QString EventsManagement::get_End_Date( )
{
   return End_Date;
}
QString EventsManagement::get_Event_Description()
{
    return Event_Description;
}
int EventsManagement::get_nbr_event_particepents()
{
   return nbr_event_particepents;
}
int EventsManagement::get_ID_EventManger()
{
    return ID_EventManger;
}
QString EventsManagement::get_Event_Address()
{
    return Event_Address;
}






//display
QSqlQueryModel *EventsManagement::DisplayEventsTable()
{
    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("select * from Event");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("Event ID"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("Event Name"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("Event Description"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("Begin Date"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("End Date"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("Participants Number"));
          model->setHeaderData(6,Qt::Horizontal,QObject::tr("Event Address"));
          model->setHeaderData(7,Qt::Horizontal,QObject::tr("Event Manager ID"));

            return model;
}

//delete
bool EventsManagement::DeleteEvent(int IdEvent)
{
    QSqlQuery query;
        QString res=QString::number(IdEvent);
        query.prepare("Delete from Event where EVENT_ID=:id");
        query.bindValue(":id",res);
        return query.exec();
}

//display ids on combobox
QSqlQueryModel *EventsManagement::DisplayEventManagerIDsOnComboBox()
{
    QSqlQueryModel *model = new QSqlQueryModel();
          model->setQuery("select EMPLOYEE_ID from Employee");
          return model;
}

//add event
bool EventsManagement::AddEvent()
{
        QSqlQuery query;
        // QString res= QString::number(id);
        query.prepare("INSERT INTO Event(Event_Name,Event_Description,Begin_Date,End_Date,Participant_Nbr,Event_Adress,Employee_id) VALUES (:eventname,:eventdescription,:begindate,:enddate,:nbrparticipants,:eventaddess,:idmanager)");
        // query.bindValue(":id",res);
         query.bindValue(":eventname",Event_Name);
         query.bindValue(":eventdescription",Event_Description);
         query.bindValue(":begindate",Begin_Date);
         query.bindValue(":enddate",End_Date);
         query.bindValue(":nbrparticipants",nbr_event_particepents);
         query.bindValue(":eventaddess",Event_Address);
         query.bindValue(":idmanager",ID_EventManger);
         return query.exec();
}
//update event
bool EventsManagement::UpdateEvent(int id)
{
     QSqlQuery query;
        QString res=QString::number(id);
        query.prepare("Update Event set Event_Id=:id,Event_Name=:eventname,Event_Description=:eventdescription,Begin_Date=:begindate,End_Date=:enddate,Participant_Nbr=:nbrparticipants,Event_Adress=:eventaddess,Employee_id=:idmanager where Event_Id=:id");
        query.bindValue(":id",res);
        query.bindValue(":eventname",Event_Name);
        query.bindValue(":eventdescription",Event_Description);
        query.bindValue(":begindate",Begin_Date);
        query.bindValue(":enddate",End_Date);
        query.bindValue(":nbrparticipants",nbr_event_particepents);
        query.bindValue(":eventaddess",Event_Address);
        query.bindValue(":idmanager",ID_EventManger);
        return query.exec();

}
//search event and return an event in parameter
bool EventsManagement::SearchEvent(int id, EventsManagement *E)
{


       QSqlQuery query;
       QString res=QString::number(id);
       query.prepare("Select * from Event where Event_Id=:id");
       query.bindValue(":id",res);

       int column1Value=0 ;
        QString column2Value ;
        QString column3Value ;
        QString column4Value ;
        QString column5Value ;
        int column6Value = 0 ;
        QString column7Value ;
        int column8Value = 0 ;

       if (query.exec()) {
             while (query.next()) {
                column1Value = query.value(0).toInt();
                column2Value = query.value(1).toString();
                column3Value = query.value(2).toString();
                column4Value = query.value(3).toString();
                column5Value = query.value(4).toString();
                column6Value = query.value(5).toInt();
                column7Value = query.value(6).toString();
                column8Value = query.value(7).toInt();

               // Do something with the retrieved values

           }

       } else {
           // handle error
       }
       // E(column1Value,column2Value,column3Value);
        E->set_IDevent(column1Value);
        E->set_EventName(column2Value);
        E->set_Event_Description(column3Value);
        E->set_Begin_Date(column4Value);
        E->set_End_Date(column5Value);
        E->set_nbr_event_particepents(column6Value);
        E->set_Event_Address(column7Value);
        E->set_ID_EventManger(column8Value);


          return query.exec();



}
 QSqlQueryModel *EventsManagement::DisplayEventsTableByEventName()
 {
     QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("select * from Event ORDER BY Event_Name");
           model->setHeaderData(0,Qt::Horizontal,QObject::tr("Event ID"));
           model->setHeaderData(1,Qt::Horizontal,QObject::tr("Event Name"));
           model->setHeaderData(2,Qt::Horizontal,QObject::tr("Event Description"));
           model->setHeaderData(3,Qt::Horizontal,QObject::tr("Begin Date"));
           model->setHeaderData(4,Qt::Horizontal,QObject::tr("End Date"));
           model->setHeaderData(5,Qt::Horizontal,QObject::tr("Participants Number"));
           model->setHeaderData(6,Qt::Horizontal,QObject::tr("Event Address"));
           model->setHeaderData(7,Qt::Horizontal,QObject::tr("Event Manager ID"));

             return model;

 }


 QSqlQueryModel *EventsManagement::DisplayEventsTableByNumberOfParticipents()
 {
     QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("select * from Event ORDER BY Participant_Nbr");
           model->setHeaderData(0,Qt::Horizontal,QObject::tr("Event ID"));
           model->setHeaderData(1,Qt::Horizontal,QObject::tr("Event Name"));
           model->setHeaderData(2,Qt::Horizontal,QObject::tr("Event Description"));
           model->setHeaderData(3,Qt::Horizontal,QObject::tr("Begin Date"));
           model->setHeaderData(4,Qt::Horizontal,QObject::tr("End Date"));
           model->setHeaderData(5,Qt::Horizontal,QObject::tr("Participants Number"));
           model->setHeaderData(6,Qt::Horizontal,QObject::tr("Event Address"));
           model->setHeaderData(7,Qt::Horizontal,QObject::tr("Event Manager ID"));

             return model;

 }
 QSqlQueryModel *EventsManagement::DisplayEventsTableByEventID()
 {
     QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("select * from Event ORDER BY Event_Id");
           model->setHeaderData(0,Qt::Horizontal,QObject::tr("Event ID"));
           model->setHeaderData(1,Qt::Horizontal,QObject::tr("Event Name"));
           model->setHeaderData(2,Qt::Horizontal,QObject::tr("Event Description"));
           model->setHeaderData(3,Qt::Horizontal,QObject::tr("Begin Date"));
           model->setHeaderData(4,Qt::Horizontal,QObject::tr("End Date"));
           model->setHeaderData(5,Qt::Horizontal,QObject::tr("Participants Number"));
           model->setHeaderData(6,Qt::Horizontal,QObject::tr("Event Address"));
           model->setHeaderData(7,Qt::Horizontal,QObject::tr("Event Manager ID"));

             return model;

 }

 QSqlQueryModel *EventsManagement::DisplayEventsSearchByEventID(int event_id)
 {

     QSqlQueryModel *model = new QSqlQueryModel();
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Event ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Event Name"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Event Description"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Begin Date"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("End Date"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Participants Number"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Event Address"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("Event Manager ID"));

         QSqlQuery query;
         query.prepare("SELECT * FROM Event WHERE Event_Id = :id");
         query.bindValue(":id", event_id);
         query.exec();
         model->setQuery(query);

         return model;

 }

QChartView * EventsManagement::statsevent()
{
    QSqlQuery query;

    // Create an array of MonthData objects
    MonthData monthData[12];

    // Initialize each MonthData object with events and participants set to 0
    for (int i = 0; i < 12; i++) {
        monthData[i].events = 0;
        monthData[i].participants = 0;
    }

    query.prepare("SELECT * FROM Event");

    if (query.exec()) {
        while (query.next()) {
            QString dateString = query.value(3).toString();
            QDate date = QDate::fromString(dateString, "dd-MM-yyyy");
            int month = date.month() - 1; // Subtract 1 to get 0-based index

            // Increment the events and participants for the corresponding month
            monthData[month].events++;
            monthData[month].participants += query.value(5).toInt();
        }
    } else {
        // handle error
    }

    // Create the chart
    QChart *chart = new QChart();

    // Create the bar series
    QBarSeries *series = new QBarSeries();

    // Create the sets for the bars
    QBarSet *participants = new QBarSet("Participants");
    QBarSet *events = new QBarSet("Events");


    // Set the values for the sets
    for (int i = 0; i < 12; i++) {
        participants->append(monthData[i].participants);
        events->append(monthData[i].events);
    }

    // Set the colors for the sets
    QColor eventsColor("#0A9A84");
    QColor participantsColor("#2ecc71");

    participants->setColor(participantsColor);
    events->setColor(eventsColor);

    // Add the sets to the series
    series->append(participants);
    series->append(events);

    // Add the series to the chart
    chart->addSeries(series);

    // Set the chart title
    chart->setTitle("Participants and Events by Month");


    // Set the X-axis categories
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("January");
    axisX->append("February");
    axisX->append("March");
    axisX->append("April");
    axisX->append("May");
    axisX->append("June");
    axisX->append("July");
    axisX->append("August");
    axisX->append("September");
    axisX->append("October");
    axisX->append("November");
    axisX->append("December");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Set the Y-axis range
    int minParticipants = INT_MAX;
    int maxParticipants = INT_MIN;
    int minEvents = INT_MAX;
    int maxEvents = INT_MIN;
    for (int i = 0; i < 12; i++) {
        minParticipants = qMin(minParticipants, monthData[i].participants);
        maxParticipants = qMax(maxParticipants, monthData[i].participants);
        minEvents = qMin(minEvents, monthData[i].events);
        maxEvents = qMax(maxEvents, monthData[i].events);
    }

    QValueAxis *axisY = new QValueAxis();

    axisY->setRange(qMin(minParticipants, minEvents), qMax(maxParticipants, maxEvents));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    series->setBarWidth(1);


    // Create the chart view and set the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;


}



