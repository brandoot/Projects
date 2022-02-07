//Original Author
/***************************************************************************//**
  @file         main.c
  @author       Stephen Brennan
  @date         Thursday,  8 January 2015
  @brief        LSH (Libstephen SHell)
*******************************************************************************/
//Edited by Student:
/*										
	Name:		Brandon Deo
	Date:		21 September 2021 
	Last Update:	5 October 2021
	Purpose: 	To emulate a Linux shell program, create some base functions that perform the
			same functions as a regular shell
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
/*
  Function Declarations for builtin shell commands:
 */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int setshellname(char **args);
int setterminator(char **args);
int newname(char **args);
int listnewnames(char **args);
int savenewnames(char **args);
int readnewnames(char **args);

char* shellname = "myshell";
char* terminator = ">";
FILE *ifile;
FILE *ofile;
/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "cd",
  "help",
  "exit",
  "setshellname",
  "setterminator",
  "newname",
  "listnewnames",
  "savenewnames",
  "readnewnames"
};

int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_help,
  &lsh_exit,
  &setshellname,
  &setterminator,
  &newname,
  &listnewnames,
  &savenewnames,
  &readnewnames
};


int lsh_num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
};

//Following are counters used for conditional statements and to not exceed limits
//tcc used to keep count of how many tokens were created in input at shell,
//then used to check if valid amount of arguments were made for each function
int nncount = 0;
int tcc = 0;

//Following are globabl arrays used to store nick names created by user
char* newname_str[10] = {" "," "," "," "," "," "," "," "," "," "};
char* oldname_str[10] = {" "," "," "," "," "," "," "," "," "," "};


/*
  Builtin function implementations.
*/

/**
   @brief Bultin command: change directory.
   @param args List of args.  args[0] is "cd".  args[1] is the directory.
   @return Always returns 1, to continue executing.
 */
int lsh_cd(char **args)
{
	if (args[1] == NULL) {
    		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  	} 
	else {
    		if (chdir(args[1]) != 0) {
      			perror("lsh");
    		}		
  	}	
  	return 1;
}

/**
   @brief Builtin command: print help.
   @param args List of args.  Not examined.
   @return Always returns 1, to continue executing.
 */
int lsh_help(char **args)
{
	if(tcc != 1){
                printf("Incorrect number of arguments\n");
                return 1;
        }

  	int i;
 
       	printf("Stephen Brennan's LSH\n");
  	printf("Type program names and arguments, and hit enter.\n");
  	printf("The following are built in:\n");

  	for (i = 0; i < lsh_num_builtins(); i++) {
    		printf("  %s\n", builtin_str[i]);
  	}	

  	printf("Use the man command for information on other programs.\n");
  	return 1;
}

/**
   @brief Builtin command: exit.
   @param args List of args.  Not examined.
   @return Always returns 0, to terminate execution.
 */
int lsh_exit(char **args)
{
 	if(tcc != 1){
 		 printf("Incorrect number of arguments\n");
        	 return 1;
 	}

	return 0;
}


/*
	brief: renames the shell on command line
	param: args -> List of arguments, examined and utilized accordingly
	return:Always returns 1, to continue executing
 */
int setshellname(char** args)
{
	if(tcc != 2){
                printf("Incorrect number of arguments\n");
                return 1;
        }

	//conditional statement that sets a default name, otherwise renames the shell
	if (args[1] == NULL)
	{
		shellname = "myshell";
	}
	else
	{
		shellname = args[1];
	}

	return 1;

}

int setterminator(char** args){
	if(tcc != 2){
		printf("Incorrect number of arguments\n");
		return 1;
	}

	if(args[1] == NULL){
		terminator = ">";
	}
	else{
		terminator = args[1];
	}

	return 1;
}

//brief:  checks whether or not the function inputted is not 
	//one of our prebuilt functions but is a linux command
//param: args-> List of arguments, examined and utilized accordingly
//return:. 1 or 0 is used for evaluating whether or not the command executed
//reference: found specific c functions through various sources
int checkunix(char** args){
	//variable for return
	int stat;
	
	//process to append string of char together
	char* aa = args[2];
	char* zz = "type -t ";
	char* yy = (char*) malloc(1 + strlen(zz)+ strlen(aa));
	strcpy(yy,zz);
	strcat(yy,aa);
	char* qq = " > /dev/null 2>&1";
	char* ww = (char*) malloc(1 + strlen(qq)+ strlen(yy));
	strcpy(ww,yy);
	strcat(ww,qq);

	//assigns an integer based on output condition
	//system performs action, to which that output is put into null file
	stat = system(ww);
	return stat;
}

//brief: Builting function that renames a command to a nickname
	//uses the 2 global arrays to store and evaluate inputted names
//param: args-> List of arguments, examined and utilized accordingly
//return: 1 for continuation of program
int newname(char** args){
	if(tcc != 3){
                printf("Incorrect number of arguments\n");
                return 1;
        }


	if(args[2] == NULL || args[1] == NULL){
		printf("Empty command name.");
		return 1;
	}


	//checks if linux command and performs separately
	if(checkunix(args) == 0 && nncount < 10){
		newname_str[nncount] = args[1];
		oldname_str[nncount] = args[2];
		nncount += 1;
		return 1;
	}


	//otherwise, input  goes through conditional statements and loops
	//to check if exists in builtin functions and doesn't exceed requirements
	//also replaces old nicknames for same functions
	char* x = args[2];
	int i;
	for( i=0; i<lsh_num_builtins(); i++){
		if(strcmp(x,builtin_str[i]) == 0 && strcmp(x,oldname_str[i]) != 0){
			if(nncount<10){			
				newname_str[nncount] = args[1];
				oldname_str[nncount] = builtin_str[i];
				nncount += 1;
				printf("Successful \n");
				return 1;
			}
			else{
				printf("Too many new names.\n");
				return 1;
			}
		}
		else if(strcmp(x,oldname_str[i]) == 0){
			newname_str[i] = args[1];
			printf("Replaced old nickname.\n");
			return 1;
		}

	}
	printf("Invalid Command Name.\n");
	return 1;

}
//brief: prints new names created onto the console
//param: args, List of arguments, not utilized directly
//return: 1 for continuation of program
int listnewnames(char** args){
	if(tcc != 1){
		printf("Incorrect number of arguments\n");
		return 1;
	}
	if(nncount == 0){
		printf("No nicknames were made\n");
		return 1;
	}

	int i;
	for(i = 0;i < nncount; i++){
		printf("%s",newname_str[i]);
		printf(" %s",oldname_str[i]);
		printf("\n");
	}
	return 1;
}

//brief: first checks if file can be created, 
	//then writes new nicknames into the file and saves
//param: args, List of arguments, utilized accordingly
//return: 1 for continuation of program
int savenewnames(char** args){
	if(tcc != 2){
		printf("Incorrect number of arguments\n");
		return 1;
	}
	if(args[1] == NULL){
		printf("Empty, please type a filename.");
		return 1;
	}
	ofile = fopen(args[1],"a+");
	if(nncount == 0){
		printf("No nicknames were created\n");
		return 1;
	}
	int i;

	for(i = 0; i<nncount; i++){
		fprintf(ofile, "%s\n",newname_str[i]);
	}
	fclose(ofile);
	return 1;
}

//brief: checks if file has any content
	//then prints contents of file into console
//param: args, List of arguments, utilized accordingly
//return: 1 for continuation of program
int readnewnames(char** args){
	if(tcc != 2){
                printf("Incorrect number of arguments\n");
                return 1;
        }
        if(args[1] == NULL){
                printf("Empty, please type a filename.");
                return 1;
        }
	char c;
	ifile = fopen(args[1],"r+");
	if(ifile == NULL){
		printf("Error with file.");
		fclose(ifile);
		return 1;
	}
	while ((c = getc(ifile)) != EOF) printf("%c",c);
	fclose(ifile);
	return 1;

}

/**
  @brief Launch a program and wait for it to terminate.
  @param args Null terminated list of arguments (including program).
  @return Always returns 1, to continue execution.
 */
int lsh_launch(char **args)
{
 	 pid_t pid, wpid;
 	 int status;

  	pid = fork();
 	if (pid == 0) {
    	// Child process
   	if (execvp(args[0], args) == -1) {
     		perror("lsh");
    	}
    
	exit(EXIT_FAILURE);
  	} 
	else if (pid < 0) {
    	// Error forking
    	perror("lsh");
  	} 
	else {
    	// Parent process
    	do {
      		wpid = waitpid(pid, &status, WUNTRACED);
    	}while (!WIFEXITED(status) && !WIFSIGNALED(status));
  	}

  	return 1;
}

/**
   @brief Execute shell built-in or launch program.
   @param args Null terminated list of arguments.
   @return 1 if the shell should continue running, 0 if it should terminate
 */
int lsh_execute(char **args)
{
  	int i;
  	//counter to check if input is nickname
	int y;

  	if (args[0] == NULL) {
    	// An empty command was entered.
    	return 1;
  	}

  	//goes through loop to check if input was a nickname
  	//then renames it back to the original command
  	for(y = 0; y < 10; y++){
  		if(strcmp(args[0],newname_str[y]) == 0){
		args[0] = oldname_str[y];
		}
  	}

  	//goes through loop to check if input was a builtin function
	for (i = 0; i < lsh_num_builtins(); i++) {
    		if (strcmp(args[0], builtin_str[i]) == 0) {
      		return (*builtin_func[i])(args);
    		}
  	}

	//if not checks if linux command
  	return lsh_launch(args);
}

#define LSH_RL_BUFSIZE 1024
/**
   @brief Read a line of input from stdin.
   @return The line from stdin.
 */
char *lsh_read_line(void)
{
  	int bufsize = LSH_RL_BUFSIZE;
  	int position = 0;
 	char *buffer = malloc(sizeof(char) * bufsize);
 	int c;

  	if (!buffer) {
    		fprintf(stderr, "lsh: allocation error\n");
    		exit(EXIT_FAILURE);
  	}

  	while (1) {
    	// Read a character
    	c = getchar();

    	// If we hit EOF, replace it with a null character and return.
    		if (c == EOF || c == '\n') {
      			buffer[position] = '\0';
      			return buffer;
    		} 
		else {
      			buffer[position] = c;
    		}
    		position++;

    		// If we have exceeded the buffer, reallocate.
    		if (position >= bufsize) {
      			bufsize += LSH_RL_BUFSIZE;
      			buffer = realloc(buffer, bufsize);
      			if (!buffer) {
        			fprintf(stderr, "lsh: allocation error\n");
        			exit(EXIT_FAILURE);
      			}
    		}
  	}
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
/**
   @brief Split a line into tokens (very naively).
   @param line The line.
   @return Null-terminated array of tokens.
 */
char **lsh_split_line(char *line)
{
  	int bufsize = LSH_TOK_BUFSIZE, position = 0;
  	char **tokens = malloc(bufsize * sizeof(char*));
  	char *token;

  	tcc = 0;

  	if (!tokens) {
  		fprintf(stderr, "lsh: allocation error\n");
    		exit(EXIT_FAILURE);
  	}

  	token = strtok(line, LSH_TOK_DELIM);
  	while (token != NULL) {
    		tokens[position] = token;
    		position++;

    		if (position >= bufsize) {
      			bufsize += LSH_TOK_BUFSIZE;
      			tokens = realloc(tokens, bufsize * sizeof(char*));
      			if (!tokens) {
        			fprintf(stderr, "lsh: allocation error\n");
        			exit(EXIT_FAILURE);
      			}
    		}

    		token = strtok(NULL, LSH_TOK_DELIM);
    		tcc += 1;
  	}
  	tokens[position] = NULL;
  	return tokens;
}

/**
   @brief Loop getting input and executing it.
 */
void lsh_loop(void)
{
  	char *line;
  	char **args;
  	int status;

  	do {
    		printf("%s %s ", shellname, terminator);
    		line = lsh_read_line();
    		args = lsh_split_line(line);
    		status = lsh_execute(args);

//    free(line);
//    free(args);
  	} while (status);
}

/**
   @brief Main entry point.
   @param argc Argument count.
   @param argv Argument vector.
   @return status code
 */
int main(int argc, char **argv)
{
  // Load config files, if any.

  // Run command loop.
  	lsh_loop();

  // Perform any shutdown/cleanup.

  	return EXIT_SUCCESS;
}
