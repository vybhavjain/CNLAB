#include<stdio.h>
int high[25]={0},low[25]={0};
int hf=0,lf=0,hr=0,lr=0;

void insert(int val,int pri){
  if(pri==1){
    if(hr<24){
    printf("Packet inserted into high priority queue\n");
    high[hr++]=val;
  }
    else
    printf("The queue is full\n");
  }
  else if(pri==2){
   if(lr<24){
    printf("Packet inserted into low priority queue\n");
    low[lr++]=val;
  }
   else
   printf("Queue is full\n");
  }
  else
    printf("Invalid priority request\n");
}

void process(){
  if(hf!=hr){
    printf("Processing high prio-rity queue\n");
    while(hf!=hr){
      printf("%d\t",high[hf++]);
    }
  }
  else{
    if(lf!=lr)printf("Processing low priority queue\n");	
    while(lf!=lr){
      printf("%d\t",low[lf++]);
    }
  }
  printf("\nProcess complete\n");
}

void main(){
  int val,pri,ch=1;
  while(ch!=3){
    printf("Enter 1 for insertion,2 to process, 3 to exit\n");
    scanf("%d",&ch);
    if(ch==1){
      //printf("Enter the packet value and priority\n");
      printf("add value");
      scanf("%d",&val);
      printf("priority");
      scanf("%d",&pri);
      insert(val,pri);
    }
    else if(ch==2){
      process();
    }
    else
      break;
  }
}
