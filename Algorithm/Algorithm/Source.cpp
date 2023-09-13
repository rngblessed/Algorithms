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

int** makeArray() {
	int** a = new int* [10];
		for (int i = 0; i < 10; ++i) {
			a[i] = new int[(i + 1) * 100];
			for (int j = 0; j <= (i + 1) * 100; ++j) {
				srand(time(0));
				a[i][j] = rand() % 1000;
			}
		}
	return a;
}

void printArray(int* a, int n) {
	for (int i = 0; i < n; ++i)
		std::cout << a[i] << ' ';
}

int main() {
	int choice;
	int** a;
	a = makeArray();
	int* result = new int[10];
	for (int i = 0; i < 10; ++i) {
			result[i] = bubbleSort(a[i], (i+1)*100);
			std::cout << "for n = " << (i+1)*100 << " difficulty is " << result[i] << "\n";
	}
}