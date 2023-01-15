#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

void print(int a)
{
	printf("%d\n",a);
}

char* myStrcpy(char *des,const char *src)
{
	char *p = des;
	while(*des++ = *src++);
	ptrdiff_t dist = des - p;//返回拷贝的字节数
	printf("%td\n",dist);//6
	return p;
}

int mystrcmp(const char* s1,const char* s2)
{
	int val;
	while(((val = *s1 - *s2) == 0) && *s1++ && *s2++);
	return val;

}
int mystrncmp(const char* s1,const char* s2,size_t n)
{
	int val;
	int i = 0;
	while(((val = *s1 - *s2) == 0) && *s1++ && *s2++)
	{
		if(++i >= n)
			break;
	}

	return val;

}

int main(void)
{
	/*
	printf("%-5d",2313);
	printf("haha\n");
	printf("%11f\n",123.45);
	printf("%+d\n",12);
	printf("%+d\n",-12);
	printf("%-6.3fhaha\n",0.5);
	printf("%*.*f\n",-6,3,0.5);
	printf("%.8s\n","hello world");
	
	float x1 = 6.0 / 4;
	printf("%f\n",x1);

	int score = 5;
	score = (score / 20.0)*100;
	printf("%d\n",score);
	printf("%d\n",-11%5);
	int i = 42;
	int j;
	j = (i++ + 10);
	printf("i=%d,j=%d\n",i,j);
	j = (++i + 10);
	printf("i=%d,j=%d\n",i,j);
	int b = 0x01;
	printf("%x\n",~b);
	int c = 0x80;
	c <<= 2;
	printf("%x\n",c);
	
	int num = 5;
	if(num > 6)
	{
		if(num < 12)
			printf("more than 6,but less than 12\n");
	}
	else
	{
		printf("wrong number\n");
	}

	int m,n;
	for(m = 0,n = 999;m < 10; m++,n--)
	{
		printf("%d,%d\n",m,n);
	}
	int ba = 012;
	printf("012 = %d\n",ba);
	

	int x = 100;
	printf("dec=%d\n",x);
	printf("octal = %o\n",x);
	printf("hex = %x\n",x);
	printf("octal = %#o\n",x);
	printf("hex = %#x\n",x);
	printf("hex = %#X\n",x);
	
	if(0.1 + 0.2 == 0.3)
	{
		printf("ok\n");
	}
	else
	{
		printf("errof\n");
	}
	double f1 = 123.456e+4;
	double f2 = 123.456e3;
	double f3 = 0.3E6;
	double f4 = .3E6;
	double f5 = 3.0E6;
	double f6 = 3.E6;
	printf("f1=%f\n",f1);
	printf("f2=%f\n",f2);
	printf("f3=%f\n",f3);
	printf("f4=%f\n",f4);
	printf("f5=%f\n",f5);
	printf("f6=%f\n",f6);
	printf("%zd\n",sizeof(int));
	unsigned int ui = UINT_MAX;
	ui++;
	printf("ui = %u\n",ui);
	ui--;
	printf("ui = %u\n",ui);
	signed char sc = SCHAR_MIN;
	printf("sc=%d\n",sc);
	unsigned char uc = UCHAR_MAX;
	printf("uc=%d\n",uc);
	size_t se = sizeof(int);
	printf("int size = %zu\n",se);
	int32_t x32 = 4556655;
	printf("x32 = %d\n",x32);
	int in = 3.14;
	printf("in=%d\n",in);
	float fl = 12 * 2;
	printf("fl = %f\n",fl);
	char cc = 10;
	printf("size = %zu\n",sizeof(cc));
	int ii = cc - 500;
	printf("ii = %d\n",ii);
	
	int ku = 321;
	char zi = ku;
	printf("%d\n",zi);
	printf("zzf = %f\n",3+1.2);
	int ww = -5;
	if(ww < sizeof(int))
		printf("dosomthing\n");
	else
		printf("error\n");

	unsigned char aaa = 1;
	unsigned char bbb = 255;
	unsigned char ccc = 255;
	if(aaa-5 < 0)
		printf("dosomthinga5\n");
	if(bbb+ccc>300)
		printf("dosomthingbc\n");

	int*p;
	int test;
	p = &test;
	*p = 8;
	printf("test=%d\n",test);

	int *p1;
	p1 = (int*)0x1234;
	p1 += 1;
	printf("p1 = %p\n",p1);
	p1--;
	--p1;
	
	printf("p1 = %p\n",p1);
	short *j1,*j2;
	j1 = (short*)0x1234;
	j2 = (short*)0x1236;

	ptrdiff_t dist = j2 - j1;
	printf("%td\n",dist);

	int val = 999;
	
	void (*print_ptr)(int) = &print;
	print(val);
	(*print_ptr)(10);
	(*print)(10);
	(&print)(10);
	print_ptr(10);
	int a[5];
	for(int k=0;k<5;k++)
	  printf("array = %d\n",a[k]);
	int ar[] = {22,37,345};
	int arrLen = sizeof(ar);
	printf("arrLen=%d\n",arrLen);

	char *str = "hello world";
	printf("str's len=%zd\n",strlen(str));

	printf("str's is %zd\n",sizeof(str));//error
        char str11[10] = "hello";
	printf("str11 strlen=%zd\n",strlen(str11));
	printf("str11 sizeof=%zd\n",sizeof(str11));
	char chara[] = {"china"};
	printf("%s\n",chara);

	printf("hello\n");
	int a;
	char b;
	if(b='0')
	{
		printf("yes\n");
	}
	else
		printf("no\n");
	printf("b=%d\n",b);
	char arr[] = "hello";
	myStrcpy(arr,"world");
	printf("%s\n",arr);

*/
	char *s1 = "Happy New Year";
	char *s2 = "Happy New ";
	char *s3 = "Happy Iolidays ";
	printf("s1,s2=%d\n",strncmp(s1,s2,11));
	printf("s1,s3=%d\n",strncmp(s1,s3,9));
	printf("s3,s1=%d\n",strncmp(s3,s1,5));

	if(0 == '\0')
	{
		printf("yes\n");
	}
	else
		printf("no\n");

	//数据溢出的例子
	char *first = "hello";
	char *last = "world";
	char s[10];
	int a = snprintf(s,7,"%s %s",first,last);
	printf("len=%d,%s\n",a,s);
	//*** stack smashing detected ***: terminated
        //Aborted (core dumped)

	return 0;

}
