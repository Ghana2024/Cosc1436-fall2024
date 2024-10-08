

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

    string Genre;
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


int main()
{
    //Nested loop menu
    int iterations = 0;
    for (int i = 0;i < 100;++i)
    {
       /* if (i != 0)
        {
            char choice;
            cout << "Do you want to give up?";
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
                break;
        };*/
        for (int j = 0;j < 10;++j)
        {
            if (iterations % 100 == 0)
            {
                char choice;
                cout << "Do you want to give up?";
                cin >> choice;
                if (choice == 'Y' || choice == 'y')
                    break;
            };
            ++iterations;
            cout << i << ", " << j << " = " << iterations << endl;
        };
    };
    cout << "Total iteraitons = " << iterations << endl;
  

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
    do 
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
    } while (menuCommand == 0);
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
   // while (movie.Title == "")
    do
    {
        cout << "Enter a title: ";
       // cin >> movie.Title;
        getline(cin, movie.Title);
        //Decisio making -IF statement
        //If-ststement ::= if (Eb) S
        if (movie.Title == "")

            cout << "ERROR: Title is required" << endl;

           

    } while (movie.Title == "");
    //Get run length, at least 0. minutes
    //movie.RunLength = -1;
    do//while (movie.RunLength < 0 || movie.RunLength > 1440)
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

    } while (movie.RunLength < 0 || movie.RunLength > 1440);
    
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

        switch (isClassic)
        {
            case 'Y':
            case 'y':movie.IsClassic = true; done = true; break;

            case 'N':movie.IsClassic = false; // break;
            case 'n':movie.IsClassic = false; done = true; break;
            //else condition doesnot match then
            default:
            {
                cout << "ERROE: You must enter Y or N";
                
            };
        };
    };
    cin.ignore();

    

    for (int index = 0; index < 5; ++index) // =0, <N (rarely) =1, <=N
    {
        cout << "Enter optional genre: " << (index + 1) << ": ";
        string genre;
        getline(cin, genre);
        if (genre != "")

            break; //Exits the loop
       // continue; //Loops only - stops the current iteration and loops again
        movie.Genre += genre + ", ";

    };

   

    cout << "-------------------" << endl;
    cout << movie.Title << "(" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;
    cout << "Is Classic? " << movie.IsClassic << endl;
    string classicIndicator;
    
    cout <<"Is classic?" << (movie.IsClassic ? "Yes": "No") << endl;
    if (movie.Genre != ")");
    cout << "Genres " << movie.Genre << endl;
    if (movie.Description !="")
    cout << movie.Description << endl;

    cout << "-------------------" << endl;
}

