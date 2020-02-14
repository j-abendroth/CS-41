/*
 John Abendroth
 Program 1
 CS 41
*/

#include <iostream>
#include <sstream>
using namespace std;

struct node {
    float num;
    node *next;
};

class Stack{
public:
    Stack() {top = NULL;};
    bool IsEmpty();
    void push(float x);
    void pop();
    float peek();
    bool checkSize(int n);
    void display();
    void print();
    node *top;
};

class RPN: public Stack{
public:
    void add();
    void subtract();
    void multiply();
    void divide();
    bool isOperator(const string& input);
    void performOperation(const string& input);
};

//function to check if stack is empty
bool Stack::IsEmpty(){
    return (top == NULL);
}

//function to push data into stack
void Stack::push(float pushed_num){
    
    //create new node for data to be pushed
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    
    //put the pushed data into temp, assign top pointer to temp link, and make temp as top of stack
    temp->num = pushed_num;
    temp->next = top;
    top = temp;
}

//function to pop value from top of the stack
void Stack::pop(){
    //Check if stack is empty, if it's not move the top of the stack to the next value
    if(IsEmpty())
        cout << "Error: Empty Stack";
    else
        top = top->next;
}

//function to return top element in the stack
float Stack::peek(){
    if(IsEmpty())
        cout << "Error: Empty Stack";
    return top->num;
}

//function to return how many items are in the stack
bool Stack::checkSize(int n){
    int size = 0, count = 0;
    
    node* temp = top;
    while (temp != NULL)
    {
        count ++;
        temp = temp->next;
    }
    
    size = count;
    
    if (size >= n)
    {
        return true;
    }

    else
        return false;
}

void Stack::display(){
    node* temp;
    
    if(IsEmpty())
        cout << "Stack is empty" << endl;
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->num << endl;
            temp = temp-> next;
        }
    }
    /*
    else
    {
        cout << " = " << top->num << endl;
        while (top != NULL)
        {
            pop();
        }
    }
    */
}

void Stack::print(){
    cout << " = " << top->num << endl;
}

//function to add two operands together
void RPN::add(){
    float num1, num2;
    
    //check if there's enough operands in the stack to complete the operator, if there is pop the first 2 values in the stack and add them together
    if (checkSize(2))
    {
        num1 = peek();
        pop();
        num2 = peek();
        pop();
        
        push(num1 + num2);
        
        print();
    }
    else
        cout << "Error: Too many operators" << endl;
}

//function to subract two operands together
void RPN::subtract(){
    float num1, num2;
    
    //check if there's enough operands in the stack to complete the operator, if there is pop tthe first 2 values in the stack and subtract them
    if (checkSize(2))
    {
        num1 = peek();
        pop();
        num2 = peek();
        pop();
        
        push(num2 - num1);
        
        print();
    }
    else
        cout << "Error: Too many operators" << endl;
}

void RPN::multiply(){
    float num1, num2;
    
    if (checkSize(2))
    {
        num1 = peek();
        pop();
        num2 = peek();
        pop();
        
        push(num1 * num2);
        
        print();
    }
    else
        cout << "Error: Too many operators" << endl;
}


void RPN::divide(){
    float num1, num2;
    
    if (checkSize(2))
    {
        num1 = peek();
        pop();
        num2 = peek();
        pop();
        
        if (num1 == 0)
            //throw invalid_argument("Division by zero");
            cout << " Error: Division by zero" << endl;
        else
            push(num2 / num1);
        
        print();
    }
    else
        cout << "Error: Too many operators" << endl;
}

bool RPN::isOperator(const string& input){
    string arr[] = {"+", "-", "*", "/"};
    for (int i = 0; i < 4; i++)
    {
        if (input == arr[i])
            return true;
    }
    
    return false;
}

void RPN::performOperation(const string& input){
    switch (input[0])
    {
        case '+':
            add();
            break;
        case '-':
            subtract();
            break;
        case '*':
            multiply();
            break;
        case '/':
            divide();
            break;
    }
}

int main(){
    RPN calc;
    bool keep_going = true;
    string input;
    float num;
    
    cout << "Reverse Polish Notation Calculator" << endl;
    cout << "Enter your RPN string (Enter 0 to exit)" << endl;
    
    while (1)
    {
        //cin >> input;
        getline(cin, input);
        stringstream ss(input);
        
        if (input == "0")
            return 0;
        
        if (ss >> num)
        {
            calc.push(num);
        }
        else if (calc.isOperator(input))
        {
            calc.performOperation(input);
        }
    }
    return 0;
}
