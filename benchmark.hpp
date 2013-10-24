/**
*benchmark.hpp
*last updated: 02/23/2013
*by jordan goss
* performs benchmark on functions giving the average,
* worst, best, and total running time. 
*
*/

#ifndef  BENCHMARK_H_
#define  BENCHMARK_H_
#include "stopwatch.hpp" //Stopwatch

//benchmark running times 
#define SHORT_RUN  100 
#define MEDIUM_RUN 10000
#define LONG_RUN   100000 
#define LONG_LONG_RUN 1000000

namespace benchmark {

//choices for Benchmarks
enum BenchmarkType{
    SHORT,
    MEDIUM,
    LONG,
    VERY_LONG
};
class Benchmark {
    private:
        double _avg;   //average time in microseconds 
        double _total; //total time in microseconds;
        double _worst; //worst time in microseconds
        double _best; //best time in microseconds 
        Stopwatch _stopw; //timer for benchmark
    public:
        Benchmark();
        ~Benchmark();

        /**
         *get_average
         *  gets average of running times for benchmark
         *Precondition: benchmark should be run first 
         *Postcondition: returns the average time
         */
        double get_avg();

        /**
         *get_best
         *  gets the best running time for benchmark
         *Precondition: benchmark should be run first 
         *Postcondition: returns the best running time 
         */
        double get_best();
        /**
         *get_worst
         *  gets the worst running time for benchmark
         *Precondition: benchmark should be run before
         *Postcondition: returns worst running time 
         */
        double get_worst();

        /**
         *get_total
         *  gets accumlated total running times for
         *  benchmark
         *Precondition: benchmark should be run before
         *Postcondition: returns total running time
         */
        double get_total();

        /**
         *run
         *  runs the benchmark for a test function 
         *  with a benchmark type
         *Preconditions:
         *  PARAMS: test_funct = function to run benchmark on
         *          bt = benchmark type to run
         *Postcondition:
         *      _best, _worst, _avg, _total will be updated
         */
        void run(void (*test_func)(), BenchmarkType bt);
        
        /**
         *reset
         * resets all the running time variables
         *
         * Precondition: None
         * Postcondition: _best, _worst, _avg, _total will be
         *  set to 0; _stopw will also be reset
         */
        void reset();

        /**
         *get_runs
         *  returns number of runs for a benchmark type
         *precondition: 
         *    must be passed a valid benchmark type
         *    Params:
         *      bt = benchmark type to get # of runs for
         *postcondition: returns number of runs for benchmark type
         */
        size_t get_runs(BenchmarkType bt);

};
}//benchmark namespace
#endif //BENCHMARK_H_
