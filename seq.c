#include<string.h>
#include<stdio.h>

struct Process{
	char name[10];
	int start_add;
	int len;
	int flag;
};

void recurse(int file[],struct Process p[],int num_pro,int size){
	int i,j,flag=0;
	
	for(i=0;i<num_pro;i++){
		
		printf("Enter name of the process %d :-",i+1);
		scanf("%s",p[i].name);
		printf("Enter start address of the process %d :- ",i+1);
		scanf("%d",&p[i].start_add);
		printf("Enter length of the process %d :- ",i+1);
		scanf("%d",&p[i].len);

		if((p[i].start_add+p[i].len)>size){
			printf("Process cannot be allocated\n");
			p[i].flag=1;
		}else{
			for(j=p[i].start_add;j<(p[i].start_add+p[i].len);j++){
				if(file[j]==0){
					file[j]=1;
					flag++;
				}
			}
			if(flag==p[i].len){
				p[i].flag=0;
				printf("Process :- %s Sucessfully allocated\n",p[i].name);
			}else{
				p[i].flag=2;
				printf("Process :- %s trying to occupy preallocated blocks hence not allocated\n",p[i].name);
			}
		}
	}
}

void display(int file[],struct Process p[],int num_pro){
	int i,j;
	printf("\nFile Allocation Table\n\n");
	printf("File Name\tStart Address\tLength\tBlocks Allocated\n");

	for(i=0;i<num_pro;i++){
		if(p[i].flag==0){
			printf("%-10s\t\t%-10d\t\t%-5d\t",p[i].name,p[i].start_add,p[i].len);
			for(j=p[i].start_add;j<(p[i].start_add + p[i].len);j++){
				if(file[j]==1){
					printf("%d ",j);
				}
			}
			printf("\n");
		}else if(p[i].flag==1){
			printf("%-10s\t\t%-10d\t\t%-5d\t",p[i].name,p[i].start_add,p[i].len);
			printf("Process cannot be allocated due to Overflow\n");
		}else{
			printf("%-10s\t\t%-10d\t\t%-5d\t",p[i].name,p[i].start_add,p[i].len);
			printf("Process :- %s trying to occupy preallocated blocks hence not allocated\n",p[i].name);
		}
		
	}
}

int main(){
	int size;
	printf("Enter the Number of Blocks :- ");
	scanf("%d",&size);

	int num_pro;
	printf("Enter the Number of Process :- ");
	scanf("%d",&num_pro);
	int file[size];
	struct Process p[num_pro];

	int i;

	for(i=0;i<size;i++){
		file[i]=0;
	}
	
	for(i=0;i<num_pro;i++){
		p[i].flag=0;
	}
	
	recurse(file,p,num_pro,size);

	display(file,p,num_pro);
	
	return 0;
	
}