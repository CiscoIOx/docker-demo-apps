/*
 * Sample code for basic C app which loops forever
 */

#include <stdio.h>
#include <unistd.h>

/*
 * Create a loop
 */
int main()
{
    /* loop */
    while(1)
    {   
        /* Sleep for a second for each iteration */
        sleep(10000);
    }
    return 0;
}
