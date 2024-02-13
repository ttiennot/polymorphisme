#include "Professeur.h"

Professeur::Professeur(string Nom, string Prenom, int Age, string Telephone, string Email, string Adresse, vector<string> Matiere, vector<int> Heure, float Tarif, float Salaire)
	:Personne(Nom, Prenom, Age, Telephone, Email, Adresse) , matiere(Matiere), heure(Heure), tarif(Tarif), salaire(Salaire)
{
	this->matiere.swap(Matiere);
	this->heure = Heure;
	this->tarif = Tarif;
	this->salaire = Salaire;
}

Professeur::~Professeur()
{

}

void Professeur::afficher()
{

}
