#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Personne
{
	string nom;
	string prenom;
	int age;
	string telephone;
	string email;
	string adresse;
public :
	Personne(string Nom, string Prenom, int Age, string Telephone,string Email, string Adresse);
	virtual ~Personne() {};
	string getNom() { return nom; }
	string getPrenom() { return prenom; }
	int getAge() { return age; }
	string getTelephone() { return telephone; }
	string getAdresse() { return adresse; }
	string getEmail() { return email; }

	void setNom(string newVal) { this->nom = newVal; };
	void setPrenom(string newVal) { this->prenom = newVal; };
	void setAge(int newVal) { this->age = newVal; };
	void setTelephone(string newVal) { this->telephone = newVal; };
	void setAdresse(string newVal) { this->adresse= newVal; };
	void setEmail(string newVal) { this->email = newVal; };
};

