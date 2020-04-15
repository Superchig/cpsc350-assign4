#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char **argv)
{
  DoublyLinkedList<int> list;
  list.insertFront(7);
  list.insertFront(5);
  list.insertFront(3);

  list.printList();

  return 0;
}