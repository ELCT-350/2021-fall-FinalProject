#pragma once
#include "Exceptions/NotImplementedException.h"
#include "Vector.h"

namespace ELCT350
{
  namespace Math
  {
    template<typename T>
    class Matrix final
    {
    public:
      #pragma region Constructors and Destructors
      Matrix(size_t numRows, size_t numColumns, const T& initialValue = T{})
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix(const Matrix<T>& original)
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix(Matrix<T>&& old)
      {
        throw Common::Exceptions::NotImplementedException();
      }

      ~Matrix()
      {
        throw Common::Exceptions::NotImplementedException();
      }
      #pragma endregion

      #pragma region Observers
      size_t getNumberOfRows() const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      size_t getNumberOfColumns() const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Vector<T> getRow(size_t rowIndex) const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Vector<T> getColumn(size_t columnIndex) const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T> computeInverse() const
      {
        auto rows = getNumberOfRows();
        if (rows != getNumberOfColumns())
          throw std::logic_error("Must be a square matrix");

        auto tmpColumns = 2 * rows;
        Matrix<T> tmp(rows, tmpColumns);
        for (size_t row = 0; row < rows; ++row)
        {
          for (size_t column = 0; column < rows; ++column)
            tmp(row, column) = (*this)(row, column);
          tmp(row, row + rows) = 1;
        }

        auto pivot = [&tmp, &rows, &tmpColumns]()
        {
          for (size_t row = 0, lead = 0; row < rows && lead < tmpColumns; ++row, ++lead)
          {
            size_t i = row;
            while (tmp(i, lead) == T{})
            {
              if (++i == rows)
              {
                i = row;
                if (++lead == tmpColumns)
                  return;
              }
            }

            for (size_t column = 0; column < tmpColumns; ++column)
              std::swap(tmp(i, column), tmp(row, column));

            if (tmp(row, lead) != T{})
            {
              T f = tmp(row, lead);
              for (size_t column = 0; column < tmpColumns; ++column)
                tmp(row, column) /= f;
            }

            for (size_t j = 0; j < rows; ++j)
            {
              if (j == row)
                continue;
              T f = tmp(j, lead);
              for (size_t column = 0; column < tmpColumns; ++column)
                tmp(j, column) -= f * tmp(row, column);
            }
          }
        };

        pivot();
        Matrix<T> inv(rows, rows);
        for (size_t row = 0; row < rows; ++row)
        {
          for (size_t column = 0; column < rows; ++column)
            inv(row, column) = tmp(row, column + rows);
        }
        return inv;
      }
      #pragma endregion

      #pragma region Operators
      #pragma region Observers
      const T& operator()(size_t row, size_t column) const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T> operator-() const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T> operator+(const Matrix<T>& rhs) const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T> operator-(const Matrix<T>& rhs) const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T> operator*(const Matrix<T>& rhs) const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Vector<T> operator*(const Vector<T>& rhs) const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T> operator*(const T& scalar) const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T> operator/(const T& scalar) const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      bool operator==(const Matrix<T>& rhs) const
      {
        throw Common::Exceptions::NotImplementedException();
      }

      bool operator!=(const Matrix<T>& rhs) const
      {
        throw Common::Exceptions::NotImplementedException();
      }
      #pragma endregion

      #pragma region Modifiers
      T& operator()(size_t row, size_t column)
      {
        return const_cast<T&>(const_cast<const Matrix<T>*>(this)->operator()(row, column));
      }

      Matrix<T>& operator+=(const Matrix<T>& rhs)
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T>& operator-=(const Matrix<T>& rhs)
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T>& operator*=(const T& scalar)
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T>& operator/=(const T& scalar)
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T>& operator=(const Matrix<T>& rhs)
      {
        throw Common::Exceptions::NotImplementedException();
      }

      Matrix<T>& operator=(Matrix<T>&& rhs)
      {
        throw Common::Exceptions::NotImplementedException();
      }
      #pragma endregion
      #pragma endregion
    };

    #pragma region Operators
    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const Matrix<T>& matrix)
    {
      throw Common::Exceptions::NotImplementedException();
    }
    #pragma endregion
  }
}