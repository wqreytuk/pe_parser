[中文](https://github.com/wqreytuk/pe_parser/blob/main/readme-ZH.md)

**BUILD WITH VS2012**

**PAY ATTENTION! THIS TOOL CAN ONLY WORK IN VS2012 DEBUGGER**

I don't know how to export the functions in export/import table of PE file with [PE-bear](https://github.com/hasherezade/pe-bear-releases)

![image](https://user-images.githubusercontent.com/106856146/171994056-102b6834-f6ce-4957-a27d-530f2c126f14.png)

I want the function list, but there is no option for me to do it


so I write this little tool, it is enough for me

usage:
```
pe-parser.exe C:\users\x\downloads\srv2.sys
```

for some reason (maybe my shit code), you have to run it in visual studio

result will be saved in .\motherfuckerout.txt


turns out my code can only run normally with debugger: https://stackoverflow.com/questions/16696444/differences-between-running-an-executable-with-visual-studio-debugger-vs-without

because the heap is different with debugger and standalone


# 2022-10-02 更新

提取shellcode到二进制文件的功能

![image](https://user-images.githubusercontent.com/48377190/193454451-4d5782a5-3744-450f-9281-b00598ae624f.png)

取消注释Line 1865~1873之前的代码注释即可，.text的内容会被写到data.bin文件中（覆盖写）
