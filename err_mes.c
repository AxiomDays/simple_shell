#include "main.h"

void print_err_mes(void)
{
	err_count++;
	_print(progName);
	_print(": ");
	print_number(err_count);
	_print(": ");
	_print("input: ");
	perror(NULL);
}
