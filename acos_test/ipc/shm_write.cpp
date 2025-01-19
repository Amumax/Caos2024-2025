#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1000000

int main() {
  int shm_id;
  char* shm_ptr;

  shm_id = shmget(12222, SHM_SIZE, IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(1);
  }

  shm_ptr = (char*) shmat(shm_id, nullptr, 0);
  if (shm_ptr == (char*) -1) {
    perror("shmat");
    exit(1);
  }

  const char* message = "Hello from writer!";
  sprintf(shm_ptr, "%s", message);
  printf("Write: wrote to shared memory: %s\n", message);

  getchar();

  shmdt(shm_ptr);
}
