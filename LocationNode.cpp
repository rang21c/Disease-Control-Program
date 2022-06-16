#include "LocationNode.h"

LocationNode::LocationNode()
{
	Location = new char[32];//memory allocation
	BST = new PatientBST;//memory allocation
	pLeft = NULL;
	pRight = NULL;
}

LocationNode::~LocationNode()
{
	delete[] Location;//memory release
	delete BST;//memory release
	pLeft = NULL;
	pRight = NULL;
}

char * LocationNode::GetLoc()
{
	return Location;//return location
}

PatientBST * LocationNode::GetBST()
{
	return BST;//return BST
}

LocationNode * LocationNode::GetLeft()
{
	return pLeft;//return leftchild
}

LocationNode * LocationNode::GetRight()
{
	return pRight;//return rightchild
}

void LocationNode::SetLoc(char * location)
{
	strcpy(Location, location);//set location
}

void LocationNode::SetPatientBST(PatientBST* bst)
{
	this->BST = bst;//set patientBST
}

void LocationNode::SetLeft(LocationNode * node)
{
	this->pLeft = node;//set leftchild
}

void LocationNode::SetRight(LocationNode * node)
{
	this->pRight = node;//set rightchild
}