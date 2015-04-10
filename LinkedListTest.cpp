#include "intLinkedList.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    intLinkedList MyFirstList;
    
    MyFirstList.AddToTail(1);
    MyFirstList.AddToTail(3);
    MyFirstList.AddToTail(5);
    MyFirstList.AddToTail(7);
    MyFirstList.AddToTail(12345);
    MyFirstList.AddToTail(78);
    MyFirstList.AddToTail(2);
    
    MyFirstList.PrintList();
    
    MyFirstList.RemoveHead();
    
    MyFirstList.PrintList();

    MyFirstList.RemoveHead();
    
    MyFirstList.PrintList();
    
    MyFirstList.RemoveTail();
    
    MyFirstList.PrintList();
    
    MyFirstList.RemoveTail();
    
    MyFirstList.PrintList();
    
    return 0;
    
}
