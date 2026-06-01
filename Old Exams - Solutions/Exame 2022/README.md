# Project Specifications: Restaurant Table Management System

## 🎯 Objectives
* Compose a complete program in the C language
* Apply the concept of modularity in program construction

---

## 📝 Project to Develop

Consider a restaurant that aims to optimize the management of its tables based on the size of customer groups wishing to have lunch. The goal is to minimize waiting time while achieving the most efficient possible table occupancy.

There are tables with **2, 4, 6, and 8 seats**.

### 📂 Input Files
The input data is provided in 2 `.csv` (comma-separated values) files:

1. **Table File (`tables.csv`)**: Each line represents a table, containing its respective ID number, the total number of seats, and the number of currently occupied seats.
   * **Format:** `Table,Seats,Occupancy`
   * **Example:**
     ```csv
     1,2,0
     2,6,5
     3,2,1
     4,8,0
     5,4,0
     ```

2. **Customer File (`customers.csv`)**: Each line represents a group of people waiting for a table, featuring an uppercase letter identifying the group (alphabetical order corresponds to the arrival order) and the number of people in that group.
   * **Format:** `Group,People`
   * **Example:**
     ```csv
     A,2
     B,5
     C,7
     D,1
     E,4
     ```

### ⚙️ Distribution Criteria
The objective is to assign a table to each customer group according to the following criteria:
1. Seat as many groups as possible;
2. Respect the arrival order, without compromising criterion 1.

You must write a program in C that reads both the table and customer files, performs the distribution, and displays the appropriate information on the screen. For example, using the data provided above, the output must be:

```text
Group A - table 1
Group B - waiting
Group C - table 4
Group D - waiting
Group E - table 5

<!-- To Do Later: Best Fit Algorithm -->