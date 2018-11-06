#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints the contents to STDOUT
 * @filename: the filename to open
 * @letters: number of letters to read and print
 *
 * Return: the number of letters read and printed, 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = -1, err = 0, len = 0;
	char *temp_b;

	if (!filename)
		return (0);
	temp_b = malloc(sizeof(char) * letters);
	if (!temp_b)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(temp_b);
		return (0);
	}
	err = read(fd, temp_b, letters);
	if (err < 0)
	{
		free(temp_b);
		return (0);
	}
	while (temp_b && temp_b[len])
		len++;
	err = write(STDOUT_FILENO, temp_b, len);
	free(temp_b);
	close(fd);
	if (err < 0)
		return (0);
	return ((ssize_t)err);
}
