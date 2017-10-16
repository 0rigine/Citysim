#pragma once

class Skill
{
public:
	Skill();
	~Skill();

private:
	// Statut
	int statut; // 2 si debloque, 1 si en developpement, 0 sinon

	// Effets
	int maxEmployes; // augmentation du nombre max d'employes sur la ressource
	float coeffProdTotale, bonusProdEmploye; // coefficient de production totale (+25% par ex) et bonus fixe sur la prod par employe
	float consoHabitant; // ajout sur la conso par habitant

	// Couts
	float cost_budget, cost_food, cost_energy, cost_happyness; // couts de developpement de la competence
	float cost_time; // temps necessaire au developpement
};

Skill::Skill()
{
}

Skill::~Skill()
{
}