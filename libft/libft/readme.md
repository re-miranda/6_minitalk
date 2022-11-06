# libft -  MANUAL
By: rmiranda | Renato Miranda Goncalves

## `ft_atoi`
_`int	ft_atoi(const char *str)`_
### DESCRIPTION
The ft_atoi() function converts the initial portion of the string pointed to by str to int.  
The call ft_atoi(str) shall be equivalent to:  
`(int) strtol(str, (char **)NULL, 10)`  
except that the handling of errors may differ. If the value cannot be represented, the behavior is undefined.  
The string may begin with an arbitrary amount of white space (as determined by isspace(3)) followed by a single optional '+' or '-' sign.
The remainder of the string is converted to an int value in the obvious manner, stopping at the first character which is not a valid digit in the given base.  
### RETURN VALUE
The ft_atoi() function returns the result of the conversion, unless the value would underflow or overflow.  If either case the behavior is undefined.
### ERRORS
No errors are defined.

## `ft_bzero`
_`void	ft_bzero(void *s, size_t n)`_
### DESCRIPTION
The ft_bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.
### RETURN VALUE
None.
### ERRORS
No errors are defined.

## `ft_calloc`
_`void	*ft_calloc(size_t nelem, size_t elsize)`_
### DESCRIPTION
The calloc() function shall allocate unused space for an array of nelem elements each of whose size in bytes is elsize. The space shall be initialized to all bits 0.  
The order and contiguity of storage allocated by successive calls to calloc() is unspecified. The pointer returned if the allocation succeeds shall be suitably aligned so that it may be assigned to a pointer to any type of object and then used to access such an object or an array of such objects in the space allocated (until the space is explicitly freed or reallocated). Each such allocation shall yield a pointer to an object disjoint from any other object. The pointer returned shall point to the start (lowest byte address) of the allocated space. If the space cannot be allocated, a null pointer shall be returned. If the size of the space requested is 0, the behavior is implementation- defined: either a null pointer shall be returned, or the behavior shall be as if the size were some non-zero value, except that the behavior is undefined if the returned pointer is used to access an object.
### RETURN VALUE
Upon successful completion with both nelem and elsize non-zero, calloc() shall return a pointer to the allocated space. If either nelem or elsize is 0, then either:  
  *  A null pointer shall be returned and errno may be set to an implementation-defined value, or  
  *  A pointer to the allocated space shall be returned. The application shall ensure that the pointer is not used to access an object.
Otherwise, it shall return a null pointer and set errno to indicate the error.
### ERRORS
The calloc() function shall fail if:
ENOMEM Insufficient memory is available.

## `ft_isalnum`
_`int	ft_isalnum(int c)`_
### DESCRIPTION
The ft_isalnum() function shall test whether c is a character of class alpha or digit; it is equivalent to (ft_isalpha(c) || ft_isdigit(c)).  
The c argument is an int, the value of which the application shall ensure is representable as an unsigned char. If the argument has any other value, the behavior is undefined.
### RETURN VALUE
The ft_isalnum() function shall return non-zero if c is an alphanumeric character; otherwise, it shall return 0.
### ERRORS
No errors are defined.

## `ft_isalpha`
_`int	ft_isalpha(int c)`_
### DESCRIPTION
The ft_isalpha() function shall test whether c is a character of class alpha.  
The c argument is an int, the value of which the application shall ensure is representable as an unsigned char. If the argument has any other value, the behavior is undefined.
### RETURN VALUE
The ft_isalpha() function shall return non-zero, if c is an alphabetic character; otherwise, it shall return 0.  
If c is an alphanumeric character, the function shall return either 1 or 2; indicating lowercase or uppercase, respectively.
### ERRORS
No errors are defined.

## `ft_isascii`
_`int	ft_isascii(int c)`_
### DESCRIPTION
The ft_isascii() function shall test whether c is a 7-bit US-ASCII character code.  
The c argument is an int, defined on all integer values.
### RETURN VALUE
The ft_isascii() function shall return non-zero, if c is a 7-bit US-ASCII character code between 0 and 127 inclusive; otherwise, it shall return 0.
### ERRORS
No errors are defined.

## `ft_isdigit`
_`int	ft_isdigit(int c)`_
### DESCRIPTION
The ft_isdigit() function shall test whether c is a character of class digit.  
The c argument is an int, the value of which the application shall ensure is a character representable as an unsigned char. If the argument has any other value, the behavior is undefined.
### RETURN VALUE
The ft_isdigit() function shall return non-zero, if c is a decimal digit; otherwise, it shall return 0.
### ERRORS
No errors are defined.

## `ft_isprint`
_`int	ft_isprint(int c)`_
### DESCRIPTION
The ft_isprint() function shall test whether c is a character of class print.  
The c argument is an int, the value of which the application shall ensure is a character representable as an unsigned char. If the argument has any other value, the behavior is undefined.
### RETURN VALUE
The ft_isprint() function shall return non-zero, if c is a character code between 32 and 127 inclusive; otherwise, it shall return 0.
### ERRORS
No errors are defined.

## `ft_memchr`
_`void	*ft_memchr(const void *s, int c, size_t n)`_
### DESCRIPTION
The ft_memchr() function scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.
### RETURN VALUE
The ft_memchr() function return a pointer to the matching byte or NULL if the character does not occur in the given memory area.
### ERRORS
No errors are defined.

## `ft_memcmp`
_`int	ft_memcmp(const void *s1, const void *s2, size_t n)`_
### DESCRIPTION
The ft_memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.
### RETURN VALUE
The ft_memcmp() function returns an integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2.  
For a nonzero return value, the sign is determined by the sign of the difference between the first pair of bytes (interpreted as unsigned char) that differ in s1 and s2.  
If n is zero, the return value is zero.
### ERRORS
No errors are defined.

## `ft_memcpy`
_`void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)`_
### DESCRIPTION
The ft_memcpy() function copies n bytes from memory area src to memory area dest. The memory areas must not overlap. Use memmove(3) if the memory areas do overlap.
### RETURN VALUE
The ft_memcpy() function returns a pointer to dest.
### ERRORS
No errors are defined.

## `ft_memmove`
_`void	*ft_memmove(void *s1, const void *s2, size_t n)`_
### DESCRIPTION
The ft_memcpy() function copies n bytes from memory area src to memory area dest. The memory areas must not overlap. Use memmove(3) if the memory areas do overlap.
### RETURN VALUE
The ft_memcpy() function returns a pointer to dest.
### ERRORS
No errors are defined.

## `ft_memset`
_`void *ft_memset(void *s, int c, size_t n)`_
### DESCRIPTION
The ft_memset() function shall copy c (converted to an unsigned char) into each of the first n bytes of the object pointed to by s.
### RETURN VALUE
The ft_memset() function shall return s; no return value is reserved to indicate an error.
### ERRORS
No errors are defined.

## `ft_strchr`
_`char	*ft_strchr(const char *s, int c)`_
### DESCRIPTION
The ft_strchr() function shall locate the first occurrence of c (converted to a char) in the string pointed to by s.  The terminating NUL character is considered to be part of the string.
### RETURN VALUE
Upon completion, ft_strchr() shall return a pointer to the byte, or a null pointer if the byte was not found.
### ERRORS
No errors are defined.

## `ft_strdup`
_`char	*ft_strdup(char *str)`_
### DESCRIPTION
The ft_strdup() function shall return a pointer to a new string, which is a duplicate of the string pointed to by s. The returned pointer can be passed to free(). A null pointer is returned if the new string cannot be created.
### RETURN VALUE
The ft_strdup() function shall return a pointer to a new string on success. Otherwise, it shall return a null pointer.
### ERRORS
These functions shall fail if storage space available is insufficient.

## `ft_strlcat`
_`size_t	ft_strlcat(char *dst, const char *src, size_t size)`_
### DESCRIPTION
The ft_strlcat() function concatenate strings. It takes the full size of the buffer (not just the length) and guarantee to NUL-terminate the result (as long as there is at least one byte free in dst). Note that a byte for the NUL should be included in size. Also note it only operates on true ''C'' strings. This means that both src and dst must be NUL-terminated.

The ft_strlcat() function appends the NUL-terminated string src to the end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
### RETURN VALUE
The ft_strlcat() functions return the total length of the string it tried to create. That means the initial length of dst plus the length of src. While this may seem somewhat confusing, it was done to make truncation detection simple.

Note, however, that if ft_strlcat() traverses size characters without finding a NUL, the length of the string is considered to be size and the destination string will not be NUL-terminated (since there was no space for the NUL). This keeps ft_strlcat() from running off the end of a string. In practice this should not happen (as it means that either size is incorrect or that dst is not a proper ''C'' string). The check exists to prevent potential security problems in incorrect code.
### ERRORS
No errors are defined.

## `ft_strlcpy`
_`size_t	ft_strlcpy(char *dst, const char *src, size_t size)`_
### DESCRIPTION
The ft_strlcpy() function copy strings. The function takes the full size of the buffer (not just the length) and guarantee to NUL-terminate the result (as long as size is larger than 0). Note that a byte for the NUL should be included in size. Also note that it only operates on true "C" strings. This means that src must be NUL-terminated.

The ft_strlcpy() function copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.
### RETURN VALUE
The ft_strlcpy() function return the total length of the string it tried to create, that means the length of src. While this may seem somewhat confusing, it was done to make truncation detection simple.
### ERRORS
No errors are defined.

## `ft_strlen`
_`size_t	ft_strlen(const char *s)`_
### DESCRIPTION
The ft_strlen() function shall compute the number of bytes in the string to which s points, not including the terminating NUL character.
### RETURN VALUE
The strlen() function shall return the length of s; no return value shall be reserved to indicate an error.
### ERRORS
No errors are defined.

## `ft_strncmp`
_`int	ft_strncmp(const char *s1, const char *s2, size_t n)`_
### DESCRIPTION
The ft_strncmp() function shall compare not more than n bytes (bytes that follow a NUL character are not compared) from the array pointed to by s1 to the array pointed to by s2.
The sign of a non-zero return value is determined by the sign of the difference between the values of the first pair of bytes (both interpreted as type unsigned char) that differ in the strings being compared.
### RETURN VALUE
Upon successful completion, ft_strncmp() shall return an integer greater than, equal to, or less than 0, if the possibly null- terminated array pointed to by s1 is greater than, equal to, or less than the possibly null-terminated array pointed to by s2 respectively.
### ERRORS
No errors are defined.

## `ft_strnstr`
_`char 	*ft_strnstr(const char	*big, const char *little, size_t len)`_
### DESCRIPTION
The strnstr() function locates the	first occurrence of the	null-terminated string little in the string big, where not more than len characters are searched.  Characters that appear after a `\0'	character are not searched.	Since the strnstr() function is	a FreeBSD specific API,	it should only be used when portability is not a concern.
### RETURN VALUE
If	little is an empty string, big is returned; if little occurs nowhere in	big, NULL is returned; otherwise a pointer to the first	character of the first occurrence of little is returned.
### ERRORS
No errors are defined.

## `ft_strrchr`
_`char	*ft_strrchr(const char *s, int c)`_
### DESCRIPTION
The strrchr() function shall locate the last occurrence of c (converted to a char) in the string pointed to by s.  The terminating NUL character is considered to be part of the string.
### RETURN VALUE
Upon successful completion, strrchr() shall return a pointer to the byte or a null pointer if c does not occur in the string.
### ERRORS
No errors are defined.

## `ft_tolower`
_`int	tolower(int c)`_
### DESCRIPTION
The ft_tolower() function has as a domain a type int, the value of which is representable as an unsigned char or the value of EOF. If the argument has any other value, the behavior is undefined.  
If the argument of ft_tolower() represents an uppercase letter, the result shall be the corresponding lowercase letter.  
All other arguments in the domain are returned unchanged.
### RETURN VALUE
Upon successful completion, the ft_tolower() function shall return the lowercase letter corresponding to the argument passed; otherwise, it shall return the argument unchanged.
### ERRORS
No errors are defined.

## `ft_toupper`
_`int	toupper(int c)`_
### DESCRIPTION
The toupper() function has as a domain a type int, the value of which is representable as an unsigned char or the value of EOF. If the argument has any other value, the behavior is undefined.  
If the argument of toupper() represents a lowercase letter, the result shall be the corresponding uppercase letter.  
All other arguments in the domain are returned unchanged.
### RETURN VALUE
Upon successful completion, toupper() shall return the uppercase letter corresponding to the argument passed; otherwise, it shall return the argument unchanged.
### ERRORS
No errors are defined.

### Part II

## `ft_substr`
_`char	*ft_substr(char const *s, unsigned int start, size_t len)`_
### DESCRIPTION
Allocates (with malloc(3)) and returns a substring from the string ’s’.  
The substring begins at index ’start’ and is of maximum size ’len’.  
s:  The string from which to create the substring.  
start:  The start index of the substring in the string ’s’.  
len:  The maximum length of the substring.
### RETURN VALUE
The substring.  
NULL if the allocation fails.
### ERRORS
No errors are defined.

## `ft_strjoin`
_`char	*ft_strjoin(char const *s1, char const *s2)`_
### DESCRIPTION
Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.  
s1:  The prefix string.  
s2:  The suffix string.
### RETURN VALUE
The new string.  
NULL if the allocation fails.
### ERRORS
No errors are defined.

## `ft_strtrim`
_`char	*ft_strtrim(char const *s1, char const *set)`_
### DESCRIPTION
Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.  
s1:  The string to be trimmed.  
set:  The reference set of characters to trim.
### RETURN VALUE
The trimmed string.  
NULL if the allocation fails.
### ERRORS
No errors are defined.

## `ft_split`
_`char	**ft_split(char const *s, char c)`_
### DESCRIPTION
Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.  The array must end with a NULL pointer.  
s:  The string to be split.  
c:  The delimiter character.
### RETURN VALUE
The array of new strings resulting from the split.  
NULL if the allocation fails.
### ERRORS
No errors are defined.

## `ft_itoa`
_`char	*ft_itoa(int n)`_
### DESCRIPTION
Allocates (with malloc(3)) and returns a string representing the integer received as an argument.  
Negative numbers must be handled.  
n:  the integer to convert.
### RETURN VALUE
The string representing the integer.  
NULL if the allocation fails.
### ERRORS
No errors are defined.

## `ft_strmapi`
_`char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))`_
### DESCRIPTION
Applies the function ’f’ to each character of the string ’s’, and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’.  
s:  The string on which to iterate.  
f:  The function to apply to each character.
### RETURN VALUE
The string created from the successive applications of ’f’.  
Returns NULL if the allocation fails.
### ERRORS
No errors are defined.

## `ft_striteri`
_`void	ft_striteri(char *s, void (*f)(unsigned int, char*))`_
### DESCRIPTION
Applies the function ’f’ on each character of the string passed as argument, passing its index as first argument.  Each character is passed by address to ’f’ to be modified if necessary.  
s:  The string on which to iterate.  
f:  The function to apply to each character.
### RETURN VALUE
None
### ERRORS
No errors are defined.

## `ft_putchar_fd`
_`void	ft_putchar_fd(char c, int fd)`_
### DESCRIPTION
Outputs the character ’c’ to the given file descriptor.  
c:  The character to output.  
fd:  The file descriptor on which to write.
### RETURN VALUE
None
### ERRORS
No errors are defined.

## `ft_putstr_fd`
_`void	ft_putstr_fd(char *s, int fd)`_
### DESCRIPTION
Outputs the string ’s’ to the given file descriptor.  
s:  The string to output.  
fd:  The file descriptor on which to write.
### RETURN VALUE
None
### ERRORS
No errors are defined.

## `ft_putendl_fd`
_`void	ft_putendl_fd(char *s, int fd)`_
### DESCRIPTION
Outputs the string ’s’ to the given file descriptor followed by a newline.  
s:  The string to output.  
fd:  The file descriptor on which to write.
### RETURN VALUE
None
### ERRORS
No errors are defined.

## `ft_putnbr_fd`
_`void	ft_putnbr_fd(int n, int fd)`_
### DESCRIPTION
Outputs the integer ’n’ to the given file descriptor.  
n:  The integer to output.  
fd:  The file descriptor on which to write.
### RETURN VALUE
None
### ERRORS
No errors are defined.

## `ft_abs`
_`int	ft_abs(int n)`_
### DESCRIPTION
Outputs the absolute integer to the given interger ’n’.  
n:  The integer to output.
### RETURN VALUE
An int with the absolute value of ’n’.
### ERRORS
When the input execceds max_int (the highest positive value of a 4 bytes int (2147483647)),
 the function will truncate the output, which shall be limited to max_int.
  Console warnings are thrown on each function call, in case truncation happens.