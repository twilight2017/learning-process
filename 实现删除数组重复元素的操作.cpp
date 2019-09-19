#include<iostream>
#include<malloc.h>
#include<iomanip>
using namespace std;

//单个节点的实现
class Node {
public:
	int num;//该节点存储的数字
	Node *next;//指向其后继节点的指针
};

//单链表的实现
class Link {
public:
	Node *head;
	Node *tail;
	int size;
	Node* Creatlink(int n);//创建一个长度为n的单链表
	Node* DeleteLink(Node *s);//用于删除节点
};

//生成节点的操作
Node * Link::Creatlink(int n) {
	int i;
	size = 1;
	head = tail = NULL;
	cout << "请依次输入待处理数组各元素：" << endl;
	for (i = 1; i <= n; i++)
	{
		int number;//用于输入待计算链表值
		if (i == 1) head = tail = (Node *)malloc(sizeof(Node));//创建头节点
		else {
			tail->next = (Node *)malloc(sizeof(Node));//创建一个新节点，链入单链表尾部
			tail = tail->next;//表尾指针下移
			size++;
		}
		cin >> number;
		tail->num = number;//给该节点数据元素赋信号值；
		tail->next = NULL;//收尾，预防出现野指针
	}
	tail->next = NULL;//为单链表做收尾处理
	return head;//返回尾节点，便于之后方便开始从尾部进行计算
}

//删除节点的操作
Node * Link::DeleteLink(Node *s) {
	Node *p = head;
	while (p->next != s)
		p = p->next;
	p->next = s->next;
	free(s);//释放被删除节点
	size--;//单链表长度执行减一操作
	return (p->next);//为方便本题的处理，返回删除节点的下一节点的指针

}

//删除数组中重复元素的函数
Link solution(Link h1) {
	Node *q = h1.head;
	while (q) {
		Node *m = q->next;
		while (m) {
			if (m->num != q->num) m = m->next;//元素不重复时检索指针正常下移
			else {
				m = h1.DeleteLink(m);
			}
		}
		q = q->next;
	}
	return h1;
}

//主函数
int main()
{
	Link h1;
	int n;//数组长度
	int number;//数组元素
	cout << "请输入待处理的数组长度：" << endl;
	cin >> n;
	Node *hed = h1.Creatlink(n);
	Link h2;
	h2 = solution(h1);
	Node *p = h2.head;
	for (int j = 0; j < h2.size; j++)
	{

		cout << p->num << " ";
		p = p->next;
	}
}

