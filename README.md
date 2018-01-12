# C-Phonebook
Author: Adam Carling

Description: This is a Phonebook programm that was created through coderunner. It allows you to enter names, edit names, and search names already entered. It works inside coerunner and will not run as a sepreate program. 

do {
			cout << endl;
			
			cout << "1. Search phone book" << endl;
			
			cout << "2. Add contact" << endl;
			
			cout << "3. Edit contact" << endl;
			
			cout << "4. End the program" << endl;
			
			cout << "Enter menu option by typing a number then hitting enter: ";
			
			cin >> menuOptions;
			
			cin.ignore(100, '\n');
			
			cout << endl;
			if (menuOptions == 1){
				search();
			} else if(menuOptions == 2) {
				addName();
			} else if (menuOptions == 3){
				editSomething();
			}//end if else
		} while (menuOptions != 4);

When you run the code on coderunner, it displays a menu of 4 options. These options are, search the phonebook, add names, edit names, and end program. Search phonebook will give you another menu with 4 more options. Display all, display names, search, and end search. Display all displays the entire phone book. Display names only shows the names, and search allows the user to make a case sensitive search. 
  The add names function will run a code that prompts the user to enter a name, number, and address. It then stores the info and returns to the main menu. 
   The edit names function, displays lines of info that the user can edit by selecting the coresponding list number. The program then displays the exact info, such as name or number, that the user wishes to change. It then prompts the user and then returns to the main menu. 

Download: There are two files that you will need to downlaod. The first is "phonebook.cpp." This file contains the actual code for the project. The second is the "phone.txt." This file is where the addresses, names, and numbers will be stored. Make sure to download both and keep them in the same directory. Once installed, use a compiler to run the program and follow the steps it gives you to use the program. 

Inspiration for this project came from the need for a final project for a class. We were told to come up with a project non-game related. So I settled on this idea. All in all it turned out decent. 

