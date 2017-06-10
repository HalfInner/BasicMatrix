#include <iostream>
#include <string>

TEST(MatrixBasics, BasicMultiplaying)
{
  TMatrix<int> m1(3,2), m2(2, 3), expectedMatrix(2, 2);
  
  m1.setValue(0, 0, 1);
  m1.setValue(1, 0, 0);
  m1.setValue(2, 0, 2);
  m1.setValue(0, 1, -1);
  m1.setValue(1, 1, 3);
  m1.setValue(2, 1, 1);
  
  m2.setValue(0, 0, 3);
  m2.setValue(1, 0, 1);
  m2.setValue(0, 1, 2);
  m2.setValue(1, 1, 1);
  m2.setValue(0, 2, 1);
  m2.setValue(1, 2, 0);
  
  expectedMatrix.setValue(0, 0, 5);
  expectedMatrix.setValue(1, 0, 1);
  expectedMatrix.setValue(0, 1, 4);
  expectedMatrix.setValue(1, 1, 2);

  auto sumMatrix1And2 = m1.mulMatrix(m2);

  ASSERT_TRUE(sumMatrix1And2 == expectedMatrix);
} 

TEST(MatrixBasics, MultiplicatinWithItself)
{
  TMatrix<int> m1(3,3), expectedMatrix(3, 3);
  
  m1.setValue(0, 0, 1);
  m1.setValue(1, 0, 0);
  m1.setValue(2, 0, 2);
  m1.setValue(0, 1, -1);
  m1.setValue(1, 1, 3);
  m1.setValue(2, 1, 3);
  m1.setValue(0, 2, -5);
  m1.setValue(1, 2, 23);
  m1.setValue(2, 2, -4);
  
  expectedMatrix.setValue(0, 0, -9);
  expectedMatrix.setValue(1, 0, 46);
  expectedMatrix.setValue(2, 0, -6);
  expectedMatrix.setValue(0, 1, -19);
  expectedMatrix.setValue(1, 1, 78);
  expectedMatrix.setValue(2, 1, -5);
  expectedMatrix.setValue(0, 2, -8);
  expectedMatrix.setValue(1, 2, -23);
  expectedMatrix.setValue(2, 2, 75);
  
  m1 *= m1;
  
  ASSERT_TRUE(m1 == expectedMatrix);
} 

TEST(MatrixBasics, MultiplayingManyMatrixes)
{
  TMatrix<int> m1(5,2), m2(5, 2), m3(5, 2), expectedMatrix(5, 2);
  
  m1.setValue(0,0, 5);
  m2.setValue(0,0, 10);
  m3.setValue(0,0, 15);
  
  expectedMatrix.setValue(0, 0, 25);
  
  m1 *= m1 * m2 * m3;
  
  ASSERT_TRUE(m1 == expectedMatrix);
} 

TEST(MatrixBasics, MultiplayingDifferentSize)
{
  TMatrix<int> m1(5,2), m2(2, 5);
  
  try 
  {
    auto m3 = m1 * m2;
    FAIL() << "Subtract different sized matrixes is allowed";
  }
  catch (std::runtime_error e)
  {
    SUCCEED() << "Excpetion test passed";
  }  
} 
