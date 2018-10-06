/*
 * This is the base desc of matrix.
*/
#ifndef RXSMATRIX_H
#define RXSMATRIX_H
#include <QVector>
#include "rxstype.h"

class RxsMatrix
{
public:
    RxsMatrix();

    bool IsSquareMatrix() const
    {
        if (row_size_ == column_size_)
        {
            return true;
        }
        return false;
    }

    uint32_t get_row_size() const
    {
        return row_size_;
    }

    uint32_t get_column_size() const
    {
    return column_size_;
    }

    void get_elements_value(QVector<double>& elements_value) const
    {
        QVector<double> vect_temp(elements_value_);
        elements_value.swap(vect_temp);
    }
private:
    QVector<double> elements_value_;
    uint32_t row_size_;
    uint32_t column_size_;
};

#endif // RXSMATRIX_H
