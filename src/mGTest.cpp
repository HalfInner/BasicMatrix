#include <gtest/gtest.h>

#include "TMatrix.hpp"
#include "GeneralMatrixTests.cpp"
#include "AddingTests.cpp"
#include "SubtractingTests.cpp"
#include "MultiplayingTests.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
