#include <iostream> //for basic input output libary so I can use basic things like cin or cout
#include <cmath> // for calulations
#include <string> // So I can use strings as a datatype
#include <iomanip> //just used for fixed and setprecision so I don't get crazy long numbers when the stats get displayed. It also was used for
using namespace std;
int main() {
    double paint_price = 0.0;
    char paint_brand_choice = '\0';
    string paint_brand;
    double wall_paint_coverage_gallon = 350.0; //this is all just the initialized variables
    int number_of_walls;
    int number_of_rooms;
    string room_name;
    double total_area_project = 0.0;

    cout << "Hello! This is your one stop to calculating" << endl; 
    cout << "how much paint you would need, to paint as many room as you wish." << endl;  //intro words to application with instructions
    cout << "Please make a selection on which paint brand you wish to use" << endl;

    // This code lets the user choose a brand or enter a custom paint price. but if they choose a selected brand it comes with a built in price point
    cout << " A - selection to input your paint brand and price" << endl;
    cout << " B - Behr Premium Plus" << endl;
    cout << " C - Sherwin-Williams SuperPaint" << endl;
    cout << " D - Benjamin Moore Regal Select" << endl;
    cout << " E - Valspar Signature" << endl;
    cout << " F - PPG Timeless" << endl;
    cin >> paint_brand_choice;
    switch (paint_brand_choice) //here are the switch cases that are activated based off input, each selection has a lowercase option incase someone doesn't want to capitilize their letters
    {
    case 'A':
    case 'a':
    cout << "Input your paint brand: " << endl;
    cin >> paint_brand;
    cout << "Input your paint Price: " << endl;
    cin >> paint_price;
    break; // after every selection, the price gets set and the brand gets inputed then this section ends with the variables now holding valuable information
    case 'B':
    case 'b':
    cout << "You have selected Behr Premium Plus" << endl;
        paint_brand = "Behr Premium Plus";
        paint_price = 45.98;
        cout << "Your paint price is: " << paint_price << endl;
        break;
    case 'C':
    case 'c':
        paint_brand = "Sherwin-Williams SuperPaint";
        paint_price = 72.99;
        break;
    case 'D':
    case 'd':
        paint_brand = "Benjamin Moore Regal Select";
        paint_price = 46.98;
        break;
    case 'E':
    case 'e':
        paint_brand = "Valspar Signature";
        paint_price = 46.98;
        break;
    case 'F':
    case 'f':
        paint_brand = "PPG Timeless";
        paint_price = 49.98;
        break;    
    default:
        cout << "Unknown brand selected." << endl;
        return 1;
        break;
    }
    
    cout << "Price per gallon for " << paint_brand << ": $" << paint_price << endl; //this is just gathering more info about the rooms
    cout << "\nHow many rooms will be painted? ";
    cin >> number_of_rooms;
    
    
    for (int i = 1; i <= number_of_rooms; i++) { // This is just a for Loop used to add up all wall areas from all rooms. It starts at 1 and not 0 because if your
    double total_area_Rooms = 0.0;// using this program then you have at least 1 wall space within a room that needs to be painted 
    cout << "\n--- Room " << i << " ---" << endl;
    cout << "Enter the room's name: "; //more instructions of room name, just to keep stuff organized so the user knows which room is which
    cin.ignore(); // just to ignore leftover space
    getline(cin, room_name); // just using a getline to grab the whole line of string and not just a portion from the user incase they input something like "Zeus's new cool room"

    cout << "How many walls are in " << room_name << "?"; // just more basic questions that's important to know
    cin >> number_of_walls;

    for (int x = 1; x <= number_of_walls; x++) {
        double wall_width = 0.0; // This is a regular for loop but since I used i already, I used x. The purpose for this for loop is to gather and update number of walls
        double wall_height = 0.0;

        cout << " Wall " << x << " - - Enter width (feet): ";
        cin >> wall_width;
        cout << " Wall " << x << " - Enter height (feet): ";
        cin >> wall_height;

        total_area_Rooms += wall_width * wall_height;
    }
    
    
    double total_gallons_needed = total_area_Rooms / wall_paint_coverage_gallon;// Convert square feet to gallons, then rounds up to whole number.
    int total_containers_needed = static_cast<int>(ceil(total_gallons_needed));
    double total_cost = total_gallons_needed * paint_price;
    total_area_project += total_area_Rooms;

    cout << "\n==========" << endl;
    cout << "Brand selected: " << paint_brand << endl;
    cout << "Price per gallon: $" << paint_price << endl;
    cout << "Total wall area that needs to be painted: " <<total_area_Rooms << " SQ ft" << endl;// just outputting the information to the user
    cout << "Total gallons needed: " << total_gallons_needed << " Gallons" << endl;
    cout << "Total paint containers needed: " << total_containers_needed << endl;
    cout << "Total cost: $" << total_cost << endl;
}

    
    double project_gallons_needed = total_area_project / wall_paint_coverage_gallon; // logic for figuring out how much paint is needed. takes all the wall area and divides by paint coverage
    int project_containers_needed = static_cast<int>(ceil(project_gallons_needed)); // tells how many containers are needed, rounded of course
    double project_total_cost = project_gallons_needed * paint_price; // total cost of paint needed, calculated by total paint containers needed times the price of the paint.

    cout << "\n=============" << endl;
    cout << "Total wall area for all rooms: " << total_area_project << " Sq ft" << endl;
    cout << fixed << setprecision (4) <<"Total gallons of paint needed for all rooms: " << project_gallons_needed << " Gallons" << endl;
    cout << "Total paint containers needed for all rooms: " << project_containers_needed << endl;// here is where it gets fully outputted
    cout << fixed << setprecision (2) <<"Total cost for paint used for walls: $" << project_total_cost << endl;
    cout << "Total cost of needed paint: " << paint_price * project_containers_needed << endl;
    return 0;
}