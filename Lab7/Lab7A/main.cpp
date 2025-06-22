/*
Author: Matthew Flores (matthewflores10@my.unt.edu)
Date: 06-12-2025
Instructor: Dr. Amar M. Maharjan
Description: Determines is email is valid
 and displays components if so
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main() {
    // Declare variables
    string emailAddress;
    int indexAt = -1, indexDot = -1;
    int usernameLength, serverNameLength, domainNameLength;
    string username, serverName, domainName;
    
    // Prompt for email
    printf("Enter email address: "); cin >> emailAddress;
    
    // Determina if email is valid by checking for '@'
    if (emailAddress.find("@") == string::npos) {
        printf("Invalid email address: @ not found\n");
        return 0;
    }
    else {
        indexAt = static_cast<int>(emailAddress.find('@'));
    }
    
    // Determine if email is valid by checking for '.'
    for (int i = emailAddress.size() - 1; i >= 0; --i) {
        if (emailAddress.at(i) == '.') {
            indexDot = i;
            break;
        }
        if (i == 0) {
            printf("Invalid email address: . not found\n");
            return 0;
        }
    }
    
    // Determine if email is valid by checking for username
    if (emailAddress.substr(0,indexAt).size() == 0) {
        printf("Invalid email address: username missing\n");
        return 0;
    }
    else {
        usernameLength = emailAddress.substr(0,indexAt).size();
        username = emailAddress.substr(0,usernameLength);
    }
    
    // Determine if email is valid by checking for server name
    if (indexDot - indexAt - 1 == 0) {
        printf("Invalid email address: server name missing\n");
        return 0;
    }
    else {
        serverNameLength = indexDot - indexAt;
        serverName = emailAddress.substr(indexAt + 1,serverNameLength - 1);
    }
    
    // Determine if email is valid by checking for domain name
    if (emailAddress.size() - indexDot - 1 == 0) {
        printf("Invalid email address: domain name missing\n");
        return 0;
    }
    else {
        domainNameLength = emailAddress.size() - indexDot;
        domainName = emailAddress.substr(indexDot + 1,domainNameLength);
    }
    
    // Display components of valid email
    printf("Valid email address.\n");
    cout << "Username: " << username << endl;
    cout << "Server: " << serverName << endl;
    cout << "Domain: " << domainName << endl;
    
    return 0;
}
