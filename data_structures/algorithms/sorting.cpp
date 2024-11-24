/*
    sorting algorithms
    -------------------
    1- Bubble sort algorithm
    2-  optimized bubble sort algorithm
    3-
    4-
    5-




*/
#include <iostream>
using namespace std;

// Bubble sort in C++
// --------------------------------------------------------------------------------------------
// avg Time complexity = O(n2) , brute force
// Space complexity = O(1)
//

// function to swap the the position of two elements  in the
// ??????????????????????????? it accepts array[i] and &array[i] how ??
void swap(int *a, int *b) {
  int temp = *a; // holding the element to be used later
  *a = *b;
  *b = temp;
}

// perform bubble sort
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size; ++step) {

    // loop to compare array elements
    for (int i = 0; i < size - step; ++i) {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {

        // swapping elements if elements
        // are not in the intended order
        swap(&array[i + 1], &array[i]);
      }
    }
  }
}
//////////////////////////////////////////////////////////
// insertion sort ... like bubble sort but it quit un needed loops, if array is
// sorted-> break
void insertion_Sort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size; ++step) {
    // loop to compare array elements
    // swap only if array[j+1]<array[j] other wise skipand save your time and
    // effort
    for (int j = step; array[j + 1] < array[j] && j >= 0; j--) {
      // swapping elements if elements are not in the intended order
      swap(&array[j + 1], &array[j]);
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Optimized bubble sort in C++
/*we can introduce an extra variable swapped. The value of swapped is set true
if there occurs swapping of elements. Otherwise, it is set false. After an
iteration, if there is no swapping, the value of swapped will be false. This
means elements are already sorted and there is no need to perform further
iterations. This will reduce the execution time and helps to optimize the bubble
sort.*/

// avg Time complexity = O(n2)
// Space complexity = O(2)
//
// perform bubble sort
void optimized_bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < (size - 1); ++step) {

    // check if swapping occurs
    int swapped = 0;

    // loop to compare two elements
    for (int i = 0; i < (size - step - 1); ++i) {

      // compare two array elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        // swapping elements if elements
        // are not in the intended order
        swap(&array[i + 1], &array[i]);

        swapped = 1;
      }
    }

    // no swapping means the array is already sorted
    // so no need of further comparison
    if (swapped == 0)
      break;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Selection sort in C++
// selection sort is a sorting algorithm that selects the smallest element from
// an unsorted list in each iteration and places that element at the beginning
// of the unsorted list.

//  Time complexity = O(n2)
// Space complexity = O(1)

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Merge Sort
//  Merge two subarrays L and M into arr ----- void merge(int arr[], int p, int
//  q, int r)
//   Time complexity = O(n*log n)
//  Space complexity = O(n)

// Merge two subarrays L and M into arr
void merge_sort(int arr[], int left, int mid, int right) {
  // devide
  //  Create L ← A[left..mid] and M ← A[mid+1..r]
  int lsize = mid - left + 1;
  int rsize = right - mid;

  int *left_arr = new int[lsize];
  int *right_arr = new int[rsize];

  for (int i = 0; i < lsize; i++)
    left_arr[i] = arr[left + i];
  for (int j = 0; j < rsize; j++)
    right_arr[j] = arr[mid + 1 + j];

  // Merge
  // Maintain current index of sub-arrays and main array
  int right_index, left_index, main_index;
  right_index = 0;   // right_index
  left_index = 0;    // left_index
  main_index = left; // main array index

  // Until we reach either end of either L or M, picmain_index larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (right_index < lsize && left_index < rsize) {
    if (left_arr[right_index] <= right_arr[left_index]) {
      arr[main_index] = left_arr[right_index];
      right_index++;
    } else {
      arr[main_index] = right_arr[left_index];
      left_index++;
    }
    main_index++;
  }

  // When we run out of elements in either L or M,
  // picmain_index up the remaining elements and put in A[p..r]
  while (right_index < lsize) {
    arr[main_index] = left_arr[right_index];
    right_index++;
    main_index++;
  }

  while (left_index < rsize) {
    arr[main_index] = right_arr[left_index];
    left_index++;
    main_index++;
  }
}
// apllay recursion
//  Divide the array into two subarrays, sort them and merge them
void mergeSort_algo(int arr[], int left, int right) {
  // if left >= righ merging is finished
  if (left >= right)
    return;

  if (left < right) {
    // m is the point where the array is divided into two subarrays
    int mid = left + (right - left) / 2;

    mergeSort_algo(arr, left, mid);
    mergeSort_algo(arr, mid + 1, right);

    // Merge the sorted subarrays
    merge_sort(arr, left, mid, right);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Quicksort
// is a sorting algorithm based on the divide and conquer
//  Time complexity = O(n2)
// Space complexity = O(log n)

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Counting sort algorithm
// better than algorithms that depends on comparison
// in this algorithm , we will have 3 arrays  , the input array , count array ,
// cumulative array count array : its size is the max element in the input array
// , its elements are the count of each element in the input array cumulative
// array : from the count array

// Complexity = O(n+k)  (linear complexity)
// space complexity = O(max)

void countSort(int array[], int size) {
  // The size of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int output[10];
  int count[10];
  int max = array[0];

  // Find the largest element of the array
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Radix sorting algorithm
// better than algorithms that depends on comparison
// Radix sort is a sorting algorithm that sorts the elements by first grouping
// the individual digits of the same place value.
//           Then, sort the elements according to their increasing/decreasing
//           order. Use any stable sorting technique to sort the digits at each
//           significant place

// Complexity = O(n+k)  (linear complexity)
// space complexity = O(max)

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bucket sort Algorithm
//  - a scatter - gather algorithm
//  - devide the input array into buckets -collections - then sort each bucket
//  by any sorting technique or recursively apply bucketing ....
//        and finally reconstruct the array
// Best --> O(n+k) ---- space complexity
// Worst --> O(n2)
// Average --> O(n)

#define NARRAY 7    // Array size
#define NBUCKET 6   // Number of buckets
#define INTERVAL 10 // Each bucket capacity

struct Node {
  int data;
  struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);

// Sorting function
void BucketSort(int arr[]) {
  int i, j;
  struct Node **buckets;

  // Create buckets and allocate memory size
  buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

  // Initialize empty buckets
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = NULL;
  }

  // Fill the buckets with respective elements
  for (i = 0; i < NARRAY; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }

  // Print the buckets along with their elements
  for (i = 0; i < NBUCKET; i++) {
    cout << "Bucket[" << i << "] : ";
    printBuckets(buckets[i]);
    cout << endl;
  }

  // Sort the elements of each bucket
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }

  cout << "-------------" << endl;
  cout << "Bucktets after sorted" << endl;
  for (i = 0; i < NBUCKET; i++) {
    cout << "Bucket[" << i << "] : ";
    printBuckets(buckets[i]);
    cout << endl;
  }

  // Put sorted elements on arr
  for (j = 0, i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  for (i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      struct Node *tmp;
      tmp = node;
      node = node->next;
      free(tmp);
    }
  }
  free(buckets);
  return;
}

// Function to sort the elements of each bucket
struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

int getBucketIndex(int value) { return value / INTERVAL; }

// Print buckets
void print(int ar[]) {
  int i;
  for (i = 0; i < NARRAY; ++i) {
    cout << setw(3) << ar[i];
  }
  cout << endl;
}

void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    cout << setw(3) << cur->data;
    cur = cur->next;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}
////////////////////////////////////////////////
int main() {
  int data[] = {-2, 45, 33, 12, 6, 55, 44, 74, 88, 11, 88, 5, 6, 5, 0, 11, -9};

  // find the array's length
  int size = sizeof(data) / sizeof(data[0]);

  selectionSort(data, size);

  cout << "Sorted Array in Ascending Order:\n";
  printArray(data, size);
}
/////////////////////////////////////////////////////
