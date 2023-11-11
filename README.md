# Library-Management-System

# Introduction:
The Name of our project is “Library Management System”. Instead of wandering around the library, you 
can just enter the name of the book that you want, and this program will assist you in finding its location 
in the library’s shelves.
# Working: (How to Operate)
In this program, we have made four functions i.e., add(), delette(), search(), booklist().

-> main():
In the main function, these all functions are called when user enters required input.

1.View the Booklist

2.Search for a book

3.Add a book

4.Delete a book

5.Exit program

When user input 1 booklist() function is called and compiler jumps to that function. When 2 is input 
search() function, 3 is input add() function, 4 is input delette() function is called and 5 is input program 
exits.

-> add():
This function is used to add a book in the file where all the data is saved. When it is called it will ask the 
user to enter the Book name then the compiler would search in the saved data if it existed there then it 
will output “file existed” but if not then it will ask user to enter the shelf number and after that it will 
output “Book added successfully”. This will save the Book name and shelf number in the text file where 
data is being saved.

-> search():
This function will get the Book name from the user. It will search that book name is text file by 
transferring data line by line in a string and comparing it with the book name if it matches it will output 
“book found” and output the shelf number of that book. If book name is not matched, then it will output “book not found".

-> delette():
This function will work same as that of search() function. If book is found, then it will delete that book 
from the data file by creating a temporary file in which it will copy all the data except the book name that 
is going to delete and shelf number of that book and output “book deletion successful”. After copying it 
will delete the previous data file and rename the temporary file to the name of previous file. This will 
delete the book name and shelf number from the text data file. Now if you search the book that is deleted 
it will show “book not found”.
-> booklist():
This function will show all the book data saved in the text file. In this function, data will transfer to the 
program and saved in a string line by line. It will show the books name in ascending order like books in 
shelf 1 will be at top with written shelf 1, then shelf2 books and others
