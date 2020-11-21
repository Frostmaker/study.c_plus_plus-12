#include <iostream>
#include <cmath>

using namespace std;

void printMatrix(double**& m, size_t& rows, size_t& cols)
{
	// ������� ������ ������� � �������

	if (m == nullptr) {
		throw - 2;
	}

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
	// ������� �������� ������������ �������

	if (m != nullptr) {
		throw - 1;
	}

	cout << "������� ���������� ����� �������: ";
	cin >> rows;
	cout << "������� ���������� �������� �������: ";
	cin >> cols;
	m = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		m[i] = new double[cols];
	}
	cout << "������� ��������: ";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> m[i][j];
		}
	}

	return;
}


void delete_matrix(double**& m, size_t& rows, size_t& cols)
{
	// ������� �������� ������������ ������� �� ������

	if (m == nullptr) {
		throw - 2;
	}

	for (int i = 0; i < rows; ++i) {
		delete[] m[i];
	}

	delete[] m;
	m = nullptr;
	rows = 0;
	cols = 0;
	cout << "�������� ������ �������!" << endl;
	return;
}


double sum(double**& m, size_t& rows, size_t& cols)
{
	// ������� ���������� ��������� ���� ��������� �� ������� � �������� ���������� ���������� �������

	if (m == nullptr) {
		throw - 2;
	}

	if (rows != cols) {
		throw - 3;
	}

	double s1 = 0, s2 = 0;
	for (int i = 0, j = 0; i < rows, j < cols; i++, j++) {
		s1 += m[i][j];
	}
	for (int i = 0, j = cols - 1; i < rows, j >= 0; i++, j--) {
		s2 += m[i][j];
	}

	if (s2 == 0) {
		throw - 4;
	}

	cout << "�����: ";
	return s1 / s2;
}


void newcolum(double**& m, size_t& rows, size_t& cols)
{
	// ������� ��������� � ������� �������, ���������� ����������� ������������� ������� � ������. ���� � ������ ��� ������������� ���������, �� ��������� 0

	if (m == nullptr) {
		throw - 2;
	}

	double* a;
	a = new double[rows];
	double* b = new double[cols];
	double p;
	for (int i = 0; i < rows; i++) {
		p = DBL_MAX;
		for (int j = 0; j < cols; j++) {
			b[j] = m[i][j];
			if (m[i][j] < p) {
				if (m[i][j] > 0) {
					p = m[i][j];;
				}
			}
		}
		if (p == DBL_MAX)
			a[i] = 0;
		else
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
	// ������� ������� �� ������� ������ � �������, �� ����������� ������� ����� ������������ ������� �������

	if (m == nullptr) {
		throw - 2;
	}

	double max = DBL_MIN;
	int k, n;
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
	delete[] m[rows - 1];
	rows--;

	double* b;
	for (int i = 0; i < rows; i++) {
		b = new double[cols - 1];
		for (int j = 0; j < n; j++) {
			b[j] = m[i][j];
		}
		for (int j = n + 1; j < cols; j++) {
			b[j - 1] = m[i][j];
		}

		delete[] m[i];
		m[i] = new double[cols - 1];
		for (int j = 0; j < cols - 1; j++)
			m[i][j] = b[j];
		delete[] b;
	}
	cols--;
	return;
}


void print_func(bool (*f)(double*, size_t), double**& m, size_t& rows, size_t& cols)
{
	// �. ������� �� ������� ������, ��������������� �������, ��������� ��������-����������

	if (m == nullptr) {
		throw - 2;
	}

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
	// �. ���������: ������ ������� �� ����� �����, � ������ ��� ������������� ���������

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