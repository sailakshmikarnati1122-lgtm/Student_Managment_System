# 🎓 Student Management System in C

A simple **Student Management System** written in **C language** using **structures, file handling, arrays, loops, strings, functions, and conditional statements**.  
This project allows you to **add, view, search, update, and delete student records**, and all data is stored persistently using a text file.

---

## 📚 Features

- ➕ **Add Student** – Enter roll number, name, and marks.
- 📋 **Display All Students** – View all student records.
- 🔍 **Search Student** – Find a student by roll number.
- ✏️ **Update Student** – Modify existing student details.
- ❌ **Delete Student** – Remove a student record.
- 💾 **File Handling** – Data is saved to `students.txt` for future use.

---

## 🧠 Concepts Used

- **Structures** – To represent student data.
- **Functions** – To modularize the program.
- **File Handling** – To store and retrieve records (`fopen`, `fprintf`, `fscanf`, etc.).
- **Conditional Statements** – For logical operations (if-else, switch).
- **Loops** – To handle menu navigation and repetitive tasks.
- **Arrays & Strings** – To store and manipulate student names and data.

---

## ⚙️ How It Works

1. When the program starts, it **reads existing student data** from `students.txt`.
2. The user is presented with a **menu** of options (Add, Display, Search, Update, Delete, Exit).
3. Each option calls a separate **function** that handles the specific task.
4. When adding or updating data, records are **saved automatically** to the file.
5. When the user exits, all data remains safely stored in `students.txt`.
