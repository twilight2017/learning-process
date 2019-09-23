#include<iostream>
#include<string>
using namespace std;

//判断是否为变位词的函数实现
int judgeword(string s1, string s2) {
	int count = 0;//计数器，用于遍历每一个字符
	if (s1.length() == s2.length()) {
		for (int i = 0; i < s1.length(); i++) 
			for (int j = 0; j < s2.length(); j++) {
				if (s1[i]==s2[j]) count++;
			}
		if (count == s1.length()) return 1;
		else return 0;
	}
	else return 0;//两字符串长度不等，一定不可能是变位词
}

//主函数
int main()
{
	string s1, s2;
	cout << "请输入待检测的两个单词：" << endl;
	cin >> s1 >> s2;
	int result = judgeword(s1, s2);
	if (result == 1) cout << "输入的两个单词是变位词";
	else cout << "输入的两个单词不是变位词";
	return 0;
}