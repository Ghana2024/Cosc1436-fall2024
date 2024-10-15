
/*#include <iostream>
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
// function defination -defines functions what it does
//declaration ::= declare the existence of something and what it is (eg; var declaration) Example- MenuCommand menuCommand = (MenuCommand)0;
//              used by the complier to recongnize tohe use of the identifier( for complier)
//              must be declared before usage
// definition ::= what it does (var defined), function body inside the curly braces ( for linker)
//Function names are verbs representing actions,
//Casing: Pascal casing, camel casing 


MenuCommand g_menuCommand = (MenuCommand)0;//global variable
/// Display main menu
void DisplayMenu()
{
    cout << "Movie Library" << endl;
    cout << "______________" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;
   
   MenuCommand menuCommand = (MenuCommand)0;
   void AddMovie()
   {
       cout << "AddMovie" << endl;
   }
   void DeleteMovie()
   {
       cout << "AddMovie" << endl;
   }
   void EditMovie()
   {
       cout << "AddMovie" << endl;
   }
   void ViewMovie()
   {
       cout << "AddMovie" << endl;
   }


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
    //HACK: Don't do this
    g_menuCommand = menuCommand;//don't do it
}

/// Handles the menu selection
void HandleMenu(MenuCommand menuCommand)
{
    //HACK: Fix this 
   // MenuCommand menuCommand = (MenuCommand)0;
    switch (menuCommand)
    {
        case MenuCommand::AddMovie: AddMovie(); break;
        case MenuCommand::EditMovie : EditMovie(); break;
        case MenuCommand::DeleteMovie: DeleteMovie(); break;
        case MenuCommand::ViewMovie: ViewMovie();break;
    };
}

int main()
{
    //Function call ::=id();
    DisplayMenu();
    
    //// Get input
   
    
    ////Handle menu Command
    HandleMenu(g_menuCommand);//global look like
   
   
    //Add a new movie
    //Create a new Movie
    Movie movie; // { 0 };

    //Get required title
   // while (movie.Title == "")
    do
    {
        cout << "Enter a title: ";
   
        getline(cin, movie.Title);
       
        if (movie.Title == "")

            cout << "ERROR: Title is required" << endl;       
    } while (movie.Title == "");
    //Get run length, at least 0. minutes
    //movie.RunLength = -1;
    do//while (movie.RunLength < 0 || movie.RunLength > 1440)
    {
        cout << " Enter run length( in Minutes):";
        cin >> movie.RunLength;

       
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
}*/


/*
include <iostream>
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

    // >= 1900
    int ReleaseYear;

    bool IsClassic;

    string Genre;
};

//Integral data type with named values
enum MenuCommand
{
    //MC_Begin,
    MC_AddMovie = 1,    //const int MenuCommand::MC_AddMovie = 0;
    MC_EditMovie,
    MC_DeleteMovie,
    MC_ViewMovie,
    //MC_End
};

// function ::= Reusable block of code
//              Benefits: reusability, maintainability, readability, security
// function definition - Defines a function and what it does (for linker)
// declaration ::= Declares the existence of something and what it is (var declaration)
//                 Used by the compiler to recognize the use of the identifier
//                 Must be declared before usage
// 
// Function names are verbs representing actions
//   Casing: Pascal casing, camel casing

// Parameters - data passed to a function
// parameter-list ::= parameter { , parameter }*
// parameter      ::= T [ id ]

//HACK: Don't do this
MenuCommand g_menuCommand = (MenuCommand)0;
Movie g_movie;



/// Reads a string from input
/// @param message Message to display
/// @param isRequired True if the value is required
/// @return Input from user
string ReadString(string message, bool isRequired)
{
    string input;
    do
    {
        cout << "message ";
        getline(cin, input);

        if (isRequred && input == "")
            cout << "ERROR: Title is required" << endl;
    } while (isRequired && input == "");
    return input;
}

///@breif Reads a string from input
/// @param message Message to display
/// @return Input from user
string ReadString(string message, bool isRequired)
{
    return ReadString(message, false);
}
void AddMovie()
{
    Movie movie;

    //Get required title
    movie.Title = ReadString("Enter a title: ", true);
    /*do
    {
        cout << "Enter a title: ";
        getline(cin, movie.Title);

        if (movie.Title == "")
            cout << "ERROR: Title is required" << endl;
    } while (movie.Title == "");*/

    //Get run length, at least 0, minutes
  /* do
    {
        cout << "Enter run length (in minutes): ";
        cin >> movie.RunLength;

        if (movie.RunLength < 0 || movie.RunLength > 1440)
            cout << "ERROR: Run length must be between 0 and 1440" << endl;
    } while (movie.RunLength < 0 || movie.RunLength > 1440);

    //Get release year, at least 1900
    while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    {
        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
            cout << "ERROR: Release year must be between 1900 and 2100" << endl;
    };


    //Get the optional description
    movie.Description = ReadString()
    cout << "Enter optional description: ";
    cin.ignore();
    getline(cin, movie.Description);

    //Get Is classic
    bool done = false;
    while (!done)
    {
        char isClassic;
        cout << "Is this a classic (Y/N)? ";
        cin >> isClassic;

        switch (isClassic)
        {
            case 'Y':
            case 'y': movie.IsClassic = true; done = true; break;

            case 'N':
            case 'n': movie.IsClassic = false; done = true; break;

            default:
            {
                cout << "ERROR: You must enter Y or N";
            };
        };
    };
    cin.ignore();

    //Get genre(s)
    for (int index = 0; index < 5; ++index)  // = 0, < N  (rarely) = 1, <= N
    {
        string genre = ReadString("Enter optional genre ");
        //cout << "Enter optional genre " << (index + 1) << ": ";

        //string genre;
       // getline(cin, genre);
        if (genre == "")
           break; //Exits the loop

        movie.Genre += genre + ", ";
    };

    //HACK: Don't do this
    g_movie = movie;
}

void DeleteMovie()
{
    cout << "DeleteMovie" << endl;
}

void EditMovie()
{
    cout << "EditMovie" << endl;
}

void ViewMovie(Movie movie)
{
    ///// Display movie details
    cout << "---------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;

    cout << "Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;
    if (movie.Genre != "")
        cout << "Genre(s) " << movie.Genre << endl;
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "---------------" << endl;
}

/// Displays main menu and gets user input
void DisplayMenu()
{
    cout << "Movie Library" << endl;
    cout << "---------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    MenuCommand menuCommand = (MenuCommand)0;
    do
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::MC_AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::MC_EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::MC_DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::MC_ViewMovie; break;

            default: cout << "Bad input" << endl; break;
        };
    } while (menuCommand == 0);
    cin.ignore();

    //HACK: Don't do this
    g_menuCommand = menuCommand;
}

//Parameter kind
//input ::= read in function any valid expression as the argument

/// Handles the menu selection
/// @param menuCommand The command to handle
void HandleMenu(MenuCommand menuCommand)
{
    switch (menuCommand)
    {
        case MenuCommand::MC_AddMovie: AddMovie(); break;
        case MenuCommand::MC_EditMovie: EditMovie(); break;
        case MenuCommand::MC_DeleteMovie: DeleteMovie(); break;
        case MenuCommand::MC_ViewMovie: ViewMovie(g_movie); break;
    };
}

int main()
{
    do
    {
        //Function call ::= id ();    
        DisplayMenu();

        //// Handle menu command
        HandleMenu(g_menuCommand);
    } while (true);
}


// Movie: Title, Actors, Run length, Description, Genres, Director(s), Release Year, MPAA Rating
struct Movie
{
    //Required
    string Title;

    // At least 0, minutes
    int RunLength;

    //Optional
    string Description;

    // >= 1900
    int ReleaseYear;

    bool IsClassic;

    string Genre;
};

//Integral data type with named values
enum MenuCommand
{
    //MC_Begin,
    MC_AddMovie = 1,    //const int MenuCommand::MC_AddMovie = 0;
    MC_EditMovie,
    MC_DeleteMovie,
    MC_ViewMovie,
    //MC_End
};

// function ::= Reusable block of code
//              Benefits: reusability, maintainability, readability, security
// function definition - Defines a function and what it does (for linker)
// declaration ::= Declares the existence of something and what it is (var declaration)
//                 Used by the compiler to recognize the use of the identifier
//                 Must be declared before usage
// 
// Function names are verbs representing actions
//   Casing: Pascal casing, camel casing

// Parameters - data passed to a function
// parameter-list ::= parameter { , parameter }*
// parameter      ::= T [ id ]

//HACK: Don't do this
MenuCommand g_menuCommand = (MenuCommand)0;
Movie g_movie;

/// @brief Reads a string from input
/// @param message Message to display
/// @param isRequired True if the value is required
/// @return Input from user
string ReadString(string message, bool isRequired)
{
    string input;
    do
    {
        cout << message;
        getline(cin, input);

        if (isRequired && input == "")
            cout << "ERROR: Value is required" << endl;
    } while (isRequired && input == "");

    return input;
}

/// @brief Reads a string from input
/// @param message Message to display
/// @return Input from user
string ReadString(string message)
{
    return ReadString(message, false);
};

void AddMovie()
{
    Movie movie;

    //Get required title
    movie.Title = ReadString("Enter a title: ", true);
    /*do
    {
        cout << "Enter a title: ";
        getline(cin, movie.Title);

        if (movie.Title == "")
            cout << "ERROR: Title is required" << endl;
    } while (movie.Title == "");

    //Get run length, at least 0, minutes
    do
    {
        cout << "Enter run length (in minutes): ";
        cin >> movie.RunLength;

        if (movie.RunLength < 0 || movie.RunLength > 1440)
            cout << "ERROR: Run length must be between 0 and 1440" << endl;
    } while (movie.RunLength < 0 || movie.RunLength > 1440);

    //Get release year, at least 1900
    while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    {
        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
            cout << "ERROR: Release year must be between 1900 and 2100" << endl;
    };

    //Get the optional description
    cin.ignore();
    movie.Description = ReadString("Enter optional description: ");
    /*cout << "Enter optional description: ";
    cin.ignore();
    getline(cin, movie.Description);*/

   /*//Get Is classic
    bool done = false;
    while (!done)
    {
        char isClassic;
        cout << "Is this a classic (Y/N)? ";
        cin >> isClassic;

        switch (isClassic)
        {
            case 'Y':
            case 'y': movie.IsClassic = true; done = true; break;

            case 'N':
            case 'n': movie.IsClassic = false; done = true; break;

            default:
            {
                cout << "ERROR: You must enter Y or N";
            };
        };
    };
    cin.ignore();

    //Get genre(s)
    for (int index = 0; index < 5; ++index)  // = 0, < N  (rarely) = 1, <= N
    {
        string genre = ReadString("Enter optional genre ");
        //cout << "Enter optional genre " << (index + 1) << ": ";

        //string genre;
        //getline(cin, genre);
        if (genre == "")
            break; //Exits the loop

        movie.Genre += genre + ", ";
    };

    //HACK: Don't do this
    g_movie = movie;
}

void DeleteMovie()
{
    cout << "DeleteMovie" << endl;
}

void EditMovie()
{
    cout << "EditMovie" << endl;
}

void ViewMovie(Movie movie)
{
    ///// Display movie details
    cout << "---------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;

    cout << "Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;
    if (movie.Genre != "")
        cout << "Genre(s) " << movie.Genre << endl;
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "---------------" << endl;
}

/// Displays main menu and gets user input
void DisplayMenu()
{
    cout << "Movie Library" << endl;
    cout << "---------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    MenuCommand menuCommand = (MenuCommand)0;
    do
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::MC_AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::MC_EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::MC_DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::MC_ViewMovie; break;

            default: cout << "Bad input" << endl; break;
        };
    } while (menuCommand == 0);
    cin.ignore();

    //HACK: Don't do this
    g_menuCommand = menuCommand;
}

// Parameter Kind
//   Input ::= read in function, any valid expression as the argument

/// Handles the menu selection
/// @param menuCommand The command to handle
void HandleMenu(MenuCommand menuCommand)
{
    switch (menuCommand)
    {
        case MenuCommand::MC_AddMovie: AddMovie(); break;
        case MenuCommand::MC_EditMovie: EditMovie(); break;
        case MenuCommand::MC_DeleteMovie: DeleteMovie(); break;
        case MenuCommand::MC_ViewMovie: ViewMovie(g_movie); break;
    };
}

int main()
{
    do
    {
        //Function call ::= id ();    
        DisplayMenu();

        //// Handle menu command
        HandleMenu(g_menuCommand);
    } while (true);
}*/

//---------------------------------------------------------------------------------------------------------------------
/*
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

    // >= 1900
    int ReleaseYear;

    bool IsClassic;

    string Genre;
};

//Integral data type with named values
enum MenuCommand
{
    //MC_Begin,
    MC_AddMovie = 1,    //const int MenuCommand::MC_AddMovie = 0;
    MC_EditMovie,
    MC_DeleteMovie,
    MC_ViewMovie,
    //MC_End
};

// function ::= Reusable block of code
//              Benefits: reusability, maintainability, readability, security
// function definition - Defines a function and what it does (for linker)
// declaration ::= Declares the existence of something and what it is (var declaration)
//                 Used by the compiler to recognize the use of the identifier
//                 Must be declared before usage
// 
// Function names are verbs representing actions
//   Casing: Pascal casing, camel casing

// Parameters - data passed to a function
// parameter-list ::= parameter { , parameter }*
// parameter      ::= T [ id ]

//HACK: Don't do this
MenuCommand g_menuCommand = (MenuCommand)0;
Movie g_movie;

int ReadInt(string message, int minValue, int maxValue)
{
    int input;
    do
    {
        cout << message;
        cin >> input;

        if (input < minValue || input > maxValue)
            cout << "ERROR: Value must be between " << minValue << " and " << maxValue << endl;
    } while (input < minValue || input > maxValue);
    return input;
}

/// @brief Reads a string from input
/// @param message Message to display
/// @param isRequired True if the value is required
/// @return Input from user
string ReadString(string message, bool isRequired)
{
    string input;
    do
    {
        cout << message;
        getline(cin, input);

        if (isRequired && input == "")
            cout << "ERROR: Value is required" << endl;
    } while (isRequired && input == "");

    return input;
}

/// @brief Reads a string from input
/// @param message Message to display
/// @return Input from user
string ReadString(string message)
{
    return ReadString(message, false);
};

void AddMovie()
{
    Movie movie;

    //Get required title
    movie.Title = ReadString("Enter a title: ", true);
    /*do
    {
        cout << "Enter a title: ";
        getline(cin, movie.Title);

        if (movie.Title == "")
            cout << "ERROR: Title is required" << endl;
    } while (movie.Title == "");*/

    //Get run length, at least 0, minutes
   // movie.RunLength = ReadInt("Enter run length (in MInutes): ", 0, 1440);

   /* do
    {
        cout << "Enter run length (in minutes): ";
        cin >> movie.RunLength;

        if (movie.RunLength < 0 || movie.RunLength > 1440)
            cout << "ERROR: Run length must be between 0 and 1440" << endl;
    } while (movie.RunLength < 0 || movie.RunLength > 1440); */

    //Get release year, at least 1900
  //  movie.RunLength = ReadInt("Enter release year (1900+): ", 1900, 2100);
   /* while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    {
        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
            cout << "ERROR: Release year must be between 1900 and 2100" << endl;
    };*/

    //Get the optional description
   /* cin.ignore();
    movie.Description = ReadString("Enter optional description: ");
    cout << "Enter optional description: ";
    cin.ignore();
    getline(cin, movie.Description);

    //Get Is classic
    bool done = false;
    while (!done)
    {
        char isClassic;
        cout << "Is this a classic (Y/N)? ";
        cin >> isClassic;

        switch (isClassic)
        {
            case 'Y':
            case 'y': movie.IsClassic = true; done = true; break;

            case 'N':
            case 'n': movie.IsClassic = false; done = true; break;

            default:
            {
                cout << "ERROR: You must enter Y or N";
            };
        };
    };
    cin.ignore();

    //Get genre(s)
    for (int index = 0; index < 5; ++index)  // = 0, < N  (rarely) = 1, <= N
    {
        string genre = ReadString("Enter optional genre ");
        //cout << "Enter optional genre " << (index + 1) << ": ";

        //string genre;
        //getline(cin, genre);
        if (genre == "")
            break; //Exits the loop

        movie.Genre += genre + ", ";
    };

    //HACK: Don't do this
  //  g_movie = movie;
}

void DeleteMovie()
{
    cout << "DeleteMovie" << endl;
}

void EditMovie()
{
    cout << "EditMovie" << endl;
}

void ViewMovie(Movie movie)
{
    ///// Display movie details
    cout << "---------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;

    cout << "Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;
    if (movie.Genre != "")
        cout << "Genre(s) " << movie.Genre << endl;
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "---------------" << endl;
}

/// Displays main menu and gets user input
void DisplayMenu()
{
    cout << "Movie Library" << endl;
    cout << "---------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    MenuCommand menuCommand = (MenuCommand)0;
    do
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::MC_AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::MC_EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::MC_DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::MC_ViewMovie; break;

            default: cout << "Bad input" << endl; break;
        };
    } while (menuCommand == 0);
    cin.ignore();

    //HACK: Don't do this
    g_menuCommand = menuCommand;
}

// Parameter Kind
//   Input ::= read in function, any valid expression as the argument

/// Handles the menu selection
/// @param menuCommand The command to handle
void HandleMenu(MenuCommand menuCommand)
{
    switch (menuCommand)
    {
        case MenuCommand::MC_AddMovie: AddMovie(); break;
        case MenuCommand::MC_EditMovie: EditMovie(); break;
        case MenuCommand::MC_DeleteMovie: DeleteMovie(); break;
        case MenuCommand::MC_ViewMovie: ViewMovie(g_movie); break;
    };
}

int main()
{
    do
    {
        //Function call ::= id ();    
        DisplayMenu();

        //// Handle menu command
        HandleMenu(g_menuCommand);
    } while (true);
}*/


//-----------------------------------------------------------------------------------------------------------------------------------------------------
/*
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

    // >= 1900
    int ReleaseYear;

    bool IsClassic;

    string Genre;
};

//Integral data type with named values
enum MenuCommand
{
    //MC_Begin,
    MC_AddMovie = 1,    //const int MenuCommand::MC_AddMovie = 0;
    MC_EditMovie,
    MC_DeleteMovie,
    MC_ViewMovie,
    //MC_End
};

// function ::= Reusable block of code
//              Benefits: reusability, maintainability, readability, security
// function definition - Defines a function and what it does (for linker)
// declaration ::= Declares the existence of something and what it is (var declaration)
//                 Used by the compiler to recognize the use of the identifier
//                 Must be declared before usage
// 
// Function names are verbs representing actions
//   Casing: Pascal casing, camel casing

// Parameters - data passed to a function
// parameter-list ::= parameter { , parameter }*
// parameter      ::= T [ id ]

//HACK: Don't do this
MenuCommand g_menuCommand = (MenuCommand)0;
Movie g_movie;

/// @brief Reads an integer value
/// @param message Message to display
/// @param minValue Minimum required value
/// @param maxValue Maximum required value
/// @return Input from user
int ReadInt(string message, int minValue, int maxValue)
{
    int input;
    do
    {
        cout << message;
        cin >> input;

        if (input < minValue || input > maxValue)
            cout << "ERROR: Value must be between " << minValue << " and " << maxValue << endl;
    } while (input < minValue || input > maxValue);

    return input;
}

/// @brief Reads a string from input
/// @param message Message to display
/// @param isRequired True if the value is required
/// @return Input from user
string ReadString(string message, bool isRequired)
{
    string input;
    do
    {
        cout << message;
        getline(cin, input);

        if (isRequired && input == "")
            cout << "ERROR: Value is required" << endl;
    } while (isRequired && input == "");

    return input;
}

/// @brief Reads a string from input
/// @param message Message to display
/// @return Input from user
string ReadString(string message)
{
    return ReadString(message, false);
};

void AddMovie()
{
    Movie movie;

    //Get required title
    movie.Title = ReadString("Enter a title: ", true);
    /*do
    {
        cout << "Enter a title: ";
        getline(cin, movie.Title);

        if (movie.Title == "")
            cout << "ERROR: Title is required" << endl;
    } while (movie.Title == "");*/

    //Get run length, at least 0, minutes
  /* movie.RunLength = ReadInt("Enter run length (in minutes): ", 0, 1440);
    /*do
    {
        cout << "Enter run length (in minutes): ";
        cin >> movie.RunLength;

        if (movie.RunLength < 0 || movie.RunLength > 1440)
            cout << "ERROR: Run length must be between 0 and 1440" << endl;
    } while (movie.RunLength < 0 || movie.RunLength > 1440);*/

    //Get release year, at least 1900
    movie.ReleaseYear = ReadInt("Enter release year (1900+): ", 1900, 2100);
    /*while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    {
        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
            cout << "ERROR: Release year must be between 1900 and 2100" << endl;
    };*/

    //Get the optional description
    cin.ignore();
    movie.Description = ReadString("Enter optional description: ");
    /*cout << "Enter optional description: ";
    cin.ignore();
    getline(cin, movie.Description);*/

    //Get Is classic
    bool done = false;
    while (!done)
    {
        char isClassic;
        cout << "Is this a classic (Y/N)? ";
        cin >> isClassic;

        switch (isClassic)
        {
            case 'Y':
            case 'y': movie.IsClassic = true; done = true; break;

            case 'N':
            case 'n': movie.IsClassic = false; done = true; break;

            default:
            {
                cout << "ERROR: You must enter Y or N";
            };
        };
    };
    cin.ignore();

    //Get genre(s)
    for (int index = 0; index < 5; ++index)  // = 0, < N  (rarely) = 1, <= N
    {
        string genre = ReadString("Enter optional genre ");
        //cout << "Enter optional genre " << (index + 1) << ": ";

        //string genre;
        //getline(cin, genre);
        if (genre == "")
            break; //Exits the loop

        movie.Genre += genre + ", ";
    };

    //HACK: Don't do this
    g_movie = movie;
}

void DeleteMovie()
{
    cout << "DeleteMovie" << endl;
}

void EditMovie()
{
    cout << "EditMovie" << endl;
}

void ViewMovie(Movie movie)
{
    ///// Display movie details
    cout << "---------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;

    cout << "Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;
    if (movie.Genre != "")
        cout << "Genre(s) " << movie.Genre << endl;
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "---------------" << endl;
}

/// Displays main menu and gets user input
void DisplayMenu()
{
    cout << "Movie Library" << endl;
    cout << "---------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    MenuCommand menuCommand = (MenuCommand)0;
    do
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::MC_AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::MC_EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::MC_DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::MC_ViewMovie; break;

            default: cout << "Bad input" << endl; break;
        };
    } while (menuCommand == 0);
    cin.ignore();

    //HACK: Don't do this
    g_menuCommand = menuCommand;
}
// Function prototypes (function forwading)
int ReadInt(string, int, int);
string ReadString(string message);
string ReadString(string message, bool);
void AddMovie();
void DeleteMovie();
void EditMovie();
void ViewMovie(Movie);
void DisplayMenu();
void HandleMenu(MenuCommand);
// Parameter Kind
//   Input ::= read in function, any valid expression as the argument

/// Handles the menu selection
/// @param menuCommand The command to handle
void HandleMenu(MenuCommand menuCommand)
{
    switch (menuCommand)
    {
        case MenuCommand::MC_AddMovie: AddMovie(); break;
        case MenuCommand::MC_EditMovie: EditMovie(); break;
        case MenuCommand::MC_DeleteMovie: DeleteMovie(); break;
        case MenuCommand::MC_ViewMovie: ViewMovie(g_movie); break;
    };
}

int main()
{
    do
    {
        //Function call ::= id ();    
        DisplayMenu();

        //// Handle menu command
        HandleMenu(g_menuCommand);
    } while (true);
}*/
//------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include "Terminal.h"

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

    // >= 1900
    int ReleaseYear;

    bool IsClassic;

    string Genre;
};

//Integral data type with named values
enum MenuCommand
{
    //MC_Begin,
    MC_AddMovie = 1,    //const int MenuCommand::MC_AddMovie = 0;
    MC_EditMovie,
    MC_DeleteMovie,
    MC_ViewMovie,
    //MC_End
};

// function ::= Reusable block of code
//              Benefits: reusability, maintainability, readability, security
// function definition - Defines a function and what it does (for linker)
// declaration ::= Declares the existence of something and what it is (var declaration)
//                 Used by the compiler to recognize the use of the identifier
//                 Must be declared before usage
// 
// Function names are verbs representing actions
//   Casing: Pascal casing, camel casing

// Parameters - data passed to a function
// parameter-list ::= parameter { , parameter }*
// parameter      ::= T [ id ]

//HACK: Don't do this
MenuCommand g_menuCommand = (MenuCommand)0;
Movie g_movie;

//Function prototypes (function forwarding)


void AddMovie();
void DeleteMovie();
void EditMovie();
void ViewMovie(Movie);

void DisplayMenu();
void HandleMenu(MenuCommand);

int main()
{
    do
    {
        //Function call ::= id ();    
        DisplayMenu();

        //// Handle menu command
        HandleMenu(g_menuCommand);
    } while (true);
}
/*
/// @brief Reads an integer value
/// @param message Message to display
/// @param minValue Minimum required value
/// @param maxValue Maximum required value
/// @return Input from user
int ReadInt(string message, int minValue, int maxValue)
{
    int input;
    do
    {
        cout << message;
        cin >> input;

        if (input < minValue || input > maxValue)
            cout << "ERROR: Value must be between " << minValue << " and " << maxValue << endl;
    } while (input < minValue || input > maxValue);

    return input;
}

/// @brief Reads a string from input
/// @param message Message to display
/// @return Input from user
string ReadString(string message)
{
    return ReadString(message, false);
};

/// @brief Reads a string from input
/// @param message Message to display
/// @param isRequired True if the value is required
/// @return Input from user
string ReadString(string message, bool isRequired)
{
    string input;
    do
    {
        cout << message;
        getline(cin, input);

        if (isRequired && input == "")
            cout << "ERROR: Value is required" << endl;
    } while (isRequired && input == "");

    return input;
}*/

void AddMovie()
{
    Movie movie;

    //Get required title
    movie.Title = ReadString("Enter a title: ", true);
    /*do
    {
        cout << "Enter a title: ";
        getline(cin, movie.Title);

        if (movie.Title == "")
            cout << "ERROR: Title is required" << endl;
    } while (movie.Title == "");*/

    //Get run length, at least 0, minutes
    movie.RunLength = ReadInt("Enter run length (in minutes): ", 0, 1440);
    /*do
    {
        cout << "Enter run length (in minutes): ";
        cin >> movie.RunLength;

        if (movie.RunLength < 0 || movie.RunLength > 1440)
            cout << "ERROR: Run length must be between 0 and 1440" << endl;
    } while (movie.RunLength < 0 || movie.RunLength > 1440);*/

    //Get release year, at least 1900
    movie.ReleaseYear = ReadInt("Enter release year (1900+): ", 1900, 2100);
    /*while (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
    {
        cout << "Enter release year (1900+): ";
        cin >> movie.ReleaseYear;

        if (movie.ReleaseYear < 1900 || movie.ReleaseYear > 2100)
            cout << "ERROR: Release year must be between 1900 and 2100" << endl;
    };*/

    //Get the optional description
    cin.ignore();
    movie.Description = ReadString("Enter optional description: ");
    /*cout << "Enter optional description: ";
    cin.ignore();
    getline(cin, movie.Description);*/

    //Get Is classic
    bool done = false;
    while (!done)
    {
        char isClassic;
        cout << "Is this a classic (Y/N)? ";
        cin >> isClassic;

        switch (isClassic)
        {
            case 'Y':
            case 'y': movie.IsClassic = true; done = true; break;

            case 'N':
            case 'n': movie.IsClassic = false; done = true; break;

            default:
            {
                cout << "ERROR: You must enter Y or N";
            };
        };
    };
    cin.ignore();

    //Get genre(s)
    for (int index = 0; index < 5; ++index)  // = 0, < N  (rarely) = 1, <= N
    {
        string genre = ReadString("Enter optional genre ");
        //cout << "Enter optional genre " << (index + 1) << ": ";

        //string genre;
        //getline(cin, genre);
        if (genre == "")
            break; //Exits the loop

        movie.Genre += genre + ", ";
    };

    //HACK: Don't do this
    g_movie = movie;
}

void DeleteMovie()
{
    cout << "DeleteMovie" << endl;
}

void EditMovie()
{
    cout << "EditMovie" << endl;
}

void ViewMovie(Movie movie)
{
    ///// Display movie details
    cout << "---------------" << endl;
    cout << movie.Title << " (" << movie.ReleaseYear << ")" << endl;
    cout << "Run Length (mins) " << movie.RunLength << endl;

    cout << "Is Classic? " << (movie.IsClassic ? "Yes" : "No") << endl;
    if (movie.Genre != "")
        cout << "Genre(s) " << movie.Genre << endl;
    if (movie.Description != "")
        cout << movie.Description << endl;
    cout << "---------------" << endl;
}

/// Displays main menu and gets user input
void DisplayMenu()
{
    cout << "Movie Library" << endl;
    cout << "---------------" << endl;
    cout << "A)dd Movie" << endl;
    cout << "E)dit Movie" << endl;
    cout << "D)elete Movie" << endl;
    cout << "V)iew Movie" << endl;

    MenuCommand menuCommand = (MenuCommand)0;
    do
    {
        char input;
        cin >> input;

        switch (input)
        {
            case 'A':
            case 'a': menuCommand = MenuCommand::MC_AddMovie; break;

            case 'E':
            case 'e': menuCommand = MenuCommand::MC_EditMovie; break;

            case 'D':
            case 'd': menuCommand = MenuCommand::MC_DeleteMovie; break;

            case 'V':
            case 'v': menuCommand = MenuCommand::MC_ViewMovie; break;

            default: cout << "Bad input" << endl; break;
        };
    } while (menuCommand == 0);
    cin.ignore();

    //HACK: Don't do this
    g_menuCommand = menuCommand;
}

// Parameter Kind
//   Input ::= read in function, any valid expression as the argument

/// Handles the menu selection
/// @param menuCommand The command to handle
void HandleMenu(MenuCommand menuCommand)
{
    switch (menuCommand)
    {
        case MenuCommand::MC_AddMovie: AddMovie(); break;
        case MenuCommand::MC_EditMovie: EditMovie(); break;
        case MenuCommand::MC_DeleteMovie: DeleteMovie(); break;
        case MenuCommand::MC_ViewMovie: ViewMovie(g_movie); break;
    };
}
