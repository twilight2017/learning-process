#include<iostream>
using namespace std;

//该算法运用实现大数阶乘的求解，得到的结果存储在整形数组中
int main()
{
	int a[2000];//用于存放阶乘运算结果的整形数组
	int n,i=0,j=0,index,temp;
	cout << "请输入n的大小：" << endl;
	cin >> n;
	a[0] = 1;
	index = 1;//index表示当前从尾端至前第一个的数组内容为0的位置
	int count = 0;//计数器，用于记录末尾的0的个数
	for (i = 2; i <= n; i++)
	{
		int num = 0;//从最低位加起,此时的进位信号一定为0
		for (j = 0; j < index; j++)
		{
			temp = a[j] * i + num;
			a[j] = temp % 10;
			num = temp / 10;//num用于记录是否存在进位信号
		}
		while (num) {
			a[index] = num % 10;
			num = num / 10;
			index++;
		}
	}
	for (i = 0; a[i] == 0; i++)
		count++;
	cout << "所得结果中末位0的个数为：" << endl;
	cout << count;
	return 0;
}
