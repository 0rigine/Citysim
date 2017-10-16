#pragma once

class Tree
{
public:
	// Constructors & destructor
	Tree();
	Tree(Tree* argChild, Tree* argBrother);
	virtual ~Tree();

	// Measuring
	int heighTree(int heigh = 1); // function to calculate max heigh of a tree from a Tree
	int widthTree(int width = 1); // function to calculate the width from a Tree

	// Build
	int newChild();
	int newBrother();

	// Get Access
	static int instanceNumber();
	Tree* getChild() const;
	Tree* getBrother() const;

private:
	// Attributes
	static int TreeNumber;

	Tree* brother;
	Tree* child;
};
