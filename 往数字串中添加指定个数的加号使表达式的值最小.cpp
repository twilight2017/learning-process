#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<string>
#include<stdio.h>
using namespace std;

const int maxn = 505;
char s[maxn];//s是待处理的字符串，用字符型数组进行存储
int dp[maxn][maxn];
int num[maxn][maxn];//记录第二个子串对应的整数
const int inf = 0x3f3f3f3f;//定义进行数据比较前的初值

//求较小值的函数
int min(int a, int b)
{
	if (a >= b) return b;
	else return a;
}

//计算第二部分子串对应值的函数,注意a,b的值对应的是想要获取的子串在原串中的下标
int Num(int x,int y)
{
	if (num[x][y] != -1) {
		return num[x][y];//该值已经计算得到
    }
	int sum = 0;
		for (int i = x; i < y; i++)
			sum = sum * 10 + s[i] - '0';
		num[x][y] = sum;
		return sum;

}

//处理函数,用于计算前k个数字加m个加号的最小值
int solution(int k,int m)
{
	if (dp[k][m] != -1) {//结果已经计算得到
		return dp[k][m];
	}
	if (m == 0) {
		dp[k][0] = Num(0,k);//加入0个加号时等于返回该数本身
		return dp[k][0];
	}
	dp[k][m] = inf;//初始化该值为一无穷大的数，便于此后进行比较
	for (int i = k - 1; i >= m; i--) {
		dp[k][m] = min(dp[k][m], solution(i, m-1) + Num(i , k));
	}//不断增加第二个子串的长度，判断是否需要更新当前值，直到全部遍历完之后返回其中的最小值
	return dp[k][m];
}

//主函数
int main()
{
	memset(dp, -1, sizeof(dp));
	memset(num, -1, sizeof(num));
	cout << "请输入待处理数字串：" << endl;
	cin >> s;
	cout << "请输入待插入的加号个数：" << endl;
	int M;
	cin >> M;
	int len = strlen(s);
	int res = solution(len, M);
	cout << res;
	return 0;
}

