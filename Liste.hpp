/**
* \file Liste.hpp
* \authors Emlyn Murphy et Maya Manel Ait Djebara
* \date 24 mai 2023
* Créé le 24 mai 2023
*/

#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"

template <typename T>
class Liste
{
public:
	//TODO: Constructeurs et surcharges d'opérateurs
	Liste() = default;

	Liste(int capacite) : capacite_(capacite), nElements_(capacite)
	{
		elements_ = make_unique<shared_ptr<T>[]>(capacite);
	}

	Liste(const Liste<T>& copie) : capacite_(copie.capacite_), nElements_(copie.nElements_) 
	{
		elements_ = make_unique<shared_ptr<T>[]>(copie.nElements_);
		for (int i = 0; i < nElements_; ++i) 
		{
			elements_[i] = copie.elements_[i];
		}
	}

	shared_ptr<T>& operator[] (int position) 
	{
		return elements[position];
	}

	Liste<T>& operator = (Liste<T>&&) noexcept = default;

	//TODO: Méthode pour ajouter un élément à la liste
	void ajouterElement(shared_ptr<T> element) 
	{
		elements_[nElements_++] = move(element);
	}

	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//TODO: Méthode pour changer la capacité de la liste
	void changerCapaciteListe(int nouvelleCapacite)
	{
		unique_ptr<shared_ptr<T>[]> nouvelleListe = make_unique<shared_ptr<T>[]>(nouvelleCapacite);
		for (int i = 0; i < nElements_; ++i)
		{
			nouvelleListe[i] = elements_[i];
		}
		elements_ = move(nouvelleListe);
		capacite_ = nouvelleCapacite;
	}

	//TODO: Méthode pour trouver une élément selon un critère (lambda).
	template <typename PredicatUnaire>
	shared_ptr<T> trouverElement(const PredicatUnaire& critere)
	{
		for (unsigned i = 0; i < nElements_; ++i)
		{
			if (critere(*elements_[i]))
			{
				return elements_[i];
			}
		}
		return nullptr;
	}

private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les éléments de la liste.
	unique_ptr<shared_ptr<T>[]> elements_;
};
