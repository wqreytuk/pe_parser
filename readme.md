[中文](https://github.com/motherfucker12138/pe-parser/blob/main/readme-ZH.md)

**BUILD WITH VS2012**

I don't know how to export the functions in import table of PE file with [PE-bear](https://github.com/hasherezade/pe-bear-releases)

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
