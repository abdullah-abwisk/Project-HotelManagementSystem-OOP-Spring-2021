#include "Classes.h"

// Time Class
Time::Time(){
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Time::Time(Time& t){
    hours = t.getHours();
    minutes = t.getMinutes();
    seconds = t.getSeconds();
}

void Time::setTime(){
    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
    cout << "Enter seconds: ";
    cin >> seconds;
}

int Time::getHours(){
    return hours;
}

int Time::getMinutes(){
    return minutes;
}

int Time::getSeconds(){
    return seconds;
}

// Time input/output operator overloading
istream& operator>>(istream& input, Time& time)
{
	time.setTime();
	return input;
}

ostream& operator<<(ostream& output, Time& time)
{
    cout << time.getHours() << ":" << time.getMinutes() << ":" << time.getSeconds();
	return output;
}

// Date Class
Date::Date(){
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(Date& d){
    day = d.getDay();
    month = d.getMonth();
    year = d.getYear();
}

Date& Date::operator+(int d){
    day += d;
    if(day > 30){
        day -= 30;
        month++;
    }
    return *this;
}

void Date::setDate(){
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}

// Date input/output operator overloading
istream& operator>>(istream& input, Date& date)//Inputs the hotel
{
	date.setDate();
	return input;
}

ostream& operator<<(ostream& output, Date& date) //Outputs the time
{
    cout << date.getDay() << "-" << date.getMonth() << "-" << date.getYear();
	return output;
}

// Customer Class
Customer::Customer(){
    full_name = "";
    gender = "";
    ID_card_number = "";
    age = 0;
    balance = 0;
    days_to_reserve = 0;
    room_floor = 0;
    room_number = 0;
    room_type = 0;
}

void Customer::setCustomer(){
    cout << "Enter full name: ";
    getline(cin, full_name);
    getline(cin, full_name);
    cout << "Enter gender: ";
    getline(cin, gender);
    cout << "Enter ID Card Number: ";
    getline(cin, ID_card_number);
    cout << "Enter age: ";
    cin >> age;
}

string Customer::getName(){
    return full_name;
}

string Customer::getGender(){
    return gender;
}

string Customer::getIDCardNumber(){
    return ID_card_number;
}

int Customer::getAge(){
    return age;
}

int Customer::getBalance(){
    return balance;
}

int Customer::getDaystoReserve(){
    return days_to_reserve;
}

int Customer::getRoomFloor(){
    return room_floor;
}

int Customer::getRoomNumber(){
    return room_number;
}

int Customer::getRoomType(){
    return room_type;
}

// Room Class
Room::Room(){
    customer_no = 0;
}

int Room::roomNo(){
    return room_no;
}

bool Room::availability(){
    return available;
}

int Room::customerNo(){
    return customer_no;
}

void Room::setAvailability(bool x){
    available = x;
}

void Room::setCustomerNo(int no){
    customer_no = no;
}

void Room::writefile(ofstream& f){
    f << room_no << " " << available << " " << customer_no << "\n";
}

void Room::readfile(ifstream& f){
    string s;
    getline(f, s, ' ');
    getline(f, s, ' ');
    available = stoi(s);
    getline(f, s, '\n');
    customer_no = stoi(s);
}

Room::~Room(){

}

// Room Types Classes
void Standard::display(){
	cout << room_no << ". Standard Room    Rs. 300/Night    Availability: " << available;
}

Standard::Standard(){
    price_per_day = 300;
    available = 1;
    room_no_iterator++;
    room_no = room_no_iterator;
}

void Moderate::display(){
	cout << room_no << ". Moderate Room    Rs. 500/Night    Availability: " << available;
}

Moderate::Moderate(){
    price_per_day = 500;
    available = 1;
    room_no_iterator++;
    room_no = room_no_iterator;
}

void Superior::display(){
	cout << room_no << ". Superior Room    Rs. 1000/Night    Availability: " << available;
}

Superior::Superior(){
    price_per_day = 300;
    available = 1;
    room_no_iterator++;
    room_no = room_no_iterator;
}

void Junior_Suite::display(){
	cout << room_no << ". Junior Suite Room    Rs. 2000/Night    Availability: " << available;
}

Junior_Suite::Junior_Suite(){
    price_per_day = 1000;
    available = 1;
    room_no_iterator++;
    room_no = room_no_iterator;
}

void Suite::display(){
	cout << room_no << ". Suite Room    Rs. 5000/Night    Availability: " << available;
}

Suite::Suite(){
    price_per_day = 2000;
    available = 1;
    room_no_iterator++;
    room_no = room_no_iterator;
}

// Hotel Class
Hotel::Hotel(){
    rooms = new Room**[5];
    for(int i = 0; i < 5; i++)
        rooms[i] = new Room*[5];
    for(int i = 0; i < 5; i++){
        rooms[i][0] = new Standard[10];
        rooms[i][1] = new Moderate[10];
        rooms[i][2] = new Superior[10];
        rooms[i][3] = new Junior_Suite[10];
        rooms[i][4] = new Suite[10];
    }
}

void Hotel::displayRooms(){
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			for(int k = 0; k < 10; k++){
				rooms[i][j][k].display();
				cout << endl;
			}
}

int Hotel::returnRoom(int floor, int type){
    for(int i = 0; i < 10; i++){
        if(rooms[floor - 1][type - 1][i].availability() == 1){
            return rooms[floor - 1][type - 1][i].roomNo();  
        }  
    }
}

void Hotel::setCustomerNo(int floor, int type, int roomNo, int custNo){
    rooms[floor - 1][type - 1][(roomNo % 10) - 1].setCustomerNo(custNo);
    rooms[floor - 1][type - 1][(roomNo % 10) - 1].setAvailability(0);
}

void Hotel::readRoomsfromFile(){
    ifstream readRooms;
    readRooms.open("rooms.txt");
    for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			for(int k = 0; k < 10; k++){
                rooms[i][j][k].readfile(readRooms);
            }
    readRooms.close();  
}

void Hotel::writeRoomstoFile(){
    ofstream writeRooms;
    writeRooms.open("rooms.txt");
    for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			for(int k = 0; k < 10; k++){
                rooms[i][j][k].writefile(writeRooms);
            }
    writeRooms.close();
}

void Hotel::reservedRooms(){
    cout << "\nReserved rooms: \n";
    for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			for(int k = 0; k < 10; k++){
				if(rooms[i][j][k].availability() == false){
                    rooms[i][j][k].display();
				    cout << endl;
                }
			}
}

int* Hotel::reservedType(){
    int* array = new int[5];
    for(int i = 0; i < 5; i++)
        array[i] = 0;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 10; k++){
                if(rooms[j][i][k].availability() == 0)
                    array[i]++;
            }
    return array;
}