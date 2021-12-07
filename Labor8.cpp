
/*Задані дійсні матриці С(nxm) та В(nxm).Одержати нові матриці Y(nxm) та Z(nxm) шляхом обміну місцями рядків,
що містять найбільше і найменше значення їх елементів. */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
using namespace std;
typedef int mat[10][10]; //новій тип для матриці
int n, m; //розмірність матриць за вибором користувача
void Matrix_Generate(mat); //рандомне генерування матриць
void Matrix_output(mat); //виведення матриць на екран
int max_sum(mat);  // пошук найбільшого рядка
int min_sum(mat);  //пошук найменшого рядка
void change(mat, mat, int, int, int, int); //заміна рядків
int main() {
	mat C, B; //матриці, що будуть використовуватися. Нові матриці будуть зроблені з цих двлх початкових
	cout << "Enter the size of Matrix(n m) : "; //введення розмірності
	cin >> n >> m;
	srand(time(NULL));
	int max_C, max_B, min_C, min_B; //мінімальні та максимальні рядки
	Matrix_Generate(C);
	Matrix_Generate(B);
	cout << "C(nxm):\n";
	Matrix_output(C);
	cout << "B(nxm):\n";
	Matrix_output(B);
	max_C = max_sum(C);
	max_B = max_sum(B);
	min_C = min_sum(C);
	min_B = min_sum(B);
	cout << "Max line in C is number " << max_C;
	cout << "\nMax line in B is number " << max_B;
	cout << "\nMin line in C is number " << min_C;
	cout << "\nMin line in B is number " << min_B;
	change(C, B, max_C, max_B, min_C, min_B);
	cout << "\nY(nxm), made from C with lines from B:\n";
	Matrix_output(C);
	cout << "\nZ(nxm), made from B with lines from C:\n";
	Matrix_output(B);

	return 0;
 }

void Matrix_Generate(mat matrix) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 10;
}
void Matrix_output(mat matrix) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cout << setw(4) << matrix[i][j];
			if (j == m - 1)
				cout << "\n";
		}
	cout << "\n";
}
int max_sum(mat matrix) {
	int max=0, Num=0;
	int S;
	for (int i = 0; i < n; i++) {
		S= 0;
		for (int j = 0; j < m; j++)
			S += matrix[i][j];
		if (S > max) {
			max = S;
			Num = i + 1;
		}
	}
	return Num;
}
int min_sum(mat matrix) {
	int min = 100, Num = 0;
	int S;
	for (int i = 0; i < n; i++) {
		S = 0;
		for (int j = 0; j < m; j++)
			S += matrix[i][j];
		if (S < min) {
			min = S;
			Num = i + 1;
		}
	}
	return Num;
}
void change(mat matrix1, mat matrix2, int max1, int max2, int min1, int min2) {
	int p;
	for (int j = 0; j < m; j++) {
		p = matrix1[max1 - 1][j];
		matrix1[max1 - 1][j]= matrix2[max2 - 1][j];
		matrix2[max2 - 1][j] = p;
	}
	for (int j = 0; j < m; j++) {
		p = matrix1[min1- 1][j];
		matrix1[min1 - 1][j] = matrix2[min2 - 1][j];
		matrix2[min2 - 1][j] = p;
	}
}