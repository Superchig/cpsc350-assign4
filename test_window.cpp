#include "Window.h"
#include <iostream>

using namespace std;

int main(int arc, char **argv)
{
  Student st;
  Window win1;
  Window win2;

  win1.setStudent(&st);
  cout << "win1's student's enter time: " << win1.getStudent()->getEnterTime() << endl;
  cout << "win1.hasStudent(): " << win1.hasStudent() << endl;
  cout << "win2.hasStudent(): " << win2.hasStudent() << endl;

  return 0;
}