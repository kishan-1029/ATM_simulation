#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int account_number;
    char name[100];
    float balance;
    int pin;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Error: Maximum account limit reached.\n");
        return;
    }

    Account a;
    printf("Enter account number: ");
    scanf("%d", &a.account_number);
    printf("Enter account holder name: ");
    scanf(" %[^\n]%*c", a.name);
    printf("Enter initial balance: ");
    scanf("%f", &a.balance);
    printf("Set a 4-digit PIN: ");
    scanf("%d", &a.pin);

    accounts[account_count++] = a;
    printf("Account created successfully.\n");
}

Account* find_account(int account_number) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            return &accounts[i];
        }
    }
    return NULL;
}

int verify_pin(Account* account, int pin) {
    return account->pin == pin;
}

void view_balance() {
    int account_number, pin;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    Account* account = find_account(account_number);
    if (!account) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if (!verify_pin(account, pin)) {
        printf("Error: Incorrect PIN.\n");
        return;
    }

    printf("Current balance: $%.2f\n", account->balance);
}

void deposit_money() {
    int account_number, pin;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    Account* account = find_account(account_number);
    if (!account) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if (!verify_pin(account, pin)) {
        printf("Error: Incorrect PIN.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Error: Invalid amount.\n");
        return;
    }

    account->balance += amount;
    printf("Deposit successful. New balance: $%.2f\n", account->balance);
}

void withdraw_money() {
    int account_number, pin;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    Account* account = find_account(account_number);
    if (!account) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter PIN: ");
    scanf("%d", &pin);

    if (!verify_pin(account, pin)) {
        printf("Error: Incorrect PIN.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0 || amount > account->balance) {
        printf("Error: Invalid amount or insufficient balance.\n");
        return;
    }

    account->balance -= amount;
    printf("Withdrawal successful. New balance: $%.2f\n", account->balance);
}

void change_pin() {
    int account_number, old_pin, new_pin;
    printf("Enter account number: ");
    scanf("%d", &account_number);

    Account* account = find_account(account_number);
    if (!account) {
        printf("Error: Account not found.\n");
        return;
    }

    printf("Enter old PIN: ");
    scanf("%d", &old_pin);

    if (!verify_pin(account, old_pin)) {
        printf("Error: Incorrect PIN.\n");
        return;
    }

    printf("Enter new PIN: ");
    scanf("%d", &new_pin);

    account->pin = new_pin;
    printf("PIN changed successfully.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nATM Simulation\n");
        printf("1. Create Account\n");
        printf("2. View Balance\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Change PIN\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                view_balance();
                break;
            case 3:
                deposit_money();
                break;
            case 4:
                withdraw_money();
                break;
            case 5:
                change_pin();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
