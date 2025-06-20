#include <iostream>
#include <string>
#include <sstream>
#include <limits> // for numeric_limits
#include <bits/stdc++.h>
#include <windows.h>
#include "queue1.h"
#include "stackme.h"
using namespace std;

int search(int);
int display();
string check(int); //   for checking quantity

// Creating Node
struct node
{
    int ID;
    string proName;  // PRODUCT NAME
    double prePrice; // PRODUCT PRICE
    int quantity;    // PRODUCT QUANTITY
    struct node *next;
};

struct node *head = NULL;

// ADD PRODUCTS
void beg()
{
    system("cls");
    int id, quant; // quant for quantity
    string name;
    double pre;                // pre for price
    struct node *t = new node; // A pointer to a new node structure (the product being added).
    struct node *p = head;     // A pointer used to traverse the linked list (starts at the head of the list).

    // Input and validation for product ID
    cout << "\t\t\tEnter product ID: ";
    while (!(cin >> id) || id <= 0)
    {
        cout << "Invalid input. Please enter a positive product ID: ";
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
    t->ID = id;

    // Input for product name
    cout << "\t\t\tEnter product Name: ";
    cin >> name;
    t->proName = name;

    // Input and validation for product price
    cout << "\t\t\tEnter product price: ";
    while (!(cin >> pre) || pre <= 0)
    {
        cout << "Invalid input. Please enter a positive price: ";
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
    t->prePrice = pre;

    // Input and validation for product quantity
    cout << "\t\t\tEnter product quantity: ";
    while (!(cin >> quant) || quant <= 0)
    {
        cout << "Invalid input. Please enter a positive quantity: ";
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }
    t->quantity = quant;

    // Insert the product into the linked list
    if (head == NULL)
    {
        t->next = head;
        head = t;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
        t->next = NULL;
    }

    system("cls");
    cout << "\n\n\t\t\t\tThis product is Inserted!\n\n\n";
}

// For search item in list
int search(int id)
{
    int count = 1;
    struct node *p = head;

    // Input validation: Ensure the entered ID is a positive integer
    while (id <= 0)
    {
        cout << "Invalid input. Please enter a valid product ID (positive integer): ";
        cin >> id;
    }

    // If the list is empty, return -1 to indicate the item was not found
    if (head == NULL)
    {
        cout << "The product list is empty.\n";
        return -1; // Return -1 indicating the list is empty
    }

    // Search for the product in the linked list
    while (p != NULL)
    {
        if (p->ID == id)
            break;
        else
        {
            count++;
            p = p->next;
        }
    }

    // If the item was not found, return -1 to indicate it's not in the list
    if (p == NULL)
    {
        cout << "Product with ID " << id << " not found.\n";
        return -1; // Return -1 indicating the item was not found
    }

    return count; // Return the position of the item if found
}

int hash(int x, int mod)
{
    return x % mod;
}

// Delete product
void delPro()
{
    system("cls");
    display();

    int id;
    struct node *cur = head;
    struct node *pre = NULL; // Make sure the previous pointer is initialized

    // Validate ID input: Make sure it's a positive integer
    cout << "\n\nEnter ID to delete that product:\n\n";
    while (true)
    {
        cin >> id;
        if (cin.fail() || id <= 0)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid positive integer ID: ";
        }
        else
        {
            break;
        }
    }

    if (head == NULL)
    {
        system("cls");
        cout << "List is empty" << endl;
        return;
    }

    int count = display(); // Count the number of nodes
    int pos = search(id);  // Find position of the item to delete

    if (pos <= count)
    {
        if (cur->ID == id)
        {
            // If the item to be deleted is the first node (head)
            head = cur->next; // Update the head to the next node
            delete cur;       // Delete the current node
            system("cls");
            cout << "\n<<Item is deleted>>\n";
            return;
        }

        // Traverse the list to find the item to delete
        while (cur != NULL && cur->ID != id)
        {
            pre = cur;
            cur = cur->next;
        }

        if (cur != NULL)
        {
            pre->next = cur->next; // Skip the node to delete it
            delete cur;            // Delete the node
            system("cls");
            cout << "\n<<Item is deleted>>\n";
        }
        else
        {
            cout << "\n<<<Item not found>>\n\n";
        }
    }
    else
    {
        cout << "\n<<<Item not found>>\n\n";
    }
}

// Update product details
void modify()
{
    int id;
    double pre; // pre for price
    string pName;
    int nid;
    int nq; // nid for new ID and nq for new quantity

    if (head == NULL)
    {
        system("cls");
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        display();
        cout << "\n\nEnter ID to modify product Name and its price:\n";

        // Validate ID input: Make sure it's a positive integer
        while (true)
        {
            cin >> id;
            if (cin.fail() || id <= 0)
            {
                cin.clear();                                         // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid ID. Please enter a valid positive integer ID: ";
            }
            else
            {
                break;
            }
        }

        struct node *cur = head;
        int pos = 0;
        int count = display(); // for loading the number of nodes
        pos = search(id);      // for checking whether the desired node exists or not

        if (pos <= count)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }

            cout << "\nOld ID : " << cur->ID << endl;
            cout << "Old Name : " << cur->proName << endl;
            cout << "Old Price : " << cur->prePrice << endl;
            cout << "Old Quantity : " << cur->quantity << endl;

            cout << endl
                 << endl;

            // Validate new ID input: Ensure it's a positive integer
            cout << "Enter new ID: ";
            while (true)
            {
                cin >> nid;
                if (cin.fail() || nid <= 0)
                {
                    cin.clear();                                         // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid ID. Please enter a valid positive integer ID: ";
                }
                else
                {
                    break;
                }
            }

            cur->ID = nid;

            // Validate new product name: Ensure it's not empty
            cout << "Enter new Name: ";
            cin.ignore();        // To clear the newline character left by previous input
            getline(cin, pName); // Allow spaces in product name
            while (pName.empty())
            {
                cout << "Name cannot be empty. Please enter a valid product name: ";
                getline(cin, pName);
            }
            cur->proName = pName;

            // Validate new price input: Ensure it's a positive number
            cout << "Enter new Price: ";
            while (true)
            {
                cin >> pre;
                if (cin.fail() || pre <= 0)
                {
                    cin.clear();                                         // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid price. Please enter a valid positive price: ";
                }
                else
                {
                    break;
                }
            }
            cur->prePrice = pre;

            // Validate new quantity input: Ensure it's a non-negative integer
            cout << "Enter new Quantity: ";
            while (true)
            {
                cin >> nq;
                if (cin.fail() || nq < 0)
                {
                    cin.clear();                                         // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid quantity. Please enter a valid non-negative quantity: ";
                }
                else
                {
                    break;
                }
            }
            cur->quantity = nq;
        }
        else
        {
            cout << id << " is <<<Not found>>\n\n";
        }
    }
}

// display function

int display()
{

    int c = 0; // Counter for products
    struct node *p = head;
    cout << "Existing products are:\n";
    cout << "ID" << "\t\t" << "Product Name" << "\t\t" << "Price" << "\t\t" << "Quantity\n";
    cout << "==============================================================================\n";
    while (p != NULL)
    {
        cout << p->ID << "\t\t" << p->proName << "\t\t" << p->prePrice << "\t\t" << check(p->quantity) << "\n";
        p = p->next;
        c++;
    }
    cout << "\nTotal products in our store is: " << c << "\n\n\n";
    return c;
    system("cls");
}

// checking quantity
string check(int quant)

{ //        check function
    int a = quant;
    stringstream ss;
    ss << a;
    string quantity = ss.str();

    if (quant <= 0)
        return "out of stock!";
    else
        return quantity;
}

// Buy function
void buy()
{
    system("cls");
    display(); // Display available items

    string products[20]; // To store names of products bought
    int pay = 0, no, c = 0, price, id, i = 1;

    if (head == NULL)
    {
        cout << "\n<<<<There are no items to buy>>>>\n\n";
    }
    else
    {
        cout << "How many items you want to buy?\n";
        cin >> no;

        int count = display(); // Store number of available items in store

        while (i <= no)
        {
            struct node *cur = head;
            int quant, cho;
        a: // Labels for handling invalid input and retrying
            cout << "Enter the ID of the item you want to buy: ";
            cin >> id;

            if (id == -1)
            {
                system("cls");
                return;
            }

            int pos = search(id); // Search for the item by ID
            if (pos <= count)
            {
                // Item is available in store
                while (cur->ID != id)
                {
                    cur = cur->next;
                }

                cout << "How many quantities do you want: ";
                cin >> quant;

                if (cur->quantity < quant)
                {
                    cout << "\n\n\t\t\t----The Quantity You Entered is not available---" << endl;
                    cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
                    goto a; // Retry for a valid quantity
                }

                products[c] = cur->proName; // Store item name in array
                c++;

                pay = pay + (cur->prePrice * quant);   // Calculate total price
                cur->quantity = cur->quantity - quant; // Update remaining quantity
                i++;
            }
            else
            {
                cout << "\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
            }
        }

        string customer;
        cout << "\n\t\t Enter Your Name: ";
        cin >> customer;

        // Enqueue customer to the queue
        enqueue(customer);

        system("cls");

        // Display the items bought and calculate price
        cout << "\n\n\n\n\t\t\tYou have bought: ";
        for (int i = 0; i < no; i++)
        {
            cout << products[i] << ",";
        }

        // Use bpop to assign a trolly number
        cout << "\nAssigning a trolly number...\n";
        bpop(); // Pops the trolly number from the stack

        price = pay * (0.90); // Apply 10% discount
        cout << "\nOriginal price: " << pay;
        cout << "\nWith 10% discount: " << price << "\nThank you for shopping!\n\n";
    }
}

// Administration Function
void administator()
{
    system("cls");
    string password = "admin123"; // Set the admin password
    string enteredPassword;
    int ch;

    // Ask for password
    cout << "\n\t\tEnter Administrator Password: ";
    cin >> enteredPassword;

    if (enteredPassword != password)
    {
        cout << "\nIncorrect password. Access denied.\n";
        return; // Exit if password is incorrect
    }
    else
    {
    	cout << "\nAccess Granted\n";
	}

    do
    {

        // Displaying the menu options
        cout << "\n\t\t============================================" << endl;
        cout << "\t\t|          Administrator Portal            |" << endl;
        cout << "\t\t============================================" << endl;

        cout << "\n\t\t     1) Add a New Product" << endl;
        cout << "\t\t     2) Display All Products" << endl;
        cout << "\t\t     3) Modify an Existing Product" << endl;
        cout << "\t\t     4) Delete a Particular Product Item" << endl;
        cout << "\t\t     5) View Customers List" << endl;
        cout << "\t\t     6) Remove Customer" << endl;
        cout << "\t\t     0) Back to Main Menu" << endl;

        cout << "\n\t\t============================================" << endl;
        cout << "\t\t     Please enter your choice >>> " << endl;

        cout << "\nEnter Your choice >>>";
        while (!(cin >> ch) || ch < 0 || ch > 6)
        {
            // If input is not an integer or not in the range [0, 6]
            cin.clear();                                         // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
            cout << "Invalid choice. Please enter a number between 0 and 6: ";
        }
        system("cls");

        switch (ch)
        {
        case 1:
            beg();
            break;
        case 2:
            display(); // Display all products without clearing the screen
            break;
        case 3:
            modify();
            break;
        case 4:
            delPro();
            break;
        case 5:
            cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
            displayQueue();
            break;
        case 6:
            cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
            dequeue();
            displayQueue();
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (ch != 0);
}

// Main function
int main()
{
    cout << "\n\t\t===================================================================================================" << endl;
    cout << "\t\t\t\t\t\t\tWELLCOME TO SHOPPING CLUB" << endl;
    cout << "\t\t===================================================================================================" << endl;
    // This loop simulates pushing values, assuming you have a 'push' function in your program
    for (int i = 0; i <= 51; i++)
    {
        push(i);
    }

    int ch = -1; // Initialize the variable with an invalid value to enter the loop

    while (ch != 3)
    {
        cout << "\n\n";
        cout << "\t\t*****************************************\n";
        cout << "\t\t*             Main Menu                 *\n";
        cout << "\t\t*****************************************\n";
        cout << "\t\t*  1) Administrator of Market           *\n";
        cout << "\t\t*  2) Customer                          *\n";
        cout << "\t\t*  3) Exit                              *\n";
        cout << "\t\t*****************************************\n\n";
        cout << "\t\t\n\nEnter Your choice >>>";
        while (!(cin >> ch) || ch < 1 || ch > 3)
        {
            // If input is not an integer or not in the range [1, 3]
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid choice. Please enter a number between 1 and 3: ";
        }

        switch (ch)
        {
        case 1:
            administator(); // Call the administrator function
            break;

        case 2:
            cout << endl
                 << endl;

            buy(); // Call the customer function (assuming bpop is for customer-related actions)
            system("pause");
            break;

        case 3:
            cout << "\n\n\t\t\t\t\tThank You\t\t\t\t";
            break;

        default:
            system("cls");
            break;
        }
    }

    return 0;
}
