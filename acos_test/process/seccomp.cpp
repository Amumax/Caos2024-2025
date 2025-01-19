#include <iostream>
#include <seccomp.h>
#include <unistd.h>
#include <sys/prctl.h>

void setup_seccomp() {
  scmp_filter_ctx ctx = seccomp_init(SCMP_ACT_ALLOW);

  if (ctx == nullptr) {
    perror("seccomp_init");
    exit(1);
  }

  //seccomp_rule_add(ctx, SCMP_ACT_ERRNO(EPERM), SCMP_SYS(execve), 0);
  //seccomp_rule_add(ctx, SCMP_ACT_ERRNO(EPERM), SCMP_SYS(fork), 0);

  seccomp_rule_add(ctx, SCMP_ACT_KILL_PROCESS, SCMP_SYS(execve), 0);
  seccomp_rule_add(ctx, SCMP_ACT_KILL_PROCESS, SCMP_SYS(fork), 0);

  if (seccomp_load(ctx) < 0) {
    perror("seccomp load");
    exit(1);
  }

  seccomp_release(ctx);
}

int main() {
  setup_seccomp();

  std::cout << "Process is running with restricted syscalls." << std::endl;

  char* args[] = {"/bin/ls", nullptr};
  execve(args[0], args, nullptr);

  while (true) {};
}
