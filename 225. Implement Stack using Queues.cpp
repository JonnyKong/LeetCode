class Stack {
private:
    int count;
    queue<int> a;
    queue<int> b;
    bool condition; //0 : a is main
    
public:
    Stack(): count(0), condition(0) {}
    
    // Push element x onto stack.
    void push(int x) {
        ++count;
        
        if (condition) a.push(x);
        
        else b.push(x);
        
    }

    // Removes the element on top of the stack.
    void pop() {
        
        if (condition){
            
            for(int i = 0; i < count - 1; ++i){
                
                int temp = a.front();
                a.pop();
                b.push(temp);
                
            }
            
            a.pop();
            
        }
        
        else{
            
           for(int i = 0; i < count - 1; ++i){
               
               int temp = b.front();
               b.pop();
               a.push(temp);
               
           }
           
           b.pop();
            
        }
        
        --count;
        
        condition ^= 1;
        
    }

    // Get the top element.
    int top() {
        
        int temp;
        
        if (condition){
            
            for(int i = 0; i < count; ++i){
                
                temp = a.front();
                a.pop();
                b.push(temp);
                
            }
            
        }
        
        else{
            
            for(int i = 0; i < count; ++i){
               
                temp = b.front();
               
                b.pop();
               
                a.push(temp);
               
            }
            
        }
        
        condition ^= 1;
        
        return temp;
        
    }

    // Return whether the stack is empty.
    bool empty() {
        
        return a.empty() && b.empty();
        
    }
};