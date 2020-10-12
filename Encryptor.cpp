#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class securefolder 
{
	public:
		void lock();
		void unlock();
};

void securefolder :: lock()
{
 char pass[15]="";
 ofstream lfolder;
 char folder[200]={0}; 
 char tempfolder[200]={'0'};
 char attributes[50]={'0'};
 
 system("COLOR 57");
 cout << "\n\t\t>>LOCK Folder: \n\n";
 cout << "\n\t Enter the complete path to the Folder: ";
 cin >> folder;

 strcpy(tempfolder, folder);

 strcat(folder, "\\Desktop.ini");
 
 lfolder.open(folder, ios::out);
 
 lfolder << "[.shellClassInfo]" << endl;
 lfolder << "CLSID = {63E23168-BFF7-4E87-A246-EF024425E4EC}" << endl;

 lfolder.close();

 strcpy(attributes, "attrib +h +s ");
 strcat(attributes, tempfolder);
 
 WinExec(attributes, NULL); 
 
 lfolder.open("C:\\windows\\db.dat", ios::app);
 lfolder << "\tFolder Locked: " << tempfolder << endl;
 lfolder.close();
 
 cout << "\n\n" << tempfolder << " has been locked successfully!\n";
}

void securefolder :: unlock()
{
 char folder[255]; 
 char tempfolder[255];
 char attributes[50];
 char del[50];
 ofstream lfolder;
 
 system("COLOR 27");
 cout << "\n\t\t >>UNLOCK Folder: \n\n";
 cout << "\n\t Enter the complete path to the Folder: ";
 cin >> folder;

 strcpy(tempfolder, folder);

 strcat(folder, "\\Desktop.ini");

 strcpy(del, "del ");
 strcat(del, folder);
 system(del);

 strcpy(attributes, "attrib -h -s ");
 strcat(attributes, tempfolder);
 
 WinExec(attributes, NULL);

 lfolder.open("C:\\windows\\db.dat", ios::app);
 lfolder << "\t! Folder Unlocked: " << tempfolder << endl;
 lfolder.close();

 cout << "\n\n" << tempfolder << " has been unlocked successfully!\n";
 }

int main()

{
	securefolder secure;
	
	char option;
	do
	{
		system("CLS");
		system("COLOR 4f");
		cout << "\n\n\n\n\t\t\t\t" << " Object Oriented Programming : SECURE FOLDER \n";
		cout << "\n\n" << "\t Options:\t\t\t\n";
		cout << "\t ======================\n";
		cout << "\t 1. >> Lock Folder. \n";
		cout << "\t 2. >> Unlock Folder. \n";
		cout << "\t 3. >> Credits. \n";
		cout << "\t 4. >> Exit. \n";
		cout << "\t ======================  \n";
		cout << "\n\t Enter your choice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
			case 1: 
			{
				system("CLS");
				secure.lock();
				break;
			}
			case 2: 
			{
				system("CLS");
				secure.unlock();
				break;
			}
			case 3: 
			{
				system("CLS");
				system("COLOR 10");
				cout<<"\n\n\t\t\t\t OBJECT ORIENTED PROGRAMMING PROJECT\n";
				cout<<"\n\n\t\t\t\t 		SECURE FOLDER \n";
				cout<<"\t Submitted to:\n\t MR. SARABJEET SINGH";
				cout<<"\n\n\t Submitted by:\n\t Vasu Garg\n\t CO18358\n\t CSE 1st Year";;
				break;
			}
			case 4: 
			{
				exit(0);
				break;
			} 
			default:
			{
				cout << "\n\t\t\tYour input is Invalid! \n\t\t\tPlease Select a Valid Option";
				break;
			}
		}
		
		cout<<"\n\n\t Press any key to Continue:\n\t";
		cin>>option;
		
		if(option == 'y' || 'Y')
			option = 'y';
		else if(option == 'n' || 'N' )
			exit(0);
		else
			cout<<"\n\n\t Enter Valid Option!";
	}while(option=='y');
 	return 0;
}
