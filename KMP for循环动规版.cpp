#include<stdio.h> 
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class KMP
{
private:
	string B;
	int* next;
	void get_next()
	{
		int j = -1;
		next[0]=-1;
		next[1]=0; 
		for (int i = 1; i < B.length(); i++)
		{
			while (j != -1 && B[j] != B[i-1])
			{
				j = next[j];
			}
			if (j==-1||B[j] == B[i-1])
			{
				++j;
				if(B[j] != B[i]) 
				next[i] = j;
				else 
				next[i]=next[j];
			}	
		}

		for(int k=0;k<B.length();k++) 
		{
			printf("%d ",next[k]); 
		}	
		printf("\n"); 
	}
public:
	KMP(string under)
	{
		B = under;
		next = new int[B.length()];
		
		memset(next, 0, sizeof(int)*B.length());
		next[0] = -1;
		get_next();
	}
	int matching(string A)
	{
		int i=0,j=-1;
		for (int i = 0; i < A.length(); i++)
		{
			while (j >= 0 && A[i] != B[j + 1])//寻找子缀,直到匹配或者为0,可优化
			{
				j = next[j];
			}
			if (A[i] == B[j+1])j++;//匹配则j向后移动一位,
			if (j+1 == B.length())return i - j;//j==B.length()-1;代表匹配完毕.
		}
		return -1;

	}



};
int main()
{	string A,B;
	cin >> A;
	cin >> B;
	KMP ans(B);
	
	cout<<ans.matching(A);

}