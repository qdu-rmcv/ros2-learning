# 3-18作业思路 
- 消息接口使用自定义消息接口，该消息接口在功能包包zidiingyi_xiaoxijiekou里面
- param1参数（默认为2）在cli_ser/config/canshu.yaml里面修改；num1（默认为12）和num2（默认为7）在cli_ser/src/node_cli.cpp里面的主函数send里面修改
- 运用服务通信，cli_ser功能包里面的客户端（node_cli）向服务端(node_ser)发送简单的几个数(num1和num2)，服务端读取yaml参数然后用参数和客户端发来的数进行简单计算（此处以（num1+num2）*param1做简单示例）然后将计算所得数据返回客户端
- 作业要求launch再调用其他功能包节点，因此此处再利用话题通信，调用other_packages功能包里面的(node_pub)节点，订阅客户端（node_cli）发布的话题，订阅接收客户端最终计算出来的数,再打印出来
## 如何启动:利用work_launch文件里面launch文件夹里面的start.launch.py直接启动就可以