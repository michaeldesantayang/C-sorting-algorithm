#include<iostream>
#include<algorithm>

using namespace std;
//����� ������
void heapSink(int* array, int length, int index) {
	int maxID = index; //maxID��ʼ��Ϊindex
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < length && array[left] > array[maxID]) maxID = left; //��������ӣ������ӱ�maxID��maxID����Ϊ���ӣ���ʱmaxIDΪ�������ֵ��
	if (right < length && array[right] > array[maxID]) maxID = right;//������Һ��ӣ����Һ��ӱ�maxID��maxID����Ϊ�Һ��ӡ���ʱmaxIDΪ�������ֵ
	if(maxID != index) {//�����Ҫ����
		swap(array[index], array[maxID]);
		heapSink(array, length, maxID);
	}
}

void heapSort(int* array, int length) {
	for (int i = length / 2 - 1; i >= 0; i--) {//�����һ����Ҷ�ӽڵ㿪ʼ�������һ���ڵ�ĸ��׽ڵ�
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