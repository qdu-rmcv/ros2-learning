# 作业

## 大体思路

british_pub节点发布随机英寸值到/inch话题，metric_system节点订阅/inch话题来获得英寸值然后转换后再发布到/meter话题

## 说明:
- 消息接口是用的自己自定义的my_msg
- 用的launch启动两个节点，在src里面的work_launch
