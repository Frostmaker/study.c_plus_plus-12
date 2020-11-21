/*
1. ������� ����� ������� �������, ���������� �� � ������������ ������ � ���� ��������� �������
2. ������� �������� �������, ����������� � ������������ ������
3. ������� ���������� ��������� ���� ��������� �� ������� � �������� ���������� ���������� �������.
4. �������� � ������� �������, ���������� ����������� ������������� ������� � ������. 
	���� � ������ ��� ������������� ���������, ������� ������ ��������� �������� 0.
5. ������� �� ������� ������ � �������, �� ����������� ������� ����� ������������ ������� �������. 
	�������, ��� ������� ����������� ��� ������ �� ������������ ���������, ���� �� ���������.
6. ������� �� ������� ������, ��������������� �������, ���������  ��������-����������. 
	������������ � �������� ��������� �������: ������ ������� �� ����� �����, � ������ ��� ������������� ���������.
*/

#include <iostream>
#include "defs.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	double** m = nullptr;
	size_t rows;
	size_t cols;

	// # 1
	read_new(m, rows, cols);

	// # 2
	delete_matrix(m, rows, cols);

	// # 3
	read_new(m, rows, cols);
	try {
		cout << sum(m, rows, cols) << endl;
	}
	catch (int a) {
		cout << "������: ������� �� 0" << endl;
	}
	delete_matrix(m, rows, cols);

	// # 4
	read_new(m, rows, cols);
	newcolum(m, rows, cols);
	delete_matrix(m, rows, cols);

	// # 5
	read_new(m, rows, cols);
	max_del(m, rows, cols);
	delete_matrix(m, rows, cols);

	// # 6
	read_new(m, rows, cols);
	printMatrix(m, rows, cols);
	print_func(check_row, m, rows, cols);
	printMatrix(m, rows, cols);
	delete_matrix(m, rows, cols);

	//system("pause");
	return 0;
}