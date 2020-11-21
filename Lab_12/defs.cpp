#include <iostream>
#include <cmath>

using namespace std;

void printMatrix(double**& m, size_t& rows, size_t& cols)
{
	// Функция печати матрицы в консоль

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << m[i][j] << '\t';
		}
		cout << "\n";
	}
	cout << '\n';
	return;
}


void read_new(double**& m, size_t& rows, size_t& cols)
{
	// Функция создания динамической матрицы

	cout << "Введите количество строк матрицы: ";
	cin >> rows;
	cout << "Введите количество столбцов матрицы: ";
	cin >> cols;
	m = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		m[i] = new double[cols];
	}
	cout << "Введите элементы: ";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> m[i][j];
		}
	}

	return;
}


void delete_matrix(double**& m, size_t rows, size_t cols)
{
	// Функция удаления динамической матрицы из памяти

	for (int i = 0; i < rows; ++i) {
		delete[] m[i];
	}

	delete[] m;
	cout << "Удаление прошло успешно!" << endl;
	return;
}


double sum(double**& m, size_t& rows, size_t& cols)
{
	// Функция вычисления отношения сумм элементов на главной и побочной диагоналях квадратной матрицы

	double s1 = 0, s2 = 0;
	for (int i = 0, j = 0; i < rows, j < cols; i++, j++) {
		s1 += m[i][j];
	}
	for (int i = 0, j = cols - 1; i < rows, j >= 0; i++, j--) {
		s2 += m[i][j];
	}

	if (s2 == 0) {
		throw 1;
	}

	return s1 / s2;
}


void newcolum(double**& m, size_t& rows, size_t& cols)
{
	// Функция добавляет в матрицу столбец, содержащий минимальный положительный элемент в строке. Если в строке нет положительных элементов, то добавляет 0

	double* a;
	a = new double[rows];
	double* b = new double[cols];
	double p = 0;
	for (int i = 0; i < rows; i++) {
		p = m[i][0];
		for (int j = 0; j < cols; j++) {
			b[j] = m[i][j];
			if ((m[i][j] < p)) {
				if (m[i][j] <= 0) {
					p = 0;
				}
				else {
					p = m[i][j];
				}
			}
		}
		a[i] = p;


		delete[] m[i];
		m[i] = new double[cols + 1];
		for (int ni{ 0 }; ni < cols; ni++) {
			m[i][ni] = b[ni];
		}

		m[i][cols] = a[i];
	}

	cols++;
	return;
}


void max_del(double**& m, size_t& rows, size_t& cols)
{
	// Функция удаляет из матрицы строку и столбец, на пересечении которых стоит максимальный элемент матрицы

	double max = 0;
	int k = 0, n = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (m[i][j] > max) {
				max = m[i][j];
				k = i;
				n = j;
			}
		}
	}
	for (int i = k + 1; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			m[i - 1][j] = m[i][j];
		}
	}
	for (int j = n + 1; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			m[i][j - 1] = m[i][j];
		}
	}

	return;
}


void print_func(bool (*f)(double*, size_t), double**& m, size_t& rows, size_t& cols)
{
	// Ф. удаляет из матрицы строки, удовлетворяющие условию, заданному функцией-параметром

	int k{ 0 };
	for (int i = 0; i < rows; i++) {
		if (f(m[i], cols)) {
			k++;
		}
		else {
			for (int j = 0; j < cols; j++) {
				m[i - k][j] = m[i][j];
			}
		}
	}

	for (int i = (rows - k); i < rows; i++) {
		delete[] m[i];
	}

	rows -= k;
	return;
}


bool check_row(double* row, size_t len)
{
	// Ф. проверяет: строка состоит из одних нулей, в строке нет положительных элементов

	bool only_zeros{ true }, no_positive{ true };
	for (int i{ 0 }; i < len; i++) {

		if (row[i] > 0.0) {
			no_positive = false;
		}
		if (row[i] != 0.0) {
			only_zeros = false;
		}

		if (no_positive | only_zeros) {
			return true;
		}
	}

	return false;
}