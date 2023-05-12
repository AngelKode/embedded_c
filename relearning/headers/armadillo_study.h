#ifndef ARMADILLO_S
#define ARMADILLO_S
#define ARMA_USE_LAPACK
#include <armadillo>
using namespace arma;

namespace armadillo_ex{
	inline Mat<cx_double> matrix_examples() {
		//fill is a namespace that help us initializing matrix
		fmat floatMatrix(size(2,3), fill::randu);//Mat<float_>
		mat doubleMatrix(3,3,fill::eye); //Mat<double> === dmat
		cx_mat complexMatrix(10,10, fill::eye);//Mat<cx_double> where cx_double = complex<double>
		cx_fmat complexFloatMatrix(10,10);//Mat<cx_float> where cx_float = complex<float>
		umat unsignedIntegerMatrix(2,3,fill::ones);//Mat<uword> where uword = unsigned int
		imat signedIntegerMatrix(2,2);//Mat<sword> where sword = signed int
		mat X(5, 5, fill::randu);
		
		return complexMatrix;
	}
	
	inline fvec column_vectors_examples() {

		vec doubleCol(10,fill::ones);//Col<double>
		fvec floatCol("0 1 2 3 19 2");//Col<float> with strings initialization
		cx_vec complexDoubleCol(3);//Col<cx_double>
		cx_fvec complexFloatCol(5);//Col<cx_float>
		uvec unsignedIntegerCol(5);//<Col<uword>
		ivec signedIntegerCol(5);//Col<sword>

		return floatCol;
	}

	inline cx_rowvec row_vectors_examples() {

		Row<double> doubleRow(4);//rowvec
		frowvec floatRow(5);//Row<float>
		cx_rowvec complexDoubleRow(5);//Row<cx_double>
		cx_frowvec complexFloatRow(5);//Row<cx_float>
		urowvec unsignedIntegerRow(5);//Row<uword>
		irowvec signedIntegerRow(5);//Row<sword>

		return complexDoubleRow;
	}

	inline cube tensor_examples() {
		cube doubleTensor(2,3,2, fill::randu);
		fcube floatTensor(2,3,2);
		cx_cube complexDoubleTensor(2,3,2);
		cx_fcube complexFloatTensor(2,3,2);
		ucube unsignedIntegerTensor(2,3,2);
		icube signedIntegerTensor(2,3,2);
		return doubleTensor;
	}
}



#endif