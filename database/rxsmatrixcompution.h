#ifndef RXSMATRIXCOMPUTION_H
#define RXSMATRIXCOMPUTION_H
#include "rxsmatrix.h"
#include "rxsconfig.h"
namespace matrix_compution
{
    MatrixComputionResult  GetDeterminant(const RxsMatrix&matrix, double& value);
    MatrixComputionResult  Multiplication(const RxsMatrix&matrix_left, const RxsMatrix& matrix_right, RxsMatrix& matrix_result);
}
#endif // RXSMATRIXCOMPUTION_H
