# 🚀 C++ Object-Oriented Programming (OOP) Journey

Welcome to my C++ OOP learning repository! 👋

This repository documents my journey in mastering **Object-Oriented Programming** concepts using C++. It contains a collection of mini-projects ranging from basic Class/Object instantiation to complex Polymorphism and Memory Management.

## 🧠 Key Concepts Covered
In this repository, I demonstrated practical implementation of:
- **Classes & Objects**: Blueprints, Instantiation, and Memory allocation.
- **Encapsulation**: Data hiding using `private`, `protected`, and `public` access modifiers.
- **Inheritance**: Parent-Child class relationships and Constructor Chaining.
- **Polymorphism**: Virtual functions, Method Overriding, and Dynamic Binding.
- **Pointers & Memory**: Managing Array of Pointers and dynamic object creation (`new`).
- **Logic Building**: Input validation, Loops, and Control Flow (Menu Systems).

---

## 📂 Project List

Here is the breakdown of the source codes included in this repository:

### 1. Basic Class & Logic (`01_basic_class.cpp`)
* **Description**: A simple introduction to defining classes and creating objects.
* **Key Learning**: Syntax structure, Attributes, and Methods.

### 2. Secure ATM System (`02_encapsulation_atm.cpp`)
* **Description**: A simulation of a Bank ATM where `saldo` (balance) is protected.
* **Features**: Check Balance, Deposit, and Withdraw with validation logic.
* **Key Learning**: **Encapsulation**. Using Getter/Setter methods to protect sensitive data from direct access.

### 3. Tamagotchi / Virtual Pet (`03_logic_tamagotchi.cpp`)
* **Description**: An interactive pet simulator. The pet has states (Hunger, Energy, Happiness) that change based on user interaction.
* **Features**: Feeding, Playing, Sleeping, and complex status validation (clamping values between 0-100).
* **Key Learning**: Game Logic implementation within Class Methods.

### 4. Corporate Payroll System (`04_inheritance_payroll.cpp`)
* **Description**: An employee salary calculation system for PT. Maju Mundur.
* **Features**: Calculates salary based on roles (**Manager** vs **Sales**) using a base `Karyawan` class.
* **Key Learning**: **Inheritance**. Using `protected` access modifier and Constructor Chaining (passing data from Child to Parent constructor).

### 5. Smart Home & Cinema System (`05_polymorphism_final.cpp`)
* **Description**: The final project simulating a Cinema Ticketing System (Regular vs Premiere) and Smart Home Devices.
* **Features**: 
    - Inputting multiple orders into a shopping cart.
    - Printing different ticket types using a single command.
    - Menu looping (`do-while`).
* **Key Learning**: **Polymorphism**. Using `virtual` functions, `override`, and **Array of Pointers** to manage different objects uniformly.

---

## 🛠️ How to Run
You can compile these files using any C++ compiler (like GCC/G++).

**Example using Terminal/Command Prompt:**
```bash
# 1. Compile the file (e.g., the Cinema project)
g++ 05_polymorphism_final.cpp -o cinema_app

# 2. Run the program
./cinema_app
