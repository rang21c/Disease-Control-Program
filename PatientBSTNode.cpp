#include "PatientBSTNode.h"

PatientBSTNode::PatientBSTNode()
{
	Name = new char[32];
	Disease = 0;
	pLeft = NULL;
	pRight = NULL;
}

PatientBSTNode::~PatientBSTNode()
{
	delete[] Name;
	Disease = 0;
	pLeft = NULL;
	pRight = NULL;
}

char * PatientBSTNode::GetName()
{
	return Name;//return name
}

char PatientBSTNode::GetDisease()
{
	return Disease;//return disease
}

PatientBSTNode * PatientBSTNode::GetLeft()
{
	return pLeft;//return leftchild
}

PatientBSTNode * PatientBSTNode::GetRight()
{
	return pRight;//return rightchild
}

void PatientBSTNode::SetName(char * name)
{
	strcpy(Name, name);//set name
}

void PatientBSTNode::SetDisease(char disease)
{
	Disease = disease;//set disease
}

void PatientBSTNode::SetLeft(PatientBSTNode * node)
{
	this->pLeft = node;//set leftchild
}

void PatientBSTNode::SetRight(PatientBSTNode * node)
{
	this->pRight = node;//set rightchild
}
