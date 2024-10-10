/******************************************************************************
Author: Dylan Pallasigui
Date: 3/3/2023
*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int selectTicketType() {
    // Prompt user to select ticket type and return selection
    int ticketType;
    while (true) {
        cout << "Select a ticket type:" << endl;
        cout << "1. Nosebleed ($5)" << endl;
        cout << "2. Box Seats ($100)" << endl;
        cout << "3. Fifty Yard Line ($50)" << endl;
        cout << "4. Student Section ($10)" << endl;
        cin >> ticketType;
        if (ticketType < 1 || ticketType > 4) {
            cout << "Invalid ticket type. Please try again." << endl;
            exit(0);
        } else {
            return ticketType;
        }
    }    
}

int enterNumTickets() {
    // Prompt user to enter number of tickets and return input
    int numTickets;
    while (true) {
        cout << "How many tickets would you like to purchase?" << endl;
        cin >> numTickets;
        if (numTickets < 1) {
            cout << "Invalid ticket type. Please try again." << endl;
            exit(0);
        } else {
            return numTickets;
        }
    }
}

double calculateCost(int ticketType, int numTickets) {
    // Calculate total cost based on ticket type and number of tickets
    double ticketPrice;
    switch(ticketType) {
        case 1:
            ticketPrice = 5;
            break;
        case 2:
            ticketPrice = 100;
            break;
        case 3:
            ticketPrice = 50;
            break;
        case 4:
            ticketPrice = 10;
            break;
        default:
            cout << "Invalid ticket type selected." << endl;
            return 0;
    }
    // Return total cost
    double totalCost = ticketPrice * numTickets;
    return totalCost;
}

void payByCash(double totalCost, double& change) {
    // Prompt user to enter the amount of cash and calculate change
    // Print the receipt with details of purchase
    double amountPaid;
    while (true) {
        cout << "Enter amount paid: $" << endl;
        cin >> amountPaid;
        // error checking if payment is less than the cost
        if (amountPaid < totalCost) {
            cout << "Insufficient payment. Please try again." << endl;
            exit(0);
        } else {
            change = amountPaid - totalCost;
            break;
        }
    }
}

void payByCreditCard(double totalCost) {
    // Print message that credit card will be billed for purchase
    cout << "Your credit card will be billed for $" << fixed << setprecision(2) << totalCost << endl;
}

string selectPaymentType() {
    // Prompt user to select payment type and return selection
    while (true) {
        string paymentType;
        cout << "Select a payment type (cash or credit):" << endl;
        cin >> paymentType;
        // Error checking if neither cash or credit 
        if (paymentType != "cash" && paymentType != "credit") {
            cout << "Invalid payment type. Please try again." << endl;
        } else {
            return paymentType;
        }
    }    
}

int main() {
    // Initialize variables
    int ticketType, numTickets;
    double totalCost, change;
    int cents, dollars, quarters, dimes, nickels, pennies;
    string paymentType;
    
    // Get ticket type and number of tickets
    ticketType = selectTicketType();
    numTickets = enterNumTickets();

    // Calculate the total cost of ticket and print
    totalCost = calculateCost(ticketType, numTickets);
    cout << "Your total is $" << totalCost << endl;

    // Select payment type and process payment
    paymentType = selectPaymentType();
    if (paymentType == "cash") {
        payByCash(totalCost, change);
        cout << "Change: $" << fixed << setprecision(2) << change << endl;
    } else if (paymentType == "credit") {
        payByCreditCard(totalCost);
    } else {
        cout << "Invalid payment type selected." << endl;
        return 0;
    }

    // Print the receipt
    cout << "-----------------------------" << endl;
    cout << "Ticket type: " << ticketType << endl;
    cout << "Number of tickets: " << numTickets << endl;
    cout << "Total cost: $" << fixed << setprecision(2) << totalCost << endl;
    cout << "Payment type: " << paymentType << endl;
    if (paymentType == "cash") {
        cents = round(change * 100); // convert change to cents
        dollars = cents / 100; // count number of dollars
        cents %= 100; // remove dollars from cents
        quarters = cents / 25; // count number of quarters
        cents %= 25; // remove quarters from cents
        dimes = cents / 10; // count number of dimes
        cents %= 10; // remove dimes from cents
        nickels = cents / 5; // count number of nickels
        cents %= 5; // remove nickels from cents
        pennies = cents / 1; // count number of pennies
        cents %= 1; // remove nickels from cents
        cout << "Change: $" << fixed << setprecision(2) << change << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Quarters: " << quarters << endl;
        cout << "Dimes: " << dimes << endl;
        cout << "Nickels: " << nickels << endl;
        cout << "Pennies: " << pennies << endl;
    } else {
        
    }
    cout << "-----------------------------" << endl;

    return 0;
}