#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, const char** argv) {
    char str[15] = "Hi some write\n";
    char input[10];
    if(write(4, str, 14) == -1) {
        perror("some error in write");
        return 1;
    }
    read(0, input, 10);
    write(1, input, 10);
    
}