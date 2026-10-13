#include <iostream>
#include <string>
#include<vector>
#include<limits>
#include<algorithm>
#include<fstream>

using namespace std;

struct book {
    int ID;
    string Name;
    string auther;
    bool isBorrowed;
};

void SaveBook(vector<book>& books) {
    ofstream file("books.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }
        for (int i = 0;i < books.size();i++) {
            file << books[i].ID <<"||";
            file << books[i].Name << "||";
            file << books[i].auther << "||";
            if (books[i].isBorrowed) {
                file << "1"<<endl ;
            }
            else {
                file << "0" << endl;
            }

        }
    
}

void LoadBooks(vector<book>& books) {
    ifstream file("books.txt");
    if (!file.is_open()) {
        cerr << "Error:Unable to open file!" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        int firstsepar = line.find("||");
        int secondsepar = line.find("||", firstsepar + 2);
        int thirdsepar = line.find("||", secondsepar + 2);
        book b;
        b.ID = stoi(line.substr(0, firstsepar));
        b.Name = line.substr(firstsepar + 2, secondsepar-(firstsepar+2));
        b.auther = line.substr(secondsepar + 2, thirdsepar-(secondsepar+2));
        b.isBorrowed = stoi(line.substr(thirdsepar + 2));
        books.push_back(b);
    }
}

void AddBook(vector<book>&books) {
    book b;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Book name : "<<endl;
    getline(cin,b.Name);
    cout << "Book Auther : "<<endl;
    getline(cin,b.auther);
    b.isBorrowed = false;
    books.push_back(b);
}
void DisplayBooks(vector<book>&books) {
    if (!books.empty()) {
        for (int i = 0;i < books.size();i++) {
            cout << "Book ID : " << books[i].ID << endl;
            cout << "Book Name : " << books[i].Name << endl;
            cout << "Book Auther : " << books[i].auther << endl;
            if (books[i].isBorrowed) {
                cout << "Borrowed" << endl;
            }
            else {
                cout << "Available" << endl;
            }
            cout << "=====================================" << endl;

        }
    }
    else {
        cout << "the library is empty" << endl;
    }
}
void Search(vector<book>& books) {
    int S;
    int SID;
    string SName;
    bool found = false;

    if (!books.empty()) {
        do {
            cout << "Search by \n1.ID \n2.Name" << endl;
            cin >> S;
        } while (S != 1 && S != 2);

        if (S == 1) {
            cout << "Enter the book ID :" << endl;
            cin >> SID;
        }
        else {
            cout << "Enter the Book Name : " << endl;
            getline(cin >> ws, SName); // consomme le '\n' restant puis lit la ligne
        }

        for (int i = 0; i < (int)books.size(); ++i) {
            if ((S == 1 && SID == books[i].ID) || (S == 2 && SName == books[i].Name)) {
                cout << "****Book found****" << endl;
                cout << "Books ID : " << books[i].ID << endl;
                cout << "Book Name : " << books[i].Name << endl;
                cout << "Auther : " << books[i].auther << endl;
                cout << (books[i].isBorrowed ? "Borrowed" : "Available") << endl;
                found = true;
                break; // arrêt après première correspondance
            }
        }

        if (!found) cout << "------not found------" << endl;
    }
    else {
        cout << "the library is empty" << endl;
    }
}
void Borrow(vector<book>& books) {
    string BName;
    bool found = false;
    int i = 0;
    if (!books.empty()) {
    cout << "Enter the Book Name you want to borrow"<<endl; 
    getline(cin>>ws,BName);
    for (i;i < books.size();i++) {
        if (BName == books[i].Name) {
            found = true;
            if (!books[i].isBorrowed) {
                cout << "the book is availble \nYou Borrowed it" << endl;
                books[i].isBorrowed = true;
                break;
            }
            else { cout << "the book isn't availble" << endl; }
        }
    }
    if (!found) {
        cout << "not found" << endl;
    }
    }
    else {
        cout << "the library is empty" << endl;
    }
}
void Return(vector<book>& books) {
    string BName;
    bool found = false;
    int i = 0;
    if (!books.empty()) {
    cout << "Enter the Book Name you are returning" << endl;
    getline(cin >> ws, BName);
    for (i;i < books.size();i++) {
        if (BName == books[i].Name) {
            found = true;
            if (books[i].isBorrowed) {
                cout << "Thank you for returning the book" << endl;
                books[i].isBorrowed=false ;
                break;
            }
            else { cout << "the book isn't borrowed" << endl; }
        }
    }
    if (!found) {
        cout << "not found" << endl;
    }
    }
    else {
        cout << "the library is empty" << endl;
    }

}
void Delete(vector<book>& books) {
    string BName;
    bool found = false;
    int i = 0;
    
    if (!books.empty()) {
    cout << "Enter the Name of Book you're returning" << endl;
    getline(cin >> ws, BName);
    for (i;i < books.size();i++) {
        if (BName == books[i].Name) {
            found = true;
            if (!books[i].isBorrowed) {
                books.erase(books.begin() + i);
                break;
            }
            else {
                cout << "the book isn't borrowed" << endl;
                break;
            }
        }
    }
    if (!found) {
        cout << "not found" << endl;
    }
    }
    else {
        cout << "the library is empty" << endl;
    }
}


int main()
{
    //declaration :
    book b;
    vector <book>Books;
    int choice;
    bool finish = false;
    int j = 1;
    
    LoadBooks(Books);
    //Menu:
    do{
    cout << "===============Library===============" << endl;
    cout << "1.Add book. \n2.Display books. \n3.Search. \n4.Borrow. \n5.Return. \n6.Delete book. \n7.Exit "<<endl;
    cout << endl;
    do{
        cout << "choose : " << endl;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
    } while (choice < 1 || choice > 7);


    switch (choice) {
    case 1:
        AddBook(Books);
        Books.back().ID = j;
        j ++;

        break;
    case 2:
        DisplayBooks(Books);
        break;
    case 3:
        Search(Books);
        break;
    case 4:
        Borrow(Books);
        break;
    case 5:
        Return(Books);
        break;
    case 6:
        Delete(Books);
        break;
    case 7:
        finish = true;
    }
    

    } while (finish == false);
    SaveBook(Books);
    
}