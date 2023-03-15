#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

template <typename T>
void bubbleSort(T* array, int len) {
	for (int j = len - 1; j > 0; j--) {
		bool done = true;//每一趟标志位设置为真
		for (int i = 0; i < j; i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]); 
				done = false;//一旦交换就设置为假
			}
		}
		if (done == true)return;//标志位为真，说明此轮没有交换，说明已经有序了
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
	bubbleSort(arr, N);
	cout << "Sort complete:" << endl;
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete []arr;
	return 0;
}