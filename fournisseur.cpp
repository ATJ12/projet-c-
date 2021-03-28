#include "fournisseur.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


fournisseur::fournisseur()
{
    this->id=0;
    this->nom="";
    this->prenom="";
    this->addr="";
    this->email="";
}
fournisseur::fournisseur(int id, QString nom, QString prenom ,QString addr,QString email)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->addr=addr;
    this->email=email;
}

bool fournisseur::ajouter(){

    QSqlQuery query;

    query.prepare("insert into fournisseur (id,nom,prenom,addr,email)"
                  "values(:id,:nom,:prenom,:addr,:email)");
    QString ids=QString::number(id);
    query.bindValue(":id",ids);
    query.bindValue(":nom",nom);
    query.bindValue(":marque",prenom);
    query.bindValue(":addr",addr);
    query.bindValue(":email",email);

    return query.exec();
}
QSqlQueryModel * fournisseur::afficher(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from fournisseur");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    return query;
}
bool fournisseur::supprimer(int idd)
{
    QSqlQuery query;

    query.prepare("Delete from fournisseur where id=:id");
    QString idds=QString::number(idd);
    query.bindValue(":id",idds);
    return query.exec();
}

bool fournisseur::modifier(){
    QSqlQuery query1;
    query1.prepare("UPDATE fournisseur set nom=:nom,prenom=:prenom,addr=:addr,email=:email WHERE id=:id");
    query1.bindValue(":id",id);
    query1.bindValue(":nom",nom);
    query1.bindValue(":prenom",prenom);
    query1.bindValue(":addr",addr);
    query1.bindValue(":email",email);

    return (query1.exec());
}

QSqlQueryModel * fournisseur::afficher_tri_alphabetique_fournisseur(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from fournisseur ORDER BY nom");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    return query;

}
QSqlQueryModel * fournisseur::afficher_tri_identifiant_fournisseur(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from fournisseur ORDER BY id");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("email"));
    return query;

}

QSqlQueryModel * fournisseur::rechercher_dynamique(QString nom){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from fournisseur where nom like '"+nom+"%' or id like '"+nom+"%' or prenom like '"+nom+"%' or addr like '"+nom+"%' or email like '"+nom+"%' ");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("deplacement"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("dateachat"));
    return query;

}

QSqlQueryModel * fournisseur::afficher_tri_descendant_fournisseur(){

    QSqlQueryModel * query = new QSqlQueryModel();
    query->setQuery("select * from fournisseur ORDER BY id DESC");
    query->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("marque"));
    query->setHeaderData(1,Qt::Horizontal,QObject::tr("deplacement"));
    query->setHeaderData(2,Qt::Horizontal,QObject::tr("dateachat"));
    return query;

}


