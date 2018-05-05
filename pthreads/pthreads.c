#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *my_entry_function(void *param)
{
    int* value = (int*) param;
    while (--(*value)) /* NOP */ ;
    printf("Finished decrementing x\n");
    return NULL;
}

int main()
{
    srand(time(NULL));
    int x = rand() % (1000 * 1000);  // Random initial value
    int y = rand() % (1000 * 1000);  // Random initial value

    printf("x = %d, y = %d\n", x, y);

    // Create a thread that decrements the x parameter
    pthread_t thread0;
    pthread_create(&thread0, NULL, my_entry_function, &x);
    
    // Decrement the y parameter in the main thread.
    while (--y) /* NOP */ ;
    printf("Finished decrementing y\n");

    pthread_join(thread0, NULL);
    printf("Joined the x decrementer thread\n");

    return 0;
}
