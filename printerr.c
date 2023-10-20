#include "shell.h"

/**
 * printerr - prints error message
 * @x: err number
 * @cmd: command inputted
 * @prog: program name
 * Return: error message
 */

int printerr(int x, char *cmd, char *prog)
{
	char *msg, *msg1;

	vo x;
	vo cmd;
	vo prog;
	vo msg;

	if (errno == 123)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", prog, x, cmd);
		return (127);
	}
	else if (errno == 120)
	{
		msg1 = "Permission denied\n";
		fprintf(stderr, "%s: %d: %s %s\n", prog, x, cmd, msg1);
		return (126);
	}
	return (0);
}
