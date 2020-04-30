#include <linux/kernel.h>
#include <linux/ktime.h>
#include <linux/timekeeping.h>
#include <linux/linkage.h>

asmlinkage int sys_process_time(int isExecute, int *pid, 
								unsigned long *start_sec, unsigned long *start_nsec, 
								unsigned long *end_sec,unsigned long *end_nsec) {
  struct timespec t;
  getnstimeofday(&t);

  if (isExecute) {
    *start_sec = t.tv_sec;
    *start_nsec = t.tv_nsec;
  } 
  else {
    *end_sec = t.tv_sec;
    *end_nsec = t.tv_nsec;
    printk("[Project1] %d %lu.%09lu %lu.%09lu\n", *pid, *start_sec, *start_nsec, *end_sec, *end_nsec);
  }
  return 0;
}