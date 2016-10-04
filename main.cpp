#include <iostream>
using namespace std;
double sum = 0;

void showMenu();
void showProducts();
void showPrices();
void buyProducts();
void payAndPrint();


int main()
{
    int choice = 0;
    bool quit = false;
    //Alert if an invalid choice is made
    while(quit == false)
    {
        showMenu();
        cin >> choice;


        //Switch case for each choice
        switch (choice)
        {
            case 1:
                showProducts();
                break;
            case 2:
                showPrices();
                break;
            case 3:
                buyProducts();
                break;
            case 4:
                payAndPrint();
                break;
            case 5:
                cout << "Thank you for shopping at Shopsmart vending machines, have a great day!\n";
                quit = true;
                break;
            default:
                cout << "\aInvalid Choice\n";
        }
    }

    return 0;
}

/*************************************************************************
Name            :   showProducts
Arguments       :   No Arguments
Returns         :   No Return
PreCondition    :   None
PostCondition   :   This function will print to screen the products
**********************************************************************/

void showProducts()
{
    cout <<     "***************************************************\n"
        <<      "**********YOU HAVE SELECTED SHOW PRODUCTS**********\n"
        <<      "***************************************************\n\n"
        <<      "   1. Pepsi bottle\n"
        <<      "\t  .=.\n"
        <<      "\t  } {\n"
        <<      "\t .' '.\n"
        <<      "\t/     \\\n"
        <<      "\t;'---';\n"
        <<      "\t|PEPSI|\n"
        <<      "\t| .-. |\n"
        <<      "\t| '-' |\n"
        <<      "\t|'---'|\n"
        <<      "\t'._._.'\n\n\n"

        << "   2. Candy\n"
        <<      "   ___      .-\"\"-.      ___\n"
        <<      "   \\  \"-.  /      \\  .-\"  /\n"
        <<      "         > -=.\\/        \\/.=- <\n"
        <<      "         > -=\'/\\        /\\\'=- <\n"
        <<      "        /__.-'  \\      /  '-.__\\\n"
        <<      "                 \'-..-\'\n\n\n"

        << "   3. Ice Cream\n"
        <<      "\t     ()\n"
        <<      "\t    (__)\n"
        <<      "\t   (____)\n"
        <<      "\t  (______)\n"
        <<      "\t (________)\n"
        <<      "\t(__________)\n"
        <<      "\t \\/\\/\\/\\/\\/\n"
        <<      "\t  \\/\\/\\/\\/\n"
        <<      "\t   \\/\\/\\/\n"
        <<      "\t    \\/\\/\n"
        <<      "\t     \\/\n\n\n";
}


/******************************************************************
Name            :   showPrices
Arguments       :   No Arguments
Returns         :   No Return
Precondition    :   None
PostCondition   :   This function will print to screen the prices
*****************************************************************/
void showPrices()
{
    cout <<     "***************************************************\n"
        <<      "*********YOU HAVE SELECTED TO SHOW PRICES**********\n"
        <<      "***************************************************\n\n"
        <<      "\t 1. Pepsi bottle \t$1.75\n"
        <<      "\t 2. Candy \t\t$0.50\n"
        <<      "\t 3. Ice Cream \t\t$2.50\n\n";
}

/******************************************************************
Name            :   buyProducts
Arguments       :   double pepsi, candy, icecream
                    int products
                    char more
Returns         :   sum
PreCondition    :   None
PostCondition   :   This function will sum the cost of all items purchased
*******************************************************************/
void buyProducts()
{
    double pepsi = 1.75, candy = .50, iceCream = 2.50;
    int product;
    char more = 'y';

    cout <<     "**************************************************\n"
        <<      "**********YOU HAVE SELECTED BUY PRODUCTS**********\n"
        <<      "**************************************************\n\n";

    //Will keep running loop if Y or y is selected at the end for extra items
    do
    {
        cout << "Please enter:\n"
            <<  "\t1. For Pepsi Bottle\n"
            <<  "\t2. For Candy\n"
            <<  "\t3. For Ice Cream\n\n";

        cin >> product;
        //Switch to let the user decide what product the user wants to purchase
        switch (product)
        {
            case 1:
                cout << "Great! The machine added a Pepsi Bottle to your cart.\n";
                sum += pepsi;
                cout << "Would you like to have another transaction: ";
                break;
            case 2:
                cout << "Great! The machine added a candy to your cart.\n";
                sum += candy;
                cout << "Would you like to have another transaction: ";
                break;
            case 3:
                cout << "Great! The machine added ice cream to your cart.\n";
                sum += iceCream;
                cout << "Would you like to have another transaction: ";
                break;
            default:
                cout << "\aSorry wrong choice; please enter 'Y' or'N'. Would you like to add items to your cart? ";
        }

        cin >> more;
        //While the answer is not yes or no, it will keep asking to user to enter a valid choice
        while (more != 'Y' && more != 'y' && more != 'n' && more != 'N')
        {
            cout << "\aInvalid Choice; please enter 'Y' or 'N'. Would you like to add items to your cart? ";
            cin >> more;
        }
    }while(more == 'Y' || more == 'y');

    cout << "Thank you for adding more items on your cart.";
}


/********************************************************************
Name            :   payAndPrint
Arguments       :   double payment
Returns         :   No return
PreCondition    :   Will use the sum from the result of buyProducts
PostCondition   :   This function will calculate how much the user pays
                    and what the users change will be or if the user hasn't
                    paid enough and display the final result.
*********************************************************************/
void payAndPrint()
{
    double payment = 0.0;

    cout << "***********************************************************\n";
    cout << "**********YOU HAVE SELECTED PAY AND PRINT RECEIPT**********\n";
    cout << "***********************************************************\n\n";

    cout << "Your total is $" << sum << ", please enter the money value now "
        <<  "(if negative number you will go the previous menu): ";
    //Magic formula to set the result to currency precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cin >> payment;

    //If payment is not negative
    if(payment >= 0)
    {
        //If payment is positive but less than the sum
        while (payment >= 0 && payment < sum)
        {
            cout << "That is not enough, your total is $" << sum << ", please enter"
                <<  " the money value now (if negative number you will go to  the "
                <<  "previous menu): ";
            cin >> payment;
        }
        //If payment is greater than the sum
        if (payment >= sum)
        {
            cout << "You entered\t\t$" << payment << endl;
            cout << "Your total\t\t$" << sum << endl;
            cout << "Your remainder\t\t$" << payment - sum << endl;
            cout << "\n\nPlease remember to pick your change and your items. Thank you.\n\n";
        }
    }
}


/************************************************************************
Name            :   showMenu
Arguments       :   No Arguments
Returns         :   No Return
Precondition    :   None
PostCondition   :   This function  will print to screen the menu
************************************************************************/

void showMenu()
{
    cout << "\n======================================\n"
        <<  "Please choose from the following menu:\n"
        <<  "======================================\n\n"
        <<  "\t 1. Show Products\n"
        <<  "\t 2. Show Prices\n"
        <<  "\t 3. Buy Products\n"
        <<  "\t 4. Pay and Print receipt\n"
        <<  "\t 5. Quit\n";
}
