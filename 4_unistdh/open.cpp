#include <string>
#include <unistd.h>
#include <fcntl.h>

int main() {
  int fd = open("/home/amumax/Caos2024-2025/some_unput_text.txt", O_RDONLY);
  write(1, std::to_string(fd).data(), 1);
}