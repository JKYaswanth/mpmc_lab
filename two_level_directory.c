#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Directory{
	char dname[10];
	char fname[10][10];
	int fcnt;
};

int search_directory(char d[],struct Directory dir[],int n){
	int i;
	int flag=0;
	for(i=0;i<n;i++){
		if(strcmp(d,dir[i].dname)==0){
			flag=1;
			break;
		}
	}
	if(flag==1){
		return 1;
	}else{
		return 0;
	}
}

int ret_dir(char d[], struct Directory dir[],int dcnt){
	int i,flag=0;
	for(i=0;i<dcnt;i++){
		if(strcmp(d,dir[i].dname)==0){
			flag=1;
			return i;
			break;
		}
	}
	if(flag==0){
		return -1;
	}
}

int search_file(char f[],struct Directory dir[],int dir_num){
	int i,n=dir[dir_num].fcnt,flag=0;
	for(i=0;i<n;i++){
		if(strcmp(f,dir[dir_num].fname[i])==0){
			flag=1;
			return i;
			break;
		}
	}
	if(flag==0){
		return -1;
	}
}
	
int main(){

	int i,j,ch,dcnt=0;
	char d[10],f[10];
	struct Directory dir[10];

	printf("\n\n1. Create Directory\t2. Create File \t3. Delete File\t4. Delete Directory\t5. Search File\t6. Display \t7. Exit\n\n");

	while(1){
		printf("Enter your Choice :- ");
		scanf("%d",&ch);

		switch(ch){

			case 1:
				printf("Enter the name of the directory :- ");
				scanf("%s",d);
				if(dcnt>10){
					printf("Directory Limit Exceeded\n");
				}
				else if(search_directory(d,dir,dcnt)){
					printf("Directory already exists\n");
				}else{
					strcpy(dir[dcnt].dname,d);
					dir[dcnt].fcnt=0;
					printf("%s Directory created\n",dir[dcnt].dname);
					dcnt++;
				}
				break;

			case 2:
				printf("Enter the name of the directory :-");
				scanf("%s",d);
				int dir_num=ret_dir(d,dir,dcnt);
				if(dir_num==-1){
					printf("Directory not Found\n");
				}else if(dir[dir_num].fcnt>10){
					printf("File Limit Exceeded\n");
				}else{
					printf("Enter the name of the file :- ");
					scanf("%s",f);
					int file=search_file(f,dir,dir_num);
					if(file!=-1){
						printf("File already exists\n");
					}else{
						strcpy(dir[dir_num].fname[dir[dir_num].fcnt],f);
						printf("%s File created in %s Directory\n",dir[dir_num].fname[dir[dir_num].fcnt],dir[dir_num].dname);
						dir[dir_num].fcnt++;
					}	
				}
				break;

			case 3:
				printf("Enter the name of the Directory in which the File is :- ");
				scanf("%s",d);
				int dir_num1=ret_dir(d,dir,dcnt);
				if(dir_num1!=-1){
					printf("Enter the name of the File to be Deleted :- ");
					scanf("%s",f);
					int file=search_file(f,dir,dir_num1);
					if(file==-1){
						printf("File not Found in the Directory %s",dir[dir_num1].dname);
					}else{	
						printf("%s File Deleted from %s",dir[dir_num1].fname[file],dir[dir_num1].dname);
						strcpy(dir[dir_num1].fname[file],dir[dir_num1].fname[dir[dir_num1].fcnt-1]);
						dir[dir_num1].fcnt--;
					}
				}else{
					printf("Directory not Found\n");
				}
				break;

			case 4:

				printf("Enter the name of the Directory to be deleted :- ");
				scanf("%s",d);
				int dir_num2=ret_dir(d,dir,dcnt);
				if(dir_num2!=-1){
					printf("%s Directory Deleted\n",dir[dir_num2].dname);
					dir[dir_num2] = dir[dcnt-1];
					dcnt--;
				}else{
					printf("Directory not Found\n");
				}
				break;

			case 5:

				printf("Enter the name of the Directory in which the File is to be Searched :-");
				scanf("%s",d);
				int dir_num3=ret_dir(d,dir,dcnt);
				if(dir_num3==-1){
					printf("%s Directory not Found\n",d);
				}else{
					printf("Enter the name of the File to be Searched :- ");
					scanf("%s",f);
					int file=search_file(f,dir,dir_num3);
					if(file==-1){
						printf("%s File not found in the Directory %s\n ",f,dir[dir_num3].dname);
					}else{
						printf("%s File found in the Directory %s\n ",f,dir[dir_num3].dname);
					}
				}
				
				break;

			case 6:

				printf("Directory Name\t\t\tFile name\n\n");
				for(i=0;i<dcnt;i++){
					printf("%s\t\t\t\t\t\t",dir[i].dname);
					int n=dir[i].fcnt;
					for(j=0;j<n;j++){
						printf("%s\t",dir[i].fname[j]);
					}
					printf("\n");
				}
				
				break;

			case 7:
				exit(0);
			
			default:
				printf("Invalid Choice\n");
				break;
		}
	}
	return 0;
}