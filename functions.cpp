#include "functions.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void welcome_message()
{
    cout << "\n\033[1;32m=========================================\033[0m" << endl;
    cout << "\033[1m Welcome to the Flashcard Game! \033[0m" << endl;
    cout << "  This game helps you study for exams,\n";
    cout << "  quizzes, or anything else you'd like to learn!" << endl;
    cout << "\033[1;32m=========================================\033[0m\n" << endl;
}   

void print_options()
{
    cout << "\n\033[1;36m======================\033[0m" << endl;
    cout << "\033[1;36m|| \033[0m     \033[1mMain Menu\033[0m     \033[1;36m||\033[0m" << endl;
    cout << "\033[1;36m======================\033[0m" << endl;
    cout << "\033[1;33m1.\033[0m Card Functions" << endl;
    cout << "\033[1;33m2.\033[0m Start Quiz" << endl;
    cout << "\033[1;33m3.\033[0m Set Functions" << endl;
    cout << "\033[1;33m4.\033[0m Help / Info" << endl;
    cout << "\033[1;33m5.\033[0m Exit" << endl;
    cout << "\033[1;36m======================\033[0m" << endl;
    cout << "Enter your choice: ";
}
//Prints out an exit message
void exit_message()
{
    cout << "\n\033[1;31mThanks for playing!\033[0m" << endl;
}
//Function 
int card_functions(vector<Deck>& List)
{
    int user_choice;
    string set_name;
    //Card function option screen
    cout << "\n\033[1;36m======================\033[0m" << endl;
    cout << "\033[1;36m|| \033[0m  \033[1mCard functions\033[0m  \033[1;36m||\033[0m" << endl;
    cout << "\033[1;36m======================\033[0m" << endl;
    cout << "\033[1;33m1.\033[0m Add a card" << endl;
    cout << "\033[1;33m2.\033[0m Remove a card" << endl;
    cout << "\033[1;33m3.\033[0m Edit a card" << endl;
    cout << "\033[1;33m4.\033[0m Exit to main screen" << endl;
    cout << "Enter your choice: ";
    //Take in user data
    cin >> user_choice;
    if (user_choice == 1)
    {
        pretty_menu("   Add card   ");
        cout << "\nEnter set name:";
        cin >> set_name;

        for (int i = 0; i < List.size();i++)
        {
            if (List[i].set_name == set_name)
            {
            Flashcard newcard = create_card(List[i]);
            List[i].Cards.push_back(newcard);
            cout << "New card added to deck" << endl;
            return user_choice;
            }
        }
        return user_choice;
    }
    else if(user_choice == 2)
    {
        pretty_menu(" Remove card ");
        cout << "\n\033[1;31mWarning! Removing cards is permanent and will need to be manually entered again.\n\033[0m" << endl;
        remove_card(List);
        return user_choice;

    }
    else if(user_choice == 3)
    {
        //Edit card
        return user_choice;
    }
    else if(user_choice == 4)
    {
        return 0;
    }
    else
    {
        cout << "Invalid number" << endl;
        return user_choice;
    }

    
}
//Returns a flashcard that the user has created
Flashcard create_card(Deck& D)
{
    //Generate flashcard instance
    Flashcard a;

    //Enter and read in question
    cout << "Enter question:";
    cin.ignore();
    getline(cin,a.question);
    //Enter and read in answer
    cout << "Enter answer:";
    getline(cin,a.answer);    
    //Enter difficulty
    cout << "Enter difficulty from 1-5:";
    cin >> a.difficulty;

    a.number = D.Cards.size() + 1;

    return a;
}

void print_deck(Deck& d)
{
    for (int i = 0; i < d.Cards.size(); i++){
        cout << "Card " << d.Cards[i].number << " information;" << endl;
        cout << "Question:" << d.Cards[i].question << endl;
        cout << "Answer:" <<  d.Cards[i].answer << endl;
        cout << "Difficulty:" << d.Cards[i].difficulty << endl; 
    }
}

void remove_card(vector<Deck>& d)
{
    int choice,card_num;
    string set_name,question;
    cout << "\033[1;33m1.\033[0mEnter question you want to delete\nor " << endl;
    cout << "\033[1;33m2.\033[0mEnter a set name and the number of the card you want to remove" << endl;
    cout << "\033[1;33m3.\033[0mExit to welcome page" << endl;

    cin >>choice;

    if (choice == 1)
    {
        cout << "Question: ";
        cin.ignore();
        getline(cin,question);
        search_question(d,question);
    }
    else if (choice == 2)
    {
        //Ask for and read in data
        cout << "Set name: " << endl;
        cin >> set_name;
        cout << "Card number: " << endl;
        cin >> card_num;
        //call search function
        search_set_name(d,set_name,card_num);
    }
    else
    {
        return;
    }
}

void search_set_name(vector<Deck>& d, string name, int number)
{
    bool valid = false;

    //Iterates through the vector looking for a card that matches set name and number then remove
    for (int i = 0; i < d.size(); i++)
    {
        
        if (d[i].set_name == name)
        {  
            for (int j = 0; j < d[i].Cards.size(); j++)
            {
                if (d[i].Cards[j].number == number)
                {
                    d[i].Cards.erase(d[i].Cards.begin() + j);
                    cout << "Card removed successfully" << endl;
                    valid = true;
                    break;
                }
            }
            
        }
    }

    if (valid == false)
    {
        cout << "Card not found" << endl;
    }

}

void search_question(vector<Deck>& d,string question)
{
    //Flag to check if a card was removed or not
    bool valid = false;

    for (int i = 0; i < d.size(); i++)
    {
        for (int j = 0; j < d[i].Cards.size();j++)
        {
            if(d[i].Cards[j].question == question)
            {
                d[i].Cards.erase(d[i].Cards.begin() + j);
                cout << "Card removed successfully" << endl;
                valid = true;
                return;  
            }
        }
    }

    if (!valid)
    {
        cout << "Card not found" << endl;
    }
}

void pretty_menu(string title)
{
    cout << "\n\033[1;36m======================\033[0m" << endl;
    cout << "\033[1;36m|| \033[0m  \033[1m" << title << "\033[0m  \033[1;36m||\033[0m" << endl;
    cout << "\033[1;36m======================\033[0m" << endl;
}

void help_info()
{  
    cout << "\n\033[1;33m======================================\033[0m\n";
    cout << "\033[1;33m||      \033[0m\033[1mHelp Menu - Instructions\033[0m     \033[1;33m||\033[0m\n";
    cout << "\033[1;33m======================================\033[0m\n\n";

    cout << "\033[1m1.\033[0m Add, remove or edit cards from a specified set of flashcards.\n";
    cout << "\033[1m2.\033[0m Start a quiz to test your knowledge with your inputted flashcards.\n";
    cout << "\033[1m3.\033[0m Add or remove sets from the database.\n";

    cout << "\n\033[1;36mReturning to the main menu...\033[0m\n";
}
