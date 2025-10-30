#include "headers.h"
#include "cd_b.h"

void cd(int start,int number)
{
    if ((number-start) > 2)
    {
        // base case
        printf(":( Error wrong number of arguments given for cd\n");
    }
    else if ((number-start) == 1)
    {
        getcwd(old_dir, sizeof(old_dir));
        oldpwd = true;
        chdir(tilda);
        
    }
    else if ((number-start) == 2)
    {
        // cd -
        if (argv[start+1][0] == '-')
        {
            if (oldpwd == false)
            {
                printf(":( Error OLDPWD not found\n");
            }
            else
            {
                char temp[1024];
                
                getcwd(temp, sizeof(temp));
                printf("%s\n",old_dir);
                chdir(old_dir);
                strcpy(old_dir, temp);
            }
          
        }
        // cd ~
        else if (argv[start+1][0] == '~' && strlen(argv[start+1]) <= 2)
        {
            getcwd(old_dir, sizeof(old_dir));
            oldpwd = true;
            chdir(tilda);
        }
        // cd ~/dir
        else if (argv[start+ 1][0] == '~')
        {
            char temp[1024];
            char destination[1024];
            strcpy(destination,tilda);
        
            int string_copy_len = strlen(argv[start+1]) - 1;
            strncpy(temp, argv[start+1] + 1, string_copy_len);
            temp[string_copy_len]='\0';
            strcat(destination,temp);
            getcwd(old_dir, sizeof(old_dir));
            oldpwd = true;
            chdir(destination);
        }
        else
        {
            getcwd(old_dir, sizeof(old_dir));
            oldpwd = true;
            chdir(argv[start+1]);
        }
    }
}