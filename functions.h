#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

using namespace std;

struct Flashcard{
    int number;
    string question;
    string answer;
    int difficulty;
};
//Struct of a Deck with a name for the set and a vector to hold cards
struct Deck{
    string set_name;
    vector<Flashcard> Cards;
};


void welcome_message();

void print_options();

void exit_message();

int card_functions(vector<Deck>&);

Flashcard create_card(Deck&);

void print_deck(Deck&);

void remove_card(vector<Deck>&);

void search_set_name(vector<Deck>&,string,int);

void search_question(vector<Deck>&,string);

void pretty_menu(string);

void help_info();








#endif
