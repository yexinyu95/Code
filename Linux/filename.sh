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