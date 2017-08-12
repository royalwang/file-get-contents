#ifndef FILE_GET_CONTENTS_FILE_GET_CONTENTS_H
#define FILE_GET_CONTENTS_FILE_GET_CONTENTS_H

#include <stdio.h>
#include <stdlib.h>

/*
 * Structure that is filled while reading the contents of a file.
 */
struct file_get_contents {
	// A pointer to the first character in the file. You may read up to the
	// reported size of characters.
	char *data;

	// Number of characters read.
	size_t size;
};

/*
 * Reads the entire contents of a file to memory.
 *
 * On success it returns 1 and the given structure will be filled. When you're
 * done using the structure, you need to pass it to file_get_contents_free.
 *
 * On failure it returns 0. The given structure will not be modified.
 */
int file_get_contents(const char *path, struct file_get_contents *result);

/*
 * Frees up the resources bound to the given structure.
 */
void file_get_contents_free(struct file_get_contents *result);

#endif /* FILE_GET_CONTENTS_FILE_GET_CONTENTS_H */
