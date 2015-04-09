#include "intLinkedList.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    intLinkedList MyFirstList;
    
    MyFirstList.AddNode(1);
    MyFirstList.AddNode(3);
    MyFirstList.AddNode(5);
    
    MyFirstList.PrintList();
    
    return 0;
    
}
