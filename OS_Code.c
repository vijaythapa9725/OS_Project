#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t pen,paper,ques;
int a,count=0;

void *student1(void *);
void *student2(void *);
void *student3(void *);

int main()
{
	system("cls");
	int s1,s2,s3;

	pthread_t t1,t2,t3;
	sem_init(&pen,0,0);
	sem_init(&paper,0,0);
	sem_init(&ques,0,0);
	pthread_create(&t1,NULL,student1,NULL);
	pthread_create(&t2,NULL,student2,NULL);
	pthread_create(&t3,NULL,student3,NULL);
	printf("\n\n\t|~>> WELCOME TO EXAMINATION HALL Management System <<~|\n\n");
	printf("Student 1 with pen || Student 2 with Paper || Student 3 with Ques Paper\n\n");
	printf("Teacher places-\n1. Paper and Ques\n2. Pen and Ques\n3. Pen and Paper\n\n");
	while(count!=3){
	printf("Enter What Teacher Places: ");
	scanf("%d",&a);
	switch(a){
			
	case 1:	if(s1==0){
		printf("\nStudent 1 is completing assignment..\n");
		//sem_init(&pen,0,0);
		sem_post(&paper);
		sem_post(&ques); s1++;
		count++;
		sleep(0);
		}
		else printf("\nStudent 1 is already completed his assignment.\n\n");
		break;

	case 2:	if(s2==0){
		printf("\nStudent 2 is completing assignment..\n");
		sem_post(&pen);
		sem_post(&ques);	sem_post(&pen);
		s2++;
		count++;
		sleep(1);
		}
		else
		printf("\nStudent 2 is already completed his assignment.\n\n");
		break;

	case 3:	if(s3==0){
		printf("\nStudent 3 is completing assignment\n");
		sem_post(&pen);
		sem_post(&paper); 
		count++; s3++;
		sleep(0);
		}
		else
		printf("\nStudent 3 is already completed his assignment.\n\n");
		break;
	
	default: printf("\n\t\tInvalid Input.\n\t\t--Try Again--\n\n");
	}
	}
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	printf("All student's assignments is completed.");
	//system("clear");
	printf("\n\n\n\t*****THANKS FOR USING OUR SERVICE*****\n\n");
}

void *student1(void *p)
{
	sem_wait(&paper);
	sem_wait(&ques);
	printf("Assignment is completed.\n\n");
	//sem_post(&paper);
	//sem_post(&ques);
}

void *student2(void *p)
{
	sem_wait(&pen);
	sem_wait(&ques);
	printf("Student 2 assignment is completed.\n\n");
	//sem_post(&pen);
	//sem_post(&ques);
}

void *student3(void *p)
{
	sem_wait(&pen);
	sem_wait(&paper);
	printf("Student 3 assignment is completed.\n\n");
	//sem_post(&pen);
	//sem_post(&paper);
}
