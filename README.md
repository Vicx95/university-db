This is a simple project of university-db


How to build and run:
1. mkdir build && cd build
2. cmake ..
3. make -j 
4. ./university-db or ./university-db-ut if you want to run tests

Basic requirements:
1. Storage of student records with the structure: first name, last name, address, index number, PESEL, gender
2. Adding new students
3. Displaying the entire database
4. Searching by last name
5. Searching by PESEL number
6. Sorting by PESEL number
7. Sorting by last name
8. Deleting by index number
9. Validation whether the PESEL number is correct'
10. Loading from a file and saving the entire database to a file


Additional requirements:
1. Storage of employees records with the structuer: name, last name, PESEL, gender, address, salary
2. All people regardless of whether they are employees or students are to be kept in one container
3. Filling database with fake data(data generation)
4. Salary modifying by searching person by PESEL number
5. Sorting by salary
