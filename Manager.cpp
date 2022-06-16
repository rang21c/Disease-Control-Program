#include "Manager.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

Manager::Manager()
{//Memory dynamic allocation
    ds_queue = new queue<PatientNode*>;
    ds_bst = new LocationBST;
    ds_heap = new LocationHeap;
}

Manager::~Manager()
{//Memory release
    delete ds_queue;
    delete ds_bst;
    delete ds_heap;
}

void Manager::run(const char * command)
{
    const char* locitem[8] = { "Gwangju", "Daegu", "Seoul", "Busan", "Daejeon", "Incheon", "Ulsan" };
    for (int i = 0; i < 7; i++)
    {//Make LocationBST
        LocationNode* a = new LocationNode;
        string loc1 = locitem[i];
        char loc[32];
        strcpy(loc, loc1.c_str());
        a->SetLoc(loc);//set location
        ds_bst->Insert_Location(a);//make Location_BST
    }
    fin.open(command);//read file open
    flog.open("log.txt", ios::app);//write file open
    if(!fin)
    {//When the file doesn't open
        flog << "File Open Error" << endl;
        return;
    }
    char cmd[32];
    while (!fin.eof())
    {
        fin.getline(cmd, 32);//read line
        char* tmp = strtok(cmd, " ");//word cutting
        if (strcmp(tmp, "LOAD") == 0)
        {
            if (LOAD())
                PrintSuccess(tmp);//LOAD success
            else
                PrintErrorCode(100);//LOAD fail
        }
        else if (strcmp(tmp, "ADD") == 0)
        {
            char* name = strtok(NULL, " ");
            char* temperature = strtok(NULL, " ");
            char* cough = strtok(NULL, " ");
            char* location = strtok(NULL, " ");
            char* check = strtok(NULL, " ");//CHECK OVER PARAMETER
            if (name == NULL || temperature == NULL || cough == NULL || location == NULL || check != NULL)
            {//if parameter not exist
                PrintErrorCode(200);//ADD fail
            }
            else
            {
                if (ADD(name, atof(temperature), *cough, location))
                    continue;//ADD success
            }
        }
        else if (strcmp(tmp, "QPOP") == 0)
        {
            char* num = strtok(NULL, " ");
            char* check = strtok(NULL, " ");//CHECK OVER PARAMETER
            if (num == NULL || check != NULL)
            {//if parameter not exist
                PrintErrorCode(300);//QPOP fail
            }
            else 
            {
                if (QPOP(atoi(num)))
                    PrintSuccess(tmp);//QPOP success
                else
                    PrintErrorCode(300);//QPOP fail
            }
        }
        else if (strcmp(tmp, "SEARCH") == 0)
        {
            char* name = strtok(NULL, " ");
            char* check = strtok(NULL, " ");//CHECK OVER PARAMETER
            if (name == NULL || check != NULL)
            {//if parameter not exist
                PrintErrorCode(400);//SEARCH fail
            }
            else
            {
                if (SEARCH(name))
                    continue;//SEARCH success
                else
                    PrintErrorCode(400);//SEARCH fail
            }
        }
        else if (strcmp(tmp, "PRINT") == 0)
        {
            char* bst_heap = strtok(NULL, " ");
            char* sel = strtok(NULL, " ");
            char* check = strtok(NULL, " ");//CHECK OVER PARAMETER
            if (bst_heap == NULL || (bst_heap == "B" && sel == NULL) || check != NULL)
            {//if parameter not exist
                PrintErrorCode(500);//PRINT fail
            }
            else
            {
                if (PRINT(bst_heap, sel))
                    continue;//PRINT success
                else
                    PrintErrorCode(500);//PRINT fail
            }
        }
        else if (strcmp(tmp, "BPOP") == 0)
        {
            char* name = strtok(NULL, " ");
            char* check = strtok(NULL, " ");//CHECK OVER PARAMETER
            if (name == NULL || check != NULL)
            {//if parameter not exist
                PrintErrorCode(600);//SEARCH fail
            }
            else
            {
                if (BPOP(name) && name)
                    PrintSuccess(tmp);//BPOP success
                else if (!name || !BPOP(name))
                    PrintErrorCode(600);//BPOP fail
            }
        }
        else if (strcmp(tmp, "EXIT") == 0)
        {
            PrintSuccess(tmp);//EXIT success
            break;//loop exit
        }
        else
        {//print error
            flog << "========== ERROR ==========" << endl;
            flog << "Command Error" << endl;
            flog << "===========================" << endl << endl;
            cout << "========== ERROR ==========" << endl;
            cout << "Command Error" << endl;
            cout << "===========================" << endl << endl;
        }
    }
    fin.close();//fin close
    flog.close();//flog close
}

bool Manager::LOAD()
{
    fstream temp;
    temp.open("data.txt");//read file open
    if (!temp || !ds_queue->empty())//file open fail || queue is not empty
        return false;//LOAD fail
    char cmd[32];
    while (!temp.eof())
    {
        PatientNode* patient = new PatientNode;
        temp.getline(cmd, 32);//read line
        char* name = strtok(cmd, " ");
        char* temperature = strtok(NULL, " ");
        char* cough = strtok(NULL, " ");
        char* location = strtok(NULL, " ");
        if (cmd[0] == 0)
            break;
        patient->SetName(name);//set name
        patient->SetTemp(atof(temperature));//char* to float
        patient->SetCough(*cough);//set cough
        patient->SetLoc(location);//set location
        ds_queue->push(patient);//push queue
    }
    temp.close();
    return true;//LOAD success
}

bool Manager::ADD(char* name, float temperature, char cough, char* location)
{
    PatientNode* patient = new PatientNode;
    patient->SetName(name);//set name
    patient->SetTemp(temperature);//char* to float
    patient->SetCough(cough);//set cough
    patient->SetLoc(location);//set location
    ds_queue->push(patient);//push queue
    PrintSuccess_ADD(name, temperature, cough, location);
    return true;//ADD success
}

bool Manager::QPOP(int num)
{//Patient_Queue -> Location_BST
    if (ds_queue->size() < num)
        return false;//QPOP fail
    for (int i = 0; i < num; i++)
    {//loop count num
        ds_bst->Insert_Patient(ds_queue->front());//insert BST
        ds_queue->pop();//pop queue front
    }
    return true;//QPOP success
}

bool Manager::SEARCH(char* name)
{
    if (ds_bst->Search(name) == false)
        return false;//SEARCH fail
    return true;//SEARCH success
}

bool Manager::PRINT(char* b_or_h, char* select)
{
    if (strcmp(b_or_h, "B") == 0)
    {//first parameter is "B"
        flog << "========== " << "PRINT" << " ==========" << endl;
        cout << "========== " << "PRINT" << " ==========" << endl;
        flog << "BST" << endl;
        cout << "BST" << endl;
        if (strcmp(select, "PRE") == 0)
        {//second parameter is "PRE"
            ds_bst->Print_PRE();
        }
        else if (strcmp(select, "IN") == 0)
        {//second parameter is "IN"
            ds_bst->Print_IN();
        }
        else if (strcmp(select, "POST") == 0)
        {//second parameter is "POST"
            ds_bst->Print_POST();
        }
        else if (strcmp(select, "LEVEL") == 0)
        {//second parameter is "LEVEL"
            ds_bst->Print_LEVEL();
        }
    }
    else if (strcmp(b_or_h, "H") == 0)
    {//first parameter is "H"
        if (ds_heap->Getsize() == 0)//No data in heap
            return false;//PRINT fail
        flog << "========== " << "PRINT" << " ==========" << endl;
        cout << "========== " << "PRINT" << " ==========" << endl;
        flog << "Heap" << endl;
        cout << "Heap" << endl;
        ds_heap->Print();//call heap print function
    }
    flog << "============================" << endl << endl;
    cout << "============================" << endl << endl;
    return true;//PRINT success
}

bool Manager::BPOP(char* name)
{
    if (char* temp = ds_bst->Delete(name))
    {
        ds_heap->Insert(temp);//Insert location
        return true;//BPOP success
    }
    else if (temp == NULL)//NO EXIST "name"
    {
        return false;//BPOP fail
    }
    else
        return false;
}

void Manager::PrintErrorCode(int num)
{//print error code
    flog << "========== ERROR ==========" << endl;
    flog << num << endl;
    flog << "===========================" << endl << endl;
    cout << "========== ERROR ==========" << endl;
    cout << num << endl;
    cout << "===========================" << endl << endl;
}

void Manager::PrintSuccess(char * act)
{//print success
    flog << "========== " << act << " ==========" << endl;
    flog << "Success" << endl;
    flog << "============================" << endl << endl;
    cout << "========== " << act << " ==========" << endl;
    cout << "Success" << endl;
    cout << "============================" << endl << endl;
}

void Manager::PrintSuccess_ADD(char* act1, float act2, char act3, char* act4)
{//print add success
    flog << "========== " << "ADD" << " ==========" << endl;
    flog << act1 << "/" << act2 << "/" << act3 << "/" << act4 << endl;
    flog << "============================" << endl << endl;
    cout << "========== " << "ADD" << " ==========" << endl;
    cout << act1 << "/" << act2 << "/" << act3 << "/" << act4 << endl;
    cout << "============================" << endl << endl;
}