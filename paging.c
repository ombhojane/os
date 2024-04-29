#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4
#define NUM_FRAMES 4
#define NUM_PAGES 10

int page_table[NUM_PAGES];
int memory[NUM_FRAMES][PAGE_SIZE];

void init_page_table() {
    for (int i = 0; i < NUM_PAGES; ++i) {
        page_table[i] = -1;
    }
}

void init_memory() {
    for (int i = 0; i < NUM_FRAMES; ++i) {
        for (int j = 0; j < PAGE_SIZE; ++j) {
            memory[i][j] = -1;
        }
    }
}

void display_page_table() {
    printf("Page Table:\n");
    for (int i = 0; i < NUM_PAGES; ++i) {
        printf("Page %d -> Frame %d\n", i, page_table[i]);
    }
    printf("\n");
}

void display_memory() {
    printf("Memory:\n");
    for (int i = 0; i < NUM_FRAMES; ++i) {
        printf("Frame %d: ", i);
        for (int j = 0; j < PAGE_SIZE; ++j) {
            printf("%d ", memory[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void page_fault(int page) {
    printf("Page %d not in memory. Page fault!\n", page);
    int frame = rand() % NUM_FRAMES;
    printf("Loading Page %d into Frame %d\n", page, frame);
    page_table[page] = frame;
    for (int i = 0; i < PAGE_SIZE; ++i) {
        memory[frame][i] = page * PAGE_SIZE + i;
    }
}

int main() {
    srand(time(NULL));
    init_page_table();
    init_memory();

    for (int i = 0; i < 20; ++i) {
        int page = rand() % NUM_PAGES;
        if (page_table[page] == -1) {
            page_fault(page);
        }
        display_page_table();
        display_memory();
    }

    return 0;
}
