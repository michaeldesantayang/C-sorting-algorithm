#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

template <typename T>//语法糖。可接受各种数据类型，自动转换。
void selectSort(T* array, int len) {
	for (int j = len - 1; j > 0; j--) {
		int maxID = 0;
		for (int i = 0; i <= j; i++) {
			if (array[i] > array[maxID]) maxID = i;
		}
		swap(array[maxID], array[j]);
	}
}

int main() {
	int N;
	cout << "Enter the size of the array:" << endl;
	cin >> N;
	int* arr = new(nothrow)int[N];
	if (arr == NULL) exit(-1);
	cout << "Enter the array to be sorted:" << endl;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << endl;
	selectSort(arr, N);
	cout << "Sort complete:" << endl;
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete []arr;
	return 0;
}