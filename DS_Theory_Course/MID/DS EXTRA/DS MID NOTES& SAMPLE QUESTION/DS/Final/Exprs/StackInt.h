class StackInt{
private:
    int top;
    int max;
    int* arr;
public:
    StackInt(int s){
        max = s;
        arr = new int[s];
        top=0;
    }
    void push(int c){
        arr[top++] = c;
    }
    void pop(){
        top--;
    }
    int getTop(){
        return arr[top-1];
    }
};
