# my_matrix+

Реализация библиотеки my_matrix_oop.h

В данном проекте реализован проект [**matrix**](https://github.com/stironni/Matrix) библиотека для работы с матрицами с использованием объектно-ориентированный подхода

- Программа разработана на языке C++ стандарта C++17 с использованием компилятора gcc
- Код программы находится в папке src
- Код придерживается Google Style
- Приватные поля `matrix_`, `rows_` и `cols_`
- Доступ к приватным полям `rows_` и `cols_` реализован через accessor и mutator. При увеличении размера - матрица дополняется нулевыми элементами, при уменьшении - лишнее просто отбрасывается
- Решение оформлено как статическая библиотека (с заголовочным файлом my_matrix_oop.h)
- Полное покрытие unit-тестами функций библиотеки c помощью библиотеки GTest
- Makefile для сборки библиотеки и тестов (с целями all, clean, test, my_matrix_oop.a)

## Операции над матрицами

Ниже представлено краткое описание операций над матрицами, которые реализованы в библиотеке.

| Операция                                | Описание                                                                    | Исключительные ситуации                                           |
| --------------------------------------- | --------------------------------------------------------------------------- | ----------------------------------------------------------------- |
| `bool EqMatrix(const MyMatrix& other)`  | Проверяет матрицы на равенство между собой                                  |                                                                   |
| `void SumMatrix(const MyMatrix& other)` | Прибавляет вторую матрицы к текущей                                         | различная размерность матриц                                      |
| `void SubMatrix(const MyMatrix& other)` | Вычитает из текущей матрицы другую                                          | различная размерность матриц                                      |
| `void MulNumber(const double num)`      | Умножает текущую матрицу на число                                           |                                                                   |
| `void MulMatrix(const MyMatrix& other)` | Умножает текущую матрицу на вторую                                          | число столбцов первой матрицы не равно числу строк второй матрицы |
| `MyMatrix Transpose()`                  | Создает новую транспонированную матрицу из текущей и возвращает ее          |                                                                   |
| `MyMatrix CalcComplements()`            | Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее | матрица не является квадратной                                    |
| `double Determinant()`                  | Вычисляет и возвращает определитель текущей матрицы                         | матрица не является квадратной                                    |
| `MyMatrix InverseMatrix()`              | Вычисляет и возвращает обратную матрицу                                     | определитель матрицы равен 0                                      |

Помимо реализации данных операций, реализованы конструкторы и деструкторы:

| Метод                             | Описание                                                                              |
| --------------------------------- | ------------------------------------------------------------------------------------- |
| `MyMatrix()`                      | Базовый конструктор, инициализирующий матрицу некоторой заранее заданной размерностью |
| `MyMatrix(int rows, int cols)`    | Параметризированный конструктор с количеством строк и столбцов                        |
| `MyMatrix(const MyMatrix& other)` | Конструктор копирования                                                               |
| `MyMatrix(MyMatrix&& other)`      | Конструктор переноса                                                                  |
| `~MyMatrix()`                     | Деструктор                                                                            |

Также перегружены следующие операторы, частично соответствующие операциям выше:

| Оператор         | Описание                                          | Исключительные ситуации                                           |
| ---------------- | ------------------------------------------------- | ----------------------------------------------------------------- |
| `+`              | Сложение двух матриц                              | различная размерность матриц                                      |
| `-`              | Вычитание одной матрицы из другой                 | различная размерность матриц                                      |
| `*`              | Умножение матриц и умножение матрицы на число     | число столбцов первой матрицы не равно числу строк второй матрицы |
| `==`             | Проверка на равенство матриц (`EqMatrix`)         |                                                                   |
| `=`              | Присвоение матрице значений другой матрицы        |                                                                   |
| `+=`             | Присвоение сложения (`SumMatrix`)                 | различная размерность матриц                                      |
| `-=`             | Присвоение разности (`SubMatrix`)                 | различная размерность матриц                                      |
| `*=`             | Присвоение умножения (`MulMatrix`/`MulNumber`)    | число столбцов первой матрицы не равно числу строк второй матрицы |
| `(int i, int j)` | Индексация по элементам матрицы (строка, колонка) | индекс за пределами матрицы                                       |
