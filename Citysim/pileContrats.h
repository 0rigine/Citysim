#pragma once
#include "Contrat.h"

class pileContrats
{
public:
	pileContrats();
	pileContrats(Contrat* arg_contract, pileContrats* arg_next = NULL);
	~pileContrats();

	
	void purge(); // Retrait des contrats p�rim�s
	bool isClosed(); // tester si le contrat est termin�

	// Manipulation de liste
	void removeAll(); // supprimer la liste chain�e
	void removeNext(); // suppression du maillon suivant
	void addNext(Contrat* arg_contrat); // ajout d'un maillon
	bool isPresent(float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS]); // v�rification de la pr�sence d'un contrat
	Contrat* findContract(float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS]); // trouver un contrat

	// Accesseurs
	pileContrats* getNext() const;

private:
	Contrat *localContract;
	pileContrats *next;
};