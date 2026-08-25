*This project has been created as part of the 42 curriculum by frodrig2.*

# Libft

## Description

Libft is the first project in the 42 curriculum. The goal is to reimplement a set of standard C library functions from scratch, and to develop a collection of additional utility functions that will serve as a personal toolkit throughout the rest of the curriculum.

The project is divided into three parts: a reimplementation of common Libc functions, a set of additional string and memory utilities not found in the standard library (or that exist in a different form), and a suite of functions for manipulating singly linked lists.

An additional fourth part was later merged into the library: a reimplementation of a subset of the standard library's `printf()`, originally developed and submitted as its own standalone 42 project. It was folded into `libft` to consolidate both projects into a single reusable archive.

Beyond the practical output, the project is designed to build a genuine understanding of how foundational C functions work at the byte level — memory layout, pointer arithmetic, string termination, overflow handling — things that are easy to take for granted when using the standard library directly.

The library is compiled into a static archive, `libft.a`, which can be linked into future projects.

The project's code was written in accordance with [The Norm v4.1](https://github.com/42school/norminette/blob/master/pdf/en.norm.pdf).

---

## Instructions

### Compilation

Clone the repository and run `make` at its root:

```sh
git clone https://github.com/aria-v042/Libft.git libft-aria-v042
cd libft-aria-v042
make
```

This produces `libft.a` at the root of the repository.

### Linking

To use the library in your own project, include the header and link against the archive:

```sh
cc your_file.c -L. -lft -I. -o your_program
```

Or, if the library is in a subdirectory:

```sh
cc your_file.c -Llibft -lft -Ilibft -o your_program
```

### Makefile rules

| Rule | Effect |
|---|---|
| `make` / `make all` | Compiles `libft.a` |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Runs `fclean` then `all` |

#### Extra rules

These rules were not included in the official submission of the project, but were left in `.extras/Makefile` for easily allowing users to test and debug either mine or their own implementations from within the `.extras/` folder of this repo.

| Rule | Effect |
|---|---|
| `make test` | Compiles `./test` |
| `make debug <file.c>` | Compiles `./debug` using provided source code file; uses `test.c` if no file is provided |
| `make ft_printf_test` | Compiles `./test_ft_printf` |
| `make tclean` | Removes object files, `libft.a` and `runtests` |
| `make dclean` | Removes object files, `libft.a` and `debug` |
| `make pclean` | Removes object files, `libft.a` and `test_ft_printf` |

---

## Library

*For readability purposes, the following descriptions do not include function prototypes. To consult them, refer to the `libft.h` header file.*

### Part 1 — Libc functions

Reimplementations of standard C library functions. All functions are prefixed with `ft_` and match the behavior described in their respective man pages. They do not rely on any external functions.

With the exception of `ft_memcpy`, which guards against an additional edge case where both `dest` and `src` are null (required by 42's automated tests), every function in this section should behave identically to GNU C Library's implementations.

---

#### Character classification

These functions take an `int` argument (a character value) and return `1` if the character belongs to the tested class, `0` otherwise. Unlike the standard library versions, which may return any non-zero value on match, these always return exactly `1`.

| Function | Description |
|---|---|
| `ft_isalpha` | Returns `1` if `c` is an alphabetic character (`a`–`z` or `A`–`Z`). |
| `ft_isdigit` | Returns `1` if `c` is a decimal digit (`0`–`9`). |
| `ft_isalnum` | Returns `1` if `c` is alphanumeric (alphabetic or digit). |
| `ft_isascii` | Returns `1` if `c` is a valid ASCII character (value 0–127). |
| `ft_isprint` | Returns `1` if `c` is a printable character (including space, values 32–126). |

---

#### Character conversion

| Function | Description |
|---|---|
| `ft_toupper` | Converts a lowercase letter to its uppercase equivalent. Non-lowercase characters are returned unchanged. |
| `ft_tolower` | Converts an uppercase letter to its lowercase equivalent. Non-uppercase characters are returned unchanged. |

---

#### String functions

| Function | Description |
|---|---|
| `ft_strlen` | Returns the number of characters in a string, not counting the null terminator. Passing `NULL` is undefined behavior. |
| `ft_strchr` | Returns a pointer to the first occurrence of character `c` in string `s`, or `NULL` if not found. Correctly handles searching for the null terminator (`'\0'`), returning a pointer to the end of the string. |
| `ft_strrchr` | Like `ft_strchr`, but returns a pointer to the *last* occurrence of `c`. Also handles searching for `'\0'`. |
| `ft_strncmp` | Compares at most `n` bytes of two strings. Returns a negative value, zero, or a positive value depending on whether `s1` is less than, equal to, or greater than `s2`. Comparison is done on `unsigned char` values. |
| `ft_strnstr` | Finds the first occurrence of substring `needle` in `haystack`, searching at most `len` characters. If `needle` is an empty string, returns `haystack`. Returns `NULL` if not found within the limit. |
| `ft_strlcpy` | Copies up to `size - 1` characters from `src` to `dst`, always null-terminating the result if `size > 0`. Returns the length of `src`, allowing callers to detect truncation by comparing the return value against the buffer size. |
| `ft_strlcat` | Appends `src` to `dst`, appending at most `size - strlen(dst) - 1` characters and always null-terminating. Returns the total length it attempted to create (`strlen(src) + MIN(size, strlen(dst))`), which lets callers detect truncation. |
| `ft_strdup` | Allocates memory and returns a duplicate of string `s`. The caller is responsible for freeing the returned pointer. Returns `NULL` on allocation failure. |

> `ft_strlcpy` and `ft_strlcat` are safer alternatives to `strcpy`/`strcat`. The return value convention is specifically designed for truncation detection: if the return value is `>= size`, the output was truncated.

---

#### Memory functions

| Function | Description |
|---|---|
| `ft_memset` | Fills `n` bytes of memory starting at `s` with the byte value `c`. Returns `s`. The value is cast to `unsigned char` before writing, so only the low byte of `c` is used. |
| `ft_bzero` | Zeroes `n` bytes of memory starting at `s`. Equivalent to `ft_memset(s, 0, n)`. |
| `ft_memcpy` | Copies `n` bytes from `src` to `dst`. The source and destination must not overlap; use `ft_memmove` when overlap is possible. Returns `dst`. |
| `ft_memmove` | Copies `n` bytes from `src` to `dst`, correctly handling overlapping memory regions by choosing the copy direction based on the relative positions of the pointers. Returns `dst`. |
| `ft_memchr` | Scans the first `n` bytes of memory at `s` for the byte value `c`. Returns a pointer to the first match, or `NULL` if not found. |
| `ft_memcmp` | Compares the first `n` bytes of two memory regions. Returns a negative value, zero, or a positive value, with comparison done on `unsigned char` values. |

---

#### Conversion

| Function | Description |
|---|---|
| `ft_atoi` | Converts the initial portion of string `str` to an `int`. Leading whitespace is skipped; an optional leading `+` or `-` is handled. Behavior is undefined for values that overflow `int`. |

---

#### Allocation

| Function | Description |
|---|---|
| `ft_calloc` | Allocates memory for an array of `nmemb` elements of `size` bytes each, zeroing the allocated memory. Returns a unique non-NULL pointer even if `nmemb` or `size` is zero (the pointer can be safely passed to `free`). Returns `NULL` on allocation failure or overflow. |
| `ft_strdup` | Allocates memory and returns a duplicate of string `s`. The caller is responsible for freeing the returned pointer. Returns `NULL` on allocation failure. |

---

### Part 2 — Additional functions

Utility functions not found in the standard library, or that exist in a meaningfully different form.

| Function | Description |
|---|---|
| `ft_substr` | Allocates and returns a substring of `s` starting at index `start` with a maximum length of `len`. If `start` is beyond the end of `s`, returns an empty string. Returns `NULL` on allocation failure. |
| `ft_strjoin` | Allocates and returns a new string that is the concatenation of `s1` and `s2`. Returns `NULL` on allocation failure. |
| `ft_strtrim` | Allocates and returns a copy of `s1` with all leading and trailing characters that appear in `set` removed. `set` is treated as a set of characters, not a substring. Returns `NULL` if `s1` is `NULL` or on allocation failure; returns a duplicate of `s1` if `set` is `NULL`. |
| `ft_split` | Allocates and returns a null-terminated array of strings obtained by splitting `s` on the delimiter character `c`. Consecutive delimiters are treated as a single delimiter. Each string in the array is independently allocated. Returns `NULL` if any allocation fails (all previously allocated memory is freed in that case). |
| `ft_itoa` | Allocates and returns a string representation of integer `n`. Handles negative numbers and `INT_MIN` correctly. Returns `NULL` on allocation failure. |
| `ft_strmapi` | Allocates and returns a new string created by applying function `f` to each character of `s`, passing the character's index as the first argument. Returns `NULL` on allocation failure. |
| `ft_striteri` | Applies function `f` to each character of `s` in place, passing the character's index and a pointer to the character. Unlike `ft_strmapi`, this modifies the string directly rather than creating a new one. |

> When using `ft_split`, free both each individual string in the array and the array itself:
> ```c
> char **parts = ft_split(str, ' ');
> int i = 0;
> while (parts[i])
>     free(parts[i++]);
> free(parts);
> ```

---

#### Output functions

These functions write to a file descriptor, making them useful for writing to stdout (`fd = 1`), stderr (`fd = 2`), or any open file.

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes character `c` to file descriptor `fd`. |
| `ft_putstr_fd` | Writes string `s` to file descriptor `fd`. |
| `ft_putendl_fd` | Writes string `s` followed by a newline to file descriptor `fd`. |
| `ft_putnbr_fd` | Writes the integer `n` as a decimal string to file descriptor `fd`. |

---

### Part 3 — Linked list

A suite of functions for manipulating singly linked lists using the following node structure, defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

The `content` field holds a `void *`, allowing nodes to store any type of data. The `next` field points to the next node, or is `NULL` for the last node.

| Function | Description |
|---|---|
| `ft_lstnew` | Allocates and returns a new node with `content` set to the given value and `next` set to `NULL`. Returns `NULL` on allocation failure. |
| `ft_lstadd_front` | Inserts `new` at the beginning of the list pointed to by `lst`. |
| `ft_lstadd_back` | Appends `new` to the end of the list pointed to by `lst`. If the list is empty (`*lst == NULL`), `new` becomes the first node. |
| `ft_lstsize` | Returns the number of nodes in the list. |
| `ft_lstlast` | Returns a pointer to the last node of the list, or `NULL` if the list is empty. |
| `ft_lstdelone` | Frees the content of node `lst` using `del`, then frees the node itself. Does not touch `lst->next`. |
| `ft_lstclear` | Deletes and frees every node in the list starting from `*lst`, using `del` to free each node's content. Sets `*lst` to `NULL` after clearing. |
| `ft_lstiter` | Applies function `f` to the `content` of each node in the list. |
| `ft_lstmap` | Creates a new list by applying `f` to the `content` of each node in `lst`. If any allocation fails, the partially built list is cleared using `del` and `NULL` is returned. |

> `ft_lstdelone` removes a single node without affecting the rest of the list. `ft_lstclear` removes the entire list from a given node onwards. Use `ft_lstdelone` when removing a node mid-traversal (after relinking), and `ft_lstclear` to destroy the whole list.

---

### Part 4 — ft_printf()

*Originally developed and submitted as a standalone 42 project, later merged into this library.*

A reimplementation of a subset of the standard library's `printf()`, using variadic functions to handle a defined set of conversion specifiers.

| Specifier | Output |
|---|---|
| `%c` | Single character |
| `%s` | String (null-terminated, C convention) |
| `%p` | Pointer address in hexadecimal (`0x...`) |
| `%d`, `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned integer in lowercase hexadecimal |
| `%X` | Unsigned integer in uppercase hexadecimal |
| `%%` | Literal percent sign |

The function returns the total number of characters written, matching the behavior of the original `printf()`.

> Internal helpers for this module (`parse_specification()`, the `convert_*()` functions, `ft_putnbr_base()`, and `ft_numlen()`) are declared in `ft_printf/ft_printf.h` and are not part of the library's public interface — only `ft_printf()` itself is exposed via `libft.h`.

#### Algorithms and data structure

##### Format string parsing

The function's core loop iterates through the format string character by character, copying ordinary characters (not %) as-is to the output stream using the `write()` function. When a conversion specification is found, introduced by a % character, the format string pointer is advanced to the next position and is passed to the `parse_specification()` function.

##### Conversion specification parsing

`parse_specification()` takes the conversion specification and the address of the `va_list` of arguments, and routes the latter to the appropriate handler. It is implemented as a series of conditionals mapping each valid specifier to the dedicated conversion function. Unknown or unsupported specifiers are silently ignored.

##### Conversion handling

Each specifier type is handled by a corresponding function responsible for correctly converting the next argument in the `va_list` and writing it to the standard output stream.

The numeric specifiers that require a base conversion share a common utility function `ft_putnbr_base()`, that also updates the variable containing the length of the converted number through its address.

Pointer printing (`%p`) is treated as a special case of hex output: the address is cast to `uintptr_t` and printed with the `0x` prefix prepended. The data type used is `uintptr_t` rather than `unsigned long` or `unsigned int` for compatibility with pointer width variation across architectures.

---

## Testing and debugging

### Testing

Tests were developed independently for the first section of the project. The structure and formatting took some inspiration from my pisicinemate [gopiment](https://github.com/GoPepperPY)'s [Libft-2026/main.c](https://github.com/GoPepperPY/Libft-2026/blob/main/main.c), but the testing framework itself was written from scratch. I learned a lot by implementing my own testing, but I decided to not continue doing so for Parts 2 and 3 as it was consuming way too much of my time with diminishing returns in terms of what I was learning with each new test.

Although the `test.c` file was not delivered in the official project submission, it is available in the `.extras/` folder of this repository with the purpose of allowing users and other students to make use of it or even to serve as an inspiration for their own testing framework.

> You can use the extras' `Makefile` to compile the tests by running `make test` from within the `.extras/` folder.
> After compiling, run the tests by executing `./test`.
> When you're done, use `make tclean` or manually remove the program.

#### ft_printf

*`ft_printf()` was originally developed and tested as a standalone project before being merged into this library.*

A tester program was created to compare `ft_printf()` against the standard `printf()`. Each test case calls both functions with the same arguments and displays the returned value of each.

| Test case | Tested values |
|---|---|
| Format string with no conversion | `"hello world\n"` |
| `NULL` format string | `NULL` |
| `%c` | `'f'`, `0` |
| `%s` | `"hi friend"`, `NULL` |
| `%p` | The function's own pointer, `NULL` |
| `%d`, `%i` | `42`, `INT_MIN`, `INT_MAX` |
| `%u` | `0`, `UINT_MAX` |
| `%x`, `%X` | `42`, `UINT_MAX` |
| `%%` | Literal percent sign |

The `NULL` and boundary values (`INT_MIN`, `INT_MAX`, `UINT_MAX`) are the cases most likely to expose bugs. Overflow handling, unsigned wrapping, and guarding against NULL values are common points-of-failure.

> The tester's source is available as `ft_printf_test.c` in the `.extras/` folder. Compile it with `make ft_printf_test` from within `.extras/`, then run `./test_ft_printf`. When you're done, use `make pclean` or manually remove the program.

### Debugging

GDB was used for debugging some of the functions: small debugger programs were written at the end of the function's source code file, and then compiled with the `-g` flag using `cc`. These programs were left commented at the end of those files.

> You can use the `.extras/Makefile` to compile debugging programs with the `-g` flag by running `make debug <file.c>` from within the `.extras/` folder.
> Run the compiled program by executing `./debug`. When you're done, use `make dclean` or manually remove the program.

---

## Resources

### Reference material

- man pages (mostly GNU) — primary reference for all Part 1 function specifications.
- GNU C Library source — [https://sourceware.org/git/glibc.git](https://sourceware.org/git/glibc.git)
- Apple Libc source — [https://github.com/apple-oss-distributions/Libc](https://github.com/apple-oss-distributions/Libc)
- musl libc source — [https://github.com/bminor/musl](https://github.com/bminor/musl)
- the World Wide Web — additional research.

The three implementations of Libc mentioned above were consulted additionally to the man pages, to clear up ambiguity about edge case behavior.

### Learning resources

- Caleb Curry — [*Structs in C*](https://youtu.be/IAvfAC4H_0s)
- CodeVault — [*Linked Lists in C (playlist)*](https://youtube.com/playlist?list=PLfqABt5AS4FmXeWuuNDS3XGENJO1VYGxl)
- Mike Shah — [*GDB Debugger introduction*](https://youtu.be/MTkDTjdDP3c)

### Use of AI

AI was not used during the implementation phase. Quality information was available through the man pages, the Web and even official source code (accessed by cloning the repositories of widely used implementations). I didn't want my thought process to be influenced by AI's logic during this part of the learning process.

During the final phase of the project, after the functions were passing all tests, Claude was used in a review capacity — checking implementations for bad practices, edge case handling, and correctness issues. Because LLM technology excels at pattern recognition, it proved to be very helpful with this task: it contributed to catching several real bugs (notably in `ft_strtrim` and `ft_substr`) without undermining the learning process, since the implementations and the understanding behind them were already in place.
