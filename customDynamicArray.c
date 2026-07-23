#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *a, int initialCapacity) {
    a->data = (int *)malloc(initialCapacity * sizeof(int));
    a->size = 0;
    a->capacity = initialCapacity;
}

void insertArray(DynamicArray *a, int element) {
    if (a->size == a->capacity) {
        a->capacity *= 2;
        a->data = (int *)realloc(a->data, a->capacity * sizeof(int));
    }
    a->data[a->size++] = element;
}

void freeArray(DynamicArray *a) {
    free(a->data);
    a->data = NULL;
    a->size = a->capacity = 0;
}

int main() {
    DynamicArray arr;
    initArray(&arr, 2); // Start small to trigger expansions

    for (int i = 1; i <= 5; i++) {
        insertArray(&arr, i * 10);
    }

    printf("Dynamic Array Elements:\n");
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\nCapacity: %d, Size: %d\n", arr.capacity, arr.size);

    freeArray(&arr);
    return 0;
}
