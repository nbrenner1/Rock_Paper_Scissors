//*******************************************************************************************
// Program name: A2: Files and Pointers
// Author: Nick Brenner
// Functionality: This code reads in from a file entitled "students_scores.txt"
// 				        before determining the min and max score for each student as well as
// 			          sorting the students' scores from lowest to highest. If a negative score
// 			          is found, an error message is displayed for that student.
//*******************************************************************************************

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void findMin(float *min, float arr[], int arrSize)
{
    *min=arr[0];                    // Set min to the first value in the array
    for (int i=1; i<arrSize; i++)
    {
        if (arr[i]<*min)            // Check and replace if necessary
        {
            *min = arr[i];
        }
    }
}

void findMax(float *max, float arr[], int arrSize)
{
    *max=arr[0];                    // Set max to first value in the array
    for (int i=1; i<arrSize; i++)
    {
        if (arr[i]>*max)            // Check and replace if necessary
        {
            *max = arr[i];
        }
    }
}

void sortScores(float arr[], int arrSize)
{
    float newArray[arrSize];           // Create new array of the same size for the sorted values
    for (int i=0; i<arrSize; i++)
    {
        newArray[i]=arr[i];
    }
    
    for (int j=0; j<arrSize - 1; j++)
    {
        for (int k=0; k<arrSize - 1; k++)
        {
            if (newArray[k]>newArray[k + 1])     // Standard bubble sort used to sort values in our new array
            {
               int temp = newArray[k];          
               newArray[k]=newArray[k+1];
               newArray[k+1]=temp;
            }
        }
    }
    
    cout << "Sorted array: ";
    for (int g=0; g<arrSize - 1; g++)      // Output sorted array values
    {
        cout << newArray[g] << ", ";
    }
    
    cout << newArray[arrSize - 1];         // Output the final sorted value without a comma afterwards
    cout << "\n";                          // Two new lines added for space between students
    cout << "\n";
    
}

int main()
{
	ifstream myFile;
	myFile.open("students_scores.txt");
	string studentName;
    float studentScores[1000]={0};
	string line2;
	int i=0;
	float min=0;
	float max=0;
	int invalid=0;
	
	while (getline(myFile, studentName))   // Start reading first line of file
	{
        i=0;
        invalid=0;
		getline(myFile, line2);            // Begin reading second line
		
		while(line2.length()!=0)
		{
		    string score = "";
		    int commaLocation = line2.find(',');   // Use .find() function to locate commas and save location to int commaLocation
		    if (commaLocation>0)
		    {
		        score = line2.substr(0,commaLocation);    // Save only the number value to score by deleting commas
                line2.erase(0,line2.find(',')+1);
		    }
		    else
		    {
		        score = line2.substr(0,line2.length()-1);    // If there is no comma, this else skips over the semicolon and then clears the line
		        line2="";
		    }
		
            float num_float = stof(score);
			
            try                                            // Check for negative numbers
		    {
				if (num_float<0) 
				{
					throw runtime_error("negative number detected!");
				}
		    } 
     
		    catch(runtime_error e)                         // Display error if a negative number is caught
		    {
			    cout << "Grades for student " << studentName << " are invalid, " << e.what() << endl;
			    cout << "\n";
		    }
            
            studentScores[i]=num_float;        // Add number to array of student scores
            i++;							   // Increment to fill next array "bucket" on following loop
			
            for (int a=0; a<i; a++)            // Check array for negatives
            {
                if (studentScores[a]<0)
                {
                    invalid = 1;
                }
            }
		}

        if (invalid!=1)                        // This if statement ensures the scores and the min and max are not displayed if there are invalid scores (i.e. negatives)
        {
            findMin(&min, studentScores, i);   // Pass by reference min and max into each of their respective functions
            findMax(&max, studentScores, i);   // i is passed in as the size of the score array (in order to handle any number of scores
            
            cout << "Student " << studentName << " has a high score of " << max << " and a low score of " << min << endl;
            sortScores(studentScores, i);      // Call sorting function, passing in our array and the size of the array, i
        }
	}
	
	return 0; 
}
