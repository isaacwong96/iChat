#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include<string>

using namespace std;

void func1(){
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";

    string sendBuf = js.dump();
    cout<<js<<endl;
    cout<<sendBuf.c_str()<<endl;
}

void func2(){
    json js;
    js["id"] = {1,2,3,4,5};
    js["name"] = "zhang san";
    js["msg"]["zhang san"]="hello world";
    js["msg"]["liu shuo"] = "hello China";
    //此句与上两名作用相同
    //js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello China"}};
    cout<<js<<endl;
}

void func3(){
    json js;

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    js["list"] = vec;

    map<int, string> m;
    m.insert({1,"黄山"});
    m.insert({2,"华山"});
    m.insert({3,"泰山"});

    js["path"] = m;

    cout<<js<<endl;
}
string simulationRecv1(){
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";

    string sendBuf = js.dump();
    return sendBuf;
}
string simulationRecv2(){
    json js;
    js["id"] = {1,2,3,4,5};
    js["name"] = "zhang san";
    js["msg"]["zhang san"]="hello world";
    js["msg"]["liu shuo"] = "hello China";
    //此句与上两名作用相同
    //js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello China"}};
    return js.dump();
}
string simulationRecv3(){
    json js;

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    js["list"] = vec;

    map<int, string> m;
    m.insert({1,"黄山"});
    m.insert({2,"华山"});
    m.insert({3,"泰山"});

    js["path"] = m;

    return js.dump();
}
int main(){
    //string recvBuf = simulationRecv1();

    //string recvBuf = simulationRecv2();

    string recvBuf = simulationRecv3();

    json jsbuf = json::parse(recvBuf);

    //cout<<jsbuf["msg_type"]<<endl;
    //cout<<jsbuf["from"]<<endl;
    //cout<<jsbuf["to"]<<endl;
    //cout<<jsbuf["msg"]<<endl;

    //cout<<jsbuf["id"]<<endl;
    //auto arr = jsbuf["id"];
    //cout<<arr[2]<<endl;

    vector<int> vec = jsbuf["list"];
    for(auto &v:vec){
        cout<<v<<' ';
    }
    cout<<endl;
    map<int, string> mymap = jsbuf["path"];
    for(auto &p:mymap){
        cout<<p.first<<' '<<p.second<<endl;
    }
    cout<<endl;
    return 0;
}
