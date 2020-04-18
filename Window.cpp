#include "Window.h"

Window::Window() : student(nullptr), lastStudentTime(-1)
{
}

bool Window::hasStudent()
{
  // If student is null, then there is no student currently assigned to the
  // window
  return student != nullptr;
}

int Window::calcIdleTime(int currTime)
{
  return lastStudentTime - currTime;
}

int Window::getLastStudentTime()
{
  return lastStudentTime;
}

void Window::setLastStudentTime(int time)
{
  lastStudentTime = time;
}

Student *Window::getStudent()
{
  return student;
}

void Window::setStudent(Student *student)
{
  this->student = student;
}