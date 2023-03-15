#include<iostream>

using namespace std;

void shellSort(int* arr, int len) {
	int temp;
	int i, j, k;
	for (i = len / 2; i > 0; i /= 2) {//步长为5，依次除以二，最后步长为1排完即有序
		for (j = i; j < len; j++) {//j是第一个需要插入排序的元素下标。（第一组数的第二个数）
			for (k = j - i; k >= 0; k -= i) {//k是有序序列的最后一个数下标。
				if (arr[k] > arr[k + i]) {//插入排序
					temp = arr[k];
					arr[k] = arr[k + i];
					arr[k + i] = temp;
				}
			}
		}
	}
}

int main() {
	int a[20];
	int N;
	cout << "Enter the length of the array:" << endl;
	cin >> N;
	cout << "Enter the array to be sorted:" << endl;
	for (int i = 0; i < N; i++) {
		cin >> a[i];//cin的结束标识符为空格或者回车
	}
	shellSort(a, 10);
	cout << "The sorted array is:" << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}