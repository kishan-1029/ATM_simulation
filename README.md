# ATM Simulation

This is a simple ATM simulation program written in C. The program allows users to create accounts, view balances, deposit money, withdraw money, and change PINs. 

## Features

- **Create Account**: Allows users to create a new account with an account number, name, initial balance, and a 4-digit PIN.
- **View Balance**: Enables users to view the balance of their account after entering the correct PIN.
- **Deposit Money**: Allows users to deposit money into their account after entering the correct PIN.
- **Withdraw Money**: Allows users to withdraw money from their account after entering the correct PIN and ensuring sufficient balance.
- **Change PIN**: Enables users to change their account PIN after entering the correct old PIN.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/atm-simulation.git
    cd atm-simulation
    ```

2. Compile the program:

    ```bash
    gcc -o atm atm_simulation.c
    ```

3. Run the program:

    ```bash
    ./atm
    ```

## Usage

Upon running the program, you will be presented with a menu with the following options:

1. **Create Account**: Follow the prompts to enter the account details and set a PIN.
2. **View Balance**: Enter your account number and PIN to view your current balance.
3. **Deposit Money**: Enter your account number, PIN, and the amount you want to deposit.
4. **Withdraw Money**: Enter your account number, PIN, and the amount you want to withdraw.
5. **Change PIN**: Enter your account number, old PIN, and new PIN.
6. **Exit**: Exit the program.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Thanks to all the contributors who have helped in improving this project.

