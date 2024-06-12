#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to check if the card number is valid using the Luhn algorithm
bool isValidCardNumber(const string& cardNumber) {
    int nDigits = cardNumber.length();
    int sum = 0;
    bool isSecond = false;

    for (int i = nDigits - 1; i >= 0; i--) {
        int d = cardNumber[i] - '0';

        if (isSecond == true)
            d = d * 2;

        sum += d / 10;
        sum += d % 10;

        isSecond = !isSecond;
    }
    return (sum % 10 == 0);
}

// Function to determine the bank based on the card's prefix
string getBankName(const string& cardNumber) {
    unordered_map<string, string> bankPrefixes = {
        {"603799", "MELI"},
        {"589210", "SEPAH"},
        {"627353", "TEJARAT"},
        {"589463", "REFH"},
        {"627381", "EN"},
        {"621986", "SAMAN"},
        {"639346", "PASARGAD"},
        {"627412", "EGHTESAD NOVIN"},
        {"622106", "PARSIAN"},
        {"639607", "SARMAYE"}
        // Add other prefixes here as needed
    };

    string prefix = cardNumber.substr(0, 6);
    if (bankPrefixes.find(prefix) != bankPrefixes.end()) {
        return bankPrefixes[prefix];
    }
    else {
        return "UNKNOWN";
    }
}

// Function to format the card number
string formatCardNumber(const string& cardNumber) {
    return cardNumber.substr(0, 4) + "-" + cardNumber.substr(4, 4) + "-" +
        cardNumber.substr(8, 4) + "-" + cardNumber.substr(12, 4);
}

int main() {
    string cardNumber;

    // Get the card number from the user
    cout << "Please enter your 16-digit card number: ";
    cin >> cardNumber;

    // Check if the card number is 16 digits long
    if (cardNumber.length() != 16) {
        cout << "The card number must be 16 digits." << endl;
        return 1;
    }

    // Check if the card number is valid
    if (!isValidCardNumber(cardNumber)) {
        cout << "The card number is not valid." << endl;
        return 1;
    }

    // Identify the bank
    string bankName = getBankName(cardNumber);

    // Format and display the card information
    cout << "CARD: " << formatCardNumber(cardNumber) << endl;
    cout << "BANK: " << bankName << endl;

    return 0;
}
