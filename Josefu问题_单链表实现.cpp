#include<iostream>
#include<malloc.h>
#include<iomanip>
using namespace std;
class Node {
public:
	int num;//该节点对应序号
	Node *next;//指向其直接后继节点的指针
};
class Link {
public:
	Node *head;
	Node *tail;
	int size;
	Node* Creatlink(int n);//创建一个长度为n的循环单链表
	Node* DeleteLink(Node *s);//用于删除节点
	void Josephu(Node *p, int n, int m, int k);//按约瑟夫规则进行输出

};
Node * Link::Creatlink(int n) {
	int i;
	head=tail=NULL;
	for (i = 1; i <= n; i++)
	{
		if (i == 1) head = tail = (Node *)malloc(sizeof(Node));//创建头节点
		else {
			tail->next = (Node *)malloc(sizeof(Node));//创建一个新节点，链入单链表尾部
			tail = tail->next;//表尾指针下移
		}
		tail->num = i;//给该节点数据元素赋信号值；
		tail->next = NULL;//收尾，预防出现野指针
	}
	tail->next = head;//为单链表做循环处理
	return head;//返回头节点
}

Node * Link::DeleteLink(Node *s) {
	Node *p = s;
	while (p->next != s)
		p = p->next;
	p->next = s->next;
	free(s);//释放被删除节点
	return (p->next);//为方便本题的处理，返回删除节点的下一节点的指针

}

void Link::Josephu(Node *p, int n, int m, int k) {//默认这个p指针指向的是单链表的第一个节点
	int i, j;
	cout << "输出的序列为：" << endl;
	for (i = 1; i < k; i++)
		p = p->next;//找出起始报数的人
	for (i = 0; i < n; i++)//每次循环出列一人
	{
		for (j = 1; j < m; j++)
			p = p->next;//找出当前需要出列的人
		cout << p->num << ",";
		p = DeleteLink(p);//删除出列节点并返回其下一个人；
	}

}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	Link h; 
	Node *hed=NULL;//指针要做初始化操作，防止出现野指针
	hed = h.Creatlink(n);
	h.Josephu(hed, n, m, k);
	return 0;

}
