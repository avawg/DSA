#include<unistd.h>

int main()
{
    char *argv[] = {"./argv", "test_sample", (char *) 0};
    char *envp[] = {0};
    execve("./argv", argv, envp);

    return 0;
}
