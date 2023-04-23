#include "myshell.h"
/**
 * main - entry point
 * @argv: the argument vector
 * @argc: the argument count
 * Return: success 0, 1  on error
 */
int main(int argc, char **argv)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1. %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
			{
				exit(126);
			}
			if (errno == ENOENT)
			{
				_puts(argv[0]);
				_puts(": ): can't open");
				_puts(agrv[1]);
				putchar('\n');
				putchar(BUFFER_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, argv);
	return (EXIT_SUCCUSS);
}
/* a NIYIBIZI Bonaventure codes */
