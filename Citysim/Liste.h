#pragma once

template <typename Data>
class Liste
{
public:
	Liste();
	~Liste();

private:
	Data info;
	Liste *next;
};
