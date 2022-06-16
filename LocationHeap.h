#pragma once
#include "LocationHeapNode.h"
#include <fstream>
using namespace std;

class LocationHeap
{
private:
	LocationHeapNode ** Heap;
	int size;

public:
	LocationHeap();
	~LocationHeap();

	bool Insert(char * location);//insert location
	void Print();//level order print
	int Getsize();//return size
};
