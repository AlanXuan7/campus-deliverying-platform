//含有四个功能的一个合法性检测cpp，可以检测name，id，password，time（营业时间）
//函数调用为Protectname（name），返回值为1代表检测合规

#include<iostream>
#include<string>
using namespace std;
//判断是否含有数字，特殊字符等（查姓名）
bool IfnumbOrChar(string A){
    int len=A.length();
    int flag=0;
    for(int i=0;i<len;i++)
        if(isdigit(A[i])||A[i]>=33&A[i]<=47||A[i]>=58&A[i]<=64||A[i]>=91&A[i]<=96||A[i]>=123&A[i]<=127)
            flag=1;

    if(flag==1)
        return true;
    else
        return false;
}

//判断是否由纯数字构成（查账号）
bool Allnumb(string A){
    int len=A.length();
    int flag=1;
    for(int i=0;i<len;i++)
        if(!isdigit(A[i]))
            flag=0;

    if(flag==1)
        return true;
    else
        return false;
}

//判断是否只含有数字，英文，特殊字符（查密码）
bool Ifpassword(string A){
    int len=A.length();
    int flag=1;
    for(int i=0;i<len;i++)
        if(A[i]>126||A[i]<33)
            flag=0;

    if(flag==1)
        return true;
    else
        return false;
}
//判断是否是正确的营业时间（查营业时间）
bool Iftime(string A){
    int len=A.length();
    int flag=1;
    for(int i=0;i<len;i++)
        if(!isdigit(A[i])&&A[i]!=':'&&A[i]!='-')
            flag=0;

    if(flag==1)
        return true;
    else
        return false;
}

//查姓名  返回值为1说明格式正确
int Protectname(string name){
    if(IfnumbOrChar(name))
    {
        cout<<"姓名中不允许含有阿拉伯数字和特殊字符！"<<endl;
        return 0;
    }
    else
        return 1;
}

//查ID  返回值为1说明格式正确
int Protectid(string id){
    if(!Allnumb(id))
    {
        cout<<"ID只能由纯数字构成！"<<endl;
        return 0;
    }
    else
        return 1;
}

//查密码 返回值为1说明格式正确
int Protectpassword(string password){
    if(!Ifpassword(password))
    {
        cout<<"密码只能由数字，英文，特殊字符构成！"<<endl;
        return 0;
    }
    else
        return 1;
}

//查营业时间 返回值为1说明格式正确
int Protecttime(string time){
    if(!Iftime(time)){
        cout<<"营业时间格式错误！"<<endl;
        return 0;
    }
    else
        return 1;
}

//测试主函数
//int main(){
//    string name;
//    string id;
//    string password;
//    string time;
//    cin>>name;
//    int a=Protectname(name);
//    cout<<a<<endl;
//    cin>>id;
//    int b=Protectid(id);
//    cout<<b<<endl;
//    cin>>password;
//    int c=Protectpassword(password);
//    cout<<c<<endl;
//    cin>>time;
//    int d=Protecttime(time);
//    cout<<d<<endl;
//    return 0;
//}