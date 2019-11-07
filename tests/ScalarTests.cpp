#include <iostream>
#include <string>

TEST(MatrixBasics, BasicScalar)
{
  TMatrix<int> m1(2,2), expectedMatrix(2, 2);

  m1.setValue(0,0, 2);
  m1.setValue(1,0, 2);
  m1.setValue(0,1, 2);
  m1.setValue(1,1, 2);

  expectedMatrix.setValue(0,0, 4);
  expectedMatrix.setValue(1,0, 4);
  expectedMatrix.setValue(0,1, 4);
  expectedMatrix.setValue(1,1, 4);

  ASSERT_TRUE(m1*2 == expectedMatrix);
}

TEST(MatrixBasics, FloatScalar)
{  
  TMatrix<int> m1(2,2), expectedMatrix(2, 2);

  m1.setValue(0,0, 2);
  m1.setValue(1,0, 2);
  m1.setValue(0,1, 2);
  m1.setValue(1,1, 2);

  expectedMatrix.setValue(0,0, 3);
  expectedMatrix.setValue(1,0, 3);
  expectedMatrix.setValue(0,1, 3);
  expectedMatrix.setValue(1,1, 3);

  ASSERT_TRUE(m1*1.5 == expectedMatrix);
}

TEST(MatrixBasics, Float2Scalar)
{  
  TMatrix<float> m1(2,2), expectedMatrix(2, 2);

  m1.setValue(0,0, 10);
  m1.setValue(1,0, 9);
  m1.setValue(0,1, 8);
  m1.setValue(1,1, 7);

  expectedMatrix.setValue(0,0, 5);
  expectedMatrix.setValue(1,0, 4.5);
  expectedMatrix.setValue(0,1, 4);
  expectedMatrix.setValue(1,1, 3.5);

  ASSERT_TRUE(m1*0.5 == expectedMatrix);
}
