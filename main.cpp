#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //this is so the transform function can work
#include <random> //this is gonna help me with rare events like winning the chess game
#include <cstdlib> //to help me clear the control pannel and kill the code
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
            cout << "thank you for playing, goodbye" << endl;
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
    string userinput;
    cout << "You awake in a small and poorly lit room. You can't seem to remember how you got here or what exactly is going on.\nYou notice you are wearing a orange jumpsuit with the number 61 labeled on the right selve." << endl;
    do
    {
        cout << "What would you like to do:" << endl;
        getline(cin, userinput); 
        userinput = trim(userinput);

        if (toLowercase(userinput) == "door" || toLowercase(userinput) == "walk through the door" || toLowercase(userinput) == "go to door" || toLowercase(userinput) == "try to open the door" || toLowercase(userinput) == "look at the door" || toLowercase(userinput) == "inspect the door" || toLowercase(userinput) == "go to the door" || toLowercase(userinput) == "go door" || toLowercase(userinput) == "open door" || toLowercase(userinput) == "open the door" || toLowercase(userinput) == "try door")
        {
            system("cls");
            cout << "You take a step forward towards the door and upon doing so you hear a loud metal clang echo in though out the room and the door slowly starts to rise from the ground up." << endl;
            dooropen = true;
        }
        else if (toLowercase(userinput) == "look" || toLowercase(userinput) == "glace" || toLowercase(userinput) == "take a look around" || toLowercase(userinput) == "take a look" || toLowercase(userinput) == "look room" || toLowercase(userinput) == "view room" || toLowercase(userinput) == "view the room" || toLowercase(userinput) == "look at the room" || toLowercase(userinput) == "look around" || toLowercase(userinput) == "look around the room")
        {
            system("cls");
            cout << "You look around the room to seem that the walls on each side are only an arms length away from each other.\nThe walls themselfs are also stained witha yellowish colour of age and wear" << endl;
            cout << "Each wall in blank execpt for the wall directly infront of you which has a large metal door that seems to be sealed tight." << endl;
        }
        else if (toLowercase(userinput) == "inventory" || toLowercase(userinput) == "view inventory" || toLowercase(userinput) == "check inventory")
        {
            if (!inventory.empty()) 
            {
                system("cls");
                cout << "Inventory: ";
                for (const string& item : inventory) 
                { 
                    cout << item << "| "; 
                }
                cout << endl; 
            }
            else
            {
                system("cls");
                cout << "Inventory is empty." << endl;
            }
        }
        else if(toLowercase(userinput) == "leave room" || toLowercase(userinput) == "walk through door" || toLowercase(userinput) == "exit room" || toLowercase(userinput) == "go to next room" || toLowercase(userinput) == "leave the room" || toLowercase(userinput) == "exit the room" || toLowercase(userinput) == "go to the next room" || toLowercase(userinput) == "go through the door" || toLowercase(userinput) == "leave" || toLowercase(userinput) == "go forward" || toLowercase(userinput) == "go through door")
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
        else
        {
            cout << "Wrong input. Please try again." << endl;
        }
    } while (!nextroom);

    if (nextroom)
    {
        roomtwo(inventory);
    }
}

//Gun Room code
void roomtwo(vector<string>& inventory)
{
    system("cls"); 
    bool nextroom = false;
    bool dooropen = false;
    string userinput;
    cout << "You are in room two now. In it lies a table with nothing more than a firearm on it. \nBehind the table on the other side of the room lies another door" << endl;

    do
    {

       
        cout << "What would you like to do: ";
        getline(cin, userinput);
        userinput = trim(userinput); 
        
        //gun get
        if (toLowercase(userinput) == "take firearm" || toLowercase(userinput) == "take the firearm" || toLowercase(userinput) == "take gun" || toLowercase(userinput) == "grab the firearm" || toLowercase(userinput) == "take the gun" || toLowercase(userinput) == "pick up the gun" || toLowercase(userinput) == "pick up the firearm" || toLowercase(userinput) == "pick up firearm" || toLowercase(userinput) == "pick up gun" || toLowercase(userinput) == "grab gun" || toLowercase(userinput) == "grab the gun")
        {
            system("cls");
            inventory.push_back("firearm");
            cout << "You picked up the firearm off the table." << endl;
        }
        //looks room
        else if (toLowercase(userinput) == "look" || toLowercase(userinput) == "glace" || toLowercase(userinput) == "take a look around" || toLowercase(userinput) == "take a look" || toLowercase(userinput) == "look room" || toLowercase(userinput) == "view room" || toLowercase(userinput) == "view the room" || toLowercase(userinput) == "look at the room" || toLowercase(userinput) == "look around" || toLowercase(userinput) == "look around the room")
        {
            auto firearmIt = find(inventory.begin(), inventory.end(), "firearm");
            if (firearmIt != inventory.end())
            {
                system("cls");
                cout << "you see a big empty room with nothing more than a wooden table in the center of the room where the firearm once was. \nbeyond that lays a door" << endl;
            }
            else
            {
                system("cls");
                cout << "you see a big empty room with nothing more than a firearm laying on a wooden table in the center of the room. \nbeyond that lays a door" << endl;
            }
        }
        //door check
        else if (toLowercase(userinput) == "door" || toLowercase(userinput) == "walk through the door" || toLowercase(userinput) == "go to door" || toLowercase(userinput) == "try to open the door" || toLowercase(userinput) == "look at the door" || toLowercase(userinput) == "inspect the door" || toLowercase(userinput) == "go to the door" || toLowercase(userinput) == "go door" || toLowercase(userinput) == "open door" || toLowercase(userinput) == "open the door" || toLowercase(userinput) == "try door")
        {
            cout << "upon apporching the door the loud click you heard once before echos through the room and the door slowly opens \nyou walk though into the next room" << endl;
            dooropen = true;
        }
        //inventory
        else if (toLowercase(userinput) == "inventory" || toLowercase(userinput) == "view inventory" || toLowercase(userinput) == "check inventory") 
        {
            if (!inventory.empty())
            {
                system("cls");
                cout << "Inventory: ";
                for (const string& item : inventory)
                {
                    cout << item << "| ";
                }
                cout << endl;
            }
            else
            {
                cout << "Inventory is empty." << endl;
            }
        }
        //self harm
        else if (toLowercase(userinput) == "use gun on self" || toLowercase(userinput) == "kill myself" || toLowercase(userinput) == "kill self" ||toLowercase(userinput) == "shoot self" || toLowercase(userinput) == "kill myself with gun" || toLowercase(userinput) == "shoot myself"|| toLowercase(userinput) == "use firearm on self" || toLowercase(userinput) == "kill myself with firearm" || toLowercase(userinput) == "kill myself with the gun")
        {
            auto firearmIt = find(inventory.begin(), inventory.end(), "firearm");
            if (firearmIt != inventory.end())
            {
                system("cls");
                cout << "You bring the gun up to the side of your head and you pull the trigger hoping to be free from this prison you have found your self in. \nWith the click of the barrel everything turns to black" << endl; 
                cout << "\033[1;31mGAME OVER\033[0m\nEnding 4 of #" << endl << endl;
                cout << "You have completed the Pre-Alpha for '\033[38;5;208mThe Experiment\033[0m' \nThank you for playing!" << endl; 
                cout << "Used path 4 out of 5" << endl;
                exit(0);
            }
            else
            {
                cout << "you do not have an item to do that with" << endl;
            }
        }
        //leaving room
        else if (toLowercase(userinput) == "leave room" || toLowercase(userinput) == "walk through door" || toLowercase(userinput) == "exit room" || toLowercase(userinput) == "go to next room" || toLowercase(userinput) == "leave the room" || toLowercase(userinput) == "exit the room" || toLowercase(userinput) == "go to the next room" || toLowercase(userinput) == "go through the door" || toLowercase(userinput) == "leave")
        {
            if (dooropen) 
            { 
                nextroom = true;
            }
            else
            {
                cout << "The door is in the way" << endl; 
            }
        }
        else
        {
            cout << "Inviald input please try again" << endl;
        }


    } while (!nextroom);
    //next room
    if (nextroom)
    {
        roomthree(inventory);

    }
}
//chess room
void roomthree(vector<string>& inventory)
{
    system("cls");
    bool nextroom = false;
    bool dooropen = false;
    bool puzzlesolved = false;
    bool attable = false;
    bool mandead = false;
    int endingNumber = 0; 
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 100);

    string userinput;
    cout << "room three" << endl;

    do
    {

        cout << "What would you like to do: ";
        getline(cin, userinput);
        userinput = trim(userinput);

        //looking
        if (toLowercase(userinput) == "look" || toLowercase(userinput) == "glace" || toLowercase(userinput) == "take a look around" || toLowercase(userinput) == "take a look" || toLowercase(userinput) == "look room" || toLowercase(userinput) == "view room" || toLowercase(userinput) == "view the room" || toLowercase(userinput) == "look at the room" || toLowercase(userinput) == "look around" || toLowercase(userinput) == "look around the room")
        {
            cout << "you look at room" << endl;
        }
        //inventory
        else if (toLowercase(userinput) == "inventory" || toLowercase(userinput) == "view inventory" || toLowercase(userinput) == "check inventory")
        {
            if (!inventory.empty())
            {
                cout << "Inventory: ";
                for (const string& item : inventory)
                {
                    cout << item << "| ";
                }
                cout << endl;
            }
            else
            {
                cout << "Inventory is empty." << endl;
            }
        }
        //talking
        else if (toLowercase(userinput) == "talk to guy" || toLowercase(userinput) == "speak to man" || toLowercase(userinput) == "converstate with man" || toLowercase(userinput) == "talk to the guy" || toLowercase(userinput) == "speak to the man" || toLowercase(userinput) == "talk" || toLowercase(userinput) == "talk to the man" || toLowercase(userinput) == "speak")
        {
            cout << "you talk to the guy" << endl;
        }
        //siting
        else if (toLowercase(userinput) == "sit with man" || toLowercase(userinput) == "play chess" || toLowercase(userinput) == "sit in the chair" || toLowercase(userinput) == "sit down" || toLowercase(userinput) == "sit at the table" || toLowercase(userinput) == "play chess with the man" || toLowercase(userinput) == "sit with the man" || toLowercase(userinput) == "play chess with him" || toLowercase(userinput) == "play chess with him" || toLowercase(userinput) == "sit")
        {
            if (!puzzlesolved)
            {
                attable = true;
                cout << "You sit down in front of the quite man and get ready to play chess" << endl;
                do
                {
                    int randomNumber = distribution(generator);
                    cout << "You sit in front of the chess board, what would you like to do now:" << endl;
                    getline(cin, userinput);
                   
                    userinput = trim(userinput);
                    if (toLowercase(userinput) == "look" || toLowercase(userinput) == "glace" || toLowercase(userinput) == "take a look around" || toLowercase(userinput) == "take a look" || toLowercase(userinput) == "look room" || toLowercase(userinput) == "view room" || toLowercase(userinput) == "view the room" || toLowercase(userinput) == "look at the room" || toLowercase(userinput) == "look around" || toLowercase(userinput) == "look around the room")
                    {
                        cout << "As you sit in front of the table before you lies a chess board with a soild metal playing field. \nEach piece is made out of a thick wood that is coat in boat a black and white paint with the white pieces being infront of you and the black being in front of him \nThe chairs and the table seem to be made out of the same wood matieral as the pieces only difference being that the table and chairs are bolted to the ground and seem unable to be moved" << endl;
                    }
                    else if (toLowercase(userinput) == "give up" || toLowercase(userinput) == "knock over king" || toLowercase(userinput) == "surrender game" || toLowercase(userinput) == "surrender" || toLowercase(userinput) == "forfeit" || toLowercase(userinput) == "forfeit the game" || toLowercase(userinput) == "forfeit chess")
                    {
                        cout << "You knock over your king in as a sign of surrender for you are no match to best this chess player. \nUpon your king hitting the table you hear a loud click echo through out the room \nfollowing the click you stand up out of your seat" << endl;
                        puzzlesolved = true; 
                        attable = false; 
                        dooropen = true;
                        endingNumber = 3; 
                        
                        
                    }
                    else if (toLowercase(userinput) == "play chess" || toLowercase(userinput) == "move pawn" || toLowercase(userinput) == "move piece" || toLowercase(userinput) == "start chess" || toLowercase(userinput) == "move knight" || toLowercase(userinput) == "move bishop" || toLowercase(userinput) == "move rook" || toLowercase(userinput) == "begin chess game" || toLowercase(userinput) == "play")
                    {
                        if (randomNumber == 1)
                        {
                            system("cls");
                            cout << "through sheer force of will and dumb luck you found a way to beat the man in chess. Upon doing so you hear a loud click echo through out the room. \nYou proceed to stand up out of the chair" << endl;
                            puzzlesolved = true;
                            attable = false;
                            dooropen = true;
                            endingNumber = 1;
                            
                        }
                        else
                        {
                            system("cls");
                            cout << "With little to no effort it seems the man defeats you in chess" << endl;
                        }

                    }
                    else if (toLowercase(userinput) == "eat his king")
                    {
                        system("cls");
                        cout << "In a turn of events that the slient man surely wasnt expecting you reach over the chess board and you swallow his king in one gulp. \nYou start coughing (having just ate a whole chess piece will do that to ya) and as you do you hear a loud click echo through the room \nYou stand up out of your chair." << endl;
                        puzzlesolved = true;
                        attable = false;
                        dooropen = true;
                        endingNumber = 2; 
                        
                    }
                    else if (toLowercase(userinput) == "stand up" || toLowercase(userinput) == "leave the table" || toLowercase(userinput) == "leave table" || toLowercase(userinput) == "walk away from the table" || toLowercase(userinput) == "get out of the chair" || toLowercase(userinput) == "get out of chair")
                    {
                        cout << "you stand from out of your chair back into the middle of the room" << endl;
                        attable = false;
                        
                    }
                    else if (toLowercase(userinput) == "shoot man" || toLowercase(userinput) == "kill man" || toLowercase(userinput) == "use firearm on man" || toLowercase(userinput) == "shoot the man with the gun" || toLowercase(userinput) == "shoot the guy" || toLowercase(userinput) == "shoot chess player")
                    {
                        if (!mandead) 
                        {
                       
                            auto firearmIt = find(inventory.begin(), inventory.end(), "firearm");
                            if (firearmIt != inventory.end())
                            {
                                system("cls");
                                cout << "You pull out your newly aquired firearm and you point it stright at the mute chess player, even when faced with death the man does not losen his gaze or even flitch. \nYou close your eyes and pull the trigger and with a click of the barrel the bullet is fired stright into the forehead of the defenseless man\nWhen you open your eyes you see that the gun most not have been in very good shape for after fireing it the barrel is complete destoryed and is now in a state of non use" << endl;
                                cout << "You also notice that the now broken gun is newly splattered with corse red blood stains \nLooking up from the gun you see the chess man is now laying on his side lifeless with slowly growing pool of blood around him \nYou stand up from the table." << endl;
                                inventory.erase(firearmIt);
                                inventory.push_back("Broken Blood Stained Firearm");
                                puzzlesolved = true;
                                attable = false;
                                dooropen = true;
                                mandead = true;
                                endingNumber = 5;
                                cout << "You hear a loud click echo through out the room" << endl;
                                

                            }
                            else
                            {
                                cout << "you dont have that item in your inventory" << endl;
                            }
                        }
                        else
                        {
                            cout << "You have already killed him" << endl; 
                        }
                    }
                    
                } while (attable);
            }
            else if (mandead)
            {
                cout << "How do you expect to play chess with a dead man" << endl;
            }
            else
            {
                cout << "There is no need to play anymore" << endl;
            }
        }
        //door
        else if (toLowercase(userinput) == "door" || toLowercase(userinput) == "go to door" || toLowercase(userinput) == "try to open the door" || toLowercase(userinput) == "look at the door" || toLowercase(userinput) == "inspect the door" || toLowercase(userinput) == "go to the door" || toLowercase(userinput) == "go door" || toLowercase(userinput) == "open door" || toLowercase(userinput) == "open the door" || toLowercase(userinput) == "try door")
        {
            system("cls");
            if (!dooropen)
            {
                cout << "You approach the metal door but unlike before the door does not open and instead stays shut tight. \nThere must be another way to open it" << endl; 
            }
            else
            {
                cout << "You see now that the door is open and you are free to move through it" << endl;
            }
        }
        //self harm
        else if (toLowercase(userinput) == "use gun on self" || toLowercase(userinput) == "kill myself with gun" || toLowercase(userinput) == "shoot myself" || toLowercase(userinput) == "use firearm on self" || toLowercase(userinput) == "kill myself with firearm" || toLowercase(userinput) == "kill myself with the gun")
        {
            auto firearmIt = find(inventory.begin(), inventory.end(), "firearm");
            if (firearmIt != inventory.end())
            {
                system("cls");
                cout << "You bring the gun up to the side of your head and you pull the trigger hoping to be free from this prison you have found your self in. \nWith the click of the barrel everything turns to black" << endl;
                cout << "\033[1;31mGAME OVER\033[0m\nEnding 4 of #" << endl << endl;
                endingNumber = 4;
                cout << "You have completed the Beta for '\033[38;5;208mThe Experiment\033[0m' \nThank you for playing!" << endl;
                cout << "Used path " << endingNumber << "out of 5" << endl;
                exit(0);
            }
            else
            {
                cout << "you do not have an item to do that with" << endl;
            }
        }
        //killing man
        else if (toLowercase(userinput) == "shoot man" || toLowercase(userinput) == "kill man" || toLowercase(userinput) == "use firearm on man" || toLowercase(userinput) == "shoot the man with the gun" || toLowercase(userinput) == "shoot the guy" || toLowercase(userinput) == "shoot chess player" || toLowercase(userinput) == "shoot the man" || toLowercase(userinput) == "kill the man")
        {
            if (!mandead)
            {

                auto firearmIt = find(inventory.begin(), inventory.end(), "firearm");
                if (firearmIt != inventory.end())
                {
                    system("cls");
                    cout << "You pull out your newly aquired firearm and you point it stright at the mute chess player, even when faced with death the man does not losen his gaze or even flitch. \nYou close your eyes and pull the trigger and with a click of the barrel the bullet is fired stright into the forehead of the defenseless man\nWhen you open your eyes you see that the gun most not have been in very good shape for after fireing it the barrel is complete destoryed and is now in a state of non use" << endl;
                    cout << "You also notice that the now broken gun is newly splattered with corse red blood stains \nLooking up from the gun you see the chess man is now laying on his side lifeless with slowly growing pool of blood around him." << endl;
                    inventory.erase(firearmIt); 
                    inventory.push_back("Broken Blood Stained Firearm"); 
                    puzzlesolved = true; 
                    dooropen = true; 
                    mandead = true; 
                    endingNumber = 5;
                    cout << "You hear a loud click echo through out the room" << endl; 

                }
                else
                {
                    cout << "you dont have that item in your inventory" << endl; 
                }
            }
            else
            {
                cout << "You have already killed him" << endl; 
            }
        }
        //leaving room
        else if (toLowercase(userinput) == "leave room" || toLowercase(userinput) == "walk through door" || toLowercase(userinput) == "exit room" || toLowercase(userinput) == "go to next room" || toLowercase(userinput) == "leave the room" || toLowercase(userinput) == "exit the room" || toLowercase(userinput) == "go to the next room" || toLowercase(userinput) == "go through the door" || toLowercase(userinput) == "leave" || toLowercase(userinput) == "walk through the door")
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
        else
        {
            cout << "Invaild Input" << endl;
        }
    } while (!nextroom);

    if (nextroom)
    {
        system("cls");
        cout << "You have beaten the Pre-Alpha for '\033[38;5;208mThe Experiment\033[0m' \nThank you for playing!" << endl; 
        cout << "Used path " << endingNumber << " out of 5" << endl; 
        exit(0);   
    }
}
