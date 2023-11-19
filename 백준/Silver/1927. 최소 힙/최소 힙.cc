#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    long long* arr;
    int size;
    int capacity;
} Heap;

void createHeap(Heap* pHp, int count)
{
    pHp->arr = (long long*)malloc(sizeof(long long) * count);
    pHp->size = 0;
    pHp->capacity = count;
}

void shiftup(long long* arr, int childIdx)
{
    int parentIdx = (childIdx - 1) / 2;
    long long temp;

    if (parentIdx < 0)
        return;

    if (arr[parentIdx] > arr[childIdx])
    {
        temp = arr[parentIdx];
        arr[parentIdx] = arr[childIdx];
        arr[childIdx] = temp;

        shiftup(arr, parentIdx);
    }
}

void shiftdown(long long* arr, int parentIdx, int size)
{
    int childIdx1 = (parentIdx * 2) + 1;
    int childIdx2 = (parentIdx * 2) + 2;
    int minIdx = -1;

    if (childIdx1 < size)
        minIdx = childIdx1;
    if (childIdx2 < size && arr[minIdx] > arr[childIdx2])
        minIdx = childIdx2;

    if (minIdx == -1)
        return;

    if (arr[minIdx] < arr[parentIdx])
    {
        long long temp;
        temp = arr[parentIdx];
        arr[parentIdx] = arr[minIdx];
        arr[minIdx] = temp;

        shiftdown(arr, minIdx, size);
    }
}

void addHeap(Heap* pHp, long long value)
{
    if (pHp->capacity == pHp->size)
        return;
    pHp->arr[pHp->size] = value;
    shiftup(pHp->arr, pHp->size);
    pHp->size++;
}

void deleteHeap(Heap* pHp)
{
    if (pHp->size == 0)
    {
        printf("0\n");
        return;
    }
    long long minNum = pHp->arr[0];
    pHp->arr[0] = pHp->arr[pHp->size - 1];
    pHp->size--;
    shiftdown(pHp->arr, 0, pHp->size);
    printf("%lld\n", minNum); // %lld로 수정
}

int main()
{
    Heap heap;

    int n;
    scanf("%d", &n);
    createHeap(&heap, n);
    for (int i = 0; i < n; i++)
    {
        long long num;
        scanf("%lld", &num); // %lld로 수정
        if (num == 0)
            deleteHeap(&heap);
        else
            addHeap(&heap, num);
    }

    return 0;
}