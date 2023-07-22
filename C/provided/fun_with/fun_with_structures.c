//study for exam2

#include<stdio.h>

int main(void){
	
	printf("\tFun With Structures\n\n");
	
	//declare structures
	struct ball {				//ball structure
		int radius;
		char color;
		float velocity;
	};
	
	struct ball ball4;
	int i;
	
	printf("Declaration of ball structure: SUCCESS\n");

	//initialize structures
	struct ball ball1;														//no initialization
	printf("Ball struct ball1 created\n");
	printf("\tball1 has...\n\t\tradius: %d\n\t\tcolor = %c\n\t\tvelocity = %.2fmps\n", ball1.radius, ball1.color, ball1.velocity);


	struct ball ball2 = {10, 'r', 5};										//in order initialization
	printf("Ball struct ball2 created\n");
	printf("\tball2 has...\n\t\tradius: %d\n\t\tcolor = %c\n\t\tvelocity = %.2fmps\n", ball2.radius, ball2.color, ball2.velocity);
	
	struct ball ball3 = {.color = 'y', .velocity = 25, .radius = 1};		//field specified initialization
	printf("Ball struct ball3 created\n");
	printf("\tball3 has...\n\t\tradius: %d\n\t\tcolor = %c\n\t\tvelocity = %.2fmps\n", ball3.radius, ball3.color, ball3.velocity);
	
	ball4 = (struct ball) {.velocity = 100, .radius = 50, .color = 'g'};	//compound literal initialization
	printf("Ball struct ball4 created\n");
	printf("\tball4 has...\n\t\tradius: %d\n\t\tcolor = %c\n\t\tvelocity = %.2fmps\n", ball4.radius, ball4.color, ball4.velocity);

	//arrays of structures
	struct ball ballPit[10];		//creates array which holds ball structures
	printf("\nBallPit created");
	for(i = 0; i < 10; i++){
		struct ball ballPit[i];
		printf("\nBallPit ball%i created", i+1);
	};
	
	return 0;
}