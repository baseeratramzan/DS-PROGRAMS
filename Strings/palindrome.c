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
	printf("count=%d,%s\n",count,str);
	i=0;
	stsize=count;
	count=count-1;
	
	printf("value of string is %c,%c\n",str[i],str[count]);
	while(count!=i)
	{

		if(str[i]==str[count])
		{
		
	     flag=flag+1;
	     
		 }
		 printf("count=%c,%c\n",str[i],str[count]);
		 i=i+1;
		 count=count-1;
	 }
  
	if(flag==(stsize/2))
	{
		printf("  a palindrome= %s\n",str);
		}
		else{
			
			printf("not a palindrome");
		}	
	
	
	
	
}
