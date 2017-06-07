#pragma once
#include <sstream>
#include <memory>
#include <algorithm>

template <typename T>
TMatrix<T>::TMatrix(uint64_t columns, uint64_t rows)
  : col(columns), row(rows)
{
  dataMatrix.assign(col * row, 0);
}
  
template <typename T>
TMatrix<T>::TMatrix()
  : TMatrix(0, 0)
{}

template <typename T>
std::string TMatrix<T>::printMatrix()
{
  std::stringstream buf;
  
  size_t i = 0;
  for (auto const &x : dataMatrix)
  {
    buf << x << " ";
    if (++i % col == 0)
      buf << std::endl;
  }
  
  return buf.str();
}

template <typename T>
bool TMatrix<T>::operator==(const TMatrix<T> &tm)
{
  return col == tm.col && 
         row == tm.row && 
         std::equal(dataMatrix.begin(), dataMatrix.end(), tm.dataMatrix.begin());
}

template <typename T>
void TMatrix<T>::resize(uint64_t columns, uint64_t rows)
{
  col = columns;
  row = rows;
  dataMatrix.resize(col * row);
}

template <typename T>
void TMatrix<T>::setValue(uint64_t i, uint64_t j, T t)
{
  if (i >= col || j >= row)
    throw std::out_of_range("TMatrix::out_of_range");
    
  dataMatrix[i + j * col] = t;
}

template <typename T>
T TMatrix<T>::getValue(uint64_t i, uint64_t j)
{
  if (i >= col || j >= row)
    throw std::out_of_range("TMatrix::out_of_range");

  return dataMatrix[i + j * col];
}

template <typename T>
TMatrix<T>::TMatrix(const TMatrix<T> &tm)
{
  dataMatrix = tm.dataMatrix;
}

template <typename T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &tm)
{
  dataMatrix = tm.dataMatrix;
  return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, TMatrix<T>& tm)
{
    os << tm.printMatrix();
    return os;
}

//adding
template <typename T> template <typename T2>
TMatrix<T> TMatrix<T>::addMatrix(TMatrix<T2> &tm)
{
  if (col != tm.col || row != tm.row)
    throw std::runtime_error("TMatrix::adding different sizes of matrix");
  
  TMatrix<T> resultMatrix(col, row);
  
  std::transform (
    dataMatrix.begin(), 
    dataMatrix.end(), 
    tm.dataMatrix.begin(), 
    resultMatrix.dataMatrix.begin(), 
    [](int a, int b) { return a + b; });
  
  return resultMatrix;
}

template <typename T> template <typename T2>
TMatrix<T> TMatrix<T>::operator+(TMatrix<T2> &tm)
{
  return addMatrix(tm);
}

template <typename T> template <typename T2>
TMatrix<T>& TMatrix<T>::operator+=(TMatrix<T2> &tm)
{
  *this = this->addMatrix(tm);
  return *this;
}

//subtracting

template <typename T> template <typename T2>
TMatrix<T> TMatrix<T>::subMatrix(TMatrix<T2> &tm)
{
  if (col != tm.col || row != tm.row)
    throw std::runtime_error("TMatrix::adding different sizes of matrix");
  
  TMatrix<T> resultMatrix(col, row);
  
  std::transform (
    dataMatrix.begin(), 
    dataMatrix.end(), 
    tm.dataMatrix.begin(), 
    resultMatrix.dataMatrix.begin(), 
    [](int a, int b) { return a - b; });
  
  return resultMatrix;
}

template <typename T> template <typename T2>
TMatrix<T> TMatrix<T>::operator-(TMatrix<T2> &tm)
{
  return subMatrix(tm);
}

template <typename T> template <typename T2>
TMatrix<T>& TMatrix<T>::operator-=(TMatrix<T2> &tm)
{
  *this = this->addMatrix(tm);
  return *this;
}











