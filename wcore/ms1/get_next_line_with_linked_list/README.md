*This project has been created as part of the 42 curriculum by htoe.*

# get_next_line

## Description

`get_next_line` is a function that reads from a file descriptor and returns a single line each time it is called.

A line is defined as a sequence of characters ending with a newline character (`\n`) or the end of file (`EOF`).  
The function maintains internal state between calls using a static cache variable, allowing partially read data to be preserved and reused correctly.

Only the mandatory (single file descriptor) version is implemented.

---

## Function Prototype

```c
char	*get_next_line(int fd);
```

## Behavior

- Reads from the given file descriptor

- Returns **one line per function call**

- Includes the newline character (`\n`) if present

- Stops reading at `\n` or `EOF`

- Returns `NULL` when there is nothing left to read or on error

## Compilation

The project can be compiled together with the required source files.

```bash
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
```

or

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
	main.c get_next_line.c get_next_line_utils.c
```

## Project Structure

```
.
├── get_next_line.c
├── get_next_line_utils.c
└── get_next_line.h
```

## Usage Example

```c
int		fd;
char	*line;

fd = open("file.txt", O_RDONLY);
while ((line = get_next_line(fd)))
{
	printf("%s", line);
	free(line);
}
close(fd);
```

## Edge Case Handling

- Invalid file descriptor → returns `NULL`

- Read error → returns `NULL`

- Empty file → returns `NULL`

- File without a trailing newline → returns the last line without `\n`

- Newline at buffer boundary → handled correctly

## Internal Design

### Persistent Cache

Unread data is stored in a static cache between function calls.

This allows the function to continue reading exactly where it stopped previously.

### Linked List Buffering

- Data read from the file descriptor is stored in a linked list of nodes:

- Each node stores a chunk read from `read()`

- Avoids unnecessary memory reallocations

- Allows efficient line assembly without repeated string concatenation


### Line Extraction Strategy

The implementation follows these steps:

1. Read data until **a newline** or **EOF** is encountered

2. Store read chunks in a linked list

3. Calculate the exact length of the next line

4. Allocate memory for the line

5. Copy characters up to and including `\n`

6. Update the cache to keep remaining data

This guarantees:

- Exact memory allocation

- No data loss

- No extra reads

## Design Choices

### Iterative Processing

All operations are implemented iteratively:

- No recursion

- Predictable memory usage

- Clear execution flow

### Minimal Memory Allocation

- Memory is allocated only when required

- Unused nodes are freed immediately

- Cache is updated only when unread data remains

### Separation of Responsibilities

Each helper function has a single responsibility:

- Reading data

- Storing chunks

- Extracting a line

- Updating the cache

- Freeing resources

## Notes

- The caller is responsible for freeing the returned string

- BUFFER_SIZE can be defined at compile time.
If not defined, **a default value of 3** is used.

- Bonus version supports multiple file descriptors (up to 1024)


## Resources

[Linux Manual Pages - read(2)](https://linux.die.net/man/2/read)

[Linked Lists - learn-c.org](https://www.learn-c.org/en/Linked_lists)

[cppreference](https://en.cppreference.com/w/c/language/static_storage_duration.html)