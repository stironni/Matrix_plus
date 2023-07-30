#ifndef MY_MATRIX_OOP_H_
#define MY_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

constexpr double EPS = 1e-7;

class MyMatrix {
  friend MyMatrix operator*(const double num, MyMatrix &matrix);
  friend MyMatrix operator*(MyMatrix &matrix, const double num);

 public:
  MyMatrix();
  MyMatrix(int rows, int cols);
  MyMatrix(const MyMatrix &other) noexcept;
  MyMatrix(MyMatrix &&other) noexcept;
  ~MyMatrix();

  MyMatrix operator+(const MyMatrix &other);
  MyMatrix operator-(const MyMatrix &other);
  MyMatrix operator*(const MyMatrix &other);

  bool operator==(const MyMatrix &other);

  MyMatrix &operator=(const MyMatrix &other);
  MyMatrix &operator=(MyMatrix &&other) noexcept;

  MyMatrix &operator+=(const MyMatrix &other);
  MyMatrix &operator-=(const MyMatrix &other);
  MyMatrix &operator*=(const MyMatrix &other);
  MyMatrix &operator*=(const double num);

  double &operator()(int row, int col);
  double operator()(int row, int col) const;

  int GetRows() const;
  int GetCols() const;

  void SetRows(int rows);
  void SetCols(int cols);

  bool EqMatrix(const MyMatrix &other);

  void SumMatrix(const MyMatrix &other);
  void SubMatrix(const MyMatrix &other);
  void MulMatrix(const MyMatrix &other);
  void MulNumber(const double num);

  MyMatrix Transpose();
  double Determinant();
  MyMatrix CalcComplements();
  MyMatrix InverseMatrix();

 private:
  int rows_{};
  int cols_{};
  double **matrix_{};

  void Create(int rows, int cols);
  void Copy(const MyMatrix &other);
  void Remove();
  MyMatrix Setters(int rows, int cols);
  MyMatrix MinorMatrix(int rows, int col);
};

#endif  // My_MATRIX_OOP_H_
