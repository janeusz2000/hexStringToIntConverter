
#include <string>
#include <string_view>
#include <iostream>
#include <vector>
#include <map>

std::vector<std::string> divToChunks(std::string input);             //format #00--00 // ! DONE
int dictionary(const char &symbol);                                  // translates char to int // ! DOne
std::vector<int> hexStrToInt(std::vector<std::string> &ChunkVector); //Format [number0, number1, number2]

int main()
{
    std::string codedNumbers = "abc123bcd234b5c4ff";
    std::vector<int> values = hexStrToInt(divToChunks(codedNumbers));
    for (auto &value : values)
    {
        std::cout << value << std::endl;
    }
    return 0;
}

std::vector<std::string> divToChunks(std::string input)
{
    std::vector<std::string> chunkVector;
    std::string temp = "";
    for (int symbol = input.size() - 1; symbol >= 0; symbol--)
    {
        if ((symbol + 1) % 2 == 0)
        {
            temp = temp + input[symbol];
        }
        else
        {
            temp = temp + input[symbol];
            chunkVector.push_back(temp);
            temp = "";
        }
    }
    return chunkVector;
}

int dictionary(const char &symbol)
{
    const std::map<const char, int> dict = {
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'a', 10},
        {'b', 11},
        {'c', 12},
        {'d', 13},
        {'e', 14},
        {'f', 15},
    };
    return dict.at(symbol);
}

std::vector<int> hexStrToInt(std::vector<std::string> &ChunkVector)
{
    std::vector<int> valuesVector;
    for (auto &chunk : ChunkVector)
    {
        int temp = 0;
        for (int index = 0; index < chunk.size(); index++)
        {
            temp += dictionary(chunk[index]) * pow(16, index);
        }
        valuesVector.push_back(temp);
    }
    return valuesVector;
}
// 1. Divide string to chunks of two
// 2. translate each char to int and multiply it by interation n: 16^n
// 3. sum thosetwo numbers and return them