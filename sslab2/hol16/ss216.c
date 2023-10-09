#include <unistd.h>    
#include <sys/types.h> 
#include <stdio.h>     

void main()
{
    
    int childToParentfd[2], parentToChildfd[2];
    int childToParentPipeStatus;
    int parentToChildPipeStatus; 
    int readBytes, writeBytes;   
    char *writeBuffer, *readBuffer;

    pid_t childPid;

    childToParentPipeStatus = pipe(childToParentfd);
    parentToChildPipeStatus = pipe(parentToChildfd);

    if (childToParentPipeStatus == -1 || parentToChildPipeStatus == -1)
        perror("Error while creating the pipe!");
    else
    {
        childPid = fork();

        if (childPid == -1)
            perror("Error while forking child!");
        else if (childPid == 0)
        {
           
            close(parentToChildfd[1]); 
            close(childToParentfd[0]); 

            
            writeBuffer = "child process is here!";
            writeBytes = write(childToParentfd[1], &writeBuffer, sizeof(writeBuffer));
            if (writeBytes == -1)
                perror("Error while writing to  child to parent pipe!");

            
            readBytes = read(parentToChildfd[0], &readBuffer, sizeof(readBuffer));
            if (readBytes == -1)
                perror("Error while reading from parent to child pipe!");
            else
                printf("The parent said: %s\n", readBuffer);
        }
        else
        {
            close(parentToChildfd[0]); 
            close(childToParentfd[1]); 

         
            writeBuffer = "parent is here!";
            writeBytes = write(parentToChildfd[1], &writeBuffer, sizeof(writeBuffer));
            if (writeBytes == -1)
                perror("Error while writing to  parent to child pipe!");

            

            readBytes = read(childToParentfd[0], &readBuffer, sizeof(readBuffer));
            if (readBytes == -1)
                perror("Error while reading from child to parent pipe!");
            else
                printf("The child said: %s\n", readBuffer);
        }
    }
}
