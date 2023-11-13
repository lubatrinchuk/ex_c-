// задача 2
#include <iostream>

namespace myspace {

	int cubeR(int& a) {
		return a * a * a;
	}

}

int main()
{
	int a = 5;
	int& b = a;
	std::cout << myspace::cubeR(b);
}