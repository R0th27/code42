*This project has been created as part of the 42 curriculum by htoe.*

# Get_Next_Line

## Description

A “Description” section that clearly presents the project, including its goal and a brief overview.

Using the system function `read()` from **unistd header**, we can obtain the content from a valid and readable file. The content may include multiple lines divided with a newline character `\n` or none at all except a single line ended at `EOF`. This function is to get a single line up to `EOF` or `\n` from a file for every time this function is called until we close our file descriptor for that file. 

## Instructions

Open a file with a `OPEN()` function from **fcntl header** and capture the return file descriptor id with an int. And then we can use that int with a get_next_line() function to get a line or NULL if there are no more content left or the file is invalid or empty. 

## Resources

1. [**Input Output System Calls** by geeks for geek](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/
)

	* **OPEN(file, mode)** is a system function that can open a file with a name in string format and the mode can be selected according to the intention. The return value is a valid file descriptor in int type and -1 upon failure due to file does not exist or the file is out of permission.

	* **File Descriptor** is an int type that is assigned to a file which is opened before closing and the default **FD** are **0 for stdin**, **1 for stdout** and **2 for stderr**.

	* **read(fd, buffer, buffer_size)** is a function that can copy a content from a file up to buffer_size into a buffer which is a valid pointer with enough space for buffer_size. The return value is the read bytes from a file and **0 if the end of file `EOF`** is reached or **-1 if the file is modified or moved** before completing the operation. Read function works with offset which persists until file is closed so there is no backtracing if we don't store the content from a buffer before calling it again.

	* **close(fd)** is a system function to remove the assigned value of file descriptor for a file after completing the operation.

2. [**Static Variables** by codeAcademy](https://www.codecademy.com/resources/docs/c/static-variables)

	* **A static variable** is a variable that can store values which will not be clear until we manually remove it in the program throughout the running time.

## Usage Examples

### Brief Operation Steps

The get_next_line function will check for validity of `FD` and `BUFFER_SIZE` first. If there is some left over value in static char named cache, that value will be added into our first node of a linked list. 

**The linked list** includes the pointer to store the read line from a buffer or remaining cache, an int len to store the string length it contains and the pointer to next line. 

If there is no cache or newline character is not found in cache, the function will read the file with **a constant BUFFER_SIZE** set during compilation time until it reaches to a newline or EOF. Everytime we read with BUFFER_SIZE, the copied content will be added to a new node.

Even after that, if the list is empty, we will return **NULL**. If not, we will extract the line from the linked list. That malloced line will be return later.

Before returning the line, the cache will be updated if there are characters after the newline character `\n` or free it if no newline is found in the last node which means the `EOF` has reached. Another important thing to do is to free the linked list to prevent memory leak.

## Explanation For Functions

```c
char	*get_next_line(int fd);
```

>check **the input fd, BUFFER_SIZE** and create the value which can be line created with malloc of NULL

```c
void	add_node(char *line, t_node **head);
```

>create a node with a input string line while storing the len of that string and append to a created linked list

```c
void	parse_file(int fd, t_node **list);
```
>read through the file of a fd with a constant buffer size into a temporary buffer and **add a node** for every read buffer creating a list until the buffer include a newline character

```c
size_t	line_length(t_node *list);
```

>process through the created linked list to acquire the len of the line until the last node. If there is no newline character in last node the len of last node is added to return. If there is a newline character in last node, **the index got from the following formula** is returned.

>***index = address of newline - address of line's start***

```c
char	*update_cache(char *cache, t_node *list);
```

>acquire the last node with a **ft_lstlast** function and if there is no newline character the cache is free and return. If there is a newline the index is calculated like the line_length and the difference between total len and index is allocated memory and copied and returned.

```c
char	*extract_line(t_node *list);
```

>using the length acquired from line_length function, a string is allocated memory and copied from every strings of the linked list and returned.

```c
size_t	ft_strlen(char *str);
```

>calculate the length of incoming string up to the null terminator and the value is returned. 

```c
char	*ft_strchr(const char *s, int c);
```

>find the first occurence of char `c` in a string `s`. The memory address of the occurence is returned if found. If not found or the incoming string is empty, **NULL** is returned.

```c
void	free_list(t_node **list);
```

>loop through the list while freeing the line created with malloc and node created with malloc. the head of the list is set to **NULL** to avoid **dangling pointer** after freeing all the nodes.

```c
t_node	*ft_lstlast(t_node *head);
```

>loop through the list until **the next node is NULL** which indicates the current node is last node. The memory address of the last node is returned. The return value is the incoming memory address if the list is **NULL**.

## Technical Choices

There were two ways I implemented the get_next_line functions. In case the file is too large and there may be newline at the end of file or no newline at all. The buffer has to read according to the set BUFFER_SIZE so if the file is $512$ KB and BUFFER_SIZE is just $4$ B, the file must be read $128000$ times.

1. Using the strjoin while reading the file

	There is no linked list. The static cache is passed to function implemented to read the file. Every buffer call is saved to the cache with strjoin. 
	To complete the $128000$ times of reading, the first buffer must be passed and copied into ft_strjoin for $128000$ times. The last buffer must be copied one time. If we sum all the copied value become $$\frac{(128000 * 128001)} 2 $$ which is $8192064000$ B or $8192064$ KB.
	
	* **pros**: simple way to implement the function
	
	* **cons**: the time complexity becomes $O(n^2$) if the newline is at the end of a big file. 

2. Using the linked list while reading the file

	The linked list store all the read buffer within separated nodes. All the buffer for $128000$ times is stored in $128000$ nodes copying $512000$ B. After that all the lines is copied into an enough sized line copying all $512000$ B. The total copied byte become 1024000B or $1024$ KB.

	* **pros** the time complexity becomes $O(n$) even if the newline is at the end of a big file.

	* **cons** creating 128000 nodes consume memory for node overhead and the usage for memory address become $128000+$. 