#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() : timeNeeded(-1), enterTime(-1)
{
}

int Student::getTimeNeeded()
{
  return timeNeeded;
}

int Student::getEnterTime()
{
  return enterTime;
}

void Student::setTimeNeeded(int timeNeeded)
{
  this->timeNeeded = timeNeeded;
}

void Student::setEnterTime(int enterTime)
{
  this->enterTime = enterTime;
}

void Student::modTimeNeeded(int amount)
{
  this->timeNeeded += amount;
}

void Student::printStudent()
{
  cout << "Student with enterTime: " << enterTime << endl;
  cout << "\ttimeNeeded: " << timeNeeded << endl;
}