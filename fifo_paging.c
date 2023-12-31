#include<stdio.h>
#include<stdlib.h>

int main(){
	int p,f,i,j,page[10],flag,frame_number=0,page_fault=0;
	printf("Enter Number of Pages :- ");
	scanf("%d",&p);
	printf("Enter Number of Frames :- ");
	scanf("%d",&f);
	printf("Enter page numbers :- ");
	for(i=0;i<p;i++){
		scanf("%d",&page[i]);
	}
	int frame[10];

	for(i=0;i<f;i++){
		frame[i]=-1;
	}

	printf("\n");

	for(i=0;i<p;i++){
		flag=0;
		for(j=0;j<f;j++){
			if(page[i]==frame[j]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			frame[frame_number]=page[i];
			frame_number=(frame_number+1)%f;
			page_fault++;
		}
		printf("%d :\t",page[i]);
		for(j=0;j<f;j++){
			printf("%d\t",frame[j]);
		}
		printf("\n");
	}

	printf("\nPage Faults :- %d",page_fault);

	return 0;
}