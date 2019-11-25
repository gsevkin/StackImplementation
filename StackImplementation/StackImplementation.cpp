// StackImplementation.cpp : Defines the entry point for the console application.
//
#include "StackType.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

	std::ifstream myFile;
	myFile.open("names.txt");
	StackType<int> stack1;
	StackType<string> stack2;
	string temp;
	
	for(int i = 0 ; i<15 ; i++)
	{
		myFile>>temp;
		stack1.Push(i);
		stack2.Push(temp);
	}
	for(int i = 0; i<15 ;i++)
	{
		cout<<stack1.RetrieveItem(i)<<endl;
	
	}
	for(int i = 0; i<15 ;i++)
	{
		cout<<stack2.RetrieveItem(i)<<endl;
	
	}
	for(int i = 0; i<10 ;i++)
	{
		stack2.Pop();
	
	}

	for(int i = 0; i<5 ;i++)
	{
		cout<<stack2.RetrieveItem(i)<<endl;
	
	}


	return 0;
}

