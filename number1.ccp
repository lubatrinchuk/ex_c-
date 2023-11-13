// задача 1
#include <iostream>

namespace myspace{

	void printNTimes(const char* str, int n = 10){
		for (int i = 1; i <= n; ++i){
			std::cout << str << "\n";
		}
	}

}

int main()
{
	const char* st = "love";
	myspace::printNTimes(st);
}