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
        Node* TempPntr = this->Head;
        while(TempPntr->GetNext()!=NULL)
        {
            TempPntr = TempPntr->GetNext();
        }
        TempPntr->SetNext(NewNode);
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
    Node* NewTail;
    Node* PrevTail = this->Head;
    
    while(PrevTail->GetNext()!=NULL)
    {
        NewTail = PrevTail;
        PrevTail = PrevTail->GetNext();
    }//at the end of this while loop, PrevTail should be pointed to the last item, and NewTail should be pointed to the penultimate item
    free(PrevTail); //free the last item
    NewTail->SetNext(NULL); //the formerly penultimate item is now the last item, so it has it's 'Next' member set to NULL
}

void intLinkedList::PrintList(void)
{
    printf("\n");
    Node* TempPntr = this->Head;
    while(TempPntr != NULL)
    {
        printf("%d\n",TempPntr->GetData());
        TempPntr = TempPntr->GetNext();
    }
}
