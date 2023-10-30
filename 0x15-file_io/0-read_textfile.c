#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to be read
 * @letters: number of letters to read and print
 * PESSYKAPERE
 * Return: the number of letters printed, or 0 if it failed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	int r, w; /* read & write character counter */
	int f;  /* File descriptor */

	if (!filename)
		return (0);

	f = open(filename, O_RDONLY);
	if (f < 0)
		return (0);

	buffer = malloc(letters * sizeof(char));
	if (buffer == NULL)
		return (0);

	r = read(f, buffer, letters);
	if (r < 0)
	{
		free(buffer);
		return (0);
	}
	buffer[r] = '\0';
	close(f);

	w = write(STDOUT_FILENO, buffer, r);
	free(buffer);

	if (w < 0)
		return (0);

return (w);
}
