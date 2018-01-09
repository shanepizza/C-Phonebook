#include <iostream>
#include <fstream>
#include <string>


void search();
void addName();
void editSomething();


using namespace std;
int main(int argc, char *argv[]) {
	
	int menuOptions = 0;
		
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

		return 0;

	
}// end main


//*******************************************************************
void search(){
	
//declaring variables 
	int length = 0;
	int search1 = 0;
	int search2 = 0;
	int search3 = 0;
	int menuOptions = 0;
	string line = " ";
	string search = " ";
	string name = " ";
	string address = " ";
	string number = " ";

	ifstream inPhone;
	
		// while menu option is not 4
			do {
				cout << endl;
				cout << "1. Display all" << endl;
				cout << "2. Display Names" << endl;
				cout << "3. Search the Directory" << endl;
				cout << "4. End Search" << endl;
				cout << "Enter menu option: ";
				cin >> menuOptions;
				cin.ignore(100, '\n');
				cout << endl;
			//menu option 1: displays all the info
				if (menuOptions == 1){

					inPhone.open("phone.txt", ios::in);
					if (inPhone.is_open()){					

					// gets the info for one line and displays it
						do {
							getline(inPhone, name, '#');
							getline(inPhone, number, '#');
							getline(inPhone, address, '\n');
							length = name.length();
							if (length != 0){
								cout << name << '\t';
								if (length <= 7){ 
									cout << '\t';
									
								}// end if extra tab
								cout << number << '\t' << address << endl;
							}// end if
						} while (inPhone.eof() == false);
					// displays end of list note
						cout <<'\t' << '\t' << "*End of List*" << endl;
						inPhone.close();
					} else {
						cout << "File failed to open.";
					}//end if
			//end option 1
				
				//Option 2: displays only names
				} else if(menuOptions == 2) {
					inPhone.open("phone.txt", ios::in);
					if (inPhone.is_open()){
						//gets name and displays it
						do {
							getline(inPhone, line, '#');
							inPhone.ignore(100, '\n');
							cout << line << endl;
						} while (inPhone.eof() == false);
						inPhone.close();
					} else {
						cout << "File for names failed to open";
					}
			//end option 2
			
			//option 3: searches for name 
				} else if (menuOptions == 3){
						inPhone.open("phone.txt", ios::in);
						if (inPhone.is_open()){					
							cout << "Enter the Name, Address, or Number you are looking for(-1 to cancel): ";
							getline(cin, search);
							if (search != "-1"){
								do {
								
								//gets name, number, and address to compare with search request
									getline(inPhone, name, '#');
									getline(inPhone, number, '#');
									getline(inPhone, address, '\n');
									search1 = name.find(search, 0);
									search2 = number.find(search, 0);
									search3 = address.find(search, 0);
									
								// campers the results
									if (search1 != -1){
										cout << name << '\t' << number << '\t' << address << endl;								    
									} else if (search2 != -1){
										cout << number << '\t' << name << '\t' << address << endl;
									} else if (search3 != -1){
										cout << address << '\t' << name << '\t' << number << endl;
									}// end if else					
								
								} while (inPhone.eof() == false);
								cout << endl << endl;
							}//end search if
						} else {
							cout << "File for search failed to open";
						}//end if file is open	
						inPhone.close();
			//end option 3					
				}//end if else
			} while (menuOptions != 4);
}// end search function 


//**************************************************************
void addName(){

//declaring variables 
	string fullName = " ";
	string pNumber = " ";
	string address = " ";
	ofstream outPhone;
	outPhone.open("phone.txt", ios::app);
		
// entering info 
	if (outPhone.is_open()){
		cout << "Enter Name (-1 to cancel): ";
		getline(cin, fullName);
		if (fullName != "-1"){
			cout << "Enter their phone number(-1 to cancel): ";
			getline(cin, pNumber);
			if (pNumber != "-1"){
				cout << "Enter Address(N/A to ignore): ";
				getline(cin, address);
				if (address != "-1"){
					outPhone << fullName << '#' << pNumber << '#' << address << endl;
				}// end if
			}//end pNumber cancel if
		}//end full name cancel if
		outPhone.close();
	} else { 
		cout << "File failed to open." << endl;
	}//end if else
	

}//end void addName function 


//*************************************************************
void editSomething(){

//declaring variables 
	int secondCounter = 0;
	int counter = 0;
	int location = 0;
	int length = 0;	
	
	string nameEdit = " ";
	string numberEdit = " ";
	string addressEdit = " ";
	
	string tempEdit = " ";
	string line = " ";
	string temp[1000] = {" "};
	
	ifstream inPhone;
	ofstream outPhone;
	
	// assigns all info in the "phone.txt to the line variable 
	inPhone.open("phone.txt", ios::in);
	if (inPhone.is_open()){
		getline(inPhone, tempEdit);
		line = tempEdit;		
		do {
			getline(inPhone, tempEdit);
			line = line + '\n' + tempEdit;
		} while (inPhone.eof() == false);
		inPhone.close();
	}// end if is open
	
// gets all the info and assigns each line to a seperate array position 
	inPhone.open("phone.txt", ios::in);
	if (inPhone.is_open()){
		do {
			getline(inPhone, temp[counter]);
			counter += 1;
			} while (inPhone.eof() == false);
		inPhone.close();
		counter = 0;
	}else {
		cout << "File failed to Open" << endl; 
	}//end if is open
	
// displays the info that can be edited.
	inPhone.open("phone.txt", ios::in);
		if (inPhone.is_open()){
			do {
				getline(inPhone, nameEdit, '#');
				getline(inPhone, numberEdit, '#');
				getline(inPhone, addressEdit, '\n');
				counter +=1;
				length = nameEdit.length();
				if (length != 0){
					cout << counter << ". " << nameEdit << '\t' << '\t' << numberEdit << '\t' << addressEdit << endl;	
					}// end if extra tab
				} while (inPhone.eof() == false);
			inPhone.close();
		}else {
			cout << "File failed to Open" << endl; 
		}//end if is open	
	
//asks the user to choose the line they want to edit
	cout << endl;
	cout << "Enter the corresponding number for the name/number" << endl << "you would like to change:";
	cin >> counter;
	cout << endl;
	
// takes the line that needs to be edited and puts it in a folder for reading
	outPhone.open("phone.txt", ios::out);
	if (outPhone.is_open()){
		outPhone << temp[counter -1];
		outPhone.close();
	} else {
		cout << "Fille failed to open" << endl;
	}// end if
	
// reads and displays the name, number, and addres of the chosen line
	inPhone.open("phone.txt", ios::in);
	if (inPhone.is_open()){
		getline(inPhone, nameEdit, '#');
		getline(inPhone, numberEdit, '#');
		getline(inPhone, addressEdit, '\n');
		inPhone.close();
	} else {
		cout << "File failed to open" << endl;
	}// end if
		
// ask what they need fixed	
	cout << "1." << nameEdit << endl;
	cout << "2." << numberEdit << endl;		
	cout << "3." << addressEdit << endl;		
	cout << endl << " line needs to be fixed?(any other number to cancel): ";
	cin >> secondCounter;
		
// getting the new whatever needs to be fixed
	if (secondCounter == 1){
		cout << "What is the new Name? ";
		cin.ignore(100, '\n');
		getline(cin, nameEdit);
	} else if (secondCounter == 2){
		cout << "What is the new Number? ";
		cin.ignore(100, '\n');
		getline(cin, numberEdit);
	}else if (secondCounter == 3){
		cout << "What is the new Address? ";
		cin.ignore(100, '\n');
		getline(cin, addressEdit);
	}// end if
		
// replacing the line with the edit so it can go back into the file
	tempEdit = nameEdit + "#" + numberEdit + "#" + addressEdit + '\n';
	location = line.find(temp[counter -1], 0);
	length = temp[counter -1].length();
	line.replace(location, length, tempEdit);			
		
//putting it all back in the file
	outPhone.open("phone.txt", ios::out);
	if (outPhone.is_open()){
		outPhone << line;
		outPhone.close();
	} else {
		cout << "File failed to open." << endl;
	} //end if file is open
}// end of edit




