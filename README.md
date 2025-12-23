# Restaurant-Reservation-Application
Allow users to reserve tables at a restaurant. If table is already reserved, allows user to waitlisted.
## Table of Contents
- [Application Overview](#introduction)
- [Code and File Structure Explained](#code-and-file-structure-explained)
- [Algorithm and Data Analysis](#algorithm-and-data-structuring)
- [How to run](#how-to-run)
- [Demo](#Demo)
<br><br><br><br><br>
### Introduction
This application allows users to reserve a table at a restaurant. The application allows for a few other features including allowing users to view all current tables, view which ones are currently reserved and still get on the waitlist for those tables. The application also allows users to claim their reservation spot.
<br><br>
### Code and File Structure Explained
There application consists of two main files, main.cpp and Restaurant.cpp, (I know, very creative). 
- Restaurant.cpp is where the main code structure and descriptions are included.
  -  This file includes classes ``Table``, ``Queue``, and ``Restaurant``
  -  These classes define all the available structure of the application
  -  ***Table*** is the lowest complixity data type. What I mean by that is, the other classes use instances of *Table*, in a way, to create their own data types and complexities. Table allows the creation for a table to reserve. You can reserve a 4-person-table.
  -  ***Queue*** is the second complex class. It stores a collection of Table objects, allowing operations to be done on Table objects, structuring them in the form of a queue.
  -  ***Restaurant*** is the most complex data type. It stores a collection of *Queues*, structured contiguously in memory. It allows operations such as reserving a table, displaying a table, or claiming a table.
- main.cpp is where code execution and a lot of application's computation flow. Ex: what the steps will look like, what will be looped, what actions can the user take, etc.
  - main.cpp included a function to structure the options for the user and a function to run the options which is then called in the main() function.
<br><br>
### Algorithm and Data Structuring
Knowing how to model data is essential for data storage and retrieval efficiency. This application uses various data structures for specific needs.
- In the ```Queue``` class, I use a queue data structure (DS), to model how a queue is supposed to work. The Table node that is inserted first will be the first one to be removed. When the user decided to make a reservation on a table, if the that is the first time the reservation is being done on that table, that reservation will be the first one in the queue, if it's not the first time I am reserving that table, it will be the next on the queue.
- In the ```Restaurant``` class, I use an array to store all the collection of queues. In each queue, I have Tables, so essentially, the array in the Restaurant class stores Table objects, a little like a linked list.
<br><br>
### How to run
There are two ways to run the code:
1. [Copy and paste the code onto two .cpp files in an IDE](#copy-and-paste), or
2. [Clone the repository then open it in an IDE](#clone-repo), preferably VSCode.

Either process will require you already have a valid c++ compiler installed on VSCode. 
#### Copy and paste
1. Open up your favorite Integrated Development Environment(IDE), I suggest Visual Studio Code (VSCode). 
2. Create a new project folder, then create a file by the name of main.cpp and Restaurant.cpp.
3. Paste the corresponding code into it's corresponding file. When done, you are ready to [compile](#compile).
#### Clone Repo
1. Click on the clone repo icon on this page
2. Then copy the repository url
3. If you have a computer that runs on WindowsOS or MacOS, open up your terminal and navigate to the folder where you want to clone this repository. When you are in that folder, type:
   ```clone https://github.com/Tyrone21nc/Restaurant-Reservation-Application.git```
5. Assuming it clones the repository, the next command on your terminal should be ```code```, which will then open up VSCode and you can navigate where you cloned the repository. When you get there, you should be ready to [compile](#compile)
<img width="734" height="513" alt="Screenshot 2025-12-23 021735" src="https://github.com/user-attachments/assets/42595a38-81b9-489a-9a0e-f62decfdeddb" />

<br><br>
#### Compile
To compile, you can run these commands:
- Compile your code: ```g++ -Wall main.cpp Restaurant.cpp -o main```
- Then run the program: ```./main```

### Demo
<img width="400" height="550" alt="Screenshot 2025-12-23 023208" src="https://github.com/user-attachments/assets/341c3b1f-5f61-4130-92b4-209249b06956" />
<img width="400" height="550" alt="Screenshot 2025-12-23 023359" src="https://github.com/user-attachments/assets/c0b81acc-90f1-4f4b-84ba-ce21145fad84" />
<img width="400" height="550" alt="Screenshot 2025-12-23 023512" src="https://github.com/user-attachments/assets/85ffd992-a470-4090-af9d-586a0e9f2005" />

