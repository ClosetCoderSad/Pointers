/******************************************************************************

Ask the use to enter how many student scores will be entered. Allow the user to enter name–score pairs. 
For each student taking a test, the user types the student’s name followed by the student’s integer test score. 
Modify the selectionSort sorting function so it takes a pointer to array holding the student names, and a pointer to array holding 
the student test scores. Sort on the student scores. When the sorted list of scores is displayed, each student’s name should be displayed 
along with his or her score. In stepping through the arrays, use pointers rather than array subscripts.

*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void sort(string*, double*, int);  
double average(double*, int); 

int main()
{
   // Declare variable to hold the number of test scores
   int numOfScores;
   // Declare variable o hold the average score
   double avgScore;
   // Declare variable to point to the scores array
   double *ptrScores = nullptr;
   // Declare variable to point to the names array
   string *ptrNames = nullptr;

   // Get the number of test scores.
   cout << "\nHow many test scores will you enter? ";
   cin >> numOfScores;
   
   
   // Validate the input. Should be > 0, if not ask the user to enter again
   while(numOfScores <= 0){
       cout << "Enter again" << endl;
       cin >> numOfScores;
   }
   // Allocate an array to hold the test scores.
   ptrScores = new double[numOfScores];                                    // to allocate dynamic version of scores array
   
   // Allocate an array to hold the names.
   ptrNames = new string[numOfScores];                                     // to allocate dynamic version of string array
  
   // Populate the two arrays.Check that score are postive values, otherwise ask to enter again
   for(int i=0; i < numOfScores; i++){
       cout << "\nEnter student " << i+1 << "'s name: ";
       cin >> ptrNames[i];
       cout << "Enter that student's test score: ";
       cin >> ptrScores[i];
       if(ptrScores[i] < 0){
           cout << "Negative scores are not allowed." << endl;
           cout << "Enter another score for this test: ";
           cin >> ptrScores[i];
       }
   }


   // Sort the test scores.
   sort(ptrNames, ptrScores, numOfScores);


   // Get the average of the test scores.
   avgScore = average(ptrScores, numOfScores);
   

   // Display the resulting data.
   cout << "\nThe test scores in ascending "
        << "order, and their average, are:\n\n";
   cout << setw(12) << left << "Name" << setw(6) 
        << " Score" << endl;
   cout << "----------------------------------------" << endl;
   cout << setprecision(2) << fixed << showpoint;
   
   //display scores 
   //display average score
   cout << endl;
   for(int i=0; i<numOfScores; i++){
       cout << setw(12) << left << *(ptrNames + i) << setw(6) << left << *(ptrScores + i) << endl;
   }
   
   cout << "\nAverage score:  " << avgScore << "\n\n";

   // Free the dynamically-allocated memory.
   delete [] ptrScores;
   delete [] ptrNames;
   
   ptrScores = nullptr, ptrNames = nullptr;
 
   
   return 0;
}

// Function definitions
void sort(string *ptrNames, double *ptrScores, int numOfScores){
    int minIndex;
    int minValue;
    string minValName;
    for(int i=0; i < numOfScores - 1; i++){
        minIndex = i;
        minValue = *(ptrScores + i);
        minValName = *(ptrNames + i);
        for(int j=i+1; j < numOfScores; j++){
            if(*(ptrScores + j) < minValue){
                minIndex = j;
                minValue = *(ptrScores + j);
                minValName = *(ptrNames + j);
            }
        }
        swap(*(ptrScores + i), *(ptrScores + minIndex));
        swap(*(ptrNames + i), *(ptrNames + minIndex));
    }
}

double average(double *ptrScores, int numOfScores){
    int total = 0; 
    double avg;
    for(int i=0; i<numOfScores; i++){
        total += *(ptrScores + i);
    }
    avg = static_cast<double>(total)/numOfScores;
    
    return avg;
    
}