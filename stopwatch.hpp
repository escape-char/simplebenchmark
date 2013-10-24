/**
 * stopwatch.hpp
 * Author: jordan goss
 * last updated: 2/22/2013
 * 
 * Stopwatch can be used to get running time of programs or functions 
 */ 
#ifndef STOPWATCH_H_ 
#define STOPWATCH_H_

#include <time.h>

//convertion constants
#define MICRO_IN_SEC 1000000
#define MICRO_IN_MILL 1000
#define MILL_IN_SEC   1000

//define time structures and functions for Windows
#if defined(_WIN32) || defined(WIN32)
    #include <windows.h>
    //Since windows time functions aren't portable
    //implement our own structures that follow POSIX
    //Implementation taken from: 
    //http://stackoverflow.com/questions/2494356/how-to-use-gettimeofday-or-something-equivalent-with-visual-studio-c-2008/5197874#5197874
    struct timezone 
    {
          __int32  tz_minuteswest; /* minutes W of Greenwich */
            bool  tz_dsttime;     /* type of dst correction */
    };

    //holds current time since Epoch with seconds and microseconds
    struct timeval {
        __int32    tv_sec;         /* seconds */
        __int32    tv_usec;        /* microseconds */
    };

    /**
     *gettimeofday
     *  gets the current time and time zone
     *Precondition:
     *      valid timeval and time zone structures
     *Post condition:
     *      updates tv and tz with time and timezone
     */
    int gettimeofday(struct timeval *tv/*in*/, struct timezone *tz/*in*/)
//Unix already has time functions and structures needed
#else
   #include <sys/time.h> //timeval, timezone, gettimeofday
#endif 

//keeps track of elapsed time
class Stopwatch{
    private:
        //time values
        struct timeval _begin; //begin time
        struct timeval _end;   //end time
        struct timeval _elapsed; //elapsed time
       
        /**
         *diff
         *  takes the difference between _begin and _end time
         *Precondition: none
         *Postcondition: updates _elapsed with the difference
         */
        void diff();
    public:
        Stopwatch();
        ~Stopwatch();

        /**
         * start
         *   starts the stop watch
         * Precondition: none
         * Postcondition:
         *      _start will be updated with current time
         *      since epoch
         */
        void start();

        /**
         *stop
         * stops the stopwatch and returns elapsed time
         *
         * precondition: start should be run first
         * Postcondition:
         *      updates _end and _elapsed
         *      returns elapsed time in microseconds
         */
        int stop();

        /**
         *time
         * gets the elapsed time of stopwatch in microseconds
         * Precondition: start and stop should be run before
         * Postcondition: returns elapsed time in microseconds
         */
        int time();

        /**
         * to_milliseconds
         *  converts elapsed time to milliseconds
         *Precondition: start and stop should be run before
         *Postcondition: returns elapsed time in ms
         */
        double to_milliseconds();

        /**
         * to_seconds
         *  converts elapsed time to milliseconds
         *Precondition: start and stop should be run before
         *Postcondition: returns elapsed time in sec
         */
        double to_seconds();
        
        /**
         *reset
         * resets all values in time structures to zero
         * Preconditions: none
         * Postcondition: 
         *      tv_sec and usec  in _begin, _end, _elapsed
         *      will be set to zero
         */
        void reset();
};    
#endif //STOPWATCH_H_
