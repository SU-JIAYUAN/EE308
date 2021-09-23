# Programming specifications

> The specification references the following website:

[https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/contents/](https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/contents/)

## Indentation

Use 1 Tab (equals to 4 white spaces) for indentation.

## Variable Name

Variable names are all lowercased and well-defined, meaning that readers can understand the representation from its name. And every single word in a variable should be  spaced by "_".

Here are some examples that can help you understand:

```cpp
int keywords_count = 0;
int switch_count = 0;
int case_count = 0;
```

## Maximum number of characters per line

In this case, 80 is the maximum number of characters of a line.

## Maximum number of function lines

The lines number of each function should not exceed 40.

## Function and class naming

Generally, function and class names begin with a capital letter (i.e., "camel name" or "PASCAL variable name") and no underscores.

Here are some examples:

```cpp
void UserInterfaceHiddenCode(string path, int level);
void CountKeywords(fstream& fName);
void CountSwitch();
void CountSelectionTotal();
void CountIfElseNum();
void CountIfElseifElseNum();

```

## Constant

All constants must be written in capital letters and well-defined, meaning that the representations can be known from its name.

Here is a example:

```cpp
const int KEYWORDS_LIST_NUM = 32;
```

## Blank line rule

Each function is preceded by four blank lines to make it clearer to the reader. The front line of selection statements and loop statements are usually a blank line.

Here are some examples:

```cpp
fstream File;
	File.open(path.c_str());
// a blank line here
	if (File.fail())
	{ }
```

```cpp
void function1(){
      ...
}
// a blank line here
void function2(){
      ...
}
```

## Annotation rules

For the comments about a variable, annotations should keep up with the end of the line. However, in other situations, annotations are usually written on the front line of the section to be explained and do not contain any code.

Here are some examples:

```cpp
int number = 0 // The variable is used to count the number of ... ...

// The funtion is to ... ...
void function1(){
...
}
```

## Space before and after operator

Unary operators follow variables without spaces in between. Binary operators must be separated by a white space.

Here are examples:

```cpp
int c = a + b;
c++;
```