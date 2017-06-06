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

