#include "stdafx.h"
#include "Tree.h"
#include <iostream>

// Static members
int Tree::TreeNumber = 0;


// Constructors & destructor
Tree::Tree() :
	child(NULL),
	brother(NULL)
{
	++Tree::TreeNumber;
}

Tree::Tree(Tree* argChild, Tree* argBrother) :
	brother(argBrother),
	child(argChild)
{
	++Tree::TreeNumber;
}

Tree::~Tree()
{
	if (child != 0)
	{
		delete child;
	}
	if (brother != 0)
	{
		delete brother;
	}
	--Tree::TreeNumber;
}


// Measuring
int Tree::heighTree(int heigh)
{
	int lenChild(0), lenBrother(0);
	if (child != NULL)
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
	else if (brother != NULL)
	{
		lenBrother = brother->heighTree(heigh);
		if (heigh < lenBrother)
		{
			return lenBrother;
		}
	}
	return heigh;
}

int Tree::widthTree(int width)
{
	if (brother != NULL)
	{
		return brother->widthTree(width + 1);
	}

	return width;
}


// Build
int Tree::newChild()
{
	if (child == 0)
	{
		child = new Tree(argdata);
	}
	else if (child->brother == NULL)
	{
		child->brother = new Tree(argdata);
	}
	else
	{
		return child->brother->newBrother(argdata);
	}

	return 0;
}

int Tree::newBrother()
{
	if (brother == NULL)
	{
		brother = new Tree();
	}
	else
	{
		return brother->newBrother();
	}

	return 0;
}


// Get Access
int Tree::instanceNumber()
{
	return Tree::TreeNumber;
}

Tree* Tree::getChild() const
{
	return child;
}

Tree* Tree::getBrother() const
{
	return brother;
}