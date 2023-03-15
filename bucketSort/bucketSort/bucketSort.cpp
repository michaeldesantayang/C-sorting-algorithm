#include<iostream>
#include<vector>

using namespace std;
const int BUCKET_NUM = 10;//10个桶，排序数据假设从0到100
class ListNode {
public:
	ListNode* mNext;
	int mData;
	explicit ListNode(int i = 0) :mData(i), mNext(NULL){}//explicit关键字防止构造器隐式转换，给定值的形参可以被其他值覆盖
};

ListNode* insert(ListNode* head, int val) {
	ListNode* dummy = new(nothrow)ListNode;//由于头可能会变，设置头前面的空节点（哨兵位）
	if (!dummy) exit(-1);
	ListNode* pre = dummy;
	ListNode* newnode = new(nothrow)ListNode(val);
	if (!newnode) exit(-1);
	dummy->mNext = head;
	ListNode* cur = head;
	while (cur != NULL && cur->mData <= val) {//当前不为空并且当前值小于val，继续向后遍历
		pre = cur;
		cur = cur->mNext;
	}
	pre->mNext = newnode;//此时要么走到最后一位的next，要么走到第一个比val大的节点前面。也就是应该插入的位置
	newnode->mNext = cur;
	return dummy->mNext;//返回该链表的头
}

ListNode* Merge(ListNode* head1, ListNode* head2) {
	ListNode dummyNode;//链表归并
	ListNode* dummy = &dummyNode;
	while (head1 != NULL && head2 != NULL) {
		if (head1->mData <= head2->mData) {
			dummy->mNext = head1;
			head1 = head1->mNext;
		}
		else {
			dummy->mNext = head2;
			head2 = head2->mNext;
		}
		dummy = dummy->mNext;
	}
	if (head1 != NULL) dummy->mNext = head1;
	if (head2 != NULL) dummy->mNext = head2;//由于是链表，最后只要接上剩下的一个链表就行
	return dummyNode.mNext;
}

void bucketSort(int* arr, int len) {
	vector<ListNode*> buckets(BUCKET_NUM, NULL);//容器里每个元素是一个指向这组数据链表头节点的指针
	int rank;
	for (int i = 0; i < len; ++i) {
		rank = arr[i] / BUCKET_NUM;
		buckets.at(rank) = insert(buckets.at(rank), arr[i]);//插入对应桶，返回更新后的头
	}
	ListNode* head = NULL;
	for (int i = 0; i < BUCKET_NUM; ++i) {
		head = Merge(head, buckets.at(i));
	}
	for (int i = 0; i < len; ++i) {
		arr[i] = head->mData;//已经有序的链表元素倒回数组
		head = head->mNext;
	}
}

int main() {
	int a[20];
	int N;
	cout << "Enter the length of the array:" << endl;
	cin >> N;
	cout << "Enter the array to be sorted:" << endl;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];//cin的结束标识符为空格或者回车
	}
	bucketSort(a, N);
	cout << "The sorted array is:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}