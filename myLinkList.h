#ifndef MYLINKLIST_H_INCLUDED
#define MYLINKLIST_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;
class LinkList;
struct INO
{
    string name;
    int id;
};

class LinkNode
{
    friend class LinkList;
private:
    LinkNode *next;
    INO val;
    LinkNode(INO x):val(x),next(NULL){};
};

class LinkList
{
public:
    LinkList();                 //构造函数
    ~LinkList();
    int Length();
    void myinsert(INO val ,int pos);
    void mydelete(INO val);
    void print();
    int myfind(INO val);        //查找结点位置
private:
    LinkNode *head;
    int length;

};
LinkList::LinkList()
{
    head=NULL;
    length=0;
}
LinkList::~LinkList()
{
    LinkNode *temp;
    for (int i=0;i<length;i++)
    {
        temp=head;
        head=head->next;
        delete temp;
    }

}
int LinkList::Length()
{
    return length;
}
void LinkList::myinsert(INO val,int pos)
{
    if(pos<0) throw "This position doesn't exist!";
    int index=1;
    LinkNode *temp=head;
    LinkNode  *node=new LinkNode(val);
    if(pos==0)
    {
        node->next=head;
        head=node;
        length++;
        return;
    }
    if(temp==NULL)
    {
        std::cout<<"insert failed!"<<std::endl;
        return;
    }
    while(temp!=NULL&&index<pos)
    {
        temp=temp->next;
        index++;
    }
    node->next=temp->next;
    temp->next=node;
    length++;

}



int LinkList::myfind(INO val)               //找到某元素的位置
{
    LinkNode *temp=head;
    int index=1;
    while(temp!=NULL)
    {
        if((temp->val.name==val.name)&&(temp->val.id==val.id))
            return index;

        temp=temp->next;
        index++;

    }
    return -1;
}

void LinkList::mydelete(INO val)
{
    int pos=myfind(val);
    if(pos==-1)
    {
        cout<<"Delete element failed!"<<endl;
        return;
    }
    if(pos==1)
    {
        head=head->next;
        length--;
        return ;
    }
    int index=2;
    LinkNode *temp=head;
    while(index<pos)
{
            temp=temp->next;
            index++;
}

    temp->next=temp->next->next;
    length--;




}

void LinkList::print()
{
    if(head==NULL)
    {
        cout<<"head is empty!"<<endl;
        return;
    }
    LinkNode *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val.name<<"\n"<<temp->val.id<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
#endif // MYLINKLIST_H_INCLUDED
