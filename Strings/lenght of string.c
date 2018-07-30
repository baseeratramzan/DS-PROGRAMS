#include<stdio.h>
int main()
{

	int i,count,flag=0,stsize=0;
	char str[10];
	printf("enter a string ");

	scanf("%s",&str);
	printf("the string is=%s\n",str);
	i=0;
	while(str[i]!='\0')
	{
		count++;
		i++;
	}
	printf("length of string=%d",count);
}
