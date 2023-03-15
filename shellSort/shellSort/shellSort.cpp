#include<iostream>

using namespace std;

void shellSort(int* arr, int len) {
	int temp;
	int i, j, k;
	for (i = len / 2; i > 0; i /= 2) {//����Ϊ5�����γ��Զ�����󲽳�Ϊ1���꼴����
		for (j = i; j < len; j++) {//j�ǵ�һ����Ҫ���������Ԫ���±ꡣ����һ�����ĵڶ�������
			for (k = j - i; k >= 0; k -= i) {//k���������е����һ�����±ꡣ
				if (arr[k] > arr[k + i]) {//��������
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
		cin >> a[i];//cin�Ľ�����ʶ��Ϊ�ո���߻س�
	}
	shellSort(a, 10);
	cout << "The sorted array is:" << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}