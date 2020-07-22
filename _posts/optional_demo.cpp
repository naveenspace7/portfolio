#include <iostream>
#include <optional>
#include <fstream>

using namespace std;

optional<string> getFileData(const string& filePath)
{
    fstream fstrm(filePath);

    if (fstrm)
    {
        return {"hello naveen, you got your file constructed"};
    }
    
    return {};
}

int main()
{
    optional<string> fileContent = getFileData("confi.txt");

    if (fileContent)
    {
        // cout << *fileContent << endl;
        cout << fileContent.data() << endl;
    }
    else
    {
        cout << "there is no file, sorry" << endl;
    }
}