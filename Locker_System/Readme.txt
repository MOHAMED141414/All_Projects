Definitions and Includes:

#define F_CPU 8000000UL: Defines the CPU frequency as 8 MHz.
Includes: The code includes various header files for standard data types, bit manipulation, and interfaces for DIO (Digital Input/Output), LCD, Keypad, LED, I2C, and EEPROM.
Global Variables:

pass1 and pass2: Arrays to store the set password and the entered password, respectively.
Function: Init_voidSystem

Initializes the LCD, Keypad, and two LEDs connected to PORTB pins 4 and 5.
Function: compare_passwords

Compares two passwords (password1 and password2). If all digits match, it returns 1; otherwise, it returns 0.
Function: Set_voidPassword

Allows the user to set a 4-digit password using the keypad. The password is stored in pass1 and displayed as asterisks (*) on the LCD.
Function: Enter_voidPassword

Prompts the user to enter the 4-digit password using the keypad. The entered password is stored in pass2 and displayed as asterisks (*) on the LCD.
Function: App

This is the main application function that controls the flow of the Locker System.
The system starts with a welcome message and prompts the user to set a password.
The password is saved to EEPROM for persistence.
The system then enters a loop where the user is prompted to enter the password to unlock the locker.
If the entered password matches the stored password, the locker is "unlocked" (LED on pin 5 is turned on).
If the password is incorrect, the user is given three attempts. After exhausting the attempts, the system enforces a short delay before allowing more attempts.