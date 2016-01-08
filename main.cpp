//November 23, 2015

using namespace std;

#include "miniQueue.h"
#include "miniStack.h"
#include "miniStack.cpp"
#include "miniQueue.cpp"
#include <iostream>

int main() {


    int selection, qOrS, sType, qType, stackDAnum, stackLnum, stackVnum,
            queueDAnum, queueLnum, queueVnum, contentsOf, sizeOf, topFront, removeElements,
            sRemType, qRemType;

    miniQueueVT<int> queue1;
    miniQueueLT<int> queue2;
    miniQueueDA<int> queue3;
    miniStackDA<int> stack1;
    miniStackLT<int> stack2(0);
    miniStackVT<int> stack3(0);

    do {
        try {
            cout << "\nPlease make a selection from the following menu:" << endl;
            cout << "1. Add elements to a container" << endl
                    << "2. Remove elements from a container" << endl
                    << "3. Display the content of a container" << endl
                    << "4. Display the size of a container" << endl
                    << "5. Display the value of the top/front element in a container" << endl
                    << "(Input any invalid number to quit the program)" << endl;
            cin >> selection;

            if (selection == 1) {
                cout << "Which container would you like to add to?" << endl <<
                        "1. Stack" << endl <<
                        "2. Queue" << endl;
                cin >> qOrS;

                if (qOrS == 1) {
                    cout << "Which stack would you like to add to?" << endl <<
                            "1. Dynamic array" << endl <<
                            "2. List" << endl <<
                            "3. Vector" << endl;
                    cin >> sType;

                    if (sType == 1) {
                        cout << "Please enter the number you would like to add" << endl;
                        cin >> stackDAnum;
                        stack1.Push(stackDAnum);
                    }
                    else if (sType == 2) {
                        cout << "Please enter the number you would like to add" << endl;
                        cin >> stackLnum;
                        stack2.Push(stackLnum);
                    }
                    else if (sType == 3) {
                        cout << "Please enter the number you would like to add" << endl;
                        cin >> stackVnum;
                        stack3.Push(stackVnum);
                    }

                }

                else if (qOrS == 2) {
                    cout << "Which queue would you like to add to?" << endl <<
                            "1. Dynamic array" << endl <<
                            "2. List" << endl <<
                            "3. Vector" << endl;
                    cin >> qType;

                    if (qType == 1) {
                        cout << "Please enter the number you would like to add" << endl;
                        cin >> queueDAnum;
                        queue3.enqueue(queueDAnum);
                    }
                    else if (qType == 2) {
                        cout << "Please enter the number you would like to add" << endl;
                        cin >> queueLnum;
                        queue2.enqueue(queueLnum);
                    }
                    else if (qType == 3) {
                        cout << "Please enter the number you would like to add" << endl;
                        cin >> queueVnum;
                        queue1.enqueue(queueVnum);
                    }

                }
            }

            else if (selection == 2) {
                cout << "Which container would you like to remove elements from?" << endl <<
                        "1. Stack" << endl <<
                        "2. Queue" << endl;
                cin >> removeElements;

                if (removeElements == 1) {
                    cout << "Which stack would you like to remove elements from?" << endl <<
                            "1. Dynamic array" << endl <<
                            "2. List" << endl <<
                            "3. Vector" << endl;
                    cin >> sRemType;

                    if (sRemType == 1) {
                        stack1.Pop();
                    }
                    else if (sRemType == 2) {
                        stack2.Pop();
                    }
                    else if (sRemType == 3) {
                        stack3.Pop();
                    }
                }

                else if (removeElements == 2) {
                    cout << "Which queue would you like to remove elements from?" << endl <<
                            "1. Dynamic array" << endl <<
                            "2. List" << endl <<
                            "3. Vector" << endl;
                    cin >> qRemType;

                    if (qRemType == 1) {
                        queue1.dequeue();
                    }
                    else if (qRemType == 2) {
                        queue2.dequeue();
                    }
                    else if (qRemType == 3) {
                        queue3.dequeue();
                    }
                }

            }

            else if (selection == 3) {
                cout << "Which container would you like to see the contents of?" << endl <<
                        "1. Stack" << endl <<
                        "2. Queue" << endl;
                cin >> contentsOf;

                if (contentsOf == 1) {
                    if(!stack1.IsEmpty()) {
                        cout << "The contents of the dynamic array stack is: ";
                        stack1.PrintStack();
                        cout << endl;
                    }
                    else
                        cout << "The dynamic array stack is empty" << endl;
                    if(!stack2.IsEmpty()) {
                        cout << "The contents of the list stack is: ";
                        stack2.PrintStack();
                        cout << endl;
                    }
                    else
                        cout << "The list stack is empty" << endl;
                    if(!stack3.IsEmpty()) {
                        cout << "The contents of the vector stack is: ";
                        stack3.PrintStack();
                        cout << endl;
                    }
                    else
                        cout << "The vector stack is empty" << endl;
                }

                else if (contentsOf == 2) {
                    if(!queue3.IsEmpty()) {
                        cout << "The contents of the dynamic array queue is: ";
                        queue3.PrintQueue();
                        cout << endl;
                    }
                    else
                        cout << "The dynamic array queue is empty" << endl;
                    if(!queue2.IsEmpty()) {
                        cout << "The contents of the list queue is: ";
                        queue2.PrintQueue();
                        cout << endl;
                    }
                    else
                        cout << "The list queue is empty" << endl;
                    if(!queue1.IsEmpty()) {
                        cout << "The contents of the vector queue is: ";
                        queue1.PrintQueue();
                        cout << endl;
                    }
                    else
                        cout << "The vector queue is empty" << endl;
                }

            }

            else if (selection == 4) {
                cout << "Which container would you like to see the size of?" << endl <<
                        "1. Stack" << endl <<
                        "2. Queue" << endl;
                cin >> sizeOf;

                if (sizeOf == 1) {
                    if (!stack1.IsEmpty())
                        cout << "The size of the dynamic array stack is: " << stack1.size() << endl;
                    else
                        cout << "The dynamic array stack is empty" << endl;
                    if (!stack2.IsEmpty())
                        cout << "The size of the list stack is: " << stack2.size() << endl;
                    else
                        cout << "The list stack is empty" << endl;
                    if (!stack3.IsEmpty())
                        cout << "The size of the vector stack is: " << stack3.size() << endl;
                    else
                        cout << "The vector stack is empty" << endl;

                }
                else if (sizeOf == 2) {
                    if (!queue3.IsEmpty())
                        cout << "The size of the dynamic array queue is: " << queue3.size() << endl;
                    else
                        cout << "The dynamic array queue is empty" << endl;
                    if (!queue2.IsEmpty())
                        cout << "The size of the list queue is: " << queue2.size() << endl;
                    else
                        cout << "The list queue is empty" << endl;
                    if (!queue1.IsEmpty())
                        cout << "The size of the vector queue is: " << queue1.size() << endl;
                    else
                        cout << "The vector queue is empty" << endl;
                }
            }

            else if (selection == 5) {
                cout << "Which container would you like to see the top/font element of?" << endl <<
                        "1. Stack (top)" << endl <<
                        "2. Queue (front)" << endl;
                cin >> topFront;

                if (topFront == 1) {
                    if (!stack1.IsEmpty())
                        cout << "The top element of the dynamic array stack is: " << stack1.TopStack() << endl;
                    else
                        cout << "The dynamic array stack is empty" << endl;
                    if (!stack2.IsEmpty())
                        cout << "The top element of the list stack is: " << stack2.TopStack() << endl;
                    else
                        cout << "The list stack is empty" << endl;
                    if (!stack3.IsEmpty())
                        cout << "The top element of the vector stack is: " << stack3.TopStack() << endl;
                    else
                        cout << "The vector stack is empty" << endl;

                }
                else if (topFront == 2) {
                    if (!queue3.IsEmpty())
                        cout << "The front element of the dynamic array queue is: " << queue3.front() << endl;
                    else
                        cout << "The dynamic array queue is empty" << endl;
                    if (!queue2.IsEmpty())
                        cout << "The front elelemnt of the list queue is: " << queue2.front() << endl;
                    else
                        cout << "The list queue is empty" << endl;
                    if (!queue1.IsEmpty())
                        cout << "The front element of the vector queue is: " << queue1.front() << endl;
                    else
                        cout << "The vector queue is empty" << endl;
                }
            }
        }

        catch(exception& e)
        {
            cout << e.what() << endl;
        }

        catch(emptyStackException& e){
            cout << e.what() << endl;
        }

        catch(emptyQueueException& e){
            cout << e.what() << endl;
        }

    }while(selection <= 5 && selection >= 1);

    if (selection > 5 || selection < 1){
        cout << "\nYou have made an invalid selection from the main menu. "
                "\nThe program will now end." << endl;

    }   //enables user to escape main menu with an invalid number choice.
    //without this statement, the user would be given the same menu,
    //unable to quit

return 0;
}



