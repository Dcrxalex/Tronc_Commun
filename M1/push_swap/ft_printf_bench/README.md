*This project has been created as part of the 42 curriculum by ikryvenk*

# Descriprion

The goal of this project is to reproduce the behavior of printf function. The but was to implement the folloving conversions:

- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign

# Instructions:

The project includes a Makefile to automate the compilation process. Use the following commands in your terminal:

- all: Compiles the library and generates the libftprintf.a file.
- clean: Removes all object files (.o).
- fclean: Removes object files and the compiled library file (libftprintf.a).
- re: Performs a full re-compilation (fclean + all).
- bonus: Compiles the library with the bonus part.

# Recources

I used :

-  [Geeksforgeeks](https://www.geeksforgeeks.org/questions/c/): for found some information about printf and variadic function.
- [Makefile](https://www.gnu.org/software/make/manual/make.html): for found more information about makefile
- [Stackoverflow](https://stackoverflow.com/questions): for read more about some bugs
- [Fun](https://superdebile.com/): just for fun
- I used Gemini throughout the project, but not so much, so when I'm writing it, I don't really remember for what.

# Details

I take all the string in my function `int	ft_printf(const char *str, ...)`, after I search the '%' and I check the symbol after it, then I take it from my list and I print it. The function ft_printf returns number of printed character, and in case fo error it returns the negative value.

I didn't use my Libft because I use only some of this function, and also I changed some of them to win some space, and to be more flexible, also I added some other function(for exemple: ft_putnbr_base).

## Bonus

I did only one bonus, I manage following flags: 

> "# +"

At first I created two files one ft_printf.c and onother for bonus part ft_printf_bonus.c.
But after I found some trouble in Makefile, because subject says that we cannot recompile files if we didn't change it. So when I do all command and after bunus command, it add ft_printf_bonus in my library, but ft_printf still be there so it doesn't work. I read egain all instruction and they say that I should include a bonus rule in my Makefile, so I did it. And it should add all the various headers, libraries, or functions taht are not allowed in the main part fo the project. So i don't use some forbidden things in my bonus part. So I just put all my bonus in mandatory part and now I have only one file ft_printf.c which is doing two part mandatory and bonus part.