#include <bits/stdc++.h>
using namespace std;

static int ans[2] = {0,0};

int strcmp(char *str1,char *str2)
{
    if (strlen(str1)!=strlen(str2)) return 0;

    for(int i = 0;i<strlen(str1);i++) if(str1[i] != str2[i])return 0;

    return 1;
}

int get_dot(char *str)
{
	for (int i = strlen(str)-1; i>=0 ; i-- ) if (str[i] == '.') return i;
	return -1;
}


int checker(int argc, char **argv)
{
	int limit = get_dot(argv[argc]); // Get the position of the '.' from the back

	if (limit == -1) return 0;	// If no '.' is detected return false

	char *arr = &argv[argc][limit];	// Get the char[] after the '.'

	int size = strlen(argv[argc]); // size of the whole filename
	cout<<"SIZE : "<<size<<endl;

	// For comparison

	char cpp[] = ".cpp"; 
	char c[] = ".c";

	if (size>4) // size of .cpp is 4
	{
		cout<<"Checking for .cpp"<<endl;
		if (strcmp(arr,cpp))
		{
			cout<<".cpp recognized"<<endl;
			ans[0] = 0;
			ans[1] = limit;
			return 1;
		}
	}
	if (size>2) // size of .c is 2
	{		
		cout<<"Checking for .c"<<endl;
		if (strcmp(arr,c))
		{
			cout<<".c recognized"<<endl;
			ans[0] = 1;
			ans[1] = limit;
			return 1;
		}
		
	}
	return 0;
}

int main(int argc, char **argv)
{
	// If arguments given are only 2

	if (argc == 2)
	{
		if (checker(argc-1,argv)) // Checking for the extension file format .c or .cpp
		{
			
			cout<<"ANSWER : "<<ans[0]<<" "<<ans[1]<<endl; // Status codes - is C file and the index of the '.' in the filename
			
			string filename = argv[argc-1]; // Get the filename
			
			string savename = ""; // Initialize string for savename

			for (int i = 0; i<ans[1];i++)savename+=argv[argc-1][i];	// Getting the savename

			cout<<"FILENAME : "<<filename<<" SAVENAME : "<<savename<<endl; // Displaying the filename and savename
			
			// Compiler to be used

			string cpp = "g++ ";
			string c = "gcc ";
			
			// String that will be finally input in the system command

			string input;
			
			// Generating the command with proper compiler, filename and savename

			if (ans[0]) input = c + filename + " -o " + savename;
			else input = cpp + filename + " -o " + savename;
			
			cout<<input<<endl; // The final command to be input into the system command

			system(input.c_str()); // Executing the system command ( Converting the string into const char* - default input data format for system)

			string execute = savename + ".exe";
			system("cls");
			system(input.c_str());
		}
		else
		{
			cout<<"Wrong Format\n Format should be .c or .cpp"<<endl; // Wrong format of file given
		}
	}
	
	return 0;
}