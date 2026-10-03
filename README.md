 Individual Contribution: Tehuti, Supplier Management & Main Menu

Student Number: 225000652
Main Responsibility: Supplier Management module and the main menu (main.c)

Files: 'suppliers.c', 'suppliers.h', main.c'

Supplier module: stores up to 100 suppliers (ID, name, email, phone, town) in arrays. supplierMenu() lets the user add, list or search suppliers. 'addSupplier()' validates every field. 'listSuppliers()' shows all suppliers and the total. 'searchSupplier()' finds suppliers by exact name.

Main menu: 'displayMenu()' and 'main()' repeat the menu until the user exits. Option 3 opens the supplier menu, and the other options are placeholders until those modules are integrated by my fellow collueges.

C concepts used: 2D character arrays, string functions ('strlen', 'strcmp', 'strcpy', 'strcspn'), 'do-while' and 'for' loops, 'switch', functions and header files.

Testing: added, listed and searched suppliers; confirmed empty fields, empty search, duplicate IDs and invalid menu choices are rejected.

GitHub: frequent commits to 'suppliers.c', 'suppliers.h' and 'main.c' over several sessions.

Build: 'gcc -std=c99 -Wall -Wextra -pedantic main.c suppliers.c -o myapp'