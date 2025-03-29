#include <stdio.h>
#define MAX_FRAMES 10

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 5, 6};  // Page reference sequence
    int n = 12;  // Number of pages
    int frames[MAX_FRAMES] = {-1, -1, -1};  // Frames initialized to empty
    int f = 3;  // Number of frames
    int page_faults = 0, current_frame = 0, i, j, k, found;

    for (i = 0; i < n; i++) {
        found = 0;

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