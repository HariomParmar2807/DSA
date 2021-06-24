//Application of stringstream
// count of words
// CPP program to count words in a string 
// using stringstream. 
#include <bits/stdc++.h> 
using namespace std; 

int countWords(string str) 
{ 
	// breaking input into word using string stream 
	stringstream s(str); // Used for breaking words 
	string word; // to store individual words 

	int count = 0; 
	while(s>>word) 
	{
		count++;
	}
	return count;
} 

void Remove_space(string str)
{
	stringstream ss;
	ss<<str;
	string temp;
	str ="";
	while(getline(ss,temp,' '))
	{
		str += temp;
	}
	cout<<str;
}
// Driver code 
int main() 
{ 
	string s;getline(cin,s);
	cout<<s;
	cout << " Number of words are: " << countWords(s)<<endl; 
	cout<< "After removing whitespaces\n";
	Remove_space(s);
	return 0; 
} 
