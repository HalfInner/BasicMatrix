#include <vector>
#include <iostream>
#include <cstdint>


template <typename T>
class TMatrix
{
public:
  std::string printMatrix();

  void setValue(uint64_t, uint64_t, T);
  
  T getValue(uint64_t, uint64_t);
  
  void resize(uint64_t, uint64_t);

  //adding
  template <typename T2>
  TMatrix<T> addMatrix(const TMatrix<T2> &);
  
  template <typename T2>
  TMatrix<T> operator+(const TMatrix<T2> &);
      
  template <typename T2>
  TMatrix<T>& operator+=(const TMatrix<T2> &);
      
  //subtracting
  template <typename T2>
  TMatrix<T> subMatrix(const TMatrix<T2> &);
  
  template <typename T2>
  TMatrix<T> operator-(const TMatrix<T2> &);
      
  template <typename T2>
  TMatrix<T>& operator-=(const TMatrix<T2> &);
  
  //multiplication
  template <typename T2>
  TMatrix<T> mulMatrix(const TMatrix<T2> &);
  
  template <typename T2>
  TMatrix<T> operator*(const TMatrix<T2> &);
      
  template <typename T2>
  TMatrix<T>& operator*=(const TMatrix<T2> &);
  
  bool operator==(const TMatrix<T> &);    

  // ctr dst
  TMatrix(uint64_t, uint64_t);

  TMatrix();
  
  ~TMatrix() {};
  
  TMatrix(const TMatrix<T> &);
  
  TMatrix<T>& operator=(const TMatrix<T> &);
  
private:
  std::vector<T> dataMatrix;
  uint64_t col, row;  
};


/* put body to seperate file */
#include "TMatrix.cpp"
