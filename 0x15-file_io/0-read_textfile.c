#include <stdio.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX standardoutput.
 * @filename: A pointer to the filename.
 * @letters: The number of letters the function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t outputfile;
	ssize_t readfile;
	ssize_t writefile;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	outputfile = open(filename, O_RDONLY);
	readfile = read(outputfile, buffer, letters);
	writefile = write(STDOUT_FILENO, buffer, readfile);
	if (outputfile == -1 || readfile == -1)
	{
		free(buffer);
		return (0);
	}
	if (writefile == -1 || writefile != readfile)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(outputfile);

	return (writefile);
}
