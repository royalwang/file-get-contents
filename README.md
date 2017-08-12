# File-get-contents 1.0.0

Read an entire file to memory with a single function call in C.


## Table of contents

1. Introduction
2. Example
3. How to use
4. Reporting bugs
5. License


## 1. Introduction

This library provides a function inspired by PHP's `file_get_contents`. It's
useful in systems that don't provide an equivalent to POSIX's `mmap`.


## 2. Example

```C
#include <stdio.h>
#include <file-get-contents.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
		return 1;
	}

	const char *filename = argv[1];

	struct file_get_contents contents;

	if (!file_get_contents(filename, &contents)) {
		fprintf(stderr, "Failed to read file.\n");
		return 1;
	}

	printf("Read %d bytes.\n", contents.size);
	printf("Here are the first couple of bytes:\n");
	printf("%.*s\n", contents.size > 10 ? 10 : contents.size, contents.data);

	file_get_contents_free(&contents);

	return 0;
}
```


## 3. How to use

You can either copy the source files into your own project or install the
header file and the static library on your system and have your compiler link
to `libfile-get-contents.a`.

In your code you will need to include the `file-get-contents.h` header file.

```C
#include <file-get-contents.h>
```

Then you can read files by calling `file_get_contents`. You need to pass it the
path to the file and a pointer to a `struct file_get_contents` that will be
filled up if the function succeeds reading the file. It returns 1 on success
and 0 on failure.

```C
struct file_get_contents contents;
int success = file_get_contents(filename, &contents);
```

When you're done, you need to free up the resources that are bound to the
structure by calling `file_get_contents_free`.

```C
file_get_contents_free(&contents);
```


## 4. Reporting bugs

If you encounter a bug, please open an issue on GitHub:

	https://github.com/daniel-araujo/file-get-contents/issues


## 5. License

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
