**Object Oriented Programming Techniques**

**Lab – 1**

**Task 1**

Write a program that defines a class named **Point2D**. The class should have two integer member variables, x and y, to represent the coordinates of a point in 2D space.

Inside the class, create a method to display the values of x and y.

In the main function:

1.  Create an instance of the **Point2D** class.
2.  Set values for x and y.
3.  Use the method you created to print the values of x and y.

**Task 2**

Write a program that defines a class named **Student** with the following features:

1.  **Member Variables**:
    *   name (string): The name of the student.
    *   ERP (integer): The ERP number of the student.
    *   StudentCount (integer): A static variable that keeps track of the total number of Student instances created. This variable should increment by 1 every time a new **Student** object is instantiated.
2.  **Public Methods**:
    *   getCount(): A method that returns the current value of StudentCount.
    *   output(): A method that displays the details of the student, including name and ERP.
3.  **Main Function**:
    *   Create multiple instances of the **Student** class, providing a name and ERP for each.
    *   Use the getCount() method to display the total number of students created after instantiating the objects.

**Task 3**

Create a class Product to manage the details of products in an inventory system. The class should have the following features:

### 1\. **Member Variables**:

*   name (string): The name of the product.
*   price (double): The price of the product.
*   stock (integer): The quantity of the product available in stock.

### 2\. **Methods**:

*   addStock(quantity): Increases the stock by the given quantity.
*   reduceStock(quantity): Decreases the stock by the given quantity if there are enough items in stock; otherwise, display an error message indicating that there is insufficient stock.
*   displayDetails(): Prints the product’s name, price, and current stock.

### 3\. **Main Function**:

*   In the main function, create multiple instances of the Product class.
*   Simulate adding and reducing stock for each product.
*   Display the details of each product after performing the stock operations.

**Task 4**

Write a program that defines a class named Rectangle with the following features:

1.  **Member Variables**:
    *   x (integer)
    *   y (integer)
2.  **Methods**:
    *   calculateArea(): A method that calculates the area of the rectangle and outputs the result.
    *   calculatePerimeter(): A method that calculates the perimeter of the rectangle and outputs the result.
3.  **Main Function**:
    *   Create an instance of the Rectangle class and assign values to its member variables.
    *   Call both calculateArea() and calculatePerimeter() to display the rectangle’s area and perimeter.

**Task 5**

You are tasked with creating a **Library Management System**. The library has books, members, and librarians. Each of these plays a specific role in the system.

**Requirements**

1.  **Books**
    *   Each book has a title, author, and a unique book ID.
    *   A book can either be available or borrowed by a member.
2.  **Members**
    *   Members have a name and a unique member ID.
    *   Members can borrow up to 3 books at a time.
3.  **Librarians**
    *   Librarians are responsible for managing the library.
    *   They can add new books to the system or remove old ones.
4.  **System Features**
    *   Allow members to borrow and return books.
    *   Let librarians add or remove books.

**Your Tasks**

1.  Identify the **classes** needed for this system.
2.  Determine the **attributes** (fields) for each class.
3.  Decide what **methods** (functions) each class should have.