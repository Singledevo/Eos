#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/msg.h>

#define MQ_KEY 0x1234


typedef struct mg{
long type;
int x;
int y;
}mg_t;


typedef struct mgs{
long type;
int z;

}mgs_t;


int main()
{ 
int mqid,ret,s,result;
//create message queue

mqid=msgget(MQ_KEY,IPC_CREAT|0600);
if(mqid<0)
{
perror("msgget() failed");
_exit(1);
}

//create child

ret =fork();
if(ret==0)
{
//child process
mg_t m1;
m1.type=1;
printf("Enter the numbers: ");
scanf("%d %d",&m1.x,&m1.y);


//child message send

ret = msgsnd(mqid,&m1,(sizeof(int)*2),0);
//ret =msgsnd(mqid,&m1,sizeof(m1.y),0);

printf("message send from child: %d \n",ret);

//message received from parent 
mgs_t m4;
ret = msgrcv(mqid,&m4,sizeof(m4.z),2,0 );

//print the result 
printf("addition of two number is: %d\n",m4.z);
}
else
{

//parent process
mg_t m2;
printf("Waiting for messsage....\n");
//receving messsage from child

ret =msgrcv(mqid,&m2,(sizeof(int)*2),1,0);
//ret =msgrcv(mqid,&m2,sizeof(m2.y),1,0);

//operation
int x= m2.x;
int y=m2.y;
int z=(x+y);
//send message to child after calculating
mgs_t m3;
m3.type=2;

m3.z=z;
ret = msgsnd(mqid,&m3,sizeof(m3.z),0);
printf("result send by parent after calculating: %d\n",m3.z);
}
return 0;
}
