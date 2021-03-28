#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDate>
#include<QDateTime>
#include<QDesktopServices>
#include<QSqlQuery>
#include <QMessageBox>
#include <QTabWidget>
#include <QString>
#include <QTextDocument>
#include <QPainter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QStringList>
#include<QPropertyAnimation>
#include<QEasingCurve>
#include<QParallelAnimationGroup>
#include<QGraphicsOpacityEffect>
#include <QRegExpValidator>
#include <QSystemTrayIcon>
#include <QDesktopServices>
#include <QUrl>
#include <QSound>
#include <QtMultimedia>
#include <QWidget>
#include <QMediaPlayer>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
            QSqlQuery *query=new QSqlQuery();
            int ide=ui->ajout_id_fournisseur->text().toInt();
            QString nome=ui->ajout_fournisseur_nom->text();
            QString prenom=ui->ajout_fournisseur_prenom->text();
            QString adresse=ui->ajout_fournisseur_adresse->text();
            QString email=ui->ajout_fournisseur_email->text();
            fournisseur e(ide,nome,prenom,adresse,email);
            bool test=e.ajouter();
            if(test)
            {

                QMessageBox::information(nullptr, QObject::tr("Ajout fournisseur"),
                                         QObject::tr("ajout avec succès.\n""Click Cancel to exit."), QMessageBox::Cancel);
                ui->tableView->setModel(tempfournisseur.afficher());
                ui->ajout_id_fournisseur->clear();
                ui->ajout_fournisseur_nom->clear();
                ui->ajout_fournisseur_prenom->clear();
                ui->ajout_fournisseur_adresse->clear();
                ui->ajout_fournisseur_email->clear();
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Ajout fournisseur"),
                                         QObject::tr("ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

}
