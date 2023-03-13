#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "eventsmanagement.h"
#include <QDialog>
#include <QFileDialog>
#include "smtp.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_Patient_clicked();

    void on_pushButton_Employee_clicked();

    void on_pushButton_Employee_2_clicked();

    void on_pushButton_Appointment_clicked();

    void on_pushButton_Treatment_clicked();

    void on_pushButton_Event_clicked();

    void on_pushButton_Appointment_2_clicked();

    void on_pushButton_Treatment_2_clicked();

    void on_pushButton_Event_2_clicked();

    void on_pushButton_Employee_3_clicked();

    void on_pushButton_Patient_3_clicked();

    void on_pushButton_Treatment_3_clicked();

    void on_pushButton_Event_3_clicked();

    void on_pushButton_Employee_4_clicked();

    void on_pushButton_Patient_4_clicked();

    void on_pushButton_Appointment_4_clicked();

    void on_pushButton_Event_4_clicked();

    void on_pushButton_Employee_5_clicked();

    void on_pushButton_Patient_5_clicked();

    void on_pushButton_Appointment_5_clicked();

    void on_pushButton_Treatment_5_clicked();

    void on_pushButton_Addemp_clicked();

    void on_pushButton_Listemp_2_clicked();

    void on_pushButton_Patient_6_clicked();

    void on_pushButton_Appointment_6_clicked();

    void on_pushButton_Treatment_6_clicked();

    void on_pushButton_Event_6_clicked();

    void on_pushButton_Addemp_3_clicked();

    void on_pushButton_Stats_clicked();

    void on_pushButton_Stats_2_clicked();

    void on_pushButton_Listemp_3_clicked();

    void on_pushButton_Patient_7_clicked();

    void on_pushButton_Appointment_7_clicked();

    void on_pushButton_Treatment_7_clicked();

    void on_pushButton_Event_7_clicked();

    void on_pushButton_AddPat_clicked();

    void on_pushButton_Employee_8_clicked();

    void on_pushButton_Appointment_8_clicked();

    void on_pushButton_Treatment_8_clicked();

    void on_pushButton_Event_8_clicked();

    void on_pushButton_ListPat_2_clicked();

    void on_pushButton_Employee_9_clicked();

    void on_pushButton_Appointment_9_clicked();

    void on_pushButton_Treatment_9_clicked();

    void on_pushButton_Event_9_clicked();

    void on_pushButton_StatsPat_2_clicked();

    void on_pushButton_StatsPat_clicked();

    void on_pushButton_ListPat_3_clicked();

    void on_pushButton_AddPat_3_clicked();

    void on_pushButton_Employee_10_clicked();

    void on_pushButton_Patient_10_clicked();

    void on_pushButton_Treatment_10_clicked();

    void on_pushButton_Event_10_clicked();

    void on_pushButton_AddAppoint_clicked();

    void on_pushButton_ListAppoint_2_clicked();

    void on_pushButton_Employee_11_clicked();

    void on_pushButton_Patient_11_clicked();

    void on_pushButton_Treatment_11_clicked();

    void on_pushButton_Event_11_clicked();

    void on_pushButton_StatsAppoint_2_clicked();

    void on_pushButton_StatsAppoint_clicked();

    void on_pushButton_ListAppoint_clicked();

    void on_pushButton_ListAppoint_3_clicked();

    void on_pushButton_AddAppoint_3_clicked();

    void on_pushButton_Calendar_3_clicked();

    void on_pushButton_Employee_12_clicked();

    void on_pushButton_Patient_12_clicked();

    void on_pushButton_Treatment_12_clicked();

    void on_pushButton_Event_12_clicked();

    void on_pushButton_StatsAppoint_4_clicked();

    void on_pushButton_ListAppoint_4_clicked();

    void on_pushButton_AddAppoint_4_clicked();

    void on_pushButton_Calendar_clicked();

    void on_pushButton_Calendar_2_clicked();

    void on_pushButton_Employee_13_clicked();

    void on_pushButton_Patient_13_clicked();

    void on_pushButton_Appointment_13_clicked();

    void on_pushButton_Event_13_clicked();

    void on_pushButton_ListTreat_2_clicked();

    void on_pushButton_AddTreat_clicked();

    void on_pushButton_StatsTreat_clicked();

    void on_pushButton_StatsTreat_2_clicked();

    void on_pushButton_Employee_14_clicked();

    void on_pushButton_Patient_14_clicked();

    void on_pushButton_Appointment_14_clicked();

    void on_pushButton_Event_14_clicked();

    void on_pushButton_ListTreat_3_clicked();

    void on_pushButton_AddTreat_3_clicked();

    void on_pushButton_Employee_15_clicked();

    void on_pushButton_Patient_15_clicked();

    void on_pushButton_Appointment_15_clicked();

    void on_pushButton_Treatment_15_clicked();

    void on_pushButton_ListEvent_2_clicked();

    void on_pushButton_AddEvent_clicked();

    void on_pushButton_Employee_16_clicked();

    void on_pushButton_Patient_16_clicked();

    void on_pushButton_Appointment_16_clicked();

    void on_pushButton_Treatment_16_clicked();

    void on_pushButton_ListEvent_3_clicked();

    void on_pushButton_AddEvent_3_clicked();

    void on_pushButton_StatsEvent_2_clicked();

    void on_pushButton_ListEvent_clicked();

    void on_pushButton_StatsEvent_clicked();

    void on_pushButton_UpdateEmployee_clicked();

    void on_pushButton_DeleteEvent_clicked();

    void on_pushButton_ConfirmAddEvent_clicked();

    void on_pushButton_UpdateEvent_clicked();

    void on_pushButton_UpdatePatient_clicked();

    void on_pushButton_UpdateAppoint_clicked();

    void on_pushButton_UpdateTreatment_clicked();

    void on_pushButton_ConfirmUpdateEvent_clicked();

    void on_pushButton_GeneratePDF_Events_clicked();

    void on_pushButton_FilterEvents_clicked();

    void on_lineEdit_SearchEvent_editingFinished();

    void on_pushButton_GenerateQrCode_clicked();

    void on_lineEdit_SearchEvent_textChanged(const QString &arg1);

    void on_pushButton_ListEvent_4_clicked();

    void on_pushButton_Email_clicked();

    //mail functions
    void sendMail();
    void mailSent(QString);
    void browse();

    void on_pushButton_Employee_17_clicked();

    void on_pushButton_Patient_17_clicked();

    void on_pushButton_Appointment_17_clicked();

    void on_pushButton_Treatment_17_clicked();

    void on_pushButton_Email_2_clicked();

    void on_pushButton_StatsEvent_3_clicked();

    void on_pushButton_StatsEvent_4_clicked();

    void on_pushButton_AddEvent_4_clicked();

    void on_pushButton_Email_3_clicked();

private:
    Ui::Dialog *ui;
    //variable eventmanagenment
    EventsManagement tmpeEvent;   
    QStringList files;

    //
};

#endif // DIALOG_H
