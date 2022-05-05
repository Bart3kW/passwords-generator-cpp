#include <iostream>
#include <ctime>

using namespace std;

//EIGHT CHARACTERS PASSWORDS GENERATOR


//CONSTATNT EXPRESSIONS 
//-------------------------------------------
constexpr char *bigLetters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};//table with big letters 
constexpr char *smallLetters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};//table with small latters
constexpr char *special[] = {"!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "_", "+", "{", "}", ":", "<", ">", "?"};//table with special characters
constexpr char *numbers[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};//table with numbers
//-------------------------------------------

void swapLetters(char *[], int &);//declaration of function swaping 0 to 6 ,6 to 0 and 2 to 4 ,4 to 2 

int main()
{
    srand(time(NULL));//to have every time new randoms

    cout<<"*******************"<<endl;
    cout<<"  EIGHT CHARACTERS"<<endl;
    cout<<"PASSWORDS GENERATOR"<<endl;

    constexpr int howMuchLetters=8;
    char *passwordString[howMuchLetters];
    int quarterOfPasswordLength=howMuchLetters / 4;

//MAIN FUNCTION
//--------------------------------------------
//DRAWING TABLE WITH 2 BIG LETTERS ,2 SMALL LETTERS, TWO SPECIAL CHARACTERS, 2 DIGITS
    for (int i=0; i < quarterOfPasswordLength; i++)
        passwordString[i]=bigLetters[rand() % 26 ];//BIG LETTERS

    for(int i=quarterOfPasswordLength; i < 2 * quarterOfPasswordLength ;i++)
        passwordString[i]=smallLetters[rand() % 26];//SMALL LETTERS

    for(int i=quarterOfPasswordLength * 2; i<3 * quarterOfPasswordLength ; i++)
        passwordString[i]=special[rand() % 18];//SPECIAL CHARACTERS

    for(int i=quarterOfPasswordLength * 3; i < 4 * quarterOfPasswordLength; i++)
        passwordString[i]=numbers[rand() % 10];//DIGITS
//--------------------------------------------


    swapLetters(passwordString, quarterOfPasswordLength);//SWAPING FUNCTION\


//OUTPUT
//-------------------------------
    cout<<"Your password"<<endl;

    for(const auto i : passwordString)
        cout<<i;
//-------------------------------

}

void swapLetters(char *passwordString[], int &quarterOfPasswordLength)
{
    char *tmp1, *tmp2;//temporary characters 
    tmp1=passwordString[quarterOfPasswordLength * 0];//swaping using quarter of password length
    tmp2=passwordString[quarterOfPasswordLength*3];
    passwordString[quarterOfPasswordLength * 0]=tmp2;
    passwordString[quarterOfPasswordLength*3]=tmp1;

    tmp1=passwordString[quarterOfPasswordLength*2];
    tmp2=passwordString[quarterOfPasswordLength];
    passwordString[quarterOfPasswordLength*2]=tmp2;
    passwordString[quarterOfPasswordLength]=tmp1;
}