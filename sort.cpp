#include<iostream>
using namespace std;

void selection_sort(int* B, int length)
{
    int i,j,temp,max;
    for(i=length-1;i>=0;i--)
    {
        max=i;
        for(j=0;j<=i;j++)
        {
            if(*(B+j)>*(B+max))
            {
                max=j;
            }
        }
        temp=*(B+i);
        *(B+i)=*(B+max);
        *(B+max)=temp;
    }
}

//Bubble sort using pointers
void bubble_sort(int *B, int length)
{
    int i,j,temp;
    for(i=length-2;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            if(*(B+j)>*(B+j+1))
            {
                temp=*(B+j);
                *(B+j)=*(B+j+1);
                *(B+j+1)=temp;
            }
        }
    }
}

void Recursive_bubble_sort(int* B, int length)
{
    int i,temp;
    if(length==1 || length==0)  //base case
    return;

    for(i=0;i<length-1;i++)  //sorting
    {
        if(*(B+i)>*(B+i+1))
        {
            temp=*(B+i);  //swapping
            *(B+i)=*(B+i+1);
            *(B+i+1)=temp;
        }
    }
    Recursive_bubble_sort(B,length-1);  //calling recursive function
}
//insertion sort using while loop
void insertion_sort(int B[], int length)
{
    int i,j,key,temp;
    for(i=1;i<=length-1;i++)
    {
        key=B[i];
        j=i-1;
        while(j>=0&&B[j]>key)
        {
            temp=B[j+1];
            B[j+1]=B[j];
            B[j]=temp;
            j--;
        }

    }
}
//insertion sort using for loop
void ins_sort(int A[], int length)
{
    int i,j,key,temp;
    for(i=1;i<length;i++)
    {
        key=A[i];
        for(j=i-1;j>=0;j--)
        {
            if(A[j]<=key)
            break;
            else
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

int main(){
    //the sample array.
    int A[]={786,122,93,666,5,1000,20,1};
    //the length of array
    int l=sizeof(A)/sizeof(A[0]);
    insertion_sort(A,l);
    for (int i = 0; i < l; i++)
    {
        cout<<A[i]<<endl;
    }
    return(0);
}
/*code run successful*/