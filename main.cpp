#include <iostream>
#include <string>
#include <vector>
using namespace std;


void roomone(vector<string>& inventory);
void roomtwo(vector<string>& inventory);
void roomthree(vector<string>& inventory);


int main()
{
    bool gameRunning = true;
    vector<string> inventory;  

    while (gameRunning) 
    {
        cout << "Welcome! Please hit enter to start" << endl;
        string userinput;
        getline(cin, userinput);

        if (userinput == "")
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
    bool nextroom = false;
    string userinput;
    cout << "You are in room one. There is a door in front of you." << endl;
    do
    {
       
        getline(cin, userinput);

        if (userinput == "door")
        {
            cout << "The door opens." << endl;
            nextroom = true;
        }
        else if (userinput == "look")
        {
            cout << "You look around and see a door." << endl;
        }
        else if (userinput == "inventory")
        {
            if (!inventory.empty())
            {
                cout << "Inventory: ";
                for (const string& item : inventory)
                {
                    cout << item << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "Inventory is empty." << endl;
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
    bool nextroom = false;
    string userinput;
    cout << "You are in room two now. In it lies a table with nothing more than a firearm on it. \nBehind the table on the other side of the room lies another door" << endl;

       do 
       {
          
           // Add items to the inventory
           cout << "What would you like to do: ";
           getline(cin, userinput);

           if (userinput == "take firearm")
           {
               inventory.push_back("firearm");
               cout << "You picked up the firearm off the table." << endl;
           }
           else if (userinput == "look room")
           {
               cout << "you see a big empty room with nothing more than a firearm laying on a wooden table in the center of the room. \nbeyond that lays a door" << endl;
               
           }
           else if (userinput == "door")
           {
               cout << "upon apporching the door the loud click you heard once before echos through the room and the door slowly opens \nyou walk though into the next room" << endl; 
               nextroom = true; 
           }
           else if (userinput == "inventory")
           {
               if (!inventory.empty())
               {
                   cout << "Inventory: ";
                   for (const string& item : inventory)
                   {
                       cout << item << ", ";
                   }
                   cout << endl; 
               }
               else
               {
                   cout << "Inventory is empty." << endl;
               }
           }
           else
           {
               cout << "Inviald input please try again" << endl;
           }

          
       } while (!nextroom); 

       if (nextroom)
       {
            //roomthree(inventory);
           cout << "the end" << endl;
       }
}
