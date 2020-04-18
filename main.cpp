#include "GenQueue.h"
#include "Window.h"
#include <fstream>
#include <iostream>

using namespace std;

// Read students in from an input file
GenQueue<Student *> *readStudents(string fileName)
{
  ifstream inputFile{fileName};

  if (!inputFile.is_open()) {
    return nullptr;
  }

  // This variable isn't used in this function. It simply reads in the first
  // line so that future lines can be read in.
  int numWindowsUnused = 0;
  inputFile >> numWindowsUnused;

  GenQueue<Student *> *students = new GenQueue<Student *>();
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

bool hasEmptyWindow(Window *windows, int size)
{
  for (int i = 0; i < size; ++i) {
    if (!windows[i].hasStudent()) {
      return true;
    }
  }

  return false;
}

Window *getEmptyWindow(Window *windows, int size)
{
  for (int i = 0; i < size; ++i) {
    if (!windows[i].hasStudent()) {
      return &windows[i];
    }
  }

  return nullptr;
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

  // Create array of windows, number of windows does not change
  Window windows[numWindows];

  // Read in the students and their corresponding info in from the file
  GenQueue<Student *> *students = readStudents(fileName);

  // Main simulation loop
  int currTime = 1;
  while (true) {
    cout << "currTime: " << currTime << endl;

    // Provided that there is a window available, move students who have entered
    // the line into an available window
    while (!students->isEmpty() &&
           students->peek()->getEnterTime() <= currTime &&
           hasEmptyWindow(windows, numWindows)) {
      Student *currStudent = students->remove();
      // cout << "Adding student with enter time: " <<
      // currStudent->getEnterTime() << endl;

      Window *currWindow = getEmptyWindow(windows, numWindows);
      // cout << "currWindow->getLastStudentTime(): "
      //      << currWindow->getLastStudentTime() << endl;

      currWindow->setStudent(currStudent);
    }

    // Update the ticking times for the windows and the students
    for (int i = 0; i < numWindows; ++i) {
      Window &win = windows[i];
      if (!win.hasStudent()) {
        continue;
      }

      Student *student = win.getStudent();
      if (student->getTimeNeeded() > 0) {
        // Update the time for the student
        student->modTimeNeeded(-1);
      }
      else {
        // The student has spent their necessary amount of time at the window,
        // so remove them from the window
        win.setStudent(nullptr);
        // FIXME: Possibly calculate and add student's idle time to list

        // We will no longer use the student's info, so deallocate them
        delete student;
      }
    }

    // Update the time by a tick
    ++currTime;

    // Break if the simulation goes on too long
    // TODO: Remove when rest of simulation implementation is finished
    if (currTime > 20) {
      break;
    }
  }

  // TODO: Deallocate memory for students still in windows?
  // There is currently a memory leak that probably stems from that

  // Deallocate memory for individual students and then for queue
  while (!students->isEmpty()) {
    delete students->remove();
  }
  delete students;

  return 0;
}