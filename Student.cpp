#include "Student.h"

Student::Student() : timeNeeded(-1), enterTime(-1), exitTime(-1)
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

int Student::getExitTime()
{
  return exitTime;
}

void Student::setTimeNeeded(int timeNeeded)
{
  this->timeNeeded = timeNeeded;
}

void Student::setEnterTime(int enterTime)
{
  this->enterTime = enterTime;
}

void Student::setExitTime(int exitTime)
{
  this->exitTime = exitTime;
}

void Student::modTimeNeeded(int amount)
{
  this->timeNeeded += amount;
}