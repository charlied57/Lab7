//////////////////////////////////////////////////////////////////////////////
// Timer.h  UNIX SYSTEM VERSION
// =======
// High Resolution Timer.
// This timer is able to measure the elapsed time with 1 micro-second accuracy
// in both Windows, Linux and Unix system 
//
//  AUTHOR: Song Ho Ahn (song.ahn@gmail.com)
// CREATED: 2003-01-13
// UPDATED: 2006-01-13
//
// Copyright (c) 2003 Song Ho Ahn
//////////////////////////////////////////////////////////////////////////////
// MODIFIED: by tom bailey  1000  19 nov 2012
// change of method names
// change to bool for running flag
// change timeInSeconds from data member to local variable
//
// MODIFIED: by tom bailey   1500  28 feb 2013
// separate the Windows and Unix versions
//////////////////////////////////////////////////////////////////////////////

#ifndef TIMER_H_DEF
#define TIMER_H_DEF

#include <sys/time.h>
//#include "unixTimer.cpp"


class Timer
{
public:
    Timer();                                    // default constructor
    ~Timer();                                   // default destructor

    void   start();                             // start the timer
    void   stop();                              // stop the timer
    double operator()();                        // get elapsed time in seconds

private:
    bool   running;                             // running flag
    double startTimeInSec;                      // start time for current interval
    double elapsedTimeInSec;                    // sum of all intervals on this Timer

};

#endif // TIMER_H_DEF