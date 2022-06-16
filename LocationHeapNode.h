#pragma once
#include <cstring>
#include <queue>
using namespace std;

class LocationHeapNode
{
private:
	int Count;
	char * Location;

public:
	LocationHeapNode();
	~LocationHeapNode();

	int GetCount();//return count
	char * GetLoc();//return location

	void SetCount(int count);//set count
	void SetLoc(char * location);//set location
};
