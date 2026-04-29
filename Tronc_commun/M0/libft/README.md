*This project has been created as a part of the 42 curriculum by aldecroi*

# Description : Libft is a library containing reimplemented C standard functions and additional utility functions useful for future 42 projects.

	libc functions :
	- isalpha	-	returns 1 if c is an uppercase or lowercase letter, else returns 0
	- isdigit	-	returns 1 if c is a digit (0-9), else returns 0
	- isalnum	-	returns 1 if c is a digit or a letter, else returns 0
	- isascii	-	returns 1 if c is a valid ASCII character (0-127), else returns 0
	- isprint	-	returns 1 if c is a printable character, else returns 0
	- strlen	-	returns the length of a string, not counting the null terminator
	- memset	-	fills n bytes of memory with the byte value c
	- bzero		-	fills n bytes of memory with zeros
	- memcpy	-	copies n bytes from src to dst, undefined behavior if regions overlap
	- memmove	-	copies n bytes from src to dst, safe even if regions overlap
	- strlcpy	-	copies src into dst up to size - 1 characters, always null terminates, returns length of src
	- strlcat	-	appends src to dst up to size total bytes, returns combined length of both strings
	- toupper	-	converts a lowercase letter to uppercase, returns the character unchanged if not a letter
	- tolower	-	converts an uppercase letter to lowercase, returns the character unchanged if not a letter
	- strchr	-	returns a pointer to the first occurrence of c in s, NULL if not found
	- strrchr	-	returns a pointer to the last occurrence of c in s, NULL if not found
	- strncmp	-	compares up to n bytes of two strings, returns the difference of the first differing byte
	- memchr	-	searches n bytes for the first occurrence of c, returns a pointer to it or NULL
	- memcmp	-	compares n bytes of two memory regions, returns the difference of the first differing byte
	- strnstr	-	finds the first occurrence of needle in haystack within len bytes, returns a pointer to it or NULL
	- atoi		-	converts a string to an integer, handles leading whitespace and sign
	- calloc	-	allocates nmemb * size bytes of zeroed memory, returns a freeable pointer even if size is 0
	- strdup	-	allocates and returns a copy of the string s

	Additional functions :
	- ft_substr		-	allocates and returns a substring of s starting at index start with maximum length len
	- ft_strjoin	-	allocates and returns a new string of s1 and s2 concatenated
	- ft_strtrim	-	allocates and returns a copy of s1 with all characters in set removed from both ends
	- ft_split		-	allocates and returns an array of strings by splitting s using c as delimiter, NULL terminated
	- ft_itoa		-	allocates and returns a string representing the integer n, handles negative numbers
	- ft_strmapi	-	allocates and returns a new string created by applying f to each character of s with its index
	- ft_striteri	-	applies f to each character of s passing its index, modifies the string in place
	- ft_putchar_fd	-	outputs the character c to the file descriptor fd
	- ft_putstr_fd	-	outputs the string s to the file descriptor fd
	- ft_putendl_fd	-	outputs the string s followed by a newline to the file descriptor fd
	- ft_putnbr_fd	-	outputs the integer n to the file descriptor fd

	linked list :
	- ft_lstnew			-	allocates and returns a new node with content set and next set to NULL
	- ft_lstadd_front	-	adds the node new at the beginning of the list
	- ft_lstsize		-	returns the number of nodes in the list
	- ft_lstlast		-	returns the last node of the list
	- ft_lstadd_back	-	adds the node new at the end of the list
	- ft_lstdelone		-	frees the content of a node using del then frees the node itself, does not touch next
	- ft_lstclear		-	deletes and frees all nodes from the given node onwards, sets the pointer to NULL
	- ft_lstiter		-	applies the function f to the content of every node in the list
	- ft_lstmap			-	creates a new list by applying f to each node's content, frees everything on failure

# Instructions :
	- make			: compiles the mandatory part and creates libft.a
	- make clean	: removes all object files
	- make fclean	: removes object files and libft.a
	- make re		: runs fclean then all
	- to reuse libft: add #include "libft.h" in your file and compile with -L. -lft

# Resources :
	- Man pages for all reimplemented functions
	- 42 Libft subject (Libft.pdf)
