#include "shell.h"
/**
 * env_to_path - This is function of my path
 * @my_path : is my path to the path/bin
 *
 */
void env_to_path(const char *my_path)
{
	if (setenv("MY_PATH", my_path, 1) != 0)
	{
		perror("Error to set PATH env varaible");
		exit(EXIT_FAILURE);
	}
}
