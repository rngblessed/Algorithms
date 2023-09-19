#include <algorithm>
#include <iostream>
#include <ctime>

int bubbleSort(int*& a, int n) {
	int cnt = 0;
	srand(time(0));
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			cnt += 2;
			if (a[i] < a[j]) {
				std::swap(a[i], a[j]);
				cnt += 5;
			}
		}
	}
	return cnt;
}

int** makeArray(int option) {
	int** a = new int* [10];
	for (int i = 0; i < 10; ++i) {
		a[i] = new int[(i + 1) * 100];
		for (int j = 0; j < (i + 1) * 100; ++j) {
			switch (option) {
			case(1): {
				a[i][j] = 1;
				break;
			}
			case(2): {
				a[i][j] = std::rand() % 1000;
				break;
			}
			case(3): {
				a[i][j] = j + 1;
				break;
			}
			}
		}
	}
	return a;
}

int main() {
	int** minArray;
	int** maxArray;
	int** meanArray;
	minArray = makeArray(1);
	maxArray = makeArray(3);
	meanArray = makeArray(2);
	int** result = new int* [3];
	for (int i = 0; i < 3; ++i)
		result[i] = new int[10];
	for (int j = 0; j < 10; ++j) {
		int sum = 0;
		result[0][j] = bubbleSort(*&minArray[j], (j + 1) * 100);
		for (int n = 0; n < 1000; ++n) {
			sum += bubbleSort(*&meanArray[j], (j + 1) * 100);
			meanArray = makeArray(2);
		}
		result[1][j] = sum / 1000;
		result[2][j] = bubbleSort(*&maxArray[j], (j + 1) * 100);
	}
	for (int i = 0; i < 10; ++i)
		std::cout << "minimal difficulty for n = " << (i + 1) * 100 << " is " << result[0][i] << "\n";
	std::cout << "\n";
	for (int i = 0; i < 10; ++i)
		std::cout << "mean difficulty for n = " << (i + 1) * 100 << " is " << result[1][i] << "\n";
	std::cout << "\n";
	for (int i = 0; i < 10; ++i)
		std::cout << "maximum difficulty for n = " << (i + 1) * 100 << " is " << result[2][i] << "\n";
}