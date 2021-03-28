#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{
public:
    fournisseur();
    fournisseur(int,QString, QString,QString,QString);
    int getID(){return id;}
    QString getNom(){return nom;}
    QString getMarque(){return prenom;}
    QString getDeplacement(){return addr;}
    QString getDateachat(){return email;}

    void setID(int id){this->id=id;}
    void setNOM(QString nom){this->nom=nom;}
    void setMarque(QString prenom){this->prenom=prenom;}
    void setDeplacement(QString addr){this->addr=addr;}
    void setDateachat(QString email){this->email=email;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * afficher_tri_alphabetique_fournisseur();
    QSqlQueryModel * afficher_tri_identifiant_fournisseur();
    QSqlQueryModel * rechercher_dynamique(QString);
    QSqlQueryModel * afficher_tri_descendant_fournisseur();
private:
    int id;
    QString nom, prenom, addr, email;


};

#endif // FOURNISSEUR_H
