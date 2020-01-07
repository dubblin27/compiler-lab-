#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct table{
	char var[50];
	char type[10];
	int size;
	int scope;
};
char t[50];
int check(){
	if(!strcmp(t,"int")) return 1;
	else if(!strcmp(t,"float")) return 2;
	else if(!strcmp(t,"char")) return 3;
	else if(!strcmp(t,"double")) return 4;
	else return 0;	
}
int arraySize(int i){ // to check the array size
	char *num = malloc(sizeof(char) * 15);
	int temp, j = 0;
	while(t[i] != '\0'){
		num[j] = t[i];
		j++; i++;
	}
	num[j] = '\0';
	return atoi(num);
}
void main(){
	char arr[50];
	printf("\n Enter the file name to be read : ");
	scanf("%s",arr);

	FILE *fp;
	fp = fopen(arr,"r");
	if(fp == NULL) {
		printf("\n Cannot Open File");
		return;
	}
	char ch;
	ch = fgetc(fp);
	
	int i = 0, j = 0, k = 0, arr_size = 1, arr_start = 0;
	struct table st[10];
	
	int type = 0, scope = 0, flag = 0;
	while(ch != EOF){
		if(isspace(ch) || ch == ',' || ch == ';' || ch == '\n' || ch == '{'){
			t[j] = '\0'; j = 0;
			if(flag == 0 && !strcmp(t,"main()")){
				scope = 1; 
				flag = 1;
			}
			if(check()) type = check(); 
			else if(type != 0 && t[0] != '\0'){
				strcpy(st[k].var, t);
				if(type == 1) {
					strcpy(st[k].type,"int");
					st[k].size = 2;
				}
				else if(type == 2) {
					strcpy(st[k].type,"float");
					st[k].size = 4;
				}
				else if(type == 3) {
					strcpy(st[k].type,"char");
					st[k].size = 1;
				}
				else if(type == 4) {
					strcpy(st[k].type,"double");
					st[k].size = 8;
				}
				st[k].size = st[k].size * arr_size;
				st[k].scope = scope;
				k++;
				if(ch == ';') type = 0;
				arr_size = 1; 
			}
		}
		else if(ch == '[') arr_start = j;
		else if(ch == ']') {
			arr_size = arraySize(arr_start);
			j = arr_start;
		}
		else{
			t[j] = ch; //temp char array
			j++;
		}
		ch = fgetc(fp);
	}
	//print
	printf("\n Variable\t Type\t Size\t   Scope\n");
	printf("-------------------------------------------");
	for(i = 0; i < k ; i++){
		printf("\n %s\t|\t %s\t| %d\t|  ",st[i].var,st[i].type,st[i].size);
		if(st[i].scope == 0) printf("Global\n");
		else printf("Local\n");
	}
	fclose(fp);
}	
