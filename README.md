# ATM-Simulator

This is the finished ATM simulation program I developed as part of personal growth and knowledge 

---

## How does it work?

The program simulates an Automated Teller Machine (ATM) with secure PIN authentication and basic banking functionalities, including balance checks, deposits, withdrawals, and fund transfers between accounts.

### System Overview:

1. **Accounts and Authentication:**
   - The program simulates two bank accounts with unique account holders and PINs.
   - PIN authentication ensures secure access to account details and functionalities.

2. **Menu Options:**
   Users can perform the following actions after successful authentication:
   - **Check Balance:** View the current balance of the authenticated account.
   - **Deposit Money:** Add money to the account.
   - **Withdraw Money:** Withdraw money, ensuring sufficient balance is available.
   - **Transfer Funds:** Transfer money between the two simulated accounts securely.
   - **Exit:** End the session.

---

## Implementation Details

### Data Structures:

1. **BankAccount Class:**
   - This class represents each bank account and contains attributes like the account holder's name, balance, and PIN.
   - It includes methods for deposit, withdrawal, balance inquiry, fund transfer, and authentication.

2. **Input Validation Functions:**
   - `getValidInteger()` ensures integer input for menu options and PINs.
   - `getValidDouble()` validates monetary inputs, such as deposits and withdrawals, to prevent invalid entries.

---

## Transaction Procedure

### 1. Authentication:
   - Users select an account and input the corresponding PIN to authenticate.
   - If the PIN is incorrect, the program prompts the user to re-enter it.

### 2. Menu Operations:
   - After successful authentication, users are presented with a menu to select a transaction.
   - Each operation is handled with appropriate checks and validations:
     - Deposits and withdrawals ensure positive amounts.
     - Transfers verify that sufficient balance is available before completing the transaction.

### 3. Error Handling:
   - Invalid inputs, such as non-numeric values or incorrect menu selections, are handled gracefully.
   - The user is re-prompted to enter valid data without crashing the program.

---

## Key Features

1. **Secure Authentication:**
   - Each account is protected by a unique PIN, ensuring secure access.

2. **Robust Input Validation:**
   - Prevents crashes by handling invalid inputs like non-numeric or negative values.

3. **Realistic Banking Operations:**
   - Simulates real ATM functionalities, including fund transfers between accounts.

4. **User-Friendly Interface:**
   - Clear instructions and error messages guide users through the process.

---

## Technical Details

1. **Sequential Transaction Processing:**
   - The program processes one transaction at a time, ensuring clear flow and consistent state management.

2. **Error Prevention:**
   - Includes checks for sufficient balance during withdrawals and transfers.

3. **Session Handling:**
   - Users can perform multiple transactions in a session or exit at any time.

---

## Advanced Techniques Used

1. **Class-Based Design:**
   - The `BankAccount` class encapsulates all account-related operations and data, demonstrating object-oriented programming principles.

2. **Forward Validation:**
   - Ensures that invalid inputs or insufficient balances are caught early, preventing errors during execution.

3. **Backtracking Simulation:**
   - If an operation fails (e.g., insufficient funds during a transfer), the program allows the user to retry with a new value.

---

## Project Structure

- **Code:** The program is implemented in C++ using object-oriented programming concepts.
- **BankAccount Class:** Handles account operations such as deposits, withdrawals, transfers, and PIN validation.
- **Input Validation Functions:** Ensure robust handling of numeric inputs.

---

## How to Run the Program

1. Clone the repository:
   ```bash
  git clone https://github.com/HarshitB6/ATM-Simulator.git

