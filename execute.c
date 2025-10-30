#include "headers.h"
#include "execute.h"
#include "echo_b.h"
#include "pwd_b.h"
#include "cd_b.h"
#include "history.h"
void execute(int task_id)
{
    int i = 0;
    int back = 0;
    argv[0] = strtok(extra_task[task_id], " \t");
    while (argv[i] != NULL)
    {
        i++;
        argv[i] = strtok(NULL, " \t");
    }
    if (!strcmp("exit", argv[0]))
    {
        writetohistory();
    }
    else if (!strcmp("echo", argv[0]))
    {
        echo(1, i);
    }
    else if (!strcmp("pwd", argv[0]))
    {
        pwd(0, i);
    }
    else if (!strcmp("cd", argv[0]))
    {
        cd(0, i);
    }
    else if (!strcmp("history", argv[0]))
    {
        commandhistory(i);
    }
    dup2(shellInFile,STDIN_FILENO);
    dup2(shellOutFile,STDOUT_FILENO);
}
