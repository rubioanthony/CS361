#include <iostream>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

int main()
{
    //Set to 0 so value is known
    int user_choice = 0;
    int card_choice = 0;
    //temp set for testing card functionality
    Deck test;
    test.set_name = "test";

    //Vector of Decks
    vector<Deck> DeckList;

    DeckList.push_back(test);

    //Print welcome message
    welcome_message();

    //While not 5, do one of these
    while(user_choice != 5){
        print_options();
        cin >> user_choice;

        if (user_choice == 1){
            card_functions(DeckList);

        }
        else if (user_choice == 2){

        }    
        else if (user_choice == 3){

        }    
        else if (user_choice == 4){
            help_info();
        }    
        else if (user_choice == 5){
            exit_message();
            print_deck(DeckList[0]);  
            return 0;
        }
        else{
            cout << "Invalid option please try again" << endl;
            print_options();
        }
    }


}
