#include<iostream>
#include<cstdlib>
using namespace std;

void binaryInsertSort(int array[], int len) {
	int left, right, key, mid;
	for (int i = 1; i < len; i++) {//往前面插入第i个数
		left = 0;
		right = i - 1;
		key = array[i];//在前(i - 1)个数整体往后挪时array【i】会被覆盖掉，提前保存
		mid = (left + right) >> 1;
		while (left <= right) {//注意临界情况，不管是右减左是1还是0，mid始终是left。
			if (array[mid] > key) right = mid - 1;//array【mid】大于key，此时mid等于left，则left对应的位置就是正确的位置（排在它前面）
			else left = mid + 1;//array【mid】小于key，此时mid等于left，则（left + 1）对应的位置就是正确的位置（排在它后面）
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