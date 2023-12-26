#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Directory{
	char dname[10];
	char fname[10][10];
	int fcnt;
};

int main() {

	int i,ch,flag;
	struct Directory dir;
	char f[30];
	dir.fcnt=0;

	printf("Enter the Name of the Directory :- ");
	scanf("%s",dir.dname);

	printf("\n\n1. Create File.\t2. Delete Files\t3. Search File\t4. Display Files\t5. Exit\n\n");
	
	while(1){

		printf("Enter your choice :- ");
		scanf("%d",&ch);

		switch(ch){
			
			case 1:
				flag=0;
				printf("Enter the name of the file :- ");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++){
					if(strcmp(f,dir.fname[i])==0){
						flag=1;
						break;
					}
				}
				if(flag==1){
					printf("File already exists.\n");
				}else{
					strcpy(dir.fname[dir.fcnt],f);
				}
				dir.fcnt++;
				break;

			case 2:
				printf("Enter the name of the file to be deleted :- ");
				scanf("%s",f);
				if(dir.fcnt==0){
					printf("No File is present in the Directory\n");
				}else{
					for(i=0;i<dir.fcnt;i++){
						if(strcmp(f,dir.fname[i])==0){
							printf("File %s is deleted\n",f);
							strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
							break;
						}
					}
					if(i==dir.fcnt){
						printf("File %s is not present in the Directory\n",f);
					}
					else{
						dir.fcnt--;
					}
				}
				break;

			case 3:
				printf("Enter the File to be searched :- ");
				scanf("%s",f);
				if(dir.fcnt==0){
					printf("No File is present in the Directory\n");
				}else{
					for(i=0;i<dir.fcnt;i++){
						if(strcmp(f,dir.fname[i])==0){
							printf("File %s is present in the Directory\n",f);
							break;
						}
					}
					if(i==dir.fcnt){
						printf("File %s is not present in the Directory\n",f);
					}
				}
				break;

			case 4:

				if(dir.fcnt==0){
					printf("No File is Present in the Directory\n");
				}else{
					printf("Files in the Directory %s are :-\n",dir.dname);
					for(i=0;i<dir.fcnt;i++){
						printf("\t%s",dir.fname[i]);
					}
				}
				printf("\n");
				break;

			case 5:
				exit(0);

			default:
				printf("Invalid Choice\n");
				break;
			
		}
		
	}
	
  return 0;
}