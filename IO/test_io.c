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
	����scanf���뺯�� ,scanf���л���ģ�ƥ��ʧ�ܵ����ݻ����ڻ����С� 
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
* ��ȡ�û����������
* @param  pwd     char*  ����������ڴ���׵�ַ
* @param  pwdlen  int    �������󳤶�
**/
void getpwd(char *pwd, int pwdlen){
    char ch = 0;
    int i = 0;
    while(i<pwdlen){
        ch = getch();
        if(ch == '\r'){  //�س���������
            printf("\n");
            break;
        }
       
        if(ch=='\b' && i>0){  //����ɾ����
            i--;
            printf("\b \b");
        }else if(isprint(ch)){  //����ɴ�ӡ�ַ�
            pwd[i] = ch;
            printf("*");
            i++;
        }
    }
    pwd[i] = 0;
}
