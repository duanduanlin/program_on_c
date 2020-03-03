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
	����С�������ֱ�ʾ������ʮ���Ƶ�ָ�ʽa.b;�Լ�ָ����ʽaen��aEn; 
*/
void test_float()
{
	printf("\r\ntest_float\r\n");
	float a = 3.14;
	float b = 3.14e-1;
	
	printf("test_float:a = %f,b = %f\r\n",a,b);
}

/*
	����float��double�Ĵ�С ,С�����ȹ̶���floatΪ4��doubleΪ8�� 
*/
void get_float_size()
{
	printf("\r\nget_float_size\r\n");
	float a = 3.14;
	double b = a;
	
	printf("get_float_size: sizeof float a = %d, sizeof double b = %d\r\n",sizeof a,sizeof b); 
}

/*
	����int��long�Ĵ�С ,int��longһ��Ϊ4��long longΪ8�� 
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
	�������ݵĴ洢 ���ṹ�����Ԫ�صĵ�ַ��Ϊ�νṹ��ĵ�ַ���ڴ�С������ ,λ��û��ȡ��ַ�� 
*/
void test_memory()
{
	printf("\r\ntest_memory\r\n");
	typedef struct
	{
		int a;	//��λ���͵�ַ 
		int b;
		int c;	//��λ���ߵ�ַ 
	}strut; 
	
	strut a;
	
	typedef struct
	{
		unsigned char low:4;	//����λ 
		unsigned char height:4;	//����λ 
	}strut_bits; 
	
	unsigned char c = 0xa5; 
	strut_bits *b = (strut_bits*)&c;
	
	printf("addr a:%#x a.a:%#x,a.b:%#x,a.c:%#x\r\n",&a,&a.a,&a.b,&a.c);
	printf("b:%#x,b.low:%#x,b.height:%#x\r\n",c,b->low,b->height);
	//printf("addr b:%#x,b->low:%#x,b->height:%#x\r\n",b,&b->low,&b->height);
}

/*
	�����ַ����Ĵ洢 ,�����ָ�룬������Ըı䣬ָ�벻�У���Ϊָ��ָ����ǳ����� 
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
 	���Կ��ַ� ,����������Ĭ��֧�ֿ��ַ����������ֽڴ洢 ;�������ʹ��L�Ѷ��ַ�תΪ���ַ� 
 */
 void test_wchar()
 {
 	printf("\r\ntest_wchar\r\n");
 	char str1[] = "�й�";
	printf("str1:%s, len:%d\r\n",str1,strlen(str1));
	
	char str2[] = "�й�abc";
	printf("str2:%s,len:%d\r\n",str2,strlen(str2)); 
	
	//char str3[] = L"�й�abc"; //���ǷǷ���
	wchar_t  str3[] = L"abc";
	printf("str3:%s,%ls\r\n",str3,str3); //����������ַ���a,��Ϊa������'0'
	wprintf(L"str3:%s\r\n",str3); 
}

/*
	�����������Լ� ,printf�����������ǵȱ��ʽ��ֵ������Ϻ�Ż�����ַ����� 
*/ 
void test_incr()
{
	printf("\r\ntest_incr\r\n");
	int a = 5;
	int b = 5;
	
	printf("a:%d,a++:%d,b:%d,++b:%d",a,a++,b,++b);	//�����a:6,a++:5,b:6,++b:6 
} 
