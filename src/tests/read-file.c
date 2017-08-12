#include <stdio.h>
#include <string.h>

#include "file-get-contents.h"

int main(void)
{
	int ret = 1;

	const char *filename = "../src/tests/10chars";

	struct file_get_contents contents;

	if (!file_get_contents(filename, &contents)) {
		fprintf(stderr, "Failed to read file.\n");
		goto exit0;
	}

	if (contents.size != 10) {
		fprintf(stderr, "Wrong size.\n");
		goto exit1;
	}

	if (memcmp(contents.data, "123456789\n", contents.size) != 0) {
		fprintf(stderr, "Wrong data.\n");
		goto exit1;
	}

	ret = 0;
exit1:
	file_get_contents_free(&contents);
exit0:
	return ret;
}
