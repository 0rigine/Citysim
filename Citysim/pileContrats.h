#pragma once
#include "Contrat.h"

class pileContrats
{
public:
	pileContrats();
	pileContrats(Contrat* arg_contract, pileContrats* arg_next = NULL);
	~pileContrats();

	// Contrats
	void resolveAll(); // résolution des contrats de la liste
	void purge(pileContrats** current); // Retrait des contrats périmés
	bool isClosed(); // tester si le contrat est terminé
	vector<vector<vector<float>>> presenterContrats();

	// Manipulation de liste
	void removeAll(pileContrats** cur); // supprimer la liste chainée
	void removeNext(); // suppression du maillon suivant
	void removeThis(pileContrats** current, float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS]); // suppression d'un seul maillon correspondant
	void removeCurrent(pileContrats** to_remove); // suppression du maillon indiqué (ici to_remove correspond au pointeur sur le maillon courant indiqué par this)
	void addNext(Contrat* arg_contrat); // ajout d'un maillon
	bool isPresent(float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS]); // vérification de la présence d'un contrat
	Contrat* findContract(float arg_marchandises[][MERCHANDISES_LINES][MERCHANDISES_COLUMNS]); // trouver un contrat
	int numberByCity(City* ville); // retourne le nombre total de contrats d'une ville donnée

	// Accesseurs
	pileContrats* getNext() const;

private:
	Contrat *localContract;
	pileContrats *next;
};