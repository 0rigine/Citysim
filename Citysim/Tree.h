#pragma once
#include <iostream>

template <typename dataType>
class Tree
{
public:
	// Constructors & destructor
	Tree();
	Tree(dataType argdata, Tree<dataType>* argChild = 0, Tree<dataType>* argBrother = 0);
	virtual ~Tree();

	// Measuring
	int heighTree(int heigh = 1); // function to calculate max heigh of a tree from a Tree
	int widthTree(int width = 1); // function to calculate the width from a Tree

								  // Build
	int newChild(dataType argdata);
	int newBrother(dataType argdata);

	// Get Access
	static int instanceNumber();
	Tree<dataType>* getChild() const;
	Tree<dataType>* getBrother() const;

protected:
	// Attributes
	static int TreeNumber;

	dataType data;
	Tree<dataType>* brother;
	Tree<dataType>* child;
};


// Static members
template <typename dataType>
int Tree<dataType>::TreeNumber = 0;


// Constructors & destructor
template <typename dataType>
Tree<dataType>::Tree() :
	child(0),
	brother(0)
{
	++Tree<dataType>::TreeNumber;
}

template <typename dataType>
Tree<dataType>::Tree(dataType argdata, Tree<dataType>* argChild, Tree<dataType>* argBrother) :
	brother(argBrother),
	child(argChild),
	data(argdata)
{
	++Tree<dataType>::TreeNumber;
}

template <typename dataType>
Tree<dataType>::~Tree()
{
	if (child != 0)
	{
		delete child;
	}
	if (brother != 0)
	{
		delete brother;
	}
	--Tree<dataType>::TreeNumber;
}


// Measuring
template<typename dataType>
int Tree<dataType>::heighTree(int heigh)
{
	int lenChild(0), lenBrother(0);
	if (child != 0)
	{
		lenChild = child->heighTree(heigh + 1);
		if (brother != 0)
		{
			lenBrother = brother->heighTree(heigh);
			if (lenChild < lenBrother)
			{
				return lenBrother;
			}
		}
		return lenChild;
	}
	else if (brother != 0)
	{
		lenBrother = brother->heighTree(heigh);
		if (heigh < lenBrother)
		{
			return lenBrother;
		}
	}
	return heigh;
}

template<typename dataType>
int Tree<dataType>::widthTree(int width)
{
	if (brother != 0)
	{
		return brother->widthTree(width + 1);
	}

	return width;
}


// Build
template <typename dataType>
int Tree<dataType>::newChild(dataType argdata)
{
	if (child == 0)
	{
		child = new Tree<dataType>(argdata);
	}
	else if (child->brother == 0)
	{
		child->brother = new Tree<dataType>(argdata);
	}
	else
	{
		return child->brother->newBrother(argdata);
	}

	return 0;
}

template<typename dataType>
int Tree<dataType>::newBrother(dataType argdata)
{
	if (brother == 0)
	{
		brother = new Tree<dataType>(argdata);
	}
	else
	{
		return brother->newBrother(argdata);
	}

	return 0;
}


// Get Access
template<typename dataType>
int Tree<dataType>::instanceNumber()
{
	return Tree<dataType>::TreeNumber;
}

template<typename dataType>
Tree<dataType>* Tree<dataType>::getChild() const
{
	return child;
}

template<typename dataType>
Tree<dataType>* Tree<dataType>::getBrother() const
{
	return brother;
}
