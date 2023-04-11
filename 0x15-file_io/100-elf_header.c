#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void check_elf-type(unsigned char *condi);
void print_elf_mag(unsigned char *condi);
void print_elf_class(unsigned char *mag);
void print_data(unsigned char *indent);
void print_elf_version(unsigned char *mag);
void print_osabi(unsigned char *mag);
void print_abi_version(unsigned char *mag);
void print_type(unsigned int type, unsigned char *ident);
void print_entry(unsigned long int entry, unsigned char *ident);
void close_elf(int elf_fd);
/**
 * check_elf_type - Checks if a file is an ELF file.
 * @condi: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf_type(unsigned char *condi)
{
	int i;

	for (i = 0; index < 4; i++)
	{
		if (condi[i] != 127 &&
		    condi[i] != 'E' &&
		    condi[i] != 'L' &&
		    condi[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * print_elf_mag - Prints the magic numbers of an ELF header.
 * @magic: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_elf_mag(unsigned char *condi)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", condi[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * print_elf_class - Prints the class of an ELF header.
 * @mag: A pointer to an array containing the ELF class.
 */
void print_elf_class(unsigned char *mag)
{
	printf("  Class:                             ");

	switch (mag[EI_CLASS])
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
		printf("<unknown: %x>\n", mag[EI_CLASS]);
	}
}
/**
 * print_data - Prints the data of an ELF header.
 * @ident: An array containing the ELF class.
 */
void print_data(unsigned char *indent)
{
	printf("  Data:                              ");

	switch (ident[EI_DATA])
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
		printf("<unknown: %x>\n", indent[EI_CLASS]);
	}
}
/**
 * print_elf_version - Prints the version of an ELF header.
 * @mag: A pointer to an array containing the ELF version.
 */
void print_elf_version(unsigned char *mag)
{
	printf("  Version:                           %d",
	       mag[EI_VERSION]);

	switch (mag[EI_VERSION])
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
 * @mag: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *mag)
{
	printf("  OS/ABI:                            ");

	switch (mag[EI_OSABI])
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
		printf("<unknown: %x>\n", mag[EI_OSABI]);
	}
}
/**
 * print_abi_version - Prints the ABI version of an ELF header.
 * @mag: A pointer to an array containing the ELF ABI version.
 */
void print_abi_version(unsigned char *mag)
{
	printf("  ABI Version:                       %d\n",
			mag[EI_ABIVERSION]);
}
/**
 * print_type - Prints the type of an ELF header.
 * @type: The ELF type.
 * @ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int type, unsigned char *ident)
{
	if (ident[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}
/**
 * print_entry - Prints the entry point of an ELF header.
 * @entry: The address of the ELF entry point.
 * @ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int entry, unsigned char *ident)
{
	printf("  Entry point address:               ");

	if (ident[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);

	else
		printf("%#lx\n", entry);
}
/**
 * close_elf - Closes an ELF file.
 * @elf_fd: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf_fd)
{
	if (close(elf_fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf_fd);
		exit(98);
	}
}
/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fD, read_status;

	fD = open(argv[1], O_RDONLY);
	if (fD == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(fD);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	read_status = read(fD, header, sizeof(Elf64_Ehdr));
	if (read_status == -1)
	{
		free(header);
		close_elf(fD);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf_type(header->e_ident);
	printf("ELF Header:\n");
	print_elf_mag(header->e_ident);
	print_elf_class(header->e_ident);
	print_data(header->e_ident);
	print_elf_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi_version(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(fD);

	return (0);
}
