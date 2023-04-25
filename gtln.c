#include "myshell"
/**
 * input_buf - buffers for list of command
 * @buffer :adress of buffer
 * @info:is the paramater of struct
 * @leng: is the length of var
 * Return: always success
 */
ssize_t input_buf(info_t *info, char **buffer, size_t *leng)
{
	ssize_t x = 0;
	size_t y = 0;

	if (!*leng)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		x = getline(buffer, &y, stdin);
#else
		x = _getline(info, buffer, &y);
#endif
		if (x > 0)
		{
			if ((*buffer)[x - 1] == '\n')
			{
				(*buffer)[x - 1] = '\0';
			}
			info->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_lists(info, *buffer, info->histcount++);
			{
				*leng = x;
				info->cmd_buffer = buffer;
			}
		}
	}
	return (x);
}
/**
 * get_input - gets a line neg the newline
 * @info: is the parameter struct
 * Return: Always success
 */
ssize_t get_input(info_t *info)
{
	static char *buffer;
	static size_t a, b, leng;
	ssize_t x = 0;
	char **buffer_c = &(info->arg), *c;

	_putchar(BUFFER_FLUSH);
	x = input_buf(info, &buffer, &leng);
	if (x == -1)
		return (-1);
	if (leng)
	{
		b = a;
		c = buffer + a;

		chexk_chain(info, buffer, &b, a, leng);
		while (b < leng)
		{
			if (is_chain(info, buffer, &b))
				break;
			b++;
		}
		a = b + 1;
		if (i >= len)
		{
			a = leng = 0;
			info->cmd_buffer_type = CMD_NORM;
		}
		*buffer_c = c;
		return (_strlen(c));
	}
	*buff_c = buffer;
	return (x);
}
/**
 * read_buf - readable  abuffer
 * @info: is thre parameter of struct
 * @buffer: is the buffer
 * @a:size of buffer
 * Return: x
 */
ssize_t  read_buf(info_t *info, char *buffer, size_t *a)
{
	ssize_t x = 0;

	if (*a)
		return (0);
	x = read(info->readfd, buffer, READ_BUFFER_SIZE);
	if (x >= 0)
		*a = x;
	return (x);
}
/**
 * _getline - gets the next line of inputs
 * @info: is the paramater struct
 * @pt: is the adress of the pointer to buffer
 * @leng: size of preallocated pt
 * Return:Always success
 */
int _getline(info_t *info, char **pt, size_t *leng)
{
	static char buffer[REA_BUFFER_SIZE];
	static size_t a, d;
	size_t q;
	ssize_t x = 0, c = 0;
	char *f = NULL, *new_f = NULL, *b;

	*f = *pt;
	if (f && leng)
		c = *leng;
	if (a == d)
		a = d = 0;
	x = read_buffer(info, buffer, &d);
	if (x == -1 || (x == 0 && d == 0))
		return (-1);
	b = _strchr(buffer + a, '\n');
	q = b ? 1 + (unsigned int)(b - buffer) : d;
	new_f = _realloc(f, c, c ? c + q : q + 1);
	if (!new_f)
		return (f ? free(f), -1 : -1);
	if (c)
		_strncat(new_f, buffer + a, q - a);
	else
		_strncpy(new_f, buffer + a, q - a + 1);
	c += q - a;
	a = q;
	f = new_f;
	if (leng)
		*leng = c;
	*pt = f;
	return (c);
}
/**
 * sigintHandler - blocking ctr + C
 * @sig_n: the signal number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_n)
{
	_puts("\n");
	_puts("$");
	_putchar(BUFF_FLUSH);
}
