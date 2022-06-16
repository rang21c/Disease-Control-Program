#pragma once
#include "PatientBSTNode.h"
#include "PatientNode.h"
#include <fstream>
#include <queue>
using namespace std;

class PatientBST
{
private:
	PatientBSTNode * Root;

public:
	PatientBST();
	~PatientBST();

	PatientBSTNode * GetRoot();
	bool Insert(PatientNode * node);//insert patientnode
	bool Search(char * name);//search function
	bool Delete(char * name);//delete function
	void Print_PRE(PatientBSTNode * node);//pre order
	void Print_IN(PatientBSTNode * node);//in order
	void Print_POST(PatientBSTNode * node);//post order
	void Print_LEVEL();//level order
	void POST_ORDER(PatientBSTNode* node);//post order
};
