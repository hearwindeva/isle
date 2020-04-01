#include <iostream>
#include <algorithm>
#include <conio.h> 

#define N 10
using namespace std;

//堆的实现 
template <typename Item>
class MaxHeap
{
	private:
		Item* data; // 堆数据存放
		int count; // 堆目前所含数据量大小
		int capacity; // 堆容量大小

		void shift_up(int k)
		{
			Item new_item = this->data[k]; // 保存新插入的值
//      如果新插入的值比父节点的值小, 则父节点的值下移, 依次类推, 直到到达根节点或者满足最大堆定义
			while( k > 1 && this->data[k/2] < new_item )
				{
					this->data[k] = this->data[k/2];
					k /= 2;
				}
			this->data[k] = new_item; // k就是 新插入元素 应该在堆中的位置
		}

		void shift_down(int k)
		{
			Item root = this->data[1];
//        在完全二叉树中判断是否有左孩子即可
			while(2*k <= this->count)
				{
					int j = k + k;
//            如果有右子节点，并且右节点 > 左边点
					if( j + 1 <= this->count && this->data[j + 1] > this->data[j])
						{
							j += 1;
						}
//            root找到了堆中正确位置 k 满足堆性质, 跳出循环
					if(root >= this->data[j])
						{
							break;
						}
					this->data[k] = this->data[j];
					k = j;
				}
			this->data[k] = root;
		}
	public:
		MaxHeap(int capacity)
		{
			this->data = new Item[capacity + 1]; // 堆中数据从索引为1的位置开始存储
			this->count = 0;
			this->capacity = capacity;
		}
//    将数组构造成堆：heapify
		MaxHeap(Item arr[], int n)
		{
			this->data = new Item[n+1];
			this->capacity = n;
			this->count = n;
			for(int i = 0; i < n; i++)
				{
					this->data[i + 1] = arr[i];
				}
			for(int i = n/2; i >= 1; i--)
				{
					this->shift_down(i);
				}
		}
		~MaxHeap()
		{
			delete[] this->data;
		}
//    返回堆中元素个数
		int size()
		{
			return this->count;
		}
//    返回布尔值：堆中是否为空
		bool is_empty()
		{
			return this->count == 0;
		}

//    向堆中插入元素
		void insert(Item item)
		{
			// 堆空间已满, 开辟新的堆空间.
			// 按照惯例，容量扩大到原来的2倍
			if(this->count >= this->capacity)
				{
					this->capacity = this->capacity + this->capacity; // 容量变成2倍
					Item* more_data = new Item[this->capacity + 1]; // data[0] 不存放任何元素
					copy(this->data, this->data + this->count + 1, more_data); // 将原先 data 中的有效数据拷贝到 more_data 中
					delete[] this->data;
					this->data = more_data;
				}
			this->data[this->count + 1] = item; // 插入堆尾部
			this->shift_up(this->count + 1); // 执行 shift_up，将新插入的元素移动到应该在的位置
			this->count ++;
		}

//    取出最大值
		Item extract_max()
		{
			Item ret = this->data[1]; // 取出根节点
			swap(this->data[1], this->data[this->count]); // 将根节点元素和最后元素交换
			this->count --; // 删除最后一个元素
			this->shift_down(1); // shift_down 将元素放到应该在的位置
			return ret;
		}
};

//主函数测试 
int main()
{
	int A[N]= {1,7,50,42,19,81,2,94,15,46};
	MaxHeap<int> max_heap = MaxHeap<int>(A, N);
	cout<<"最大值和次大值为：";
	cout<< max_heap.extract_max() << " "; // 控制台输出最大值
	cout<< max_heap.extract_max() << " ";// 控制台输出次大值 
	cout<<endl;
	getch(); 
	return 0;
}
