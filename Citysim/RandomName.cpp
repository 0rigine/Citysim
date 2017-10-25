#include "stdafx.h"
#include "RandomName.h"
#include <random>

 vector<string> RandomName::prefixes =
{
	"",
	"bel",
	"nar",
	"xan",
	"bell",
	"natr",
	"ev",
	"gas"
};

 vector<string> RandomName::syllabes =
{
	"",
	"adur",
	"aes",
	"anim",
	"appol",
	"imac",
	"educ",
	"equis",
	"extr",
	"guis",
	"hann",
	"equit",
	"amoran",
	"hum",
	"ialem",
	"illet",
	"opt",
	"usul",
	"yxir"
};

 vector<string> RandomName::suffixes =
{
	"",
	"us",
	"ix",
	"ox",
	"ith",
	"ath",
	"um",
	"ator",
	"ory",
	"one",
	"ais",
	"uch"
};

RandomName::RandomName()
{
}


RandomName::~RandomName()
{
}

string RandomName::generate()
{
	string name = "";
	name += prefixes[rand()%prefixes.size()];
	name += syllabes[rand() % syllabes.size()];
	name += suffixes[rand() % suffixes.size()];
	name[0] = name[0] - 32;
	return name;
}
