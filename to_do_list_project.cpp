#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
using namespace std;

// This is my project for sprint 1 in my CSE 310 - Applied programming class
// it's purpose to allow this user to create a list of tasks that can then be 
// altered later to allow the user to delete items that the user has completed

class UserVariables {
    // Creating my variables that will be called through out the entire program
    public:
        bool back_to_menu = true;
        vector<string> users_to_do_list;
        string users_name;
        string add_task;
        string stop_showing;
        string remove_task;
        int nav_number;
        int remove_task_counter;
        int remove_task_display_counter;
        int task_counter;

};

// Create a function to test if its a int
bool isNumber(const string& str) {
        return !str.empty() && all_of(str.begin(), str.end(), [](char c) {
            return isdigit(static_cast<unsigned char>(c));
        });
    }

// Create the "Main" function of my program 
void myUI() {
    // Call my class
    UserVariables UsersVaribles;

    // Display welcome message to the user
    cout << "\nHello, Welcome to \"Task-Master\" Andrew's To Do List Program\n";
    cout << "To start, what is your name?\n\n";
    getline(cin, UsersVaribles.users_name);
    cout << "\nWelcome " << UsersVaribles.users_name;
    
    while (UsersVaribles.nav_number != 4) {
        // Display the "Main Menu"
        cout << "\n\nWhat would you like to do?";
        cout << "\n1. Add item(s) to your \"To-Do-List\"\n2. Remove an item(s) from your \"To-Do-List\"";
        cout << "\n3. Show what is on your \"To-Do-List\"\n4. Exit \"Task-Master\" \n\n";
        // Request int input from the user
        cin >> UsersVaribles.nav_number;
        
        // Logic for adding tasks to the To-Do-List
        if (UsersVaribles.nav_number == 1) {
            // Display message to user
            cout << "\nWhat would you like to add to your \"To-Do-List\"? (type \"done\" when you are done adding items.)\n\n";
            // Reset Boolean Varible
            UsersVaribles.back_to_menu = true;
            // Add tasks to the list until user enters "done", not case sensitive
            while (UsersVaribles.back_to_menu) {
                // Request string input from user
                getline(cin, UsersVaribles.add_task);
                // Turns whatever the user enters into all lower case
                transform(UsersVaribles.add_task.begin(), UsersVaribles.add_task.end(), UsersVaribles.add_task.begin(), [](unsigned char c) {return tolower(c); });
                // Logic to decide whether to add task to the list, or not
                if (UsersVaribles.add_task != "done" && UsersVaribles.add_task != "reset" && UsersVaribles.add_task != "") {
                    UsersVaribles.users_to_do_list.push_back(UsersVaribles.add_task);
                } else if (UsersVaribles.add_task == "done") {
                    cout << "\nYou have finished adding items to your \"To-Do-List\" I will take you back to the menu now.";
                    // Stop while loop
                    UsersVaribles.back_to_menu = false;
                } else if (UsersVaribles.add_task == "") {
                     // This is here to keep the programm from adding a blank item into the list.
                } else {
                    cout << "Please enter a valid input";
                }
            }
        } 
        
        // Logic for removing tasks from the To-Do-List
        else if (UsersVaribles.nav_number == 2) {
            // Reset Boolean Varible
            UsersVaribles.back_to_menu = true;

            while (UsersVaribles.back_to_menu) {
                UsersVaribles.remove_task_counter = 1;     
                cout << "\nWhich item would you like to remove? (type the number in front of the task or \"done\" when finished)\n";
                    
                // Display what is in the list
                for (string task : UsersVaribles.users_to_do_list) {
                    cout << UsersVaribles.remove_task_counter << ". " << task <<"\n";
                    UsersVaribles.remove_task_counter += 1;
                }
                
                if (UsersVaribles.remove_task == "") {
                    cout << "\n";
                    cin.ignore();
                    getline (cin, UsersVaribles.remove_task); 
                } else {
                    getline (cin, UsersVaribles.remove_task);
                }
   
                // Set variable to lower case
                transform(UsersVaribles.remove_task.begin(), UsersVaribles.remove_task.end(), UsersVaribles.remove_task.begin(), [](unsigned char c) {return tolower(c); });
                   
                // Remove task from list, and tell user which one was removed
                if (isNumber(UsersVaribles.remove_task)) {
                    int remove_task_number = stoi(UsersVaribles.remove_task);
                        
                    if (remove_task_number >= 1 && remove_task_number <= UsersVaribles.users_to_do_list.size()) {
                        
                        cout << "\nYou have removed \"" << UsersVaribles.users_to_do_list[remove_task_number - 1] << "\".\n";
                        UsersVaribles.users_to_do_list.erase(UsersVaribles.users_to_do_list.begin() + remove_task_number - 1);

                    } else {
                        cout << "Please enter a valid option\n";
                    }
                } 
                // Display message to the user
                else if (UsersVaribles.remove_task == "done") {
                    cout << "\nAll the tasks you have asked to be removed have been removed. \nI will now take you back to the main menu.\n";
                    // Stop while loop
                    UsersVaribles.back_to_menu = false;
                } else {
                    cout << "\nPlease enter a vaild option\n";
                }   
            }
        } 
        
        // Show the user everything in his To-Do-List
        else if (UsersVaribles.nav_number == 3) {
            UsersVaribles.back_to_menu = true;
            cout << "\nWhen you would like to go back to the \"Main Menu\" type (\"done\")";
            while (UsersVaribles.back_to_menu) {
                getline (cin, UsersVaribles.stop_showing);
                transform(UsersVaribles.stop_showing.begin(), UsersVaribles.stop_showing.end(), UsersVaribles.stop_showing.begin(), [](unsigned char c) {return tolower(c); });
                UsersVaribles.task_counter = 1;
                cout << "\nThe tasks in your \"To-Do-List\" are:\n";
                // Iterates every task in the To-Do-List
                for (string task : UsersVaribles.users_to_do_list) {
                    cout << UsersVaribles.task_counter << ". " << task << "\n";
                    UsersVaribles.task_counter += 1;                    
                }
                if (UsersVaribles.stop_showing == "done") {
                    // Stop while loop
                    UsersVaribles.back_to_menu = false;
                }
                cout << "\n";
            }
        } 
        
        // Display a goodbye message to the user
        else if (UsersVaribles.nav_number == 4) {
            cout << "\nThanks for using Task-Master! Goodbye!\n";
        } else {
            cout << "\nPlease enter a valid option. (1, 2, 3, or 4)\n";
        }
    }
}

int main() {
    myUI(); // Call my function
    return 0;
}