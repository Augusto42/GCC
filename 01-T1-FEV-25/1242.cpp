#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
    string sequence;
    
    while (cin >> sequence)
    {
        string converted;
        int count = 0;
        stack<char> stackBuffer;
        
        for (int i = 0; i < sequence.size(); i++)
        {
            if (sequence[i] == 'S')
                converted += 'B';
            else if (sequence[i] == 'B')
                converted += 'S';
            else if (sequence[i] == 'C')
                converted += 'F';
            else if (sequence[i] == 'F')
                converted += 'C';
        }
        
        for (int i = 0; i < sequence.size(); i++)
        {
            if (stackBuffer.empty() || stackBuffer.top() != converted[i])
                stackBuffer.push(sequence[i]);
            else 
            {
                while (true)
                {
                    if (stackBuffer.empty())
                    {
                        i--;
                        break;
                    }
                    else if (converted[i] == stackBuffer.top())
                    {
                        count++;
                        stackBuffer.pop();
                        i++;
                    }
                    else
                    {
                        i--;
                        break;
                    }
                    
                    if (i >= converted.size())
                    {
                        i--;
                        break;
                    }
                }
            }
        }
        
        cout << count << "\n";
    }
    
    return 0;
}

//Augusto C Fagundes