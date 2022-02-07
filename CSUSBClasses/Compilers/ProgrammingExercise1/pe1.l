%{
#include <stdio.h>

int count = 0;
%}

letter [a-zA-Z]
digit [0-9]
notid ({digit}{letter})+

%%
[\t\n]+

(notid){printf("%s is not an identifier\n",yytext);}
%%

int main(){
	FILE *f;

	char file[10];
	printf("\nEnter filename: ");
	scanf("%s", file);
	f = fopen(file,"r");
	yyin = f;
	yylex();
	
	return 0;
}
