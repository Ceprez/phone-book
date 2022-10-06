#include <iostream>
#include <fstream>

void addContacts();
void readContacts();
void showContacts();

void menu(){

    int userInput;

    std::cout << "=====================" << std::endl;
    std::cout << "======PHONEBOOK======" << std::endl;
    std::cout << "=====================" << std::endl;

    std::cout << "1. Find Contact" << std::endl;
    std::cout << "2. Add Contact" << std::endl;
    std::cout << "3. Show Contacts" << std::endl;
    std::cout << "4. Exit" << std::endl;

    std::cout << "Your Choice: ";
    std::cin >> userInput;

    switch (userInput) {

        case 1: {
            readContacts();
            break;
        }

        case 2: {
            addContacts();
            break;
        }

        case 3: {
            showContacts();
            break;
        }

        case 4: {
            exit(0);
        }

        default: {
            std::cout << std::endl;
            std::cout << "Enter number 1-4!" << std::endl;
            std::cout << std::endl;
            menu();
        }

    }


}


void addContacts(){

    std::string name;
    int number;

    std::cout << "Create a name for a contact: ";
    std::cin >> name;
    std::cout << "Enter a phone number: ";
    std::cin >> number;

    std::ofstream openFile;

    openFile.open("contacts.txt", std::ios::app);

    openFile << std::endl << name << ' ' << number;

    openFile.close();

    menu();

}


void readContacts(){

    std::string name, checkName;
    int check = 0, checkNumber;

    std::cout << "Enter name of a contact: ";
    std::cin >> name;

    std::ifstream readFile;

    readFile.open("contacts.txt");

    while(!readFile.eof()){

        readFile >> checkName >> checkNumber;

        if(name == checkName){
            std::cout << std::endl;
            std::cout << "Number: " << checkNumber << std::endl;
            std::cout << std::endl;
            check = 1;
            break;
        }

    }
    readFile.close();
    if (check != 1){
        std::cout << std::endl;
        std::cout << "No contact found with this name!" << std::endl;
        std::cout << std::endl;
    }

    menu();

}

void showContacts(){

    std::string name;
    int number;

    std::ifstream readFile;

    readFile.open("contacts.txt");

    std::cout << std::endl;

    while(!readFile.eof()){

        readFile >> name >> number;

        std::cout << "Name: " << name << " Number: " << number << std::endl;

    }

    readFile.close();

    std::cout << std::endl;

    menu();
}