#include "rxsmatrix.h"

RxsMatrix::RxsMatrix()
{
    elements_value_.clear();
    row_size_ = 0;
    column_size_ = 0;
}

RxsMatrix::~RxsMatrix()
{
    elements_value_.clear();
    row_size_ = 0;
    column_size_ = 0;
}

RxsMatrix::RxsMatrix(const QVector<double> &elements_value, uint32_t row_size, uint32_t column_size)
{
    ResetMatrix(elements_value,row_size,column_size);
}

RxsMatrix::MatrixError RxsMatrix::ResetMatrix(const QVector<double> &elements_value, uint32_t row_size, uint32_t column_size)
{
    if (elements_value.size() != row_size*column_size)
    {
        return ERROR_SIZE;
    }
    QVector<double> vect_temp(elements_value);
    elements_value_.swap(vect_temp);
    row_size_ = row_size;
    column_size_ = row_size;

    return NO_ERROR;
}
