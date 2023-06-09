// Copyright 2023 <Copyright AngelKode>
#pragma once
#ifndef INITIAL_EXAMPLES
#define INITIAL_EXAMPLES

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <optional>

namespace cpp_course {
	class Base {
	public:
		virtual void foo() = 0;

		Base() = default;

		bool operator==(const Base& other) const = default;
	};

	class Derived : public Base {
	public:
		void foo() override {
			std::cout << "Derived::foo()" << std::endl;
		}

		Derived() = default;

		bool operator==(const Derived& other) const = default;
	};

	class Cylinder {
	private:
		uint64_t height, volume;
	public:
		// constructor delegation to the constructor that needs 2 parameters
		Cylinder() : Cylinder(0, 0) {}

		// Using initializer list
		// use explicit to avoid implicit conversion
		explicit Cylinder(const uint64_t& height, const uint64_t& volume) : height(height), volume(volume) {
			// The same as
			// this->height = height etc...
		}

		// copy constructor
		Cylinder(const Cylinder& cylinderReference)
			: height(cylinderReference.height), volume(cylinderReference.volume) {}

		bool operator==(const Cylinder& other) const {
			return this->height == other.height && this->volume == other.volume;
		}
	};

	void celsius_to_fahrenheit() {
		float celsiusIn{};
		float fahrenheitOut{};

		std::cout << "Enter celsius degrees: ";
		std::cin >> celsiusIn;

		fahrenheitOut = (static_cast<float>(9.0) / static_cast<float>(5))
			* celsiusIn + 32;
		std::cout << celsiusIn << " Celsius is " << fahrenheitOut << " Fahrenheit\n";
	}

	void constant_expressions() {
		// For evaluate things at compile time
		// instead run time
		constexpr int calculateAtCompileTime1{ 2 };

		int number1{ 10 };
		const int number2{ 10 };

		// constexpr int batInitializing{number1};  // Cannot initialize with
													// variables that are not constant
		constexpr int goodInitializing{ number2 };  // OK
	}

	void casting_data() {
		// Old method, insecure
		int number1{ 20 };
		double doubleNumber{ 20.1929 };
		// number1 = (double) doubleNumber;

		// Better
		number1 = static_cast<int>(doubleNumber);

		// Const cast
		const int constantNumber1{ 20 };
		int* gettingConstantValue = const_cast<int*>(&constantNumber1);

		// Reinterpret cast
		int numberToCast{ 15 };
		// double* ptrToDouble = reinterpret_cast<double*>(numberToCast);

		// Dinamic cast
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

		// std::cout << "The collection contains " << totalUniques << " unique
		// numbers, they are : ";
		for (auto cont = 0; cont < totalUniques; cont++) {
			// std::cout << uniqueNums[cont] << " ";
		}
	}

	void pointers() {
		int myInt = 20;
		int* ptrInt{ &myInt };

		const char* myPhrase = "asdsdsa";
		// const char* myPhrase[] = { "asdsa" , "asdsa" };

		int* const constPtr{ &myInt };  // const ptr
		const int* constVar{ &myInt };  // const var

		int numbers[] = { 1, 2, 3, 4 };
		int* ptrNumbers{ numbers };  // array decay in pointer, loses some information

		// Pointer difference
		int* ptr1{ numbers + 1 };
		int* ptr2{ numbers + 3 };
		std::ptrdiff_t diff1 = ptr2 - ptr1;
	}

	void characters_and_strings() {
		// If a character is alphanumeric
		char letterC{ 'C' };
		char charMinus{ '<' };
		std::cout << "Letter C is Alphanumeric?: " << std::isalnum(letterC) << '\n';
		std::cout << "Letter < is Alphanumeric?: " << std::isalnum(charMinus) << '\n';

		// If a character is blank
		char notBlank{ 'a' };
		char itsBlank{ ' ' };
		std::cout << "a is blank?: " << std::isblank(notBlank) << '\n';  // returns 0 if not
		std::cout << "  is blank?: " << std::isblank(itsBlank) << '\n';
		// If a character is lower/upper case
		char charLower{ 'a' };
		char charUpper{ 'A' };
		if (std::islower(charLower)) {
			std::cout << "a is lower" << '\n';
		}
		if (std::isupper(charUpper)) {
			std::cout << "A is upper " << '\n';
		}

		// switching lower/upper letters
		char changedUpper = std::toupper(charLower);
		char changedLower = std::tolower(charUpper);

		// Size of a c-string
		const char myCString[]{ "Hello" };
		const char* myCStringPointer{ "Hello again" };  // Array decay into pointer

		std::cout << "The size of first c-string is: ";
		std::cout << std::strlen(myCString) << '\n';

		std::cout << "The size of second c-string is: ";
		std::cout << std::strlen(myCStringPointer) << '\n';

		std::cout << "If we use sizeof in a decayed array into pointer";
		std::cout << "we get the size of the pointer : " << sizeof(myCStringPointer) << '\n';
		std::cout << "Size of a char: " << sizeof(const char*) << '\n';

		// Commparing strings
		const char* firstString{ "Mountain" };
		const char* secondString{ "Mounteee" };

		std::cout << "(Mountain, Mountee): " << std::strcmp(firstString, secondString) << '\n';

		// Finding occurrences
		// but the function itself return the first ocurrence
		const char* stringToSearch{ "Searching letters" };
		char target = 'e';
		const char* pointerToString = stringToSearch;

		while ((pointerToString = std::strchr(pointerToString, target)) != nullptr) {
			std::cout << "Ocurrence find at " << pointerToString << '\n';
			pointerToString++;
		}

		// Last ocurrence
		const char* result = std::strrchr(stringToSearch, target);

		// If its different of null
		if (result) {
			std::cout << "String result: " << result << '\n';
		}

		// Concat strings
		char destination[50] = "How are you?: ";
		const char* source{ "Im okay" };

		strcat_s(destination, sizeof(destination), source);

		std::cout << "Result: " << destination << '\n';

		// Copy strings
		const char* stringToCopy{ "Im a string to copy" };
		char* stringDest{ new char[std::strlen(stringToCopy) + 1] {} };

		strcpy_s(stringDest, std::strlen(stringToCopy) + 1, stringToCopy);
		std::cout << "String dest new value: " << stringDest << std::endl;

		// Strings
		std::string myString {"Hi"};
		myString.append(5, '.');
		std::cout << myString << std::endl;

		// Append 2 std::string
		std::string myString2 {std::string {"Hi"} + " World"};
		// Or
		std::string myString3 {myString + ' ' + myString2};
		std::cout << myString << std::endl;

		// Compare strings in lexicographical order
		std::string anotherString{"H"};
		std::cout << myString.compare(anotherString) << std::endl;

		// Replacing part of the string
		std::string originalString{ "Hi I am Ana" };
		std::string stringToReplaceWith{ "George" };

		originalString.replace(8, 10, stringToReplaceWith);
		std::cout << originalString << " new value\n";

		// Copy from a std::string using char*
		char* copiedFromString = new char[7];
		originalString.copy(copiedFromString, 7, 8);
		copiedFromString[6] = '\0';  // Add null terminator
		std::cout << copiedFromString << '\n';
		delete[] copiedFromString;  // Free space
		// now using std::string when copy from std::string to another std:string
		std::string copiedFromString_String;
		const int sizeOfCopy = 11;
		copiedFromString_String.resize(sizeOfCopy);  // Automatically add null character
		originalString.copy(&copiedFromString_String[0], sizeOfCopy, 3);
		std::cout << copiedFromString_String << '\n';
		// when resize up, we can specify what character to fill of the extra spaces
		copiedFromString_String.resize(15, 'a');
		std::cout << copiedFromString_String << '\n';

		// swapping between strings
		copiedFromString_String.swap(myString);
		std::cout << copiedFromString_String << '\n';  // will contain Hi......

		// Find in a std::string
		std::string stringSearch{ "My coffee is cold" };
		std::string stringSearching{ "mountain" };
		size_t posFounded = stringSearch.find(stringSearching);

		if (posFounded != std::string::npos) {
			std::cout << "Founded at " << posFounded << '\n';
		}
		else {
			std::cout << "Not founded" << '\n';
		}

		stringSearching = "o";

		posFounded = stringSearch.find_last_of(stringSearching);

		if (posFounded != std::string::npos) {
			std::cout << "Founded at " << posFounded << " " << stringSearch[posFounded] << '\n';
		}
		else {
			std::cout << "Not founded" << '\n';
		}

		// std::string to numbers and visceversa
		// 2 can be int, double, etc
		std::string castedString{ std::to_string(2) };

		// If the string to be casted into a number is bad, an exception is thrown
		try {
			int castedToNumber{ std::stoi("2sadblw") };  // if has at the beginning some numbers, it will stop until numbers finded
			int castedToNumberOK{ std::stoi("12sdsaka") };  // it will store 12
			uint64_t castedToNumberOK2{ std::stoul("32.123") };  // it will store a positive number if negative and only the number before .
			std::cout << castedToNumberOK2 << '\n';
		}
		catch (const std::invalid_argument& exception) {
			std::cout << "Invalid argument: " << exception.what() << '\n';
		}

		// Raw string literals
		std::string myLiteral{R"(Hi \t you
)"};
		std::cout << myLiteral;

		// Copying strings
		std::string stringOne{ "Im string one" };
		std::string& stringTwo{ stringOne };

		const char* ptr1 = stringOne.data();
		const char* ptr2 = stringTwo.data();
		std::cout << reinterpret_cast<void*>(const_cast<char*>(ptr2));  // using const_cast to remove the const
		std::cout << " -- ";
		std::cout << reinterpret_cast<void*>(const_cast<char*>(ptr1)) << '\n';  // using const_cast to remove the const

		// string_view
		std::string_view myStringView{ stringOne };
		myStringView.remove_prefix(3);  // will remove 'Im ';
		myStringView.remove_suffix(4);  // will remove ' one';
		// changes only on the view

		std::cout << std::strlen(myStringView.data()) << '\n';  // will contain bad data bc removing methods
		std::cout << myStringView << '\n';
	}

	bool is_number_palindrome(uint64_t number) {
		uint64_t number_reversed{ 0 };
		uint64_t auxNumber{ 0 };
		uint32_t digitCounter{ 1 };
		uint64_t initial_number{ number };
		size_t numberSize{ std::to_string(number).length() };
		while (number != 0) {
			auxNumber = number % 10;
			number /= 10;
			number_reversed += auxNumber * static_cast<uint64_t>(pow(10, numberSize - digitCounter));
			digitCounter++;
		}
		std::cout << initial_number << "--" << number_reversed << '\n';
		return initial_number == number_reversed;
	}

	std::optional<uint64_t> optionalFunction(uint64_t dividend, uint64_t divisor) {
		if (divisor == 0) {
			return std::nullopt;
		}

		return dividend / divisor;
	}

	void static_variables() {
		// The static variable dont get deleted after getting out of scope
		// every time we call this function, the variable myCount get added 1: 1,2,3,etc
		static uint64_t myCount {0};
		myCount++;
		std::cout << myCount << '\n';
	}
}  // namespace cpp_course

#endif  // !INITIAL_EXAMPLES
