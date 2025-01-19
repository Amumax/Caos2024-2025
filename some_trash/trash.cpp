#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, const char** argv) {
    char str[15] = "Hi some write\n";
    char input[10];
    if(write(3, str, 14) == -1) {
        perror("some error in write");
        return 1;
    }
    if(read(0, input, 10)== -1){
        perror("some error in read");
        return 1;
    };
    if(write(1, input, 10) == -1){
        perror("some error in write 2");
        return 1;
    }
    
}