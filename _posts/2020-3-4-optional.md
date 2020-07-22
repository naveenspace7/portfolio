---
layout: post
title: std::optional
excerpt_separator: <!--more-->
tags: C++ optional C++17
---




<!--more-->

Present in the header, `std::optional`.

std::optional can either contain a value or be empty.

If you ever what to return a status along with the value of interest, use optional instead of giving (by return or modifying arguments).

Without `optional`, the code would look like this:

``` cpp

bool ReadFile(const string& filePath, string& fileContent)
{
    fstream fileStream(filePath);

    if (fileStream)
    {
        // open file and copy the content
        fileContent = content;
        return true;
    }

    fileContent = string();

    return false;
}

void client()
{
    string fileData;
    if (ReadFile("config.txt", fileData))
    {
        // use fileData
    }
    else
    {
        // do the default operations
    }
}
```

Although the above code works as intented, C++17 provides a more pragmatic of achieving the similar functionality.

``` cpp
std::optional<std::string> ReadFile(const string& filePath)
{
    fstream fileStream(filePath);

    if (fstream)
    {
        string fileContent;
        // open file and copy the content
        return fileContent;
    }
    
    return {};
}

void client()
{
    std::optional<std::string> fileData = ReadFile("config.txt");
    if (fileData.has_value()) // or if (fileData) - since it has a boolean operator
    {
        // use fileData
    }
    else
    {
        // do the default operations
    }

    string data = fileData.value_or(string{"default"});
}

```

The validity of the optional can be checked by `has_value` function, which return a bool whether it contains a value or not.

The data can be extracted with `value` function. However, if the to assign a default option when there is no value present, use `value_or` function, which takes as an argument the default value to be returned.

[Reference](https://en.cppreference.com/w/cpp/utility/optional)