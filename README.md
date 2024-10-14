# Hospital Management System

## Project Overview

The **Hospital Management System** is a project designed to streamline operations in hospitals, clinics, and dispensaries. It enhances administration, control, and patient care while maintaining strict cost control and improving overall profitability. The system is built using C++ with Object-Oriented Programming principles, and it leverages a MySQL database to store and manage information efficiently.

This project enables hospital staff to manage patients, doctors, staff, billing, and more through an easy-to-use interface.

## Features

- **Patient Management**: The system records details about patients, including admission/discharge information, unique patient IDs, and bed availability.
- **Doctor Management**: Doctors' information is stored, including availability, experience, and fees. Patients can search for and select doctors based on these factors.
- **Staff Management**: The system keeps track of staff members, including their past, present, and future records.
- **Billing and Pharmacy**: The system automatically calculates and stores expenses for each patient, including medication and services. It creates transparency by allowing patients to view their bills.
- **Secure Access**: The system can be accessed only by authorized personnel (administrators or receptionists), ensuring data privacy and security.

## Block Diagram

The system follows a simple flow where users (admin/receptionist) input data related to doctors, patients, and staff. This data is processed and stored in a MySQL database, which can be retrieved when necessary.

## Technologies Used

- **Programming Language**: C++ (Object-Oriented Programming)
- **Database**: MySQL,Sqlite3 (for storing hospital records)
- **IDE**: Visual Studio Code

## Installation

1. **Clone the repository**:
    ```bash
    git clone https://github.com/shuklaAlkesh/Hospital-Management-system-C--oops-project.git
    ```
2. **Set up MySQL**:
   - Install MySQL on your local machine.
   - Create a database for the system and configure it to store information related to patients, doctors, staff, and billing.

3. **Compile and Run the Project**:
   - Open the project in **Visual Studio Code** or any C++ IDE.
   - Compile the code and run the program.

## Usage

- **Login**: The system can be accessed only by administrators or receptionists via a username and password.
- **Add Records**: You can add new patient records, doctor details, or staff information through a user-friendly interface.
- **Search and View Records**: You can search for existing patient records, check doctor availability, and view patient billing information.
- **Billing System**: The cost of medicines and services is automatically added to the patient's bill. The system ensures transparency by allowing patients to view their expenses.

## Expected Output

The project aims to digitize most hospital records, improving efficiency by reducing paperwork and manual errors. Key features include:

- Automated patient admission/discharge processes.
- Doctor selection based on patient preferences.
- Detailed record keeping for staff and medical expenses.
- Secure, user-friendly access for hospital administration.

---

This project was developed as part of the **Object-Oriented Programming Course** at **Indian Institute of Information Technology, Sri City**, under the guidance of **Dr. Pavan Kumar BN**.
