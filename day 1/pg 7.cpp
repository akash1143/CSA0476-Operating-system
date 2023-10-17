#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<string.h>  
int main()  
{  
int i;  
void *shared_memory;  
char buff[100];  
int shmid;  
shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);   
printf("Key of shared memory is %d\n",shmid);  
shared_memory=shmat(shmid,NULL,0);    
printf("Process attached at %p\n",shared_memory); 
printf("Enter some data to write to shared memory\n");  
read(0,buff,100); 
strcpy(shared_memory,buff); 
printf("You wrote : %s\n",(char *)shared_memory);  
}  
8. Illustrate the concept of multithreading using a C program.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>  
#include<pthread.h>
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
} 
int main()
{
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}
