# 📚 Library Management System

A console-based Library Management System built with **C++** to practice object-oriented programming concepts, functions, vectors, structures, and file handling.

## ✨ Features

- **Add Books** — Add books with an ID, title, and author.
- **Display Books** — View all books in the library.
- **Search Books** — Find a book by its title.
- **Borrow Books** — Mark a book as borrowed.
- **Return Books** — Mark a borrowed book as available.
- **Delete Books** — Remove books from the library.
- **Save Data** — Store book information in a text file.
- **Load Data** — Restore saved books when the program starts.

## 🛠️ Technologies

- C++
- Standard Template Library (STL)
- `vector`
- File handling with `ifstream` and `ofstream`

## 💾 Data Persistence

Book information is stored in `books.txt`, allowing the library data to persist between program sessions.

Each book stores:
- ID
- Title
- Author
- Borrowing status

## 🚀 How to Run

1. Clone or download this repository.
2. Make sure a C++ compiler such as GCC is installed.
3. Compile the source file:

   ```bash
   g++ main.cpp -o library
   ```

4. Run the program:

   **Windows:**
   ```bash
   .\library.exe
   ```

   **Linux/macOS:**
   ```bash
   ./library
   ```

Replace `main.cpp` with your actual source filename if it differs.

## 🎯 Project Goal

This project was developed as a hands-on programming exercise to strengthen my C++ fundamentals and learn how to build a functional, menu-driven application with persistent data storage.

## 👨‍💻 Author

**Mohamed Aziz Ikridih**

