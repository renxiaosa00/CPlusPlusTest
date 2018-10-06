#include "rxsmatrixcompution.h"

MatrixComputionResult matrix_compution::GetDeterminant(const RxsMatrix &matrix, double &value)
{
    if ( !matrix.IsSquareMatrix() )
    {
        return IS_NOT_SQUARE_MATRIX;
    }
    QVector<double> vect_det;
    matrix.get_elements_value(vect_det);
    uint32_t n_size = matrix.get_row_size();
    value = 0.0;
    double element = 0.0;
    for (uint32_t i = 0; i < n_size; i++)
    {
        element = vect_det[i];
        for (uint32_t j = 1; j < n_size; j++)
        {
            uint32_t n_flag = i;
            double row_value_sum = 1.0;
            for (uint32_t k = 0; k < n_size; k++)
            {
                if (i == k)
                {
                    continue;
                }
                n_flag += k;
                uint32_t pos = j*n_size + k;
                row_value_sum *=vect_det[pos];
                if (row_value_sum == 0.0)
                {
                    break;
                }
            }

            if (n_flag % 2)
            {
                value -= element*row_value_sum;
            }
            else
            {
                value += element*row_value_sum;
            }
        }
    }
    return OK;
}
