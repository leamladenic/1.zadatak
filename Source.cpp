#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

#define file_name "Studenti.txt"
#define MAX 100


typedef struct {

	char name[20];
	char surname[20];
	int grades;

}student;

int rowCount(char*);
void Load(char*, int, student*);
void Print( int, student*);
float aps(int);
float rel(int, int);


int main(){

	int n;
	student *p = NULL;
	
	n = rowCount(file_name);

	printf("U datoteci ima %d studenata.\n", n);

	p = (student*)malloc(n*sizeof(student));


	Load (file_name, n, p);

	Print( n, p);

	return 0;
}

int rowCount(char* filename){

	int br = 1;
	FILE*fp = NULL;
	char*x;

	fp = fopen(file_name, "r");

	if (fp == NULL){
		printf("ERROR\n");
		exit(1);
	}

	while (!feof(fp)){
		x = (char*)malloc(sizeof(char)*MAX);

		fgets(x, MAX, fp);
		if (strlen(x) > 0) br++;
		free(x);
	}
	
	fclose(fp);

	return br;
}

void Load(char*filename, int n, student *p){

	int i;
	FILE*fp = NULL;
	

	fp = fopen(file_name, "r");

	if (fp == NULL){
		printf("ERROR\n");
		exit(1);
	}

	for (i = 0; i<n; i++){
		fscanf(fp, "%s", p[i].name);
		fscanf(fp, "%s", p[i].surname);
		fscanf(fp, "%d", &p[i].grades);
	}

	fclose(fp);
	return;
}

void Print(int n, student*p){
	int max;
	int i;

	max = p[0].grades;
	for (i = 0; i<n; i++){
		if ((p[i].grades)>max){
			max = (p[i].grades);
		}
	}

	printf("Najveci broj bodova: %d\n", max);

printf("IME\tPREZIME\t\tRELATIVAN BROJ BODOVA\tAPSOLUTAN BROJ BODOVA\n");
	for (i = 0; i<n-1; i++){
		
		printf("%s\t", p[i].name);
		printf("%s\t\t\t", p[i].surname);
		printf("%f\t\t\t\t", rel(p[i].grades, max));
		printf("%f\n", aps(p[i].grades));

	}
	return;

}
float aps(int x){
	float max = 90;
	float odg;

	odg = (x / max) * 100;
	return odg;
}
float rel(int x, int max){

	float odg;

	odg = (x / (float)max) * 100;
	return odg;

}

