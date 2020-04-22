#include "Student.h"

// Represents a window at the registrar's office
class Window {
private:
  Student *student;

  // Time when the most recent student left this window
  int lastStudentTime;
  int idleTime;

public:
  Window();

  int getLastStudentTime();
  void setLastStudentTime(int time);
  Student *getStudent();
  void setStudent(Student *student);
  int getIdleTime();
  void modIdleTime(int modAmount);

  // Returns whether or not the window currently has a student
  bool hasStudent();
};