#include <stdio.h>
#define MAX_FRAMES 10
#define MAX_PAGES 100

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES];
    int n, f, i, j, k, page_faults = 0;
    int current_frame = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference sequence: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int found = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[current_frame] = pages[i];
            current_frame = (current_frame + 1) % f;
            page_faults++;
        }

        printf("\nFrames: ");
        for (k = 0; k < f; k++) {
            if (frames[k] == -1)
                printf("- ");
            else
                printf("%d ", frames[k]);
        }
    }

    printf("\n\nTotal Page Faults: %d\n", page_faults);

    return 0;
}