/*汉诺塔问题
x y z三个柱子，将x上的63个盘子，移动到z上，保证小盘在上，大盘在下
拆分
问题一: 将x上的63个盘子借助z移动到y上
	--1.前62个盘子移动到z
	--2.第63移动到y
	--3.将z上的62个盘子移动到y上
问题二: 将y上的63个盘子借助x移动到z上
	--1.前62个盘子移动到x
	--2.第63移动到z
	--3.将x上的62个盘子移动到z上
经过这个思路，进一步拆分，问题一和问题二各自还有下一步，问题的尽头就变成了3个盘子
*/

#include <stdio.h>

//将n个盘子从x借助y移动到z
void move(int n, char x, char y, char z) {
	if(n==1) {
		printf("%c-->%c\n", x, z);
	} else {
		move(n-1, x, z, y);//将n-1个盘子从x借助z移动到y上
		printf("%c-->%c\n", x, z);//将第n个盘子从x移动到z上
		move(n-1, y, x, z);//将n-1个盘子从y借助x移动到z上
	}
}

int main()
{
	int n;
	printf("请输入汉诺塔的层数:");
	scanf("%d", &n);
	printf("移动的步骤如下:\n");
	move(n, 'X', 'Y', 'Z');
	return 1;
}
