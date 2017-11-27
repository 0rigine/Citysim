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


// SOURCES


template <typename Data>
Liste<Data>::Liste()
{
}

template <typename Data>
Liste<Data>::~Liste()
{
}
