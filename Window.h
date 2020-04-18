#include "Student.h"

// Represents a window at the registrar's office
class Window {
private:
  Student *student;

  // Time when the most recent student left this window
  int lastStudentTime;

public:
  Window();

  int getLastStudentTime();
  void setLastStudentTime(int time);
  Student *getStudent();
  void setStudent(Student *student);

  // Returns whether or not the window currently has a student
  bool hasStudent();
  int calcIdleTime(int currTime);
};