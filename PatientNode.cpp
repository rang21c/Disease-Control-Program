#include "PatientNode.h"
#include <cstring>
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

PatientNode::PatientNode()
{
	Name = new char[32];//memory allocation
	Temperature = 0;
	Cough = 0;
	Location = new char[32];//memory allocation
}

PatientNode::~PatientNode()
{
	delete[] Name;//memory release
	Temperature = 0;
	Cough = 0;
	delete[] Location;//memory release
}

char * PatientNode::GetName()
{
	return Name;//return name
}

float PatientNode::GetTemp()
{
	return Temperature;//return temperature
}

char PatientNode::GetCough()
{
	return Cough;//return cough
}

char * PatientNode::GetLoc()
{
	return Location;//return location
}

void PatientNode::SetName(char * name)
{
	strcpy(Name, name);//set name
}

void PatientNode::SetTemp(float temp)
{
	Temperature = temp;//set temperature
}

void PatientNode::SetCough(char cough)
{
	Cough = cough;//set cough
}

void PatientNode::SetLoc(char * location)
{
	strcpy(Location, location);//set location
}