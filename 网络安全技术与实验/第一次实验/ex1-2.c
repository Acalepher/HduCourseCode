#include<stdio.h>
void getFlag()
{
	printf("flag is here\n");
}
void foo(int num)
{
	int result;
	char s;
	gets(&s);
	result = puts(&s);
	if(num == 0x61616161)
	{
		getFlag();
	}
	else{
		puts("wrong flag");
	}
}
int main()
{
	setbuf(stdin, 0);
	setbuf(stdout, 0);
	setbuf(stderr, 0);
	puts("so, can u find flag?");
	foo(0x12345678);
	return 0;
}