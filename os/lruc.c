#include <stdio.h>

#define CAPACITY 3  // Number of frames
#define NUM_PAGES 12  // Number of pages

void displayFrames(int frames[]) {
    for (int i = 0; i < CAPACITY; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int searchPage(int frames[], int page) {
    for (int i = 0; i < CAPACITY; i++) {
        if (frames[i] == page)
            return i; // Page found, return index
    }
    return -1; // Page not found
}

void shiftLeft(int frames[], int index) {
    for (int i = index; i < CAPACITY - 1; i++) {
        frames[i] = frames[i + 1];
    }
}

void LRU(int pages[]) {
    int frames[CAPACITY];
    int pageFaults = 0, index = 0;

    for (int i = 0; i < CAPACITY; i++)
        frames[i] = -1;

    printf("\nPage Reference Sequence:\n");
    for (int i = 0; i < NUM_PAGES; i++) {
        int page = pages[i];
        int pos = searchPage(frames, page);

        if (pos == -1) {  // Page fault occurs
            pageFaults++;

            if (index < CAPACITY) {
                frames[index++] = page;
            } else {
                shiftLeft(frames, 0);
                frames[CAPACITY - 1] = page;
            }
        } else {
            shiftLeft(frames, pos);
            frames[CAPACITY - 1] = page;
        }

        printf("Page %d -> Frames: ", page);
        displayFrames(frames);
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
}

int main() {
    int pages[NUM_PAGES] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 5, 6};

    LRU(pages);

    return 0;
}