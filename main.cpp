/**
* Programme qui permet d'afficher une liste de jeux accompagé de ses informations, soit son titre, 
* son année de sortie, son développeur et la liste de ses concepteurs.
* \file main.cpp
* \authors Emlyn Murphy et Maya Manel Ait Djebara
* \date 24 mai 2023
* Créé le 24 mai 2023
*/

#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "Jeu.hpp"
#include "lectureFichierJeux.hpp"
#include <iostream>
#include <fstream>
using namespace std;

//TODO: Vos surcharges d'opérateur <<

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi(); 
	#pragma endregion
	
	Liste<Jeu> lj = creerListeJeux("jeux.bin");
	static const string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

	//TODO: Les l'affichage et l'écriture dans le fichier devraient fonctionner.
	//cout << ligneSeparation << lj;
	//ofstream("sortie.txt") << lj;

	//TODO: Compléter le main avec les tests demandés.
	//TODO: S'assurer qu'aucune ligne de code est non couverte.
	//NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	//NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.
}