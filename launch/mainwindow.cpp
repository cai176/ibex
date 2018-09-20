#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpatientdialog.h"
#include "exposuredialog.h"
#include "QMessageBox"
#include "pacsnodesettingsdialog.h"
#include "LoadStudyDialog.h"
#include "worklistserversettingsdialog.h"
#include "worklistdialog.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _dialog= new NewPatientDialog(this);
    connect(_dialog,SIGNAL(accepted()),this,SLOT(on_newPatient_accepted()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_Study_triggered()
{

    _dialog->setModal(true);
    _dialog->show();

}

void MainWindow::on_newPatient_accepted()
{
    qDebug()<< "Dialog RESULT:"<<_dialog->result();
}

void MainWindow::on_action_Quick_Start_triggered()
{
    ExposureDialog* _dialog =new ExposureDialog(this);
    //_dialog->show();
    _dialog->showMaximized();

}

void MainWindow::on_action_Update_PACS_Server_Settings_triggered()
{
   PacsNodeSettingsDialog* _dialog = new PacsNodeSettingsDialog(this);
   _dialog->show();

}

void MainWindow::on_action_Load_Study_triggered()
{

    LoadStudyDialog* _dialog=new LoadStudyDialog(this);
    _dialog->show();
}

void MainWindow::on_action_Update_Worklist_Settings_triggered()
{
    WorklistServerSettingsDialog* worklistDlg =new WorklistServerSettingsDialog(this);
    worklistDlg->show();
}

void MainWindow::on_action_Open_Study_triggered()
{
    WorkListDialog* wrkDlg=new WorkListDialog(this);
    wrkDlg->show();
}
