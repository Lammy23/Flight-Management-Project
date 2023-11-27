#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Airline;

class Flight
{

private:
    string flight_id;
    int rows;
    int columns;
    vector<Passenger> passenger_list;
    vector<vector<string>> seat_map;

public:
    Flight(string flight_id, int rows, int columns);
    ~Flight(){};
    Flight(const Flight &flight);
    Flight &operator=(const Flight &flight);

    const string get_flight_id() const { return flight_id; };
    const int get_rows() const { return rows; };
    const int get_columns() const { return columns; };

    void set_flight_id(string flight_id) { this->flight_id = flight_id; };
    void set_rows(int rows) { this->rows = rows; };
    void set_columns(int columns) { this->columns = columns; };

    void add_passenger(Passenger passenger);
    void remove_passenger(Passenger passenger);

    void showFlightSeatMap();
    void showFlightPassengerList();
};

class Passenger
{
private:
    int passengerID;
    string firstName;
    string lastName;
    int phoneNumber;
    Flight *passengerSeat; // FLIGHT CLASS

public:
    Passenger(int id, string fName, string lName, int phone, Seat *seat);
    Passenger(const Passenger &other);
    ~Passenger() {}

    int getPassengerID() const { return passengerID; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    int getPhoneNumber() const { return phoneNumber; }
    Flight *getPassengerSeat() const { return passengerSeat; }

    void setPassengerID(int id) { passengerID = id; }
    void setFirstName(const string &fName) { firstName = fName; }
    void setLastName(const string &lName) { lastName = lName; }
    void setPhoneNumber(int phone) { phoneNumber = phone; }
    // void setPassengerSeat(Seat* seat) { passengerSeat = seat; } // Lami commented this line of code
    void showPassengerInfo(); // Lami added this line of code
};

class Seat
{
private:
    int rowNumber;
    char columnLetter;
    bool status;

public:
    Seat(int rowNum, char colLetter, bool stat);
    Seat(const Seat &other);
    ~Seat() {}
    int getRowNumber() const { return rowNumber; }
    char getColumnLetter() const { return columnLetter; }
    bool getStatus() const { return status; }
    void setRowNumber(int rowNum) { rowNumber = rowNum; }
    void setColumnLetter(char colLetter) { columnLetter = colLetter; }
    void setStatus(bool stat) { status = stat; }
};