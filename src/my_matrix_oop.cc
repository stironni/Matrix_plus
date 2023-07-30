#include "my_matrix_oop.h"

MyMatrix::MyMatrix() = default;

MyMatrix::MyMatrix(int rows, int cols) { Create(rows, cols); }

void MyMatrix::Create(int rows, int cols) {
  if (rows < 0 || cols < 0)
    throw std::invalid_argument(
        "Invalid input, matrix size must be greater than zero");

  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

MyMatrix::MyMatrix(const MyMatrix &other) noexcept
    : rows_(other.rows_), cols_(other.cols_) {
  Create(rows_, cols_);
  Copy(other);
}

MyMatrix::MyMatrix(MyMatrix &&other)

    noexcept
    : rows_{0}, cols_{0}, matrix_{nullptr} {
  *this = std::move(other);
}

MyMatrix::~MyMatrix() {
  if (matrix_) Remove();
}

void MyMatrix::Remove() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
    matrix_[i] = nullptr;
  }
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

int MyMatrix::GetRows() const { return rows_; }

int MyMatrix::GetCols() const { return cols_; }

void MyMatrix::SetRows(int rows) {
  if (rows <= 0)
    throw std::invalid_argument(
        "Invalid input, matrix size must be greater than zero");

  *this = Setters(rows, cols_);
}

void MyMatrix::SetCols(int cols) {
  if (cols <= 0)
    throw std::invalid_argument(
        "Invalid input, matrix size must be greater than zero");

  *this = Setters(rows_, cols);
}

MyMatrix MyMatrix::Setters(int rows, int cols) {
  if (rows_ == rows && cols_ == cols) return *this;

  MyMatrix tmp(rows, cols);
  for (int i = 0; i < tmp.rows_; i++) {
    for (int j = 0; j < tmp.cols_; j++) {
      if (i >= rows_ || j >= cols_)
        continue;
      else
        tmp.matrix_[i][j] = matrix_[i][j];
    }
  }

  return tmp;
}

void MyMatrix::SumMatrix(const MyMatrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_)
    throw std::invalid_argument("Matrix: different matrix dimensions");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void MyMatrix::SubMatrix(const MyMatrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_)
    throw std::invalid_argument("Matrix: different matrix dimensions");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

bool MyMatrix::EqMatrix(const MyMatrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_) return false;

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS) return false;

  return true;
}

void MyMatrix::MulMatrix(const MyMatrix &other) {
  if (cols_ != other.rows_)
    throw std::invalid_argument(
        "the number of columns of the first matrix is not equal to the "
        "number of rows of the second matrix");

  MyMatrix result(rows_, other.cols_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = std::move(result);
}

void MyMatrix::MulNumber(const double num) {
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      matrix_[row][col] = matrix_[row][col] * num;
    }
  }
}

void MyMatrix::Copy(const MyMatrix &other) {
  for (int row = 0; row < other.rows_; row++) {
    for (int col = 0; col < other.cols_; col++) {
      matrix_[row][col] = other.matrix_[row][col];
    }
  }
}

MyMatrix MyMatrix::Transpose() {
  MyMatrix result(cols_, rows_);

  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }

  return result;
}

MyMatrix MyMatrix::MinorMatrix(int rows, int col) {
  MyMatrix result(rows_ - 1, cols_ - 1);
  for (int i = 0, minor_rows = 0; i < rows_; i++) {
    if (i == rows) continue;
    for (int j = 0, minor_cols = 0; j < cols_; j++) {
      if (j == col) continue;
      result.matrix_[minor_rows][minor_cols] = matrix_[i][j];
      minor_cols++;
    }
    minor_rows++;
  }
  return result;
}

double MyMatrix::Determinant() {
  if (rows_ != cols_)
    throw std::invalid_argument("Matrix: Sizes of matrices are not the same!");

  double result = 0;
  if (rows_ == 1) result = matrix_[0][0];

  if (rows_ == 2)
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];

  if (rows_ > 2) {
    double determinant = 0.0;
    for (int i = 0; i < cols_; i++) {
      MyMatrix minor = MinorMatrix(0, i);
      determinant = minor.Determinant();
      result += matrix_[0][i] * pow(-1, i) * determinant;
    }
  }

  return result;
}

MyMatrix MyMatrix::CalcComplements() {
  if (rows_ != cols_)
    throw std::invalid_argument("Matrix: the matrix is not square");

  MyMatrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      double determinant = 0.0;
      MyMatrix minor = MinorMatrix(i, j);
      determinant = minor.Determinant();
      determinant = determinant * pow(-1, i + j);
      result.matrix_[i][j] = determinant;
    }
  }

  return result;
}

MyMatrix MyMatrix::InverseMatrix() {
  if (cols_ != rows_)
    throw std::invalid_argument("Matrix: the matrix is not square");

  double det = Determinant();
  if (det == 0) throw std::invalid_argument("Matrix: Determinant equal zero");

  MyMatrix result(rows_, cols_);
  if (std::fabs(det - 0) >= pow(10, -7)) {
    MyMatrix calc = CalcComplements();
    result = calc.Transpose();
    result.MulNumber(1.0 / det);
  }

  return result;
}

///////////////////////////
///      Operators      ///
///////////////////////////

MyMatrix MyMatrix::operator+(const MyMatrix &other) {
  MyMatrix result(*this);
  result.SumMatrix(other);
  return result;
}

MyMatrix MyMatrix::operator-(const MyMatrix &other) {
  MyMatrix result(*this);
  result.SubMatrix(other);
  return result;
}

MyMatrix MyMatrix::operator*(const MyMatrix &other) {
  MyMatrix result(*this);
  result.MulMatrix(other);
  return result;
}

MyMatrix operator*(const double num, MyMatrix &matrix) {
  MyMatrix result(matrix);
  result.MulNumber(num);
  return result;
}

MyMatrix operator*(MyMatrix &matrix, const double num) {
  MyMatrix result(matrix);
  result.MulNumber(num);
  return result;
}

bool MyMatrix::operator==(const MyMatrix &other) { return EqMatrix(other); }

MyMatrix &MyMatrix::operator=(const MyMatrix &other) {
  if (this == &other) return *this;

  Remove();
  Create(other.rows_, other.cols_);
  Copy(other);

  return *this;
}

MyMatrix &MyMatrix::operator=(MyMatrix &&other)

    noexcept {
  if (*this == other) return *this;

  Remove();

  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);

  return *this;
}

MyMatrix &MyMatrix::operator+=(const MyMatrix &other) {
  SumMatrix(other);
  return *this;
}

MyMatrix &MyMatrix::operator-=(const MyMatrix &other) {
  SubMatrix(other);
  return *this;
}

MyMatrix &MyMatrix::operator*=(const MyMatrix &other) {
  MulMatrix(other);
  return *this;
}

MyMatrix &MyMatrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double &MyMatrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
    throw std::invalid_argument("Row or Col number out of size of matrix!");

  return matrix_[row][col];
}

double MyMatrix::operator()(int row, int col) const {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
    throw std::invalid_argument("Row or Col number out of size of matrix!");

  return matrix_[row][col];
}
