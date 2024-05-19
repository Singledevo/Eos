#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
int ret, signal_number, pid;
printf("Enter the pid: ");
scanf("%d",&pid);
printf("Enter the signal number: ");
scanf("%d",&signal_number);

ret= kill(pid , signal_number);
if(ret==0)
{
printf("show process id : %d signal numnber:%d\n",pid,signal_number);
}
else
{
perror("failed to send process");
_exit(1);
}
return 0;

}
