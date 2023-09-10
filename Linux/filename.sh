$folderPath = "C:\Path\To\Your\Folder"

# 获取文件夹内所有文件
$files = Get-ChildItem $folderPath

# 遍历每个文件并修改文件名
foreach ($file in $files) {
    $newFileName = $file.Name.Substring(2)
    $newPath = Join-Path -Path $folderPath -ChildPath $newFileName
    Rename-Item -Path $file.FullName -NewName $newPath
}

Write-Host "File names have been modified."





#分隔符问题：如果你的字符串中包含了其他不可见字符（如换行符或制表符），它们可能会干扰字符串的分隔。
#你可以尝试先使用Trim()函数来去除字符串两侧的空白字符，然后再进行拆分。

$directoryPath = "C:\Path\To\Directory"
$directoryListing = dir $directoryPath
$directoryListingAsString = $directoryListing | Out-String
Write-Host $directoryListingAsString

$directoryListingAsString = dir -name
$fileNames = ($directoryListingAsString.Trim()) -split ' '
foreach ($fileName in $fileNames) {
    Write-Host $fileName
}



# dir -name rename.csv；将文件名输出到csv
# Excel ="ren "&A1&" "&B1，
# 拼接ren命令和两个文件名字符串