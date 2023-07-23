//  Program to illustrate structure pointers

#include <stdio.h>

struct date
{
   int  month;
   int  day;
   int  year;
};


int main (int argc, char* argv[])
{
   
      FILE *fp;

     struct date  today, *datePtr;

     datePtr = &today;
     
     today.month = 1;
     today.day = 1;
     today.year = 1000;

     printf ("Today's date is %i/%i/%.2i.\n",
               datePtr->month, datePtr->day, datePtr->year % 100);

     printf ("Today's date is %i/%i/%.2i.\n",
               today.month, today.day, today.year % 100);
     
     
     datePtr->month = 9; 
     datePtr->day = 25;
     datePtr->year = 2015;

     printf ("Today's date is %i/%i/%.2i.\n",
               datePtr->month, datePtr->day, datePtr->year % 100);

     printf ("Today's date is %i/%i/%.2i.\n",
               today.month, today.day, today.year % 100);



               return 0;
}
