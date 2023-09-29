# Electronic-Component-Inventory-Management-System

Overview

The Electronic Component Inventory Management System is a software application designed to efficiently manage an inventory of electronic components. It is implemented using a linked list data structure with two primary components:

•	Type Data Structure: This structure represents the types of electronic components available in the shop. Each node of this structure connects to the next type structure and links to an associated item data structure.
•	Item Data Structure: This structure represents the inventory items listed under a specific component type. Each node in the item structure contains information such as scale, measuring unit, available quantity, and unit price for an electronic component.

Supported Operations
The system supports a variety of operations, including:

•	Creating new types of electronic components
•	Adding new inventory items under existing types
•	Searching for inventory items based on type, scale, and unit
•	Deleting inventory items
•	Selling inventory items
•	Buying inventory items
•	Setting new prices for inventory items
•	Sorting inventory items based on scale
•	Displaying all inventory items under a specific type
Using the System
To use the system, users simply need to create a text file named inputs.txt and provide a list of commands in the following format:
<COMMAND> <TYPE> <SCALE> <UNIT> <QUANTITY> <UNIT PRICE>
The following is an example of an input file:
CREATE resistor
ADD resistor 1 kiloOhm 100 5.49
SEARCH resistor 1.2 kiloOhm
DELETE resistor 220 Ohm
SELL resistor 1.2 kiloOhm 10
BUY resistor 3.3 kiloOhm 135
SETPRICE resistor 2.2 MegaOhm 12.99
SORT resistor ASC
DISPLAY resistor
EXIT
Once the input file is created, users can run the system by executing the following command:
The system will then process the commands in the input file and perform the corresponding operations on the inventory.

Conclusion

The Electronic Component Inventory Management System is a powerful and flexible tool for managing electronic component inventory. It is easy to use and provides a wide range of features to meet the needs of businesses of all sizes.

Additional Information

The following are some additional details about the system:

•	The system is implemented in C++ and uses the STL library to implement the linked list data structure.
The following is a simple tutorial on how to use the Electronic Component Inventory Management System:
1.	Create a new text file named inputs.txt.
2.	Add the following command to the file:
CREATE resistor
This will create a new type of electronic component called "resistor".
3.	Add the following command to the file:
ADD resistor 1 kiloOhm 100 5.49
This will add a new inventory item under the "resistor" type with the following details:
•	Scale: 1 kiloOhm
•	Unit: 100
•	Quantity: 5.49

Display all inventory items under the "resistor" type with the following command:

DISPLAY resistor
The system will display the following output:
Type: resistor
Scale: 1 kiloOhm
Unit: 100
Quantity: 5.49

This is just a simple example of how to use the Electronic Component Inventory Management System. For more information, please consult the system documentation.

