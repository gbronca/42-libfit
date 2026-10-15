*This project has been created as part of the 42 curriculum by `gcouto-b`*

# libft

## About

This is the very first project of the 42 School Common Core curriculum. It is a re-implementation of some of the *C standard library* functions.

### Part 1 - Libc functions

- ft_isalpha - Returns `1` if a character is an alphabet letter (a-z).
- ft_isdigit - Returns `1` if a character is an numeric digit (0-9).
- ft_isalnum - Returns `1` if a character is alphanumeric, meaning an alphabet letter (a-z) or a number (0-9).
- ft_isascii - Returns `1` if an integer character code is a 7-bit ASCII character.
- ft_isprint - Returns `1` if the given character can be printed (numbers, letters, punctuation characters or space).
- ft_strlen - Get the length of a string.
- ft_memset - Set memory to a given value.
- ft_bzero - Set the first part of an object to null bytes (filling it with zeroes).
- ft_memcpy - Copy bytes from one buffer to another.
- ft_memmove - Copy bytes from one buffer to another, handling overlapping memory correctly.
- ft_strlcpy - Size-bounded string copy.
- ft_strlcat - Size-bounded string concatenation.
- ft_toupper - Converts the lowercase alphabet to the uppercase alphabet.
- ft_tolower - Converts the uppercase alphabet to the lowercase alphabet.
- ft_strchr - Find the first occurrence of a character in a string.
- ft_strrchr - Find the last occurrence of a character in a string.
- ft_strncmp - Compare two strings, up to a given length.
- ft_memchr - Find the first occurrence of a character in a buffer (locate byte in byte string).
- ft_memcmp - Compare the bytes in two buffers.
- ft_strnstr - Locate a substring in a string.
- ft_atoi - Convert ASCII string to integer.
- ft_calloc - Allocate space for an array and initializes it to 0. This function and malloc return a void pointer, that had no associated data type with it. A void pointer can hold address of any type and can be typecasted to any type.
- ft_strdup - Create a duplicate of a string, using malloc.

### Part 2 - Additional functions

- ft_substr - Returns a substring from string `s`.
- ft_strjoin - Returns concatenation of strings `s1` and `s2`.
- ft_strtrim - Trims the characters specified in `set` from the beginning and the end of the string.
- ft_split - Returns an array of strings obtained by splitting the string using a delimiter.
- ft_itoa - Returns a string representation of an integer.
- ft_strmapi - Returns a new string modified by a given function.
- ft_striteri - Modifies a string with a given function.
- ft_putchar_fd - Outputs a character to a given file.
- ft_putstr_fd - Outputs a string to a given file.
- ft_putendl_fd - Outputs a string to a given file, followed by a newline.
- ft_putnbr_fd - Outputs an integer to a given file.

### Part 3 - linked lists

ft_lstnew - Creates a new list.
ft_lstadd_front - Adds a new node to the beginning of the list.
ft_lstsize - Counts the number of nodes in the list.
ft_lstlast - Returns the last node of the list.
ft_lstadd_back - Adds a new node to the end of the list.
ft_lstdelone - Deletes one node from the list.
ft_lstclear - Deletes and frees the given node and all its successors.
ft_lstiter - Iterates through the nodes in the list and applies the function `f` to the content of each node.
ft_lstmap - Iterates through the nodes in the and applies the function `f`. Returns a new list.

## Installation

- Clone the repo with `git clone`.
- `make` to compile the library.
- To remove the object files, use `make clean`.
- To remove the object files and the executable, use `make fclean`.
- To use the library, simply import its header into your code `#include "libft.h"`.

## Resources

- `man`
- [man7.org](https://man7.org/linux/man-pages/index.html)

## Pitfalls, Edge Cases & Curiosities

- `size_t` is never negative. With `size_t`, decrementing past `0` wraps around to `SIZE_MAX`, the largest value.
- **`ft_strrchr`** since `size_t len` can never be negative, to use `size_t` instead of `int` we need to decrement at the top of the loop. Otherwise, the function keeps scanning backwards through the memory until it reaches memory it can’t read, and crashes.

```c
len = ft_strlen(s) + 1;
while (len > 0)
{
  len--;
  if (s[len] == (char)c)
    return ((char *)&s[len]);
}
return (NULL);
```

- **`ft_strnstr`** in the outer loop, we need to check `len` first or it would crash if the function is called with these parameters: `ft_strnstr(NULL, "a", 0)`. Also, it fails if the passed string has no terminator (`'\0`).

- **`ft_strjoin`** treats a `NULL` argument as an empty string, so `ft_strjoin(NULL, "a")` and `ft_strjoin("a", NULL)` both return a new copy of `"a"`. `ft_strjoin(NULL, NULL)` returns an allocated string `""` and not `NULL`.
