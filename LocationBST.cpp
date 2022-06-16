#include "LocationBST.h"
#include "Manager.h"
#include <queue>
#include <stack>

LocationBST::LocationBST()
{
    Root = NULL;
}

LocationBST::~LocationBST()
{
    Root = NULL;
}

LocationNode * LocationBST::GetRoot()
{
    return Root;
}

void LocationBST::Insert_Location(LocationNode * node)
{
    PatientBST* newbst = new PatientBST;
    node->SetPatientBST(newbst);//make patient bst
    LocationNode* cur = Root, * p = 0;
    while (cur)
    {//search node
        p = cur;
        if (strcmp(node->GetLoc(), cur->GetLoc()) < 0)
            cur = cur->GetLeft();
        else if (strcmp(node->GetLoc(), cur->GetLoc()) > 0)
            cur = cur->GetRight();
    }
    if (Root)
    {//insert location if root o
        if (strcmp(node->GetLoc(), p->GetLoc()) < 0)
            p->SetLeft(node);
        else
            p->SetRight(node);
    }
    else//insert location if root x
        Root = node;
    //Build once in Constructor
}

bool LocationBST::Insert_Patient(PatientNode * node)
{
    //QPOP
    LocationNode* cur = this->GetRoot();
    queue<LocationNode*> q;
    while (cur)
    {//Level order search
        if (strcmp(cur->GetLoc(), node->GetLoc()) == 0)
            break;//search sucess
        if (cur->GetLeft())
            q.push(cur->GetLeft());//insert queue
        if (cur->GetRight())
            q.push(cur->GetRight());//insert queue
        if (q.empty())
            break;
        cur = q.front();//set (front->cur)
        q.pop();
    }
    cur->GetBST()->Insert(node);//insert fuction call
    return 1;
}

bool LocationBST::Search(char * name)
{
    //SEARCH
    LocationNode* cur = this->GetRoot();
    queue<LocationNode*> q;
    while (cur)
    {//Level order search
        if (cur->GetBST()->Search(name) == true)
        {
            return true;//search success
        }
        if (cur->GetLeft())
            q.push(cur->GetLeft());//insert queue
        if (cur->GetRight())
            q.push(cur->GetRight());//insert queue
        if (q.empty())//queue is empty
            break;
        cur = q.front();//set (front->cur)
        q.pop();
    }
    return false;//search fail
}

char * LocationBST::Delete(char * name)
{
    //BPOP
    LocationNode* cur = this->GetRoot();
    queue<LocationNode*> q;
    while (cur)
    {//Level order search 
        if (cur->GetBST()->Delete(name))
        {
            return cur->GetLoc();//return location name
        }
        if (cur->GetLeft())
            q.push(cur->GetLeft());//push leftchild
        if (cur->GetRight())
            q.push(cur->GetRight());//push rightchild
        if (q.empty())//queue is empty
            break;
        cur = q.front();//set cur node
        q.pop();//pop queue front
    }
    return NULL;//Delete fail
}

void LocationBST::Print_PRE()
{
    //PRINT B PRE
    LocationNode* cur = this->GetRoot();
    stack<LocationNode*> s;
    s.push(cur);//insert root node
    while (!s.empty())
    {
        cur = s.top();//get top node
        s.pop();//pop top node
        if(cur->GetBST()->GetRoot())
            cur->GetBST()->Print_PRE(cur->GetBST()->GetRoot());//cur node visit
        if (cur->GetRight())
            s.push(cur->GetRight());//insert rightchild
        if (cur->GetLeft())
            s.push(cur->GetLeft());//insert leftchild
    }
}

void LocationBST::Print_IN()
{
    //PRINT B IN
    LocationNode* cur = this->GetRoot();
    stack<LocationNode*> s;
    while (1)
    {
        while (cur)
        {//push left child
            s.push(cur);
            cur = cur->GetLeft();
        }
        if (s.empty())//stack is empty
            break;
        cur = s.top();//set (top->cur)
        s.pop();//pop top node
        cur->GetBST()->Print_IN(cur->GetBST()->GetRoot());//visit cur node
        cur = cur->GetRight();//move right child
    }
}

void LocationBST::Print_POST()
{
    //PRINT B POST
    LocationNode* cur = this->GetRoot();
    POST_ORDER(cur);//start root node
}

void LocationBST::Print_LEVEL()
{
    //PRINT B LEVEL
    LocationNode* cur = this->GetRoot();
    queue<LocationNode*> q;
    while (cur)
    {
        cur->GetBST()->Print_LEVEL();//visit cur node
        if (cur->GetLeft())
            q.push(cur->GetLeft());//push leftchild
        if (cur->GetRight())
            q.push(cur->GetRight());//push rightchild
        if (q.empty())//queue is empty
            break;
        cur = q.front();//set cur node
        q.pop();//pop front
    }
}

void LocationBST::POST_ORDER(LocationNode* cur)
{
    if (cur)
    {
        POST_ORDER(cur->GetLeft());//recursive visit leftchild
        POST_ORDER(cur->GetRight());//recursive visit rightchild
        cur->GetBST()->Print_POST(cur->GetBST()->GetRoot());//visit cur node
    }
}