#include <iostream>
#include "ContactList.h"
#include "Contact.h"

void printMenu() {
  cout << endl;
  cout << "********************************************" << endl;
  cout << "Main Menu" << endl;
  cout << endl;
  cout << "Enter the letter for the desired menu option:" << endl;
  cout << "   C - Get count" << endl;
  cout << "   L - Load contacts from file" << endl;
  cout << "   S - Search contacts" << endl;
  cout << "   P - Print contacts" << endl;
  cout << "   X - Exit" << endl;
  cout << endl;
}

int main() {
  char input;
  printMenu();
  cin >> input;
  ContactList c;
  while (input != 'X' and input != 'x') {
    if ((input == 'C') || input == 'c') {
      cout << "There are " << c.getCount() << " contacts" << endl;
    } else if ((input == 'L') || input == 'l') {
      string filename;
      cout << "Enter a filename" << endl;
      cin >> filename;
      cout << c.loadContactsFromFile(filename) << endl;
    } else if ((input == 'S') || input == 's') {
      cout << "Enter a search term" << endl;
      string search;
      cin >> search;
      vector<int> searchResult = c.findContactsByName(search);
      if (searchResult.size() > 1) {
        cout << endl << "Found " << searchResult.size() << " results" << endl;
      } else {
        cout << endl << "Found " << searchResult.size() << " result" << endl;
      }
      for (int i = 0; i < searchResult.size(); i++) {
        cout << i + 1 << ". " << c.getContact(searchResult[i])->getName() << endl;
      }
      cout << endl;
      cout << "Enter an option:" << endl;
      cout << "   P - Print contacts" << endl;
      cout << "   or a Contact number to view/edit" << endl;
      cout << "   R - Return to main menu" << endl << endl;

      string subInput;
      cin >> subInput;
      if (subInput == "P"|| subInput == "p") {
        c.printContacts(searchResult);
      } else if (subInput == "R" || subInput == "r") {
        
      } else if (stoi(subInput) > 0 && stoi(subInput) <= searchResult.size()) {
        cout << c.getContact(searchResult[stoi(subInput) - 1])->getAsString() << endl;
        cout << "Enter an option for contact: " << endl;
        cout << "   A - Edit address" << endl;
        cout << "   B - Edit date of birth" << endl;
        cout << "   E - Edit email address" << endl;
        cout << "   N - Edit name" << endl;
        cout << "   P - Edit phone numbers" << endl;
        cout << "   R - Return to main menu" << endl;
        cout << "   D - Delete" << endl;

        char SInput;
        cin >> SInput;
        if (SInput == 'D' || SInput == 'd') {
          cout << endl;
          cout << "Are you sure you want to delete contact " 
               << c.getContact(searchResult[stoi(subInput) - 1])->getName() << "?" << endl;
          cout << "Enter 'Y' to confirm." << endl;
          char del;
          cin >> del;
          if (del == 'Y' || del == 'y') {
            cout << c.deleteContact(searchResult[stoi(subInput) - 1]) << endl;
          }
        } else if (SInput == 'E' || SInput == 'e') {
          cout << endl << "Current email: " << endl;
          cout << c.getContact(searchResult[stoi(subInput) - 1])->getEmail() << endl;
          cout << endl << "Enter new email or C to cancel:" << endl;
          string mailInput;
          cin >> mailInput;
          if (mailInput != "C" && mailInput != "c") {
            cout << endl << "Email updated:" << endl;
            c.getContact(searchResult[stoi(subInput) - 1])->setEmail(mailInput);
            cout << mailInput << endl;
          }
        } else if (SInput == 'P' || SInput == 'p') {
          vector<string> p = c.getContact(searchResult[stoi(subInput) - 1])->getPhoneNumbers();
          if (p.size() > 1)
            cout << "Found " << p.size() << " phone numbers" << endl;
          else
            cout << "Found " << p.size() << " phone number" << endl;
          for (int i = 0; i < p.size(); i++) {
            cout << i + 1 << ". " << p[i] << endl;
          }
          cout << "Enter an option:" << endl;
          cout << "   A - Add a phone number" << endl;
          cout << "   R - Return to main menu" << endl;
          cout << "   or list number to delete" << endl << endl;
          string pChoice;
          cin >> pChoice;
          if (pChoice == "A" || pChoice == "a") {
            cout << "Enter the letter for the phone number type: " << endl;
            cout << "C(ell), W(ork) or H(ome)" << endl;
            char phoneType;
            cin >> phoneType;
            cout << "Enter the phone number:" << endl;
            string phoneNum;
            cin >> phoneNum;
            cout << c.getContact(searchResult[stoi(subInput) - 1])->addPhone(phoneType, phoneNum) 
                   << endl;
          } else if (pChoice == "R") {
            
          } else if (stoi(pChoice) > 0 && stoi(pChoice) <= p.size()) {
            cout << endl << "Are you sure you want to delete phone:  "
                 << p[stoi(pChoice) - 1] << "?" << endl;
            cout << "Enter 'Y' to confirm." << endl;
            char del;
            cin >> del;
            if (del == 'Y' || del == 'y') {
              cout << c.getContact(searchResult[stoi(subInput) - 1])->deletePhone(stoi(pChoice) - 1) 
                   << endl;
            }
          }
        } else if (SInput == 'R' || SInput == 'r') {
          
        }
      }
      cout << endl;
    }
    printMenu();
    cin >> input;
    cout << endl;
  }
}