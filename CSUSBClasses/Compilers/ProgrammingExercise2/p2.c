#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Define set of states
enum STATE {Q0,Q1,Q2,Q3,END,SUCCESS};

bool check = false;
char buffer[] = {' ',' ',' '};

void reset(char b[]){
	b[0] = ' ';
	b[1] = ' ';
	b[2] = ' ';
}
//create peek function to check next character
int cpeek(FILE* f){
	int c;

	c=fgetc(f);
	ungetc(c,f);
	return c;
}

//following are states that lead the input to
//whereever it needs to go
enum STATE initial(int c){
	enum STATE state = Q0;
	if((char)c=='a'){
		state=Q1;
		buffer[0]='a';
	}
	return state;
}

enum STATE a(int c){
	enum STATE state = Q1;
	if((char)c=='b'){
		state=Q2;
		buffer[1]='b';
	}
	else if((char)c=='a')
		reset(buffer);
	return state;
}

enum STATE ab(int c){
	enum STATE state = Q2;
	if((char)c=='b'){
		state=Q3;
		buffer[2]='b';
	}
	else if((char)c=='a'){
		state=Q1;
		reset(buffer);
	}
	return state;
}

enum STATE abb(int c, FILE* f1){
	enum STATE state = Q3;
	
	int x = cpeek(f1);

	for(int i=0;i<3;i++){
		if(buffer[i] == 'a' || buffer[i] == 'b')
			check=true;
	}

	if((x == EOF || x == ' ') && check == true){
		state=SUCCESS;
		reset(buffer);
	}
	else if((char)c=='a')
		state=Q1;
	else if((char)c=='b')
		state=Q0;

	return state;
}

int main(){
	//Open a file and check if its valid
	FILE* fo;
	char fbuf[10];

	printf("\nEnter in filename: ");
	scanf("%s",fbuf);
	fo = fopen(fbuf,"r");

	//our variables that we are going to check with
	int c;
	enum STATE state =Q0;


	//loop through entire file until we get to the end
	while((char)(c=getc(fo)) != EOF){
		if (state==Q0){
			state=initial(c);
		}
		else if(state==Q1){
			state=a(c);
		}
		else if(state==Q2){
			state=ab(c);
		}
		else if(state==Q3){
			state=abb(c,fo);
		}
		else if(state==SUCCESS){
			printf("(a|b)* abb found\n");
			state=Q0;
		}
		
	}
	
	fclose(fo);
	return 0;
}
	
