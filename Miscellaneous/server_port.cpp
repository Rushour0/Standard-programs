#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	int port = 8888;
	char ch;
	string command = "python -m http.server ";
	switch(argc)
	{
		case 1:
		cout << "NO PORT NUMBER GIVEN\nStart site on port : 8888? (y/n) : ";
		cin >> ch;
		if (tolower(ch) == 'y') command += "8888";
		else if (tolower(ch) == 'n') exit(1);
		else cout << "Incorrect choice\nExiting...\n";
		break;

		case 2:
		
		try
		{
			port = stoi(argv[1]);
			if (to_string(port) != argv[1]) throw 1;
			command += argv[1];
		}
		catch (...)
		{
			cout << "Put in a correct port number\n";
			exit(1);
		}
		cout << "Starting localhost server at port number " << argv[1] << endl;

		break;

		default:
		cout << "WRONG FORMAT\nFormat : server_port 0000\n";
		exit(1);
		break;
	}

	system(command.c_str());
	system("exit");

	return 0;
}