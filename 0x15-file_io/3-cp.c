#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *output_file);
void close_file_descriptor(int descriptor);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @output_file: The name of the output file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *output_file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", output_file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file_descriptor - Closes a file descriptor.
 * @descriptor: The file descriptor to be closed.
 */
void close_file_descriptor(int descriptor)
{
	int result;

	result = close(descriptor);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", descriptor);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If the source file does not exist or cannot be read - exit code 98.
 * If the destination file cannot be created or written to - exit code 99.
 * If file descriptors cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	read_bytes = read(source_fd, buffer, 1024);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (source_fd == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_bytes = write(destination_fd, buffer, read_bytes);
		if (destination_fd == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_bytes = read(source_fd, buffer, 1024);
		destination_fd = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(buffer);
	close_file_descriptor(source_fd);
	close_file_descriptor(destination_fd);

	return (0);
}
