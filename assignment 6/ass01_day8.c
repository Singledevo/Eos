#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
 
int main()
{
int i, ret1,child_pid ,ret2,ret3, ret4, ret5,s;
ret1= fork();
if (ret1==0)
{
for (i=1; i<=5;i++)
{
printf("count : %d , pid : %d\n",i,getpid());
}
ret2 = fork();
if (ret2==0)
{
for (i=1; i<=5;i++)
{
printf("count : %d , pid : %d\n",i,getpid());
}
_exit(0);
}
ret3=fork();

if (ret3==0)
{
for (i=1; i<=5;i++)
{
printf("count : %d , pid : %d\n",i,getpid());
}
_exit(0);
}
ret4=fork();

if (ret4==0)
{
for (i=1; i<=5;i++)
{
printf("count : %d , pid : %d\n",i,getpid());
}
_exit(0);
}
ret5=fork();

if (ret5==0)
{
for (i=1; i<=5;i++)
{
printf("count : %d , pid : %d\n",i,getpid());
}
_exit(0);
}

//parent process
for(i=1;i<=5;i++)
{
child_pid=wait(&s);
}

return 0;


}
}
