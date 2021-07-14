//mohamed ahmed mohamed elshafie sec 3  bn 30
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct node{
   char name[20];
   int ID;
   int day,month,year;
   int score;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;


void print(void){

   struct node *newNode = head;

   while(newNode != NULL){
      printf("name: %s\n",newNode->name);
      printf("ID: %d \n",newNode->ID);
      printf("Date of birth: %d/%d/%d \n",newNode->day,newNode->month,newNode->year);
      printf("Score: %d \n",newNode->score);
      printf("********************************\n");
      newNode = newNode->next;
   }

   printf(" \n");
}


int sizeOfList(void){
   int size = 0;

   if(head==NULL)
   {
      printf("List size : %d ", size);
      return -1;
   }

   current = head;
   size = 1;
   while(current->next != NULL)
   {
      current = current->next;
      size++;
   }
   return size;
}


void insertAtFirst(char myname[],int myID,int myDay,int myMonth,int myYear,int myScore){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->next = head;
	strcpy(newNode->name,myname);
    newNode->ID = myID;
    newNode->day = myDay;
    newNode->month = myMonth;
    newNode->year = myYear;
    newNode->score = myScore;

	head = newNode;

}


void insertAtLast(char myname[],int myID,int myDay,int myMonth,int myYear,int myScore){
   struct node *newNode = (struct node*) malloc(sizeof(struct node));
    strcpy(newNode->name,myname);
    newNode->ID = myID;
    newNode->day = myDay;
    newNode->month = myMonth;
    newNode->year = myYear;
    newNode->score = myScore;

   newNode->next = NULL;

   if(head==NULL){
      head = newNode;
      return;
   }

   current = head;

   while(current->next != NULL)
   {
	   current = current->next;
   }

   current->next = newNode;
}


void insertAtMid(char myname[],int myID,int myDay,int myMonth,int myYear,int myScore){

    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    strcpy(newNode->name,myname);
    newNode->ID = myID;
    newNode->day = myDay;
    newNode->month = myMonth;
    newNode->year = myYear;
    newNode->score = myScore;
    int count=0;
    if(sizeOfList()%2==0){
        count=sizeOfList()/2;
    }
    else{
        count=(sizeOfList()+1)/2;
    }
    current = head;
    while(count>1){
        current = current->next;
        count -= 1;
    }
    newNode->next = current->next;
    current->next = newNode;
}
int main(void){

    //test insert:

    /*insertAtFirst("mohamed",1,15,6,2000,90);
    insertAtLast("ahmed",2,20,5,1997,80);
    insertAtFirst("mahmoud",3,20,5,1997,80);
    insertAtLast("abdallah",4,25,4,1998,70);
    print();*/

    //test insert in the middle in case of even number of elements:

    /*insertAtFirst("mohamed",1,15,6,2000,90);
    insertAtLast("ahmed",2,20,5,1997,80);
    insertAtMid("abdallah",3,25,4,1998,70);
    print();*/

    //test insert in the middle in case of odd number of elements:

    insertAtFirst("mohamed",1,15,6,2000,90);
    insertAtLast("ahmed",2,20,5,1997,80);
    insertAtLast("mahmoud",3,20,5,1997,80);
    insertAtLast("abdallah",4,25,4,1998,70);
    insertAtLast("yasser",5,25,4,1998,70);
    insertAtMid("omar",6,30,3,1999,60);
    print();


}
