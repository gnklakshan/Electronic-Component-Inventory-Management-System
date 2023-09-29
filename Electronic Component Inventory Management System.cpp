
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

// creating item structure
struct Item
{
    float scale;
    string measuringUnit;
    int avaliableQuantity;
    float unitPrice;
    Item *nextItem;
};

// creating type structure
struct Type
{
    string name;
    Type *nextType;
    Item *itemHead;
};

// global head
Type *head = NULL;
Type *temp_type = NULL;
// Item *temp_pre = NULL;
// Item *temp_item = NULL;
int counter = 0;    // line counter

//FUNCTIONS DECLERATIONS****************************************************************

void toUpperCase(string &str);
void stringToArray(string str, string *arr);
void setArrayToNull(string *ptr, int x);
bool isPositiveNumericalValue(const string &str);
bool isPositiveNumericalInteger(const string &str);
void create(string name1);
void add(string word, float scale1, string measuringUnit1, int avaliableQuantity1, float unitPrice1);
void display(string word);
void setPrice(string type1, float scale1, string unit1, float newPrice);
void sell(string operation, string type, float scale, string unit, int quantity);
int search(string type, float scale, string unit, bool choice);
void deleteitem(string type, float scale, string unit);
void sort(string type, string choice);



int main(int argv, char *argc[])
{
    // Declare variables
    ifstream File;   // Create File Object to read the file
    string fileLine; // String variable to hold a line of text from the file
    const int size = 10;
    string arr[size];
    // check whether there are any input parameters to the programme
    // when it is launched
    if (argv < 2)
    {
        // no arguments other than the programme name is provided
        // so, no file name is provided as parameter to the program
        cerr << "Error: No input file name is provided" << endl;
        return -1;
    }
    // open the file
    File.open(argc[1], ios::in); // file name and file stream type

    cout << "_________________________________________________________________________________________" << endl;
    // print the content to the console
    while (getline(File, fileLine))
    {
        cout<<fileLine<<endl;
        counter++;
        stringToArray(fileLine, arr);
        if (arr[0] == "CREATE")
        {
            create(arr[1]);
        }
        else if (arr[0] == "ADD")
        {
            if (isPositiveNumericalValue(arr[2]) && isPositiveNumericalValue(arr[5]) && isPositiveNumericalInteger(arr[4]))
            {
                add(arr[1], stof(arr[2]), arr[3], stoi(arr[4]), stof(arr[5]));
            }
            else
            {
                cout << "ERROR! ...There is a error in the line of txt: " << counter << endl;
                cout << "Scale, Unit price and quantity must be numerical positive values. Also quantity should be a positive integer." << endl;
            }
        }

        else if (arr[0] == "DISPLAY")
        {
            cout << "_________________________________________________________________________________________" << endl;
            cout << "* Dispaly Function called : " << endl;
            cout << "_________________________________________________________________________________________\n"
                 << endl;

            display(arr[1]);
            cout << endl
                 << endl;
        }
        else if (arr[0] == "SETPRICE")
        {
            cout << "_________________________________________________________________________________________" << endl;
            cout << "* Set price Function called : " << endl;
            cout << "_________________________________________________________________________________________\n"
                 << endl;

            if (isPositiveNumericalValue(arr[2]) && isPositiveNumericalValue(arr[4]))
            {
                setPrice(arr[1], stof(arr[2]), arr[3], stof(arr[4]));
            }
            else
            {
                cout << "ERROR! ...There is a error in the line of txt: " << counter << endl;
                cout << "Scale and new price must be positive numerical values" << endl;
            }
            cout << endl
                 << endl;
        }
        else if (arr[0] == "SELL" || arr[0] == "BUY")
        {
            cout << "_________________________________________________________________________________________" << endl;
            cout << "* Sell / Buy Function called : " << endl;
            cout << "_________________________________________________________________________________________" << endl;

            if (isPositiveNumericalValue(arr[2]) && isPositiveNumericalInteger(arr[4]))
            {
                sell(arr[0], arr[1], stof(arr[2]), arr[3], stoi(arr[4]));
            }

            else
            {
                cout << "ERROR! ...There is a error in the line of txt: " << counter << endl;
                cout << "Scale must be positive numerical integer and quantity must be a positive integer." << endl;
            }

            cout << endl
                 << endl;
        }
        else if (arr[0] == "SEARCH")
        {
            cout << "_________________________________________________________________________________________" << endl;
            cout << "* Search Function called : " << endl;
            cout << "_________________________________________________________________________________________\n"
                 << endl;
            if (isPositiveNumericalValue(arr[2]))
            {
                search(arr[1], stof(arr[2]), arr[3], 1);
            }
            else
            {
                cout << "ERROR! ...There is a error in the line of txt: " << counter << endl;
                cout << "Scale must be positive numerical integer" << endl;
            }
            cout << endl
                 << endl;
        }
        else if (arr[0] == "DELETE")
        {
            cout << "_________________________________________________________________________________________" << endl;
            cout << "* Delete item Function called : " << endl;
            cout << "_________________________________________________________________________________________\n"
                 << endl;

            if (isPositiveNumericalValue(arr[2]))
            {
                deleteitem(arr[1], stof(arr[2]), arr[3]);
            }
            else
            {
                cout << "ERROR! ...There is a error in the line of txt: " << counter << endl;
                cout << "Scale must be positive numerical integer" << endl;
            }
            cout << endl
                 << endl;
        }
        else if (arr[0] == "SORT")
        {
            cout << "_________________________________________________________________________________________" << endl;
            cout << "* Sort Function called : " << endl;
            cout << "_________________________________________________________________________________________" << endl;
            sort(arr[1], arr[2]);
            if (arr[2] == "ASC")
                cout << ">> Items sorted in ascending order : " << endl;
            else
                cout << ">> Items sorted in descending order : " << endl;
            cout << endl;
        }
        else if (arr[0] == "EXIT")
        {
            cout << endl;
            cout << "----------------------------- EXIT PROGRAM------------------------------------------------" << endl;
            exit(0);
        }
        else 
        {
            if(arr[0].empty()==0)
            {
                cout << endl;
                cout << "INVALID COMMAND : " <<arr[0]<< endl;
            }
            
        }
        setArrayToNull(arr, 10);
    }

    cout << "_________________________________________________________________________________________" << endl;
    // close the file
    File.close();
    return 0;
}

//FUNCTION DEFINITIONS********************************************************************************************

// to convert uppercase
void toUpperCase(string &str)
{
    for (char &c : str)
    {
        c = toupper(c);
    }
}

// line to array
void stringToArray(string str, string *arr)
{
    toUpperCase(str);
    istringstream iss(str);
    string word;
    int i = 0;
    while (iss >> word)
    {

        arr[i] = word;
        i++;
    }
}

// A function to put elements of wordsOfALine array to NULL
void setArrayToNull(string *ptr, int x)
{
    for (int i = 0; i < x; i++)
    {
        ptr[i] = "";
    }
}

// ispositivenumericalvalue
bool isPositiveNumericalValue(const string &str)
{
    istringstream iss(str);
    float number;
    if (iss >> number)
    {
        return number > 0;
    }
    return false;
}

// ispositivenumericalinteger
bool isPositiveNumericalInteger(const string &str)
{
    istringstream iss(str);
    float number;
    if (iss >> number)
    {
        if (fmod(number, 1) == 0 && number > 0)
        {
            return true; // Number is a positive numerical integer
        }
    }
    return false; // Not a positive numerical integer
}

// creating type of electronic component
void create(string name1)
{
    Type *temp = new Type();
    temp->name = name1;
    temp->itemHead = NULL;
    temp->nextType = nullptr; // Set the nextType of the new node to nullptr

    if (head == nullptr)
    {
        // If the list is empty (head is nullptr), make the new node the head
        head = temp;
    }
    else
    {
        // Traverse the list until the last node
        Type *current = head;
        while (current->nextType != nullptr)
        {
            current = current->nextType;
        }
        // Assign the new node as the next node of the last node
        current->nextType = temp;
    }
}

// adding item to specific type
void add(string word, float scale1, string measuringUnit1, int avaliableQuantity1, float unitPrice1)
{
    bool type_created = false;
    Type *head1 = head;

    Item *temp = new Item();
    temp->scale = scale1;
    temp->measuringUnit = measuringUnit1;
    temp->avaliableQuantity = avaliableQuantity1;
    temp->unitPrice = unitPrice1;
    temp->nextItem = NULL;
    while (head1 != NULL)
    {
        if (head1->name == word)
        {
            type_created = true;
            if (head1->itemHead == nullptr)
            {
                head1->itemHead = temp;
            }
            else
            {
                Item *head5 = head1->itemHead;
                while (head5->nextItem != nullptr)
                {
                    head5 = head5->nextItem;
                }
                head5->nextItem = temp;
            }
        }
        head1 = head1->nextType;
    }
    if (type_created == false)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "ERROR : TYPE NOT FOUND " << endl;
        cout << "ITEM NOT ADDED ! FIRST CREATE TYPE [ " << word << " ]\n"  << endl;
    }
}

// display function
void display(string word)
{

    Type *head7 = head;
    while (head7 != NULL)
    {
        if (head7->name == word)
        {
            cout << setw(50) << "An Inventory of Electronic Components \n"
                 << endl;

            cout << setw(14) << "ITEM TYPE : " << word << endl;
            cout << "---------------------------------------------------------------" << endl;
            Item *head6 = head7->itemHead;
            if (head6 == NULL)
            {
                cout << "There are no items in the type called: " << word << endl;
                return;
            }
            else
            {
                cout << "|" << setw(8) << "SCALE" << setw(16) << "UNIT" << setw(14) << "QUANTITY" << setw(21) << "UNIT PRICE" << setw(4) << "|";
                cout << "\n---------------------------------------------------------------" << endl;
                while (head6 != NULL)
                {
                    cout << "|" << setw(5) << head6->scale << setw(18) << head6->measuringUnit << setw(12) << head6->avaliableQuantity << setw(20) << head6->unitPrice << setw(8) << "|";
                    cout << endl;
                    head6 = head6->nextItem;
                }
                cout << "---------------------------------------------------------------" << endl;
            }
            return;
        }
        head7 = head7->nextType;
    }
    cout << "There is no type called: " << word << endl;
}

// setprice funtion
void setPrice(string type1, float scale1, string unit1, float newPrice)
{
    Type *head7 = head;
    while (head7 != NULL)
    {
        if (head7->name == type1)
        {
            Item *head6 = head7->itemHead;
            while (head6 != NULL)
            {
                if (head6->scale == scale1 && head6->measuringUnit == unit1)
                {
                    float oldPrice = head6->unitPrice;
                    head6->unitPrice = newPrice;
                    cout << ">>Set Price of " << type1 << " " << scale1 << " " << unit1 << " is set to " << newPrice << " "
                         << "from " << oldPrice << endl
                         << endl;

                    return;
                }
                head6 = head6->nextItem;
            }
            cout << "There is no item called: " << type1 << " " << scale1 << " " << unit1 << " in the type of " << type1 << endl;
            return;
        }
        head7 = head7->nextType;
    }
    cout << "There is no type called: " << type1 << endl;
}

//Function for sell and buy operation
void sell(string operation, string type, float scale, string unit, int quantity)
{
    bool success = false;
    Type *Head = head;
    while (Head != NULL)
    {
        if (Head->name == type)
        {
            Item *item = Head->itemHead;
            while (item != NULL)
            {
                if (item->scale == scale && item->measuringUnit == unit)
                {
                    success = true;
                    if (operation == "SELL")
                    {
                        cout << "Selling Mode :\n"
                             << endl;
                        if (item->avaliableQuantity >= quantity)
                        {
                            item->avaliableQuantity = item->avaliableQuantity - quantity;
                            cout << "Sold " << quantity << " of " << scale << " " << unit << " " << type << endl;
                        }
                        else
                        {
                            cout << ">> THis opreation cannot be perform ! <<" << endl;
                            cout << "-Available quanyity is lower than request quantity." << endl;
                            ;
                            cout << "-Avaliable quanyity is: " << item->avaliableQuantity << endl;
                            cout << "-Requested quanyity is: " << quantity;
                        }
                    }
                    else if (operation == "BUY")
                    {
                        cout << "BUY Mode :\n"
                             << endl;
                        item->avaliableQuantity = item->avaliableQuantity + quantity;
                        cout << "Brought " << quantity << " of " << scale << " " << unit << " " << type << endl;
                    }
                }
                item = item->nextItem;
            }
            cout << endl;
            if (success == false)
            {
                cout << ">> THis opreation cannot be perform <<" << endl;
                cout << "- There is no item called: " << type << " " << scale << " " << unit << " in the type of " << type << endl;
                cout << "- To buy a new item, please use add function with unitprice." << endl;
            }
        }
        Head = Head->nextType;
    }
}

//Search function
int search(string type, float scale, string unit, bool choice)
{

    Type *Head = head;
    Item *pre = Head->itemHead;
    bool success = false;

    while (Head != NULL)
    {
        if (Head->name == type)
        {
            Item *item = Head->itemHead;

            while (item != NULL)
            {
                if (item->scale == scale && item->measuringUnit == unit)
                {
                    success = true;
                    
                        cout << "* Item is in the list\n " << endl;
                        // display(type);
                        cout << "Type" << setw(40) << ": " << type << endl;
                        cout << "Scale" << setw(39) << ": " << item->scale << endl;
                        cout << "Measuring Unit" << setw(30) << ": " << item->measuringUnit << endl;
                        cout << "Unit price" << setw(34) << ": " << item->unitPrice << endl;
                        cout << "Available quantity" << setw(26) << ": " << item->avaliableQuantity << endl;
                        return 1;
                   
                }
                pre = item;
                item = item->nextItem;
            }
            if (!success)
                cout << ">> There is no item called: " << type << " " << scale << " " << unit << " in the type of " << type << endl;
        }
        Head = Head->nextType;
    }
}

//Function to delete items 
void deleteitem(string type, float scale, string unit)
{
    Type *Head = head;
    while (Head != NULL)
    {
        if (Head->name == type)
        {
            Item *item_head = Head->itemHead;
            while (item_head != NULL)
            {
                if (item_head->scale == scale && item_head->measuringUnit == unit)
                {
                    Head->itemHead = item_head->nextItem;
                    cout << "<< " << type << " " << scale << " " << unit << " is succussfully deleted from the list of " << type << endl;
                    delete item_head;
                    return;
                }
                if (item_head->nextItem != NULL && item_head->nextItem->scale == scale && item_head->nextItem->measuringUnit == unit)
                {
                    Item *temp = item_head->nextItem;
                    item_head->nextItem = item_head->nextItem->nextItem;
                    cout << "<< " << type << " " << scale << " " << unit << " is succussfully deleted from the list of " << type << endl;
                    delete temp;
                    return;
                }
                item_head = item_head->nextItem;
            }
            cout << "There is no item called: " << type << " " << scale << " " << unit << " to delete" << endl;
            return;
        }
        Head = Head->nextType;
    }
    cout << "There is no item called: " << type << " " << scale << " " << unit << " to delete" << endl;
}

//sortimg function
void sort(string type, string choice)
{
    Type *currentType = head;
    Item *first = NULL;
    Item *i = NULL, *j = NULL;

    float scale;
    string measuringUnit;
    int availableQuantity;
    float unitPrice;

    while (currentType != NULL)
    {
        if (currentType->name == type)
        {
            first = currentType->itemHead;
            break; // Found the desired type, no need to continue searching
        }
        currentType = currentType->nextType;
    }

    i = first;
    while (i != NULL)
    {
        j = i->nextItem;
        while (j != NULL)
        {
            if (i->scale > j->scale && choice == "ASC") // Use ">" for ascending order
            {
                // Swap the values between i and j
                scale = i->scale;
                measuringUnit = i->measuringUnit;
                availableQuantity = i->avaliableQuantity;
                unitPrice = i->unitPrice;

                i->scale = j->scale;
                i->measuringUnit = j->measuringUnit;
                i->avaliableQuantity = j->avaliableQuantity;
                i->unitPrice = j->unitPrice;

                j->scale = scale;
                j->measuringUnit = measuringUnit;
                j->avaliableQuantity = availableQuantity;
                j->unitPrice = unitPrice;
            }
            else if (i->scale < j->scale && choice == "DESC") // Use ">" for descending order
            {
                // Swap the values between i and j
                scale = i->scale;
                measuringUnit = i->measuringUnit;
                availableQuantity = i->avaliableQuantity;
                unitPrice = i->unitPrice;

                i->scale = j->scale;
                i->measuringUnit = j->measuringUnit;
                i->avaliableQuantity = j->avaliableQuantity;
                i->unitPrice = j->unitPrice;

                j->scale = scale;
                j->measuringUnit = measuringUnit;
                j->avaliableQuantity = availableQuantity;
                j->unitPrice = unitPrice;
            }
            j = j->nextItem;
        }
        i = i->nextItem;
    }
}
