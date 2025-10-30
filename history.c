#include "headers.h"
#include "history.h"

void readfromhistory()
{
    
    char *lineeo = NULL;
    for (int karna = 0; karna < 20; karna++)
    {
        history[karna] = (char *)malloc(1024);
    }
    history_path = (char *)malloc(1024);
    sprintf(history_path, "%s/history.txt", tilda);
    FILE *fd = fopen(history_path, "r");

    int filesize;
    if (fd == NULL)
    {

        FILE *fde = fopen(history_path, "w");
        fprintf(fde,"\n");
        fclose(fde);
        total_number = 0;
        latest_number = 0;
    }
    else
    {
        latest_number = 0;
        size_t readeo, len = 0;
        readeo = getline(&lineeo, &len, fd);
        inital_number = atoi(lineeo);
        while ((readeo = getline(&lineeo, &len, fd)) != -1)
        {
            if (strcmp(lineeo, "\n"))
            {
                strcpy(history[latest_number], lineeo);
                latest_number++;
            }
        }
        total_number = latest_number;
        latest_number = inital_number;
        fclose(fd);
    }
}
void writetohistory()
{
    FILE *fd = fopen(history_path, "w");
    fprintf(fd, "%d\n", latest_number);
    if (total_number < latest_number)
    {
        for (int i = 0; i < latest_number; i++)
        {
            fprintf(fd, "%s", history[i]);
        }
    }
    else
    {
        for (int i = 0; i < 20; i++)
        {
            fprintf(fd, "%s", history[i]);
        }
    }
    fclose(fd);
    exit(0);
}
void commandhistory(int number)
{
    if (number == 1)
    {
        if (total_number >= latest_number)//latest number is wrapped around 20
        {
            int startprinting=latest_number-10;
            if(startprinting<0)
            {
                startprinting+=20;
            }
            for (int j = 0; j < 10; j++)
            {
                if (startprinting == 20)
                {
                    startprinting = 0;
                }
                printf("%s", history[startprinting]);
                startprinting++;
            }
        }
        else
        {
            if (latest_number >= 10)
            {
                int startprinting = latest_number - 10;
                for (int j = 0; j < 10; j++)
                {
                    if (startprinting == -1)
                    {
                        startprinting = 19;
                    }
                    printf("%s", history[startprinting]);
                    startprinting++;
                }
            }
            else
            {
                
                int startprinting = 0;
                for (; startprinting<latest_number; startprinting++)
                {
                    printf("%s", history[startprinting]);
                }
            }
        }
    }
}