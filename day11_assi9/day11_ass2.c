#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
int ret3,res,n1,n2, ret1,ret2,ret,s,x,y;
int arr1[2],arr[2];
//create pipe
ret1= pipe(arr);
ret2=pipe(arr1);
ret=fork();
if(ret==0)
{
//child process
close(arr[0]); 
close(arr1[1]);

//enter 2 numbers
printf("Enter the two numbers: ");
scanf("%d %d",&x,&y);


//writing in ppipe1
write(arr[1],&x,sizeof(x));
write(arr[1],&y,sizeof(y));

//reading data from parent (result)
read(arr1[0],&res,sizeof(res));
printf("result: %d\n",res);

close(arr1[0]);
close(arr[1]);
//close(arr1[0]);
_exit(0);
}
else
{
//parent process
close(arr[1]);
close(arr1[0]);

//reading data from child 
read(arr[0],&n1,sizeof(n1));
read(arr[0],&n2,sizeof(n2));

//operation
int z=n1+n2;

//writing result in pipe2 to children
write(arr1[1],&z,sizeof(z));


close(arr1[1]);
close(arr[0]);


//waiting for child to exit
waitpid(-1,&s,0);

}



return 0;
}
