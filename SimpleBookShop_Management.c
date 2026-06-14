
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100 // maximum number of books the shop can store




// structure to store book information
struct Book {
    char title[50];
    char author[50];
    float price;
    int copies;
};




// global variables
struct Book bookList[MAX_BOOKS];
int numBooks = 0; // number of books currently in the shop



// function prototypes
void showWelcomeMessage();
void showGoodbyeMessage();
void showMenuOptions();
void showBooks();
void addBook();
void searchBook();
void showNumberOfBooks();



// main function
int main() {
    int choice;
    showWelcomeMessage();
    do {
        
        
        showMenuOptions();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
             case 1:
                // do nothing, just continue the loop
               break;
            case 2:
                showBooks();
                break;
            case 3:
                addBook();
                break;
            case 4:
                searchBook();
                break;
            case 5:
                showNumberOfBooks();
                break;

            case 6:
                showGoodbyeMessage();
                exit(0); // terminate the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}



// function definitions
void showWelcomeMessage() {
    printf("*****************************************\n\nWelcome to Simple Book Management System.\n\n*****************************************\n");
}

void showGoodbyeMessage() {
    printf("\n**************************************************\n\nThank you for using Simple Book Management System.\n\n**************************************************\n");
}



void showMenuOptions() {
    printf("\nPlease select a menu option number:\n");
    printf("1) Display this menu.\n");
    printf("2) Show all available books.\n");
    printf("3) Add a book to the shop.\n");
    printf("4) Search a book by title.\n");
    printf("5) Display the total number of books.\n");
   // printf("5. Continue shopping\n");
    printf("6. Exit from the book shop system.\n");
}



void showBooks() {
    if (numBooks == 0){
        printf("No books are currently available in the shop.\n");
    }
    else{

    
        for (int i = 0; i < numBooks; i++) {
        printf("Book Title       : %s\n",bookList[i].title);
        printf("Book Author      : %s\n",bookList[i].author);
        printf("Book price       : %.2f\n",bookList[i].price);
        printf("Number of copies : %d\n",bookList[i].copies);}

    }
}




void addBook() {
    if (numBooks == MAX_BOOKS) {
        printf("Sorry, the shop is full and cannot accept more books.\n");
        return;
    }
    
    
   
    struct Book newBook;
    printf("Enter the details of the book:\n");
    printf("Title: ");
    scanf(" %[^\n]s", newBook.title);
    printf("Author: ");
    scanf(" %[^\n]s", newBook.author);
    printf("Price: ");
    scanf("%f", &newBook.price);
    printf("Number of copies: ");
    scanf("%d", &newBook.copies);
    bookList[numBooks] = newBook;
    numBooks++;
    printf("The book has been added to the shop.\n");
}





void searchBook() {
    char searchTitle[50];
    printf("Enter the title of the book to search: ");
    scanf(" %[^\n]s", searchTitle);
    for (int i = 0; i < numBooks; i++){
        if (strcmp(bookList[i].title, searchTitle) == 0) {
            printf("Book Title       :%s\n",bookList[i].title);
            printf("Book Author      :%s\n",bookList[i].author);
            printf("Book Price       :%.2f\n",bookList[i].price);
            printf("Number of copies :%d\n",bookList[i].copies);

            return;
        }
    }
    printf("Book not found in the shop.\n");
}



void showNumberOfBooks() {
    printf("There are currently %d books in the shop.\n", numBooks);
}
