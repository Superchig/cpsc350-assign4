#include "GenQueue.h"
#include "Window.h"
#include <fstream>
#include <iostream>

// Use macros to output debug info
#ifdef DEBUG
#define debdo(X) X
#define deblog(X) cout << X << endl
#else
#define debdo(X)
#define deblog(X)
#endif

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

      debdo(enteringStudent->printStudent());
    }
  }

  inputFile.close();

  return students;
}

// Return whether or not an array of windows has one that is empty (has no
// student)
bool hasEmptyWindow(Window *windows, int size)
{
  for (int i = 0; i < size; ++i) {
    if (!windows[i].hasStudent()) {
      return true;
    }
  }

  return false;
}

// Return a pointer to an empty window if there is one or nullptr if there is
// not one
Window *getEmptyWindow(Window *windows, int size)
{
  for (int i = 0; i < size; ++i) {
    if (!windows[i].hasStudent()) {
      return &windows[i];
    }
  }

  return nullptr;
}

// Returns true if all windows are empty, false if at least one is empty
bool allWindowsEmpty(Window *windows, int size)
{
  for (int i = 0; i < size; ++i) {
    if (windows[i].hasStudent()) {
      return false;
    }
  }

  return true;
}

// Returns the mean of an array of ints
double getMean(int *items, int size)
{
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += items[i];
  }
  return sum / size;
}

void printInts(int *items, int size)
{
  for (int i = 0; i < size; ++i) {
    cout << items[i] << endl;
  }
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
  DoublyLinkedList<int> studentIdleTimes;
  while (true) {
    deblog("currTime: " << currTime);

    // Update the ticking times for the windows and the students
    for (int i = 0; i < numWindows; ++i) {
      Window &win = windows[i];
      if (!win.hasStudent()) {
        win.modIdleTime(1);
        continue;
      }

      // Update the time for the student
      Student *student = win.getStudent();
      student->modTimeNeeded(-1);

      // If the student has spent their necessary amount of time at the window,
      // remove them from the window
      if (student->getTimeNeeded() <= 0) {
        win.setStudent(nullptr);
        win.setLastStudentTime(currTime);

        // We will no longer use the student's info, so deallocate them
        delete student;
      }
    }

    // Move students who have entered the line into an available window,
    // provided that a window is available
    while (!students->isEmpty() &&
           students->peek()->getEnterTime() <= currTime &&
           hasEmptyWindow(windows, numWindows)) {
      Student *currStudent = students->remove();
      Window *currWindow = getEmptyWindow(windows, numWindows);

      // Add the student to the window
      currWindow->setStudent(currStudent);

      // Calculate and record student's idle time
      int studentIdleTime = currTime - currStudent->getEnterTime();
      studentIdleTimes.insertBack(studentIdleTime);
    }

    // Update the time by a tick
    ++currTime;

    // Break if the simulation goes on too long
    // if (currTime > 100) {
    //   break;
    // }

    if (allWindowsEmpty(windows, numWindows) && students->isEmpty()) {
      break;
    }
  }

  // Copy student idle times into an array to use for calculations
  int numStudents = studentIdleTimes.getSize();
  int studentTimesArray[numStudents];
  ListNode<int> *currTimeNode = studentIdleTimes.getFrontNode();
  for (int i = 0; i < numStudents; ++i) {
    studentTimesArray[i] = currTimeNode->data;
    currTimeNode = currTimeNode->next;
  }

  // Copy window idle times into an array to use for calculations
  int windowTimesArray[numWindows];
  for (int i = 0; i < numWindows; ++i) {
    windowTimesArray[i] = windows[i].getIdleTime();
  }

  deblog("Student idle times: ");
  debdo(studentIdleTimes.printList());
  cout << "Average student idle time: " << endl;
  cout << getMean(studentTimesArray, studentIdleTimes.getSize()) << endl;

  deblog("Window idle times: ");
  debdo(printInts(windowTimesArray, numWindows));
  cout << "Average window idle time: " << endl;
  cout << getMean(windowTimesArray, numWindows) << endl;

  // Deallocate memory for individual students and then for queue
  while (!students->isEmpty()) {
    delete students->remove();
  }
  delete students;

  return 0;
}