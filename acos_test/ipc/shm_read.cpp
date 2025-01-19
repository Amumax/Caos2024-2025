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

  shm_id = shmget(12222, SHM_SIZE, 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(1);
  }

  shm_ptr = (char*) shmat(shm_id, nullptr, 0);
  if (shm_ptr == (char*) -1) {
    perror("shmat");
    exit(1);
  }

  printf("Reader: read from shared memory: :%s\n", shm_ptr);

  shmdt(shm_ptr);

  shmctl(shm_id, IPC_RMID, nullptr);
}
