# Disaster and Emergency Aid Management

## Overview
This project aims to facilitate the management of aid and essential items during emergency situations or disasters. The system assists in tracking and organizing needed items for shipment, managing quantities on hand, and storing data for future use.

## Milestones
- **Milestone 1**: Establishes essential classes for managing dates, handling object states, creating menus, and designing a user interface.
- **Milestone 2**: Develops the main menu and a prototype for the aid management system.
- **Milestone 3**: Focuses on core classes - iProduct and Item - to manage products and their quantities.
- **Milestone 4**: Expands functionalities, such as implementing the Perishable class and rule of three, among other features.
- **Milestone 5**: Completes the implementation of the AidMan module and main menu functionalities.

## Project Structure
### Milestone 1
- **Status Class**: Manages the state of an object with description and optional status code.
- **Date Class**: Handles date stamping, validation, and comparison.
- **Utils Module**: Provides utility functions and classes.

### Milestone 2
- **Menu Class**: Represents a user menu with selectable options.
- **AidMan Class**: Prototype controller managing the entire system.

### Milestone 3
- **iProduct Interface**: Abstracts the functionality for products.
- **Item Class**: Concrete implementation of an item, derived from iProduct.

### Milestone 4
- **Perishable Class**: Inherits from the Item class and adds features for handling perishable items.

### Milestone 5
- **AidMan Module**: Fully implements the functionalities of the AidMan class and main menu options.

## Usage
- **StatusTester.cpp**: Tests the Status class functionalities.
- **DateTester.cpp**: Tests the Date class functionalities.
- **iProductTester.cpp**: Tests the iProduct interface functionalities.

## How to Run Tests
1. Compile the respective tester files.
2. Execute the compiled files.
3. Review the console output for test results.

## Installation
Clone the repository to your local machine using:
```bash
git clone https://github.com/Ashwin-BN/OOP222-Project.git
```

## Credits
- **Author**: Ashwin B N
- **Institution**: Seneca College
- **Course**: OOP244
