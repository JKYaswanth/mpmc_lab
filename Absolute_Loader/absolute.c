#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    FILE *fp;

    int i,j,staddr1;
    char name[10],line[50],name1[10],staddr[50];

    printf("Enter the name of the File :- ");
    scanf("%s",name);

    fp=fopen("input.txt","r");
    if(fp==NULL){
        perror("Error Opening the file\n");
        return 1;
    }

    fscanf(fp,"%s",line);
    for(i=2,j=0;i<8,j<6;i++,j++){
        name1[j]=line[i];
    }
    name1[j]='\0';
    printf("\nProgramme name extracted from the input.txt :- %s\n\n",name1);

    if(strcmp(name,name1)==0){
        while(fscanf(fp,"%s",line)!=EOF){
            
            while(line[0]=='T'){
                for(i=2,j=0;i<8,j<6;i++,j++){
                    staddr[j]=line[i];
                }
                staddr[j]='\0';
                staddr1=(int)strtol(staddr,NULL,16);
                i=12;
                while(line[i]!='$'){
                    if(line[i]!='^'){
                        printf("%06X\t\t%c%c%c%c%c%c\n",staddr1,line[i],line[i+1],line[i+2],line[i+3],line[i+4],line[i+5]);

                        i+=6;
                        staddr1+=3;

                    }else{
                        i++;
                    }
                }
                fscanf(fp,"%s",line);
            }

            fscanf(fp,"%s",line);
        }

    }
    else{
        printf("The Programme name does not match, ABORTING!!!\n");
    }
    fclose(fp);
    return 0;

}