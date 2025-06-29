class StackC{
private:
    int top;
    int max;
    char* arr;
public:
    StackC(int s){
        max = s;
        arr = new char[s];
        top=0;
    }
    void push(char c){
        arr[top++] = c;
    }
    void pop(){
        top--;
    }
    char getTop(){
        return arr[top-1];
    }
};
