#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int** fromFile(size_t m, size_t n)
{
	ifstream in("data.txt");
	in.seekg(3);

	int** matrix = new int* [m];
	for (size_t i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
		for (size_t j = 0; j < n; j++)
			in >> matrix[i][j];
	}

	in.close();
	return matrix;
}

void Calculate(int** matrix, int* vecS, size_t m, size_t n)
{
	for (size_t i = 0; i < m; ++i) {
		vecS[i] = 0;
		for (size_t j = 0; j < n; ++j) {
			vecS[i] += matrix[i][j];
		}
	}
}

/*
void Show(int** matrix, size_t m, size_t n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
*/

int main()
{
	ifstream file("data.txt");
	size_t M;
	size_t N;
	file >> M;
	file >> N;
	int** Mat = fromFile(M, N);
	int* Sum = new int[M];
	Calculate(Mat, Sum, M, N);
	for (size_t i = 0; i < N; i++)
		cout << Sum[i] << " ";
	cout << endl;








}
