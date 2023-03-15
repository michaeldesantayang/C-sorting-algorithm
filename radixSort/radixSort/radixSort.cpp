#include<iostream>

using namespace std;

int maxbit(int* data, int len) {//��ȡ�������λ��
	int d = 1;
	int p = 10;
	int maxdata = data[0];
	for (int i = 0; i < len; i++) {
		if (maxdata < data[i]) maxdata = data[i];
	}
	while (maxdata >= p) {
		maxdata /= 10;
		d++;
	}
	return d;
}

void radixSort(int* data, int len) {
	int d = maxbit(data, len);
	int *tmp = new(nothrow)int[len];
	if (tmp == NULL) exit(-1);
	int radix = 1;
	int count[10];//��λ����Ϊ��ֵ��Ͱ
	int key;
	for (int j = 1; j <= d; j++) {//ÿһλ�ӵ͵���������
		for (int i = 0; i < 10; i++) {
			count[i] = 0;
		}//ÿһλ��֮ǰ���Ͱ
		for (int k = 0; k < len; k++) {
			key = (data[k] / radix) % 10;//ȡ����λ����
			count[key]++;
		}
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];//ȡǰ׺��
		}
		for (int k = len - 1; k >= 0; k--) {
			key = (data[k] / radix) % 10;
			tmp[count[key] - 1] = data[k];//�������������������ﵹ����֤�ȶ���
			count[key]--;
		}
		for (int i = 0; i < len; i++) {
			data[i] = tmp[i];
		}
		radix *= 10;//���»���
	}
	delete []tmp;
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
	radixSort(a,N);
	cout << "The sorted array is:" << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}