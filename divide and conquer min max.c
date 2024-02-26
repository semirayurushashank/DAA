#include <stdio.h>
struct MinMax {
    int min;
    int max;
};
struct MinMax findMinMax(int arr[], int low, int high) {
    struct MinMax result, left, right;
    int mid;
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }
    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);
    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}
int main() {
    int n,i;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the list:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct MinMax result = findMinMax(arr, 0, n - 1);
    printf("Minimum value in the list: %d\n", result.min);
    printf("Maximum value in the list: %d\n", result.max);
    return 0;
}
