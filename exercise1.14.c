#include <stdio.h>
# define IN 1
# define OUT 0
# define MAXWORDLENGTH 256
# define HISTHEIGHT 10

int get_max_from_array(int arr[], int length) {
    int max = -1;
    for (int i = 0; i < length; i++)
        max = arr[i] > max ? arr[i] : max;
    return max;
}

int get_max_positive_index(int arr[], int length) {
    int max = -1;
    for (int i = 0; i < length; i++)
        max = arr[i] > 0 ? i : max;
    return max;
}

void print_histogram(int hist[]) {
    int max_idx = get_max_positive_index(hist, MAXWORDLENGTH);
    int max_value = get_max_from_array(hist, MAXWORDLENGTH);
    float scale_factor = HISTHEIGHT / (float)max_value;
    printf("scale factor %f\n", scale_factor);
    for (int y = max_value * scale_factor; y > 0; y--) {
        for (int x = 97; x <= 122; x++) {
            putchar(' '); // need to print right amount for the count
            hist[x] * scale_factor >= y ? printf("%c%c%c", 0xE2, 0x96, 0x88) : putchar(' ');
        }
        putchar('\n');
    }
    for (int i = 97; i <= 122; ++i)
        printf(" %c", (char)i);
    putchar('\n');
}

main()
{
    int c, nl, nw, nc, state;
    int hist[MAXWORDLENGTH];

    for (int i = 0; i < MAXWORDLENGTH; ++i)
        hist[i] = 0;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        hist[c]++;
    }
    print_histogram(hist);
}
