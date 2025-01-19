#include <stdio.h>
#include <fcntl.h>


int main(int argc, char* argv[]) {
    rename(argv[1], argv[2]);
}
