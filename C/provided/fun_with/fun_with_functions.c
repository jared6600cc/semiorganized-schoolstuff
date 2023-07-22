/*
 *	Learning functions
 *  February 11th, 2016
 *  Jared Bumgardner
 *  $ gcc -o fun_with_functions.x fun_with_functions.c
 *  ./fun_with_functions.x
 */

 #include <stdio.h>
 
void fun_function_1() {
	//todo
}

void fun_function_2() {
	//todo
}

void fun_function_3() {
	//todo
}

void fun_function_4() {
	//todo
}

void fun_function_5() {
	//todo
}
 
int main(void) {
	
	//declare variables
	int test_this;
	char again;
	
	//introduce program
	printf("\n\n\t\t***Function Tester***");
	
	do {
	    //prompt for which fun function to run
	    printf("\n\n\tChoose fun function to test: ");
	    scanf("%d", &test_this);
	
	    switch(test_this) {
		    case 1 :
		    //call fun_function 1
		    fun_function_1();
		
		    case 2 :
		    //call fun_function 2
		    fun_function_2();
		
	    	case 3 :
		    //call fun_function 3
		    fun_function_3();
		
		    case 4 :
		    //call fun_function 4
		    fun_function_4();
		
		    default :
		    //call fun_function 5
		    printf("");
		    fun_function_5();
		
		    }
	
	    //prompt for again
	    printf("\n\tWould you like to test another? (y/n): ");
	    scanf("%s", &again);
	
	} while (again == 'y');
	
return 0;

}