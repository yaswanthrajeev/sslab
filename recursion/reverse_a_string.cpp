#include<iostream>
#include<cstring>  // Required for strlen
using namespace std;

void reverse(char* str, char* temp, int i) {
    if(i < 0) {
        temp[strlen(str)] = '\0';  // Null-terminate the reversed string
        cout << temp << endl;  // Print the reversed string
        return;
    }
    temp[strlen(str) - i - 1] = str[i];  // Reverse the string
    reverse(str, temp, i - 1);  // Recursive call
}

int main() {
    char str[] = "gello";  // Input string
    char temp[strlen(str) + 1];  // Temporary array to hold the reversed string
    int i = strlen(str) - 1;  // Start from the end of the string
    reverse(str, temp, i);  // Reverse the string
    return 0;
}
