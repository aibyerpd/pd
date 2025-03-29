#include <stdio.h>
#include <limits.h>

int findOptimalPage(int pages[], int n, int frames[], int frameSize, int index) {
    int farthest = index, replaceIndex = -1;

    for (int i = 0; i < frameSize; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return (replaceIndex == -1) ? 0 : replaceIndex;
}

int main() {
    int n, frameSize;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frameSize);

    int frames[frameSize];
    int pageFaults = 0, count = 0;

    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (count < frameSize) {
                frames[count++] = pages[i];
            } else {
                int replaceIndex = findOptimalPage(pages, n, frames, frameSize, i + 1);
                frames[replaceIndex] = pages[i];
            }
            pageFaults++;
        }

        printf("Frames after processing page %d: ", pages[i]);
        for (int j = 0; j < frameSize; j++) {
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