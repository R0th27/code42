*This project has been created as part of the 42 curriculum by htoe.*

# ft_printf

## Description

This function is a simple prototype of original **printf** function from **stdio header**. The original printf function can print out the following things to stdout or terminal. 

1. a character
2. a string
3. a memory address
4. a decimal integer in base 10
5. an unsigned integer in base 10
6. an unsigned integer in base 16

And the return value of the printf function is the number of characters it printed out to the stdout. 

Although printf can print out more data types, this prototyped function is implemented in order to perform the simple operations mentioned above.

## Instructions

This prototyped function can be compiled with the included Makefile to get **an archived library file** for further uses. 


## Resources

1. [**Variadic Functions in C** by Geek for Geek](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)

	* **Variadic function from stdarg header** can accept the unknown number of argumentss into the function while storing their values with **va_start** to a list called **va_list** which you can access later with **va_arg**.

2. [**Data Types and Thier Values** by MBED](https://os.mbed.com/handbook/C-Data-Types)

	* An integer is stored in 4 Byte of memory. The stored value can be changed to signed or unsigned. 
	
		**Signed integer** use the **first bit as flag for positive or negative** 
	
		**Unsigned integer** can **utilize all 32 bits of memory**
		
		**The value of minimum and maximum** differed according to their nature.

3. [**Memory Allocation in C** by w3schools](https://www.w3schools.com/c/c_memory_allocate.php)

	* Memory allocation happens whenever we run a program. 

	* **Static memory** is reserved and assigned by compiler during compilation time for variables. 

	* **Dynamic memory** is manually assigned by a programmer before compiling and running. Also, it must be freed manually to avoid memory leak and dangling pointers. 

4. [**printf Type field** from Wikipedia](https://en.wikipedia.org/wiki/Printf)

	* Every printf specifier expect a certain data type for input and return a number of printed out characters as an integer. 

5. [**Static Variable** by codeAcademy](https://www.codecademy.com/resources/docs/c/static-variables)

	* **Static variable** are something present throughout the entire program. The lifetime of a local variable within a function scope is during the function runtime. But static variable is something that is persistent during different function calls. 

## Usage Examples

In a normal string, the % sign become the flag and the character after the flag become the specifier.

* example: This is a `%c`

1. `%c` can print out a single charater

2. `%s` can print out a string if present

	* if the string is NULL, it will print out (null)

3. `%p` can print out a memory address of a pointer which is typically 6 Byte long with 12 Hex characters after the prefix **0x**.

	* if the pointer is NULL, it will print out (nil)

4. `%d` `%i` can print out a signed decimal integer which is 4 byte long.

	* **Maximum Value** : 2147483647;
	
	* **Minimum Value** : -2147483648;

5. `%u` can print out an unsigned decimal integer which is 4 byte long

	* **Maximum Value** : 4294967295;
	
	* **Minimum Value** : 0;

6. `%x` `%X` can print out an unsigned integer which is 4 bytes long with a 8 hex characters.

	* **Maximum Value** : FFFFFFFF;
	
	* **Minimum Value** : 00000000;

7. `%%` can print out a single **%** character to avoid confusing the flag with an actual character `%`


## Technical Choices


1. **The usage of flags to avoid duplicated occurences of similar functions**

	The flags are used in 

	* ft_printf_putnbr to differentiate between **signed int with flag 1** or **unsigned int with flag 0**

	* ft_printf_puthex to differentiate between
	**lowercase hexadecimal with flag 0** or **uppercase hexadecimal with flag 1**

2. **Integer conversion methods**

	For now, there are two methods I learnt which are

	1. Conversion inside a while loop of a single function

		* **pros** : one functional call on stack memory and the task can be done.

		* **cons** : the static memory allocated during the implementation to store the computed integers must be enough.

		* **usage** : when the number of loop is certain and the amount of output can be determined.

	2. Conversion with a recursive function

		* **pros** : the functions can be called for any amount of times until the task is done.

		* **cons** : multiple calls for a same function can consume memory as everytime a function is called, it needs to be loaded into a stack memory.

		* **usage** : when the number of loop is uncertain and the base cases can be defined exactly.

3. **Performance vs Simplicity**

	In the original **printf**, there is a buffer which store the characters to print out before actually calling the `write()` to reduce the amount of system function calling time to improve the performance.

	In the implemented **ft_printf**, there is no buffer management and everytime a character is printed out, the `write()` is called.
