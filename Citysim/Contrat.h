#pragma once

class Contrat
{
public:
	Contrat();
	~Contrat();

private:
	int timeLeft;
	float &resourceUsed;
	float cost;
	float quantity;
};

Contrat::Contrat()
{
}

Contrat::~Contrat()
{
}