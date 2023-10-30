#include "main.h"

/**
 * read_textfile - reads letters from a text file and prints them
 * @filename: filename.
 * @letters: numbers of letters printed.
 * Return: numbers of letters printed. If it fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fod;
	ssize_t nrd, nwr;
	char *buff;

	if (!filename)
		return (0);

	fod = open(filename, O_RDONLY);
	if (fod == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters + 1)); // Allocate space for the null terminator
	if (!buff)
		return (0);

	nrd = read(fod, buff, letters);
	if (nrd == -1) {
		free(buff);
		close(fod);
		return (0);
	}

	nwr = write(STDOUT_FILENO, buff, nrd);
	if (nwr == -1) {
		free(buff);
		close(fod);
		return (0);
	}

	close(fod);
	free(buff);

	return (nwr);
}
