// The Adventure Game
// Text based game that uses a RNG and plays in the favor of the player (so its easy)
#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void wait(int sec)
{this_thread::sleep_for(chrono::seconds(sec));}

void ellipse()
{
    wait(1);
    cout << ".";
    wait(1);
    cout << ".";
    wait(1);
    cout << "." << endl;
    wait(1);
}

void clear()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void shop(char shopBuy, char shopChoice, int count, int gold, int potion, int user)
{
    if (count == 4)
    {
        cout << "You have come across a roadside merchant!" << endl;
        wait(1);
        cout << "Would you like to see his wares? (y/n)" << endl;
        do
        {
            cin >> shopChoice;
            shopChoice = tolower(shopChoice);
            if (shopChoice == 'y')
            {
                cout << endl;
                cout << "      MERCHANT MENU" << endl;
                wait(1);
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                wait(1);
                cout << setw(25) << setfill('.') << left << "Golden Apple";
                cout << right << "3" << endl;
                wait(1);
                cout << setw(25) << left << "Dagger";
                cout << right << "5" << endl;
                wait(1);
                cout << setw(25) << left << "Potion of Luck";
                cout << right << "5" << endl << endl;
                wait(2);
                cout << "To buy an item, input a, b, or c." << endl;
                cin >> shopBuy;
                shopBuy = tolower(shopBuy);
                if (shopBuy == 'a' && gold >= 3)
                {
                    wait(1);
                    cout << "You have purchased a golden apple!" << endl;
                    wait(1);
                    cout << "Your strength increases by 3." << endl;
                    gold -= 3;
                    user+= 3;
                }
                else if (shopBuy == 'b' && gold >= 5)
                {
                    wait(1);
                    cout << "You have purchased a dagger!\nYour strength increases by 5." << endl;
                    gold -= 5;
                    user+= 5;
                }
                else if (shopBuy == 'c' && gold >= 5)
                {
                    wait(1);
                    cout << "You have purchased a potion of luck!" << endl;
                    wait(1);
                    cout << "You drink it to see what happens..." << endl;
                    gold -= 5;
                    potion = rand()%7+3;
                    user += potion;
                    wait(1);
                    cout << "Your strength has increased by " << potion << "!" << endl;
                    wait(1);
                    cout << "Your strength is now " << user << "." << endl;
                    
                }
                cout << "The merchant disappears into the woods. I guess it's time to move on." << endl;
                cout << endl;
            }
            
            else if (shopChoice == 'n')
            {
                cout << "Let's be on our way then!" << endl;
            }
            else
            {
                cout << "Invalid input. Please answer y/n." << endl;
            }
        } while (shopChoice != 'y' && shopChoice != 'n');
    }
}


// OPTION: LEFT ===============================================================


int goLeft(int path1, int user, int goldFind, int gold, int monster, int count)
{
    path1 = rand()%2+1;
    if (path1 == 1)
    {
        cout << "You take the path on the left";
        ellipse();
        cout << "You have found a golden apple!" << endl;
        wait(1);
        cout << "You now feel more powerful. (Strength +3)" << endl;
        user += 3;
        wait(1);
        cout << "Your strength is now " << user << "." << endl;
        wait(1);
        // randomizes gold find
        goldFind = rand()%3+1;
        gold += goldFind;
        if (goldFind == 1)
        {
            cout << "You have also found " << goldFind << " gold coin." << endl;
            wait(1);
            cout << "You now have " << gold << " gold in your pocket." << endl;
            wait(1);
        }
        else if (goldFind > 1)
        {
            cout << "You have also found " << goldFind << " gold coins." << endl;
            wait(1);
            cout << "You now have " << gold << " gold in your pocket." << endl;
            wait(1);
        }
        // ---------------------
    }
    else
    {
        cout << "You take the path on the left";
        ellipse();
        cout << "You have crossed paths with a monster of the forest!" << endl;
        wait(1);
        cout << "You must defeat it to pass through." << endl;
        wait(1);
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "The monster has a strength of " << monster << "." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        wait(1);
        if (user >= monster)
        {
            cout << "You have defeated the monster!" << endl;
            wait(1);
            cout << "You feel stronger as a result! (Strength +2)" << endl;
            user += 2;
            cout << "Your strength is now " << user << "." << endl;
        }
        else
        {
            cout << "You have been defeated by the monster and died at level " << count << "." << endl;
            wait(1);
            cout << "Game over." << endl;
            return 0;
        }
    }
    return 0;
}

 int goRight(int path2, int user, int goldFind, int gold, int monster, int count)
 {
     path2 = rand()%2+1;
     if (path2 == 1)
     {
         cout << "You take the path on the right";
         ellipse();
         cout << "You have found a golden apple!" << endl;
         wait(1);
         cout << "You now feel more powerful. (Strength +3)" << endl;
         user += 3;
         wait(1);
         cout << "Your strength is now " << user << "." << endl;
         wait(1);
         // randomizes gold find
         goldFind = rand()%3+1;
         gold += goldFind;
         if (goldFind == 1)
         {
             cout << "You have also found " << goldFind << " gold coin." << endl;
             wait(1);
             cout << "You now have " << gold << " gold in your pocket." << endl;
             wait(1);
         }
         else if (goldFind > 1)
         {
             cout << "You have also found " << goldFind << " gold coins." << endl;
             wait(1);
             cout << "You now have " << gold << " gold in your pocket." << endl;
             wait(1);
         }
         gold += goldFind;
         // ---------------------
     }
     else
     {
         cout << "You take the path on the right";
         ellipse();
         cout << "You have crossed paths with a monster of the forest!" << endl;
         wait(1);
         cout << "You must defeat it to pass through." << endl;
         wait(1);
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         cout << "The monster has a strength of " << monster << "." << endl;
         cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
         wait(1);
         if (user >= monster)
         {
             cout << "You have defeated the monster!" << endl;
             wait(1);
             cout << "You feel stronger as a result! (Strength +2)" << endl;
             user += 2;
             cout << "Your strength is now " << user << "." << endl;
         }
         else
         {
             cout << "You have been defeated by the monster and died at level " << count << "." << endl;
             wait(1);
             cout << "Game over." << endl;
             return 0;
         }
     }
     return 0;
 }




 // MAIN BODY ==============================================================================================================================================
 
int main()
{
    string strength;
    int user, monster, goldFind, potion, path1, path2;
    int gold = 2;
    char choice, shopChoice, shopBuy;
    
    clear();
    srand(time(0));                                                         // randomizes values based on clock
    cout << setfill('-') << setw(9) << "" << endl;
    wait(1);
    cout << setw(9) << left << "BEN'S" << endl;
    wait(1);
    cout << "ADVENTURE" << endl;
    wait(1);
    cout << setw(9) << right << "GAME" << endl;
    wait(1);
    cout << setw(9) << "" << endl;
    wait(3);
    cout << "Please type 'role' to get your initial strength:" << endl;
    cin >> strength;
    clear();
    // Checks for invalid input on the getline
    while (strength != "role")
    {
        cout << "Invalid input. Please type 'role'." << endl;
        cin >> strength;
    }
    // Randomizes initial user strength
    user = rand()%6+1;
    cout << "Your initial strength is " << user << "." << endl;
    if (user == 1)
    {
        wait(1);
        cout << "You are incredibly weak. Good luck, you're gonna need it." << endl;
    }
    else if (user == 6)
    {
        wait(1);
        cout << "You are incredibly strong! This should be easy for you." << endl;
    }
    wait(2);
    cout << "*~*~* You start with 2 gold coins in your pocket! *~*~*" << endl << endl;
    wait(3);
    
    monster = rand()%4+1; // gives monster a random "strength" number between 1-4
    
    for (int count = 1; count <= 10; count++)
    // +1 to a level count when the level is "passed"
    {
        do
        {
            cout << "------------------------------------------" << endl;
            cout << setfill(' ') << setw(22)<< "| Level " << count << " |"  << endl;
            cout << "------------------------------------------" << endl << endl;
            wait(2);
            shop(shopBuy, shopChoice, count, gold, potion, user);
            wait(1);
            cout << "You have encountered a fork in the road";
            ellipse();
            cout << "Would you like to go left or right? (l/r):" << endl;
            cin >> choice;
            choice = tolower(choice);
            
            // User has a choice to go left or right, but the path outcome randomizes each time
            if (choice == 'l')
            {goLeft(path1, user, goldFind, gold, monster, count);}
            
            else if (choice == 'r')
            {goRight(path2, user, goldFind, gold, monster, count);}
            // * Invalid input *
            else
                cout << "Invalid input. Please try again." << endl << endl;
        } while (choice != 'l' && choice != 'r'); // executes loop if choice is invalid (not l/r)
        
        monster += rand()%3+1; // every level, the monster increases strength by between 1 and 3 strength, regardless of if it is fought or not.
    }
    
    wait(1);
    cout << "Congratulations!" << endl << endl;
    wait(1);
    cout << "You have made it to the end of the adventure!" << endl;
    wait(1);
    cout << "Thank you for playing." << endl << endl;
    wait(1);
    cout << "In honor of the late Mr. Cooper...my coach, teacher, and mentor.";
    return 0; // ends program
}

// MAIN BODY ==============================================================================================================================================
