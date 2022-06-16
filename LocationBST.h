#pragma once
#include "LocationNode.h"
#include "PatientNode.h"

class LocationBST
{
private:
	LocationNode * Root;

public:
	LocationBST();
	~LocationBST();

	LocationNode * GetRoot();
	void Insert_Location(LocationNode * node);//make location bst
	bool Insert_Patient(PatientNode * node);//make patient bst
	bool Search(char * name);
	char * Delete(char * name);
	void Print_PRE();//pre order
	void Print_IN();//in order
	void Print_POST();//post order
	void Print_LEVEL();//level order
	void POST_ORDER(LocationNode* cur);
};	
