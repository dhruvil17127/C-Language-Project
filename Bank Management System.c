#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to store account information
struct Account {
    int accountNumber;
    char name[100];
    float balance;
};

// Array to store the accounts
struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function to create a new account
void createAccount() {
    struct Account newAccount;

    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);

    printf("Enter account holder's name: ");
    getchar();  // to consume the newline character left by previous input
    fgets(newAccount.name, sizeof(newAccount.name), stdin);
    newAccount.name[strcspn(newAccount.name, "\n")] = 0;  // Remove newline character

    printf("Enter initial deposit: ");
    scanf("%f", &newAccount.balance);

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

// Function to display account details
void displayAccount(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to deposit money into an account
void depositMoney(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            float depositAmount;
            printf("Enter deposit amount: ");
            scanf("%f", &depositAmount);
            if (depositAmount > 0) {
                accounts[i].balance += depositAmount;
                printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Invalid deposit amount!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw money from an account
void withdrawMoney(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            float withdrawAmount;
            printf("Enter withdraw amount: ");
            scanf("%f", &withdrawAmount);
            if (withdrawAmount > 0 && withdrawAmount <= accounts[i].balance) {
                accounts[i].balance -= withdrawAmount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Invalid withdraw amount or insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to display all accounts
void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("---------------------------\n");
    }
}

// Main function
int main() {
    int choice, accountNumber;

    while (1) {
        printf("\n--- Banking Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter account number to display: ");
                scanf("%d", &accountNumber);
                displayAccount(accountNumber);
                break;
            case 3:
                printf("Enter account number to deposit money: ");
                scanf("%d", &accountNumber);
                depositMoney(accountNumber);
                break;
            case 4:
                printf("Enter account number to withdraw money: ");
                scanf("%d", &accountNumber);
                withdrawMoney(accountNumber);
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
