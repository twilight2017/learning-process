#include<iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int i = 0, j = 0;
		int num = 0;//用于更新用的数字
		int m = 0;//输出值
		int count = 0;//计数器，用于记录该数字的长度
		int a = x / pow(10, i);
		
	
			while (a != 0) {
				count++;
				i++;
				a = x / pow(10, i);
			}
			while (count > 0) {
				num = x / pow(10, count - 1);
				x = x - num * pow(10, count - 1);
				m += num * pow(10, j);
				j++;
				count--;
			}
			return m;
		}
	};
    
	
	int main()
	{
		int origin;//原始输入
		cin >> origin;
		Solution st;
		cout<<st.reverse(origin);
		return 0;
	}
