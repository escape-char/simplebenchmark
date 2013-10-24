/**
 * main.cpp
 * Author: Jordan Goss
 * 02/22/2013
 * Tests algorithms with various running times (O(n), O(n^2), O(n^3) etc)
 */
#include <iostream>
#include "benchmark.hpp"

// outer for loop limit for tests runs
#define RUN_COUNT 50 

//number of tests
#define NO_OF_TESTS 6

/**
 *test1
 *  O(n) running time
 *Precondition: 
 *  timer must be set before calling this function
 *Postcondition: 
*   timer is stopped after function call
 */
void test1();

/**
 *test2
 * O(n^2) running time
 *
 *Precondition: 
 *  timer must be set before calling this function
 *Postcondition: 
 *   timer is stopped after function call
 */
void test2();

/**
 *test3
 *  O(n^3) running time
 *Precondition: 
 *  timer should be set before calling this function
 *Postcondition: 
 *   timer should stopped after function call
 */
void test3();

/**
 *test4
 * O(n^2) running time
 *Precondition: 
 *  timer should be set before calling this function
 *Postcondition: 
 *   timer should stopped after function call
 */
void test4();
/**
 *test5
 *O(n^5) running time
 *Precondition: 
 *  timer should set before calling this function
 *Postcondition: 
 *   timer should stopped after function call
 */
void test5();

/**
 *test6 
 *O(n^4) running time
 *Precondition: 
 *  timer should be set before calling this function
 *Postcondition: 
 *   timer is stopped after function call
 */
void test6();

//function pointer type
//useful for array of functions
typedef void (*funct_ptr_t)(void);
  
int main(){
    //tests go here to be run by benchmark
    funct_ptr_t test_func[NO_OF_TESTS] = {test1, test2, test3, test4, test5, test6};
    
    benchmark::Benchmark b; //used for determing running time
   
    //run benchmarks for all the tests
    for(int i = 0; i < NO_OF_TESTS; i++){
        std::cout << "test " << i + 1 << std::endl;
        b.run(test_func[i], benchmark::SHORT);
        b.reset();
    }
   return 0;
}

void test1(){
    int sum = 0; 
    for(int i = 0; i < RUN_COUNT; i++){
       sum +=1; 
    }

}
void test2(){
    int sum = 0;
    for(int i = 0; i < RUN_COUNT; i ++ ){
        for(int j = 0; j < RUN_COUNT; j++){
            sum +=1;
        }
    }
}
void test3(){
    int sum = 0;
    for (int i = 0; i < RUN_COUNT; i++) {
        for (int j = 0; j < (RUN_COUNT*RUN_COUNT); j++) {
           sum++; 
        }
    }
}
void test4(){
    int sum = 0;
    for(int i = 0; i < RUN_COUNT; i ++ ){
        for(int j = 0; j < i; j++){
            sum +=1;
        }
    }
}
void test5(){
    int sum = 0;
    for(int  i = 0; i < RUN_COUNT; i++ ){
        for(int  j = 0; j < i * i; j++ ){
            for(int  k = 0; k < j; k++ )
                sum ++;
        }
    }
}
void test6(){
    int sum = 0;
    for(int  i = 1; i < RUN_COUNT; i++ )
        for(int  j = 1; j < i * i; j++ )
            if( j % i == 0)
               for(int  k = 0; k < j; k++ )
                  sum ++;
};
