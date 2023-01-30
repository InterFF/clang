this is a test that learn clang.  
notes on learning [c语言教程](https://wangdoc.com/clang)  
this is haha.  
this is a test.  
this is a tes from co  
this is a tes from co  
this is a tes from co haha   
 




## about linux
### 修改权限的例子：
1. 将档案file1.txt 和 file2.txt设定为该档案拥有者与其他所属同一个群体者可写入，但其他人则不可写
```shell
chmod ug+w,o-w file1.txt file2.txt
```

2. 将当前目录下的所有档案与子目录皆设为任何人可读取
```shell
chmod -R a+r *

-R:对目前目录下的所有档案与子目录进行相同的权限变更（即以递归的方式）
```
## about vim
### 默认配置修改
1.find `$HOME & $VIM`,在 *vim*编辑器中使用以下命令
```vi
:echo $VIM //此目录下的vimrc文件为全局配置文件，修改它全局生效，需要root权限
:echo $HOME//此目录下vimrc文件为用户配置文件，如果不存在，创建一个.vimrc,修改它，仅仅当前用户生效
```

2. 配置用户配置文件模板
```shell
$ vim ~/.vimrc
```
3. 编辑示例
```md
"这里是注释，双引号代表注释
set num  "设置显示行号
```

## intro
### ready
C语言是一种编译型语言，源码都是文本文件，本身无法运行。必须通过编译器，生成二进制的可执行文件，
才能执行。编译器将代码从文本文件翻译成二进制指令的过程，就成为编译阶段，又成为“编译时（compile time）”
跟运行阶段，又成为运行时（runtime）区分开。最常用的编译器就是GCC编译器，开源且免费，全平台运行。
首次使用，安装gcc编译环境
```shell
非root用户
$ sudo apt install gcc
```
### go
用C写一个hello world程序
first,create c source file
```shell
$ vim hello.c
```
secode,write program.
```c
#include <stdio.h>

int main(void)
{
	printf("hello world!\n");
	return 0;
}
```
third. compile c source file

```shell
$ gcc hello.c

gen a.out file

or -o filename
$ gcc -o hello hello.c

or -std c99 mode
$ gcc -std=c99 -o hello hello.c
```

last. run it
```shell
$ ./hello
hello world
```
## syntax
### 语句
代码就是由语句组成的，C语言规定语句必须使用分号结尾。
```c
int x = 1;
```
也可以些成4行：
```c
int
x
=
1
;
```
### 表达式
就是一个计算公式，用来获取值的,例如：
```c
1+2
````
表达式通常都有返回值。


### 语句块
多个语句使用一对大括号{}组成一个语句块，也称为复合语句。例如：
```c
{

int x;
x = 1;
}
```

*注意* 大括号的结尾不需要添加分号


### 可有可无的东西
- 空格不是必须的(看情况)
- 换行不是必须的
- 注释不是必须的


### 格式化输出函数
#### 限定宽度
```c
// 占位符最小宽度至少为5位，不足，左侧补空格
printf("%5d\n",123); //输出 “  123”

//右补零，左对齐
printf("%-5d\n",123); //输出 “123  ”

//浮点数输出，默认显示精度小数点后6位
printf("%12f\n",123.45);//输出 “  123.450000”
```

#### 总显示正负号
默认情况下，不显示`+`号，可以在占位符`%`后面加`+`
```c
printf("%+d\n",12); //输出"+12"
printf("%+d\n",-12);//输出“-12”
```
#### 限定小数位数
```c
//小数点后2位
printf("%.2f\n",0.5);//输出 “0.50”

//最小宽度和小数点位数同时限制
printf("%6.3f\n",0.5);//输出 “ 0.500”

//同上写法
printf("%*.*f\n",6,3,0.5); //输出 “ 0.500”
```

#### 输出部分字符串
```c
printf("%.5s\n","hello world");//输出hello
```
## variable
### 变量名

变量可以理解为一块内存区域的名字，通过变量名，可以引用这块内存区域，获取里面的值。

由于值可能发生变化，所以称变量。
变量由严格的命名规范

```
+ 只能包含字母（区分大小写），数字和下划线(_)
+ 不能以数字开头
+ 不能超过63个字符
+ 关键字不能作为变量名
```

一般地，两个下划线开头或者一个下划线开头+大写英文字母的都是系统保留的，我们不用起这样的变量名

变量必须声明才能用，否则报错。声明的变量必须赋值，否则会是一个随机值。
### 多个变量也可以同时赋值
```c
int x,y,z,m,n;
x = y = z = m = n = 3;

```

## ooperator
### 算术运算
`+,-,*,/,%`
例子1：
```c
float x = 6 / 4;
printf("%f\n",x);//输出1.000000

//如果希望得到浮点数，两个运算至少有一个是浮点数
float x = 6.0 / 4;
or 
float x = 6 / 4.0;

printf("%f\n",x);
```

例子2：
```c
int score = 5;
score = (sore / 20) * 100;//输出 0

//correct way
score = (score / 20.0)*100; 
```

例子3：
```c
//求模运算,负数的规则是计算结果的正负号由第一个运算数决定
11 % -5 // 1
-11 % -5 // -1
-11 % 5 // -1

```
### 自增,自减运算符
- `++`:自增运算符
- `--`:自减运算符
```c
// ++i,先自增，然后运算
// i++,先运算，后自增

int i = 42;
int j;

j = (i++ + 10);
printf("i=%d,j=%d\n",i,j);//输出 43，52

j = (++i + 10);
printf("i=%d,j=%d\n",i,j);// 输出44，54
```
### 位运算符
例子1：取反
```
~ 10010011 //返回01101100

```

例子2；移位
```c
0x80 << 2 //0x200
//左移相当于乘法。2的2次方，乘以4

0x80 >> 2 //0x20

```
### 逗号运算符
用于将多个表达式连在一起，从左到右依次运行每个表达式
```c
int x=10,y=20;

```
### 优先级
+ `()`
+ `++,--`
+ `+,-`一元运算
+ `*,/`
+ `+,-`
+ `<,>`
+ `=`

圆括号优先级最高，万能用法。

## flow-control
### if
```c
int num = 5;
if(num > 6)
	if(num<12)
		printf("more than 6,but less than 12.\n");
else
	printf("wrong num\n");

// 什么也不会输出，else部分匹配最近的if，所以不会输出

//正确的做法
if(num>6)
{
	if(num<12)
		printf("more than 6,but less than 12.\n");
}
else
{
	printf("wrong num\n");
}
//结果输出 “wrong num”
```
### for
每个表达式都可以有多个语句
```c
	int m,n;
	for(m = 0,n = 999;m < 10; m++,n--)
	{
		printf("%d,%d\n",m,n);
	}
```
三个表达式有时也不是必须的。
```c
for(;;)
{
	printf("本行会无限循环打印.\n");
}
```
### goto
跳到指定的标签名。这会破坏结构化编程，一般不使用。但也有好用的用法

```c
//跳出复杂的嵌套循环
for()
{
	for()
	{
		while()
		{
			do
			{
				if(some_error)
					goto bail;
			}while();
		}
	}
}

bail:

//提前结束多重判断
if(do() == err)
	goto error;
if(do2() == err)
	goto error;
if(do3() == err)
	goto error;
if(do4() == err)
	goto error;

error:
//

```
## types
c语言的一种数据都是有类型的，编译器必须知道数据的类型，才能操作数据。所谓“类型”，就是相似的数据所拥有的
共同特征，一旦直到某个值的数据类型，就能直到该值的特征和操作方式。
基本的数据类型有三种：字符(char),整数(int)和浮点数(float)。复杂的类型都是基于它们构建的。
### 字符类型
放单引号里，每一个字符都对应一个整数（由ASCII码决定）,范围`0`到 `127`
在不同点计算机中默认的范围不一样。一些系统默认`-127`到`128`,=signed char,有些默认`0`到 `255`,=unsigned char。

### 整数类型
就是`int`
```c
signed int a;
//等价
int a;

```

整数的子类型
为了更精细地限定整数的范围，不浪费空间，C语言在`int`类型之外，又提供了三个整数的子类型。
```c
一般省略signed,int .其他不能省
short int a;//等价short a
long int b;//等价long b;
long long int c;//等价long long c;
```

### 整数类型的极限值
可查看头文件 limits.h文件


### 整数的进制
```c

	int x = 100;
	printf("dec=%d\n",x);
	printf("octal = %o\n",x);
	printf("hex = %x\n",x);
	printf("octal = %#o\n",x);
	printf("hex = %#x\n",x);
	printf("hex = %#X\n",x);
```
### 浮点数

任何有小数点的数值，都会被编译器解释为浮点数。所谓“浮点数”就是使用`m*b^e`的形式，存储一个数值，m是小数部分，

b是基数(通常是2)，e是指数部分。这种形式是精度和数值范围的结合，可以表示非常大或者非常小的数。
浮点数类型有:
```c
float c = 10.5; //一般占用4字节（32bit）,至少能够提供6位有效数字
double d = 100.8; //一般占用8字节（64位），至少能够提供13位有效数字
long double e = 1000.8 //一般占用16个字节（128位）
```
由于存在精度限制，浮点数只是一个近似值，它的计算是不精确的。
```c
if(0.1 + 0.2 == 0.3) //false
```
也可以用科学计数法表示浮点数，使用字母e分割：
```c
double f1 = 123.456e+3;//123.456*10^3
//简写用法
double f2 = 123.456e4;//123.456*10^4
//等同于,使用大写E
double f2 = 123.456E4;//123.456*10^4;

printf("f1=%f\n",f1);//输出 “123456.000000”
printf("f2=%f\n",f2);//输出 “1234560.000000”
//科学计数法的小数部分如果是`0.x`或 `x.0`的形式，那么`0`可以省略。
0.3E6
//等同于
.3E6


3.0E6
//等同于
3.E6
 ```
### 字面量的类型
指的是代码里直接出现的值。
```c
int x = 123;
//x 是变量，123就是字面量
```
一般是编译器自动分配。如果希望为字面量指定不同的类型，那么可以加上字面量后缀。
常用法：
```c
//f 和 F ：float
//l 和 L : 对于整数 就是 long int ,对于小数就是long double
//ll 和 LL: long long
//u 和 U : unsigned int

//其他结合类型，u可以放在前面，也可以放后面，如10UL，10ULL,10LLU
```
### 溢出
每一种数据类型都有数值范围，如果超出这个范围，就会发生溢出，而且编译器也不会报错，
这可以说是一个致命错误。
```c
unsigned int ui = UINT_MAX;//4294967295
ui++;
printf("ui=%u\n",ui);//0
ui--;
printf("ui=%u\n",ui);//494967.295
```
常见错误：
```c
for(unsigned int i = n;i>=0;--i);//无线死循环
//正确写法
for(unsigned int i = n;i>0;--i);

```
### sizeof运算符
返回某种数据或者某个值占用的字节个数。

```c
size_t len = size(int);
printf("int size = %zd\n",len);
//or
printf("int size = %zu\n",len);
```
### 类型的自动转换
某些情况下，C语言会自动转换某个值的类型。非常可怕
#### 赋值运算
赋值运算符会自动将右边的值转成左边变量的类型
```c
//浮点数赋值给整数变量，直接丢弃小数部分。
int x = 3.14;
printf("x = %d\n");//3

//整数赋值给浮点数变量，自动转为浮点数
float y = 12 * 2;
printf("y = %f\n",y);//24.000000

// 窄类型赋值给宽类型，自动转换为宽类型
char x = 10;
int i = x + y;

// 宽类型赋值给窄类型，可能会发生截值，不可预料的后果
int i = 321;
char ch = i; // 65
```
#### 混合类型的运算
不同类型的值进行混合运算时，必须先转成同一个类型，才能计算

```c
//整数与浮点数，整转浮
3 + 1.2 //4.2

//浮点宽度不同，窄转宽，float 转 double ,double 转 long double

//整数宽度不同，窄转宽，short 转 int ,int 转 long ,long转 long long.

//特殊，最好避免。有符号转无符号
int a = -5;
if(a < sizeof(int))
	do_something();//不会执行这句话，因为a自动转无符号为4294967291

```
#### 整数类型的运算
宽度小于`int`的类型，运算结果会自动提升为`int`
```c
// 会输出dosothing两次
	unsigned char aaa = 1;
	unsigned char bbb = 255;
	unsigned char ccc = 255;
	if(aaa-5 < 0)
		printf("dosomthinga5\n");
	if(bbb+ccc>300)
		printf("dosomthingbc\n");
```


#### 函数
函数的参数和返回值，会自动转换成函数定义里的数据类型


### 类型的显示转换
也就是手动类型转换。在一个变量或数值面前使用圆括号指定类型（type）就行了。
```c
int a = (int) ch;

``` 
### 可移植类型
c语言的整数类型（short,int ,long）在不同的计算机上占用的字节个数可能是不一样的，无法提前知道他们到底占用多少字节。
为了准群控制类型宽度。提高代码的可移植性，因此创造了新的类型名称。
引用`stdint.h`文件就行
包含：
- 精确宽度类型（`uint8_t` ,`int16_t`等等）
- 最小宽度类型（`int_least8_t`等等）
- 最快的最小宽度类型（`int_fast8_t`等等）
- 可以保存指针的整数类型（`intptr_t`,`uintptr_t`）
- 最大宽度整数类型（`intmax_t`,`uintmax_t`）

### pointer
指针是一个值，代表一个内存地址。相当于指向某个内存地址的路标。
```c
int* int_ptr;//一个指向int类型的指针
char * char_ptr;//一个指向字符的指针
float *float_ptr;//一个指向浮点数的指针
double*dou_ptr;//一个指向double类型的指针
```
可以理解为指针就是一个普通的变量，只不过它的值是内存地址而已。

#### 取值
取出指针指向的内存地址中的值
```c

//自增运算
void increment(int *p)
{
	*p = *p + 1;
}

```

#### 取地址
取出一个变量所在的内存地址
```c
int x = 1;
printf("x's address is %p\n",&x);

//& 和 * 互为逆运算
int i = 5;
if(i == *(&i))//正确的
```

#### 初始化

```c
int *p;
*p = 1;//错误

//p没有初始化，指向的地址是随机的
//正确的做法
int *p;
int i;

p = &i;
*p = 1;
```
为了防止读写未初始化的指针变量，统一：
```c
int *p = NULL;
//NULL 在C语言中是一个常量，表示地址为0的内存空间，这个地址是无法使用的，读写会报错
```
#### 指针的运算
指针本质上就是一个无符号整数，代表了内存地址。它可以进行运算，但规则并不同与整数运算

```c
//指针与整数的加减运算，表示指针的移动
short *j;
j = (short*)0x1234;
j = j + 1;//0x1236,代表指针内存地址的高位移动一个单位，而一个单位short类型占据两个字节的宽度，所以相当于
//向高位移动2个字节。
指针移动的单位，与指针指向的数据类型有关。数据类型占用多少字节，每个单位就移动多少字节。


//指针与指针的加法运算是非法的

//指针与指针的减法运算，返回他们之间的距离，即相隔多少个数据单位。
高位减去低位地址，返回正值，反之，返回负值
short *j1,*j2;
j1 = (short*)0x1234;
j2 = (short*)0x1236;

ptrdiff_t dist = j2 - j1;
printf("%td\n",dist);

//指针与指针的比较运算，比较的是那个内存地址大，返回的是1或0

```
### function
任何一个函数，都有五种调用函数的写法


#### 函数原型
告诉编译器每个函数的返回值类型和参数类型，其他的都不需要，也不用包含函数体。可以后补。
```c
int twice(int);
//等同于
int twice(int a);

```

#### 函数说明符
extern 说明该函数的定义来自其他文件。不过函数原型默认就是`extern`，因此，也可以省略
```c
extern int foo(int a,int b);
//等同于
int foo(int a,int a);

```

static只初始化一次，在两次调用之间保持不变
只能赋值位常量，不能赋值为变量
修饰函数本身，表明这个函数不能被其他文件调用
放参数里面，修饰数组，告诉编译器数组长度，不会对程序产生影响


const表示函数内部不能修改参数的变量

```c
//同时限制*p和p不能被修改
void f(const int* const p)
{

}
```
## array
```c
int scores[100];
scores[100] = 51;
//上面示例中，数组scores只是100个成员，因此scores[100]这个位置不存在的。但是，引用这个位置并不会报错，会正常运行。
使得紧跟在scores后面的那块内存区域被赋值，而那实际上是其他变量的区域，因此不知不觉就改变了其他变量的值。这很容易
引发错误，而且难以发现。
```

## string
C语言中没有string类型，如果想要表示字符串，那么就用字符型数组表示。

### 简介
```c
char str[6] = {'h','e','l','l','o','\0'};//此种声明方式，一定要结尾加`\0`代表字符串
char str[] = {'h','e','l','l','o','\0'};//此种声明方式，一定要结尾加`\0`代表字符串
char str[] = {"hello"};//不用加`\0`,编译器自动加.记住一定是双引号
char str[] = "hello";//不用加`\0`,编译器自动加.记住一定是双引号
char *str ="hello";//也可以声明成一个指针，指向数组


//多行字符串写法
char greeting[] = "hello,""how are you""today!";
//等同于
char greeting[]= “helllo,how are you today!”;
//等同于
char greeting[] = "hello,"
"how are you"
"today!";

```
字符指针和字符数组的区别
```c
//第一个区别，字符指针不能修改单个字符，而字符数组可以
char s[]="hello";
char s[0] = 'z';//可以的

char *s = "hello";
s[0] = 'z';//报错

//第二个区别，字符指针可以整个替换字符串的值，而字符数组不可以
char s1[] = "world";
s1 = "haha";//报错
//or
strcpy(s1,"haha");//可以的

char* s2 = "world";
s2 = "haha";//可以的
```

### 计算长度
使用strlen函数计算字符串长度，引用string.h文件
- 不包含结尾的`\0`
- 无论是字符指针还是字符数组都可以

跟sizeof区别是:
```c
char str[10] = "hello";
strlen(str) //5
sizeof(str)//10

char *s = "world";
strlen(s);//5
sizeof(s)//error

```
## memory
stack:系统管理的内存，主要是函数内部的变量,不用管，也管不着。
heap:用户管理的内存，主要是程序运行过程中存在的变量，全局变量。自己管理。

