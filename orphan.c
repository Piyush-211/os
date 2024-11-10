
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main(){

int n;

printf("Enter the number of elelments:");
scanf("%d",&n);

int arr[n];

for(int i=0;i<n;i++){

scanf("%d",&arr[i]);

}
//fork -> system call -> replica (child process)
pid_t pid;
pid=fork();




if(pid!=0){//parent process
printf("\n This is parent process");
printf("Parent process id =%d\n",getppid());//parent process id
printf("Parent child id=%d\n",getpid());//current process id equal

bubbleSort(arr,n);
printf("\n Parent sorted array");
for(int i=0;i<n;i++){

printf("%d",arr[i]);
}
printf("\n");//execute
sleep(2);
}
else{//child process
sleep(1);
printf("\n This is child processs\n");
printf("CHild process id=%d\n ",getpid());
printf("child parent id=%d\n",getppid());//equal

bubbleSort(arr,n);
printf("Child sorted array");
for(int i=0;i<n;i++){
printf("%d ",arr[i]);
}
printf("\n");
}}
