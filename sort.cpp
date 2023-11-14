#include <iostream>
#include <vector>
#include <random>
#include <string>

class Sort
{
    private:
        std::vector<int> arr;
        int size;

    public:
        Sort();
        int random_number_generator();
        int return_size();
        void print_arr();
        void bubbleSort();
        void insertionSort();
        void selectionSort();
        void mergeSort(int l, int r);
        void merge(int p, int q, int r);
        void quickSort(int low, int high);
        int partition(int low, int high);
};

Sort::Sort()
{
    size = random_number_generator();
    std::cout << "make array with size: " << size << '\n';
    for (int i = 0; i < size; ++i)
    {
        int num = random_number_generator();
        arr.push_back(num);
    }
}

int Sort::return_size()
{
    return size;
}

int Sort::random_number_generator()
{
    // Create a random number generator engine
    std::random_device rd;            // Obtain a random number from hardware
    std::mt19937 engine(rd());         // Standard Mersenne Twister engine

    // Define a distribution
    std::uniform_int_distribution<int> distribution(1, 10); // Range from 1 to 10

    // Generate a random number
    int random_number = distribution(engine);

    // Return the random number
    return random_number;
}

void Sort::print_arr()
{
    std::cout << "printing array..." << '\n';
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << '\n';
}

// function to swap the the position of two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Sort::bubbleSort()
{
    // loop to access each array element
    for (int step = 0; step < (size - 1); ++step)
    {

        // check if swapping occurs
        int swapped = 0;

        // loop to compare two elements
        for (int i = 0; i < (size - step - 1); ++i)
        {

            // compare two array elements
            // change > to < to sort in descending order
            if (arr[i] > arr[i + 1])
            {

                // swapping occurs if elements
                // are not in intended order
                
                swap(&arr[i], &arr[i + 1]);

                swapped = 1;
            }
        }

        // no swapping means the array is already sorted
        // so no need of further comparison
        if (swapped == 0)
            break;
    }
    std::cout << "array sorted...\n";
}

void Sort::insertionSort()
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void Sort::selectionSort()
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
    {

        // To sort in descending order, change > to < in this line.
        // Select the minimum element in each loop.
        if (arr[i] < arr[min_idx])
            min_idx = i;
    }

        // put min at the correct position
        swap(&arr[min_idx], &arr[step]);
    }
}

void Sort::merge(int p, int q, int r)
{
  
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<int> L;
    std::vector<int> M;

    for (int i = 0; i < n1; i++)
        L.push_back(arr[p + i]);
    for (int j = 0; j < n2; j++)
        M.push_back(arr[q + 1 + j]);

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
        arr[k] = L[i];
        i++;
        } 
        else 
        {
        arr[k] = M[j];
        j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void Sort::mergeSort(int l, int r)
{
   if (l < r)
   {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    // Merge the sorted subarrays
    merge(l, m, r);
  }
}

void Sort::quickSort(int low, int high)
{
    if (low < high) 
    {
      
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(low, high);

        // recursive call on the left of pivot
        quickSort(low, pi - 1);

        // recursive call on the right of pivot
        quickSort(pi + 1, high);
  }
}

int Sort::partition(int low, int high)
{
    // select the rightmost element as pivot
  int pivot = arr[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&arr[i], &arr[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swap(&arr[i + 1], &arr[high]);
  
  // return the partition point
  return (i + 1);
}

void menu()
{
    bool sort_array_flag = false; // Declare sort_array_flag outside the loop
    Sort array;
    while (true)
    {
        int number;
        std::cout << "select a number and press enter...\n";
        std::cout << "1. print an array with random numbers.\n";
        std::cout << "2. sort the array with bubble sort algorithm.\n";
        std::cout << "3. sort the array with insertion sort algorithm.\n";
        std::cout << "4. sort the array with selection sort algorithm.\n";
        std::cout << "5. sort the array with merge sort algorithm.\n";
        std::cout << "6. sort the array with quick sort algorithm.\n";
        std::cout << "7. making another array\n";
        std::cout << "8. exit.\n";
        std::cin >> number;

        if (number != 1 && number != 8 && number != 7 && sort_array_flag == true)
        {
            std::string prompt;
            std::cout << "your array was already sorted\n"
                      << "do you want to make another array?(y/n)";
            std::cin >> prompt;
            if (prompt == "y" || prompt == "yes")
            {
                array = Sort();
                sort_array_flag = false;
            }
            else
                break;
        }
        else if (number == 1)
            array.print_arr();
        else if (number == 2)
        {
            array.bubbleSort();
            sort_array_flag = true;
        }
        else if (number == 3)
        {
            array.insertionSort();
            sort_array_flag = true;
        }
        else if (number == 4)
        {
            array.selectionSort();
            sort_array_flag = true;
        }
        else if (number == 5)
        {
            array.mergeSort(0, array.return_size() - 1);
            sort_array_flag = true;
        }
        else if (number == 6)
        {
            array.quickSort(0, array.return_size() - 1);
            sort_array_flag = true;
        }
        else if (number == 7)
        {
            array = Sort();
            sort_array_flag = false;
        }
        else if (number == 8)
            break;
    }
}

int main()
{
    menu();
    return 0;
}
