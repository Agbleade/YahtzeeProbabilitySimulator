
/*
NAME: ALEX YAW AGBLEADE
STUDENT ID: 800812955

 */


#include <ctime>
#include <climits>
#include <iostream>
#include <cstdlib>
#include<unordered_map>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {

    istringstream isin;
    srand((unsigned)time(NULL));
    unordered_map<int,int>hashtable;
    //creating a map that pairs all possible values from 1-6 to initial count of 0
    hashtable[1]=0;
    hashtable[2]=0;
    hashtable[3]=0;
    hashtable[4]=0;
    hashtable[5]=0;
    hashtable[6]=0;
    int indices[5];//creating an indices of size 5
    int maxValue;//this is to track the integer with the most count (highest maxCount)
    int maxCount =INT_MIN; //creating a tracker called maxCount to help me check the occurences of each integer in the map
    


    //creating all integers to count all the possible appearances for all the possible outcomes
    int nopaircount=0;
    int onepaircount=0;
    int threecount=0;
    int fourcount=0;
    int yahtzeecount=0;
    int simulationcount=0;
    int attempts;

    //PUTTING THE WHOLE  SIMULATION  INTO A WHILE LOOP 10,000 TIMES

    while (simulationcount < 10000) {
    ostringstream osin; //outputstring stream to help me print out the first attempt with the '*' on the most occuring value
    string firsttry;
    string secondtry;
        cout << "Attempt # " << simulationcount+1 << endl;
    hashtable[1]=0;
    hashtable[2]=0;
    hashtable[3]=0;
    hashtable[4]=0;
    hashtable[5]=0;
    hashtable[6]=0;
  
      // 3 attempts, whenever the maxCount turns to be 5, you break out of the loop
  //1ST ATTEMPT IS DONE OUTSIDE THE INNER WHILE LOOP 
    //for every single simulaiton, the indices is first reset to all 0's
    for (int i=0; i< 5; i++) {
        indices[i]=0;
    }
    maxValue=INT_MIN;//this is to track the max integer
    maxCount =INT_MIN; //creating a tracker called maxCount to help me check the occurences in the hashtable
    for (int i=0; i < 5; i++) {
        indices[i] = (rand()%6)+1;
        hashtable[indices[i]]++;
        maxCount=max(maxCount,hashtable[indices[i]]);
       
        osin << setw(3) << indices[i];
    }

    firsttry=osin.str();
    if (maxCount > 1) {
        for (auto item:hashtable) {
            if (item.second==maxCount) {
                maxValue=item.first;
                break;
            }
        }
        firsttry=osin.str();
       
       
        for (int i=0; i < firsttry.size();i++) {
            if (isdigit(firsttry[i]) and firsttry[i]-'0'== maxValue) {
                secondtry.push_back('*');
                secondtry.push_back(firsttry[i]);

            }
            else {
                secondtry.push_back(firsttry[i]);
            }
        }
        cout  << secondtry;
        secondtry.clear();
        osin.clear();
        firsttry.clear();
        secondtry.clear();
    }
    else {
        cout << setw(3) << firsttry;
        firsttry.clear();

    }
    osin.clear();
    firsttry.clear();
    secondtry.clear();

    cout << endl;
    //now after the first attempt is done, if the maxCount=5; the program would jump out of the inner while loop else, it would go back into it (unless it has exhausted the attempts)
    attempts=0; //for 0 < 2 times
    //REMAINING TWO ATTEMPTS [breaks on its own if the two attempts are reached or Yahtzee acheived]
    while (attempts < 2) {
    if (maxCount==5) {
        break;
    }
    else if (maxCount>1 and maxCount < 5) {
        

        //loop through it again and reset all values not equal to the maxValue to 0
        for (auto &item: hashtable) { // passing by reference to change it after the loop
            if (item.first != maxValue) {
                item.second=0;
            }
        }
        //loop through the indices array again and print if it the value at that index is maxValue, if it is not find the random and print it
        for (int i=0; i < 5; i++) {
            if (indices[i]==maxValue) {
                cout <<  setw(3)<< "*"<<indices[i];
            }
            else {
                indices[i] = (rand()%6)+1;
                if (indices[i]==maxValue) {
                cout << setw(3) << "*"<< indices[i];
                }
                else {
                    cout << setw(3) << indices[i];
                }
                //since the initial maxValue is being kept, no need to keep track of other values anymore in the hashtable, so only add to the count if the rand is maxValue
                if (indices[i]==maxValue) {
                hashtable[indices[i]]++; //add to the count;
                maxCount = max(maxCount,hashtable[indices[i]]);
                }
            }
        }
        cout << endl;

    }
    else if (maxCount==1) {
        //reset the hashtable to 0
        for (auto& item:hashtable) {
            item.second=0;
        }
        
        
        for (int i=0; i< 5; i++) { //reset all the values in the array to 0 before finding random numbers again(throwing dice)
        indices[i]=0;
    }
    osin.str("");
    
    
   for (int i=0; i < 5; i++) {
        indices[i] = (rand()%6)+1;
        hashtable[indices[i]]++;
        maxCount=max(maxCount,hashtable[indices[i]]);
        osin << setw(3) << indices[i];
    }

    firsttry=osin.str();
    if (maxCount > 1) {
        for (auto item:hashtable) {
            if (item.second==maxCount) {
                maxValue=item.first;
                break;
            }
        }
        firsttry=osin.str();

        for (int i=0; i < firsttry.size();i++) {
            if (isdigit(firsttry[i]) and firsttry[i]-'0'== maxValue) {
                secondtry.push_back('*');
                secondtry.push_back(firsttry[i]);

            }
            else {
                secondtry.push_back(firsttry[i]);
            }
        }
        cout  << secondtry;
        secondtry.clear();
        osin.clear();
        firsttry.clear();
        secondtry.clear();
    }
    else {
        cout << setw(3) << firsttry;
        firsttry.clear();

    }

    cout << endl;

    }
    attempts++;
    }
//DETERMING WHAT KIND OF OUTCOME WAS ATTAINED AFTER THREE ATTEMPTS
    if (maxCount==1) {
        cout << " --- Result: No pairs" << endl;
        nopaircount++;
    }
    else if (maxCount==2) {
        cout << " --- Result: 1 Pair ---" << endl;
        onepaircount++;
    }
    else if (maxCount==3) {
        cout << " --- Result: 3 of a kind ---" << endl;
        threecount++;
    }
    else if (maxCount==4) {
        cout << " --- Result: 4 of a kind ---" << endl;
        fourcount++;
    }
    else if (maxCount==5) {
        cout << " --- Result: Yahtzee ! --- " << endl;
        yahtzeecount++;
    }
    cout << "." << endl;
    cout << "." << endl;
    cout << "." << endl;

    simulationcount++;

}

//
cout << fixed << setprecision(2); // to set the no of decimal places

//NOW CREATING MY TABLE
cout << "Final Stats: " << endl;
cout << endl;
cout << left << setw(20) << "No pairs:" << left << setw(20) << nopaircount << (nopaircount*0.010) << endl;
cout << left << setw(20) << "1 pair:" << left << setw(20) << onepaircount << (onepaircount*0.010) << endl;
cout << left << setw(20) << "3 of a kind: " << left << setw(20) << threecount << (threecount*0.010) << endl;
cout << left << setw(20) << "4 of a kind: " << left << setw(20) << fourcount << (fourcount*0.010) << endl;
cout << left << setw(20) << "Yahtzee's: " << left << setw(20) << yahtzeecount << (yahtzeecount*0.010) << endl;

}
