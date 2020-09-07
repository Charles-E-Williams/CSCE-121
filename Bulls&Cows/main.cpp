#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
using namespace std;

bool isnotUnique(vector<int> vector) {
     bool broken = false;
            for (int i = 0; i < vector.size(); i++) { 
                for (int j = i + 1; j < vector.size(); j++) {
                    if (vector.at(i) == vector.at(j)) {
                        broken = true;
                        break;
                        }
                    }

                if (broken) break;
                continue;
                }
        
        return broken;
}

int main() {
    srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
    // needed to autograde some test cases in Mimir 
	  // do not call srand again in your program
    
    // Your code starts here
    int codeDigits; 
    vector<int> tempVect;  
    int bull,cow;
    int dummy = 10;

    while (dummy != 0 && dummy != 3  && dummy != 4 && dummy !=5) { // if one becomes false, the whole expression becomes false and checks cease 
        cout << "Enter number of digits in code (3, 4 or 5): ";  // if we put ||, then if one is true, then the whole thing is true continues.
        cin >> codeDigits;
        dummy = codeDigits;
        }

    int codeZero, digitStore, tempVal,guess;
    vector<int> digitsVector;
    vector<int> compareVector;
    if (codeDigits == 0) {

        // enter the code you want the user to guess
        cout << "Enter code: "; 
        cin >> codeZero;

        //input the number of digits in the code
        int numDigits; // number of digits in code
        cout << "Enter number of digits in code: ";
        cin >> numDigits; 

        // get digits and store it into digitsVector
        int digitsEntered, tmpVal;
        int counter = 0; // used to get the number of digits in the entered number
        while (codeZero != 0) {
            digitStore = codeZero % 10;
            codeZero /= 10;
            digitsVector.insert(digitsVector.begin(),digitStore);
            counter++;
            }
 
        // add leading zeros as needed
        bool leadingZeros = false;
        int tempCount = counter;
        if (counter < numDigits) {
            leadingZeros = true;
            while (numDigits > counter) {
                digitsVector.insert(digitsVector.begin(),0);
                counter++;
            }
        }

        // output number to guess 
        cout << "Number to guess: ";
        for (int i = 0; i < digitsVector.size() - 1; i++) {
            cout << digitsVector.at(i) << "-";
        }
        cout << digitsVector.at(digitsVector.size()-1);
        cout << endl;

        // prompt the user for a guess until they get it right
        bool flag = false;
        do {
            cout << "Enter Guess: ";
            cin >> guess; 

            int guessDigits = 0;
            while (guess != 0) {
                digitStore =  guess % 10;
                guess /= 10;
                compareVector.insert(compareVector.begin(),digitStore);
                guessDigits++;
                        } 

        tempVect = compareVector;
        cow = bull = 0;
        if (numDigits == guessDigits) {
            for (int i = 0; i < digitsVector.size(); i++) {
                for (int j = 0; j < digitsVector.size(); j++) {   
                    if (digitsVector.at(i) == compareVector.at(j)) {
                        if(i == j) {
                        bull++;
                       }
                        else {
                            cow++;
                        }
                    }
                }
            }
        }

        int tempDigits = guessDigits;    
        if (tempDigits < numDigits) {
             while (numDigits > tempDigits) {
                tempVect.insert(tempVect.begin(),0);
                tempDigits++;
            }
 
        for (int i = 0; i < digitsVector.size(); ++i) {
            for (int j = 0; j < tempVect.size(); ++j) {   
                if (digitsVector.at(i) == tempVect.at(j)) {
                    if(i == j) {
                        bull++;
                        break;
                    }
                    else {
                        cow++;
                    }
                }
            }
        }
    }
    
      // output you can only enter x amount of digits
        bool flag2 = false;
        if (!leadingZeros) {
            if (compareVector.size() > numDigits) {
                flag2 = true;
                cout << "You can only enter " << numDigits << " digits.\n";
        }
    }

        else if (leadingZeros) {
            if (compareVector.size() > numDigits) {
            flag2 = true;
            cout << "You can only enter " << numDigits << " digits.\n";      
            }
        }
    
    //detects for duplicates in the guess
        bool broken = false;
        if (!flag2) {
            for (int i = 0; i < tempVect.size(); i++) { 
                for (int j = i + 1; j < tempVect.size(); j++) {
                    if (tempVect.at(i) == tempVect.at(j)) {
                        cout << "Each number must be different." << endl;
                        broken = true;
                        break;
                        }
                    }

            if (broken) break;
            continue;
            }
        }
       
    compareVector.clear(); //empty out tempVect for the next loop   
    if (tempVect == digitsVector) {flag = true;} // termination of loop 
    
    if (!flag && !broken && !flag2) {
        cout << bull << " bulls\n";
        cout << cow << " cows\n";
    }

        }while(!flag);
    
    if (flag) {
        bull = numDigits;
        cout << bull << " bulls... ";
        for (int i = 0; i < digitsVector.size() - 1; i++) {
            cout << digitsVector.at(i) << "-";
        }
        cout << digitsVector.at(digitsVector.size() - 1) << " is correct!\n";
    }
                } // end of original if 



    else if (codeDigits == 3 || codeDigits == 4 || codeDigits == 5) {
     
    for (int i = 0; i < codeDigits; i++) {
        digitsVector.insert(digitsVector.begin(), rand() % 10);
        }

    
    for (int i = 0; i < codeDigits; i++) {
        cout << digitsVector.at(i) << " "; 
        }
    cout << endl;

    bool flag3 = isnotUnique(digitsVector);
    if (flag3){ //not unique = true 
        while (flag3) {
            for (int i = 0; i < digitsVector.size(); i++) {
                for (int j = 0; j < digitsVector.size(); j++) {
                    if (i != j) {
                        if (digitsVector.at(i) == digitsVector.at(j)) {
                            digitsVector.at(i) = rand() % 10;
                        }
                    }
                }
            }
        
        flag3 = isnotUnique(digitsVector);
        }
    }
            // output number to guess 
        cout << "Number to guess: ";
        for (int i = 0; i < digitsVector.size() - 1; i++) {
            cout << digitsVector.at(i) << "-";
        }
        cout << digitsVector.at(digitsVector.size()-1);
        cout << endl;
    

        // prompt the user for a guess until they get it right
        bool flag = false;
        do {
            cout << "Enter Guess: ";
            cin >> guess; 

            int guessDigits = 0;
            while (guess != 0) {
                digitStore =  guess % 10;
                guess /= 10;
                compareVector.insert(compareVector.begin(),digitStore);
                guessDigits++;
                        } 

            if (compareVector.size() < codeDigits) {
                while (compareVector.size() < codeDigits)
                compareVector.insert(compareVector.begin(), 0);
                }

        for (int i = 0; i < compareVector.size(); i++){
            cout << compareVector.at(i) << " ";
        }cout << endl;


        tempVect = compareVector;
        cow = bull = 0;
        if (codeDigits == guessDigits) {
            for (int i = 0; i < digitsVector.size(); ++i) {
                for (int j = 0; j < digitsVector.size(); ++j) {   
                    if (digitsVector.at(i) == tempVect.at(j)) {
                        if(i == j) {
                        bull++;
                        break;
                        }
                        else {
                            cow++;
                        }
                    }
                }
            }
        }

    //detects for duplicates in the guess
        bool broken = false;
        
            for (int i = 0; i < tempVect.size(); i++) { 
                for (int j = i + 1; j < tempVect.size(); j++) {
                    if (tempVect.at(i) == tempVect.at(j)) {
                       if (tempVect.at(i) != 0) { // 
                        cout << "Each number must be different" << endl;
                        broken = true;
                        break;
                        }
                    }
                    }

                if (broken) break;
                continue;
                }
       

    compareVector.clear(); //empty out tempVect for the next loop
    if (tempVect == digitsVector) {flag = true;} // termination of loop 
   
    if (!flag && !broken) {
        cout << bull << " bulls\n";
        cout << cow << " cows\n";
    }

        }while(!flag);
    
    if (flag) {
        bull = codeDigits;
        cout << bull << " bulls... ";
        for (int i = 0; i < digitsVector.size() - 1; i++) {
            cout << digitsVector.at(i) << "-";
        }
        cout << digitsVector.at(digitsVector.size() - 1) << " is correct!\n";
        }        
    }


    
    return 0;
} 
