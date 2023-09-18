#include <algorithm>
#include <iostream>
#include <fstream>
#include <ctime>

int bubbleSort(int*& a, int n) {
	int cnt = 0;
	for (int i = 0; i < n - 1; ++i) {
		cnt++;
		for (int j = i + 1; j < n; ++j) {
			cnt++;
			if (a[i] < a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				cnt += 3;
			}
		}
	}
	return cnt;
}

int** makeArray(int option) {
	int** a = new int* [10];
		for (int i = 0; i < 10; ++i) {
			a[i] = new int[(i + 1) * 100];
			for (int j = 0; j <= (i + 1) * 100; ++j) {
				switch (option) {
					case(1): {
						a[i][j] = 1;
						break;
					}
					case(2): {
						srand(time(0));
						a[i][j] = rand() % 1000;
						break;
					}
					case(3): {
						a[i][j] = j;
						break;
					}
				}
			}
		}
	return a;
}

void printArray(int* a, int n) {
	for (int i = 0; i < n; ++i)
		std::cout << a[i] << ' ';
}

int main() {
	int** minArray;
	int** maxArray;
	int** avgArray;
	minArray = makeArray(1);
	maxArray = makeArray(3);
	avgArray = makeArray(2);
	int** result = new int*[3];
	for (int i = 0; i < 3; ++i)
	result[i] = new int[10];
	for (int j = 0; j < 10; ++j) {
		result[0][j] = bubbleSort(*minArray, (j + 1) * 100);
		result[1][j] = bubbleSort(*avgArray, (j + 1) * 100);
		result[2][j] = bubbleSort(*maxArray, (j + 1) * 100);
	}
	for(int i = 0; i < 10; ++i)
		std::cout << "minimal difficulty for n = " << (i + 1) * 100 << " is " << result[0][i] << "\n";
	for (int i = 0; i < 10; ++i)
		std::cout << "average difficulty for n = " << (i + 1) * 100 << " is " << result[1][i] << "\n";
	for (int i = 0; i < 10; ++i)
		std::cout << "maximum difficulty for n = " << (i + 1) * 100 << " is " << result[2][i] << "\n";
}