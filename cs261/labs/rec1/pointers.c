#include <stdio.h>
#include <stdlib.h>

void
f(void)
{
    //a is a pointer to 4 allocated int values
    int a[4];
    //poits to memory in the heap that can store 16 bytes of data
    int *b = malloc(16);
    //pointer
    int *c;
    int i;

    printf("1: a = %p, b = %p, c = %p\n", a, b, c);
    //c gets the a pointer, so c points to a which points to array in heap
    c = a;
    //for loop 
    for (i = 0; i < 4; i++)
	a[i] = 100 + i;
    //a[0] is the same as c[0]
    //c[0] changed to 200 so a[0] changed too
    c[0] = 200;
    printf("a = %p, b = %p, c = %p\n", a, b, c);
    printf("2: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);
    
    //assign index 1 300
    c[1] = 300;
    //dereferences c + 2 which means c[2] gets 301
    *(c + 2) = 301;
    //third index of c gets 302
    3[c] = 302;
    printf("a = %p, b = %p, c = %p\n", a, b, c);
    printf("3: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);

    c = c + 1;
    *c = 400;
    printf("a = %p, b = %p, c = %p\n", a, b, c);
    printf("4: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);

    c = (int *) ((char *) c + 1);
    *c = 500;
    printf("a = %p, b = %p, c = %p\n", a, b, c);
    printf("5: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n",
	   a[0], a[1], a[2], a[3]);

    b = (int *) a + 1;
    //converts from int pointer to char pointer
    //adding one to a pointer traverses an array 
    c = (int *) ((char *) a + 1);
    printf("a = %p, b = %p, c = %p\n", a, b, c);
    printf("6: a = %p, b = %p, c = %p\n", a, b, c);
}

int
main(int ac, char **av)
{
    f();
    return 0;
}
