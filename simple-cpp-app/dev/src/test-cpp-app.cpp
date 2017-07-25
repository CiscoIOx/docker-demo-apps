/*
 * Sample code for C++ application that demonstrates the usage of C++ features
 * like classes, inheritance, polymorphism and vectors from the STL library.
 * This application does implement the below tasks and prints:
 * a) the current system date and time
 * b) the factorial of 5 numbers
 * c) the inheritance, polymorphism and a virtual function operations
 * d) the vector elements manipulated by different STL vector operations
 */

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

/*
 * Demonstrating the usage of C++ classes, inheritance, polymorphism and
 * a virtual function using geometric shape example.
 */

/* Base class to represent the geometric shape */
class Shape
{
    public:
        /* Name to represent the type of a shape */
        string name;

        /* A pure virtual function to calculate the area */
        virtual float get_area(void) = 0;

        /* A pure virtual function to calculate the perimeter */
        virtual float get_perimeter(void) = 0;
};

/* Rectangle class which is derived from a base class Shape */
class Rectangle : public Shape
{
    protected:
        /* Variables to store the length and width of a shape */
        float length, width;

    public:
        /* Rectangle class constructor */
        Rectangle(float input_length, float input_width)
        {
            name = "Rectangle";
            length = input_length;
            width = input_width;
        }

		/* Find the area of a rectangle */
        float get_area()
        {
            return (length * width);
        }

        /* Find the perimeter of a rectangle */
        float get_perimeter()
        {
            return ((2 * length) + (2 * width));
        }
};

/* Circle class which is derived from a base class Shape */
class Circle : public Shape
{
    private:
        /* Variable to store the radius of a circle */
        float radius;
        /* Variable to store pi value */
        float pi;

    public:
        /* Set the circle data to find the area and a circumference */
        Circle(float input_radius)
        {
            name = "Circle";
            radius = input_radius;
            pi = 3.14;
        }

        /* Find the area of a circle */
        float get_area()
        {
            return (pi * radius * radius);
        }

        /* Find the perimeter of a circle */
        float get_perimeter()
        {
            return (2 * pi * radius);
        }
};

/* Function to get different geometric shapes */
vector<Shape *>* get_shapes()
{
    /* Vector used to store the shape objects */
    vector<Shape *> *shape_vector = new vector<Shape *>();

    /* Create and store the shape objects in a vector */
    shape_vector->push_back(new Rectangle(5, 6));
    shape_vector->push_back(new Circle(4));
    return shape_vector;
}

/* Function to delete the shapes */
void delete_shapes(vector<Shape *> *shapes)
{
    vector<Shape *>::iterator iter;
    /* Delete the shape objects */
	for(iter = shapes->begin(); iter != shapes->end(); iter++)
    {
        cout << "Deleting: " << (*iter)->name << endl;
        delete (*iter);
    }
}

/* Find the shape's operations like area and perimeter */
void find_shape_operations()
{
    /* Get the shapes */
    vector<Shape *> *shapes = get_shapes();
    vector<Shape *>::iterator iter;

    /* Find the area and perimeter of all the shapes */
    for(iter = shapes->begin(); iter != shapes->end(); iter++)
    {
        cout << "Shape type: " << (*iter)->name << endl;
        cout << "area: " << (*iter)->get_area() << endl;
        cout << "perimeter: " << (*iter)->get_perimeter() << endl;
        cout << endl;
    }

    /* Delete the shapes */
    delete_shapes(shapes);
}

/* Base class for general utility functions */
class Utils
{
    public:
        /* Display the current system date and time */
        void display_date_time()
        {
            /* Variable to store the date and time */
            char* date_and_time;

            /* Get the system time */
            time_t time_now = time(0);

            /* Convert the time into human readable string format */
            date_and_time = ctime(&time_now);

            cout << "Current date and time: " << date_and_time << endl;
        }

        /* Find the factorial of a given number */
        int factorial(int n)
        {
            if (n == 0)
                return 1;
            return n * factorial (n - 1);
        }
};

/* Derived class that uses the base class methods */
class Fact : public Utils
{
    public:
        int i, n;

        /* Print the factorial of 5 numbers */
        void display_factorial()
        {
            cout << "Executing the factorial program: " << endl;
            for (i = 0; i < 5; ++i) {
                n = factorial (i);
                cout << "factorial of " << i << "=" << n << "\n";
                sleep(1);
            }
            cout << endl;
        }
};

/*
 * Global functions which are related to C++ STL vectors
 *
 */

/* Function to display the vector statistics */
void display_vector_stats(vector<string> str_vector)
{
    cout << "size:     " << str_vector.size()     << endl;
    cout << "maxsize:  " << str_vector.max_size() << endl;
    cout << "capacity: " << str_vector.capacity() << endl;
}

/* Function to display the vector elements */
void display_vector_elements(vector<string> str_vector)
{
    /* Display the vector elements separated with spaces */
    copy (str_vector.begin(), str_vector.end(), ostream_iterator<string>(cout," "));
    cout << endl;
}


/*
 * Main function which does execute the below tasks and displays:
 * a) the current system date and time
 * b) the factorial of 5 numbers
 * c) the inheritance, polymorphism and a virtual function operations
 * d) the vector elements manipulated by different STL vector operations
 */
int main()
{
    /* Create a fact class object */
    Fact util;

    /* Variable used to track the iterations */
    int count = 0;

    /* Vector used to store the strings */
    vector<string> str_vector;

    /* Reserve the memory for 7 elements */
    str_vector.reserve(7);

    cout << "Demonstrating the C++ application" << endl;

    cout << "####################################################" << endl;
    /* Display the date and time */
    util.display_date_time();

    /* Display the factorial of 5 numbers */
    util.display_factorial();

    /* Inheritance, polymorphism and a virtual function operations */
    cout << "Executing the Polymorphism, Inheritance operations:" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Geometric Shape Class Operations: " << endl;
    cout << endl;
    find_shape_operations();
    cout << endl;

    /* STL vector operations */
    cout << "Executing the STL vector operations:" << endl;
    cout << "------------------------------------" << endl;
    /* add an elements to the vector */
    str_vector.push_back("This");
    str_vector.push_back("is");
    str_vector.push_back("a");
    str_vector.push_back("C++");
    str_vector.push_back("example");
    str_vector.push_back("STL");
    str_vector.push_back("program");

    /* Display the vector elements */
    cout << "Vector elements:" << endl;
    display_vector_elements(str_vector);
    cout << endl;

    /* Display the vector statistics like size, maxsize etc */
    cout << "Vector statistics:" << endl;
    display_vector_stats(str_vector);

    /* Swap the 4th and 5th elements */
    cout << endl;
    cout << "Vector elements after swapping the 4th and 5th elements:"
         << endl;
    swap(str_vector[4], str_vector[5]);

    /* Display the vector elements after swapping */
    display_vector_elements(str_vector);
    cout << endl;

    /* Insert an element "vector" before the element "program" */
    str_vector.insert (find(str_vector.begin(),str_vector.end(),"program"), "vector");

    /* Display the vector with new elements */
    cout << "Vector elements after inserting the new elements:" << endl;
    display_vector_elements(str_vector);
    cout << endl;

    /* Display the vector new statistics */
    cout << "Vector statistics with new elements:" << endl;
    display_vector_stats(str_vector);

    /* Clear the vector elements */
    str_vector.clear();
}
