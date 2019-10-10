#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//结构体的实现，便于将每个数与其重数关联起来,即对每个众数进行封装
struct mode{
	int index;//众数
	int repeat;//该众数的重数
	void CreatMode(int a, int b) {
		index = a;
		repeat = b;
	}//构造函数和传值函数
};

//递归求解函数
void solution(int A[], int size, vector<mode> &s1) {
	if (size == 1||size==0) {
	}
	else {
		int B[50];//子数组1
		int C[50];//子数组2
		int size1 = 0;//数组B的元素个数
		int size2 = 0;//数组C的元素个数
		int mid = 0;//分治算法中中间位置的检索信号
		if (size % 2 == 0) mid = size / 2;//数组中元素个数为偶数
		else mid = size / 2 + 1;//数组中元素个数为奇数
		mode resm;
		resm.CreatMode(0, 0);
		int count1 = 0;
		int count2 = 0;
		for (int i = mid - 1; A[i] == A[mid - 1] && i >= 0; i--)
			count1++;
		for (int j = mid; A[j] == A[mid - 1] && j < size; j++)
			count2++;
		resm.index = A[mid - 1];//中位数作为候选众数
		resm.repeat = count1 + count2;//记录该中位数的重数
		mode mode2 = s1.front();
		if (resm.repeat > mode2.repeat) {
			s1.pop_back();
			s1.push_back(resm);
		}
		if (resm.repeat == mode2.repeat) {
			s1.push_back(resm);
		}
		//完成两个子数组的初始化
		for (int i = 0; i < mid - count1; i++) {
			size1++;
			B[i] = A[i];
		}
		for (int j = 0; j < size-mid; j++) {
			size2++;
			C[j] = A[j + mid];
		}
		 solution(B, size1,s1);
		 solution(C, size2,s1);
	}

}


//主函数
int main()
{
	int A[10] = {1,2,2,2,3,3,3,7,5,6};
	int size = sizeof(A) / sizeof(int);//计算数组的长度
	vector<mode> s1;
	//定义全局变量，用于存放结果
	mode mode1;
	mode1.CreatMode(0, 0);
	s1.push_back(mode1);
	solution(A,size,s1);
	int i = 0;
	while (i<s1.size())
	{
		mode mod = s1[i];
		cout << "该序列的众数为：" << mod.index << "     该众数对应的重数为：" << mod.repeat;
		cout << endl;
		int k = 0;
		i++;
	}
	return 0;
}
