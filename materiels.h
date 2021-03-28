#ifndef MATERIELS_H
#define MATERIELS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class materiels
{
public:
    materiels();
    materiels(int,QString, QString,QString,QString);

private:
    int id;
    QString nom, marque, deplacement, dateachat;

    int getID(){return id;}
    QString getNom(){return nom;}
    QString getMarque(){return marque;}
    QString getDeplacement(){return deplacement;}
    QString getDateachat(){return dateachat;}

    void setID(int id){this->id=id;}
    void setNOM(QString nom){this->nom=nom;}
    void setMarque(QString marque){this->marque=marque;}
    void setDeplacement(QString deplacement){this->deplacement=deplacement;}
    void setDateachat(QString dateachat){this->dateachat=dateachat;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * afficher_tri_alphabetique_materiels();
    QSqlQueryModel * afficher_tri_identifiant_materiels();
    QSqlQueryModel * rechercher_dynamique(QString);
    QSqlQueryModel * afficher_tri_descendant_materiels();

};

#endif // MATERIELS_H
