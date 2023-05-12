#pragma once
#ifndef INITIAL_EXAMPLES
#define INITIAL_EXAMPLES

#include <iostream>
#include <cctype>
#include <cstring>

namespace cpp_course {
	class Base {
	public:
		virtual void foo() = 0;
	};

	class Derived : public Base {
	public:
		void foo() override {
			std::cout << "Derived::foo()" << std::endl;
		}
	};

	void celsius_to_fahrenheit() {
		float celsiusIn{};
		float fahrenheitOut{};

		std::cout << "Enter celsius degrees: ";
		std::cin >> celsiusIn;

		fahrenheitOut = ((float)9.0 / (float)5) * celsiusIn + 32;
		std::cout << celsiusIn << " Celsius is " << fahrenheitOut << " Fahrenheit\n";
	}

	void constant_expressions() {
		//For evaluate things at compile time
		//instead run time
		constexpr int calculateAtCompileTime1{ 2 };

		int number1{ 10 };
		const int number2{ 10 };

		//constexpr int batInitializing{number1};//Cannot initialize with variables that are not constant
		constexpr int goodInitializing{ number2 };//OK
	}

	void casting_data() {
		//Old method, insecure
		int number1{ 20 };
		double doubleNumber{ 20.1929 };
		number1 = (double)doubleNumber;

		//Better
		number1 = static_cast<int>(doubleNumber);

		//Const cast
		const int constantNumber1{ 20 };
		int* gettingConstantValue = const_cast<int*>(&constantNumber1);

		//Reinterpret cast
		int numberToCast{ 15 };
		//double* ptrToDouble = reinterpret_cast<double*>(numberToCast);

		//Dinamic cast
		Base* base = new Derived;
		Derived* derived = dynamic_cast<Derived*>(base);

		if (derived) {
			//
		}
	}

	void eliminate_duplicates_array(int numbers[], unsigned int collection_size) {
		bool isRepeated{ false };
		int uniqueNums[20]{};
		int totalUniques{ 0 };

		for (unsigned int i = 0; i < collection_size; i++) {
			isRepeated = false;
			for (int iUN = 0; iUN < totalUniques; iUN++) {
				if (uniqueNums[iUN] == numbers[i]) {
					isRepeated = true;
					break;
				}
			}

			if (!isRepeated) {
				uniqueNums[totalUniques] = numbers[i];
				totalUniques++;
			}
		}

		//std::cout << "The collection contains " << totalUniques << " unique numbers, they are : ";
		for (auto cont = 0; cont < totalUniques; cont++) {
			//std::cout << uniqueNums[cont] << " ";
		}
	}

	void pointers() {
		int myInt = 20;
		int* ptrInt{ &myInt };

		const char* myPhrase = "asdsdsa";
		//const char* myPhrase[] = { "asdsa" , "asdsa" };

		int* const constPtr{ &myInt };//const ptr
		const int* constVar{ &myInt };//const var

		int numbers[] = { 1,2,3,4 };
		int* ptrNumbers{ numbers };//array decay in pointer, loses some information

		//Pointer difference
		int* ptr1{ numbers + 1 };
		int* ptr2{ numbers + 3 };
		std::ptrdiff_t diff1 = ptr2 - ptr1;
	}

	void characters_and_strings() {
		//If a character is alphanumeric
		char letterC{ 'C' };
		char charMinus{ '<' };
		std::cout << "Letter C is Alphanumeric?: " << std::isalnum(letterC) << '\n';
		std::cout << "Letter < is Alphanumeric?: " << std::isalnum(charMinus) << '\n';

		//If a character is blank
		char notBlank{ 'a' };
		char itsBlank{ ' ' };
		std::cout << "a is blank?: " << std::isblank(notBlank) << '\n';//returns 0 if not
		std::cout << "  is blank?: " << std::isblank(itsBlank) << '\n';

		//If a character is lower/upper case
		char charLower{ 'a' };
		char charUpper{ 'A' };
		if (std::islower(charLower)) {
			std::cout << "a is lower" << '\n';
		}
		if (std::isupper(charUpper)) {
			std::cout << "A is upper " << '\n';
		}

		//switching lower/upper letters
		char changedUpper = std::toupper(charLower);
		char changedLower = std::tolower(charUpper);

		//Size of a c-string
		const char myCString[]{ "Hello" };
		const char* myCStringPointer{ "Hello again" };  // Array decay into pointer

		std::cout << "The size of first c-string is: " << std::strlen(myCString) << '\n';
		std::cout << "The size of second c-string is: " << std::strlen(myCStringPointer) << '\n';
		std::cout << "If we use sizeof in a decayed array into pointer, we get the size of the pointer: " << sizeof(myCStringPointer) << '\n';
		std::cout << "Size of a char: " << sizeof(const char*) << '\n';

		//Commparing strings
		const char* firstString{ "Mountain" };
		const char* secondString{ "Mounteee" };

		std::cout << "(Mountain, Mountee): " << std::strcmp(firstString, secondString) << '\n';

		//Finding occurrences
		//but the function itself return the first ocurrence
		const char* stringToSearch{ "Searching letters" };
		char target = 'e';
		const char* pointerToString = stringToSearch;

		while ((pointerToString = std::strchr(pointerToString, target)) != nullptr) {
			std::cout << "Ocurrence find at " << pointerToString << '\n';
			pointerToString++;
		}

		//Last ocurrence
		const char* result = std::strrchr(stringToSearch, target);

		//If its different of null
		if (result) {
			std::cout << "String result: " << result << '\n';
		}

		//Concat strings
		char destination[50] = "How are you?: ";
		const char* source{ "Im okay" };

		strcat_s(destination, sizeof(destination), source);

		std::cout << "Result: " << destination << '\n';
	}
}

#endif // !INITIAL_EXAMPLES

