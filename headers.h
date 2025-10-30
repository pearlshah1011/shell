#ifndef __HEADERS_H
#define __HEADERS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char* task;
char* extra_task[32];
char* argv[32];
char* username;
char* history_path;
char* history[20];
int latest_number;
int inital_number;
int total_number;
char sys_name[1024];
char curr_dir[1024];
bool oldpwd;
char old_dir[1024];
char tilda[1024];
int shellInFile, shellOutFile;
int back_count;
pid_t shellpid;
pid_t process_pid;

#endif
