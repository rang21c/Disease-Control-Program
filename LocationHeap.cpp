#include "LocationHeap.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

LocationHeap::LocationHeap()
{
    size = 0;
    Heap = new LocationHeapNode*[8];//memory allocation 7+1
}

LocationHeap::~LocationHeap()
{
    size = 0;
    delete[] Heap;//memory release
}

bool LocationHeap::Insert(char * location)
{
    //BPOP
    for (int i = 1; i <= size; i++)
    {//Location check
        if (strcmp(Heap[i]->GetLoc(), location) == 0)
        {//Location already exists
            Heap[i]->SetCount(Heap[i]->GetCount() + 1);
            while ((i != 1) && (Heap[i]->GetCount() > Heap[i / 2]->GetCount()))
            {//SWAP information
                int temp_count = Heap[i]->GetCount();
                char temp_loc[32];
                string loc = Heap[i]->GetLoc();
                strcpy(temp_loc, loc.c_str());
                Heap[i]->SetCount(Heap[i/2]->GetCount());
                Heap[i]->SetLoc(Heap[i/2]->GetLoc());
                Heap[i / 2]->SetCount(temp_count);
                Heap[i / 2]->SetLoc(temp_loc);
                i /= 2;//move parent node
            }
            return true;
        }
    }
    LocationHeapNode* newnode = new LocationHeapNode;
    newnode->SetLoc(location);//set location
    newnode->SetCount(newnode->GetCount() + 1);//set count  
    int insertnode = ++size;
    while ((insertnode != 1) && (newnode->GetCount() > Heap[insertnode/2]->GetCount()))
    {//bubble up
        Heap[insertnode] = Heap[insertnode / 2];//drag down parent node
        insertnode /= 2;//move parent node
    }
    Heap[insertnode] = newnode;//newnode insert
    return true;//Insert Success
}

void LocationHeap::Print()
{
    //PRINT H
    ofstream flog;
    flog.open("log.txt", ios::app);//write file open
    for (int i = 1; i <= size; i++)
    {//Level order print
        flog << Heap[i]->GetCount() << "/" << Heap[i]->GetLoc() << endl;
        cout << Heap[i]->GetCount() << "/" << Heap[i]->GetLoc() << endl;
    }
}

int LocationHeap::Getsize()
{
    return size;//return size
}
