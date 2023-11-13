// задача 4
#include <iostream>
using namespace std;

void countLetters(const char* str, int& numLetters, int& numDigits, int& numOther) {

	for (int i = 0; i < strlen(str); i++)
	{
		if (isalpha(str[i]))
			numLetters++;

		else if (isdigit(str[i]))
			numDigits++;

		else
			numOther++;

	}

}

int main()
{
	int letters = 0;
	int digits = 0;
	int other = 0;
	int& numletters = letters;
	int& numdigits = digits;
	int& numother = other;
	const char* st= "2 love is not true!";
	countLetters(st, numletters, numdigits, numother);
	cout << letters << " " << digits << " " << other;
}