#pragma once
#include <cstring>

class PatientNode
{
private:
	char * Name;
	float Temperature;
	char Cough;
	char * Location;

public:
	PatientNode();
	~PatientNode();

	char * GetName();//return name
	float GetTemp();//return temperature
	char GetCough();//return cough
	char * GetLoc();//return location

	void SetName(char * name);//set name
	void SetTemp(float temp);//set temperature
	void SetCough(char cough);//set cough
	void SetLoc(char * location);//set location
};
