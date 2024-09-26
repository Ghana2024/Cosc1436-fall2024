

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

//to create small value for switch
enum MenuCommand
{
    //MC_Begin,
    AddMovie = 1, // const int MenuCommand::MC_AddMovie = 0;
    EditMovie,
    DeleteMovie,
    ViewMovie,
    //MC_End

};
//enum class TestEnum
//{
//    TE_AddMovie
//};
//TestEnum testValue = TestEnum::MC_AddMovie;//MC_AddMovie;//TestEnum::MC_AddMovie;

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

    //Show menu
    cout << "Movie Library" << endl;
    cout << "______________" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    //While-stmt ::= while (Eb) S;
    // Get input
    MenuCommand menuCommand = (MenuCommand)0;
   // bool done = false;
    //while(!done)
    while (menuCommand == 0)
    {
        char input;
        cin >> input;

       // MenuCommand menuCommand;
        //int menuCommand;
        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::ViewMovie; break;

            default: cout << "Bad input" << endl; break;
        };
    };
    cin.ignore();
   // int shouldntWork = MenuCommand::MC_AddMovie;
    //menuCommand = (MenuCommand)1;
    
    
    //Handle menu Command
    switch (menuCommand)
    {
        case MenuCommand::AddMovie:
        case MenuCommand::EditMovie:
        case MenuCommand::DeleteMovie:
        case MenuCommand::ViewMovie: cout << "Not implemented" << endl;break;
    };


    //Add a new movie
    //Create a new Movie
    Movie movie; // { 0 };

    //Get required title
    while (movie.Title == "")
    {
        cout << "Enter a title: ";
       // cin >> movie.Title;
        getline(cin, movie.Title);
        //Decisio making -IF statement
        //If-ststement ::= if (Eb) S
        if (movie.Title == "")
        
            cout << "ERROR: Title is required" << endl;
        
            //cout << "Enter a title: ";
           // getline(cin, movie.Title);
        
    };
    //Get run length, at least 0. minutes
    movie.RunLength = -1;
    while (movie.RunLength < 0 || movie.RunLength > 1440)
    {
        cout << " Enter run length( in Minutes):";
        cin >> movie.RunLength;

       // if (movie.RunLength < 0)
        //{
        //    //Look at additinal stuff .....
        //    if (movie.RunLength < 0)
        //    {
        //        cout << "ERROR: Run length must be at least 0" << endl;

        //        cout << "Enter run length (in minutes): ";
        //        cin >> movie.RunLength;
        //    };
        //}
        // else if (movie.RunLength > 1440)
        //{
        //    cout << "ERROR: Run length cannot be greater than a day " << endl;

        //    cout << "Enter run length (in minutes): ";
        //    cin >> movie.RunLength;
        //};
        if (movie.RunLength < 0 || movie.RunLength > 1440)
        {
            cout << "ERROR: Run length must be between 0 and 1440. " << endl;

            //cout << "Enter run length (in minutes): ";
            //cin >> movie.RunLength;
        };

    };
    
    while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    {
    // Get release year, at least 1900
        cout << " Enter release year(1900+):";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
        {
            cout << "ERROR: Release Year must be between 1900 and 2100" << endl;

           // cout << "Enter Release Year (1900+): ";
            //cin >> movie.ReleaseYear;
        };
    };
    // Get the Optinal Description
    cout << "Enter optional Description:";
    cin.ignore();
    getline(cin, movie.Description);

    //Get Is Classic
    bool done = false;
    while (!done)
    {
        char isClassic;
        cout << "Is this a classic (Y?N)";
        cin >> isClassic;

        //if (isClassic == 'Y')
        //    movie.IsClassic = true;
        //else if (isClassic == 'y')
        //    movie.IsClassic = true;
        //else if (isClassic == 'N')
        //    movie.IsClassic = false;
        //else if (isClassic == 'n')
        //    movie.IsClassic = false;

        /*if (isClassic == 'Y' || isClassic =='y')
            movie.IsClassic = true;
        else if (isClassic == 'N' || isClassic == 'n')
             movie.IsClassic = false;
        else
        {
            cout << "ERROE: You must enter Y or N";
            cout << "Is this a classic (Y/N)? ";
            cin >> isClassic;
        };*/

        //switch (Select) Statement -replacement for if-elseif where same expression compared to multiple values
        //1. Must compare a single expression to one or more constant values with equality
        //2. Switch expression must be an intergral type //can use chararcer but lateral
        //3. Each case label must be a complier-time constant expression
        //4. Each case label must be unique Example Case 
        switch (isClassic)
        {
            //case 'Y':movie.IsClassic = true; break;
            //case 'y':movie.IsClassic = true;  break;
                //OR
                //Fall through works same lanuage is in the next case can be written
            case 'Y':
            case 'y':movie.IsClassic = true; done = true; break;

            case 'N':movie.IsClassic = false; // break;
            case 'n':movie.IsClassic = false; done = true; break;
            //else condition doesnot match then
            default:
            {
                cout << "ERROE: You must enter Y or N";
                //cout << "Is this a classic (Y/N)? ";
                //cin >> isClassic;
            };
        };
    };


    // display movie details
    cout << "-------------------" << endl;
    cout << movie.Title << "(" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;
    cout << "Is Classic? " << movie.IsClassic << endl;
    string classicIndicator;
    //Long form -1
    //if (movie.IsClassic)
     //   classicIndicator = "Yes";
    //else
    //    classicIndicator = "No";
   // cout << "IS Classic?" << classicIndicator << endl;
    //Better but longer form -2

   /* if (movie.IsClassic)
        cout << "Is Classic? Yes" << endl;
    else
        cout << "Is Classic? No" << endl;*/

    //shorter form using conditional operator => Eb ? Et : Ef
  //  string classicIndictor = movie.IsClassic ? "Yes" : "No";
    //cout << "Is Classic?" << classicIndicator << endl;

    //shortest form conditional Operatot => Eb ? Et : Ef
    //Et & Ef =must be the exact same type, type coercion is not allowed
    cout <<"Is classic?" << (movie.IsClassic ? "Yes": "No") << endl;
    if (movie.Description !="")
    cout << movie.Description << endl;

    cout << "-------------------" << endl;
}

