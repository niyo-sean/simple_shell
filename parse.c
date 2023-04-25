#include "myshell.h"
/**
 * is_cmd - hre is to determine i f afiles is executables
 * @info: the info struct
 * @path: path to the files
 *
 * Return: Always 0 success
 */
int is_cmd(info_t *info, char *path)
{
	struct stat g;

	(void)info;
	if (!path || stat(path, &g))
		return (0);
	if (g.g_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * dup_chars - duplicates characters
 * @pathstr: the path of string
 * @stop:  is the stopping of index
 * @start:is the atarting of index
 * Return: Always 0 success
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buffer[1024];
	int a = 0, d = 0;

	for (d = 0, a = start; a < stop; a++)
		if (pathstr[a] != ':')
			buffer[d++] = pathstr[a];
	buffer[d] = 0;
	return (buffer);
}
/**
 * find_path -finds this cmd in the PATH string
 * @info: the parameter of info struct
 * @cmd: the cmd to find
 * @pathstr: the PATH of string
 * Return: Always success
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int a = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);

	}
	while (1)
	{
		if (!pathstr[a] || pathstr[a] == ':')
		{
			path = dup_chars(pathstr, curr_pos, a);
			if (!path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[a])
				break;
			 curr_pos = a;
		}
		a++;
	}
	return (NULL);
}
/* a NIYIBIZI Bonaventure codes */
