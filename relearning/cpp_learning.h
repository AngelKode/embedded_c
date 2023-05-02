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

#include <stdbool.h>//For bool keyword 
#include <string>//For strings
#include <array>//For arrays
#include <vector>//For vectors
#include <unordered_set>
#include <set>
#include <bitset>
#include <list>
#include <queue>
#include <algorithm>

namespace cplusplus {
	inline void datatypes(void) {
		std::cout << std::setprecision(64);
		
		//Integers, float and doubles
		int integer1 = 20;
		float pi = 3.14123112312133123213;//Store as 3.1412311, not recomendable, better initialize with maximun 7 precision digits
		double pi2 = 3.1412311321312312323;//Store more digits than float

		std::cout << integer1 << "\n" <<  pi2 << "\n";
		
		//MAX, MIN VALUES
		std::cout << INT_MAX << '\n';//Integer 64-BIT SIGNED
		std::cout << LONG_MAX << '\n';//Integer 64BIT 
		std::cout << DBL_MAX << '\n';//Integer
		std::cout << FLT_MAX << '\n';//Integer

		//Strings
		
		//Initialization
		std::string myName = "John Doe";

		char name_char[] = "Pedro";
		std::string myName2(name_char);

		//Some Methods
		//myName.at(2);
		//myName.max_size();
		//myName.capacity();

		//Char and Char*
		char myChar = 'a';
		char* myDinamicChar = new char('a');
		//Or
		char* myDinamicChar2 = &myChar;

		//Maps
		std::map<std::string, int> myMap{};//Without initial values
		std::map<std::string, int> myMapWithValues = { {"john",1}, {"john 2",2}, {"john 4",3} };//With initial values

		//Some methods
		//Insert, return boolean
		myMap.insert(std::make_pair("Juan", 12));
		//Also can use iterators, the following will add all values of myMapWithValues into myMap
		myMap.insert(myMapWithValues.begin(), myMapWithValues.end());

		//To update an specific key, create a pair with that key and will be replaced
		myMap.insert(std::make_pair("Juan", 20));//Juan will change to 20

		//Access to keys
		int valueJuan = myMap["Juan"];
		
		//Find element by key
		auto iteratorFinded = myMap.find("Juan");
		if (iteratorFinded != myMap.end()) {
			std::cout << iteratorFinded->second << '\n';
		}
		else {
			std::cout << "Not founded:( \n";
		}
		
		//SETS
		std::set<int> values = std::set<int>{ 12,3,1,2 };

		//BITS
		std::bitset<16> bits_16 = 1010101010101010;
		bits_16[2] = 0;
		//Set all bits to 0
		bits_16.reset();
		//Set specific bit or a range of bits to 1
		bits_16.set(0);
		bits_16.set(0,2);

		//List
		std::list<unsigned int> integer_list;

		//Add elements
		integer_list.push_back(2);
		integer_list.push_back(23);
		integer_list.push_back(22);

		//Sorting list
		integer_list.sort();
		
		//Some methods
		integer_list.front();//Get the first element
		integer_list.unique();//Delete repeated elements
		integer_list.remove(1);//Delete at specific index
		integer_list.size();//Get the number of elements

		std::cout << "List: \n";
		for (auto it = integer_list.begin(); it != integer_list.end(); it++) {
			std::cout << *it << '\n';
		}
	}

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

		//Also use array class
		std::array<int, 5> my_array = { 1, 2, 3 };

		//And dinamically
		std::array<int, 5>* my_dinamic_array = new std::array<int, 5>();

		//VECTORS
		
		//Intialize a vector
		std::vector<int> vector1{1,2,3,4};

		//Resize a vector
		vector1.resize(5);

		//Assign new values and resize it
		vector1.assign(5,2);

		//Also has internal pointers(iterator)
		std::vector<int>::iterator it1 = vector1.begin();

		//Next, to set iterator in specific position
		std::vector<int>::iterator iteratorMoved = std::next(vector1.begin(), 3);

		//And loop trough it
		while ((it1 != vector1.end())) {
			std::cout << *it1 << "-";
			it1++;
		}
	}

	inline void pointers_ex(void) {
		int* ptrInt{ nullptr };
		int valueInt{ 23 };

		ptrInt = &valueInt;

		//std::cout << *ptrInt << std::endl;

		//Const pointers that point to const variables cannot re-assing to another memory location
		//and can not change tha value of the variable
		const int value = 2;
		const int* const ptrIntConst = &value;
		std::cout << &ptrIntConst << std::endl;
		//ptrIntConst = &otherValue;//Compiler error
		//*ptrIntConst = 20;//Compiler error

		//Const Pointers to values can change its value but can not change
		//the value of the variable that are pointing to.
		int otherValue = 20;
		int* const intConst = &otherValue;
		//*intConst = 23;//ok
		//intConst = &value;//not ok

		//Pointer to const values can not change its value but can change
		//the value of the variable that are pointing to.
		const int* notConsPtr = &otherValue;
		//*notConsPtr = 20;//not ok
		//notConsPtr = &otherValue;//ok

		//Pointer to values can change its value and can change
		//the value of the variable that are pointing to.
		int* notConstPtr2 = &otherValue;
		//*notConstPtr2 = 20;//ok
		//notConstPtr2 = &otherValue;//ok
	}

	inline void dinamic_memory(void) {
		int* dinamicPointer{ new int(34) };

		*dinamicPointer = 46;

		std::cout << *dinamicPointer << std::endl;

		//Free heap memory
		delete dinamicPointer;
		dinamicPointer = nullptr;
	}

	inline void new_fails(void) {
		int* ints{ new(std::nothrow) int[1000000000] };

		if (ints == nullptr) {
			std::cout << "Memory allocation failed" << std::endl;
			return;
		}

		std::cout << "Memory allocation succeeded" << std::endl;
	}

	inline void nullptr_check(void) {
		int* ptr{new int(45)};

		if (!ptr) {
			std::cout << "Pointer allocated NOT OK" << std::endl;
			return;
		}

		std::cout << "Pointer allocated OK" << std::endl;
	}

	inline void dinamic_array(void) {
		int* pIndexes{ new int[20] {} };
		//Release memory heap
		delete[] pIndexes;
		pIndexes = nullptr;
	}

	inline void string_manipulation(void) {
		//Lenght of the string
		const char message[]{ "Today is a sunny day" };
		std::cout << "Message length: " << std::strlen(message) << std::endl;
	
		//Lenght of the string with sizeof takes null character
		std::cout << "Message length: " << sizeof(message) << std::endl;
		
		//Compare strings
		const char* string1{ "Alabama" };
		const char* string2{ "Alabama" };

		std::cout << "Strcmp: " << std::strcmp(string1, string2) << std::endl;
	
		//Find first occurrence
		const char* phrase{ "Find P me PLS" };
		char target = 'P';
		const char* result = phrase;


		result = std::strchr(phrase, target);
		std::cout << &result << std::endl;

		//Find last ocurrence
		result = phrase;
		result = std::strrchr(phrase, target);
		std::cout << &result << std::endl;

		//Copy
		char* strDest;
		const char* strSource{"Im gonna get copied"};

		//Allocate memory for destination
		//Add 1 por null pointer at the end
		strDest = (char*) malloc(sizeof(char) * strlen(strSource) + 1);

		//Copy the content to the destination array
		strcpy_s(strDest, strlen(strSource) + 1, strSource);
		std::cout << strDest << std::endl;

		//Free memory
		free(strDest); strDest = nullptr;
	}
}

#endif // !CPP_LEARNING

