import os

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration,PathJoinSubstitution

def generate_launch_description():
    # 获取被包含 Launch 文件的路径
    another_launch_file = os.path.join(
        get_package_share_directory('client'),
        'launch',
        'client.launch.py'
    )
    # 声明启动参数
    config_arg = DeclareLaunchArgument(# 动态加载yaml文件,启动时选择合适的yaml文件
        name = 'config_file',
        default_value = 'my_params.yaml',# 默认值
    )

    # 获取 YAML 文件路径
    params_file = PathJoinSubstitution(
        [get_package_share_directory('server'), # 获取指定包的share目录
        'config', # 所在文件夹
        LaunchConfiguration('config_file')]  # yaml文件名，这里是动态加载 yaml文件
    )


    return LaunchDescription([
        config_arg,
        
        # 添加节点与配置
	Node(
		package = 'server',
		executable = 'server', 
		parameters = [params_file],
		output = 'screen' # 输出到控制台
	),
		# 包含另一个 Launch 文件并传递参数
        IncludeLaunchDescription(
	        # 将指定的launch文件加载为一个LaunchDescription对象
            PythonLaunchDescriptionSource(another_launch_file)
        )
	])
