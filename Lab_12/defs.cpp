#include <iostream>
#include <cmath>

using namespace std;

void printMatrix(double**& m, size_t& rows, size_t& cols)
{
	// ������� ������ ������� � �������

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


void delete_matrix(double**& m, size_t rows, size_t cols)
{
	// ������� �������� ������������ ������� �� ������

	for (int i = 0; i < rows; ++i) {
		delete[] m[i];
	}

	delete[] m;
	cout << "�������� ������ �������!" << endl;
	return;
}


double sum(double**& m, size_t& rows, size_t& cols)
{
	// ������� ���������� ��������� ���� ��������� �� ������� � �������� ���������� ���������� �������

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
	// ������� ��������� � ������� �������, ���������� ����������� ������������� ������� � ������. ���� � ������ ��� ������������� ���������, �� ��������� 0

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
	// ������� ������� �� ������� ������ � �������, �� ����������� ������� ����� ������������ ������� �������

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
	// �. ������� �� ������� ������, ��������������� �������, ��������� ��������-����������

	int k{ 0 };
	for (int i = rows - 1; i >= 0; i--) {
		if (f(m[i], cols)) {
			delete[] m[i];
			k++;
		}
	}
	rows -= k;
	return;
}


bool check_row(double* row, size_t len)
{
	// �. ���������: ������ ������� �� ����� �����, � ������ ��� ������������� ���������

	bool checkpoint{ true };
	for (int i{ 0 }; i < len; i++) {
		if (row[i] != 0.0 || row[i] > 0) {
			checkpoint = false;
			break;
		}
	}

	return checkpoint;
}