#include <stdio.h>

char* str_source = "FishC";

void string_reverse(char* str, int len) {
	if(len<0) {
		printf("\n");
		return;
	}
	printf("%c", str[len]);
	return string_reverse(str, len-1);
}

void print() {
	char a;
	scanf("%c", &a);
	if(a!='#') print();
	if(a!='#') printf("%c", a);
}

/***************************************
输入A    输入B    输入C    输入#
  ↓    ↗   ↓    ↗   ↓    ↗   ↓
print()  print()  print()  a=='#'
  ↓    ↖   ↓    ↖   ↓    ↖   ↓
输出A    输出B    输出C    a=='#'
***************************************/

int main()
{
	//string_reverse(str_source, 4);
	print();//"FishC#"
	return 0;
}
