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
};

Node * Link::Creatlink(int n) {
	int i;
	size = 1;
	head = tail = NULL;
	cout << "请依次输入该单链表各元素：" << endl;
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
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}//比较两链表长度的最大值

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}//比较两链表长度的最小值

//实现单链表的加法操作
int Sumcal(Link h1,Link h2){
	int judge = 0;//进位信号，用于记录进位信息
	int sum;//当前节点的加法和
	int i = 0;//位数记录标志
	int cot = 0;//最后输出的数字结果
	while (i<min(h1.size,h2.size)) {
		Node *a = h1.head;
		Node *b = h2.head;//分别获取两个单链表的头指针,防止a,b不参与循环的情况
		Node *p = h1.head;
		for (int j = h1.size; j > i+1; j--)
		{
			a = p->next;
			p = p->next;
		}
		Node *q = h2.head;
		for (int j = h2.size; j > i+1; j--)
		{
			b = q->next;
			q = q->next;
		}
		sum = a->num + b->num + judge;
		if (sum >= 10) {
			judge = 1;
			cot += (sum - (10))*pow(10,i);
		}
		if (sum < 10) {
			judge = 0;
			cot += sum * pow(10, i);
		}
		i++;
		
	}
	int k = i;
	while (k < max(h1.size, h2.size)) {
		if (h1.size > h2.size) {
			Node *a = h1.head;
			Node *p = h1.head;
			for (int j = h1.size; j > k + 1; j--)
			{
				a = p->next;
				p = p->next;
			}
			sum = a->num+judge;
			cot+= sum * pow(10, k);
		}
		else {
			Node *b = h2.head;//分别获取两个单链表的头指针,防止a,b不参与循环的情况
			Node *q = h2.head;
			for (int j = h2.size; j > k + 1; j--)
			{
				b = q->next;
				q = q->next;
			}
			sum = b->num + judge;
			cot += sum * pow(10, k);
		}
		k++;
	}
	if ((h1.size == h2.size)&&((h1.head->num + h2.head->num)>=10)) cot += pow(10, k);//特殊情况处理
	return cot;
}

//函数主体部分
int main()
{
	Link h1;
	Link h2;
	int h3;
	int n, m;
	cout << "请输入第一个链表的长度：" << endl;
	cin >> n;
	cout << "请输入第二个链表的长度：" << endl;
	cin >> m;
	Node * tal1 = h1.Creatlink(n);
	Node * tal2 = h2.Creatlink(m);
	h3 = Sumcal(h1, h2);
	cout << "两单链表做加法运算得到的结果为：";
	cout << h3;
}