/*****************************************************
 Name : Harshil Patel
 ID : 2210708
 ****************************************************/


#include<stdio.h>
#include<string.h>
#include <stdlib.h>	
#include<conio.h>
#include<stdbool.h>

/********** STRUCTURE DEFINE **********/
typedef struct book
	{
        int id;   
        char title[50]; 
        char author[50];
        char publisher[50];
        char genre[50];
        int year;
        int stock;   
        float discount_price; 
	} Books;
	Books book[500];

int i, k=0, count_book=2;


bool stringMatch(char v1[50],char v2[50])
{
    int size = strlen(v1);
    bool search = false;
    for (int i = 0; i < size; i++)
    {
      if(v1[i]==v2[i])
      {
        search = true;
      }
      else
      {
        search = false;
        break;
      }
    }
    return search;    
}


/*************** PRELOADED DATA *********************/
void preloaded_data(){

   book[0].id = 1;
   strcpy(book[0].title, "Book1");
   strcpy(book[0].author, "Auth1");
   strcpy(book[0].publisher, "Pub1");
   strcpy(book[0].genre, "Type1");
   book[0].year = 2010;
   book[0].stock = 10;
   book[0].discount_price = 25.99;

   book[1].id = 2;
   strcpy(book[1].title, "Book2");
   strcpy(book[1].author, "Auth2");
   strcpy(book[1].publisher, "Pub2");
   strcpy(book[1].genre, "Type2");
   book[1].year = 2012;
   book[1].stock = 5;
   book[1].discount_price = 20.99;
   
}


/**************** FUNCTION **************************/
void preloaded_data();
Books add_book();
void search_book();
void print_search_record();
void transaction();
void delete_record();
void view_books();



/************************** MAIN FUNCTION *****************************/
int main(){

    int option;
    char menu;

    do{
      
        system("cls");
        printf("******* BOOK MANAGEMENT SYSTEM *******\n");
        printf("\n");

        printf("1 >>> Populate the inventory\n");
        printf("2 >>> Search by keywords\n");
        printf("3 >>> Process a transaction\n");
        printf("4 >>> Delete a book record\n");
        printf("5 >>> Display all books in inventory\n");
        printf("6 >>> Exit the system\n");
        printf("\n");
        printf("\nPlease select any option:\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                if(count_book==499){
                    break;
                }
                printf("How many books you want to add: \n");
                scanf("%d", &k);

                for(i=0;i<k;i++){
                    book[count_book] = add_book();
                    count_book++;
                    
                }
            break;

            case 2:
            search_book();
            break;

            case 3:
            transaction();
            break;

            case 4:
            delete_record();
            break;

            case 5:
            preloaded_data();
            view_books();
            break;

            case 6:
            printf(">>>>>>>   GOODBYE!   <<<<<<");
            exit(0);
            break;
        }
        getchar();
        printf("Press N to exit OR Y to display menu again\n");
        menu = getchar();
        if(menu=='N' || menu=='n'){
            printf(">>>>>> GOOD BYE! SEE YOU AGAIN <<<<<<");
            exit(0);
        }
   }while(menu=='Y' || menu=='y');

}

/*************** END OF MAIN *******************************/


/*************** FUNCTION COADING *************************/
Books add_book(){

    Books bk;
        do{
            printf("Last ID number is %d \n", count_book);
            fflush(stdin);
            printf("ISBN Id:");
            scanf("%d",&bk.id);
        }while(bk.id<=count_book);

        fflush(stdin);
        printf("Book Title:");
        fgets(bk.title, 50, stdin);

        fflush(stdin);
        printf("Author of the book:");
        fgets(bk.author, 50, stdin);

        fflush(stdin);
        printf("Publisher:");
        fgets(bk.publisher, 50, stdin);

        fflush(stdin);
        printf("Genre/Type of the book:");
        fgets(bk.genre, 50, stdin);

        fflush(stdin);
        printf("Publication Year(yyyy):");
        scanf("%d",&bk.year);

        fflush(stdin);
        printf("Stock of availbale book:");
        scanf("%d",&bk.stock);

        do{
        fflush(stdin);
        printf("Discount Price:");
        scanf("%f",&bk.discount_price);
        }while(bk.discount_price<0);
        
        printf("BOOK ADDED SUCCESSFULLY\n");
        
    return bk;

}


void search_book(){

   char book_title[50];
   printf("Search book by its title:\n");
   scanf("%s", &book_title);

   char book_author[50];
   printf("Search book by Author\n");
   scanf("%s", &book_author);

   char book_genre[50];
   printf("Search book by genre:\n");
   scanf("%s", &book_genre);

   bool search1 = false;
   bool search2 = false;
   for(i=0;i<count_book;i++){
      search1 = stringMatch(book_author,book[i].author);
      search2 = stringMatch(book_title,book[i].title);
      if((search1==true)&&(search2==true)){
        print_search_record(i);
      }
   }

   if(search1==false||search2==false){
      printf("No such book available\n");
   }

}



void transaction(){

   int choose, quantity, sch;

   printf("1 >>> Purchase the book\n");
   printf("2 >>> Return the book\n");
   printf("Please select any option to continue: \n");
   scanf("%d", &choose);

   switch(choose)
   {
      case 1:
        printf("Enter Id you want to Purchase:\n");
        scanf("%d", &sch);
        if(sch>count_book){
            printf("No Book found with ISBN %d\n", sch);
        }else{
            printf("Enter number of quantity you want to Purchase: \n");
            scanf("%d", &quantity);
            for(i=0;i<count_book;i++){
                if((book[i].id==sch) && (book[i].stock>quantity)){
                    book[i].stock = book[i].stock-quantity;
                    printf("%d books of ID>>>%d is purchased.\n", quantity, sch);
                    printf("Now %d book left in stock with ID no %d\n", book[i].stock, sch);
                }/*else{
                    printf("Insufficient Books Left!\n");
                }*/
            }
            
        }
        
      break;

      case 2:
        printf("Enter Id you want to Return:\n");
        scanf("%d", &sch);
        if(sch>count_book){
           printf("No Book found with ISBN %d\n", sch);
        }else{
            printf("Enter quantity you want to Return: \n");
            scanf("%d", &quantity);
            for(i=0;i<count_book;i++){
                if(book[i].id==sch){
                book[i].stock = book[i].stock+quantity;
                printf("%d books of ID>>>%d is returned.\n", quantity, sch);
                printf("Now %d book available in stock with ID no %d\n", book[i].stock, sch);
                }
            }
        }
         
      break;
   }
} 



void delete_record(){

   int pos;

   printf("Enter ISBN ID to delete the record: \n");
   scanf("%d", &pos);

   if(pos>count_book){
      printf("Please enter a valid ID number!\n");
   }else{
      printf("Book with ID %d is deleted successfully...!\n", book[pos-1].id);
      for(i=pos-1;i<count_book-1;i++){
         book[i] = book[i+1];
      }
      count_book--;
   }

}


void view_books(){

   printf("********** LIST OF ALL AVAILABLE BOOKS ************\n");
   printf("\n");
   if(count_book==0){
       printf("NO DATA TO DISPLAY\n");
   }else{
       for(i=0;i<count_book;i++){
            printf("------------------------------------------------------------------------------------------------------------\n");
            printf("ISBN: %d\n", book[i].id);
            printf("TITLE: %s\n", book[i].title);
            printf("AUTHOR: %s\n", book[i].author);
            printf("PUBLISHER: %s\n", book[i].publisher);
            printf("BOOK TYPE: %s\n", book[i].genre);
            printf("PUBLICATION YEAR: %d\n", book[i].year);
            printf("QUANTITY: %d\n", book[i].stock);
            printf("DISCOUNT PRICE: %.2f\n", book[i].discount_price);
            printf("------------------------------------------------------------------------------------------------------------\n");
      }
   }   
}



void print_search_record(){

   printf("\n-----------------------------------------------------------------------\n");
   printf("ISBN : %ld\n", book[i].id); 
   printf("Title : %s\n", book[i].title);
   printf("Author : %s\n", book[i].author);
   printf("Publisher : %s\n", book[i].publisher);
   printf("Category : %s\n", book[i].genre);
   printf("Publication Year : %d\n", book[i].year);
   printf("Stock : %d\n", book[i].stock);
   printf("Discount Price : %.2f \n", book[i].discount_price);
   printf("\n------------------------------------------------------------------------\n");

}
