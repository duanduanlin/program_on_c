#include <stdio.h>
#include <wchar.h> 
#include "string.h"
 
void test_float();
void get_float_size();
void get_int_size();
void test_memory();
void test_str();
void test_wchar();
void test_incr(); 
 
int main()
{
	printf("hello world\r\n");
	
	get_float_size();
	test_float();
	get_int_size();
	test_memory();
	test_str();
	test_wchar();
	test_incr();
	
	return 0;
}

/*
	测试小数的两种标示方法，十进制点分格式a.b;以及指数形式aen或aEn; 
*/
void test_float()
{
	printf("\r\ntest_float\r\n");
	float a = 3.14;
	float b = 3.14e-1;
	
	printf("test_float:a = %f,b = %f\r\n",a,b);
}

/*
	测试float和double的大小 ,小数长度固定。float为4，double为8； 
*/
void get_float_size()
{
	printf("\r\nget_float_size\r\n");
	float a = 3.14;
	double b = a;
	
	printf("get_float_size: sizeof float a = %d, sizeof double b = %d\r\n",sizeof a,sizeof b); 
}

/*
	测试int和long的大小 ,int和long一般为4，long long为8； 
*/
void get_int_size()
{
	printf("\r\nget_int_size\r\n");
	int a = 123456;
	long b = a;
	long long c = b; 
	
	printf("get_int_size: sizeof int a = %d, sizeof long b = %d,sizeof long long c = %d\r\n",sizeof a,sizeof b,sizeof c); 
}

/*
	测试数据的存储 ，结构体的首元素的地址即为次结构体的地址，内存小端排列 ,位域没法取地址。 
*/
void test_memory()
{
	printf("\r\ntest_memory\r\n");
	typedef struct
	{
		int a;	//低位，低地址 
		int b;
		int c;	//高位，高地址 
	}strut; 
	
	strut a;
	
	typedef struct
	{
		unsigned char low:4;	//低四位 
		unsigned char height:4;	//高四位 
	}strut_bits; 
	
	unsigned char c = 0xa5; 
	strut_bits *b = (strut_bits*)&c;
	
	printf("addr a:%#x a.a:%#x,a.b:%#x,a.c:%#x\r\n",&a,&a.a,&a.b,&a.c);
	printf("b:%#x,b.low:%#x,b.height:%#x\r\n",c,b->low,b->height);
	//printf("addr b:%#x,b->low:%#x,b->height:%#x\r\n",b,&b->low,&b->height);
}

/*
	测试字符串的存储 ,数组或指针，数组可以改变，指针不行，因为指针指向的是常量。 
*/
void test_str()
{
	printf("\r\ntest_str\r\n");
	char str1[] = "hello world";
	char *pstr = "hello ddl";
	
	printf("str1:%s,pstr:%s\r\n",str1,pstr);
	str1[0] = 'd';
	//pstr[0] = 'd'; 
	printf("str1:%s,pstr:%s\r\n",str1,pstr);
 } 
 
 /*
 	测试宽字符 ,编译器好像默认支持宽字符，以两个字节存储 ;此外可以使用L把短字符转为宽字符 
 */
 void test_wchar()
 {
 	printf("\r\ntest_wchar\r\n");
 	char str1[] = "中国";
	printf("str1:%s, len:%d\r\n",str1,strlen(str1));
	
	char str2[] = "中国abc";
	printf("str2:%s,len:%d\r\n",str2,strlen(str2)); 
	
	//char str3[] = L"中国abc"; //这是非法的
	wchar_t  str3[] = L"abc";
	printf("str3:%s,%ls\r\n",str3,str3); //这样输出的字符是a,因为a后面是'0'
	wprintf(L"str3:%s\r\n",str3); 
}

/*
	测试自增和自减 ,printf函数，好像是等表达式的值计算完毕后才会组成字符串。 
*/ 
void test_incr()
{
	printf("\r\ntest_incr\r\n");
	int a = 5;
	int b = 5;
	
	printf("a:%d,a++:%d,b:%d,++b:%d",a,a++,b,++b);	//结果：a:6,a++:5,b:6,++b:6 
} 
