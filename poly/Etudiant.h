#pragma once
#include "Personne.h"
#include <vector>
typedef struct {
	string nom;
	float note;
}matiere;

class Etudiant : public Personne
{
	vector<matiere> matieres;
	string classe;
public :
	Etudiant(string Nom, 
		string Prenom, 
		int Age, 
		string Telephone, 
		string Email, 
		string Adresse, 
		vector<matiere> Matieres,
		string Classe);
	~Etudiant();
	void afficher();
};

