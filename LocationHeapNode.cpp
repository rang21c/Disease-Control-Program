#include "LocationHeapNode.h"

LocationHeapNode::LocationHeapNode()
{
	Count = 0;
	Location = new char[32];//memory allocation
}

LocationHeapNode::~LocationHeapNode()
{
	Count = 0;
	delete[] Location;//memory release
}

int LocationHeapNode::GetCount()
{
	return Count;//return count
}

char * LocationHeapNode::GetLoc()
{
	return Location;//return location
}

void LocationHeapNode::SetCount(int count)
{
	Count = count;//set count
}

void LocationHeapNode::SetLoc(char * location)
{
	strcpy(Location, location);//set location
}
