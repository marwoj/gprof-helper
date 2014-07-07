#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function( void *ptr );
void *print_message_functionA( void *ptr );
void *print_message_functionB( void *ptr );
void callFirst(void);
void callSecond(void);

main()
{
     pthread_t thread1, thread2;
     const char *message1 = "Thread 1";
     const char *message2 = "Thread 2";
     int  iret1, iret2;

    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, print_message_functionA, (void*) message1);
     if(iret1)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }

     iret2 = pthread_create( &thread2, NULL, print_message_functionB, (void*) message2);
     if(iret2)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }

     printf("pthread_create() for thread 1 returns: %d\n",iret1);
     printf("pthread_create() for thread 2 returns: %d\n",iret2);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     exit(EXIT_SUCCESS);
}

void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}

void *print_message_functionA( void *ptr )
{
     callFirst();
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}

void *print_message_functionB( void *ptr )
{
     callSecond();     
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}





void new_func1(void);

void func1(void)
{
    printf("\n Inside func1 \n");
    int i = 0;

    for(;i<0xffffffff;i++);
    new_func1();

    return;
}

static void func2(void)
{
    printf("\n Inside func2 \n");
    int i = 0;

    for(;i<0xffffffaa;i++);
    return;
}


void new_func1(void)
{
    printf("\n Inside new_func1()\n");
    int i = 0;

    for(;i<0xffffffee;i++);
    return;
}

void my_func(void)
{
    printf("\nInside my_func()\n");
    int i = 0;
    for(;i<0x7fffffee;i++);

  new_func1();

  return;
}


void callFirst(void)
{
	func1();
	new_func1();
}

void callSecond(void)
{
	func2();
	my_func();
	func2();
}


