#include<iostream>
#include<cstdlib>

using namespace std;

void countingSort(int* arr, int* sortedArr,int len) {
	int min = arr[0];
	int max = arr[0];//�����Сֵ��ʼ��Ϊ������Ԫ��
	for (int i = 1; i < len; i++) {
		if (min > arr[i]) min = arr[i];
		if (max < arr[i]) max = arr[i];
	}
	int k = max - min + 1;//count����ĳ��ȣ�Ϊ���鷶Χ��ӳ��
	int* countArr = new(nothrow)int[k];
	if (countArr == NULL) exit(-1);
	for (int i = 0; i < k; i++) countArr[i] = 0;
	for (int i = 0; i < len; i++) {
		countArr[arr[i] - min]++;//ӳ���ϵ��arr[i]��Ӧ��count�����±�Ϊarr[i] - min
	}
	for (int i = 1; i < k; i++) {
		countArr[i] += countArr[i - 1];//ȡǰ׺�ͣ�����count����Ԫ�ض�Ӧ�������������±��1
	}
	for (int j = len; j > 0; j--) {
		sortedArr[--countArr[arr[j - 1] - min]] = arr[j - 1];//Ϊ�˱�֤�ȶ��ԡ���¼����ʱ�����ҽ���count���飬���ǵ�������ʱ��������󵹳�
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