/*Write a function that dynamically allocates an array of integers. 
The function should accept an integer argument indicating the number of elements to allocate. 
The function should return a pointer to the array.*/
#include <iostream>
using namespace std;

// Function Prototype
int* arrayAllocator(int);

int main()
{
   // Declare variables:
   // To hold the number of elements to allocate
   // A pointer to the array
   int size;
   int *pptr = nullptr;

   // Get the array size.
   cout << "\nEnter an array size: ";
   cin >> size;
   
   
   // Allocate the array 
   //arrayAllocator(...,...);
   pptr = arrayAllocator(size);
   

   // Fill the array with values, 0,1,2,3,4,5,6.........
   for(int i=0; i < size; i++){
       *(pptr + i) = i;
   }
 

   // Display the values of the array
   cout << "Here are the values in the array:\n";
   for(int i=0; i<size; i++){
       cout << "Element " << i << " has the value " << *(pptr + i) << endl;
   }
   
   // Deallocate the array and set pptr to nullptr
   delete [] pptr;
   pptr = nullptr;
   
   
   return 0;
}

// Function Definition
int *arrayAllocator(int size){
    int *pptr = new int[size];
    return pptr;
}