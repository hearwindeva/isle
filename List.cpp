#include <iostream>
#include <algorithm>
#include <conio.h>

#define N 10
using namespace std;

//堆的实现
template <typename Item>
class Seqlist
{
	private:
		Item *data; // 数据存放
		int count; // 目前所含数据量大小
		int capacity; // 总容量大小
	public:
		Seqlist(int capacity)//构造
		{
			this->data = new Item[capacity]; // 堆中数据从索引为1的位置开始存储
			this->count = 0;
			this->capacity = capacity;
		}
		Seqlist(Item arr[], int n)//数组构造
		{
			this->data = new Item[n];
			this->count = n;
			this->capacity = n;
			for(int i = 0; i < n; i++)
				{
					this->data[i] = arr[i];
				}
		}
		~Seqlist()//析构
		{
			delete[] this->data;
		}
		void Insert(int n,Item item);
		void Delete(int n);
		Item Find(int n);
		void relocate(int k);
};
template <typename Item>
void Seqlist<Item>::Insert(int n,Item item)
{
	if(n-1>=this->count||n<0) throw "溢出并不在尾部";
	// 按照惯例，容量扩大到原来的2倍
	if(this->count >= this->capacity)
		{
			this->capacity = this->capacity + this->capacity; // 容量变成2倍
			Item* more_data = new Item[this->capacity]; // data[0] 不存放任何元素
			copy(this->data, this->data + this->count, more_data); // 将原先 data 中的有效数据拷贝到 more_data 中
			delete[] this->data;
			this->data = more_data;
		}
			for(int i=count; i>n; i--)
				{
					this->data[i]=this->data[i-1];
				}
			this->data[n] = item; // 插入表
			this->count ++;
}
template <typename Item>
Item Seqlist<Item>::Find(int n)
{
	if(n>=count||n<0) throw "溢出";
	else
		return data[n];
}
template <typename Item>
void Seqlist<Item>::Delete(int n)
{
	if(n>=count||n<0) throw "溢出";
	else
		for(int i=n; i<count-1; i++)
			{
				this->data[i]=this->data[i+1];
			}
	this->count --;
}
template <typename Item>
void Seqlist<Item>::relocate(int k)
{
	
}
int main()
{
	int A[N]= {1,7,50,42,19,81,2,94,15,46};
	Seqlist<int> List = Seqlist<int>(A, N);
	cout<<"A[0]和A[N]为：";
	cout<< List.Find(0) << " "; // 控制台输出最大值
	List.Insert(N-1,123);
	List.Delete(N-1);
	cout<< List.Find(N-1)<< " ";// 控制台输出次大值 
	cout<<endl;
	getch(); 
	return 0;
}
