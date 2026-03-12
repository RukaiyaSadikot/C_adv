#include<iostream>
#include<cstring>
using namespace std;

class Movie
{
    public:
        char title[50];
        char genre[50];
        int year;

        void display() {
            cout << "Title: " << title << "\t Genre: " << genre << "\t Year: " << year << endl;
        }
        
};

int main(){
    Movie mov[3] = {
        {"3 Idiots", "Comedy", 2007},
        {"Dhurandar", "Action Drama", 2026},
        {"The Housemaid", "Thriller", 2025}
    };

    for(int i=0; i<3; i++) {
        mov[i].display();
    }
    return 0;
}


