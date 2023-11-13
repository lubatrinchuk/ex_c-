// задача 2
#include <iostream>

namespace myspace {

	int cubeV(int a) {
		return a * a * a;
	}

}

int main()
{
	int b = 9;
	std::cout << myspace::cubeV(b);
}