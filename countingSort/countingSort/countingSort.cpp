#include<iostream>
#include<cstdlib>

using namespace std;

void countingSort(int* arr, int* sortedArr,int len) {
	int min = arr[0];
	int max = arr[0];//最大最小值初始化为数组首元素
	for (int i = 1; i < len; i++) {
		if (min > arr[i]) min = arr[i];
		if (max < arr[i]) max = arr[i];
	}
	int k = max - min + 1;//count数组的长度，为数组范围的映射
	int* countArr = new(nothrow)int[k];
	if (countArr == NULL) exit(-1);
	for (int i = 0; i < k; i++) countArr[i] = 0;
	for (int i = 0; i < len; i++) {
		countArr[arr[i] - min]++;//映射关系，arr[i]对应的count数组下标为arr[i] - min
	}
	for (int i = 1; i < k; i++) {
		countArr[i] += countArr[i - 1];//取前缀和，这样count数组元素对应着有序数组中下标加1
	}
	for (int j = len; j > 0; j--) {
		sortedArr[--countArr[arr[j - 1] - min]] = arr[j - 1];//为了保证稳定性。记录数组时从左到右进入count数组，于是倒出来的时候从右向左倒出
	}
	delete[] countArr;
}

int main() {
	int N;
	cout << "Enter the size of the array:" << endl;
	cin >> N;
	int* arr = new(nothrow)int[N];
	int* sortedArr = new(nothrow)int[N];
	if (arr == NULL || sortedArr == NULL) exit(-1);
	cout << "Enter the array to be sorted:" << endl;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << endl;
	countingSort(arr, sortedArr,N);
	cout << "Sort complete:" << endl;
	for (int i = 0; i < N; i++) {
		cout << sortedArr[i] << " ";
	}
	cout << endl;
	delete[] arr;
	delete[] sortedArr;
	return 0;
}