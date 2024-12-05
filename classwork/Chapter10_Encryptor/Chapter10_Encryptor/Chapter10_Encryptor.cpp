
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


std::string GetFilename(const char* message)
{
    std::cout << message;

    std::string filename;
    std::getline(std::cin, filename);

    return filename;
};

void Encrypt(std::fstream& input, std::fstream& output, char key)
{
    //caesper cipher (addative cipher)
   
    while(!input.eof())
    {
        char ch;

        //Read
        input.get(ch);

        //Encrypt it
        ch += key;

        //Write out
        //output <<vh;
        output.put(ch);
    }
    
};

void Decrypt(std::fstream& input, std::fstream& output, char key)
{
    //caesper cipher (addative cipher)

    while (!input.eof())
    {
        char ch;

        //Read next character
        input.get(ch);

        //Reset the erroe state of a strem
        if (input.fail());
        input.clear();

        //Dencrypt it
        ch -= key;

        //Write out
        //output <<vh;
        output.put(ch);
    }

};

void GetInputFile(std::fstream& input)
{
    do {
        std::string inputFilename = GetFilename("Enter input file: ");

        input.open(inputFilename, std::ios_base::in);

        //error checking functios
        //.fail()-> true if failed otherwise false for last file operation
        //.bad() -> true if failed otherwise false for  last file operation
        //.good() -> true if last file operation succeded or false otherwise

        //if (!input.good())
        if(input.is_open())
            return;
        std::cout << "Error opening file";

    } while (true);


}

void GetOutputFile(std::fstream& output)
{
    do {
        std::string inputFilename = GetFilename("Enter input file: ");

        output.open(inputFilename, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);;

        //error checking functios
        //.fail()-> true if failed otherwise false for last file operation
        //.bad() -> true if failed otherwise false for  last file operation
        //.good() -> true if last file operation succeded or false otherwise

        //if (!input.good())
        if (output.is_open())
            return;
        std::cout << "Error opening file";

    } while (true);


}
enum Direction
{
    EncryptMode,
    DecryptMode
};
Direction GetDirection()
{
    std::cout << "(Encrypt or Decrypt?: ";
    do
    {
        char ch;
        std::cin >> ch;
        switch (ch)
        {
            case 'E':
             case 'e': return Direction::EncryptMode;

            case 'D':
            case 'd': return Direction::DecryptMode;
        }
        std::cout << "Bad input"<< std::endl;

    } while (true);
}

int main()
{
    //Get input/out files
    //std::string inputFilename = GetFilename("Enter input file: ");
    //std::string outputFilename = GetFilename("Enter output file: ");

    //OPen input file reading , out put for writing
    std::fstream inputFile;
    GetInputFile(inputFile);

    //inputFile.open(inputFilename, std::ios_base::in);

    //std::string outputFilename = GetFilename("Enter output file: ");

    std::fstream outputFile;
    GetOutputFile(outputFile);
    //outputFile.open(outputFilename, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);

    Direction mode = GetDirection();
    switch (mode)
    {
        case Direction::EncryptMode(inputFile, outFile, 56); break;
        case Direction::EncryptMode(inputFile, outFile, 56); break;
    }

    Encrypt(inputFile, outputFile, 56);
}

