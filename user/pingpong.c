#include "kernel/types.h"
#include "user/user.h"
int main()
{
    int p[2];
    pipe(p);
    int pid = fork();
    if (!pid)
    {
        read(p[0], &pid, 4);
        printf("%d: received ping\n", pid);
    }
    else
    {
        write(p[1], &pid, 4);
        wait(0);
        printf("%d: received pong\n", getpid());
    }
    exit(0);
}
