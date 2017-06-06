#include <vector>
#include <iostream>
#include <cstdint>

/*
  Template of vectors
*/
template <typename T>
class TMatrix
{
public:
  std::string printMatrix();

  void setValue(uint64_t, uint64_t, T);
  
  T getValue(uint64_t, uint64_t);
  
  void resize(uint64_t, uint64_t);

  TMatrix<T>& addMatrix(const TMatrix<T> &);

  TMatrix(uint64_t, uint64_t);

  TMatrix();
  
  TMatrix(const TMatrix<T> &);
  
  TMatrix<T>& operator=(const TMatrix<T> &);
  
  bool operator==(const TMatrix<T> &);
private:
  std::vector<T> dataMatrix;
  uint64_t col, row;
};

/* put body to seperate file */
#include "TMatrix.cpp"
