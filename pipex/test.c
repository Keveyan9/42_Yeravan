#include <stdio.h>
#include <unistd.h>
int main() 
{ 
    printf("Hello mane !\n");
    fork();  
    printf("Hello world!\n");
    return 0; 
} 

