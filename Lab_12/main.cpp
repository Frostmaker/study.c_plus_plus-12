/*
1. Функция ввода размера матрицы, размещение ее в динамической памяти и ввод элементов матрицы
2. Функция удаления матрицы, размещенной в динамической памяти
3. Функция вычисления отношения сумм элементов на главной и побочной диагоналях квадратной матрицы.
4. Добавить в матрицу столбец, содержащий минимальный положительный элемент в строке. 
	Если в строке нет положительных элементов, столбец должен содержать значение 0.
5. Удалить из матрицы строку и столбец, на пересечении которых стоит максимальный элемент матрицы. 
	Считать, что функция выполняется для одного из максимальных элементов, если их несколько.
6. Удалить из матрицы строки, удовлетворяющие условию, заданному  функцией-параметром. 
	Использовать в качестве параметра функции: строка состоит из одних нулей, в строке нет положительных элементов.
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
	//	cout << "Ошибка: деление на 0" << endl;
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
	system("pause");
	delete_matrix(m, rows, cols);


	//system("pause");
	return 0;
}