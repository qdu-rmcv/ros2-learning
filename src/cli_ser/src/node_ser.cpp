#include "rclcpp/rclcpp.hpp"
#include "zidingyi_xiaoxijiekou/srv/fuwu.hpp"

class node_test: public rclcpp::Node{
    public:
    node_test(std::string name):Node(name){
        RCLCPP_INFO(this->get_logger(),"服务端启动!");
        service_=this->create_service<zidingyi_xiaoxijiekou::srv::Fuwu>("cli_ser1",std::bind(&node_test::ser_callback,
        this,std::placeholders::_1,std::placeholders::_2));
        this->declare_parameter<int>("param1",0);
        param1 = this->get_parameter("param1").as_int();
    }//构造函数，创建服务端，并声明和获取参数，服务的回调函数是ser_callback，收到客户端数据后调用此函数
    private:
    int param1;
    rclcpp::Service<zidingyi_xiaoxijiekou::srv::Fuwu>::SharedPtr service_;
    void ser_callback(const std::shared_ptr<zidingyi_xiaoxijiekou::srv::Fuwu::Request> request,
    std::shared_ptr<zidingyi_xiaoxijiekou::srv::Fuwu::Response> response){
        RCLCPP_INFO(this->get_logger(),"接收到数据%d和%d",request->num1,request->num2);
        response->sum=((request->num1)+(request->num2))*(this->param1);
        RCLCPP_INFO(this->get_logger(),"已返回结果");
    }//回调函数，进行计算数据并返回数据
};

int main(int argc,char **argv){
    rclcpp::init(argc,argv);
    auto node=std::make_shared<node_test>("ser01");//创建节点的共享指针
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}