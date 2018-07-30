#include<stdio.h>
#include<conio.h>
int main()
{
	int i,count;
	char str[10];
	printf("enter a string in lower case");

	scanf("%s",&str);
	printf("the string is=%s\n",str);
	i=0;
	while(str[i]!='\0')
	{
		count++;
		i++;
	}
	printf("count=%d\n",count);
	
	for(i=0;i<count;i++)
	{
 printf("character is=%c\n",str[i]);
		str[i]=str[i]-32;
	}
	
	
printf("\nfinal:%s\n",str);
return 0;
}
