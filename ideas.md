Read in all Students into a queue at start of program

- Have Student class
  - Contain time entered (tick at that time), time left
    - Can then calculate how long left waiting in the queue
  - Contain time taken up at window (windowTime)

- Have array/list of Window objects
  - Window contains a pointer to a Student
  - Will tick down student's windowTime every tick until hits 0, after which
    student is sent to addressedStudents list

At end of program, queue will be empty & no students will be in Windows
  - the addressedStudents list will have all students, can subtract time left
    minus time entered to find student's idle time
  - May not even need addressedStudents list, just list of student idle times
    that is added to when students enter a window

Will have to somehow keep track of window idle time
  - Keep windowIdleTimes list that holds the times that a window is idle
  - When adding/removing a student to a window, can calculate idle time and
    add that time to windowIdleTimes
  - Window object will have to keep track of when its last student left and
    compare that to current time (when it gets a new student) to see how long
    idle
  - Any Windows that were idle when the program ends (Windows that have
    lastStudentTime that is BEFORE the end of program time) will need to have
    their most recent idle times recorded

At end of program, analyze windowIdleTimes for stats results

At end of program, deallocate memory for all students from addressedStudents
list, as they will all be in there

Might want to use #ifndef guards to protect from including a file multiple
times

Can find median by inserting times into a median list as soon as they are able
to be calculated (& thus inserted into list)
- Inserted in a way that keeps them in order: starting from beginning, find
  first item that is greater than or equal to inserting item, insert item
  right before that one

A student who enters at minute 1 & needs 5 minutes should leave at minute 6,
it seems

If a window obtains a student at time 1, does that count as an idle time of 0?
