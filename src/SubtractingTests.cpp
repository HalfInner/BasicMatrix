#include <iostream>
#include <string>

TEST(MatrixBasics, BasicSubtracting)
{
  TMatrix<int> m1(5,2), m2(5, 2), expectedMatrix(5, 2);
  
  m1.setValue(0,0, 5);
  m2.setValue(0,0, 10);
  
  expectedMatrix.setValue(0, 0, -5);
  
  auto sumMatrix1And2 = m1.subMatrix(m2);
  
  ASSERT_TRUE(sumMatrix1And2 == expectedMatrix);
} 

TEST(MatrixBasics, SubtractingFromItself)
{
  TMatrix<int> m1(5,2), m2(5, 2), expectedMatrix(5, 2);
  
  m1.setValue(0,0, 5);
  m2.setValue(0,0, 10);
  
  expectedMatrix.setValue(0, 0, -5);
  
  m1 -= m2;
  
  ASSERT_TRUE(m1 == expectedMatrix);
} 

TEST(MatrixBasics, SubtractingManyMatrixes)
{
  TMatrix<int> m1(5,2), m2(5, 2), m3(5, 2), expectedMatrix(5, 2);
  
  m1.setValue(0,0, 5);
  m2.setValue(0,0, 10);
  m3.setValue(0,0, 15);
  
  expectedMatrix.setValue(0, 0, 25);
  
  //x = 5 - (5 - 10 - 15) = 5 - (-20) = 25
  m1 -= m1 - m2 - m3;
  
  ASSERT_TRUE(m1 == expectedMatrix);
} 

TEST(MatrixBasics, SubtractingDifferentSize)
{
  TMatrix<int> m1(5,2), m2(2, 5);
  
  try 
  {
    auto m3 = m1 - m2;
    FAIL() << "Subtract different sized matrixes is allowed";
  }
  catch (std::runtime_error e)
  {
    SUCCEED() << "Excpetion test passed";
  }  
} 
