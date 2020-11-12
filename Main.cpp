#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>
#include <array>        // std::array
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <fstream> // for file i/o
#include <iomanip>

char hex[30];

bool is_int(std::string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
void hex_string(char str[], int length)
{
    std::array<char,16> hexchr { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(hexchr.begin(), hexchr.end(), std::default_random_engine(seed));
    int i;
    for (i = 0;i < length;i++)
    {
        str[i] = hexchr[rand() % 16];
    }
    str[length] = 0;
}

int msg1()
{
    int num;
    std::string n;
    std::cout << "How many MAC Addresses?\n";
    std::cin >> n;
    num = std::stoi(n);
    if (is_int(n)) {
        return num;
    }
    else {
        std::cout << n << " is not a valid number\n";
        exit(0);
        return 0;
    }
}
int msg2()
{
    int num;
    std::string n2;
    std::cout << "\nWould you like to save to mac.txt? (0 = no | 1 = yes)\n";
    std::cin >> n2;
    num = std::stoi(n2);
    if (is_int(n2)) {
        return num;
    }
    else {
        std::cout << n2 << " is not a valid number\n";
        exit(0);
        return 0;
    }

    std::cout << "\nGenerating please wait...\n";
}
void DoGen(int num) {
    char hex[30];
    if (num == 0)
    {
        num = 1;
    }
    srand(time(0));
    for (int i = 0;i < num;i++)
    {
        hex_string(hex, 12);
        std::cout << hex << "\n";
    }
}
void DoGen2(int num, std::string filename) {
    char hex[30];
    if (num == 0)
    {
        num = 1;
    }
    srand(time(0));
    std::ofstream outfile;
    outfile.open(filename);
    for (int i = 0;i < num;i++)
    {
        hex_string(hex, 12);
        outfile << hex << "\n";
    }
    outfile.close();
    std::cout << "Saved file to: " + filename + "\n";
    exit(0);
}
bool AppendCharToCharArray(char* array, size_t n, char c)
{
    size_t sz = std::strlen(array);

    if (sz + 1 < n)
    {
        array[sz] = c;
        array[sz + 1] = '\0';
    }

    return (sz + 1 < n);
}
void pause()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string dummy;
    std::cout << "Press any key to exit . . .";
    std::getline(std::cin, dummy);
    exit(0);
}
int main()
{
    int num, num2;
    std::string n2;
    
    num = msg1();
    if (num == 0) {
        std::cout << "You entered an invalid option\n";
    }
    else {
        std::cout << "You entered:" << num;
            num2 = msg2();
            if (num2 == 0) {
                std::cout << "[MAC Address List]\n";
                DoGen(num);
            }
            else {
                DoGen2(num, "mac.txt");
            }
        }
    //pause();
    return 0;
}