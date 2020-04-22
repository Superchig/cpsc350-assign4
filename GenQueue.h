#include "List.h"

template <class T>
class GenQueue {
private:
  MyList<T> *items;

public:
  // Default constructor
  GenQueue<T>();
  // Destructor
  ~GenQueue<T>();

  // Inserts item at rear (tail) of the queue
  void insert(T item);
  // Removes item at front (head) of the queue
  T remove();

  // Show the position at the front of the queue without removing it
  T peek();
  bool isEmpty();
  int getSize();
};

template <class T>
GenQueue<T>::GenQueue()
{
  items = new MyList<T>();
}

template <class T>
GenQueue<T>::~GenQueue()
{
  delete items;
}

template <class T>
T GenQueue<T>::remove()
{
  return items->removeFront();
}

template <class T>
void GenQueue<T>::insert(T item)
{
  items->insertBack(item);
}

template <class T>
bool GenQueue<T>::isEmpty()
{
  return items->isEmpty();
}

template <class T>
T GenQueue<T>::peek()
{
  return items->getFront();
}

template <class T>
int GenQueue<T>::getSize()
{
  return items->getSize();
}