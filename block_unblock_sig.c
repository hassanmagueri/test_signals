#include <signal.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
   	sigset_t set;
    
    	sigemptyset(&set);
    	sigaddset(&set, SIGINT);
    	sigprocmask(SIG_BLOCK, &set, NULL);
   
    	sleep(5);
  	printf("you can use \'Ctrt + C\' now\n");  

    	sigprocmask(SIG_UNBLOCK, &set, NULL);  
    	while(1)
        	pause();
	return (0);
}
