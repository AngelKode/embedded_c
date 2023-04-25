#include <stdbool.h>
#include <iostream>
#include "armadillo_study.h"

using namespace armadillo_ex;
using namespace std;


int main() {

	matrix_examples().print("Matrix:");
	cout << endl << matrix_examples().col(1)(0) << endl;

	column_vectors_examples().print("Columns: ");

	row_vectors_examples().print("Rows: ");

	tensor_examples().print("Tensor");
	return 0;
}