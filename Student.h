// Header file for the Student class
class Student {
private:
  // The amount of time the student must spend at the window
  int timeNeeded;
  // The time (in ticks/minutes) the student entered the queue
  int enterTime;
public:
  // Default constructor
  Student();

  // Accessors
  int getTimeNeeded();
  int getEnterTime();

  // Modifiers
  void setTimeNeeded(int timeNeeded);
  void modTimeNeeded(int amount);
  void setEnterTime(int enterTime);

  // Print information about a student
  void printStudent();
};