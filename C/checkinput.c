#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>

int main (void)
{
//  bool badlimits(long begin, long end, long min, long max)

    const long min = -100000L;
    const long max =  100000L;

    long begin;
    long end;

    printf("Input two number: \n");
    scanf("%ld %ld", &begin, &end);

    bool notgood = false;

    if (begin > end)
    {
        printf("%ld isn't smaller than %ld.\n", begin, end);
        notgood = true;
    }

    if (begin < min or end < min)
    {
        printf("Values must be %ld or greater.\n", min);
        notgood = true;
    }

    if (begin > max or end > max)
    {
        printf("Values must be %ld or less.\n", max);
        notgood = true;
    }

//  return notgood;

    printf("input %d.\n", notgood);

    return 0;
}

