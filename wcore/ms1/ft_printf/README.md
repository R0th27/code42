*This project has been created as part of the 42 curriculum by htoe.*

# ft_printf

## Description

`ft_printf` is a simplified reimplementation of the standard C `printf` function from the `<stdio.h>` library.

This project reproduces the core behavior of `printf`: formatted output to standard output and returning the exact number of printed characters. Only a restricted set of format specifiers is supported, as defined by the project requirements.

The implementation prioritizes correctness, explicit edge-case handling, and deterministic behavior.

---

## Supported Conversions

The following format specifiers are supported:

- `%c` — character  
- `%s` — string  
- `%p` — pointer address  
- `%d`, `%i` — signed decimal integer (base 10)  
- `%u` — unsigned decimal integer (base 10)  
- `%x` — hexadecimal (lowercase)  
- `%X` — hexadecimal (uppercase)  
- `%%` — literal `%`

The function returns the total number of characters written to standard output.

---

## Compilation

The project is compiled as a static library using the provided `Makefile`.

```bash
make			#generate libftprintf.a

make fclean		#remove all files

make clean		#remove .o files

make re			#recompilation
```

## Project Structure

```
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
└── ft_printf_utils.c
```

## Usage Example

```c
ft_printf("Char: %c\n", 'A');			//Char: A
ft_printf("String: %s\n", NULL);		//String: (null)
ft_printf("Pointer: %p\n", NULL);		//Pointer: (nil)
ft_printf("Signed: %d\n", -42);			//Signed: -42
ft_printf("Unsigned: %u\n", -42);		//Unsigned: 4294967254
ft_printf("Hex: %x %X\n", 255, 255);	//Hex: ff FF
```

>Note: Negative values passed to `%u` are interpreted as unsigned integers.

## Edge Case Handling

- `%s`

	* If the string is `NULL`, `(null)` is printed

- `%p`

	* If the pointer is `NULL`, `(nil)` is printed

- `%d`, `%i`

	* Correct handling of negative values and `INT_MIN`

- `%u`, `%x`, `%X`

	* Treated as unsigned int values

- `%%`

	* Prints a literal `%` character

## Return Value Management

The return value is tracked using **a static counter** that increments every time a character is written.

```c
int	ft_count(int flag)
{
	static int	count = 0;

	if (flag == 0)
		count++;
	else
		count = 0;
	return (count);
}
```

Each call to `ft_printf_putchar` updates the counter:

```c
void	ft_printf_putchar(char c)
{
	write(1, &c, 1);
	ft_count(0);
}
```

* The counter persists across function calls

* The counter is reset explicitly at the end of ft_printf

* This guarantees an accurate character count without buffering

## Internal Dispatch Logic

Format specifiers are handled through a dedicated dispatcher:

```c
void	flag_check(va_list args, char c);
```
Each specifier maps to a single, well-defined helper function.
Unsupported specifiers are ignored.

## Number Conversion Strategy

All numeric conversions are implemented iteratively, not recursively.

This ensures:

- Predictable stack usage

- Fixed memory bounds

- No recursive call overhead

### Pointer Conversion (`%p`)

```c
int	temp[16];
```

- Uses `unsigned long long` to store the address

- Maximum of 16 hexadecimal digits

- Printed with `0x` prefix

- `(nil)` is printed if the pointer is `NULL`

### Decimal Integer Conversion (`%d`, `%i`, `%u`)

```c
int	temp[10];
```

- Handles signed and unsigned integers via a flag

- Internally uses `long` to safely process `INT_MIN`

- Maximum of 10 digits required for 32-bit integers

### Hexadecimal Conversion (`%x`, `%X`)

```c
int	temp[8];
```

- Handles 32-bit unsigned integers

- Supports lowercase and uppercase output

- Maximum of 8 hexadecimal digits

## Design Choices

### Flag-Based Function Reuse

Flags are used to avoid duplicated logic:

- Signed vs unsigned integer output

- Lowercase vs uppercase hexadecimal output

This keeps the codebase compact and consistent.

### No Output Buffering

Unlike the original `printf`, this implementation does not use an internal buffer.

- Each character is written immediately using `write()`

- Simplifies control flow and debugging

- Prioritizes correctness over performance

## Limitations

- No support for flags (`+`, `-`, `0`, `#`)

- No width or precision handling

- No floating-point conversions

- No locale-specific formatting

Only the listed conversions are supported.

## Resources

- [Variadic Functions in C — GeeksforGeeks](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)

- [Printf Format Specification — Wikipedia](https://en.wikipedia.org/wiki/Printf)

- [C Data Types and Limits — MBED](https://os.mbed.com/handbook/C-Data-Types)