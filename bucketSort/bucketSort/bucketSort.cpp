#include<iostream>
#include<vector>

using namespace std;
const int BUCKET_NUM = 10;//10��Ͱ���������ݼ����0��100
class ListNode {
public:
	ListNode* mNext;
	int mData;
	explicit ListNode(int i = 0) :mData(i), mNext(NULL){}//explicit�ؼ��ַ�ֹ��������ʽת��������ֵ���βο��Ա�����ֵ����
};

ListNode* insert(ListNode* head, int val) {
	ListNode* dummy = new(nothrow)ListNode;//����ͷ���ܻ�䣬����ͷǰ��Ŀսڵ㣨�ڱ�λ��
	if (!dummy) exit(-1);
	ListNode* pre = dummy;
	ListNode* newnode = new(nothrow)ListNode(val);
	if (!newnode) exit(-1);
	dummy->mNext = head;
	ListNode* cur = head;
	while (cur != NULL && cur->mData <= val) {//��ǰ��Ϊ�ղ��ҵ�ǰֵС��val������������
		pre = cur;
		cur = cur->mNext;
	}
	pre->mNext = newnode;//��ʱҪô�ߵ����һλ��next��Ҫô�ߵ���һ����val��Ľڵ�ǰ�档Ҳ����Ӧ�ò����λ��
	newnode->mNext = cur;
	return dummy->mNext;//���ظ������ͷ
}

ListNode* Merge(ListNode* head1, ListNode* head2) {
	ListNode dummyNode;//����鲢
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
	if (head2 != NULL) dummy->mNext = head2;//�������������ֻҪ����ʣ�µ�һ���������
	return dummyNode.mNext;
}

void bucketSort(int* arr, int len) {
	vector<ListNode*> buckets(BUCKET_NUM, NULL);//������ÿ��Ԫ����һ��ָ��������������ͷ�ڵ��ָ��
	int rank;
	for (int i = 0; i < len; ++i) {
		rank = arr[i] / BUCKET_NUM;
		buckets.at(rank) = insert(buckets.at(rank), arr[i]);//�����ӦͰ�����ظ��º��ͷ
	}
	ListNode* head = NULL;
	for (int i = 0; i < BUCKET_NUM; ++i) {
		head = Merge(head, buckets.at(i));
	}
	for (int i = 0; i < len; ++i) {
		arr[i] = head->mData;//�Ѿ����������Ԫ�ص�������
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
		cin >> a[i];//cin�Ľ�����ʶ��Ϊ�ո���߻س�
	}
	bucketSort(a, N);
	cout << "The sorted array is:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}