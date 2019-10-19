#include<iostream>
#include<stdio.h>
using namespace std;

const int maxn = 1000;//该问题用于求解待找零钱数不超过1000的值
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn];
const int n = 6;//硬币面值的总数恒为6
const int S[6] = { 1,5,10,20,50,100 };//全局定义货币面值数组

//大小比较函数
int min(int a,int b)
{
	int res = a <= b ? a : b;
	return res;
}

//求解函数
int solution(int i, int j) {
	if (dp[i][j] != -1) {//计算结果已经得到
		return dp[i][j];
	}
	if (j == 0) {//背包中无钱可放
		dp[i][0] = 0;
		return dp[i][0];
	}
	dp[i][j] = inf;//为便于之后的求较小值处理，为每个dp[i][j]赋一个较小的值
	for(int m=i;m>=0;m--)
	 for (int k = m; k >=0 ; k--)
		for (int money = j; money >= S[k];money--) {
			dp[m][money] = min(solution(m, money - S[k]) + 1, dp[m][money]);
			return dp[m][money];
		}
}

//主函数
int main()
{
	memset(dp, -1, sizeof(dp));
	cout << "请输入待处理钱的总数：" << endl;
	int money;
	cin >> money;
	int res = solution(5, money);
	cout << "所需零钱的最小张数为：" << endl;
	cout << res;
	return 0;
}