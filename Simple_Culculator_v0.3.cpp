#include<iostream>
#include<vector>
#include<string>
using namespace std;

int evaluate(const vector<int> & numbers, const string & operators){

    if(numbers.size() != operators.size() +1){
        cerr << "错误，数字和运算符号数量不匹配" << endl;
        return 0;
    }

    int result = numbers[0];
        for(size_t i=0 ; i < operators.size() ;  i++){
        switch (operators[i]){
            case '+':
                result += numbers [i + 1];
                break;
            case '-':
                result -= numbers [i + 1];
                break;
            case '*':
                result *= numbers [i + 1];
                break;
            case '/':
                if(numbers [i+1] == 0){
                    cerr << "错误，除数不能为0" << endl;
                    return 0;
                }
                result /= numbers[i + 1];
                break;
            default:
                cerr << "不支持的运算符" << endl;
                return 0;
        }
    }
    return result;
}

int main(){
    vector<int> numbers;
    string operators;
    char input;

    cout << "请输入一系列数字和运算符（+, - , * , / ，并以非数字字符结束）" << endl;
    while(cin >> input){
        if (isdigit(input)){
            numbers.push_back(input - '0');
        } else if(input == '+' || input == '-' || input == '*' || input == '/'){
            operators += input;
        }else{
            break;
        }
    }

    if(!numbers.empty() && !operators.empty()){
        int result = evaluate(numbers,operators);
        cout << "结果是"  << result <<endl;
    }else{
        cout << "没有输入有效的运算符" << endl;
    }

    return 0;
}