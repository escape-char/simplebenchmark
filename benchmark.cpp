#include<iostream>
#include<stdio.h>
#include <assert.h> 
#include "benchmark.hpp"

using namespace benchmark;

Benchmark::Benchmark(){this->_best = this->_worst= this->_avg = this->_total = 0;}
Benchmark::~Benchmark(){}
double Benchmark::get_worst(){return this->_worst;}
double Benchmark::get_best(){return this->_best;}
double Benchmark::get_avg(){return this->_avg;}
double Benchmark::get_total(){return this->_total;}
void Benchmark::reset(){
    this->_worst = this->_best = this->_avg = this->_total = 0; 
    this->_stopw.reset();
}

void Benchmark::run(void (*test_func)(), BenchmarkType bt){
    this->reset(); //start new

    //number of times to run each test function
    size_t total_runs = this->get_runs(bt); 

    double current; //current time for test

    std::cout << "Running benchmark..." << std::endl;

    //run benchmark for total runs
    for(size_t i = 0; i < total_runs; i++){
        //run stopwatch
        this->_stopw.start(); 
        test_func(); 
        current = (double) this->_stopw.stop();

        //save best time
        if(this->_best == 0){ this->_best = current;}
        if(current > 0 && current < this->_best){
            this->_best = current;
        }
        //save worst time
        if(current > this->_worst){this->_worst = current;}


        this->_total += current; //tally total for each run

        this->_stopw.reset(); //reset after each run
    }
    std::cout << "benchmark complete" << std::endl;
    std::cout << "------------------" << std::endl;
    
    this->_avg = this->_total / total_runs; //calculate average time

    //display stats
    printf("Average time: %f microseconds\n", (float) this->_avg);
    printf("Total time: %f  microseconds\n", (float) this->_total);
    printf("Best time: %f microseconds\n", (float) this->_best);
    printf("Worst time: %f microseconds\n", (float) this->_worst);
    std::cout << std::endl;

}
size_t Benchmark::get_runs(BenchmarkType bt){

    //find out number of runs based on Benchmark type
    switch(bt){
        case SHORT: return (size_t) SHORT_RUN;
        case MEDIUM: return (size_t) MEDIUM_RUN;
        case LONG:  return (size_t) LONG_RUN;
        case VERY_LONG: return (size_t) LONG_LONG_RUN;
        default:{
                assert(false); //this case should never be reached
                return 0;
        }

    }
}

