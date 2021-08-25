#include<fstream>
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<sstream>
#include<ostream>

using namespace std;

class Insurance
{
public:
  int deco();
  int inssearch();
  int display();
  int input();
  int cal();

public:
    float claimp=0;
     float ins=0;

};
int Insurance::deco()
{
    cout<<"*********************************************************************************************************"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++ VEHICAL INSURANCE COMPANY .PLC +++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"*********************************************************************************************************"<<endl;


   return 0;
}
 int Insurance::inssearch()
{
    ifstream fin;
	string isearch;
	bool isFound=0;

	fin.open("C:\\Users\\tharu\\Desktop\\CW1\\New folder (6)\\New Text Document.txt");
	if(fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	cout << "\n\n\xDB\xDB\xDB Enter Customer NIC: ";
	cin  >> isearch;

	while(!fin.eof())
	{
		string temp = "";
		getline(fin,temp);
		for(int i=0;i<isearch.size();i++)
		{
			if(temp[i]==isearch[i])
				isFound = 1;
			else
			{
				isFound =0;
				break;
			}
		}

		if(isFound)
		{
			cout << "Customer details:\nNAME            ADDRESS              PHONE NUMBER  Plcy Number  PLCY ISS./EMP.DATE     PLCY TYPE  VEHI.NO\n";

		for(int i = isearch.size()+1;i<temp.size();i++)
				cout << temp[i];

			break;
		}

	}

	if(fin.eof()&&(!isFound))
	{
		cout << "*****************UNREGISTERED CUSTOMER!*******************\n";
	}
	return isFound;

}
int Insurance::display()
{

ifstream foin;
	foin.open("C:\\Users\\tharu\\Desktop\\CW1\\New folder (6)\\New Text Document (2).txt");
	if(foin.fail())
	{
		cout << "\nInput file opening failed."<<endl;
		exit(1);
	}
	string osearch;
	cout << "\n\n\xDB\xDB\xDB Enter Vehicle Number: ";
	cin  >> osearch;
	bool didFound=0;
	while(!foin.eof())
	{
		string temp = "";
		getline(foin,temp);
		for(int p=0;p<osearch.size();p++)
		{
			if(temp[p]==osearch[p])
				didFound = 1;
			else
			{
				didFound =0;
				break;
			}
		}

		if(didFound)
		{
			cout << "\nVehicle Details :\n   VEHI.BRAND    VEHI.MODEL   YEAR    CLAIM.NO    INS.AMOUNT\n ";
			for(int p = osearch.size()+1;p<temp.size();p++)
				cout << temp[p];

			break;
		}

	}

	if(foin.eof()&&(!didFound))
	{
		cout << "\n*******************Vehicle Number not FOUND!*******************\n";
	}

	return 0;
}
int Insurance::input()
{

    cout<<"\n\n\xDB\xDB\xDB Enter Claim Price: "<<endl;
    cin>>claimp;
    cout<<"\n\n\xDB\xDB\xDB Enter Insurance Price: "<<endl;
    cin>>ins;
    return 0;

}
int Insurance::cal()
{

  float tot=0;

    if(claimp>ins)
    {
        cout<<"\n*******************Can't Claim*******************"<<endl;
        exit(1);
    }
    else
        {
            tot=ins-claimp;
            cout<<"\n*******************Remaining Amount:RS."<<tot<<endl;
            exit(1);
        }

}

int main()
{

	Insurance ins1;
	ins1.deco();
	ins1.inssearch();
	ins1.display();
    ins1.input();
	ins1.cal();


	cout<<ins1.deco()<<ins1.inssearch()<<endl<<ins1.display()<<endl<<ins1.input()<<endl<<ins1.cal()<<endl;

	return 0;
}

