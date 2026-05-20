*This project has been created as part of the 42 curriculum by ikryvenk*

# Description

The but of function 'GET_NEXT_LINE' is to return one line at a time from the file or frome the standart input. We give a file descriptor to the funtion 'char *get_next_line(int fd)' like a parameter. Whene there is nothing left to read or if an error occurs, it should return NULL. This returned line is always termined with '\n' character, except when the end of the file is reached and the file does not end whith a \n character.

# Instraction

You should compile two files:
- get_next_line.c
- get_next_line_utils.c

You can also compile it with this option: '-D BUFFER_SIZE=n', n can be every positive number. It will define the buffer size for read().

But there are not a main functions, so you can call 'get_next_line' function, like a argument you should put file descriptor 'fd'. 

# Resources

I used:

 -  [Geeksforgeeks](https://www.geeksforgeeks.org/questions/c/): for found some information about BUFFER_SIZE and static variables.
- [Stackoverflow](https://stackoverflow.com/questions): for read more about some staff, some bugs.
- [Tester(Tripouille)](https://github.com/Tripouille/gnlTester): for do a final test of my program.
- I used Gemini throughout the project, to understand better where I have some memory leaks.

# Algorithm

At first I check if there are not in a buffer already a full line, if there are not, I read frome a file and stock it in my buffer. I check if there are a '\n' new line, if it is I put this line into my line variable, dalate this line from buffer and move the additional information in my buffer to the start of the buffer. If there are not a new line in my buffer, I put all information into a line and read again, I repeat it untill I find a new line. I use 2 malloc for my line, and whene I add new information to line, I use temporary value to stock and add old information. For me it's the first algoritme that I imagine. There are only two problems, it's a little bit long, because I check all, every time symbol by symbol. And the second you cann't put the negative buffer_size it would not compile. I don't think that's a probleme becouse it doesn't make any sense.

# Bonus

I use only one static variable even in my mandatory part. And I manage the multiple file at the same time if the buffer_size isn't very big, because I stock memory at the start for every file descriptor, and if the buffer_size is very big, the computer just can't give such many space. For the bonus you can compile just 'get_next_line_bonus.c' and 'get_next_line_utils_bonus.c' with this option: '-D BUFFER_SIZE=n'.


