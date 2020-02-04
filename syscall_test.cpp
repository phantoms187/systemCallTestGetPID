#include <sys/time.h>
#include <chrono> 
#include <unistd.h>
#include <iostream>
#include <iomanip>      

using namespace std;


int main(){
    
  int pid = 0;
  int micro = 230;
  float syscall_time;

  auto start = chrono::high_resolution_clock::now();

  for (int i=0; i<1000000; ++i)
  {
    pid = getpid();
  }
  
  auto end = chrono::high_resolution_clock::now();
   
  double time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count();

  cout << "Average time for System call getpid: "<< setprecision(4) << time_taken/1000000  << " microseconds" << endl;
  
  return 0;
}