#include <stdio.h>
#include <limits.h>

#define N 12          // Number of pages
#define FRAME_SIZE 3  // Number of frames

int findOptimalPage(int pages[], int frames[], int index) {
    int farthest = index, replaceIndex = -1;

    for (int i = 0; i < FRAME_SIZE; i++) {
        int j;
        for (j = index; j < N; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        if (j == N) {
            return i;
        }
    }
    return (replaceIndex == -1) ? 0 : replaceIndex;
}

int main() {
    int pages[N] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 5, 6};  // Page reference sequence
    int frames[FRAME_SIZE];
    int pageFaults = 0, count = 0;

    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i] = -1;  // Initialize frames
    }

    for (int i = 0; i < N; i++) {
        int found = 0;

        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (count < FRAME_SIZE) {
                frames[count++] = pages[i];
            } else {
                int replaceIndex = findOptimalPage(pages, frames, i + 1);
                frames[replaceIndex] = pages[i];
            }
            pageFaults++;
        }

        printf("Frames after processing page %d: ", pages[i]);
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}