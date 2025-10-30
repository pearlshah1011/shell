#include "headers.h"
#include "display.h"
#include "execute.h"
#include "history.h"


int main()
{
    shellInFile = dup(STDIN_FILENO);
    shellOutFile = dup(STDOUT_FILENO);
    shellpid = getpid();
    oldpwd = false;
    username = (char *)malloc(1024);
    username = getenv("USER");
    gethostname(sys_name, sizeof(sys_name));
    getcwd(tilda, sizeof(tilda));
   
    char *line;
    size_t buf = 0;
    int read;
    readfromhistory();
    back_count = 0;
    process_pid = 0;
 
    while (1)
    {
        dis();
        read = getline(&line, &buf, stdin);
        if (read == -1)
        {
            // Ctrl + D
            printf("\n");
            writetohistory();
        }
  
        int cheker;
        if (latest_number == 0)
        {
            cheker = 19;
        }
        else
        {
            cheker = latest_number - 1;
        }
        if (strcmp(line, history[cheker]) && strcmp(line, "\n"))
        {
            strcpy(history[latest_number], line);
            latest_number++;
            latest_number %= 20;
        }
        line[read - 1] = '\0';

        int number_of_task = 0;
        task = strtok(line, ";");
        while (task != NULL)
        {
            extra_task[number_of_task] = task;
            number_of_task++;
            //printf("%s\n",task);
            task = strtok(NULL, ";");
        }
        // case 1 <,>,>>
        // case 2 |
        // case 3 <,|
        // acse 4 nothing
        bool condition2 = false;
        for (int j = 0; j < number_of_task; j++)
        {
                execute(j);
        }
    }
}