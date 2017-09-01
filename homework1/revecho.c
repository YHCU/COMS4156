#include <stdio.h>
#include <string.h>
#include "mylist.h"

void printString(void *string) {
    printf("%s\n", (char *)string);
}

int compareString(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main(int argc, char **argv) {
    if (argc == 0) return 0;
    
    struct List list;
    initList(&list);

    
    for (int i = 1; i < argc; i++) {
        addFront(&list, argv[i]);
    }

    traverseList(&list, &printString);

    // Find dude
    char *dude = "dude";
    if (findNode(&list, dude, &compareString) != NULL) {
        printf("\ndude found\n");
    } else {
        printf("\ndude not found\n");
    }

    removeAllNodes(&list);

    return 0;
}
