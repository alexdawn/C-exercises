#include <stdio.h>
# define IN 1
# define OUT 0
# define MAXWORDLENGTH 50
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
        for (int x = 0; x <= max_idx; x++) {
            putchar(' '); // need to print right amount for the count
            hist[x] * scale_factor >= y ? printf("%c%c%c", 0xE2, 0x96, 0x88) : putchar(' ');
        }
        putchar('\n');
    }
    for (int i = 0; i <= max_idx; ++i)
        printf(" %d", hist[i]);
    putchar('\n');
}

main()
{
    int c, nl, nw, nc, state, wl;
    int hist[MAXWORDLENGTH];

    for (int i = 0; i < MAXWORDLENGTH; ++i)
        hist[i] = 0;

    state = OUT;
    nl = nw = nc = wl = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state) {
                ;//printf("%d\n", wl);
                if (wl < MAXWORDLENGTH)
                    hist[wl]++;
                else
                    ;//printf("ERROR %d EXCEEDED MAX SIZE OF %d\n", wl, MAXWORDLENGTH);
                wl = 0;
            }
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
            ++wl;
        }
        else {
            ++wl;
        }
    }
    printf("lines: %d, words: %d, charecters: %d\n", nl, nw, nc);
    print_histogram(hist);
}
