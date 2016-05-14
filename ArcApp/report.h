#ifndef REPORT_H
#define REPORT_H

#include <QTableView>
#include <QtSql/QtSql>
#include "mymodel.h"
#include "databasemanager.h"
#include <QtConcurrent/QtConcurrent>
#include <qDebug>

// Do not use shiftNo
#define CHECKOUT_REPORT     0
#define VACANCY_REPORT      1
#define LUNCH_REPORT        2
#define WAKEUP_REPORT       3

// Use shiftNo
#define BOOKING_REPORT      4
#define TRANSACTION_REPORT  5
            
class Report
{
public:
    Report(QObject *parent, QTableView* tableView, int type);
    void updateModel(QDate date);
    void updateModel(QDate date, int shiftNo);
    
private:
    MyModel model;
    int reportType;
    void updateModelThread(QDate date);
    void updateModelThread(QDate date, int shiftNo);
    bool processTransactionQuery(QStringList* data, QSqlQuery* query);
    void setData(QSqlQuery* query);
    void setData(QStringList *data);
    void setTitle();
};
    
#endif // REPORT_H
