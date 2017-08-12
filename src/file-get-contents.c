#include "file-get-contents.h"

static inline int read(FILE *f, size_t size, struct file_get_contents *result)
{
	rewind(f);

	char *data = malloc(size * sizeof(char));

	if (data == NULL) {
		return 0;
	}

	long read = fread(data, sizeof(char), size, f);

	if ((size_t) read != size) {
		free(data);
		return 0;
	}

	result->data = data;
	result->size = size;

	return 1;
}

int file_get_contents(const char *path, struct file_get_contents *result)
{
	int ret = 0;

	FILE *f = fopen(path, "rb");

	if (f == NULL) {
		goto exit0;
	}

	if (fseek(f, 0, SEEK_END) != 0) {
		goto exit1;
	}

	long size = ftell(f);

	if (size == -1) {
		goto exit1;
	}

	if (size == 0) {
		result->size = 0;
		result->data = "";
	} else if (!read(f, size, result)) {
		goto exit1;
	}

	ret = 1;
exit1:
	fclose(f);
exit0:
	return ret;
}

void file_get_contents_free(struct file_get_contents *result)
{
	if (result->size == 0) {
		return;
	}

	free(result->data);
}
