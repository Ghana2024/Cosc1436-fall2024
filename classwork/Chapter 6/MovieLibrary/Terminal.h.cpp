
/*/// @brief Reads an integer value
/// @param message Message to display
/// @param minValue Minimum required value
/// @param maxValue Maximum required value
/// @return Input from user
int ReadInt(std::string message, int minValue, int maxValue)
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
----------------------------------------------------------------------
#pragma
int ReadInt(string, int, int);
string ReadString(string message);
string ReadString(string message, bool);

/*

// @brief Reads an integer value
/// @param message Message to display
/// @param minValue Minimum required value
/// @param maxValue Maximum required value
/// @return Input from user
int ReadInt(std::string message, int minValue, int maxValue)
{
    int input;
    do
    {
        std::cout << message;
        std::cin >> input;

        if (input < minValue || input > maxValue)
            std::cout << "ERROR: Value must be between " << minValue << " and " << maxValue << std::endl;
    } while (input < minValue || input > maxValue);

    return input;
}

/// @brief Reads a string from input
/// @param message Message to display
/// @return Input from user
std::string ReadString(std::string message)
{
    return ReadString(message, false);
};

/// @brief Reads a string from input
/// @param message Message to display
/// @param isRequired True if the value is required
/// @return Input from user
std::string ReadString(std::string message, bool isRequired)
{
    std::string input;
    do
    {
        std::cout << message;
        getline(std::cin, input);

        if (isRequired && input == "")
            std::cout << "ERROR: Value is required" << std::endl;
    } while (isRequired && input == "");

    return input;
}
*/