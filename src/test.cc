#include <gtest/gtest.h>

#include "my_matrix_oop.h"

using namespace std;

void Fill_2x3(MyMatrix &a) {
  a(0, 0) = 5;
  a(0, 1) = 4;
  a(0, 2) = 4;

  a(1, 0) = 8;
  a(1, 1) = 4;
  a(1, 2) = 1;
}

void Fill_3x2(MyMatrix &a) {
  a(0, 0) = 5;
  a(0, 1) = 4;

  a(1, 0) = 8;
  a(1, 1) = 4;

  a(2, 0) = 4;
  a(2, 1) = 4;
}

void Fill_3x3(MyMatrix &a) {
  a(0, 0) = 5;
  a(0, 1) = 4;
  a(0, 2) = 4;

  a(1, 0) = 8;
  a(1, 1) = 4;
  a(1, 2) = 1;

  a(2, 0) = 4;
  a(2, 1) = 4;
  a(2, 2) = 4;
}

void Fill_5x5(MyMatrix &a) {
  a(0, 0) = 5;
  a(0, 1) = 2;
  a(0, 2) = 7;
  a(0, 3) = 5;
  a(0, 4) = 2;

  a(1, 0) = 8;
  a(1, 1) = 1;
  a(1, 2) = 0;
  a(1, 3) = 9;
  a(1, 4) = 68;

  a(2, 0) = 8;
  a(2, 1) = 3;
  a(2, 2) = 12;
  a(2, 3) = 52;
  a(2, 4) = 17;

  a(3, 0) = 9;
  a(3, 1) = 32;
  a(3, 2) = 125;
  a(3, 3) = 5;
  a(3, 4) = 9;

  a(4, 0) = 7;
  a(4, 1) = 2;
  a(4, 2) = 25;
  a(4, 3) = 95;
  a(4, 4) = 96;
}

TEST(Test_Create, Default1214) {
  MyMatrix a(3, 3);
  ASSERT_TRUE(a.GetCols() == 3);
  ASSERT_TRUE(a.GetRows() == 3);
  Fill_3x3(a);
  ASSERT_TRUE(a(0, 0) == 5);
  ASSERT_TRUE(a(0, 1) == 4);
  ASSERT_TRUE(a(0, 2) == 4);
  ASSERT_TRUE(a(1, 0) == 8);
  ASSERT_TRUE(a(1, 1) == 4);
  ASSERT_TRUE(a(1, 2) == 1);
  ASSERT_TRUE(a(2, 0) == 4);
  ASSERT_TRUE(a(2, 1) == 4);
  ASSERT_TRUE(a(2, 2) == 4);
}

TEST(Test_Create, Default) {
  MyMatrix a(3, 3);
  Fill_3x3(a);
  MyMatrix b(std::move(a));
  ASSERT_TRUE(a.GetCols() == 0);
  ASSERT_TRUE(a.GetRows() == 0);
  ASSERT_TRUE(b.GetCols() == 3);
  ASSERT_TRUE(b.GetRows() == 3);
}

TEST(Test_Create, Matrix_2x3) {
  MyMatrix a(2, 3);
  ASSERT_TRUE(a.GetCols() == 3);
  ASSERT_TRUE(a.GetRows() == 2);
  Fill_2x3(a);
  ASSERT_TRUE(a(0, 0) == 5);
  ASSERT_TRUE(a(0, 1) == 4);
  ASSERT_TRUE(a(0, 2) == 4);
  ASSERT_TRUE(a(1, 0) == 8);
  ASSERT_TRUE(a(1, 1) == 4);
  ASSERT_TRUE(a(1, 2) == 1);
}

TEST(Test_Create, Matrix_3x2) {
  MyMatrix a(3, 2);
  ASSERT_TRUE(a.GetCols() == 2);
  ASSERT_TRUE(a.GetRows() == 3);
  Fill_3x2(a);
  ASSERT_TRUE(a(0, 0) == 5);
  ASSERT_TRUE(a(0, 1) == 4);
  ASSERT_TRUE(a(1, 0) == 8);
  ASSERT_TRUE(a(1, 1) == 4);
  ASSERT_TRUE(a(2, 0) == 4);
  ASSERT_TRUE(a(2, 1) == 4);
}

TEST(Test_GetRows_Cols, _1) {
  MyMatrix a(3, 3);
  ASSERT_TRUE(a.GetCols() == 3);
  ASSERT_TRUE(a.GetRows() == 3);
}

TEST(Test_GetRows_Cols, _2) {
  MyMatrix a(100, 4);
  ASSERT_TRUE(a.GetCols() == 4);
  ASSERT_TRUE(a.GetRows() == 100);
}

TEST(Test_SetRows, _2) {
  MyMatrix a;
  a.SetCols(3);
  a.SetRows(3);
  Fill_3x3(a);
  a.SetRows(2);
  ASSERT_TRUE(a(0, 0) == 5);
  ASSERT_TRUE(a(0, 1) == 4);
  ASSERT_TRUE(a(0, 2) == 4);
  ASSERT_TRUE(a(1, 0) == 8);
  ASSERT_TRUE(a(1, 1) == 4);
  ASSERT_TRUE(a(1, 2) == 1);
}

TEST(Test_SetRows, _4) {
  MyMatrix a(3, 3);
  Fill_3x3(a);
  a.SetRows(4);
  ASSERT_TRUE(a(0, 0) == 5);
  ASSERT_TRUE(a(0, 1) == 4);
  ASSERT_TRUE(a(0, 2) == 4);
  ASSERT_TRUE(a(1, 0) == 8);
  ASSERT_TRUE(a(1, 1) == 4);
  ASSERT_TRUE(a(1, 2) == 1);
  ASSERT_TRUE(a(2, 0) == 4);
  ASSERT_TRUE(a(2, 1) == 4);
  ASSERT_TRUE(a(2, 2) == 4);
  ASSERT_TRUE(a(3, 0) == 0);
  ASSERT_TRUE(a(3, 1) == 0);
  ASSERT_TRUE(a(3, 2) == 0);
}

TEST(Test_SetCols, _2) {
  MyMatrix a(3, 3);
  Fill_3x3(a);
  a.SetCols(2);
  ASSERT_TRUE(a(0, 0) == 5);
  ASSERT_TRUE(a(0, 1) == 4);
  ASSERT_TRUE(a(1, 0) == 8);
  ASSERT_TRUE(a(1, 1) == 4);
  ASSERT_TRUE(a(2, 0) == 4);
  ASSERT_TRUE(a(2, 1) == 4);
}

TEST(Test_SetCols, _3) {
  MyMatrix a(3, 3);
  Fill_3x3(a);
  a.SetCols(3);
  ASSERT_TRUE(a(0, 0) == 5);
  ASSERT_TRUE(a(0, 1) == 4);
  ASSERT_TRUE(a(0, 2) == 4);
  ASSERT_TRUE(a(1, 0) == 8);
  ASSERT_TRUE(a(1, 1) == 4);
  ASSERT_TRUE(a(1, 2) == 1);
  ASSERT_TRUE(a(2, 0) == 4);
  ASSERT_TRUE(a(2, 1) == 4);
  ASSERT_TRUE(a(2, 2) == 4);
}

TEST(Test_SetCols, _4) {
  MyMatrix a(1, 1);
  a.SetCols(3);
  a.SetRows(3);
  Fill_3x3(a);
  a.SetCols(4);
  ASSERT_TRUE(a(0, 0) == 5);
  ASSERT_TRUE(a(0, 1) == 4);
  ASSERT_TRUE(a(0, 2) == 4);
  ASSERT_TRUE(a(0, 3) == 0);
  ASSERT_TRUE(a(1, 0) == 8);
  ASSERT_TRUE(a(1, 1) == 4);
  ASSERT_TRUE(a(1, 2) == 1);
  ASSERT_TRUE(a(1, 3) == 0);
  ASSERT_TRUE(a(2, 0) == 4);
  ASSERT_TRUE(a(2, 1) == 4);
  ASSERT_TRUE(a(2, 2) == 4);
  ASSERT_TRUE(a(2, 3) == 0);
}

TEST(Test_EqMatrix, _3x3_3x3_) {
  MyMatrix a(3, 3), b(3, 3);
  Fill_3x3(a);
  Fill_3x3(b);
  ASSERT_TRUE(a.EqMatrix(b) == true);
}

TEST(Test_SumMatrix, A_and_A) {
  MyMatrix a(3, 3);
  Fill_3x3(a);
  a.SumMatrix(a);
  ASSERT_TRUE(a(0, 0) == 10);
  ASSERT_TRUE(a(0, 1) == 8);
  ASSERT_TRUE(a(0, 2) == 8);
  ASSERT_TRUE(a(1, 0) == 16);
  ASSERT_TRUE(a(1, 1) == 8);
  ASSERT_TRUE(a(1, 2) == 2);
  ASSERT_TRUE(a(2, 0) == 8);
  ASSERT_TRUE(a(2, 1) == 8);
  ASSERT_TRUE(a(2, 2) == 8);
}

TEST(Test_SubMatrix, A_and_A) {
  MyMatrix a(3, 3);
  Fill_3x3(a);
  a.SubMatrix(a);
  ASSERT_TRUE(a(0, 0) == 0);
  ASSERT_TRUE(a(0, 1) == 0);
  ASSERT_TRUE(a(0, 2) == 0);
  ASSERT_TRUE(a(1, 0) == 0);
  ASSERT_TRUE(a(1, 1) == 0);
  ASSERT_TRUE(a(1, 2) == 0);
  ASSERT_TRUE(a(2, 0) == 0);
  ASSERT_TRUE(a(2, 1) == 0);
  ASSERT_TRUE(a(2, 2) == 0);
}

TEST(Test_MulMatrix, _2x3_3x2_) {
  MyMatrix a(2, 3);
  MyMatrix b(3, 2);
  Fill_2x3(a);
  Fill_3x2(b);
  a.MulMatrix(b);
  ASSERT_TRUE(a(0, 0) == 73);
  ASSERT_TRUE(a(0, 1) == 52);
  ASSERT_TRUE(a(1, 0) == 76);
  ASSERT_TRUE(a(1, 1) == 52);
}

TEST(Test_MulMatrix, _3x2_2x3_) {
  MyMatrix a(3, 2);
  MyMatrix b(2, 3);
  Fill_3x2(a);
  Fill_2x3(b);
  a.MulMatrix(b);
  ASSERT_TRUE(a(0, 0) == 57);
  ASSERT_TRUE(a(0, 1) == 36);
  ASSERT_TRUE(a(0, 2) == 24);
  ASSERT_TRUE(a(1, 0) == 72);
  ASSERT_TRUE(a(1, 1) == 48);
  ASSERT_TRUE(a(1, 2) == 36);
  ASSERT_TRUE(a(2, 0) == 52);
  ASSERT_TRUE(a(2, 1) == 32);
  ASSERT_TRUE(a(2, 2) == 20);
}

TEST(Test_MulNumber, _3x3_10_) {
  MyMatrix a(3, 3);
  Fill_3x3(a);
  a.MulNumber(10);
  ASSERT_TRUE(a(0, 0) == 50);
  ASSERT_TRUE(a(0, 1) == 40);
  ASSERT_TRUE(a(0, 2) == 40);
  ASSERT_TRUE(a(1, 0) == 80);
  ASSERT_TRUE(a(1, 1) == 40);
  ASSERT_TRUE(a(1, 2) == 10);
  ASSERT_TRUE(a(2, 0) == 40);
  ASSERT_TRUE(a(2, 1) == 40);
  ASSERT_TRUE(a(2, 2) == 40);
}

TEST(Test_Transpose, _2x3_) {
  MyMatrix a(2, 3), b;
  Fill_2x3(a);
  b = a.Transpose();
  ASSERT_TRUE(b(0, 0) = 5);
  ASSERT_TRUE(b(0, 1) = 4);
  ASSERT_TRUE(b(1, 0) = 4);
  ASSERT_TRUE(b(1, 1) = 8);
  ASSERT_TRUE(b(2, 0) = 4);
  ASSERT_TRUE(b(2, 1) = 1);
}

TEST(Test_Transpose, _3x2_) {
  MyMatrix a(3, 2), b(2, 3);
  Fill_3x2(a);
  b = a.Transpose();
  ASSERT_TRUE(b(0, 0) = 5);
  ASSERT_TRUE(b(0, 1) = 4);
  ASSERT_TRUE(b(0, 2) = 8);
  ASSERT_TRUE(b(1, 0) = 4);
  ASSERT_TRUE(b(1, 1) = 4);
  ASSERT_TRUE(b(1, 2) = 4);
}

TEST(Test_CalComponents, _3x3_) {
  MyMatrix a(3, 3), b;
  Fill_3x3(a);
  b = a.CalcComplements();
  ASSERT_TRUE(b(0, 0) == 12);
  ASSERT_TRUE(b(0, 1) == -28);
  ASSERT_TRUE(b(0, 2) == 16);
  ASSERT_TRUE(b(1, 0) == 0);
  ASSERT_TRUE(b(1, 1) == 4);
  ASSERT_TRUE(b(1, 2) == -4);
  ASSERT_TRUE(b(2, 0) == -12);
  ASSERT_TRUE(b(2, 1) == 27);
  ASSERT_TRUE(b(2, 2) == -12);
}

TEST(Test_CalComponents, _5x5_) {
  MyMatrix a(5, 5), b(5, 5);
  Fill_5x5(a);
  b = a.CalcComplements();
  ASSERT_TRUE(b(0, 0) == -2214127);
  ASSERT_TRUE(b(0, 1) == 6099038);
  ASSERT_TRUE(b(0, 2) == -1422553);
  ASSERT_TRUE(b(0, 3) == 273026);
  ASSERT_TRUE(b(0, 4) == 134658);

  ASSERT_TRUE(b(1, 0) == 89984);
  ASSERT_TRUE(b(1, 1) == -1603296);
  ASSERT_TRUE(b(1, 2) == 410192);
  ASSERT_TRUE(b(1, 3) == 14992);
  ASSERT_TRUE(b(1, 4) == -94816);

  ASSERT_TRUE(b(2, 0) == 351272);
  ASSERT_TRUE(b(2, 1) == -3219968);
  ASSERT_TRUE(b(2, 2) == 804776);
  ASSERT_TRUE(b(2, 3) == -203136);
  ASSERT_TRUE(b(2, 4) == 32912);

  ASSERT_TRUE(b(3, 0) == 108262);
  ASSERT_TRUE(b(3, 1) == -354844);
  ASSERT_TRUE(b(3, 2) == 26010);
  ASSERT_TRUE(b(3, 3) == 284);
  ASSERT_TRUE(b(3, 4) == -7556);

  ASSERT_TRUE(b(4, 0) == -89965);
  ASSERT_TRUE(b(4, 1) == 1612074);
  ASSERT_TRUE(b(4, 2) == -405867);
  ASSERT_TRUE(b(4, 3) == 19638);
  ASSERT_TRUE(b(4, 4) == -15722);
}

TEST(Test_Determinant, 1) {
  MyMatrix a(3, 3);
  double det;
  Fill_3x3(a);
  det = a.Determinant();
  ASSERT_TRUE(det == 12);
}

TEST(Test_Determinant, 2) {
  MyMatrix a(5, 5);
  double det;
  Fill_5x5(a);
  det = a.Determinant();
  ASSERT_TRUE(det == -7195984);
}

TEST(Test_InverseMatrix, 1) {
  MyMatrix a(3, 3);
  MyMatrix b(3, 3);
  Fill_3x3(a);
  b = a.InverseMatrix();
  ASSERT_DOUBLE_EQ(round(b(0, 0) * 100000) / 100000, 1);
  ASSERT_DOUBLE_EQ(round(b(0, 1) * 100000) / 100000, 0);
  ASSERT_DOUBLE_EQ(round(b(0, 2) * 100000) / 100000, -1);
  ASSERT_DOUBLE_EQ(round(b(1, 0) * 100000) / 100000, -2.33333);
  ASSERT_DOUBLE_EQ(round(b(1, 1) * 100000) / 100000, 0.33333);
  ASSERT_DOUBLE_EQ(round(b(1, 2) * 100000) / 100000, 2.25);
  ASSERT_DOUBLE_EQ(round(b(2, 0) * 100000) / 100000, 1.33333);
  ASSERT_DOUBLE_EQ(round(b(2, 1) * 100000) / 100000, -0.33333);
  ASSERT_DOUBLE_EQ(round(b(2, 2) * 100000) / 100000, -1);
}

///////////////////////////
///      Operators      ///
///////////////////////////

// Addition of two matrices
TEST(Test_operators, Addition_of_two_matrices) {
  MyMatrix a(3, 3), b(3, 3), c;
  Fill_3x3(a);
  Fill_3x3(b);
  c = a + b;
  ASSERT_TRUE(c(0, 0) == 10);
  ASSERT_TRUE(c(0, 1) == 8);
  ASSERT_TRUE(c(0, 2) == 8);
  ASSERT_TRUE(c(1, 0) == 16);
  ASSERT_TRUE(c(1, 1) == 8);
  ASSERT_TRUE(c(1, 2) == 2);
  ASSERT_TRUE(c(2, 0) == 8);
  ASSERT_TRUE(c(2, 1) == 8);
  ASSERT_TRUE(c(2, 2) == 8);
}

// Subtraction of one matrix from another
TEST(Test_operators, Subtraction_of_one_matrix_from_another) {
  MyMatrix a(3, 3), b(3, 3), c;
  Fill_3x3(a);
  Fill_3x3(b);
  c = a - b;
  ASSERT_TRUE(c(0, 0) == 0);
  ASSERT_TRUE(c(0, 1) == 0);
  ASSERT_TRUE(c(0, 2) == 0);
  ASSERT_TRUE(c(1, 0) == 0);
  ASSERT_TRUE(c(1, 1) == 0);
  ASSERT_TRUE(c(1, 2) == 0);
  ASSERT_TRUE(c(2, 0) == 0);
  ASSERT_TRUE(c(2, 1) == 0);
  ASSERT_TRUE(c(2, 2) == 0);
}

// Matrix multiplication and matrix multiplication by a number

TEST(Test_operators, MulMatrix) {
  MyMatrix a(2, 3);
  MyMatrix b(3, 2);
  MyMatrix c(2, 2);
  Fill_2x3(a);
  Fill_3x2(b);
  c = a * b;
  ASSERT_TRUE(c(0, 0) == 73);
  ASSERT_TRUE(c(0, 1) == 52);
  ASSERT_TRUE(c(1, 0) == 76);
  ASSERT_TRUE(c(1, 1) == 52);
}

TEST(Test_operators, MulNumber) {
  MyMatrix a(3, 3), c;
  Fill_3x3(a);
  c = a * 10.0;
  ASSERT_TRUE(c(0, 0) == 50);
  ASSERT_TRUE(c(0, 1) == 40);
  ASSERT_TRUE(c(0, 2) == 40);
  ASSERT_TRUE(c(1, 0) == 80);
  ASSERT_TRUE(c(1, 1) == 40);
  ASSERT_TRUE(c(1, 2) == 10);
  ASSERT_TRUE(c(2, 0) == 40);
  ASSERT_TRUE(c(2, 1) == 40);
  ASSERT_TRUE(c(2, 2) == 40);
}

TEST(Test_operators, MulNumberReverse) {
  MyMatrix a(3, 3), c;
  Fill_3x3(a);
  c = 10.0 * a;
  ASSERT_TRUE(c(0, 0) == 50);
  ASSERT_TRUE(c(0, 1) == 40);
  ASSERT_TRUE(c(0, 2) == 40);
  ASSERT_TRUE(c(1, 0) == 80);
  ASSERT_TRUE(c(1, 1) == 40);
  ASSERT_TRUE(c(1, 2) == 10);
  ASSERT_TRUE(c(2, 0) == 40);
  ASSERT_TRUE(c(2, 1) == 40);
  ASSERT_TRUE(c(2, 2) == 40);
}

// Checks for matrices equality (EqMatrix)
TEST(Test_operators, Checks_for_matrices_equality) {
  MyMatrix a(3, 3), b(3, 3);
  Fill_3x3(a);
  int res;
  res = (a == b);
  ASSERT_FALSE(1 == res);
  Fill_3x3(b);
  res = (a == b);
  ASSERT_TRUE(1 == res);
}

// Assignment of values from one matrix to another one
TEST(Test_operators, Assignment) {
  MyMatrix a(3, 3), b;
  Fill_3x3(a);
  b = a;
  ASSERT_TRUE(a == b);
}

TEST(Test_operators, Assignment2) {
  MyMatrix a(3, 3), b;
  Fill_3x3(a);
  b = a;
  ASSERT_TRUE(a == b);
}

TEST(Test_operators, Assignment3) {
  MyMatrix a(3, 3), b;
  Fill_3x3(a);
  b = std::move(a);
  ASSERT_TRUE(b.GetCols() == 3);
}

// Addition assignment (SumMatrix)
TEST(Test_operators, Addition_assignment_SumMatrix) {
  MyMatrix a(3, 3), b(3, 3);
  Fill_3x3(a);
  Fill_3x3(b);
  a += b;
  ASSERT_TRUE(a(0, 0) == 10);
  ASSERT_TRUE(a(0, 1) == 8);
  ASSERT_TRUE(a(0, 2) == 8);
  ASSERT_TRUE(a(1, 0) == 16);
  ASSERT_TRUE(a(1, 1) == 8);
  ASSERT_TRUE(a(1, 2) == 2);
  ASSERT_TRUE(a(2, 0) == 8);
  ASSERT_TRUE(a(2, 1) == 8);
  ASSERT_TRUE(a(2, 2) == 8);
}

// Difference assignment (SubMatrix)
TEST(Test_operators, Difference_assignment_SubMatrix) {
  MyMatrix c(3, 3), b(3, 3);
  Fill_3x3(c);
  Fill_3x3(b);
  c -= b;
  ASSERT_TRUE(c(0, 0) == 0);
  ASSERT_TRUE(c(0, 1) == 0);
  ASSERT_TRUE(c(0, 2) == 0);
  ASSERT_TRUE(c(1, 0) == 0);
  ASSERT_TRUE(c(1, 1) == 0);
  ASSERT_TRUE(c(1, 2) == 0);
  ASSERT_TRUE(c(2, 0) == 0);
  ASSERT_TRUE(c(2, 1) == 0);
  ASSERT_TRUE(c(2, 2) == 0);
}

TEST(Test_operators, Multiplication_assignment_MulMatrix) {
  MyMatrix a(2, 3);
  MyMatrix b(3, 2);
  Fill_2x3(a);
  Fill_3x2(b);
  a *= b;
  ASSERT_TRUE(a(0, 0) == 73);
  ASSERT_TRUE(a(0, 1) == 52);
  ASSERT_TRUE(a(1, 0) == 76);
  ASSERT_TRUE(a(1, 1) == 52);
}

TEST(Test_operators, Multiplication_assignment_MulNumber) {
  MyMatrix c(3, 3);
  Fill_3x3(c);
  c *= 10;
  ASSERT_TRUE(c(0, 0) == 50);
  ASSERT_TRUE(c(0, 1) == 40);
  ASSERT_TRUE(c(0, 2) == 40);
  ASSERT_TRUE(c(1, 0) == 80);
  ASSERT_TRUE(c(1, 1) == 40);
  ASSERT_TRUE(c(1, 2) == 10);
  ASSERT_TRUE(c(2, 0) == 40);
  ASSERT_TRUE(c(2, 1) == 40);
  ASSERT_TRUE(c(2, 2) == 40);
}

TEST(Test_operators, Index_Operators_Const) {
  const MyMatrix c(1, 1);
  ASSERT_TRUE(c.operator()(0, 0) == 0);
}

// TEST(Test_Create, Matrix_0x2) {
//   ASSERT_THROW(MyMatrix a(0, 2), std::invalid_argument);
// }
//
// TEST(Test_SumMatrix, A_NO_Eg_A) {
//   MyMatrix a(3, 2), b(2, 4);
//   Fill_3x2(a);
//   Fill_2x3(b);
//   ASSERT_THROW(a.SumMatrix(b), std::invalid_argument);
// }
//
// TEST(Test_SubMatrix, A_NO_Eg_A) {
//   MyMatrix a(3, 2), b(2, 4);
//   Fill_3x2(a);
//   Fill_2x3(b);
//   ASSERT_THROW(a.SubMatrix(b), std::invalid_argument);
// }
//
// TEST(Test_MulMatrix, No_Eq) {
//   MyMatrix a(3, 3);
//   MyMatrix b(2, 3);
//   Fill_3x3(a);
//   Fill_2x3(b);
//   ASSERT_THROW(a.MulMatrix(b), std::invalid_argument);
// }
//
// TEST(Test_CalComponents, 3) {
//   MyMatrix a(2, 3);
//   Fill_2x3(a);
//   ASSERT_THROW(a.CalcComplements(), std::invalid_argument);
// }
// TEST(Test_Determinant, 3) {
//   MyMatrix a(3, 2);
//   Fill_3x2(a);
//   ASSERT_THROW(a.Determinant(), std::invalid_argument);
// }
//
// TEST(Test_operators, invalid_index) {
//   MyMatrix a(3, 3);
//   Fill_3x3(a);
//   ASSERT_THROW(a.operator()(4, 4) = 4, std::invalid_argument);
// }
//
// TEST(Test_operators, invalid_index_const) {
//   const MyMatrix a;
//   ASSERT_THROW(a.operator()(4, 4), std::invalid_argument);
// }
//
// TEST(Test_InverseMatrix, 2) {
//   MyMatrix a(3, 2);
//   ASSERT_THROW(a.InverseMatrix(), std::invalid_argument);
// }
//
// TEST(Test_SetRows, _0) {
//   MyMatrix a(1, 1);
//   ASSERT_THROW(a.SetRows(0);, std::invalid_argument);
// }
//
// TEST(Test_SetCols, _0) {
//   MyMatrix a(1, 1);
//   ASSERT_THROW(a.SetCols(0);, std::invalid_argument);
// }
//
// TEST(Test_SetRows, _minus) {
//   MyMatrix a;
//   ASSERT_THROW(a.SetRows(-4);, std::invalid_argument);
// }
//
// TEST(Test_SetCols, _minus) {
//   MyMatrix a;
//   ASSERT_THROW(a.SetCols(-9);, std::invalid_argument);
// }
//
// TEST(Test_InverseMatrix, 3) {
//   MyMatrix a;
//   ASSERT_THROW(a.InverseMatrix(), std::invalid_argument);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
