#include <stdlib.h>
#include <iostream>
using namespace std;

string chartostring(char *a)
{
	string s(a);
	return s;
}

int main(int argc,char **argv)
{
	string COMMIT_MESSAGE = "git commit -m \"";
	if (argc == 1)
	{
		cout<< "NO COMMIT MESSAGE";
		return 1;
	}

	for(int i = 1;i<argc;i++) 
	{
		COMMIT_MESSAGE+=argv[i];
		if (i != argc -1) COMMIT_MESSAGE+=' ';
	}
	COMMIT_MESSAGE	+= "\"";
	cout<<COMMIT_MESSAGE<<endl;
	system("git add .");
	system(COMMIT_MESSAGE.c_str());
	system("git push");

	return 0;
}