#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpatientdialog.h"
#include "QMessageBox"
#include "worklistserversettingsdialog.h"
#include "worklistdialog.h"
#include <QSqlField>
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "logindialog.h"
#include <QDateTime>
#include <QSqlRecord>
#include "dcmtk/dcmdata/dcuid.h"
#include "dcmtk/ofstd/ofstream.h"
#include "Utils/logmgr.h"
#include "View/loadImagedialog.h"
int MACHINE_UID=001;


MainWindow::MainWindow(QWidget *parent, LoadImageDialog &loadImageDialog) :
    QMainWindow(parent),
    m_loadImageDlg(loadImageDialog),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    _model= new QSqlTableModel(this,_database) ;
//    _model->setTable("StudyTbl");
//    _model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    _model->select();

//    _model2 = new QSqlTableModel(this,_database) ;
//    _model2->setTable("WorkListTbl");
//    _model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    _model2->select();

//    connect(_dialog,SIGNAL(accepted()),this,SLOT(on_newPatient_accepted()));
//    connect(wrkDlg,SIGNAL(NotifyRecoredSelected(QSqlRecord)),this,SLOT(on_Patient_selected(QSqlRecord)));

}

MainWindow::~MainWindow()
{
     //_model->submitAll();
    delete ui;
}


//void MainWindow::on_newPatient_accepted()
//{
////    //qDebug()<< "Dialog RESULT:"<<_dialog->result();
////    //_model->setTable("StudyTbl");
////    _model->select();
////    qDebug()<<"Number of records: "<<_model->rowCount();
////    QSqlRecord _record = _model->record();

////    char uid[100];
////    QString StudyId =GenerateStudyID();
////    _record.setValue("studyid",StudyId);
////    _record.setValue("viewid",_dialog->GetSelectedProceduresList().at(0));
////    _record.setValue("seriesinstanceuid",dcmGenerateUniqueIdentifier(uid, SITE_SERIES_UID_ROOT));
////    _record.setValue("seriesstartdatetime",QDateTime::currentDateTime().date().toString("yyyy.MM.dd"));
////    QString sop =dcmGenerateUniqueIdentifier(uid, SITE_INSTANCE_UID_ROOT);
////    _record.setValue("primarysopuid",sop);
////    _record.setValue("secondarysopuid",sop+".1");
////    _record.setValue("imageacqdatetime",QDateTime::currentDateTime().time().toString());
////    /*
////     *  SCHEDULED,
////        INPROGRESS,
////        SUSPENDED,
////        COMPLETED,
////        DISCONTINUED
////     */
////    _record.setValue("imagesendstatus","SCHEDULED");
////    _record.setValue("imageprintstatus","SCHEDULED");
////    _model->insertRecord(_model->rowCount(),_record);

////    if(_model->submitAll())
////    {
////        qDebug()<<"Successfully sumited to the db.";
////    }
////    else
////    {
////        qDebug()<<"Failed to sumite to the db.";
////    }


////        QSqlRecord _record2 = _model2->record();
////        // initialize the record with dummy data
////        for(int a=0;a<=_record2.count();a++)
////        {
////            _record2.setValue(a,QString::number(1));
////        }
////        _record2.setValue("studyid: ",StudyId);
////        _record2.setValue("accessionnum",_dialog->GetPatientInfo(NewPatientDialog::AccessionNumber));

////        QString fullname;

////        if(_dialog->GetPatientInfo(NewPatientDialog::MiddleName) != "")
////        {
////            fullname = _dialog->GetPatientInfo(NewPatientDialog::FirstName)+"^"+
////                       _dialog->GetPatientInfo(NewPatientDialog::MiddleName)+"^"+
////                       _dialog->GetPatientInfo(NewPatientDialog::LastName);
////        }
////        else
////        {
////            fullname = _dialog->GetPatientInfo(NewPatientDialog::FirstName)+"^"+
////                       _dialog->GetPatientInfo(NewPatientDialog::LastName);
////        }

////        _record2.setValue("patientname",fullname);
////        _record2.setValue("patientid",_dialog->GetPatientInfo(NewPatientDialog::PatientID));
////        _record2.setValue("sex",_dialog->GetPatientInfo(NewPatientDialog::Gender));
////        _record2.setValue("refphysician",_dialog->GetPatientInfo(NewPatientDialog::ReferrinPhysician));
////        _record2.setValue("admittingtime",QDateTime::currentDateTime().date().toString(Qt::ISODate));
////        _record2.setValue("studyinstanceuid",dcmGenerateUniqueIdentifier(uid, SITE_SERIES_UID_ROOT));
////        _record2.setValue("visitcomment","LOCAL");
////        _record2.setValue("studystatus","SCHEDULED");
////        _record2.setValue("studystartdatetime",QDate::currentDate().toString(Qt::ISODate));


////        //OTHER FIELDS ARE NOT INSERTED YET
////        _model2->insertRecord(_model2->rowCount(),_record2);

////        if(_model2->submitAll())
////        {
////            qDebug()<<"Successfully sumited to the worklist table.";
////        }
////        else
////        {
////            qDebug()<<"Failed to submit to the worklist table. Due to: "<<_model2->lastError().text();;
////        }


////    //_database.close();


//}


void MainWindow::showEvent(QShowEvent *event)
{
    QWidget::showEvent( event );
    emit NotifyMainWindowIsLoaded();
}

//void MainWindow::on_Patient_selected(QSqlRecord record)
//{

//////    for(int i=0;i<record.count();i++)
//////    {
//////        qDebug()<<"the "<<record.fieldName(i) <<" fields value is "<<record.field(i).value().toString();
//////    }

////    ExposureDialog* _dialog =new ExposureDialog(this);
////    _dialog->SetRecord(&record);
////    _dialog->show();
//}

void MainWindow::on_action_Update_PACS_Server_Settings_triggered()
{
    LogMgr::instance()->LogSysDebug(tr("loading pacs server is triggered."));
    emit NotifyUpdatePACSSettingIsTriggered();
}

void MainWindow::on_action_Update_Worklist_Settings_triggered()
{
    LogMgr::instance()->LogSysDebug(tr("worklist settings is triggered"));
    emit NotifyUpdateWorklistSettingsIsTriggered();

}

void MainWindow::on_action_Load_Study_triggered()
{
    emit NotifyLoadStudyIsTriggered();
}

void MainWindow::on_action_Open_Study_triggered()
{
    // This is not best practice: a view class initiates another
    // view objet. however, because for this iteration we know
    // that the LoadImageDialog is a simple object with
    // no controller associated. We ignore the MVC pattern
    // however, for the future iteration we can make more
    // suffisticated dialogs and turn it inot MVC design
    //LogMgr::instance()->LogSysDebug(tr("open study is triggered"));
    //LoadImageDialog* _demo=new LoadImageDialog(this);
    //_demo->show();
    m_loadImageDlg.repaint();
    m_loadImageDlg.Show();
}

void MainWindow::on_action_Quick_Start_triggered()
{
    emit NotifyQuickStudyWorkFlowIsTriggered();

}

void MainWindow::on_action_Select_triggered()
{
    emit NotifyWorklistLoadIsTriggered();
}

void MainWindow::on_action_New_Study_triggered()
{
    emit NotifyNewStudyWorkFlowIsTriggered();
}
