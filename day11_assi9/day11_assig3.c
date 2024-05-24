#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<signal.h>
int arr[2];


void signal_handler(int sig)
{
printf("Signal Caught: %d\n",sig);
close(arr[1]);
close(arr[0]);
_exit(0);

}
int main()
{
char ch='A';
int count=0;
int ret,ret1;
//create pipe
ret=pipe(arr);
if(ret<0)
{
perror("pipe() failed");
_exit(1);
}

struct sigaction sa;
memset(&sa,0,sizeof(struct sigaction));
sa.sa_handler=signal_handler;
ret1= sigaction(SIGINT,&sa,NULL);
if(ret<0)
{
perror("sigaction() failed");
_exit(1);
}
while(1)
{
write(arr[1],&ch,1);
count++;
printf("bytes written: %d\n",count);
}


return 0;
}
