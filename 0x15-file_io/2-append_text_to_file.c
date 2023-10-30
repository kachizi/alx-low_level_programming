#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 * Return: 1 if the file exists. -1 if it does not exist or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fod, rwr, nleos;

	if (!filename)
		return (-1);

	fod = open(filename, O_WRONLY | O_APPEND);
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
