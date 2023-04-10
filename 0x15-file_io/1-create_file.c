#include "main.h"

/**
 * create_file - Create a file.
 * @filename:The name of the file to create.
 * @text_content: A string to write to the file.
 *
 * Return: If the function shows success return 1 else -1.
 */
int create_file(const char *filename, char *text_content)
{
	int openfile;
	int writefile;
	int length = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (length = 0; text_content[len];)
			length++;
	}

	openfile = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	writefile = write(openfile, text_content, length);

	if (openfile == -1 || writefile == -1)
		return (-1);

	close(openfile);

	return (1);
}
