#include <iostream>
#include "GenQueue.h"

using namespace std;

int main(int argc, char **argv)
{
  GenQueue<int> q;
  q.insert(3);
  q.insert(2);
  q.insert(1);

  while (!q.isEmpty()) {
    cout << q.remove() << endl;
  }

  return 0;
}