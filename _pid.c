#include <unistd.h>
#include <stdio.h>

int check_pid(void)
{
	pid_t process_id;

	process_id = getppid();
	printf("%u\n", process_id);
	return (0);
}
