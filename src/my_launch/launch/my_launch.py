'''
Author: BandieraRosa 3132716198@qq.com
Date: 2025-02-27 16:40:23
LastEditors: BandieraRosa 3132716198@qq.com
LastEditTime: 2025-02-27 17:29:14
FilePath: /ros2_learning/src/my_launch/launch/my_launch.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    Node1 = Node(package="british_system", 
                 executable="pub_node", 
                 name="pub_node", 
                 output = "screen")
    Node2 = Node(package="metric_system", 
                 executable="sub_node", 
                 name="sub_node", 
                 output = "screen")
    return LaunchDescription([Node1, Node2])