#include<iostream>
using namespace std;

//用于实现查找矩阵中某元素是否存在的函数,存在时返回1，否则返回0
int solution(int M[5][5],int rb,int re,int cb,int ce,int x) {//rb(行首元素下标),re(行尾元素下标),cb(列首元素下标),ce(列尾元素下标),x(待查询元素)
	int rm = (rb + re) / 2;
	int cm = (cb + ce) / 2;
	//rm,cm的值用于检索该矩阵的最中心元素
	if (rb > re || cb > ce) {//错误参数处理
		return 0;
	}
	if (x == M[rm][cm]) {
		return 1;
	}//查询成功
	else if (rb == re && cb == ce) {
		return 0;
	}//当前子矩阵中仅有一个元素且该元素不是待查询元素，这也是这道递归问题的边界条件
	if (x > M[rm][cm]) {
		return (solution(M, rm + 1, re, cb, cm, x) || solution(M, rb, re, cm + 1, ce,x));
	}//以左下部分和右半部分为递归问题的子矩阵
	if (x < M[rm][cm]) {
		return (solution(M, rb, rm - 1, cb, ce, x) || solution(M, rm, re, cb, cm - 1,x));
	}//以左部分和上部分为递归问题的子矩阵
}

//主函数
int main()
{
	int x;
	cout << "请输入待查询元素：" << endl;
	cin >> x;
	int M[5][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
	int res = solution(M, 0, 4, 0, 4,x);
	if (res == 1) cout << "该矩阵中存在"<<x;
	else cout << "该矩阵中不存在"<<x;
	return 0;
}