#pragma once

template <typename Data>
class Liste;
class Contrat;

class pileContrats
{
public:
	pileContrats();
	~pileContrats();

private:
	Liste< Contrat* > contractsList; // liste des contrats
};