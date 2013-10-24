/**
 *stopwatch.cpp
 *Author: jordan goss
 *last updated: 2/22/2013
 *
 *Stopwatch can be used as a timer to test
 *the run times of fuctions and/or programs
 */
#include <assert.h>
#include <iostream>
#include "stopwatch.hpp"

 
 //if using windows, we need to define our own
 //gettimeofday function
 //seems messy, but at least its portable
#if defined(_WIN32) || defined(WIN32)
int gettimeofday(struct timeval *tv/*in*/, struct timezone *tz/*in*/)
{
  FILETIME ft; //windows uses this to hold time
  __int64 tmpres = 0;
  TIME_ZONE_INFORMATION tz_winapi;
  int rez=0;

  //clear memory
   ZeroMemory(&ft,sizeof(ft));
   ZeroMemory(&tz_winapi,sizeof(tz_winapi));

    GetSystemTimeAsFileTime(&ft);

    tmpres = ft.dwHighDateTime;
    tmpres <<= 32;
    tmpres |= ft.dwLowDateTime;

    /*converting file time to unix epoch*/
    tmpres /= 10;  /*convert into microseconds*/
    tmpres -= DELTA_EPOCH_IN_MICROSECS; 
    tv->tv_sec = (__int32)(tmpres*0.000001);
    tv->tv_usec =(tmpres%1000000);


    //_tzset(),don't work properly, so we use GetTimeZoneInformation
    rez=GetTimeZoneInformation(&tz_winapi);
    tz->tz_dsttime=(rez==2)?true:false;
    tz->tz_minuteswest = tz_winapi.Bias + ((rez==2)?tz_winapi.DaylightBias:0);

  return 0;
}
#endif
Stopwatch::Stopwatch(){
    //initialize times to zero;
    this->_begin.tv_sec = this->_end.tv_usec = 0;
    this->_begin.tv_sec = this->_end.tv_usec = 0;
    this->_elapsed.tv_sec = this->_elapsed.tv_usec = 0;
}

Stopwatch::~Stopwatch(){}

//just get current time
void Stopwatch::start(){gettimeofday(&_begin, NULL);}

int Stopwatch::stop(){
    gettimeofday(&_end, NULL); //get current time
    this->diff(); //update elapsed time
    
    //return in microseconds
    return  MICRO_IN_SEC* _elapsed.tv_sec+ _elapsed.tv_usec;
}
void Stopwatch::diff(){
    //get diffence between begin and end time
    this->_elapsed.tv_sec = this->_end.tv_sec - this->_begin.tv_sec;
    this->_elapsed.tv_usec = this->_end.tv_usec - this->_begin.tv_usec;
}
int Stopwatch::time(){
    //return time in microseconds
    return MICRO_IN_SEC  *_elapsed.tv_sec+
                           _elapsed.tv_usec;
}
double Stopwatch::to_seconds(){
    //conver to seconds
    return _elapsed.tv_sec + ((double) _elapsed.tv_usec / MICRO_IN_SEC);
}
double Stopwatch::to_milliseconds(){
    //convert to milliseconds
    return (MILL_IN_SEC *_elapsed.tv_sec) + 
                ((double) _elapsed.tv_usec / MICRO_IN_MILL );
}
void Stopwatch::reset(){
    //reset times to 0
    this->_begin.tv_sec = this->_end.tv_usec = 0;
    this->_begin.tv_sec = this->_end.tv_usec = 0;
    this->_elapsed.tv_sec = this->_elapsed.tv_usec = 0;
}
