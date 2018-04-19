#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    /* Open the random number file. */
    int r_num, random_file = open("/dev/random", O_RDONLY);

    /* Read 32 bits into a variable. */
    read(random_file, &r_num, sizeof(int));
    close(random_file);
    printf("Random number: %d\n", r_num);

    /* Seed the random number generator with random number from file. */
    srandom(r_num);
    int rand_nums[10];
    
    /* Generate 10 random numbers and store in array. */
    for (int i = 0; i < 10; i++)
    {
        rand_nums[i] = random();
    }

    /* Print contents of array. */
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", rand_nums[i]);
        if (i == 9)
            printf("\n");
    }

    return 0;
}