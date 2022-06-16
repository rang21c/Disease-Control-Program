#pragma once
#include "PatientBST.h"

class LocationNode
{
private:
	char * Location;
	PatientBST * BST;
	LocationNode * pLeft;
	LocationNode * pRight;

public:
	LocationNode();
	~LocationNode();

	char * GetLoc();//return location
	PatientBST * GetBST();//return patientBST
	LocationNode * GetLeft();//return leftchild
	LocationNode * GetRight();//return rightchild

	void SetLoc(char * location);//set location
	void SetPatientBST(PatientBST * bst);//set patientBST
	void SetLeft(LocationNode * node);//set leftchild
	void SetRight(LocationNode * node);//set rightchild
};
