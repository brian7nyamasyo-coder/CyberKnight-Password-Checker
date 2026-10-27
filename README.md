#  CyberKnight Password Strength Checker

**A C-based cybersecurity tool for password strength analysis, weak-password detection, and security recommendations.**


## Overview

CyberKnight Password Strength Checker is a command-line cybersecurity application developed in C.

It evaluates password characteristics, calculates a heuristic strength score, identifies common weak-password examples, and provides recommendations to improve password security.

The project demonstrates fundamental C programming concepts through a practical defensive cybersecurity application.

## Features

- **Password Length Analysis:** Evaluates password length.
- **Character Detection:** Identifies uppercase letters, lowercase letters, numbers, and special characters.
- **Weak Password Detection:** Checks against a built-in list of common weak passwords.
- **Security Scoring:** Calculates a password strength score out of 100.
- **Strength Classification:** Categorizes passwords as Weak, Moderate, Strong, or Very Strong.
- **Security Recommendations:** Provides suggestions for improving password quality.
- **Interactive Interface:** Allows users to analyze multiple test passwords in one session.

## Technologies Used

- C Programming Language
- GCC Compiler
- Kali Linux
- Standard C libraries

## Project Structure

```text
CyberKnight-Password-Checker/
│
├── main.c
└── README.md
```

## Installation and Usage

### 1. Clone the repository

```bash
git clone https://github.com/brian7nyamasyo-coder/CyberKnight-Password-Checker.git
```

### 2. Navigate into the project

```bash
cd CyberKnight-Password-Checker
```

### 3. Compile the program

```bash
gcc -Wall -Wextra -std=c11 main.c -o cyberknight
```

### 4. Run the application

```bash
./cyberknight
```

## Password Strength Classification

| Score | Classification |
|---|---|
| 0–39 | Weak |
| 40–59 | Moderate |
| 60–79 | Strong |
| 80–100 | Very Strong |

The score is a simplified educational heuristic, not a cryptographic security measurement.

## C Programming Concepts Demonstrated

This project applies:

- Variables and data types
- Arrays and strings
- Pointers
- Functions
- Loops and conditional statements
- String manipulation
- Character classification using `ctype.h`
- User input handling
- Modular program design

## Security Considerations

This application is an educational password-strength estimator.

It does not:
- Verify passwords against breached-password databases.
- Calculate cryptographic password entropy.
- Perform password cracking.
- Guarantee that a password is secure.

The built-in common-password list is limited and should not be treated as comprehensive.

**Privacy:** Use fictional test passwords. The program processes input locally and does not intentionally transmit passwords over a network. Terminal input is visible while typing in this version.

## Future Improvements

Potential future upgrades include:

- More advanced password-strength estimation.
- Larger common-password dictionaries.
- Breached-password checking using privacy-preserving methods.
- Improved password-pattern detection.
- Secure hidden terminal input.
- File-based security reports.
- A graphical user interface.

## Developer

**Brian Nyamasyo**

Computer Science Student | Cybersecurity Enthusiast

GitHub: [@brian7nyamasyo-coder](https://github.com/brian7nyamasyo-coder)

##Disclaimer

This project was developed for educational and defensive cybersecurity purposes. It is not intended to replace professional password-security auditing tools.

---

**CyberKnight Security — Building practical defensive cybersecurity tools with C.**
