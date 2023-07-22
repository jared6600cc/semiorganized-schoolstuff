
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main(){

long i;
struct timeval * t;
t=(struct timeval *)malloc(sizeof(struct timeval));
gettimeofday(t,NULL);
time_t startSec = t->tv_sec;
printf("seconds = %ld microseconds = %ld\n",t->tv_sec - startSec, t->tv_usec);

return 0;
}