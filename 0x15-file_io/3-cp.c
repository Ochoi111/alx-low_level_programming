#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - read 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing characters for.
 *
 * Return: Pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Close the file descriptors.
 * @Fd: file descriptor(fd) to be closed.
 */
void close_file(int Fd)
{
	int a;

	a = close(Fd);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", Fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 */
int main(int argc, char *argv[])
{
	int file_from;
	int file_to;
	int readfile;
	int writefile;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	readfile = read(from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || readfile == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		writefile = write(file_to, buffer, r);
		if (end == -1 || writefile == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		readfile = read(file_from, buffer, 1024);
		end = open(argv[2], O_WRONLY | O_APPEND);

	} while (readfile > 0);

	free(buffer);
	close_file(file_from);
	close_file(file_to);

	return (0);
}
