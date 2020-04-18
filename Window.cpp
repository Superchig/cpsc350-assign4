#include "Window.h"

Window::Window() : student(nullptr), whenLastStudentLeft(-1)
{
}

bool Window::hasStudent()
{
  // If student is null, then there is no student currently assigned to the
  // window
  return student == nullptr;
}

int Window::getWhenLastStudentLeft()
{
  return whenLastStudentLeft;
}

void Window::setWhenLastStudentLeft(int time)
{
  whenLastStudentLeft = time;
}

Student *Window::getStudent()
{
  return student;
}

void Window::setStudent(Student *student)
{
  this->student = student;
}