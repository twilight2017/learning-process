#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	//随机产生一个n行m列的整形矩阵
	int n, m;//行数和列数
	cin >> n >> m;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << (rand() % 10) + 1 << " ";
			//要取得[a,b)的随机整数，使用(rand()%(b-a))+a;
			//要取得[a,b]的随机整数，使用(rand()%(b-a+1))+a;
			//要取得(a,b]的随机整数，使用(rand()%(b-a))+a+1;
		}
		cout << endl;//单行换行
	}
	return 0;
}