//lru run  time
#include <stdio.h>

void displayFrames(int frames[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}

int searchPage(int frames[], int capacity, int page) {
    for (int i = 0; i < capacity; i++) {
        if (frames[i] == page)
            return i; // Page found, return index
    }
    return -1; // Page not found
}

void shiftLeft(int frames[], int index, int capacity) {
    for (int i = index; i < capacity - 1; i++) {
        frames[i] = frames[i + 1];
    }
}

void LRU(int pages[], int n, int capacity) {
    int frames[capacity];
    int pageFaults = 0, index = 0;

    // Initialize frames with -1 (empty)
    for (int i = 0; i < capacity; i++)
        frames[i] = -1;

    printf("\nPage Reference Sequence:\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int pos = searchPage(frames, capacity, page);

        if (pos == -1) {  // Page fault occurs
            pageFaults++;

            if (index < capacity) { // If there is space in memory
                frames[index++] = page;
            } else { // No space, replace LRU page
                shiftLeft(frames, 0, capacity);
                frames[capacity - 1] = page;
            }
        } else { // Page found, move it to the most recently used position
            shiftLeft(frames, pos, capacity);
            frames[capacity - 1] = page;
        }

        // Print frame contents after each reference
        printf("Page %d -> Frames: ", page);
        displayFrames(frames, capacity);
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
}

int main() {
    int n, capacity;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    LRU(pages, n, capacity);

    return 0;
}