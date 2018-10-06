#include "rxsmatrixcompution.h"

MatrixComputionResult matrix_compution::GetDeterminant(const RxsMatrix &matrix, double &value)
{
   if ( !matrix.IsSquareMatrix() )
   {
       return IS_NOT_SQUARE_MATRIX;
   }

   return OK;
}
