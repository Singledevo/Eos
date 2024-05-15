#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
int ret,s;
int i=1;
while(1)
{
ret=fork();
if(ret==-1)
{
break;
}
else if(ret==0)
{
printf("hello\n");
sleep(1);
_exit(0);
}
else
{
printf("count=%d \n",i);
i++;
}
}
for(int j=1;j<=i;j++)
{
wait(&s);
printf("cleared %d",j);
}
return 0;
}
