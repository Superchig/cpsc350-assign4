#include "GenQueue.h"
#include "Student.h"
#include <fstream>
#include <iostream>

using namespace std;

// Read students in from an input file
GenQueue<Student*> *readStudents(string fileName)
{
  ifstream inputFile{fileName};

  if (!inputFile.is_open()) {
    return nullptr;
  }

  // FIXME: Move this segment into the main method, where the number of windows
  // can be more readily accessed?
  // Read the first number in as number of windows
  int numWindows = 0;
  inputFile >> numWindows;

  GenQueue<Student*> *students = new GenQueue<Student*>();
  while (true) {
    // The time at which these students are entering the line
    int tickTime = 0;
    // The number of students who are entering the line at this time
    int enteringStudents = 0;

    // The time will always precede the number of entering students, so they can
    // be read in order
    inputFile >> tickTime;
    if (inputFile.eof()) {
      // The file has ended, so stop reading in Students
      break;
    }
    inputFile >> enteringStudents;

    // Read in the times for the entering students
    for (int i = 0; i < enteringStudents; ++i) {
      int timeNeeded;
      inputFile >> timeNeeded;

      Student *enteringStudent = new Student();
      enteringStudent->setTimeNeeded(timeNeeded);
      enteringStudent->setEnterTime(tickTime);

      students->insert(enteringStudent);
    }
  }

  inputFile.close();

  return students;
}

int main(int argc, char **argv)
{
  if (argc != 2) {
    cout << "Error: This program takes only 1 argument." << endl;
    return 1;
  }

  string fileName = argv[1];
  GenQueue<Student*> *students = readStudents(fileName);

  cout << students->getSize() << endl;

  // Deallocate memory for individual students and then for queue
  while (!students->isEmpty()) {
    delete students->remove();
  }
  delete students;

  return 0;
}