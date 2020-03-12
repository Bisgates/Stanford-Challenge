#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int fdin = open(argv[1], O_RDONLY); 
	int fdout = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644); 
	char buffer[1024];
	while (true) {
		ssize_t bytesRead = read(fdin, buffer, sizeof(buffer));
		if (bytesRead == 0) break;
		size_t bytesWritten = 0;
		while (bytesWritten < bytesRead) {
			bytesWritten += write(fdout, buffer + bytesWritten, bytesRead - bytesWritten);
		} 
	} 
	close(fdin); 
	close(fdout); 
	return 0;

}
