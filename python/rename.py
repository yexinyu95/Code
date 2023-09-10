# 可以删除文件夹内所有文件名的前两个字符
# 请确保在运行之前备份重要文件
import os

folder_path = "your_folder_path"  # 替换为你要操作的文件夹路径

for filename in os.listdir(folder_path):
    if filename[2:] != "":
        new_filename = filename[2:]
        new_file_path = os.path.join(folder_path, new_filename)
        os.rename(os.path.join(folder_path, filename), new_file_path)