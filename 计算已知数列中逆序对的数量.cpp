#include<iostream>
#include<algorithm>
using namespace std;

//求解合并部分逆序对数量的函数
int comb(int B[], int C[], int mid,int size1,int size2) {
	int count = 0;//逆序对计数器
	//j是数组C的索引信号,i是数组B的索引号
	sort(B, B + size1);//对数组B进行排序，默认排序方法为从小到大
		for (int j = size2 - 1; j >= 0; j--)
			for (int i = 0; i < size1; i++)
				if (B[i] > C[j]) {
					count += mid - i;
					break;
				}
	return count;
}

//求解子数组中逆序对数量的函数
int solution(int A[],int size) {
	int count=0;//计数器，用于记录逆序对的个数
	if (size == 2 && A[0] > A[1]) {//递归的边界条件，用于终止递归条件
		count++;
		return count;
	}
	if (size == 2 && A[0] < A[1])
		return 0;
	if (size == 1) return 0;
	else {
		int B[50];//子数组1
		int C[50];//子数组2
		int size1=0;//数组B的元素个数
		int size2=0;//数组C的元素个数
		int mid = 0;//分治算法中中间位置的检索信号
		if (size % 2 == 0) mid = size / 2;//数组中元素个数为偶数
		else mid = size / 2 + 1;//数组中元素个数为奇数
		//完成两个子数组的初始化
		for (int i = 0; i < mid; i++) {
			B[i] = A[i];
			size1++;
		}
		
		for (int j = 0; j < size-mid; j++) {
			C[j] = A[mid + j];
			size2++;
		}
		return solution(B,size1) + solution(C,size2)+comb(B,C,mid,size1,size2);//不断把问题细分为同类型的子问题
	}
}


//主函数
int main()
{
	int A[4] = {1,2,3,4,};
	int size = sizeof(A) / sizeof(int);//计算数组的长度
	int count = solution(A,size);
	cout << count;
	return 0;
}