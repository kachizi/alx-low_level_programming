#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content written in the file.
 * Return: 1 if it succeeds, -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fod, rwr, nleos;

	if (!filename)
		return (-1);

	fod = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fod == -1)
		return (-1);

	if (text_content)
	{
		for (nleos = 0; text_content[nleos]; nleos++)
			;
		rwr = write(fod, text_content, nleos);
		if (rwr == -1)
		{
			close(fod);
			return (-1);
		}
	}

	close(fod);

	return (1);
}
