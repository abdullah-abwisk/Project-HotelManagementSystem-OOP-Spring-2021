#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Time{
    int hours, minutes, seconds;
    public:
    Time();
    Time(Time&);
    void setTime(); // Function to set Time
    // Time getters
    int getHours();
    int getMinutes();
    int getSeconds();
};

class Date{
    int day, month, year;
    public:
    Date();
    Date(Date&); // Date Copy Constructor
    Date& operator+(int); // Date operator+ overloading
    void setDate(); // Function to set Date
    // Date getters
    int getDay();
    int getMonth();
    int getYear();
};

class Customer{
    string full_name, gender, ID_card_number;
    int age, balance, days_to_reserve, room_floor, room_number, room_type;
    Time check_in_time, check_out_time, time_remaining;
    Date check_in_date, check_out_date;
    public:
    Customer();
    void setCustomer(); // Function to set Customer
    // Customer getters
    string getName(); 
    string getGender();
    string getIDCardNumber();
    int getAge();
    int getBalance();
    int getDaystoReserve();
    int getRoomFloor();
    int getRoomNumber();
    int getRoomType();
};

class Room{
    protected:
    int price_per_day;
    bool available;
    int room_no;
    int customer_no;
    static int room_no_iterator; // Static iterator to set room numbers
    Customer* curr_customer;
    public:
    virtual void display() = 0; // Pure virtual function 
    Room();
    // Room getters
    int roomNo();
    bool availability();
    int customerNo();
    // Room setters
    void setAvailability(bool);
    void setCustomerNo(int);
    // Write/Read rooms from file
    void writefile(ofstream& f);
    void readfile(ifstream& f);
    virtual ~Room();
};

int Room::room_no_iterator = 0; 

class Standard: public Room{
    public:
    void display();
    Standard();
};

class Moderate: public Room{
    public:
    void display();
    Moderate();
};

class Superior: public Room{
    public:
    void display();
    Superior();
};

class Junior_Suite: public Room{
    public:
    void display();
    Junior_Suite();
};

class Suite: public Room{
    public:
    void display();
    Suite();
};

class Hotel{
    Room*** rooms;
    public:
    Hotel();
    void displayRooms(); // display all rooms
    int returnRoom(int floor, int type); // return free room on floor
    void setCustomerNo(int floor, int type, int roomNo, int custNo); // set customer to room
    // Write/Read rooms from file
    void readRoomsfromFile();
    void writeRoomstoFile();
    void reservedRooms(); // display reserved rooms
    int* reservedType(); // return reserved rooms and their types
};
