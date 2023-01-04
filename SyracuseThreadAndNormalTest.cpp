#include <iostream>
#include "mingw.thread.h"
#include <chrono> 
#include <fstream>

#define ITERATION 4000000000
#define FILE_NAME "syracuse.txt"

/* Syracuse IOF (alias for In One File) */

inline std::size_t syracuse(std::size_t to) {

	std::size_t tmp = to;
	std::ofstream file_output(FILE_NAME, std::ofstream::app);

	while (tmp != 1) {

		file_output << tmp << std::endl;

		if (tmp % 2 == 0) tmp /= 2;
		else tmp = (3 * tmp) + 1;
	}
	
	file_output.close();
	return tmp;
}

int main() {
	
	std::remove(FILE_NAME);

	std::chrono::high_resolution_clock::time_point start_thread = std::chrono::high_resolution_clock::now();

	std::thread first(syracuse, ITERATION);     
  	std::thread second(syracuse, ITERATION);
  	std::thread third(syracuse, ITERATION);
  	std::thread fourth(syracuse, ITERATION);
  	std::thread fifth(syracuse, ITERATION);

  	std::cout << "Thread >> Start running" << std::endl;

  	first.join();
  	second.join();
  	third.join();
  	fourth.join();
  	fifth.join();

  	std::cout << "Thread >> Complete" << std::endl;
  	std::chrono::duration<double> elapsed_thread_time = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_thread);
  	std::cout << "It lasts : " << elapsed_thread_time.count() << " seconds." << std::endl;

  	std::cout << "-------------------------------------" << std::endl;

  	std::chrono::high_resolution_clock::time_point start_normal = std::chrono::high_resolution_clock::now();

  	std::cout << "Normal >> Start running" << std::endl;

  	syracuse(ITERATION);
  	syracuse(ITERATION);
  	syracuse(ITERATION);
  	syracuse(ITERATION);
  	syracuse(ITERATION);

  	std::cout << "Normal >> Complete" << std::endl;
  	std::chrono::duration<double> elapsed_normal_time = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_normal);
  	std::cout << "It lasts : " << elapsed_normal_time.count() << " seconds." << std::endl;

	return 0;
}
