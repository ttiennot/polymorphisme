#include "Etudiant.h"

Etudiant::Etudiant(string Nom, string Prenom, int Age, string Telephone, string Email, string Adresse, vector<matiere> Matieres, string Classe) 
	: Personne(Nom, Prenom,Age, Telephone, Email, Adresse)
{
	this->matieres.swap(Matieres);
	this->classe = Classe;
}

Etudiant::~Etudiant()
{
}

void Etudiant::afficher()
{
}
