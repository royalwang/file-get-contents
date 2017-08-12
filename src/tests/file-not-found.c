#include <stdio.h>

#include "file-get-contents.h"

int main(void)
{
	// What are the chances that such a file exists?
	const char *filename = "asdvcxoiu23890uiosjcknsdiocn8129ju23ijknsdjkncidosj983ijdsf";

	struct file_get_contents contents;
	if (file_get_contents(filename, &contents)) {
		fprintf(stderr, "Unexpectedly succeeded reading file.\n");
		file_get_contents_free(&contents);
		return 1;
	}

	return 0;
}
