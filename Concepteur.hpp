/**
* \file Concepteur.hpp
* \authors Emlyn Murphy et Maya Manel Ait Djebara
* \date 24 mai 2023
* Cr�� le 24 mai 2023
*/

#pragma once
#include <string>

class Concepteur
{
public:
	//TODO: Un constructeur par d�faut et un constructeur param�tr�.
	Concepteur() = default;

	Concepteur(const string& nom, int anneeNaissance, const string& pays) : 
		nom_(nom), anneeNaissance_(anneeNaissance), pays_(pays) {}

	const std::string& getNom() const     { return nom_; }
	void setNom(const std::string& nom)   { nom_ = nom; }
	int getAnneeNaissance() const         { return anneeNaissance_; }
	void setAnneeNaissance(int annee)     { anneeNaissance_ = annee; }
	const std::string& getPays() const    { return pays_; }
	void setPays(const std::string& pays) { pays_ = pays; }

private:
	std::string nom_;
	unsigned anneeNaissance_;
	std::string pays_;
};
