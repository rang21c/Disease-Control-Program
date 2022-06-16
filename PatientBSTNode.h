#pragma once
#include <cstring>

class PatientBSTNode
{
private:
	char * Name;
	char Disease;

	PatientBSTNode * pLeft;
	PatientBSTNode * pRight;

public:
	PatientBSTNode();
	~PatientBSTNode();

	char * GetName();//return name
	char GetDisease();//return disease
	PatientBSTNode * GetLeft();//return leftchild
	PatientBSTNode * GetRight();//return rightchild

	void SetName(char * name);//set name
	void SetDisease(char disease);//set disease
	void SetLeft(PatientBSTNode * node);//set leftchild
	void SetRight(PatientBSTNode * node);//set rightchild
};
