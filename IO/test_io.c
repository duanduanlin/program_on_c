#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define PWDLEN 20

void test_scanf();
void getpwd(char *pwd, int pwdlen);
void test_pwd_get();

int main()
{
	//test_scanf();
	test_pwd_get();
	return 0;	
}

/*
	测试scanf输入函数 ,scanf是行缓存的，匹配失败的数据会留在缓存中。 
*/
void test_scanf()
{
	int a,b,c;
	printf("\r\ntest_scanf\r\n");
	printf("please input(a,b,c):");
	scanf("%d,%d,%d",&a,&b,&c);
	printf("a=%d,b=%d,c=%d\r\n",a,b,c);
	
}

void test_pwd_get()
{
	char pwd[PWDLEN+1];
    printf("Input password: ");
    getpwd(pwd, PWDLEN);
    printf("The password is: %s\n", pwd);
}

/**
* 获取用户输入的密码
* @param  pwd     char*  保存密码的内存的首地址
* @param  pwdlen  int    密码的最大长度
**/
void getpwd(char *pwd, int pwdlen){
    char ch = 0;
    int i = 0;
    while(i<pwdlen){
        ch = getch();
        if(ch == '\r'){  //回车结束输入
            printf("\n");
            break;
        }
       
        if(ch=='\b' && i>0){  //按下删除键
            i--;
            printf("\b \b");
        }else if(isprint(ch)){  //输入可打印字符
            pwd[i] = ch;
            printf("*");
            i++;
        }
    }
    pwd[i] = 0;
}
