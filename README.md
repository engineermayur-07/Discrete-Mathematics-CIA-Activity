<div align="center">

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=26&pause=1000&color=2F81F7&center=true&vCenter=true&width=700&lines=Library+Book+Borrowing+Management;Optimizing+Borrowing+with+Set+Operations;Discrete+Mathematics+%2B+C%2B%2B+STL" alt="Typing SVG" />

<br/>

![C++](https://img.shields.io/badge/C%2B%2B-STL-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Discrete Math](https://img.shields.io/badge/Discrete-Mathematics-8A2BE2?style=for-the-badge)
![Set Theory](https://img.shields.io/badge/Set-Theory-orange?style=for-the-badge)
![Console App](https://img.shields.io/badge/Interface-Console-black?style=for-the-badge&logo=gnubash&logoColor=white)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)

**A menu-driven C++ application that applies Set Theory (Union, Intersection, Difference) to analyze library book borrowing records.**

</div>

---

## 📖 Table of Contents

- [Overview](#-overview)
- [Problem Statement](#-problem-statement)
- [Mathematical Model](#-mathematical-model)
- [Features](#-features)
- [System Architecture](#-system-architecture)
- [Tech Stack](#-tech-stack)
- [Getting Started](#-getting-started)
- [Usage and Sample Run](#-usage-and-sample-run)
- [Code Structure](#-code-structure)
- [Test Cases and Verification](#-test-cases-and-verification)
- [Limitations](#-limitations)
- [Future Scope](#-future-scope)
- [References](#-references)
- [Author](#-author)

---

## 🎯 Overview

Libraries hold books across several categories, and many members borrow from more than one. Comparing those records by hand becomes slow and error-prone as the data grows.

This project, **"Optimizing Library Book Borrowing Using Set Operations"**, models each book category as a **mathematical set** of member IDs and uses **set operations** to answer questions about borrowing patterns instantly. It is a practical demonstration of how an abstract Discrete Mathematics concept maps directly onto a real-world data problem.

Three categories are modeled:

| Set | Category        |
|-----|-----------------|
| `F` | Fiction         |
| `N` | Non-Fiction     |
| `R` | Research Papers |

---

## ❓ Problem Statement

A librarian maintaining separate borrowing records per category may need to answer:

- Which members borrow **Fiction or Non-Fiction** books?
- Which members borrow **both** Fiction and Non-Fiction?
- Which members borrow Fiction **but not** Non-Fiction?
- Which members borrow from **all three** categories?
- How many **unique members** exist across all categories?

Set Theory answers each of these with a single operation.

---

## 🧮 Mathematical Model

```
F = { M1, M2, M3, M5, M7 }      Fiction
N = { M2, M3, M4, M6, M7 }      Non-Fiction
R = { M3, M5, M6, M7, M8 }      Research Papers
```

| Operation | Notation | Meaning | Result |
|-----------|----------|---------|--------|
| Union | `F ∪ N` | Fiction **or** Non-Fiction | `{M1, M2, M3, M4, M5, M6, M7}` |
| Intersection | `F ∩ N` | Both Fiction **and** Non-Fiction | `{M2, M3, M7}` |
| Difference | `F − N` | Fiction **but not** Non-Fiction | `{M1, M5}` |
| Intersection | `F ∩ R` | Both Fiction **and** Research | `{M3, M5, M7}` |
| Intersection | `N ∩ R` | Both Non-Fiction **and** Research | `{M3, M6, M7}` |
| Triple Intersection | `F ∩ N ∩ R` | All three categories | `{M3, M7}` |
| Triple Union | `F ∪ N ∪ R` | All unique members | `{M1, M2, M3, M4, M5, M6, M7, M8}` |

---

## ✨ Features

- 📚 **Dynamic input**: enter member IDs for each category at runtime
- 🔁 **Duplicate-safe**: `std::set` automatically stores unique members only
- 🔗 **Union, Intersection, and Difference** implemented with STL algorithms
- 🎯 **Multi-set analysis**: find members common to all three categories
- 👥 **Unique member listing** across the whole library
- 🧭 **Menu-driven interface** that loops until the user chooses to exit
- 🧩 **Modular design**: each operation lives in its own reusable function
- 🛡️ **Input handling**: invalid menu choices are reported gracefully

---

## 🏗️ System Architecture

```
┌──────────────────────────┐
│   Library Borrowing      │
│   Records (Member IDs)   │
└────────────┬─────────────┘
             │
             ▼
┌──────────────────────────┐
│   Input Layer            │   User enters IDs for
│   (cin >> id)            │   Fiction / Non-Fiction / Research
└────────────┬─────────────┘
             │
             ▼
┌──────────────────────────┐
│   Set Data Structure     │   std::set<int> × 3
│   (unique + sorted)      │   fiction | nonFiction | research
└────────────┬─────────────┘
             │
             ▼
┌──────────────────────────┐
│   Menu + Selected Op     │   switch (choice)
└────────────┬─────────────┘
             │
             ▼
┌──────────────────────────────────────────┐
│   Operation Layer                        │
│   findUnion()  findIntersection()        │
│   findDifference()                       │
│   (set_union / set_intersection /        │
│    set_difference from <algorithm>)      │
└────────────┬─────────────────────────────┘
             │
             ▼
┌──────────────────────────┐
│   Output Layer           │
│   display(set<int>)      │
└──────────────────────────┘
```

---

## 🛠️ Tech Stack

| Component | Details |
|-----------|---------|
| Language | C++ |
| Headers | `<iostream>`, `<set>`, `<algorithm>` |
| Data Structure | `std::set<int>` |
| Algorithms | `std::set_union`, `std::set_intersection`, `std::set_difference` |
| Interface | Console (CLI), menu-driven |

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler with C++11 support or later (g++, clang++, or MSVC)

### Clone the repository

```bash
git clone https://github.com/engineermayur-07/<your-repo-name>.git
cd <your-repo-name>
```

### Compile

```bash
g++ maths.cpp -o maths
```

### Run

```bash
# Linux / macOS
./maths

# Windows (PowerShell)
.\maths
```

> 💡 Replace `maths.cpp` with your actual source filename if it differs.

---

## 💻 Usage and Sample Run

On launch, the program asks for the number of members and their IDs in each category, then shows the analysis menu.

```
=============================================
   LIBRARY BOOK BORROWING MANAGEMENT SYSTEM
=============================================

Enter number of members who borrowed Fiction books: 5
Enter Member IDs:
1 2 3 5 7

Enter number of members who borrowed Non-Fiction books: 5
Enter Member IDs:
2 3 4 6 7

Enter number of members who borrowed Research Papers: 5
Enter Member IDs:
3 5 6 7 8

========== LIBRARY ANALYSIS MENU ==========
1. Display all borrowing records
2. Fiction UNION Non-Fiction
3. Fiction INTERSECTION Non-Fiction
4. Fiction DIFFERENCE Non-Fiction
5. Fiction INTERSECTION Research
6. Non-Fiction INTERSECTION Research
7. Members borrowing from ALL THREE categories
8. All unique members
9. Exit
===========================================
Enter your choice: 7

Members who borrowed ALL THREE categories:
3 7
```

### Menu options

| # | Option | Operation |
|---|--------|-----------|
| 1 | Display all borrowing records | Print `F`, `N`, `R` |
| 2 | Fiction ∪ Non-Fiction | Union |
| 3 | Fiction ∩ Non-Fiction | Intersection |
| 4 | Fiction − Non-Fiction | Difference |
| 5 | Fiction ∩ Research | Intersection |
| 6 | Non-Fiction ∩ Research | Intersection |
| 7 | Fiction ∩ Non-Fiction ∩ Research | Triple intersection |
| 8 | Fiction ∪ Non-Fiction ∪ Research | Triple union |
| 9 | Exit | Terminate program |

> 📸 *Add a screenshot of your terminal output here:*
> `![Program Output](screenshots/output.png)`

---

## 🗂️ Code Structure

```
.
├── maths.cpp        # Complete source code
├── README.md        # Project documentation
└── (screenshots/)   # Optional: output screenshots
```

### Core functions

| Function | Purpose |
|----------|---------|
| `display(set<int> s)` | Prints all elements of a set, or reports that none were found |
| `findUnion(A, B)` | Returns `A ∪ B` using `set_union` |
| `findIntersection(A, B)` | Returns `A ∩ B` using `set_intersection` |
| `findDifference(A, B)` | Returns `A − B` using `set_difference` |
| `main()` | Handles input, renders the menu, and dispatches operations |

### How the multi-set operations work

Operations on three sets are composed from the two-set functions:

```cpp
// F ∩ N ∩ R
set<int> temp = findIntersection(fiction, nonFiction);
display(findIntersection(temp, research));

// F ∪ N ∪ R
set<int> all = findUnion(fiction, nonFiction);
all = findUnion(all, research);
```

---

## ✅ Test Cases and Verification

Using the model data above, the program output matches the hand-calculated mathematical results for every operation.

| Test | Operation | Expected | Program Result |
|------|-----------|----------|----------------|
| 1 | Display records | `F`, `N`, `R` as defined | ✅ Same |
| 2 | `F ∪ N` | M1, M2, M3, M4, M5, M6, M7 | ✅ Same |
| 3 | `F ∩ N` | M2, M3, M7 | ✅ Same |
| 4 | `F − N` | M1, M5 | ✅ Same |
| 5 | `F ∩ R` | M3, M5, M7 | ✅ Same |
| 6 | `N ∩ R` | M3, M6, M7 | ✅ Same |
| 7 | `F ∩ N ∩ R` | M3, M7 | ✅ Same |
| 8 | `F ∪ N ∪ R` | M1 to M8 | ✅ Same |

---

## ⚠️ Limitations

- Console-only interface (no GUI)
- Stores only member IDs, not full member details
- No persistent storage or database
- No book issue/return dates or overdue tracking
- No authentication
- Limited to three book categories
- Designed as a Set Theory demonstration, not a full library management system

---

## 🔮 Future Scope

- [ ] Database integration for permanent record storage
- [ ] Additional book categories
- [ ] Member details (name, department, contact, membership number)
- [ ] Book details (title, author, ISBN, availability)
- [ ] Issue and return date tracking
- [ ] Overdue analysis
- [ ] Graphical user interface
- [ ] Reports and borrowing-pattern visualization
- [ ] Search functionality for members and books

---

## 📚 References

1. Kenneth H. Rosen, *Discrete Mathematics and Its Applications*, McGraw-Hill.
2. C++ Standard Template Library documentation for `set` and set algorithms.
3. Discrete Mathematics course material, Sanjivani College of Engineering.
4. Class notes on Set Theory and Set Operations.

---

## 👨‍💻 Author

<div align="center">

**Mayur**
B.Tech Computer Science & Engineering, Sanjivani College of Engineering, Shirdi

[![GitHub](https://img.shields.io/badge/GitHub-engineermayur--07-181717?style=for-the-badge&logo=github)](https://github.com/engineermayur-07)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-mgund1920-0A66C2?style=for-the-badge&logo=linkedin)](https://linkedin.com/in/mgund1920)
[![Blog](https://img.shields.io/badge/Blog-engineermayur.blogspot.com-FF5722?style=for-the-badge&logo=blogger&logoColor=white)](https://engineermayur.blogspot.com)

⭐ If you found this project helpful, consider giving it a star!

</div>
