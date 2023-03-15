#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int left, right;

int* part(int* array, int left, int right) {
	int i = left + 1;
	int index = left + 1 + rand() % (right - left - 1);//注意index取值在（left + 1）和（right - 1）之间
	//cout << "index = " << index << endl;
	int pivot = right - 1;//这一趟的基准值
	swap(array[index], array[pivot]);
	while (i != right) {
		if (array[i] < array[pivot]) {
			swap(array[i++], array[++left]);
		}
		else if (array[i] == array[pivot]) {
			i++;
		}
		else {
			swap(array[i], array[--right]);
		}
		//cout << "i = " << i << endl;
		//cout << "left = " << left << endl;
		//cout << "right =" << right << endl;
		/*for (int j = 0; j < 5; j++) {
			cout << array[j] << " ";
		}
		cout << endl;*/
	}
	int e[2] = { left,right };//返回的是一个数组，里面是左边界和右边界
	return e;
}

void quickSort(int* array, int left, int right) {
	if (right - left > 2) {//即数组大小大于1
		int* equal = part(array, left, right);
		quickSort(array, left, equal[0] + 1);
		quickSort(array, equal[1] - 1, right);
	}
}

int main(){
	int a[20];
	int N;
	cout << "Enter the length of the array:" << endl;
	cin >> N;
	cout << "Enter the array to be sorted:" << endl;
	for (int i = 0; i < N; i++) {
		cin >> a[i];//cin的结束标识符为空格或者回车
	}
	quickSort(a, -1, N);
	cout << "The sorted array is:" << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}