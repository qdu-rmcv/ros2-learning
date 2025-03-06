import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # British System节点
        Node(
            package='british_system',
            executable='british_system_node',
            name='inch_publisher',
            output='screen',
            parameters=[{
                'publish_frequency': 10.0  # 可配置参数示例
            }]
        ),
        
        # Metric System节点 
        Node(
        package='metric_system',
        executable='metric_system_node',
        name='metric_node',  # 推荐使用标准命名
        output='screen',
    )
    ])