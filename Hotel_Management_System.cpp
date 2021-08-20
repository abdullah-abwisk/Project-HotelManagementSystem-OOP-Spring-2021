#include "Classes.cpp"

Hotel hotel;

int main(int argc, char **argv){
	int choice;
    fstream readCustomers, writeCustomers, readRooms;
    // read Rooms from file
    readRooms.open("rooms.txt", ios::in);
    if(!readRooms){

    }
    else
        hotel.readRoomsfromFile();
    readRooms.close();    
	cout << "[          HOTEL MANAGEMENT SYSTEM -> Menu          ]";
	do{
		cout << "\n    1. Press 1 to Reserve a Room\n    2. Press 2 to Checkin a customer/visitor\n    3. Press 3 to View Reserved Rooms\n    4. Press 4 to see detailed report\n    5. Press 5 to exit\n\n Enter your choice: "; // display Menu
	    cin >> choice;
        Customer current_Cust;
        int custno = 0, checkin = 0;
        string n;
	    switch(choice){
	    	case 1:
	    		int ch;
	            cout << "Old customer or new customer: \n1. Old Customer\n2. New Customer\n\nEnter choice: ";
	            cin >> ch;
	            if(ch == 1){ // if for old/new customer
                    readCustomers.open("customers.csv", ios::in);
                    string name;
                    cout << "Enter customer name: ";
                    cin.ignore();
                    getline(cin, name);
                    int floor, room_type;
                    cout << "Choose room floor(1-5): ";
                    cin >> floor;
                    cout << "1. Standard\n2. Moderate\n3. Superior\n4. Junior Suite\n5. Suite\n\nChoose: ";
                    cin >> room_type;
                    int room_no = hotel.returnRoom(floor, room_type);
                    while(!readCustomers.eof()){
                        getline(readCustomers, n, ',');
                        custno++;
                        if(name == n){
                            break;
                        }
                        getline(readCustomers, n, '\n');
                    }
                    readCustomers.close();
                    writeCustomers.open("customers.csv", ios::in | ios::out);
                    for(int i = 1; i < custno; i++)
                        getline(writeCustomers, n, '\n');
                    for(int i = 0; i < 5; i++)
                        getline(writeCustomers, n, ',');
                    writeCustomers << room_no << "," <<  floor << "," <<  room_type;
                    writeCustomers.close();
                    hotel.setCustomerNo(floor, room_type, room_no, custno);
	            }
	            else if(ch == 2){
                    current_Cust.setCustomer();
                    int floor, room_type;
                    cout << "Choose room floor(1-5): ";
                    cin >> floor;
                    cout << "1. Standard\n2. Moderate\n3. Superior\n4. Junior Suite\n5. Suite\n\nChoose: ";
                    cin >> room_type;
                    int room_no = hotel.returnRoom(floor, room_type);
                    writeCustomers.open("customers.csv", ios::out | ios::app);
                    writeCustomers << current_Cust.getName() << "," << current_Cust.getIDCardNumber() << "," << current_Cust.getGender() << "," << current_Cust.getAge() << "," << current_Cust.getBalance() << "," << room_no << "," << floor << "," << room_type << "\n";
                    writeCustomers.close();
                    readCustomers.open("customers.csv", ios::in);
                    while(!readCustomers.eof()){
                        getline(readCustomers, n, ',');
                        custno++;
                        if(current_Cust.getName() == n){
                            break;
                        }
                        getline(readCustomers, n, '\n');
                    }
                    readCustomers.close();
                    hotel.setCustomerNo(floor, room_type, room_no, custno);
                }
	        break;
	        case 2:{
                checkin++;
                string name;
                cout << "\n\nPlease enter customer name: ";
                cin.ignore();
                getline(cin, name);
                readCustomers.open("customers.csv", ios::in | ios::out);
                while(!readCustomers.eof()){
                    getline(readCustomers, n, ',');
                    custno++;
                    if(name == n){
                        break;
                    }
                }
                getline(readCustomers, n, ' ');
                cout << "Enter checkin time: \n";
                Time checkint;
                cin >> checkint;
                Time checkoutt(checkint);
                Date checkind;
                cout << "Enter checkin date: \n";
                cin >> checkind;
                int days_toReserve;
                Date checkoutd(checkind + days_toReserve);
                readCustomers << checkint.getHours() << ":" << checkint.getMinutes() << ":" << checkint.getSeconds() << "," << checkind.getDay() << "-" << checkind.getMonth() << "-" << checkind.getYear() << "," << checkoutd.getDay() << "-" << checkoutd.getMonth() << "-" << checkoutd.getYear();
                readCustomers.close();
	        break;
            }
	        case 3:
                hotel.reservedRooms();
	        break;
	        case 4:
                cout << "[          Detailed Report          ]\n\n";
                cout << "No. of customers checked in today: " << checkin << endl;
                int* ptr = hotel.reservedType();
                cout << "\nReserved rooms: \n";
                cout << "Standard: " << ptr[0];
                cout << "\nModerate: " << ptr[1];
                cout << "\nSuperior: " << ptr[2];
                cout << "\nJunior Suite: " << ptr[3];
                cout << "\nSuite: " << ptr[4] << endl;
                cout << "\nEmpty Rooms: \n";
                cout << "Standard: " << 50 - ptr[0];
                cout << "\nModerate: " << 50 - ptr[1];
                cout << "\nSuperior: " << 50 - ptr[2];
                cout << "\nJunior Suite: " << 50 - ptr[3];
                cout << "\nSuite: " << 50 - ptr[4] << endl;
	        break;
	    }
	}while (choice <= 4 && choice >= 1);
    // save Rooms to file
    hotel.writeRoomstoFile();

	return 0;
}
