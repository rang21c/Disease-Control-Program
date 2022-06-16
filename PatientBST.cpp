#include "PatientBST.h"
#include <queue>
#include <stack>
#include <iostream>

PatientBST::PatientBST()
{
    Root = NULL;
}

PatientBST::~PatientBST()
{
    Root = NULL;
}

PatientBSTNode * PatientBST::GetRoot()
{
    return Root;//return root
}

bool PatientBST::Insert(PatientNode * node)
{
    //QPOP
    PatientBSTNode* newnode = new PatientBSTNode;
    newnode->SetName(node->GetName());//set name
    if (node->GetTemp() >= 37.5 && node->GetCough() == 'Y')
        newnode->SetDisease('+');//set positive 
    else
        newnode->SetDisease('-');//set negative
    PatientBSTNode* cur = Root, * p = 0;
    while (cur)
    {
        p = cur;//p is parentnode
        if (strcmp(newnode->GetName(), cur->GetName()) < 0)
            cur = cur->GetLeft();//move leftnode
        else if (strcmp(newnode->GetName(), cur->GetName()) > 0)
            cur = cur->GetRight();//move rightnode
    }
    if (Root)
    {//Tree is not blank
        if (strcmp(newnode->GetName(), p->GetName()) < 0)
            p->SetLeft(newnode);//set leftnode
        else
            p->SetRight(newnode);//set rightnode
    }
    else//No root in tree
        Root = newnode;//set rootnode
    return 1;//insert sucess
}

bool PatientBST::Search(char * name)
{//Level order
    //SEARCH
    PatientBSTNode* cur = this->GetRoot();
    queue<PatientBSTNode*> q;
    while (cur)
    {//Level order search
        if (strcmp(cur->GetName(), name) == 0)
        {//search success
            ofstream flog;
            flog.open("log.txt", ios::app);//file open
            flog << "========== " << "SEARCH" << " ==========" << endl;
            flog << name << "/" << cur->GetDisease() << endl;
            flog << "============================" << endl << endl;
            cout << "========== " << "SEARCH" << " ==========" << endl;
            cout << name << "/" << cur->GetDisease() << endl;
            cout << "============================" << endl << endl;
            flog.close();
            return true;//return search success
        }
        if (cur->GetLeft())
            q.push(cur->GetLeft());//insert queue
        if (cur->GetRight())
            q.push(cur->GetRight());//insert queue
        if (q.empty())//queue is empty
            break;
        cur = q.front();
        q.pop();
    }
    return false;//search fail
}

bool PatientBST::Delete(char * name)
{
    //BPOP
    PatientBSTNode* cur = this->GetRoot(), *pp = this->GetRoot();
    PatientBSTNode* deletenode = NULL;
    while (cur)
    {//search deletenode
        if (strcmp(name, cur->GetName()) < 0)
        {
            pp = cur;
            cur = cur->GetLeft();//move leftchild
        }
        else if (strcmp(name, cur->GetName()) > 0)
        {
            pp = cur;
            cur = cur->GetRight();//move rightchild
        }
        else
        {//find name
            deletenode = cur;//set deletenode
            break;//break roop
        }
    }
    if (deletenode == NULL)//NO EXIST "name"
        return false;//Delete Fail
    if (!cur->GetLeft() && !cur->GetRight())
    {//Leaf node delete
        if (strcmp(deletenode->GetName(), pp->GetName()) < 0)//deletenode is leftchild
            pp->SetLeft(NULL);
        else if (strcmp(deletenode->GetName(), pp->GetName()) > 0)//deletenode is rightchild
            pp->SetRight(NULL);
        else
            this->Root = NULL;//set root
        delete deletenode;
        return true;//Delete Complete
    }
    else if (cur->GetLeft() && !cur->GetRight())
    {//deletenode have Only LeftChild
        if (strcmp(deletenode->GetName(), pp->GetName()) < 0)//deletenode is leftchild
            pp->SetLeft(deletenode->GetLeft());
        else if (strcmp(deletenode->GetName(), pp->GetName()) > 0)//deletenode is rightchild
            pp->SetRight(deletenode->GetLeft());
        else
            this->Root = deletenode->GetLeft();//set root
        delete deletenode;
        return true;//Delete Complete
    }
    else if (!cur->GetLeft() && cur->GetRight())
    {//deletenode have Only RightChild
        if (strcmp(deletenode->GetName(), pp->GetName()) < 0)//deletenode is leftchild
            pp->SetLeft(deletenode->GetRight());
        else if (strcmp(deletenode->GetName(), pp->GetName()) > 0)//deletenode is rightchild
            pp->SetRight(deletenode->GetRight());
        else
            this->Root = deletenode->GetRight();//set root
        delete deletenode;
        return true;//Delete Complete
    }
    else if(cur->GetLeft() && cur->GetRight())
    {//deletenode have all children
        pp = deletenode;
        cur = deletenode->GetLeft();
        PatientBSTNode* cur_child = deletenode->GetLeft()->GetRight();
        while (cur_child)
        {//roof when cur is leaf node
            pp = cur;
            cur = cur_child;
            cur_child = cur_child->GetRight();
        }
        deletenode->SetName(cur->GetName());
        deletenode->SetDisease(cur->GetDisease());
        if (pp == deletenode)
            pp->SetLeft(cur->GetLeft());
        else
            pp->SetRight(cur->GetLeft());
        delete cur;
        return true;//Delete Complete
    }
}

void PatientBST::Print_PRE(PatientBSTNode * node)
{
    //PRINT B PRE
    stack<PatientBSTNode*> s;
    ofstream flog;
    flog.open("log.txt", ios::app);//write file open
    s.push(node);//insert root node
    while (!s.empty())
    {
        node = s.top();//get top node
        s.pop();//pop top node
        //node visit
        flog << node->GetName() << "/" << node->GetDisease() << endl;
        cout << node->GetName() << "/" << node->GetDisease() << endl;
        if (node->GetRight())
            s.push(node->GetRight());//insert rightchild
        if (node->GetLeft())
            s.push(node->GetLeft());//insert leftchild
    }
    flog.close();
}

void PatientBST::Print_IN(PatientBSTNode * node)
{
    //PRINT B IN
    stack<PatientBSTNode*> s;
    ofstream flog;
    flog.open("log.txt", ios::app);
    while (1)
    {
        while (node)
        {//push left child
            s.push(node);
            node = node->GetLeft();
        }
        if (s.empty())//stack is empty
            break;
        node = s.top();//set (top->cur)
        s.pop();//pop top node
        //visit node
        flog << node->GetName() << "/" << node->GetDisease() << endl;
        cout << node->GetName() << "/" << node->GetDisease() << endl;
        node = node->GetRight();//move right child
    }
    flog.close();
}

void PatientBST::Print_POST(PatientBSTNode * node)
{
    //PRINT B POST
    POST_ORDER(node);//PatientBST postorder start
}

void PatientBST::Print_LEVEL()
{
    //PRINT B LEVEL
    PatientBSTNode* cur = this->GetRoot();
    queue<PatientBSTNode*> q;
    ofstream flog;
    flog.open("log.txt", ios::app);//open write file
    while (cur)
    {
        //visit curnode
        flog << cur->GetName() << "/" << cur->GetDisease() << endl;
        cout << cur->GetName() << "/" << cur->GetDisease() << endl;
        if (cur->GetLeft())
            q.push(cur->GetLeft());//push leftchild
        if (cur->GetRight())
            q.push(cur->GetRight());//push rightchild
        if (q.empty())//queue is empty
            break;
        cur = q.front();//set cur node
        q.pop();//pop queue front
    }
    flog.close();
}

void PatientBST::POST_ORDER(PatientBSTNode* node)
{
    if (node)
    {
        ofstream flog;
        flog.open("log.txt", ios::app);
        POST_ORDER(node->GetLeft());//recursive visit leftchild
        POST_ORDER(node->GetRight());//recursive visit rightchild
        //visit node
        flog << node->GetName() << "/" << node->GetDisease() << endl;
        cout << node->GetName() << "/" << node->GetDisease() << endl;
        flog.close();
    }
}