#include <stdio.h>
#include <time.h>

int main()
{
    time_t today = time(NULL);
    printf("local: %s", asctime(localtime(&today)));
    return 0;
}
