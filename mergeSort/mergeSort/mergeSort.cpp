#include<iostream>
#include<cstdlib>
using namespace std;

void merge(int arr[], int mid, int low, int high) {
	int i = low;
	int j = mid + 1;
	int k = 0;
	int* reg = new(nothrow)int[high - low + 1];
	if (reg == NULL) exit(-1);
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j]) {
			reg[k++] = arr[i++];
		}
		else {
			reg[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		reg[k++] = arr[i++];
	}
	while (j <= high) {
		reg[k++] = arr[j++];
	}
	for (i = low, k = 0; i <= high; i++, k++) {
		arr[i] = reg[k];
	}
	delete []reg;
}

void mergeSort(int arr[], int low, int high) {
	if (low >= high) return;
	else {
		int mid = (low + high) >> 1;//�൱�ڳ��Զ���������ȫ������һλ
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, mid, low, high);
	}
}//����˼���ģ��

int main() {
	int N;
	cout << "Enter the size of the array:" << endl;
	cin >> N;
	int* array = new(nothrow)int[N];//���������NULL
	if (array == NULL) exit(-1);//���������жϣ�exit�ǲ���ϵͳ�ṩ�ĺ���
	cout << "Enter the array to be sorted:" << endl;
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}
	cout << endl;
	mergeSort(array, 0, N - 1);
	cout << "Sort complete:" << endl;
	for (int i = 0; i < N;i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	delete []array;//�����ɾ��
	return 0;
}