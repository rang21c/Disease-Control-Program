#pragma once
#include "PatientNode.h"
#include "LocationBST.h"
#include "LocationHeap.h"
#include "PatientBST.h"

class Manager
{
private:
	queue <PatientNode *> * ds_queue;//patient queue
	LocationBST * ds_bst;//location bst
	LocationHeap * ds_heap;//location max heap
	ifstream fin;//read file
	ofstream flog;//write file

public:
	Manager();
	~Manager();

	void run(const char * command);//main fuction
	bool LOAD();
	bool ADD(char* name, float temperature, char cough, char* location);
	bool QPOP(int num);
	bool SEARCH(char* name);
	bool PRINT(char* b_or_h, char* select);
	bool BPOP(char* name);

	//error and success print
	void PrintErrorCode(int num);
	void PrintSuccess(char * act);
	void PrintSuccess_ADD(char* act1, float act2, char act3, char* act4);
};
