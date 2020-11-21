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

	//read_new(m, rows, cols);
	//delete_matrix(m, rows, cols);
	//read_new(m, rows, cols);
	//try {
	//	cout << sum(m, rows, cols) << endl;
	//}
	//catch (int a) {
	//	cout << "������: ������� �� 0" << endl;
	//}
	//delete_matrix(m, rows, cols);
	//read_new(m, rows, cols);
	//newcolum(m, rows, cols);
	//delete_matrix(m, rows, cols);
	//read_new(m, rows, cols);
	//max_del(m, rows, cols);
	//delete_matrix(m, rows, cols);
	read_new(m, rows, cols);
	printMatrix(m, rows, cols);
	print_func(check_row, m, rows, cols);
	printMatrix(m, rows, cols);
	//system("pause");
	delete_matrix(m, rows, cols);


	//system("pause");
	return 0;
}