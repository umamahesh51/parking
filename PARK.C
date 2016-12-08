#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
struct vehicle{
int vno,w;
char vtype[];
struct vehicle *address;
time_t et1,et2;
int payment;
}*v;
struct floor {
int fno,flag,cap;
struct vehicle *first,*last;
}f[3];

void park(){
	struct vehicle *v = (struct vehicle*) malloc(sizeof(struct vehicle));
	printf("Enter Vehicle type : ");
	scanf("%s",v->vtype);
	printf("enter vehicle NO : ");
	scanf("%d",&v->vno);
	printf("wheels :");	scanf("%d",&v->w);
	v->et1=(time_t)__TIME__;
	printf("entered at %s",v->et1);
	if(v->w==4){
		if(strcmp(v->vtype,"SUV")==0){
		 if(f[1].flag<=8){
			if(f[1].first==NULL){
				f[1].first=v;
				f[1].first->address=NULL;
				f[1].last = f[1].first;

			}
			else{
			       //	struct vehicle *temp = v;
				f[1].last->address=v;
				f[1].last=v;
				f[1].last->address=NULL;

			}
			f[1].flag++;
		 }
		 else{
			if(f[0].flag<=10){
			     if(f[0].first==NULL){
				f[0].first=v;
				f[0].first->address=NULL;
				f[0].last = f[0].first;
				f[0].flag++;
				}
			     else{
			       //	struct vehicle *temp = v;
				f[0].last->address=v;
				f[0].last=v;
				f[0].last->address=NULL;
				f[0].flag++;
				}
			}
			else if(f[2].flag<=15){
			    if(f[2].first==NULL){
				f[2].first=v;
				f[2].first->address=NULL;
				f[2].last = f[2].first;
				f[2].flag++;
				}
			    else{
				//struct vehicle *temp = v;
				f[2].last->address=v;
				f[2].last=v;
				f[2].last->address=NULL;
				f[2].flag++;
				}
			}
			else{
				printf("Parking full\n");
			}
		 }
		 }
		 else{
		       if(f[0].flag<=10){
			     if(f[0].first==NULL){
				f[0].first=v;
				f[0].first->address=NULL;
				f[0].last = f[0].first;
				f[0].flag++;
				}
			     else{
				//struct vehicle *temp = v;
				f[0].last->address=v;
				f[0].last=v;
				f[0].last->address=NULL;
				f[0].flag++;
				}
			}
			else if(f[2].flag<=15){
			    if(f[2].first==NULL){
				f[2].first=v;
				f[2].first->address=NULL;
				f[2].last = f[2].first;
				f[2].flag++;
				}
			    else{
			       //	struct vehicle *temp = v;
				f[2].last->address=v;
				f[2].last=v;
				f[2].last->address=NULL;
				f[2].flag++;
				}
			}
			else{
				printf("Parking full\n");
			}
		 }
		}
		else{
		    if(f[0].flag<=10){
			     if(f[0].first==NULL){
				f[0].first=v;
				f[0].first->address=NULL;
				f[0].last = f[0].first;
				f[0].flag++;
				}
			     else{
				//struct vehicle *temp = v;
				f[0].last->address=v;
				f[0].last=v;
				f[0].last->address=NULL;
				f[0].flag++;
				}
			}
			else if(f[2].flag<=15){
			    if(f[2].first==NULL){
				f[2].first=v;
				f[2].first->address=NULL;
				f[2].last = f[2].first;
				f[2].flag++;
				}
			    else{
				//struct vehicle *temp = v;
				f[2].last->address=v;
				f[2].last=v;
				f[2].last->address=NULL;
				f[2].flag++;
				}
			}
			else{
				printf("Parking full\n");
			}
		}
	}


void exitp(){
	int i,j,x;
	struct vehicle *temp1,*temp2;
	printf("enter vehicle number");
	scanf("%d",&x);


	for(i=0;i<3;i++){

		temp1=temp2=f[i].first;


		     if(x==f[i].first->vno){
			printf("%d is removed",x);
			f[i].first=f[i].first->address;
			f[i].flag--;
		     }
		     else{
			while(temp1){
			if(x==temp1->vno){
				printf("%d is removed",x);
				temp2->address=temp1->address;
				break;
			}
				temp2=temp1;
				temp1=temp1->address;


		     }

		}
		temp1->et2=(time_t)__TIME__;
		printf("%s",temp1->et2);
		printf("%f",difftime(temp1->et2,temp1->et1));
	/////////////////
	if(difftime(temp1->et2,temp1->et1)<=30){
		switch(temp1->w){
			case 2:temp1->payment=10;	break;
			case 4:if(strcmp(temp1->vtype,"SUV")==0){
				temp1->payment=30;
			}
			else{
				temp1->payment=20;
			}
			break;
		}
	}
	else{
	      switch(temp1->w){
			case 2:temp1->payment=25;	break;
			case 4:if(strcmp(temp1->vtype,"SUV")==0){
				temp1->payment=50;
			}
			else{
				temp1->payment=40;
			}
			break;
		}
	}
	}
	printf("charged amount is %d",temp1->payment);
}
void status(){
	int i,j;
	struct vehicle *temp;
	for(i=0;i<3;i++){
		printf("floor:%d ",i);
		temp=f[i].first;
		while(temp){
		     printf("Vehicle NO : %d \n",temp->vno);
		     temp=temp->address;
		}
		printf("\n");
	}
}

void main(){
	int n,j;
	clrscr();
	for(j=0;j<3;j++){
		f[j].first=f[j].last=NULL;
		f[j].flag=0;
	}
	do{
	printf("\n 1.Park the vehicle \n 2.Exit the Vehicle \n 3. Status of floors \n 4.Exit \n");
	scanf("%d",&n);
	switch(n){
		case 1:park();break;
		case 2: exitp(); break;
		case 3: status(); break;
		case 4: exit(1);
		default: printf("enter another option\n");
	}
	}while(1);
}

