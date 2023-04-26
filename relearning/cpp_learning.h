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
}

#endif // !CPP_LEARNING

