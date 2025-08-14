#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> 

using namespace std;


bool fileExists(const string &filename) {
    ifstream file(filename);
    return file.good();
}


bool fileEmpty(const string &filename) {
    ifstream file(filename, ios::ate); 
    return file.tellg() == 0;          
}

int main() {
    string line;

    if (!fileExists("employee_details.csv")) {
        cerr << "Error: employee_details.csv does not exist!" << endl;
        return 1;
    }
    if(fileEmpty("employee_details.csv"))
    {
        cout<<"employee_details.csv is empty"<<endl;
        return 0;
    }

    
    if (fileExists("employee_details_copy.csv")) {
        if (!fileEmpty("employee_details_copy.csv")) {
            
            remove("employee_details_copy.csv");
            fstream bFile("employee_details_copy.csv", ios::in | ios::out | ios::trunc);
            bFile.close();
            cout << "Cleared existing data from employee_details_copy.csv" << endl;
        }
    } else {
        
        fstream bFile("employee_details_copy.csv", ios::in | ios::out | ios::trunc);
        bFile.close();
        cout << "Created new employee_details_copy.csv" << endl;
    }

    
    ifstream aFile("employee_details.csv");
    ofstream bFile("employee_details_copy.csv", ios::app);

    if (!aFile || !bFile) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    
    while (getline(aFile, line)) {
        bFile << line << "\n";
    }

    cout << "Data copied from employee_details.csv to employee_details_copy.csv successfully!" << endl;

    aFile.close();
    bFile.close();

    return 0;
}
