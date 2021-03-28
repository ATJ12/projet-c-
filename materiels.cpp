#include "materiels.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


materiels::materiels()
{
    this->id=0;
    this->nom="";
    this->marque="";
    this->deplacement="";
    this->dateachat="";
}
materiels::materiels(int id, QString nom, QString marque,QString deplacement,QString dateachat)
{
    this->id=id;
    this->nom=nom;
    this->marque=marque;
    this->deplacement=deplacement;
    this->dateachat=dateachat;
}

bool materiels::ajouter(){

    QSqlQuery query;

    query.prepare("insert into materiels (id,nom,marque,deplacement,dateachat)"
                  "values(:id,:nom,:marque,:deplacement,:dateachat)");
    QString ids=QString::number(id);
    query.bindValue(":id",ids);
    query.bindValue(":nom",nom);
    query.bindValue(":marque",marque);
    query.bindValue(":deplacement",deplacement);
    query.bindValue(":dateachat",dateachat);

    return query.exec();
}
QSqlQueryModel * materiels::afficher(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from materiels");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("deplacement"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("dateachat"));
    return query;
}

bool materiels::supprimer(int idd)
{
    QSqlQuery query;

    query.prepare("Delete from materiels where id=:id");
    QString idds=QString::number(idd);
    query.bindValue(":id",idds);
    return query.exec();
}

bool materiels::modifier(){
    QSqlQuery query1;
    query1.prepare("UPDATE materiels set nom=:nom,marque=:marque,deplacement=:deplacement,dateachat=:dateachat WHERE id=:id");
    query1.bindValue(":id",id);
    query1.bindValue(":nom",nom);
    query1.bindValue(":marque",marque);
    query1.bindValue(":deplacement",deplacement);
    query1.bindValue(":dateachat",dateachat);

    return (query1.exec());
}

QSqlQueryModel * materiels::afficher_tri_alphabetique_materiels(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from materiels ORDER BY nom");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("deplacement"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("dateachat"));
    return query;

}
QSqlQueryModel * materiels::afficher_tri_identifiant_materiels(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from materiels ORDER BY id");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("deplacement"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("dateachat"));
    return query;

}

QSqlQueryModel * materiels::rechercher_dynamique(QString nom){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from materiels where nom like '"+nom+"%' or id like '"+nom+"%' or marque like '"+nom+"%' or deplacememt like '"+nom+"%' or dateachat like '"+nom+"%' ");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("deplacement"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("dateachat"));
    return query;

}

QSqlQueryModel * materiels::afficher_tri_descendant_materiels(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from materiels ORDER BY id DESC");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("deplacement"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("dateachat"));
    return query;

}


