#include <iostream>
#include <string>

TEST(MatrixBasics, BasicAdding)
{
  TMatrix<int> m1(5,2), m2(5, 2), expectedMatrix(5, 2);
  
  m1.setValue(0,0, 5);
  m2.setValue(0,0, 10);
  
  expectedMatrix.setValue(0, 0, 15);
  
  auto sumMatrix1And2 = m1.addMatrix(m2);
  
  ASSERT_TRUE(sumMatrix1And2 == expectedMatrix);
} 

TEST(MatrixBasics, AddingToItself)
{
  TMatrix<int> m1(5,2), m2(5, 2), expectedMatrix(5, 2);
  
  m1.setValue(0,0, 5);
  m2.setValue(0,0, 10);
  
  expectedMatrix.setValue(0, 0, 15);
  
  m1 += m2;
  
  ASSERT_TRUE(m1 == expectedMatrix);
} 

TEST(MatrixBasics, AddingManyMatrixes)
{
  TMatrix<int> m1(5,2), m2(5, 2), m3(5, 2), expectedMatrix(5, 2);
  
  m1.setValue(0,0, 5);
  m2.setValue(0,0, 10);
  m3.setValue(0,0, 15);
  
  expectedMatrix.setValue(0, 0, 35);
  
  m1 += m1 + m2 + m3;
  
  ASSERT_TRUE(m1 == expectedMatrix);
} 

TEST(MatrixBasics, AddingDifferentSize)
{
  TMatrix<int> m1(5,2), m2(2, 5);
  
  try 
  {
    auto m3 = m1 + m2;
    FAIL() << "Add different sized matrixes is allowed";
  }
  catch (std::runtime_error e)
  {
    SUCCEED() << "Excpetion test passed";
  }  
} 
