// List interface -- has pure virtual functions

template <class T>
class List {
public:
  virtual ~List<T>() {};

  virtual void insertFront(T data) = 0;
  virtual void insertBack(T data) = 0;
  virtual T removeFront() = 0;
  // Will return value or position of node depending on implementation.
  virtual int search(T val) = 0;
  virtual T remove(T value) = 0;
  virtual T removeAtPos(unsigned int pos) = 0;

  virtual unsigned int getSize() = 0;
  virtual bool isEmpty() = 0;
  virtual void printList() = 0;
};