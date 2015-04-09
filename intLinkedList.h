#ifndef INTLINKEDLIST_H
#define INTLINKEDLIST_H
class Node
{
    private:
        int Data;
        Node* Next;
            
    public:
    
    int  GetData(void){return this->Data;}
    void SetData(int x){this->Data = x;}
            
    Node* GetNext(void){return this->Next;}
    void  SetNext(Node* New){this->Next = New;}
};

class intLinkedList
{
    private:
        Node* Head;
        Node* Current;
    
    public:
    intLinkedList();
    ~intLinkedList();
    
    Node* GetHead(void){return this->Head;}
    void SetHead(Node* New){this->Head = New;}
    
    Node* GetCurrent(void){return this->Current;}
    void SetCurrent(Node* New){this->Current = New;}
    
    void AddNode(int Data);
    
    void PrintList(void);
};

#endif
