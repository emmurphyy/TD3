/**
* \file Jeu.hpp
* \authors Emlyn Murphy et Maya Manel Ait Djebara
* \date 24 mai 2023
* Cr�� le 24 mai 2023
*/

#pragma once
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>

class Jeu
{
public:
	//TODO: un constructeur par d�faut et un constructeur param�tr�.
	Jeu() = default;

	Jeu(const string& titre, int anneeSortie, const string& developpeur):
		titre_(titre), anneeSortie_(anneeSortie), developpeur_(developpeur) {}

	const std::string& getTitre() const     { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const         { return anneeSortie_; }
	void setAnneeSortie(unsigned annee)     { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	//TODO: Pouvoir acc�der � la liste de concepteurs.
	const Liste<shared_ptr<Concepteur>>& getConcepteurs() const { return concepteurs_; }

	//TODO: Votre m�thode pour trouver un concepteur selon un crit�re donn� par une lambda, en utilisant la m�thode de Liste.
	template <typename PredicatUnaire>
	shared_ptr<Concepteur> trouverConcepteur(const PredicatUnaire& critere)
	{
		return concepteurs_.trouverElement(forward<PredicatUnaire>(critere));
	}

private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	//TODO: Attribut de la liste des concepteurs du jeu
	Liste<shared_ptr<Concepteur>> concepteurs_;
};
