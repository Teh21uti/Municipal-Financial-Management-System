 Municipal Financial Management System (MFMS)
 
Course: PAP521S — Programming in Practice

Project: Project A — Foundation System

Due Date: 04 October 2026

Group Members:
#	Name,	Student Number,	Role
1.		Henok Josef, 225143402, Employee Management
2.      Richard Ashipala, 226092321,   Budget Management
3.     Tehuti Billawer, 225000652,	'Supplier Management/Intergation and Main Menu'/ Majority of Testing & Documentation
4.		 Anton Ngondo, 226091309, Asset Management
5.		  Eva Niimbwele, 226051374, Reports
6.     Robert, 226135934, Testing & Documentation

Project Description:

An application that manages municipal employees, supplies, assets, budgets and produces summary reports. 

System Features
Employee Management: add, display, search employees; calculate net salary

Budget Management:     capture departmental budgets, expenditure, remaining balance, over-budget warnings

Supplier Management: add, display, search suppliers (uses string functions)

Asset Management: add, display, search municipal assets

Reports: summary reports across all modules

Build: '   gcc -std=c99 -Wall -Wextra -pedantic main.c employees.c suppliers.c assets.c budget.c -o myapp'
