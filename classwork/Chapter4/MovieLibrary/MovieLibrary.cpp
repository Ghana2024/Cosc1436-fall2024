

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
 // Movie: Title, Actors, Run length, Description, Genres, Director(s), Release Year, MPAA Rating
struct Movie
{
    //Required
    string Title;

    // At least 0, minutes
    int RunLength;

    //Optional
    string Description;

    // >=1900
    int ReleaseYear;

    bool IsClassic;
};

int main()
{
   // //Relational demo
   // //rel_op ::= < <= > >= == !=
   // //rel_expr ::= E rel_op E (boolean)

   // //int left, right;
   // string left, right;
   // std::cout << "Enter a left and right value: ";
   // std::cin >> left >> right;

   // //Mangle the values
   // //Do not use == equality floating point values to avoid rounding errors
   // // Except when comparing floating point value to an integral (e.g f== 45)
   //
   // //left = (left * 21) / 21;
   // //right = (right * 15) / 15;
   //
   // //bool areEqual = left = right;//Assign left and right value the same
   //// cout << left << " == " << right << " = " << (left = right) << endl;
   //// bool areEqual = left = right ==20;
   //// bool areEqual = left = 20 = right;

   // // string comparision is case insensitive
   // //strcmpi(string, string) => int
   // // when using c++ strings specify value as 'expr' .c_str()
   // //returns < 0 if left < right
   // //         =0 if left == right
   // //         > 0 if left > right
   // cout << left << " ciequal " << right << " = " << _strcmpi(left.c_str(), right.c_str()) << endl;

   // cout << left << " < " << right << " = " << (left < right) << endl;
   // cout << left << " <= " << right << " = " << (left <= right) << endl;
   // cout << left << " > " << right << " = " << (left > right) << endl;
   // cout << left << " <= " << right << " = " << (left >= right) << endl;
   // cout << left << " == " << right << " = " << (left == right) << endl;
   // cout << left << " != " << right << " = " << (left != right) << endl;
   // cout << endl;


   
    //Decision making - IF statement
    // if-stmt :: = if (Eb) S

    //Add a new movie
    //Create a new Movie
    Movie movie; // { 0 };

    //Get required title
    cout << "Enter a title: ";
   // cin >> movie.Title;
    getline(cin, movie.Title);

    if (movie.Title == "")
    {
        cout << "ERROR: Title is required" << endl;

        cout << "Enter a title: ";
        getline(cin, movie.Title);
    };
    //Get run length, at least 0. minutes
    cout << " Enter run length( in Minutes):";
    cin >> movie.RunLength;
    
    if (movie.RunLength < 0)
    {
        cout << "ERROR: Run length must be at least 0" << endl;

        cout << "Enter run length (in minutes): ";
        cin >> movie.RunLength;
    };
    // Get release year, at least 1900
    cout << " Enter release year(1900+):";
    cin >> movie.ReleaseYear;

    if (movie.ReleaseYear < 1900)
    {
        cout << "ERROR: Release Year must be at least 1900" << endl;

        cout << "Enter Release Year (1900+): ";
        cin >> movie.ReleaseYear;
    };
    // Get the Optinal Description
    cout << "Enter optional Description:";
    cin.ignore();
    getline(cin, movie.Description);

    //Get Is Classic
    char isClassic;
    cout << "Is this a classic (Y?N)";
    cin >> isClassic;

    if (isClassic == 'Y')
        movie.IsClassic = true;
    if (isClassic == 'y')
        movie.IsClassic = true;
    if (isClassic == 'N')
        movie.IsClassic = false;
    if (isClassic == 'n')
        movie.IsClassic = false;

    // display movie details
    cout << "-------------------" << endl;
    cout << movie.Title << "(" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;
    cout << "Is Classic? " << movie.IsClassic << endl;
    cout << movie.Description << endl;
}

