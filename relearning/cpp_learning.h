#pragma once
#ifndef CPP_LEARNING
#define CPP_LEARNING

#include <iostream>

/*Output formatting*/
#include <iomanip>
/*Output formatting*/

/*Numeric limits*/
#include <limits>
/*Numeric limits*/

namespace cplusplus {
	inline void manipulate_io(void) {
		//Add new line
		std::cout << "Add new line" << std::endl;

		//Send data to terminal(device stream that is connected)
		std::fflush(NULL);

		//Setting width to each part printed
		std::cout << "Table using setw" << std::endl;
		std::cout << std::setw(10) << "School" << std::setw(10) << "Name" << std::endl;
		std::cout << std::setw(10) << "MIT" << std::setw(10) << "PEDRO" << std::endl;
		std::cout << std::setw(10) << "UNAM" << std::setw(10) << "LUIS" << std::endl;
		std::cout << std::setw(10) << "UAZ" << std::setw(10) << "JUANA" << std::endl;
		std::cout << std::setw(10) << "ITESM" << std::setw(10) << "LUISA" << std::endl;
		
		//Set text justification
		std::cout << std::right;
		std::cout << "Right justification" << std::endl;
		std::cout << "Another line" << std::endl;
		
		//Set boolalpha
		std::cout << std::boolalpha; 
		std::cout << true << endl;
		std::cout << std::noboolalpha;
		std::cout << true << endl;

		//Show +/- sign
		std::cout << std::showpos;
		std::cout << -45 << endl;
		std::cout << std::noshowpos;
		std::cout << -45 << endl;

		//Show in different number systems
		std::cout << std::dec << 12 << endl;
		std::cout << std::hex << 12 << endl;
		std::cout << std::oct << 12 << endl;

		//Show base (only integrals)
		std::cout << std::showbase;
		std::cout << std::dec << 12 << endl;
		std::cout << std::hex << 12 << endl;
		std::cout << std::oct << 12 << endl;
		
		//UPPERCASE & LOWERCASE
		std::cout << std::nouppercase;
		std::cout << "noupper" << 0b11010010 << std::endl;
		std::cout << std::uppercase;
		std::cout << "upper" << 0b11010010 << std::endl;

		//Set precision
		std::cout << std::setprecision(2);
		std::cout << 3.12142121 << std::endl;

		//Showpoint (trailing zeros when necesary)
		std::cout << std::showpoint;
		std::cout << 12 << std::endl;
		std::cout << 12.1 << std::endl;
	}

	inline void numeric_limits(void) {
		std::cout << "Limit for integers is from " << std::numeric_limits<int>::min() <<
					 " to " << std::numeric_limits<int>::max() << std::endl;
		std::cout << "Limit for unsigned integers is from " << std::numeric_limits<unsigned int>::min() <<
			" to " << std::numeric_limits<unsigned int>::max() << std::endl;
	}

	inline void math_functions(void) {
		//Floor and ceil
		std::cout << std::floor(20.4) << std::endl;
		std::cout << std::ceil(20.4) << std::endl;

		//Absolute value
		std::cout << std::abs(-120) << std::endl;
		std::cout << std::abs(120) << std::endl;

		//Exponential (e^x)
		std::cout << std::fixed;
		std::cout << "e elevate to 23: " << std::exp(23) << std::endl;
		
		//Pow
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		std::cout << "4 ^ 12: " << std::pow(4, 12) << std::endl;

		//Log is reversed of pow operation, 2^3 = 8, Log 8 in base 2 = 3
		//ask to which exponent we need to elevate base of log to get 8
		std::cout << "To get 23.12 we need to elevate 2 to: " << std::log2(23.12) << std::endl;

		//Square root
		std::cout << "The square root of 24.12: " << std::sqrt(24.12) << std::endl;
	
		//Round
		std::cout << "3.5 rounded is: " << std::round(3.4) << std::endl;
	}

	inline void weird_integral_types(void) {
		short int v1{ 10 };
		short int v2{ 20 };

		char v3{ 40 };
		char v4{ 50 };

		std::cout << "size of v1: " << sizeof(v1) << std::endl;
		std::cout << "size of v2: " << sizeof(v2) << std::endl;
		std::cout << "size of v3: " << sizeof(v3) << std::endl;
		std::cout << "size of v4: " << sizeof(v4) << std::endl;

		auto r1 = v1 + v2;
		auto r2 = v3 + v4;

		std::cout << "size of r1: " << sizeof(r1) << std::endl;
		std::cout << "size of r2: " << sizeof(r2) << std::endl;
	}

	inline void arrays(void) {
		char message[] = { "Hellow World!" };

		for (auto& c : message) {
			std::cout << c;
		}
		std::cout << std::endl;

		//Or
	
		std::cout << message << std::endl;
		std::cout << "Size of the array: " << std::size(message) << std::endl;
	}

	inline void pointers_ex(void) {
		int* ptrInt{ nullptr };
		int valueInt{23};

		ptrInt = &valueInt;

		std::cout << *ptrInt << std::endl;

		char p_message[] { "asd" };
	}

	inline void dinamic_memory(void) {
		int* dinamicPointer{ new int(34) };

		*dinamicPointer = 46;

		std::cout << *dinamicPointer << std::endl;

		//Free heap memory
		delete dinamicPointer;
		dinamicPointer = nullptr;
	}
}

#endif // !CPP_LEARNING

