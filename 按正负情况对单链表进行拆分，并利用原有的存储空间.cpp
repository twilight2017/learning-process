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

//实现拆分表操作的函数
void solution(Link h1) {
	int B[50];
	int C[50];//这两个数组分别用于暂时存放拆分后链表中的数据
	int i=0,j=0;//表B和表C的计数器
	Node *p = h1.head;//定义指针p用于遍历表A
	while (p) {
		if (p->num >= 0) {
			B[i] = p->num;
			i++;
		}
		else {
			C[j] = p->num;
			j++;
		}
		p = p->next;
	}//while循环完成表A的遍历与数据划分
	Node *q = h1.head;
	cout << "表B中的各数据元素为：" << endl;
	for (int k = 0; k < i; k++) {
		q->num = B[k];
		cout << q->num << " ";
		q = q->next;
	}
	cout << endl;
	cout << "表C中的各数据元素为：" << endl;
	for (int k = 0; k < j; k++) {
		q->num = C[k];
		cout << q->num << " ";
		q = q->next;
	}

}

//函数主体部分
int main()
{
	int n;//表A的长度
	Link h1;
	cout << "请输入待拆分链表的长度：" << endl;
	cin >> n;
	Node *hed = h1.Creatlink(n);
	solution(h1);
}
