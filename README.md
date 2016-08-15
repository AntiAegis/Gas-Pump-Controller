# Gas-Pump-Controller
Use MSP430G2553 to control gas pumps with 220-Volt electric.
//======================================================================================================================//
* There are two MSP430G2553 MCUs in this system: 
    One for interact with Keypad 4x4 and display it into a LCD 16x2 (chip 1).
    While another controls 12 gas pumps through two electronic relays (chip 2).
    
* Two these chips communicate with each other by I2C standard:
    Chip 1 gets data from user and transfer to chip 2.
    Chip 2 receives this data and implement as user want.

* The data gotten from user is two unsigned int variables: TimeOn and TimerOff
    TimeOn: The interval that chip 2 output high logic level in I/O pin in order to turn on gas pump.
    TimeOff: The interval that chip 2 output low logic leval in I/O pin in order to turn off gas pump.
    There is a limit in range of two variables above: [1, 999].

* The data in here isn't normal as decimal number. It is BCD number, that means the unit column of number is 4 first low
bits [3:0] of unsigned int variable, the tens column of number is 4 first next bits [7:4] of unsigned int variable, the
hundred column of number is 4 first next bits [11:8] of unsigned int variable. So the maximum BCD number is 2457 or
0x999.

* Data in communication must be divided into bytes before transmitting, so after reception, bytes must be merged. Besides,
We need a password byte in the starting of communication frame to identify safe transmission of data frame.

* A watchdog timer is needed to ensure that 2 chips will not be trapped while they are working.
