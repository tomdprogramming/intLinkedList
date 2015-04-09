#include "intLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

intLinkedList::intLinkedList()
{
    this->Head = NULL;
    this->Current = NULL;
}

intLinkedList::~intLinkedList()
{
    free(this->Head);
}

void intLinkedList::AddNode(int NewData)
{
    if(this->Head == NULL) //list is empty
    {
        Node* NewNode = (Node*)malloc(sizeof(Node));
        this->Head = NewNode;
        NewNode->SetData(NewData);
        NewNode->SetNext(NULL);
    }
    else
    {
        Node* NewNode = (Node*)malloc(sizeof(Node));
        NewNode->SetData(NewData);
        NewNode->SetNext(NULL);
        this->Current = this->Head;
        while(Current->GetNext()!=NULL)
        {
            Current = Current->GetNext();
        }
        Current->SetNext(NewNode);
    }
}

void intLinkedList::PrintList(void)
{
    printf("\n");
    this->Current = this->Head;
    while(Current != NULL)
    {
        printf("%d\n",Current->GetData());
        this->Current = this->Current->GetNext();
    }
}
