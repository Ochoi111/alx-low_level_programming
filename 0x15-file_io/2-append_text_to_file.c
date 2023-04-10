#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: A null terminated string to add to the end of the file.
 *
 * Return: Return 1 on success and -1 on failure. if file is null return -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int openfile, writefile, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[length];)
			length++;
	}

	openfile = open(filename, O_WRONLY | O_APPEND);
	writefile = write(openfile, text_content, len);

	if (openfile == -1 || writefile == -1)
		return (-1);

	close(openfile);

	return (1);
}
