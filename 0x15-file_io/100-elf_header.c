#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *magic_numbers);
void print_magic(unsigned char *magic_numbers);
void print_class(unsigned char *magic_numbers);
void print_data(unsigned char *magic_numbers);
void print_version(unsigned char *magic_numbers);
void print_abi(unsigned char *magic_numbers);
void print_osabi(unsigned char *magic_numbers);
void print_type(unsigned int elf_type, unsigned char *magic_numbers);
void print_entry(unsigned long int entry_point, unsigned char *magic_numbers);
void close_elf(int file_descriptor);

/**
* check_elf - Checks if a file is an ELF file.
* @magic_numbers: A pointer to an array containing the ELF magic numbers.
*
* Description: If the file is not an ELF file - exit code 98.
*/
void check_elf(unsigned char *magic_numbers)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (magic_numbers[index] != 127 &&
	magic_numbers[index] != 'E' &&
	magic_numbers[index] != 'L' &&
	magic_numbers[index] != 'F')
	{
	dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
	exit(98);
	}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *magic_numbers)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
	printf("%02x", magic_numbers[index]);

	if (index == EI_NIDENT - 1)
	printf("\n");
	else
	printf(" ");
	}
}

/**
* print_class - Prints the class of an ELF header.
* @magic_numbers: A pointer to an array containing the ELF class.
*/
void print_class(unsigned char *magic_numbers)
{
	printf(" Class: ");

	switch (magic_numbers[EI_CLASS])
	{
	case ELFCLASSNONE:
	printf("none\n");
	break;
	case ELFCLASS32:
	printf("ELF32\n");
		break;
	case ELFCLASS64:
	printf("ELF64\n");
	break;
	default:
	printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
	}
}

/**
* print_data - Prints the data of an ELF header.
* @magic_numbers: A pointer to an array containing the ELF class.
*/
void print_data(unsigned char *magic_numbers)
{
	printf(" Data: ");

	switch (magic_numbers[EI_DATA])
	{
	case ELFDATANONE:
	printf("none\n");
		break;
	case ELFDATA2LSB:
	printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
	break;
	default:
	printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
	}
}

/**
* print_version - Prints the version of an ELF header.
* @magic_numbers: A pointer to an array containing the ELF version.
*/
void print_version(unsigned char *magic_numbers)
{
	printf(" Version: %d", magic_numbers[EI_VERSION]);

	switch (magic_numbers[EI_VERSION])
	{
	case EV_CURRENT:
	printf(" (current)\n");
	break;
	default:
	printf("\n");
	break;
	}
}

/**
* print_osabi - Prints the OS/ABI of an ELF header.
* @magic_numbers: A pointer to an array containing the ELF version.
*/
void print_osabi(unsigned char *magic_numbers)
{
	printf(" OS/ABI: ");

	switch (magic_numbers[EI_OSABI])
	{
	case ELFOSABI_NONE:
	    printf("UNIX - System V\n");
	break;
	case ELFOSABI_HPUX:
	printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
	printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
	printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
	printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
	printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
	printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
	printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
	printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
	printf("Standalone App\n");
		break;
	default:
	printf("<unknown: %x>\n", magic_numbers[EI_OSABI]);
	}
}

/**
* print_abi - Prints the ABI version of an ELF header.
* @magic_numbers: A pointer to an array containing the ELF ABI version.
*/
void print_abi(unsigned char *magic_numbers)
{
	printf(" ABI Version: %d\n", magic_numbers[EI_ABIVERSION]);
}

/**
* print_type - Prints the type of an ELF header.
* @elf_type: The ELF type.
* @magic_numbers
*/
