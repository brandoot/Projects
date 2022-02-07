/*
    +--------------------+
    | Text               |
    | instructions in    |4199261	   = proc1
    | machine code       |4199491	   = proc2
    |                    |
    +--------------------+
    +--------------------+
    |Data                |4199909	   = etext
    | initialized var    |4210740          =g1 global initialized
    |                    |4210744          =g3
    |                    |4210748          =ls1 static initialized
    |                    |4210752          =ls3
    +--------------------+
    +--------------------+
    | unitialized var    |4210756          =edata
    |                    |4210816          =g0
    |                    |4210848          =g2
    |                    |4216848          =g4
    |                    |4216852          =ls0
    +--------------------+4216856          =ls2
    +--------------------+
    | heap for dynamic   |4216864          =end
    | allocation         |x22670 pointed to by heap1
    |                    |x22680 pointed to by heap1
    +--------------------+
              |
              |
              V
            .....
    +--------------------+
    | Stacl              |140736340311896, 140736340311896          =lc4,lc6
    | fnct activation    |140736340311900, 140736340311900          =lc3, lc5
    | records            |140736340311924          =lc2
    | local auto var     |140736340311928          =lc1
    +--------------------+140736340311932          =lc0

Question 4: The variables in the stack neither get larger or smaller.
Question 5: No the variables in the stack do not have the same address as other variables
because the stack variables are usually manipulated by functions, which means that local
variables and information that needs to popped off the stack must have different access.
Question 7: I would most likely expect the variables for recursive functions be stored
in the stack.
Question 8:

*/

// memory_segments.cpp
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int g0;       /* global variable, uninitialized */
int g1 = 14;  /* global variable, initialized */
int g2[1500]; /* global variable, uninitialized */
int g3 = 16;  /* global variable, initialized */
int g4;       /* global variable, uninitialized */

void proc1();
void proc2();
int fac(int n);

int main(){ 
    extern int etext[], edata[], end[];
    int lc0;      /* local variable, stored on stack */ 
    int lc1 = 27; /* local variable, stored on stack; mix init and uninit */ 
    int lc2;      /* local variable, stored on stack */        
    static int ls0; /* local static variable, uninitialized data */        
    static int ls1 = 19;      /* local static variable, initialized data */        
    int *pheap1;        
    int *pheap2;
    pheap1 = new int[10];        
    pheap2 = new int[100];
    printf("\n\n---------- main -------------------\n\n");        
    printf("%14p (%15lu): Last address\n", 0xffffffffffff, 999999999999999);
    printf("%14p (%15lu): Address etext\n",   etext, etext);
    printf("%14p (%15lu): Address edata\n",   edata, edata);
    printf("%14p (%15lu): Address end\n",  end, end);
    printf("%14p (%15lu): Address of code for proc1\n",   &proc1, &proc1);        
    printf("%14p (%15lu): Address of code for proc2\n",   &proc2, &proc2);
    printf("%14p (%15lu): Address of uninitialized global variable g0\n", &g0, &g0);
    printf("%14p (%15lu): Address of initialized   global variable g1\n", &g1, &g1);        
    printf("%14p (%15lu): Address of uninitialized global array    g2\n", &g2[0], &g2[0]);
    printf("%14p (%15lu): Address of initialized   global variable g3\n", &g3, &g3);
    printf("%14p (%15lu): Address of uninitialized global variable g4\n", &g4, &g4);
    printf("%14p (%15lu): Address heap1 in heap space\n", pheap1, (unsigned long) pheap1);
    printf("%14p (%15lu): Address heap2 in heap space\n", pheap2, (unsigned long) pheap2);
    printf("%14p (%15lu): Address of local variable lc0\n",   &lc0, &lc0);
    printf("%14p (%15lu): Address of local variable lc1\n",   &lc1, &lc1);
    printf("%14p (%15lu): Address of local variable lc2\n",   &lc2, &lc2);
    printf("%14p (%15lu): Address of local uninitialized static var ls0\n",   &ls0, &ls0); 
    printf("%14p (%15lu): Address of local initialized   static var ls1\n",   &ls1, &ls1);
    
    proc1(); 
    proc2();

    int a=0;
    cout<<"Enter a number for factorial\n";
    cin>>a;
    cout<<fac(a);

    return 0;
}
void proc1() {
    int lc3; 
    int lc4 = 37;
    printf("\n\n----------- proc1 ------------------\n\n");
    printf("%14p (%15lu): Address of code for proc1\n", &proc1, &proc1);
    printf("%14p (%15lu): Address of global variable g0\n", &g0, &g0);
    printf("%14p (%15lu): Address of global variable g1\n", &g1, &g1);
    printf("%14p (%15lu): Address of global variable g2\n", &g2[0], &g2[0]);
    printf("%14p (%15lu): Address of global variable g3\n", &g3, &g3);
 printf("%14p (%15lu): Address of global variable g4\n", &g4, &g4);
 printf("%14p (%15lu): Address of local variable lc3\n", &lc3, &lc3);
 printf("%14p (%15lu): Address of local variable lc4\n", &lc4, &lc4);
}

void proc2() {
    int lc5;
    int lc6 = 51;
    static int ls2;
    static int ls3 = 47;
    printf("\n\n------------ proc2 -----------------\n\n");
    printf("%14p (%15lu): Address of code for proc2\n", &proc2, &proc2); 
    printf("%14p (%15lu): Address of global variable g0\n",   &g0, &g0);
    printf("%14p (%15lu): Address of global variable g1\n",   &g1, &g1);
    printf("%14p (%15lu): Address of global variable g2\n",   &g2[0], &g2[0]);
    printf("%14p (%15lu): Address of global variable g3\n",   &g3, &g3); 
    printf("%14p (%15lu): Address of global variable g4\n",   &g4, &g4); 
    printf("%14p (%15lu): Address of local variable lc5\n",   &lc5, &lc5);
    printf("%14p (%15lu): Address of local variable lc6\n",   &lc6, &lc6); 
    printf("%14p (%15lu): Address of local uninitialized static var ls2\n",   &ls2, &ls2); 
    printf("%14p (%15lu): Address of local initialized   static var ls3\n",   &ls3, &ls3);
}

int fac(int n){
	printf("%14p (%15lu): Address of fac\n",&fac,&fac);
	printf("%14p (%15lu): Address of n\n",&n,&n);
	if(n==0)
		return 1;
	else
		return n*fac(n-1);
}
