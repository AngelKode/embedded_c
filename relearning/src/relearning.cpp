// Copyright 2023 <Copyright AngelKode>
// #include <stdbool.h>
// #include <iostream>
// #include "headers/armadillo_study.h"
// #include "cpp_learning.h"
// #include <string_view>
// using namespace armadillo_ex;
#include "../cpp-course/headers/initial_examples.h"
#include "../cpp-course/graphs/Graph.h"
// using namespace std;

int main(int argc, char** argv) {  // char** argv equals to char* argv[]
	//auto result = cpp_course::optionalFunction(2, 0);

	//if (!result.has_value()) {
	//	std::cout << "The divisor is 0, cant do division\n";
	//	return -1;
	//}

	//std::cout << "The result is: " << result.value() << '\n';

	//cpp_course::static_variables();
	//cpp_course::static_variables();
	//cpp_course::static_variables();
	/*
	matrix_examples().print("Matrix:");
	cout << endl << matrix_examples().col(1)(0) << endl;

	column_vectors_examples().print("Columns: ");

	row_vectors_examples().print("Rows: ");

	tensor_examples().print("Tensor");
	*/

	Graph* myGraph = new Graph(4, { {0,1},{1,3},{1,2},{2,3},{2,0},{1,0} });
	myGraph->print_adjacency_info();

	delete myGraph;

	GraphWeighted* myGraphWeighted = new GraphWeighted(4, { {0,1,2.3},{1,3,1.2},{1,2,32},{2,3,12},{2,0,2},{1,0,17} });
	myGraphWeighted->print_adjacency_info();

	delete myGraphWeighted;

	return 0;
}