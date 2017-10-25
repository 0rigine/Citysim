#pragma once
#include <string>
#include <vector>
using namespace std;

class RandomName
{
public:
	RandomName();
	~RandomName();
	
	static string generate();

private:
	static vector<string> prefixes;
	static vector<string> syllabes;
	static vector<string> suffixes;
};

