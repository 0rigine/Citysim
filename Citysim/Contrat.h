#pragma once

template <typename Classe>
class Contrat
{
public:
	Contrat();
	~Contrat();
	Classe &associate;
	int timeLeft;
	float &resourceUsed;
	float cost;
	float quantity;
protected:

};

template <typename Classe>
Contrat<Classe>::Contrat()
{
}

template <typename Classe>
Contrat<Classe>::~Contrat()
{
}