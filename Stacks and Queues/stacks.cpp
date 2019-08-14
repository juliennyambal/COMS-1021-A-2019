#include <iostream> 
#include <stack> 
using namespace std; 
  
void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    stack <int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 
  
    return 0; 
} 



template <typenameE> 
voidreverse(vector<E>& V){   // reverse a vector
    ArrayStack <E> S(V.size());
    for(inti = 0; i<V.size(); i++) // push elements onto stack
    S.push(V[i]);
    for(inti = 0; i<V.size(); i++){ // pop them in reverse order
    V[i] = S.top();  S.pop();
    }
}

Code Fragment 5.10:A generic function that uses a stack to reverse a vector.