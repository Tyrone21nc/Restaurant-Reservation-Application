#include "Restaurant.cpp"


bool inputIsDigit(string choice){
    for(int i=0; i<signed(choice.size()); i++){
        if(!isdigit(choice[i])){
            return false;
        }
    }
    return true;
}
string loopChoice(){
    string choice;
    do{
        cout << "Options [1-5]:" << endl;
        cout << "\033[33mEnter one of these values:\033[0m\n>>> ";
        cin >> choice;
    }while(!inputIsDigit(choice) || (stoi(choice) <= 0 || stoi(choice) > 5));
    return choice;
}

void run(){
    cout << "Welcome to La Cassa Blanca Tortas." << endl;
    Restaurant rest = Restaurant(21);
    string choice;
    int choiceInt = 0;
    do{
        cout << "Options [1-5]:" << endl;
        cout << "1. View Reservations" << endl;
        cout << "2. Make a Reservation" << endl;
        cout << "3. Claim your reserved table" << endl;
        cout << "4. View a specific queue" << endl;
        cout << "5. Quit" << endl;
        cout << "\033[33mWhat would you like to do?\033[0m\n>>> ";
        cin >> choice;
        if(!inputIsDigit(choice)){
            choice = loopChoice();
        }
        choiceInt = stoi(choice);

        if(choiceInt == 1){
            rest.displayGeneral();
        }
        else if(choiceInt == 2){
            rest.displayGeneral();
            string tableIndex, name, id;
            cout << "Which table do you want to reserve?\n>>> ";
            cin >> tableIndex;
            cin.ignore();   // this allows us to clear the new line from the user input above
            cout << "What is your name?\n>>> ";
            getline(cin, name);
            cout << "What is your registration ID?\n>>> ";
            cin >> id;

            rest.reserveTable(stoi(tableIndex), name, stoi(id));
        }
        else if(choiceInt == 3){
            string tableIndex, name, id;
            cout << "What table did you reserve?\n>>> ";
            cin >> tableIndex;
            cin.ignore();
            cout << "What's your name?\n>>> ";
            getline(cin, name);
            cout << "What's your id?\n>>> ";
            cin >> id;
            rest.claimTable(stoi(tableIndex), name, stoi(id));
        }
        else if(choiceInt == 4){
            string tableIndex;
            cout << "Which table queue do you want to view?\n>>> ";
            cin >> tableIndex;
            rest.displayTableQueue(stoi(tableIndex));
        }

        cout << endl << endl;
    }
    while(choiceInt != 5);

}



int main(){
    run();

    return 0;
}
