//-----Include required headers here-----
#include <iostream>
using namespace std;
//-----End of headers-----

//-----Don't change/delete structs-----
struct rational {
   int numerator;
   int denominator;
};
//-----Structs end here


/*Question: Reduce the number 'inputrational' to its lowest form and store it in 'outputrational'
struct rational *inputrational  : Actual rational number to be reduced
struct rational *outputrational : Variable to store the rational number in its lowest form */
int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 
void reduce(struct rational *inputrational, struct rational *outputrational) {
    //Write your solution code below this line
	int n;
	n= gcd(inputrational->numerator, inputrational->denominator);
	outputrational->numerator = inputrational->numerator/n;
	outputrational->denominator = inputrational->denominator/n;


}

/* Question: Check whether both the rational numbers obtained in the lowest form are equal or not. 
             Retrun true or false accordingly
*/
bool isEqual(struct rational num1, struct rational num2) {
    //Write your solution code below this line
    rational reducedNum1, reducedNum2;
	reduce(&num1, &reducedNum1);
	reduce(&num2, &reducedNum2);

	if (reducedNum1.numerator == reducedNum2.numerator && reducedNum1.denominator == reducedNum2.denominator)
		return true;
	else
		return false;

}

