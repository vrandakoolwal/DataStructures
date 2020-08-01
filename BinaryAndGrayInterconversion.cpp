#include <iostream>
#include<string>
using namespace std;
//-----End of headers-----


//-----Add new functions here(if any)-----

//-----New functions end here-----

/* Question : Function to convert a given binary string to 
gray code string as explained in the problem description. */
string binarytoGray(string binary) {
    // Write your code below this line.
    string gray = binary;
    gray.at(0) = binary.at(0);
    for (int i=1; i<binary.length(); i++)
    {
        if (binary.at(i) == binary.at(i-1))
            gray.at(i) = '0';
        else
            gray.at(i) = '1';
    }
    return gray;
}
 
/* Question : Function to convert a gray code string to 
binary string as explained in the problem description. */
string graytoBinary(string gray) {
    // Write your code below this line.
    string binary = gray;
    binary.at(0) = gray.at(0);
    for (int i=1; i<gray.length(); i++)
    {
    	if (gray.at(i) == '0')
    		binary.at(i) = binary.at(i-1);
    	else
    	{
    		if (binary.at(i-1) == '1')
    			binary.at(i) = '0'
    		else
    			binary.at(i) = '1';
    	}
    }
    return binary;
}