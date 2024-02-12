#include <signal.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>

void handd(int sig)
{
	if(sig == SIGINT)
		printf("2\n");
}


void hand(int sig)
{
	if(sig == SIGINT)
		printf("1\n");
}

int	main(void)
{
   	sigset_t set;
    
 	struct sigaction sa;
	sa.sa_handler = hand;
	sigaction(SIGINT, &sa, NULL);

	struct sigaction ssa;
	ssa.sa_handler = handd;
	sigaction(SIGINT, &ssa, NULL);


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
