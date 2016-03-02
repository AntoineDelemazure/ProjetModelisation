#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Exception
{
public:
	Exception(const string s, const bool b){
		cout << s << "\n";
		if (!b){
			cout << "Le programme va maintenant cesser de s'executer" << endl;
			system("pause");
			exit(0);
		}
	};
	virtual ~Exception(){};


private:

};
