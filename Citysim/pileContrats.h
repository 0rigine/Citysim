#pragma once
#include "Contrat.h"

class pileContrats
{
public:
	pileContrats();
	pileContrats(Contrat* arg_contract, pileContrats* arg_next = NULL);
	~pileContrats();

	
	void purge(); // Retrait des contrats périmés
	bool isClosed(); // tester si le contrat est terminé
	void removeAll(); // supprimer la liste chainée

	// Manipulation de liste
	void removeNext(); // suppression du maillon suivant
	void addNext(Contrat* arg_contrat); // ajout d'un maillon

	// Accesseurs
	pileContrats* getNext() const;

private:
	Contrat *localContract;
	pileContrats *next;
};