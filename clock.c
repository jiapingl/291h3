#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{

  int result;
  struct timespec tp;
  clockid_t arr[4]={CLOCK_REALTIME, CLOCK_REALTIME_COARSE, CLOCK_MONOTONIC, CLOCK_PROCESS_CPUTIME_ID};

  // int clock_gettime(clockid_t clk_id, struct timespec *tp);
  int i;
  for(i=0;i<4;i++){
  	result = clock_gettime(arr[i], &tp);
  	printf("result: %i\n", i);
  	printf("tp.tv_sec: %llds\n", tp.tv_sec);
  	printf("tp.tv_nsec: %ldns\n", tp.tv_nsec);

  	result = clock_getres(arr[i], &tp);
  	printf("precision: \n");
  	printf("tp.tv_sec: %llds\n", tp.tv_sec);
  	printf("tp.tv_nsec: %ldns\n", tp.tv_nsec);
  }
}