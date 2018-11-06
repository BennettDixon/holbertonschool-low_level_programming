#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
void safe_close(int);
/**
 * main - entry point for program to copy files
 * @argc: count of arguments passed
 * @argv: array of char pointers to the arguments
 *
 * Return: 1 on success, exits on failure w/ error code
 */
int main(int argc, char *argv[])
{
	char buff[1024];
	int bytes_read = 0, _EOF = 1, from_fd = -1, to_fd = -1, err = 0, len = 0;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from_fd = open(argv[1], O_RDONLY);
	if (from_fd < 0) /* file didn't exist */
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	while (_EOF)
	{
		if (bytes_read < 1024)
			to_fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
		else if (bytes_read < 2048)
			to_fd = open(argv[2], O_WRONLY | O_APPEND);
		if (to_fd < 0) /* failed to open/create to_file */
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			safe_close(from_fd);
			exit(99);
		}
		_EOF = read(from_fd, buff, 1024);
		if (_EOF < 0) /* error reading file */
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			safe_close(from_fd);
			safe_close(to_fd);
			exit(98);
		}
		bytes_read += _EOF, len = 0;
		while (buff[len])
			len++;
		err = write(to_fd, buff, len);
		if (err < 0) /* failed to write */
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			safe_close(from_fd);
			safe_close(to_fd);
			exit(99);
		}

		if (bytes_read <= 1024)
			safe_close(to_fd);
	}
	if (bytes_read > 1024) /* didn't close it in loop, close now */
		safe_close(to_fd);
	safe_close(from_fd);
	return (1);
}

/**
 * safe_close - closes a file and exits/prints error if close encounters error
 * @filedescriptor: file descriptor for file to be closed
 *
 * Return: always void, exits on failure
 */
void safe_close(int filedescriptor)
{
	int err;

	err = close(filedescriptor);
	if (err < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", filedescriptor);
		exit(100);
	}
}
