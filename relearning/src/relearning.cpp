// Copyright 2023 <Copyright AngelKode>
// #include <stdbool.h>
// #include <iostream>
// #include "headers/armadillo_study.h"
// #include "cpp_learning.h"
// #include <string_view>
// using namespace armadillo_ex;
#include "../cpp-course/headers/initial_examples.h"
// using namespace std;


int main(int argc, char** argv) {  // char** argv equals to char* argv[]
	auto result = cpp_course::optionalFunction(2, 0);

	if (!result.has_value()) {
		std::cout << "The divisor is 0, cant do division\n";
		return -1;
	}

	std::cout << "The result is: " << result.value() << '\n';
	/*
	matrix_examples().print("Matrix:");
	cout << endl << matrix_examples().col(1)(0) << endl;

	column_vectors_examples().print("Columns: ");

	row_vectors_examples().print("Rows: ");

	tensor_examples().print("Tensor");
	*/
    return 0;
}
