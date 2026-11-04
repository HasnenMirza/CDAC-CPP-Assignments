#include <iostream>
#include <cstring>
using namespace std;

class Booking {
    static int count;

    private:
        int B_id;
        char* source;
        char* destination;
        float fare;
        int total_dist;

    public:
        // Default Constructor (with default values)
        Booking() {
            B_id = ++count;
            const char* defaultSrc = "xyz";
            const char* defaultDest = "abc";

            source = new char[strlen(defaultSrc) + 1];
            strcpy(source, defaultSrc);

            destination = new char[strlen(defaultDest) + 1];
            strcpy(destination, defaultDest);

            total_dist = 0;
            fare = 0.0f;
        }

        // Parameterized Constructor with default distance
        Booking(const char* s, const char* d, int dist = 0) {
            B_id = ++count;

            source = new char[strlen(s) + 1];
            strcpy(source, s);

            destination = new char[strlen(d) + 1];
            strcpy(destination, d);

            total_dist = dist;
            fare = calculateFare(dist); // set initial fare based on distance
        }

        // Copy Constructor (Deep Copy)
        Booking(const Booking& other) {
            B_id = ++count;

            source = new char[strlen(other.source) + 1];
            strcpy(source, other.source);

            destination = new char[strlen(other.destination) + 1];
            strcpy(destination, other.destination);

            total_dist = other.total_dist;
            fare = other.fare;
        }

        // Destructor
        ~Booking() {
            delete[] source;
            delete[] destination;
        }

        // ----------------- Function Overloading: calculateFare -----------------

        // 1. Calculate fare based only on distance travelled
        float calculateFare(int dist) {
            total_dist = dist;
            fare = dist * 10.0f; // Base rate: 10 per km
            return fare;
        }

        // 2. Calculate fare based on distance and vehicle type
        // Vehicle Types: 'S' = Sedan (1.2x multiplier), 'U' = SUV (1.5x multiplier), default = 1.0x
        float calculateFare(int dist, char vehicleType) {
            total_dist = dist;
            float multiplier = 1.0f;
            if (vehicleType == 'S' || vehicleType == 's') multiplier = 1.2f;
            else if (vehicleType == 'U' || vehicleType == 'u') multiplier = 1.5f;

            fare = (dist * 10.0f) * multiplier;
            return fare;
        }

        // 3. Calculate fare based on distance, vehicle type, and number of passengers
        float calculateFare(int dist, char vehicleType, int passengers) {
            float baseFare = calculateFare(dist, vehicleType);
            float passengerFee = passengers * 50.0f; // 50 extra per passenger
            fare = baseFare + passengerFee;
            return fare;
        }

        // 4. Calculate fare for premium booking with service charges
        float calculateFare(int dist, char vehicleType, int passengers, float serviceCharge) {
            float baseFare = calculateFare(dist, vehicleType, passengers);
            fare = baseFare + serviceCharge;
            return fare;
        }

        // ----------------- Setters -----------------
        void setSource(const char* s) {
            delete[] source;
            source = new char[strlen(s) + 1];
            strcpy(source, s);
        }

        void setDestination(const char* d) {
            delete[] destination;
            destination = new char[strlen(d) + 1];
            strcpy(destination, d);
        }

        void setTotalDist(int d) {
            total_dist = d;
            calculateFare(total_dist);
        }

        void setFare(float f) {
            fare = f;
        }

        // ----------------- Getters -----------------
        int getBookingId() const { return B_id; }
        const char* getSource() const { return source; }
        const char* getDestination() const { return destination; }
        int getTotalDist() const { return total_dist; }
        float getFare() const { return fare; }

        // ----------------- Operator Overloading -----------------

        // Input Operator >>
        friend istream& operator>>(istream& in, Booking& b) {
            char tempSrc[100], tempDest[100];
            cout << "Enter Source: ";
            in >> tempSrc;
            cout << "Enter Destination: ";
            in >> tempDest;
            cout << "Enter Distance (in km): ";
            in >> b.total_dist;

            b.setSource(tempSrc);
            b.setDestination(tempDest);
            b.calculateFare(b.total_dist);

            return in;
        }

        // Output Operator <<
        friend ostream& operator<<(ostream& out, const Booking& b) {
            out << "\n--- Booking Details ---" << endl;
            out << "Booking ID: " << b.B_id << endl;
            out << "Source: " << b.source << endl;
            out << "Destination: " << b.destination << endl;
            out << "Total Distance: " << b.total_dist << " km" << endl;
            out << "Total Fare: $" << b.fare << endl;
            return out;
        }
};

// Static Counter Definition
int Booking::count = 0;

int main() {
    // 1. Parameterized Constructor
    Booking b1("New York", "Boston", 215);
    cout << b1;

    cout << "\n--- Testing calculateFare() Overloads ---" << endl;

    // Overload 1: Distance only
    cout << "Fare (Distance only: 100km): $" << b1.calculateFare(100) << endl;

    // Overload 2: Distance + Vehicle Type ('U' for SUV)
    cout << "Fare (Distance 100km + SUV): $" << b1.calculateFare(100, 'U') << endl;

    // Overload 3: Distance + Vehicle Type + Passengers
    cout << "Fare (100km + SUV + 3 Passengers): $" << b1.calculateFare(100, 'U', 3) << endl;

    // Overload 4: Premium (Distance + Vehicle Type + Passengers + Service Charge)
    cout << "Fare (Premium: 100km + SUV + 3 Passengers + $50 Service Charge): $" 
         << b1.calculateFare(100, 'U', 3, 50.0f) << endl;

    // 2. Copy Constructor Test
    Booking b2 = b1;
    cout << "\n--- Copied Booking (b2) ---" << b2;

    // 3. Testing >> Operator
    cout << "\n--- Enter New Booking Details ---" << endl;
    Booking b3;
    cin >> b3;
    cout << b3;

    return 0;
}