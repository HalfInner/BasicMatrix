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
  TMatrix(uint64_t, uint64_t);
  
  TMatrix();
  
  /*
  template <typename T>
  TMatrix(const TMatrix &T)
  {
  
  }*/
  
  std::string printMatrix();
private:
  std::vector<T> dataMatrix;
  uint64_t col, row;
};


#include "TMatrix.cpp"
