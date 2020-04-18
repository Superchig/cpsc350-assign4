#include "Student.h"

// Represents a window at the registrar's office
class Window {
private:
  Student *student;

  // Time when the most recent student left this window
  int whenLastStudentLeft;

public:
  Window();

  int getWhenLastStudentLeft();
  void setWhenLastStudentLeft(int time);
  Student *getStudent();
  void setStudent(Student *student);

  // Returns whether or not the window currently has a student
  bool hasStudent();
  int calcIdleTime(int currTime);
};