# Restaurant-Reservation-Application
Allow users to reserve tables at a restaurant. If table is already reserved, allows user to waitlisted.
## Table of Contents
- [Application Overview](#introduction)
- [Code and File Structure Explained](#code-and-file-structure-explained)
- [Algorithm and Data Analysis](#algorithm-and-data-analysis)
- [How to run](#how-to-run)
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
### Algorithm and Data Analysis
I use various data structures to accomplish this project.
<br><br>
### How to run
There are two ways to run the code:
1. Copy and Paste the Code onto an IDE with a .cpp file, or
2. Clone the repository and then open the repository on an IDE, preferably VSCode.
