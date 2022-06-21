**本项目使用VS2012构建**

[PE-bear](https://github.com/hasherezade/pe-bear-releases)好像没办法把import table中的函数导出来

![image](https://user-images.githubusercontent.com/106856146/171994056-102b6834-f6ce-4957-a27d-530f2c126f14.png)

所以我就写了这个小工具

由于我代码写的比较垃圾，所以只能在visual stduio中运行，直接在cmd中运行会运行到一半自己停下来

用法：
```
pe-parser.exe C:\users\x\downloads\srv2.sys
```

输出结果会保存在当前目录下的`motehrfuckerout.txt`中

程序只能在vs中运行的原因是堆内存在调试器下和cmd下不一样

https://stackoverflow.com/questions/16696444/differences-between-running-an-executable-with-visual-studio-debugger-vs-without

凑合用吧
