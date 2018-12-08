// Dakota Wilson
// Program 6 - Texas Idol
// CMPS 1044 - Dr. Halverson
// 11/15/18
// This program uses 3 prototypes and a main function to calculate the average
//score between 5 scores with the lowest and highest scores being omitted. The
//main function takes in 5 different variables from an input file and uses 
//those in a call to the prototype where the formula is stated and does the 
//math in there. It will then find the average of the numbers without those 
//that were omitted. It then makes a table that shows the contestants last 
//name as read from an input file then there average with the ones numbers 
//omitted, and lastly all of the 5 scores that they recived.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

double Find_Highest(double Num1A, double Num2A, double Num3A, double Num4A,
	double Num5A);// calls function to find the highest score
double Find_Lowest(double Num1B, double Num2B, double Num3B, double Num4B,
	double Num5B);// calls function to find lowest score
double Calculate_Score(double Num1C, double Num2C, double Num3C, double Num4C,
	double Num5C);// calls function that finds average with omited scores

int main()
{
	string Name; //makes a string for a name
	double Num1, Num2, Num3, Num4, Num5, Avg;

	ifstream infile;
	infile.open("Input_Program6.txt");
	ofstream outfile;
	outfile.open("Output_Program6.txt");

	outfile << "Dakota Wilson\n\n";
	outfile << "  Name     Avg.Score         Judges' Scores\n";
	outfile << "                       #1    #2    #3    #4    #5\n";

	while (infile >> Name >> Num1 >> Num2 >> Num3 >> Num4 >> Num5) //inputs a
							   //Name then 5 inputs from the file until empty
	{
		Avg = Calculate_Score(Num1, Num2, Num3, Num4, Num5);//calls the 
						   //prototype to find average score with omited
		outfile << left << setw(8) << Name << right << setw(10) << fixed <<
			setprecision(3) << Avg << setw(8) << fixed << setprecision(1) <<
			Num1 << setw(6) << Num2 << setw(6) << Num3 << setw(6) << Num4 <<
			setw(6) << Num5 << '\n';// Formats the inside of the table
	}// done reading data from file so countinues on reading the code
	infile.close();
	outfile.close();
	return 0;
}

// Function: Find_Highest
// Input: the 5 judges score
// Process: print the highest value of 5 given numbers
// Output: none
// This is used to calculate the highest number of the 5 given scores
double Find_Highest(double Num1A, double Num2A, double Num3A, double Num4A,
	double Num5A)
{
	double Highest;

	if (Num1A > Num2A && Num1A > Num3A && Num1A > Num4A && Num1A > Num5A)
		Highest = Num1A;// Makes it so that the first number given is highest
	else if (Num2A > Num3A && Num2A > Num4A && Num2A > Num5A)
		Highest = Num2A;//Makes it so that the second number given is highest
	else if (Num3A > Num4A && Num3A > Num5A)
		Highest = Num3A;// Makes it so that the third number given is highest
	else if (Num4A > Num5A)
		Highest = Num4A;// Makes it so that the fourth number given is highest
	else
		Highest = Num5A;// Makes it so that the fifth number given is highest

	return  Highest;// gives highest value
}

// Function: Find_Lowest
// Input: the 5 judges score
// Process: print the lowest value of 5 given numbers
// Output: none
// This is used to calculate the lowest number of the 5 given scores
double Find_Lowest(double Num1B, double Num2B, double Num3B, double Num4B,
	double Num5B)
{
	double Lowest;

	if (Num1B < Num2B && Num1B < Num3B && Num1B < Num4B && Num1B < Num5B)
		Lowest = Num1B;// Makes it so that the first number given is lowest
	else if (Num2B < Num3B && Num2B < Num4B && Num2B < Num5B)
		Lowest = Num2B;// Makes it so that the second number given is lowest
	else if (Num3B < Num4B && Num3B < Num5B)
		Lowest = Num3B;// Makes it so that the third number given is lowest
	else if (Num4B < Num5B)
		Lowest = Num4B;// Makes it so that the fourth number given is lowest
	else
		Lowest = Num5B;// Makes it so that the fifth number given is lowest

	return  Lowest;// gives lowest value
}

// Function: Calculate_Score
// Input: the 5 judges score
// Process: calculate the avrage of the 5 given numbers while omiting the 
//highest and lowest
// Output: none
// This is used to take the 5 inputs and omit the highest and lowest to then
//calculate the avrage of the 3 remaning scores
double Calculate_Score(double Num1C, double Num2C, double Num3C, double Num4C,
	double Num5C)
{
	double Average, HighestScore, LowestScore;

	LowestScore = Find_Lowest(Num1C, Num2C, Num3C, Num4C, Num5C);// uses the 
				 //function for finding the lowest number an gives its value
	HighestScore = Find_Highest(Num1C, Num2C, Num3C, Num4C, Num5C);//uses the
				 //function for finding the highest number an gives its value

	Average = ((Num1C + Num2C + Num3C + Num4C + Num5C) -
		(LowestScore + HighestScore)) / 3; //formula that omits the highest and 
										  //lowest value and calculates average

	return Average;// gives average
}



/*for (Inc = 0; Inc < 35; Inc++)
{
	infile >> Name[Inc] >> Num1 >> Num2 >> Num3 >> Num4 >> Num5;
	Avg[Inc] = Calculate_Score(Num1, Num2, Num3, Num4, Num5);//calls the 
				   //prototype to find average score with omited
	outfile << setw(8) << Name[Inc] << setw(10) << fixed << setprecision(3) <<
		Avg[Inc] << setw(8) << fixed << setprecision(1) << Num1 << setw(6) <<
		Num2 << setw(6) << Num3 << setw(6) << Num4 << setw(6) << Num5 <<
		'\n';// Formats the inside of the table

}*/