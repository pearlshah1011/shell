# SHELL BY Pearl Shah
# Compiling
execute the given command to create an executable file<br>
`make`<br>
Now run<br>
`./shell.out`
## cd_b.c
This command is made using chdir whereas egde cases like<br>
cd - is taken care by storing OLD PWD<br>
cd ~/dir is taken by manipulating strings
## display.c
This is used to display the prompt
## echo_b.c
This is used to do echo using string manipulation and printf
## headers.h
It contains global variable that will be used by different c files and contains headers for all files
## history.c
1. void readfromhistory(); to read from history.txt only to be used in the beginning
2. void writetohistory(); to write to history.txt it is executed after exit is entered by user
3. void commandhistory(int number); to implement history command , displays the name of recent commands based upon arguments
## execute.c
2 functions execute and execute_withstring both performs same function just different inputs<br>
## main.c
1. Duplicates shell input/output files.
2. Retrieves process ID, username, and system hostname.
3. Stores current directory path in `tilda`.
4. Initializes variables for input, history, and process tracking.
5. Reads command history with `readfromhistory()`.
6. Starts infinite loop:
   1. Displays prompt.
   2. Reads user input.
   3. Handles Ctrl + D, writing to history.
   4. Adds input to history if not a duplicate.
   5. Splits input by semicolons into commands.
   6. Executes each command using `execute()`.
## pwd_b.c
Print the current directory
## exit command can also be used for exiting
## Some Assumptions
1. Path length, input string will be less than 1024 characters
