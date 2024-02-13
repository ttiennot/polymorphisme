#pragma once
#include "Personne.h"
class Professeur : public Personne
{

	vector<string> matiere;
	vector<int> heure;
	float tarif;
	float salaire;

public :
	Professeur(string Nom,
		string Prenom,
		int Age,
		string Telephone,
		string Email,
		string Adresse, 
		vector<string>Matiere,
		vector<int> Heure,
		float Tarif,
		float Salaire);
	~Professeur();
	void afficher();
};

