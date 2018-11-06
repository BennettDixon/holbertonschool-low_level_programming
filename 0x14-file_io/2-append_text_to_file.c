#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - appends text to a file
 * @filename: the filename to open and append to
 * @text_content: text to append onto new file
 *
 * Return: 1 on success, -1 on failure (file can not be created, or written,
 * or write fails, etc).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, err, len;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0) /* failed opening file */
		return (-1);
	if (!text_content)
	{ /* there is a file, but no new content to write to it */
		close(fd);
		return (1);
	}
	while (*(text_content + len))
		len++;
	err = write(fd, text_content, len);
	close(fd);
	if (err < 0)
		return (-1);
	return (1);
}
