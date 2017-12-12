#pragma once
#include "Contrat.h"

class pileContrats
{
public:
	pileContrats();
	pileContrats(Contrat* arg_contract, pileContrats* arg_next = NULL);
	~pileContrats();

	// Contrats
	void resolveAll(); // r�solution des contrats de la liste
	void purge(pileContrats** current); // Retrait des contrats p�rim�s
	bool isClosed(); // tester si le contrat est termin�
	vector<vector<vector<float>>> presenterContrats();

	// Manipulation de liste
	void removeAll(pileContrats** cur); // supprimer la liste chain�e
	void removeNext(); // suppression du maillon suivant
	void removeThis(pileContrats** current, float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS]); // suppression d'un seul maillon correspondant
	void removeCurrent(pileContrats** to_remove); // suppression du maillon indiqu� (ici to_remove correspond au pointeur sur le maillon courant indiqu� par this)
	void addNext(Contrat* arg_contrat); // ajout d'un maillon
	bool isPresent(float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS]); // v�rification de la pr�sence d'un contrat
	Contrat* findContract(float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS]); // trouver un contrat
	int numberByCity(City* ville); // retourne le nombre total de contrats d'une ville donn�e

	// Accesseurs
	pileContrats* getNext() const;

private:
	Contrat *localContract;
	pileContrats *next;
};