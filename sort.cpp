#include <iostream>
using namespace std;

void selection_sort(int *B, int length)
{
    int i, j, temp, max;
    for (i = length - 1; i >= 0; i--)
    {
        max = i;
        for (j = 0; j <= i; j++)
        {
            if (*(B + j) > *(B + max)) //equivalent to    if(B[j]>B[max])
            {
                max = j;
            }
        }
        temp = *(B + i);
        *(B + i) = *(B + max);
        *(B + max) = temp;
    }
}

//Bubble sort using pointers
void bubble_sort(int *B, int length)
{
    int i, j, temp;
    for (i = length - 2; i >= 0; i--)
    {
        for (j = 0; j <= i; j++)
        {
            if (*(B + j) > *(B + j + 1))
            {
                temp = *(B + j);
                *(B + j) = *(B + j + 1);
                *(B + j + 1) = temp;
            }
        }
    }
}

void Recursive_bubble_sort(int *B, int length)
{
    int i, temp;
    if (length == 1 || length == 0) //base case
        return;

    for (i = 0; i < length - 1; i++) //sorting
    {
        if (*(B + i) > *(B + i + 1))
        {
            temp = *(B + i); //swapping
            *(B + i) = *(B + i + 1);
            *(B + i + 1) = temp;
        }
    }
    Recursive_bubble_sort(B, length - 1); //calling recursive function
}
//insertion sort using while loop
void insertion_sort(int B[], int length)
{
    int i, j, key, temp;
    for (i = 1; i <= length - 1; i++)
    {
        key = B[i];
        j = i - 1;
        while (j >= 0 && B[j] > key)
        {
            temp = B[j + 1];
            B[j + 1] = B[j];
            B[j] = temp;
            j--;
        }
    }
}
//insertion sort using for loop
void ins_sort(int A[], int length)
{
    int i, j, key, temp;
    for (i = 1; i < length; i++)
    {
        key = A[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (A[j] <= key)
                break;
            else
            {
                temp = A[j]; //Swapping values
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int partition(int A[], int low, int high)
{
    if (low < high)
    {

        int i = low ;
        int j = high + 1;
        int key = A[low], temp;
        while (i < j)
        {
            do
            {
                i++;
            } while ((A[i] < key)&&(i<=high));
            do
            {
                j--;
            } while ((A[j] > key)&&(j>0));
            if (i < j)
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            else
            {
                A[low] = A[j];
                A[j] = key;
                return j;
            }
        }
    }
    else
    {
        return (-1);
    }
}
void quicksort(int A[], int low, int high)
{
    int x;
    if (high > low)
    {
        x = partition(A, low, high);
        if (x > 0)
        {
            quicksort(A, low, x - 1);
            quicksort(A, x + 1, high);
        }
    }
}
int main()
{
    int i;
    int Arr[] = {4,2,99, 3,65,120,10,8, 2, 85,1,99,85,85};
    int length = sizeof(Arr) / sizeof(int);
    quicksort(Arr, 0, length - 1);
    cout << "The array elements are" << endl;
    for (i = 0; i < length; i++)
    {
        cout << Arr[i] << endl;
    }
}
