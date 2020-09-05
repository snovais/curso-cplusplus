#include <iostream>
#include "Book.hpp"

int main(int argc, char* argv[]){
    Book* p_book_i_am_reading = new Book;

    (*p_book_i_am_reading).author = "Philip Pullman";
    
    p_book_i_am_reading->title = "Lyra’s Oxford";
    delete p_book_i_am_reading;

    return 0;
}