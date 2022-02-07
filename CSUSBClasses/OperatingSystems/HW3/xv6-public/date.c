#include "types.h"
#include "user.h"
#include "date.h"
int main(int argc, char *argv[]){
	struct rtcdate r;
	if (date(&r)){
		printf(2, "date failed\n");
	       	exit();
	}
       	// your code to print the date in any format you like...
	
	printf(1, "Day:%d Month:%d Year:%d\n", r.day, r.month, r.year);

	exit();    
}
