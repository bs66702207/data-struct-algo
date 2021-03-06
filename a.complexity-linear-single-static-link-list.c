// data-struct-algo
数据结构是给人看的，所以起始位置是1

//时间复杂度和空间复杂度
	间复杂度，用大O来表示，多数情况下，一般的循环容易计算出时间复杂度，注意常数项统一成O(1)，这里列举两个例子让你理解如何计算时间复杂度。
for(i=0; i<n; i++)
	for(j=i;j<n;j++)
	上面的程序，当i=0时，内循环n次；当i=1时，内循环n-1次，。。。，当i=n-1时，内循环1次，那么他们之和就是n+(n-1)+(n-2)+...+1=n(n+1)/2，所以时间复杂度等于O(n^2)。
	通过上面的例子知道了，时间复杂度的计算方法是如何计算出该程序的运行次数，并且取最高项。再看一个程序：
int i=0, n=100;
while(i<n) {
	i = i*2;
}
	上面的程序，需要进行x个2相乘才可以推出循环，也就是2^x=n，那么x=log2n，时间复杂度O(logn)

	常用的时间复杂度所耗费的时间从小到大依次是：O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)
	空间复杂度，S(n)=O(f(n))，f(n)为语句关于n所占存储空间的函数，一般情况让我们求“复杂度”是指时间复杂度。
	列举一个关于时间复杂度和空间复杂度的例子，要判断某年是不是闰年，你可能会花一点心思来写一个算法，每给一个年份，就可以通过这个算法计算得到是否闰年的结果。
	另外一种方法是，事先建立一个有2050个元素的数组，然后把所有的年份按下标的数字对应，如果是闰年，则此数组元素的值是1，如果不是元素的值则为0。
	第一种方法节省空间，但是每次输入年份的时候需要进行算法计算；第二种方法节省时间，但是内存中会被2050个元素数组占用。

//线性表List
	零个或者多个数据元素组成的有限序列，第一个无前驱，最后一个无后继。
	若将线性表记为（a1,…,ai-1,ai,ai+1,…an）,则表中ai-1领先于ai,ai领先于ai+1,称ai-1是ai的直接前驱元素,ai+1是ai的直接后继元素。
	1.线性表的顺序存储结构，在存、读数据时，时间复杂度是O(1)，在插入和删除非末尾数据时，时间复杂度是O(n)。它适合元素个数比较稳定，不经常插入和删除元素，而更多的操作是存取数据的应用。
	2.单链表(head|phead) -> (a1|p1) -> (a2|p2)-> ... -> (an|null)。其优势在于，如果顺序多次插入或者删除数据，可以获取链表i的位置，然后直接插入，或者删除。
	小结: 
		--查找 顺序存储O(1); 单链表O(n)
		--插入和删除 顺序存储O(n); 单链表在确定某位置指针后为O(1)
		--空间性能 顺序存储结构, 需要合理进行预分配空间; 不需要预分配，元素个数不受限制
		==综上，频繁查找适合线性存储, 频繁插入删除适合单链表
	3.静态链表，第一个和最后一个元素不存放数据， 最后一个游标保存的是第一个存放数据的下标, 第一个游标保存的是第一个没有存放有数据的下标, 剩下的游标都是依次保存下一个元素的下标, 到数据E的游标保存的是0
	  | 游标 | 5 | 2 | 3 | 4 | 0 | 6 | 7 | ... | 1 |
	  | 数据 |   | A | C | D | E |   |   | ... |   |
	  | 下标 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | ... |999|

	3.1在数据A后面插入B，

	  第一步给出一个空间，x游标保存的数值5, 访问到y后变为6, 用变量j记住添加数据B的下标5
	           x                   y
	  | 游标 | 6 | 2 | 3 | 4 | 0 | 6 | 7 | ... | 1 |
	  | 数据 |   | A | C | D | E |   |   | ... |   |
	  | 下标 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | ... |999|

	  第二步x保存5, y保存2
               x                   y
	  | 游标 | 6 | 5 | 3 | 4 | 0 | 2 | 7 | ... | 1 |
	  | 数据 |   | A | C | D | E | B |   | ... |   |
	  | 下标 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | ... |999|

	3.2C觉得不爽，走了，删除C的操作，
               x       z           y
	  | 游标 | 2 | 5 | 6 | 4 | 0 | 3 | 7 | ... | 1 |
	  | 数据 |   | A |   | D | E | B |   | ... |   |
	  | 下标 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | ... |999|
	小结:
		-- 静态链表, 优点: 插入和删除时，只需要修改游标，不需要移动元素, 从而改进了顺序存储结构中插入和删除操作需要移动大量元素的缺点
		-- 静态链表, 缺点: 没有解决连续存储分配(数组)带来的表长难以确定的问题, 失去了顺序存储结构随即存取的特性
	    总的来说, 静态链表其实是为了给没有指针的编程语言设计的一种实现单链表功能的方法。要理解思想，以备不时之需。
//面试题 快速找到未知长度单链表的中间节点
	普通方法: 遍历一遍单链表，确定其长度L，然后从头节点出发循环L/2,找到中间节点，算法复杂度O(L+L/2)
	高级方法：快慢指针，*search和*mid，search的移动速度是mid的两倍，当search指向末尾节点的时候，mid正好就在中间了，标尺的思想
GetMidNode(LinkList L, ElemType *e)
{
	LinkList search, mid;
	mid = search = L;
	while(search->next != NULL) {
		if(search->next->next != NULL) {
			search = search->next->next;
			mid = mid->next;
		} else {
			search = search->next;
		}
	}

	*e = mid->data;
	return OK;
}
