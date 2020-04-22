#include "DoublyLinkedList.h"

// List interface and list implementation can be in same file

template <class T>
class ListInterface {
public:
  virtual ~ListInterface<T>(){};

  virtual void insertFront(T data) = 0;
  virtual void insertBack(T data) = 0;
  virtual T removeFront() = 0;

  virtual T remove(T value) = 0;
  virtual T removeAtPos(unsigned int pos) = 0;

  virtual unsigned int getSize() = 0;
  virtual bool isEmpty() = 0;
  virtual void printList() = 0;

  virtual T getFront() = 0;
};

// List implementation
template <class T>
class MyList : public ListInterface<T> {
private:
  DoublyLinkedList<T> *items;
public:
  MyList();
  ~MyList();

  void insertFront(T data);
  void insertBack(T data);
  T removeFront();

  T remove(T value);
  T removeAtPos(unsigned int pos);

  unsigned int getSize();
  bool isEmpty();
  void printList();

  T getFront();
};

template <class T>
MyList<T>::MyList()
{
  items = new DoublyLinkedList<T>();
}

template <class T>
MyList<T>::~MyList()
{
  delete items;
}

template <class T>
void MyList<T>::insertFront(T data)
{
  items->insertFront(data);
}

template <class T>
void MyList<T>::insertBack(T data)
{
  items->insertBack(data);
}

template <class T>
T MyList<T>::removeFront()
{
  return items->removeFront();
}

template <class T>
T MyList<T>::remove(T value)
{
  return items->remove(value);
}

template <class T>
T MyList<T>::removeAtPos(unsigned int pos)
{
  return items->removeAtPos(pos);
}

template <class T>
unsigned int MyList<T>::getSize()
{
  return items->getSize();
}

template <class T>
bool MyList<T>::isEmpty()
{
  return items->isEmpty();
}

template <class T>
void MyList<T>::printList()
{
  items->printList();
}

template <class T>
T MyList<T>::getFront()
{
  return items->getFront();
}