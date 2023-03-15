#include<iostream>
#include<algorithm>

using namespace std;
//大根堆 堆排序
void heapSink(int* array, int length, int index) {
	int maxID = index; //maxID初始化为index
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < length && array[left] > array[maxID]) maxID = left; //如果有左孩子，且左孩子比maxID大，maxID更新为左孩子（此时maxID为两者最大值）
	if (right < length && array[right] > array[maxID]) maxID = right;//如果有右孩子，且右孩子比maxID大，maxID更新为右孩子。此时maxID为三者最大值
	if(maxID != index) {//如果需要调整
		swap(array[index], array[maxID]);
		heapSink(array, length, maxID);
	}
}

void heapSort(int* array, int length) {
	for (int i = length / 2 - 1; i >= 0; i--) {//从最后一个非叶子节点开始，即最后一个节点的父亲节点
		heapSink(array, length, i);
	}
	for (int j = length - 1; j > 0; j--) {
		swap(array[0], array[j]);
		heapSink(array, j, 0);
	}
}

int main() {
	int array[20];
	int N;
	cout << "Enter the size of the array:" << endl;
	cin >> N;
	cout << "Enter the array to be sorted:" << endl;
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}
	cout << endl;
	heapSort(array, N);
	for (int i = 0; i < N;i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}