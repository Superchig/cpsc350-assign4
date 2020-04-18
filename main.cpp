#include "GenQueue.h"
#include "Window.h"
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

  // This variable isn't used in this function. It simply reads in the first line
  // so that future lines can be read in.
  int numWindowsUnused = 0;
  inputFile >> numWindowsUnused;

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

  // Read in the number of windows and create the Window array
  int numWindows;
  ifstream inputFile{fileName};
  inputFile >> numWindows;
  inputFile.close();
  Window windows[numWindows]; // Number of windows doesn't change, can use array

  // Read in the students and their corresponding info in from the file
  GenQueue<Student*> *students = readStudents(fileName);

  // Deallocate memory for individual students and then for queue
  while (!students->isEmpty()) {
    delete students->remove();
  }
  delete students;

  return 0;
}