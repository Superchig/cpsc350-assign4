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

  List<string> *strings = new DoublyLinkedList<string>();
  strings->insertFront("First to be inserted to front");
  strings->insertFront("Second to be inserted to front");
  strings->insertFront("Third to be inserted to front");

  cout << "The item at front: " << strings->getFront() << endl;

  strings->printList();

  delete strings;

  return 0;
}