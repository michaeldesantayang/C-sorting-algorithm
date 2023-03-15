#include<iostream>
#include<cstdlib>
using namespace std;

void binaryInsertSort(int array[], int len) {
	int left, right, key, mid;
	for (int i = 1; i < len; i++) {//��ǰ������i����
		left = 0;
		right = i - 1;
		key = array[i];//��ǰ(i - 1)������������Ųʱarray��i���ᱻ���ǵ�����ǰ����
		mid = (left + right) >> 1;
		while (left <= right) {//ע���ٽ�������������Ҽ�����1����0��midʼ����left��
			if (array[mid] > key) right = mid - 1;//array��mid������key����ʱmid����left����left��Ӧ��λ�þ�����ȷ��λ�ã�������ǰ�棩
			else left = mid + 1;//array��mid��С��key����ʱmid����left����left + 1����Ӧ��λ�þ�����ȷ��λ�ã����������棩
			mid = (left + right) >> 1;
		}
		for (int j = i - 1; j >= left; j--) {
			array[j + 1] = array[j];
		}
		array[left] = key;
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
	binaryInsertSort(arr, N);
	cout << "Sort complete:" << endl;
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[]arr;
	return 0;
}