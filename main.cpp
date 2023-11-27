#include <iostream> 
#include <string>
#include <vector>
#include <algorithm> //this is so the transform function can work
#include <random> //this is gonna help me with rare events like winning the chess game
using namespace std;

void roomone(vector<string>& inventory);
void roomtwo(vector<string>& inventory);
void roomthree(vector<string>& inventory);

string toLowercase(const string& str)
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string trim(const string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    if (start != string::npos && end != string::npos)
    {
        return str.substr(start, end - start + 1);
    }

    return "";
}

int main()
{
    bool gameRunning = true;
    vector<string> inventory;
    const std::string orangeColor = "\033[38;5;208m";
    const std::string resetColor = "\033[0m";
    string title = R"(
oooooooooooo oooo                       oooooooooooo                                            o8o                                              .   
8'   888   `8 `888                       `888'     `8                                            `"'                                            .o8   
     888       888 .oo.    .ooooo.        888         oooo    ooo oo.ooooo.   .ooooo.  oooo d8b oooo  ooo. .oo.  .oo.    .ooooo.  ooo. .oo.   .o888oo 
     888       888P"Y88b  d88' `88b       888oooo8     `88b..8P'   888' `88b d88' `88b `888""8P `888  `888P"Y88bP"Y88b  d88' `88b `888P"Y88b    888   
     888       888   888  888ooo888       888    "       Y888'     888   888 888ooo888  888      888   888   888   888  888ooo888  888   888    888   
     888       888   888  888    .o       888       o  .o8"'88b    888   888 888    .o  888      888   888   888   888  888    .o  888   888    888 . 
    o888o     o888o o888o `Y8bod8P'      o888ooooood8 o88'   888o  888bod8P' `Y8bod8P' d888b    o888o o888o o888o o888o `Y8bod8P' o888o o888o   "888" 
                                                                   888                                                                                
                                                                  o888o    
)";
    cout << orangeColor << title << resetColor << endl;
    while (gameRunning)
    {

        cout << "Please type 'start' to begin" << endl << endl;
        string userinput;
        getline(cin, userinput);
        userinput = trim(userinput);

        if (toLowercase(userinput) == "start")
        {
            roomone(inventory);
        }
        else if (userinput == "stop" || userinput == "end")
        {
            cout << "Thank you for playing, goodbye" << endl;
            gameRunning = false;
        }

    }

    return 0;
}
//First room with just a door
void roomone(vector<string>& inventory)
{
    system("cls");
    bool nextroom = false;
    bool dooropen = false;
    int help = 0; 
    string userinput;
    cout << "You awake in a small and poorly lit room. You can't seem to remember how you got here or what exactly is going on.\nYou notice you are wearing an orange jumpsuit, that has many pockets, with the number 61 labeled on the right sleeve." << endl;
    cout << "While standing up you feel the sting of cold marble on your bare feet. You now stand in the middle of the room." << endl;
    cout << "(You should \033[38;5;206mlook\033[0m around the room to get a better idea of what is around you)" << endl;
    
    //roomone code
    do
    {
       
        cout << "What would you like to do:" << endl;
        
        getline(cin, userinput);
        userinput = trim(userinput);
        
        //door check
        if (toLowercase(userinput) == "door" || toLowercase(userinput) == "knock on door" || toLowercase(userinput) == "hit door" || toLowercase(userinput) == "hit the door" || toLowercase(userinput) == "walk to the door" || toLowercase(userinput) == "look at door" || toLowercase(userinput) == "check door" || toLowercase(userinput) == "check the door" || toLowercase(userinput) == "walk to door" || toLowercase(userinput) == "go to door" || toLowercase(userinput) == "try to open the door" || toLowercase(userinput) == "look at the door" || toLowercase(userinput) == "inspect the door" || toLowercase(userinput) == "go to the door" || toLowercase(userinput) == "go door" || toLowercase(userinput) == "open door" || toLowercase(userinput) == "open the door" || toLowercase(userinput) == "try door")
        {
            if (!dooropen)
            {
                system("cls");
                cout << "You take a step forward towards the door and upon doing so you hear a loud \033[38;5;33mclick\033[0m echo through out the room. \nThe door slowly starts to rise up from the ground up and open revealing that there is another room just beyond this one." << endl;
                cout << "(Once you complete the puzzle for a room the door will open you will then need to \033[38;5;206mwalk through\033[0m the door in order to travel to the next room)" << endl;
                dooropen = true;
                help = 2;
            }
            else
            {
                system("cls");
                cout << "The door is open now and you can see that there is another room just beyond this one" << endl;
            }
        }
        //room check
        else if (toLowercase(userinput) == "look" || toLowercase(userinput) == "look around room" || toLowercase(userinput) == "glace" || toLowercase(userinput) == "take a look around" || toLowercase(userinput) == "take a look" || toLowercase(userinput) == "look room" || toLowercase(userinput) == "view room" || toLowercase(userinput) == "view the room" || toLowercase(userinput) == "look at the room" || toLowercase(userinput) == "look around" || toLowercase(userinput) == "look around the room")
        {
            system("cls");
            cout << "You look around the room to see that the walls are barely far enough apart to fully spread your arms out.\nThe walls themself are covered with padding that you would normally see in a psychiatric ward for violent patients. \nThe pads however have been here for a long time, you can tell this due to the yellowish colour that they bare" << endl;
            cout << "Aside from the thick padding lining each wall, they are blank, execpt for the wall directly infront of you which has a large metal door that seems to be sealed tight." << endl;
            cout << "(You can travel to places in the room if you wish, '\033[38;5;206mgo to ____\033[0m')" << endl;
            help = 1; 
        }
        //inventory check
        else if (toLowercase(userinput) == "inventory" || toLowercase(userinput) == "view inventory" || toLowercase(userinput) == "check inventory" || toLowercase(userinput) == "check pockets")
        {
            if (!inventory.empty()) 
            {
                system("cls");
                cout << "Inventory: ";

                auto iter = inventory.begin();

               
                cout << *iter;
                ++iter;

                
                for (; iter != inventory.end(); ++iter) {
                    cout << ", " << *iter;
                }
                cout << endl;
            }
            else 
            {
                system("cls");
                cout << "Inventory is empty." << endl;
            }
        }
        //leaving room
        else if (toLowercase(userinput) == "leave room" || toLowercase(userinput) == "walk into room" || toLowercase(userinput) == "walk into other room" || toLowercase(userinput) == "walk into the other room" || toLowercase(userinput) == "go into the other room" || toLowercase(userinput) == "enter room" || toLowercase(userinput) == "walk into the room" || toLowercase(userinput) == "walk through door" || toLowercase(userinput) == "walk through the door" || toLowercase(userinput) == "exit room" || toLowercase(userinput) == "go to next room" || toLowercase(userinput) == "leave the room" || toLowercase(userinput) == "exit the room" || toLowercase(userinput) == "go to the next room" || toLowercase(userinput) == "go through the door" || toLowercase(userinput) == "leave" || toLowercase(userinput) == "go forward" || toLowercase(userinput) == "go through door")
        {
            if (dooropen)
            {
                nextroom = true;
            }
            else
            {
                system("cls");
                cout << "The door is not yet open there must be a way to open it." << endl;
            }
        }
        //shitting self
        else if (toLowercase(userinput) == "shit" || toLowercase(userinput) == "shit pants" || toLowercase(userinput) == "shit myself" || toLowercase(userinput) == "take a shit")
        {
            auto UnderwearIt = find(inventory.begin(), inventory.end(), "Shit Stained Underwear");
            if (UnderwearIt != inventory.end())
            {
                system("cls");
                cout << "You have already \033[38;5;130mshit\033[0m yourself" << endl;

            }
            else
            {
                system("cls");
                cout << "You \033[38;5;130mshit\033[0m your pants \n(Shit Stained Underwear was added to your inventory)" << endl;
                inventory.push_back("Shit Stained Underwear");
            }
        }
        //help
        else if (toLowercase(userinput) == "/help")
        {
            if (help == 0)
            {
                system("cls");
                cout << "You could look around the room you are in to get a better idea of what is around you \nTry typing '\033[38;5;206mlook around the room\033[0m'" << endl;

            }
            else if (help == 1)
            {
                system("cls");
                cout << "The most important thing in this room right now is that door \nTry typing '\033[38;5;206mgo to the door\033[0m'" << endl; 
            }
            else if (help == 2)
            {
                system("cls");
                cout << "Now that the door is open all you have to do is walk through it into the next room \n(this is used so you can have a chance to collect any items that you may need before entering the next room) \nTry typing '\033[38;5;206mleave the room\033[0m'" << endl;
            }
        }
        //anything else
        else
        {
            cout << "I do not understand: '" << userinput << "'" << endl;
            cout << "Type \033[38;5;206m/help\033[0m if you need a little guidance." << endl;           
        }
    } while (!nextroom);
    //next room
    if (nextroom)
    {
        roomtwo(inventory);
    }
}
//Second room with firearm
void roomtwo(vector<string>& inventory)
{
    system("cls");
    bool nextroom = false;
    bool dooropen = false;
    int help = 0; 
    string userinput;
    cout << "You step out of the room and you enter a new room, similar to the one you were just in but this one is bigger but not by much. \nThe door that was just open behind you slams shut preventing you from return to the room prior \nIn the center of this room lies a table with something on it" << endl;
    cout << "(Now that you are in a new room best to \033[38;5;206mview\033[0m it and see what is in here)" << endl;
    //roomtwo code
    do
    {
        
        cout << "What would you like to do: ";
        getline(cin, userinput);
        userinput = trim(userinput);

        //gun get
        if (toLowercase(userinput) == "take firearm" || toLowercase(userinput) == "take the firearm" || toLowercase(userinput) == "take gun" || toLowercase(userinput) == "grab the firearm" || toLowercase(userinput) == "take the gun" || toLowercase(userinput) == "pick up the gun" || toLowercase(userinput) == "pick up the firearm" || toLowercase(userinput) == "pick up firearm" || toLowercase(userinput) == "pick up gun" || toLowercase(userinput) == "grab gun" || toLowercase(userinput) == "grab the gun")
        {
            auto FirearmIt = find(inventory.begin(), inventory.end(), "Firearm");
            if (FirearmIt != inventory.end())
            {
                system("cls");
                cout << "You already have the Firearm in your inventory" << endl;
            }
            else
            {
                system("cls");
                inventory.push_back("Firearm");
                cout << "You reach down towards the table and pick up the Firearm, feeling the metal of the handle and the weight of it in your hands as you slip the Firearm into on of your jumpsuit pockets" << endl;
                cout << "(Firearm was added to your inventory)" << endl;
                help = 3;
            }
            
        }
       //firearm check
        else if (toLowercase(userinput) == "inspect firearm" || toLowercase(userinput) == "look at firearm" || toLowercase(userinput) == "look at the firearm" || toLowercase(userinput) == "inspect the firearm" || toLowercase(userinput) == "look at gun" || toLowercase(userinput) == "look at the gun" || toLowercase(userinput) == "inspect the gun" || toLowercase(userinput) == "inspect gun" || toLowercase(userinput) == "view the firearm" || toLowercase(userinput) == "view firearm" || toLowercase(userinput) == "view the gun" || toLowercase(userinput) == "view gun")
        {
            system("cls");
            cout << "You look at the gun that sits upon the wooden table."
                "\nIt is a standard looking firearm, something you would see a cop use in a movie,"
                "\nit has a metal handle with no grip on it you also notice a considerable amout of wear on the gun especially on the tip of the barrel. \nWhere it seems to be blotted with bits of smoke and rust \nThis gun has defintly been fired before" << endl; 
        }
        //table check
        else if (toLowercase(userinput) == "check table" || toLowercase(userinput) == "table" || toLowercase(userinput) == "walk up to the table" || toLowercase(userinput) == "look table" || toLowercase(userinput) == "check the table" || toLowercase(userinput) == "look at the table" || toLowercase(userinput) == "see what is on the table" || toLowercase(userinput) == "go to table" || toLowercase(userinput) == "go to the table" || toLowercase(userinput) == "walk to the table")
        {
            auto FirearmIt = find(inventory.begin(), inventory.end(), "Firearm");
            if (FirearmIt != inventory.end())
            {
                system("cls");
                cout << "The wooden table is now empty after you have taken the Firearm" << endl;
            }
            else
            {
                system("cls");
                cout << "You walk towards the small wooden table and see that laying on top of it is a Firearm" << endl;
            }
           
        }
        //looks room
        else if (toLowercase(userinput) == "look" || toLowercase(userinput) == "look around room" || toLowercase(userinput) == "glace" || toLowercase(userinput) == "take a look around" || toLowercase(userinput) == "take a look" || toLowercase(userinput) == "look room" || toLowercase(userinput) == "view room" || toLowercase(userinput) == "view the room" || toLowercase(userinput) == "look at the room" || toLowercase(userinput) == "look around" || toLowercase(userinput) == "look around the room")
        {
            auto FirearmIt = find(inventory.begin(), inventory.end(), "Firearm");
            if (FirearmIt != inventory.end())
            {
                system("cls");
                cout << "Looking around this new room you can tell that there are only minor differences to the previous room. \nThe room size, though still not big, is twice as big as the last room giving you more space you strech" << endl;
                cout << "The lights in this room are much brighter and things are easier to see. The walls are still lined with the same yellow stained padding \nIn the middle of the room lies a wooden table where the Firearm use to lay" << endl;
                cout << "Beyond the table lies another large metal door just like in the last room, this door is also sealed tight" << endl; 
                cout << "(You can \033[38;5;206minspect\033[0m items as well as \033[38;5;206mtake\033[0m them if you are allowed)" << endl;
                help = 1;
            }
            else
            {
                system("cls");
                cout << "Looking around this new room you can tell that there are only minor differences to the previous room. \nThe room size ,though still not big, is twice as big as the last room giving you more room you strech" << endl;
                cout << "The lights in this room are much brighter and things are easier to see. The walls are still lined with the same yellow stained padding \nIn the middle of the room lies a wooden table that seems to be bolted to the ground and unable to move, laying on the table seems to to be a small Firearm" << endl;
                cout << "Beyond the table lies another large metal door just like in the last room, this door is also sealed tight"<< endl;  
                help = 1;
            }
        }
        //door check
        else if (toLowercase(userinput) == "door" || toLowercase(userinput) == "walk to the door" || toLowercase(userinput) == "knock on door" || toLowercase(userinput) == "hit door" || toLowercase(userinput) == "hit the door" || toLowercase(userinput) == "walk to door" || toLowercase(userinput) == "look at door" || toLowercase(userinput) == "check the door" || toLowercase(userinput) == "check door" || toLowercase(userinput) == "go to door" || toLowercase(userinput) == "try to open the door" || toLowercase(userinput) == "look at the door" || toLowercase(userinput) == "inspect the door" || toLowercase(userinput) == "go to the door" || toLowercase(userinput) == "go door" || toLowercase(userinput) == "open door" || toLowercase(userinput) == "open the door" || toLowercase(userinput) == "try door")
        {
            if (!dooropen) 
            {
                system("cls"); 
                cout << "You walk up to the large metal door that you have seen once before and as you do you hear a loud \033[38;5;33mclick\033[0m echo through out the room and the door just like before starts to open" << endl;
                dooropen = true; 
                help = 2; 
            }
            else
            {
                system("cls");
                cout << "The door is already open" << endl; 
            }
           
        }
        //inventory
        else if (toLowercase(userinput) == "inventory" || toLowercase(userinput) == "view inventory" || toLowercase(userinput) == "check inventory")
        {
            if (!inventory.empty()) {
                system("cls");
                cout << "Inventory: ";

                auto iter = inventory.begin();

                // Print the first item without a leading comma
                cout << *iter;
                ++iter;

                // Print the rest with a leading comma
                for (; iter != inventory.end(); ++iter) {
                    cout << ", " << *iter;
                }
                cout << endl;
            }
            else {
                system("cls");
                cout << "Inventory is empty." << endl;
            }
        }
        //self harm
        else if (toLowercase(userinput) == "use gun on self" || toLowercase(userinput) == "kill myself" || toLowercase(userinput) == "kill self" || toLowercase(userinput) == "shoot self" || toLowercase(userinput) == "kill myself with gun" || toLowercase(userinput) == "shoot myself" || toLowercase(userinput) == "use firearm on self" || toLowercase(userinput) == "kill myself with firearm" || toLowercase(userinput) == "kill myself with the gun")
        {
            auto FirearmIt = find(inventory.begin(), inventory.end(), "Firearm"); 
            if (FirearmIt != inventory.end())
            {
                system("cls");
                cout << "You bring the gun up to the side of your head and you pull the trigger hoping to be free from this prison you have found your self in. \nWith the \033[1;31mclick\033[0m\n of the barrel everything turns to black" << endl;
                cout << "\033[1;31mGAME OVER\033[0m\nEnding 4 of #" << endl << endl;
                cout << "You have completed the Pre-Alpha for '\033[38;5;208mThe Experiment\033[0m' \nThank you for playing!" << endl;
                cout << "Used path 4 out of 5" << endl;
                exit(0);
            }
            else
            {
                system("cls");
                cout << "you do not have an item to do that with" << endl;
            }
        }
        //leaving room
        else if (toLowercase(userinput) == "leave room" || toLowercase(userinput) == "walk into room" || toLowercase(userinput) == "walk into other room" || toLowercase(userinput) == "walk into the other room" || toLowercase(userinput) == "go into the other room" || toLowercase(userinput) == "enter room" || toLowercase(userinput) == "walk into the room" || toLowercase(userinput) == "walk through door" || toLowercase(userinput) == "walk through the door" || toLowercase(userinput) == "exit room" || toLowercase(userinput) == "go to next room" || toLowercase(userinput) == "leave the room" || toLowercase(userinput) == "exit the room" || toLowercase(userinput) == "go to the next room" || toLowercase(userinput) == "go through the door" || toLowercase(userinput) == "leave")
        {
            if (dooropen)
            {
                nextroom = true;
            }
            else
            {
                system("cls");
                cout << "The door is in the way" << endl;
            }
        }
        //shitting self
        else if (toLowercase(userinput) == "shit" || toLowercase(userinput) == "shit pants" || toLowercase(userinput) == "shit myself" || toLowercase(userinput) == "take a shit")
        {
            auto UnderwearIt = find(inventory.begin(), inventory.end(), "Shit Stained Underwear");
            if (UnderwearIt != inventory.end())
            {
                system("cls");
                cout << "You have already \033[38;5;130mshit\033[0m yourself" << endl;

            }
            else
            {
                system("cls");
                cout << "You \033[38;5;130mshit\033[0m your pants \n(Shit Stained Underwear was added to your inventory)" << endl;
                inventory.push_back("Shit Stained Underwear");
            }
        }
        //help
        else if (toLowercase(userinput) == "/help")
        {
            if (help == 0)
            {
                system("cls");
                cout << "In most rooms the best thing to start with is looking around the current room you are in to get more details on what is around you \nTry typing '\033[38;5;206mlook around the room\033[0m'" << endl;
            }
            else if (help == 1)
            {
                system("cls"); 
                cout << "There is an item in this room you can collect if you wish to do so or you can check out the door that is on the other side of the room \nTry typing '\033[38;5;206mtake the Firearm\033[0m' or '\033[38;5;206mgo to the door\033[0m'" << endl;
            }
            else if (help == 2)
            {
                system("cls"); 
                cout << "Just like before, the door is open and you can walk through when ever you are ready \nTry typing '\033[38;5;206mleave the room\033[0m'" << endl;
            }
            else if (help == 3)
            {
                system("cls");  
                cout << "Now that you have the Firearm best find a way into the next room, you could always start with the door \nTry typing '\033[38;5;206mgo to the door\033[0m'" << endl;
                cout << "You can also check your inventory by typing '\033[38;5;206minventory\033[0m'" << endl;
            }
        }
        //anything else
        else
        {
           
            cout << "I do not understand: '" << userinput << "'" << endl;
            cout << "Type \033[38;5;206m/help\033[0m if you need a little guidance." << endl;
        }


    } while (!nextroom);
    //next room
    if (nextroom)
    {
        roomthree(inventory);

    }
}
//Third room with the chess set puzzle 
void roomthree(vector<string>& inventory)
{
    system("cls");
    bool nextroom = false;
    bool dooropen = false;
    bool puzzlesolved = false;
    bool attable = false;
    bool mandead = false;
    
    int endingNumber = 0;
    int help = 0; 
    int helpWhileSitting = 0; 
    
    random_device rd; 
    mt19937 generator(rd()); 
    uniform_int_distribution<int> distribution(1, 100); 

    string userinput;
    cout << "You step out of the previous room and walk into the next. This room is even larger than the last two room combined. \nYour entrance triggers the last door to slam shut locking you in this new room \nWhich in the middle of you see a larger table with a board game of some kind set up on it. \nThere are two chairs on each side of the table. One empty and the other sits a man quietly staring forward" << endl;

    //roomthree code
    do
    {

        cout << "What would you like to do: ";
        getline(cin, userinput);
        userinput = trim(userinput);

        //looking
        if (toLowercase(userinput) == "look" || toLowercase(userinput) == "glace" || toLowercase(userinput) == "take a look around" || toLowercase(userinput) == "take a look" || toLowercase(userinput) == "look room" || toLowercase(userinput) == "view room" || toLowercase(userinput) == "view the room" || toLowercase(userinput) == "look at the room" || toLowercase(userinput) == "look around" || toLowercase(userinput) == "look around the room" || toLowercase(userinput) == "look around room")
        {
            if (!mandead)
            {
                system("cls");
                cout << "The room is the same as the ones that came before it, marbel floors, padded walls, and a sealed shut metal door that lies at the other end" << endl;
                cout << "The middle of the room of the room hosts a wooden table with two chairs one empty and the other with a man sitting in it. \nThe man is wearing a orange jumpsuit just like you with the number 39 written on the side of his sleeve. \nHe hasnt said a word since you walked into the room and has kept his gaze dead ahead almost like he does not even see or hear you" << endl;
                cout << "Table has a game of chess set up on it with the board being prepped to play a new round" << endl;
                help = 1; 

            }
            else
            {
                system("cls");
                cout << "The room is the same as the ones that came before it, marbel floors, padded walls, and a sealed shut metal door that lies at the other end" << endl;
                cout << "The middle of the room of the room hosts a wooden table with two chairs one empty and the other where the man once sat. \nHe now lies dead on the groud with a large pull of blood slowly enclosing his whole body" << endl;
                cout << "Table has a game of chess set up on it with the board being prepped to play a new round" << endl;
            }
        }
        //inventory
        else if (toLowercase(userinput) == "inventory" || toLowercase(userinput) == "view inventory" || toLowercase(userinput) == "check inventory")
        {
            if (!inventory.empty()) {
                system("cls");
                cout << "Inventory: "; 

                auto iter = inventory.begin();

                // Print the first item without a leading comma
                cout << *iter;
                ++iter;

                // Print the rest with a leading comma
                for (; iter != inventory.end(); ++iter) {
                    cout << ", " << *iter;
                }
                cout << endl;
            }
            else {
                system("cls");
                cout << "Inventory is empty." << endl;
            }
        }
        //talking
        else if (toLowercase(userinput) == "talk to guy" || toLowercase(userinput) == "say hi" || toLowercase(userinput) =="say hello" || toLowercase(userinput) =="flash him" || toLowercase(userinput) =="show him my tits" || toLowercase(userinput) =="try to talk to the man" || toLowercase(userinput) =="try to get the man to talk" || toLowercase(userinput) == "speak to man" || toLowercase(userinput) == "converstate with man" || toLowercase(userinput) == "talk to the guy" || toLowercase(userinput) == "speak to the man" || toLowercase(userinput) == "talk" || toLowercase(userinput) == "talk to the man" || toLowercase(userinput) == "talk the man" || toLowercase(userinput) == "speak")
        {
            system("cls");
            cout << "You try interacting with the man but you are quickly ignored. He seems to not care about you or anything you do or have to say" << endl;
        }
        //siting at table
        else if (toLowercase(userinput) == "sit with man" || toLowercase(userinput) == "play chess" || toLowercase(userinput) == "sit in the chair" || toLowercase(userinput) == "sit down" || toLowercase(userinput) == "sit at the table" || toLowercase(userinput) == "play chess with the man" || toLowercase(userinput) == "sit with the man" || toLowercase(userinput) == "play chess with him" || toLowercase(userinput) == "play chess with him" || toLowercase(userinput) == "sit")
        {
            if (!puzzlesolved)
            {
                system("cls");
                attable = true;
                cout << "You sit down in front of the quite man and get ready to play chess" << endl;
                do
                {   
                    
                    int randomNumber = distribution(generator);
                    cout << "You sit in front of the chess board, what would you like to do now:" << endl;
                    getline(cin, userinput);

                    userinput = trim(userinput);
                    //table check
                    if (toLowercase(userinput) == "look" || toLowercase(userinput) == "glace" || toLowercase(userinput) == "take a look around" || toLowercase(userinput) == "take a look" || toLowercase(userinput) == "look room" || toLowercase(userinput) == "view room" || toLowercase(userinput) == "view the room" || toLowercase(userinput) == "look at the room" || toLowercase(userinput) == "look around" || toLowercase(userinput) == "look around the room")
                    {
                        system("cls");
                        cout << "As you sit in front of the table before you lies a chess board with a soild metal playing field. \nEach piece is made out of a thick wood that is coated in a black and white paint with the white pieces being infront of you and the black being in front of him \nThe chairs and the table seem to be made out of the same wood material as the pieces only difference being that the table and chairs are bolted to the ground and seem unable to be moved" << endl;
                    }
                    //talking to man
                    else if (toLowercase(userinput) == "talk to guy" || toLowercase(userinput) == "say hi" || toLowercase(userinput) == "say hello" || toLowercase(userinput) == "flash him" || toLowercase(userinput) == "show him my tits" || toLowercase(userinput) == "try to talk to the man" || toLowercase(userinput) == "try to get the man to talk" || toLowercase(userinput) == "speak to man" || toLowercase(userinput) == "converstate with man" || toLowercase(userinput) == "talk to the guy" || toLowercase(userinput) == "speak to the man" || toLowercase(userinput) == "talk" || toLowercase(userinput) == "talk to the man" || toLowercase(userinput) == "talk the man" || toLowercase(userinput) == "speak")
                    {
                        system("cls");
                        cout << "You try interacting with the man but you are quickly ignored. He seems to not care about you or anything you do or have to say" << endl;
                    }
                    //inventory
                    else if (toLowercase(userinput) == "inventory" || toLowercase(userinput) == "view inventory" || toLowercase(userinput) == "check inventory") 
                    {
                        if (!inventory.empty()) 
                        {
                            system("cls");
                            cout << "Inventory: ";

                            auto iter = inventory.begin(); 

                            // Print the first item without a leading comma
                            cout << *iter; 
                            ++iter; 

                            // Print the rest with a leading comma
                            for (; iter != inventory.end(); ++iter) {
                                cout << ", " << *iter; 
                            }
                            cout << endl; 
                        }
                        else 
                        {
                            system("cls"); 
                            cout << "Inventory is empty." << endl; 
                        }
                    }
                    //giving up 
                    else if (toLowercase(userinput) == "give up" || toLowercase(userinput) == "knock over king" || toLowercase(userinput) == "surrender game" || toLowercase(userinput) == "surrender" || toLowercase(userinput) == "forfeit" || toLowercase(userinput) == "forfeit the game" || toLowercase(userinput) == "forfeit chess")
                    {
                        system("cls");
                        cout << "You knock over your king in a sign of surrender for you are no match to best this chess player. \nUpon your king hitting the table you hear a loud \033[38;5;33mclick\033[0m echo through out the room \nfollowing the click you stand up out of your seat" << endl;
                        puzzlesolved = true;
                        attable = false;
                        dooropen = true;
                        endingNumber = 3;


                    }
                    //playing chess
                    else if (toLowercase(userinput) == "play chess" || toLowercase(userinput) == "pick up piece" || toLowercase(userinput) == "play game" || toLowercase(userinput) == "play game again" || toLowercase(userinput) == "play the game" || toLowercase(userinput) == "play again" || toLowercase(userinput) == "move a piece" || toLowercase(userinput) == "move pawn" || toLowercase(userinput) == "move piece" || toLowercase(userinput) == "start chess" || toLowercase(userinput) == "move knight" || toLowercase(userinput) == "move bishop" || toLowercase(userinput) == "move rook" || toLowercase(userinput) == "begin chess game" || toLowercase(userinput) == "play")
                    {
                        if (randomNumber == 1)
                        {
                            system("cls");
                            cout << "You move your pawn foward one space and saying nothing the man looks down at the board and moves he piece in response \nThrough sheer force of will, or dumb luck, you found a way to beat the man in chess. Upon doing so you hear a loud \033[38;5;33mclick\033[0m echo through out the room. \nYou proceed to stand up out of the chair" << endl;
                            puzzlesolved = true;
                            attable = false;
                            dooropen = true;
                            endingNumber = 1;

                        }
                        else
                        {
                            system("cls");
                            cout << "You move your pawn foward one space and saying nothing the man looks down at the board and moves he piece in response. \nThe two of you start to play chess and the man defeats you with out fail. Upon victory the man resets the board and returns to staring forward" << endl;
                            if (helpWhileSitting == 0)
                            {
                                helpWhileSitting = 1;
                            }
                            else
                            {
                                helpWhileSitting = 2;
                            }
                        }
                    }
                    //eating his king
                    else if (toLowercase(userinput) == "eat his king" || toLowercase(userinput) == "eat the king" || toLowercase(userinput) == "comsume his king" || toLowercase(userinput) == "eat king" || toLowercase(userinput) == "swallow king" || toLowercase(userinput) == "swallow his king")
                    {
                        system("cls");
                        cout << "In a turn of events that the slient man surely was not expecting you reach over the chess board and you swallow his king in one gulp. \nYou start coughing (having just ate a whole chess piece will do that to ya) and as you do you hear a loud \033[38;5;33mclick\033[0m echo through the room \nYou stand up out of your chair." << endl;
                        puzzlesolved = true;
                        attable = false;
                        dooropen = true;
                        endingNumber = 2;

                    }
                    //leave table
                    else if (toLowercase(userinput) == "stand up" || toLowercase(userinput) == "leave the table" || toLowercase(userinput) == "leave table" || toLowercase(userinput) == "walk away from the table" || toLowercase(userinput) == "get out of the chair" || toLowercase(userinput) == "get out of chair" || toLowercase(userinput) == "stand up from table")
                    {
                        cout << "You stand from out of your chair back into the middle of the room" << endl;
                        attable = false;

                    }
                    //killing man
                    else if (toLowercase(userinput) == "shoot man" || toLowercase(userinput) == "kill man" || toLowercase(userinput) == "use Firearm on man" || toLowercase(userinput) == "shoot the man with the gun" || toLowercase(userinput) == "shoot the guy" || toLowercase(userinput) == "shoot chess player")
                    {
                        if (!mandead)
                        {

                            auto FirearmIt = find(inventory.begin(), inventory.end(), "Firearm");
                            if (FirearmIt != inventory.end())
                            {
                                system("cls");
                                cout << "You pull out your newly aquired Firearm and you point it stright at the mute chess player, even when faced with death the man does not losen his gaze or even flitch. \nYou close your eyes and pull the trigger and with a \033[1;31mclick\033[0m\nof the barrel the bullet is fired stright into the forehead of the defenseless man\nWhen you open your eyes you see that the Firearm must not have been in very good shape for after firing it the barrel is now completely destoryed and is in a state of non-repair" << endl;
                                cout << "You also notice that the now broken Firearm is newly splattered with corse red blood stains \nLooking up from the Firearm you see the chess man is now laying on his side lifeless with a slowly growing pool of blood around him \nYou stand up from the table." << endl;
                                inventory.erase(FirearmIt);
                                inventory.push_back("Broken Blood Stained Firearm");
                                puzzlesolved = true;
                                attable = false;
                                dooropen = true;
                                mandead = true;
                                endingNumber = 5;
                                cout << "And as you do so you hear a loud \033[38;5;33mclick\033[0m echo through out the room" << endl;
                                cout << "(Broken Blood Stained Firearm was added to your inventory)" << endl;

                            }
                            else
                            {
                                cout << "you dont have that item in your inventory" << endl;
                            }
                        }
                        else
                        {
                            cout << "The man already lies lifeless on the floor of the room" << endl;
                        }
                    
                    }
                    //help
                    else if (toLowercase(userinput) == "/help")
                    {
                        if (helpWhileSitting == 0)
                        {
                            system("cls"); 
                            cout << "Try playing chess with him and see if that will make him respond" << endl;
                            cout << "Try typing '\033[38;5;206mplay chess with man\033[0m'" << endl;
                        }
                        else if (helpWhileSitting == 1)
                        {
                            system("cls"); 
                            cout << "It seems this man might be better at chess then you thought. Maybe there is some other way to beat this puzzle" << endl;
                            helpWhileSitting = 2;
                        }
                        else if (helpWhileSitting == 2)
                        {
                            system("cls"); 
                            cout << "Don't let him beat you, let him win" << endl;
                        }

                    }
                    //anything else
                    else
                    {
                        system("cls");
                        cout << "I do not understand: '" << userinput << "'" << endl;
                        cout << "Type \033[38;5;206m/help\033[0m if you need a little guidance." << endl;
                    }
                } while (attable);
            }
            //Stops you from sitting once puzzle is solved
            else if (mandead)
            {
                system("cls");
                cout << "How do you expect to play chess with a dead man" << endl;
            }
            else
            {
                system("cls");
                cout << "There is no need to play anymore" << endl;
            }
        }
        //door check
        else if (toLowercase(userinput) == "door" || toLowercase(userinput) == "knock on door" || toLowercase(userinput) == "hit door" || toLowercase(userinput) == "hit the door" || toLowercase(userinput) == "walk to the door" || toLowercase(userinput) == "walk to door" || toLowercase(userinput) == "look at door" || toLowercase(userinput) == "check the door" || toLowercase(userinput) == "check door" || toLowercase(userinput) == "go to door" || toLowercase(userinput) == "try to open the door" || toLowercase(userinput) == "look at the door" || toLowercase(userinput) == "inspect the door" || toLowercase(userinput) == "go to the door" || toLowercase(userinput) == "go door" || toLowercase(userinput) == "open door" || toLowercase(userinput) == "open the door" || toLowercase(userinput) == "try door")
        {
            system("cls");
            if (!dooropen)
            {
                system("cls");
                cout << "You approach the metal door but unlike before the door does not open and instead stays shut tight. \nThere must be another way to open it" << endl;
            }
            else
            {
                system("cls");
                cout << "You see now that the door is open and you are free to move through it" << endl;
            }
        }
        //self harm ending
        else if (toLowercase(userinput) == "use gun on self" || toLowercase(userinput) == "kill myself" || toLowercase(userinput) == "kill self" || toLowercase(userinput) == "shoot self" || toLowercase(userinput) == "kill myself with gun" || toLowercase(userinput) == "shoot myself" || toLowercase(userinput) == "use firearm on self" || toLowercase(userinput) == "kill myself with firearm" || toLowercase(userinput) == "kill myself with the gun")
        {
            auto FirearmIt = find(inventory.begin(), inventory.end(), "Firearm");
            if (FirearmIt != inventory.end())
            {
                system("cls");
                cout << "You bring the gun up to the side of your head and you pull the trigger hoping to be free from this prison you have found your self in. \nWith the \033[1;31mclick\033[0m\n of the barrel everything turns to black" << endl;
                cout << "\033[1;31mGAME OVER\033[0m\nEnding 4 of #" << endl << endl;
                endingNumber = 4;
                cout << "You have completed the Beta for '\033[38;5;208mThe Experiment\033[0m' \nThank you for playing!" << endl;
                cout << "Used path " << endingNumber << "out of 5" << endl;
                exit(0);
            }
            else
            {
                system("cls");
                cout << "You do not have an item to do that with" << endl;
            }
        }
        //killing man
        else if (toLowercase(userinput) == "shoot man" || toLowercase(userinput) == "kill man" || toLowercase(userinput) == "use Firearm on man" || toLowercase(userinput) == "shoot the man with the gun" || toLowercase(userinput) == "shoot the guy" || toLowercase(userinput) == "shoot chess player" || toLowercase(userinput) == "shoot the man" || toLowercase(userinput) == "kill the man")
        {
            if (!mandead)
            {

                auto FirearmIt = find(inventory.begin(), inventory.end(), "Firearm");
                if (FirearmIt != inventory.end())
                {
                    system("cls");
                    cout << "You pull out your newly aquired Firearm and you point it stright at the mute chess player, even when faced with death the man does not losen his gaze or even flitch. \nYou close your eyes and pull the trigger and with a \033[1;31mclick\033[0m\n of the barrel the bullet is fired stright into the forehead of the defenseless man\nWhen you open your eyes you see that the gun must not have been in very good shape for after fireing it the barrel is complete destoryed and is now in a state of non use" << endl;
                    cout << "You also notice that the now broken gun is newly splattered with corse red blood stains \nLooking up from the gun you see the chess man is now laying on his side lifeless with a slowly growing pool of blood around him." << endl;
                    inventory.erase(FirearmIt);
                    inventory.push_back("Broken Blood Stained Firearm");
                    puzzlesolved = true;
                    dooropen = true;
                    mandead = true;
                    endingNumber = 5;
                    cout << "You then hear a loud \033[38;5;33mclick\033[0m echo through out the room" << endl;
                    cout << "(Broken Blood Stained Firearm was added to your inventory)" << endl; 
                }
                else
                {
                    system("cls");
                    cout << "You dont have that item in your inventory" << endl;
                }
            }
            else
            {
                system("cls");
                cout << "You have already killed him" << endl;
            }
        }
        //leaving room
        else if (toLowercase(userinput) == "leave room" || toLowercase(userinput) == "walk into room" || toLowercase(userinput) == "walk into other room" || toLowercase(userinput) == "walk into the other room" || toLowercase(userinput) == "go into the other room" || toLowercase(userinput) == "enter room" || toLowercase(userinput) == "walk into the room" || toLowercase(userinput) == "walk through the door" || toLowercase(userinput) == "walk through door" || toLowercase(userinput) == "exit room" || toLowercase(userinput) == "go to next room" || toLowercase(userinput) == "leave the room" || toLowercase(userinput) == "exit the room" || toLowercase(userinput) == "go to the next room" || toLowercase(userinput) == "go through the door" || toLowercase(userinput) == "leave" || toLowercase(userinput) == "walk through the door")
        {
            if (dooropen)
            {
                nextroom = true;
            }
            else
            {
                system("cls");
                cout << "The door is in the way" << endl;
            }
        }
        //shitting self
        else if (toLowercase(userinput) == "shit" || toLowercase(userinput) == "shit pants" || toLowercase(userinput) == "shit myself" || toLowercase(userinput) == "take a shit")
        {
            auto UnderwearIt = find(inventory.begin(), inventory.end(), "Shit Stained Underwear");
            if (UnderwearIt != inventory.end())
            {
                system("cls");
                cout << "You have already \033[38;5;130mshit\033[0m yourself" << endl;

            }
            else
            {
                system("cls");
                cout << "You \033[38;5;130mshit\033[0m your pants \n(Shit Stained Underwear was added to your inventory)" << endl;
                inventory.push_back("Shit Stained Underwear");
            }
        }
        //help
        else if (toLowercase(userinput) == "/help")
        {
            if (help == 0)
            {
                system("cls");
                cout << "You should start by looking around the room to get a better understanding of what makes this room different than the last two" << endl;
            }
            else if (help == 1)
            {
                system("cls");
                cout << "Try interacting with what is in the room, like the man or the chess set" << endl; 
                cout << "Try typing '\033[38;5;206msit at the table\033[0m'" << endl;
            }
        }
       //anything else
        else
        {
            
            cout << "I do not understand: '" << userinput << "'" << endl; 
            cout << "Type \033[38;5;206m/help\033[0m if you need a little guidance." << endl; 
        }
    } while (!nextroom);
    //next room (pre-alpha ending) 
    if (nextroom)
    {
        system("cls");
        cout << "You have beaten the Pre-Alpha for '\033[38;5;208mThe Experiment\033[0m' \nThank you for playing!" << endl;
        cout << "Used path " << endingNumber << " out of 5" << endl;
        exit(0);
    }
} 
