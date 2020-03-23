#include <iostream>
#include <chrono>
#include <cmath>

#include "example.hpp"

int main(int argc, char *argv[])
{
	//Starting time
	    std::chrono::high_resolution_clock::time_point time_start = std::chrono::high_resolution_clock::now();

	PrintSomething(argv[1]);

	//Ending time and computing time
		std::chrono::high_resolution_clock::time_point time_end = std::chrono::high_resolution_clock::now();
		double durationTotal =1e-6*std::chrono::duration_cast<std::chrono::microseconds>( time_end - time_start ).count();
		std::cout <<"\nProcessing Time:\t"<< durationTotal<<"s ("<< floor(durationTotal/3600.0)<<":"<<floor(fmod(durationTotal/60.0,60.0))<<":"<<floor(fmod(durationTotal,60.0))<<":"<<floor(fmod(1000*durationTotal,1000.0))<<")."<<std::endl
		<<"##############################"<<std::endl;
	return 0;
}