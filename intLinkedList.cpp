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
    if(this->Head != NULL) //list has at least one item
    {
        this->Current = this->Head;//set Current pointer to the head of the list
        while(this->Current!=NULL)//step through each item, pointing the head to the next item, and freeing the current item
        {
            this->Head = Current->GetNext();
            free(Current);
            this->Current = this->Head;
        }
        //at this point, both Head and Current should both be NULL
    }
}

void intLinkedList::AddToTail(int NewData)
{
    if(this->Head == NULL) //list is empty
    {
        Node* NewNode = (Node*)malloc(sizeof(Node));
        this->Head = NewNode;
        NewNode->SetData(NewData);
        NewNode->SetNext(NULL);
    }
    else //list has at least one item
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

void intLinkedList::RemoveHead(void)
{
    Node* TempHead = this->Head;
    Head = Head->GetNext();
    free(TempHead);
}

void intLinkedList::RemoveTail(void)
{
    Node* Previous;
    this->Current = this->Head;
    
    while(this->Current->GetNext()!=NULL)
    {
        Previous = this->Current;
        this->Current = this->Current->GetNext();
    }//at the end of this while loop, Current should be pointed to the last item, and previous should be pointed to the penultimate item
    free(this->Current); //free the last item
    Previous->SetNext(NULL); //the formerly penultimate item is now the last item, so it has it's 'Next' member set to NULL
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
