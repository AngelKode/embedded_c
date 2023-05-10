#pragma once
#ifndef INITIAL_EXAMPLES
#define INITIAL_EXAMPLES

#include <iostream>

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
	constexpr int calculateAtCompileTime1{2};

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
	double* ptrToDouble = reinterpret_cast<double*>(numberToCast);

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

	std::cout << "The collection contains " << totalUniques << " unique numbers, they are : ";
	for (auto cont = 0; cont < totalUniques; cont++) {
		std::cout << uniqueNums[cont] << " ";
	}
}

void pointers() {
	int myInt = 20;
	int* ptrInt{ &myInt };

	const char* myPhrase = "asdsdsa";
	const char* myPhrase[] = { "asdsa" , "asdsa"};

	int* const constPtr{ &myInt };//const ptr
	const int* constVar{ &myInt };//const var

	int numbers[] = { 1,2,3,4 };
	int* ptrNumbers{ numbers };//array decay in pointer, loses some information
}




#endif // !INITIAL_EXAMPLES

