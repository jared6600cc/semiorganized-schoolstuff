//   Jared Bumgardner
//   COP 3530 - Prof. Mishra
//   Credit: hanoi function authored by Prof. Mishra
//   8/25/2016

#include <stdio.h>

void hanoi(int num, char sourcepeg, char destpeg, char midpeg)	//num - #disks 
{	
   if(num == 1)			//basis
   {
	   printf("\n Move disk 1 from peg %c to peg %c", sourcepeg, destpeg);
	   return;
   }
   else
   {	   
	   hanoi(num-1, sourcepeg, midpeg, destpeg);
	   printf("\n Move disk %d from peg %c to peg %c", num, sourcepeg, destpeg);
	   hanoi(num-1, midpeg, destpeg, sourcepeg);
   }
}

void main()
{
	int disk_num = 0;
	char sourcepeg = 'A', destpeg = 'B', midpeg = 'C';
	
	//get number of disks
	printf("\n\t\t***Tower of Hanoi***");

	printf("\n\tHow many disks are in your tower?\n");	
	scanf("%d", &disk_num);
	
	//solve tower of hanoi in smallest amount of steps
	hanoi(disk_num, sourcepeg, destpeg, midpeg);
	
	return;
}