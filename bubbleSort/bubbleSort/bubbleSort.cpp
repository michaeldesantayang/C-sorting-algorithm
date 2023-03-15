#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

template <typename T>
void bubbleSort(T* array, int len) {
	for (int j = len - 1; j > 0; j--) {
		bool done = true;//ÿһ�˱�־λ����Ϊ��
		for (int i = 0; i < j; i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]); 
				done = false;//һ������������Ϊ��
			}
		}
		if (done == true)return;//��־λΪ�棬˵������û�н�����˵���Ѿ�������
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