## **Get Next Line**
> Reading a line from a fd is way too tedious

### **Aim**
This project is about programming a function that returns a line read from a file descriptor. The returned line must run until a `\n` is found or until the end of file (EOF) is found.
The resulting function is a very convenient function to add to our previously coded `libft`. The project also teaches us about a very interesting concept: *static variables*.

### **Documentation and Development**
In order to properly develop and write this project, it is extremely important to understand a series of concepts:
- Firstly, *static variables*. A static variable is a variable which has the ability of preserving its value even if we go out of its scope. For that reason, a static variable keeps its value, they are preserved in memory while the program executes while local variables are destroyed after the call to the function is ended.
- Another interesting fact about static variables is that they are initialised in 0 if they are not specifically initialised.
- Secondly, the concept of *buffer*, a temporary memory area in which data is stored while it is being processed or transferred.
- Thirdly, the usage of the *read* function. This function belongs to the ``unistd.h`` library and it is declared as follows:

 > ssize_t read(int fildes, void *buf, size_t nbyte);

- This function reads data previously written to a file, stores whatever was read in a void *variable which acts as a buffer and returns the amount of characters read from the file. If the return value is 0, it means the EOF has been reached. If the return value is -1, it means an error was encountered.

The main challenge of this project's implementation is memory management: not a single memory leak is allowed. In order to test this, it is useful to run the program with the ``-fsanitize=address -g3`` flag. Any segfaults or leaks will be tracked more easily thanks to it. Additionally, it is useful to use the system leaks command or valgrind, again, to help us track any possible leak down. Moreover, the usage of ``malloc()`` and ``ft_calloc()`` should always be implemented along with a ``free()`` call.

### **Testing**
The  ``tests`` folder includes a couple of .txt files which can be used as tests, create a main and check your function! 

Enjoy!
