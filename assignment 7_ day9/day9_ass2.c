#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

void sigint_handler(int sig)
{
printf("shashank\n");

}

int main()

{

signal(SIGINT, sigint_handler);

char cmd[512], *ptr, *args[32];
int i,ret,err,s;
while(1)
{
printf("cmd> ");
gets(cmd);
i=0;
ptr = strtok(cmd, " ");
args[i] =ptr;
i++;
//printf("first token: %s\n",ptr);
do{
ptr=strtok(NULL," ");
args[i]=ptr;
i++;

}while(ptr != NULL);

if(strcmp(args[0], "exit")==0)
break;
else if(strcmp(args[0], "cd")==0)
chdir(args[1]);
else{
//external command
ret =fork();
if(ret==0)
{
err = execvp(args[0],args);
if(err<0)
{
perror("bad comment");

_exit(1);
}
}
else
wait(&s);
}
}
printf("bye\n");

return 0;
}
