# Municipal Financial Management System (MFMS)

**Course:** PAP521S — Programming in Practice  
**Project:** Project A — Foundation System  
**Group:** PAP521S-MFMS  
**Due Date:** 02 October 2026

## Group Members

| # | Name | Student Number | Role |
|---|------|----------------|------|

| 1 | Kletus Kapusa Kapusa | 224012193 | Employee Management |
| 2 | Bertha Preslyn Witbeen  | 226003159 | Budget Management |
| 3 | Merjan Eliphas | 225082462  | Supplier Management |
| 4 | Israel Vilho | 225121530 | Asset Management | 
| 5 | *(to be confirmed)* | — | Reports |
| 6 | Laimi Shandjuka | 224074946 | Integration & Main Menu |
| 7 | *(to be confirmed)* | — | Testing & Documentation |

## Project Description

A menu-driven C application that manages municipal employees, budgets, suppliers, and assets, and produces summary reports. Built using concepts from Weeks 1–8 of the PAP521S course: variables, operators, decision-making, loops, arrays, strings, and functions.

## System Features

- **Employee Management** — add, display, search employees; calculate net salary
- **Budget Management** — capture departmental budgets, expenditure, remaining balance, over-budget warnings
- **Supplier Management** — add, display, search suppliers (uses string functions)
- **Asset Management** — add, display, search municipal assets
- **Reports** — summary reports across all modules

## Compilation

```bash

gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms

