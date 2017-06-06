#include <iostream>
#include <string>
#include "TMatrix.hpp"

TEST(MatrixBasics, Printing)
{
  TMatrix<int> matrix(5,2);
  
  std::string expectedOut = 
    "0 0 0 0 0 \n"
    "0 0 0 0 0 \n";
  
  ASSERT_STREQ(expectedOut.c_str(), matrix.printMatrix().c_str());
} 

TEST(MatrixBasics, Resizing)
{
  TMatrix<int> m1(5,2), m2(2, 5);
  
  ASSERT_FALSE(m1 == m2);
  
  m2.resize(5, 2);
  
  ASSERT_TRUE(m1 == m2);
} 

TEST(MatrixBasics, Shits)
{  
  TMatrix<int> matrix(5,2);
  
  matrix.setValue(1, 1, 42);
  
  matrix.resize(2, 4);
  
  std::cout << matrix.printMatrix(); 
}
