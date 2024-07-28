#include<iostream>
#include<string>
#include<limits>  

double add(double a,double b){
    return a + b;
}
double subtract(double a,double b){
    return a - b;
}
double multiply(double a,double b){
    return a * b;
}
double divide(double a,double b){
    return a / b;
}

int main(){
    double num1,num2;
    char operatorSymple;
    std::string input;

    std::cout << "简单计算器v0.2" << std::endl;
    std::cout << "请依次输入第一个数字，运算符，第二个数字，每次输入完成后回车键确认" << std::endl;
    
    while(true){
        std::cin.clear();
        
        std::cin >> num1 >> operatorSymple >> num2;

        switch(operatorSymple){
            case '+':
                std::cout << add(num1,num2) << std::endl; 
                break;
            case '-':
                std::cout << subtract(num1,num2) << std::endl; 
                break;

            case '*':
                std::cout << multiply(num1,num2) << std::endl; 
                break;

            case  '/':
                if(num2 != 0.0){
                    std::cout << divide(num1,num2) << std::endl; 
                    break;
                }
                else    
                    std::cout << "除数不能为0" << std::endl ;
                    break;
                
            default:
                std::cout << "输入不合法" << std::endl;
                std::string input;
                std::cout << "输入'exit'以退出程序，或重新输入正确值进行运算" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


                while(true){
                    std::getline(std::cin,input);
                    
                    if(input == "exit"){

                        std::cout << "退出程序" << std::endl;
                        break;
                    }  
                break;
                } 
                break; 
        }
    break;
    }
    return 0; 


}