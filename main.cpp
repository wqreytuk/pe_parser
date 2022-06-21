#include<windows.h>
#include<TChar.h>
#include<iostream>
#include<time.h>
#include<string>

#include <stdlib.h>

#include<fstream>
#include <io.h>
#include <fcntl.h>
#define _ui unsigned int
 #define _ul unsigned long
//int wmain(int argc, wchar_t* argv[])
//{
//#define ____DEBUG
//  #define _qunimade
#ifdef ____DEBUG

#define FUCK(_format, _var) printf(_format, _var);
#define CUM(_str) printf(_str);
#else
#define FUCK(_format, _var);
#define CUM(_str);
#endif

#ifdef _qunimade
#define qnmd return 0
#else
#define qnmd while(1)break
#endif // _UNICODE
#ifdef _UNICODE

#define cout(x) std::wcout<<_TEXT(##x##)
#define pout(x) std::wcout<<##x
#define acout(x) std::cout<<##x
#define motherfucker_string std::wstring
#else
#define cout(x) std::cout<<##x
#define acout(x) std::cout<<##x
#define pout(x) std::cout<<##x
#define motherfucker_string std::string
#endif // _UNICODE
#pragma comment(lib,"user32.lib")
#include <map>

void _read_ascii(_ui _offset, std::ifstream* _steam, char* _out) {
    char hex_sting[4096] = {0};
    char buffer[64];
    for(int i=0;;i++){
        memset(buffer,0,64);
        _steam->seekg(_offset+i);
        _steam->read(buffer, 1);
        FUCK("%u\n",(unsigned char)buffer[0]);
        strcat(hex_sting,buffer);
        if(strlen(buffer)==0)
            break;
    }
    strcpy(_out, hex_sting);
}


_ui _2_bytes_deal(char* buffer) {
    char  _tmnp_string[2+1]={0};
    char hex_sting[4+1] = {0};
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
    strcpy(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
    strcat(hex_sting, _tmnp_string);
    return (_ui)strtoul(hex_sting,NULL,16);
}

_ui _4_bytes_deal(char* buffer) {
    char  _tmnp_string[2+1]={0};
    char hex_sting[8+1] = {0};
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
    strcpy(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
    strcat(hex_sting, _tmnp_string);
    FUCK("hex_sting: %s",hex_sting);
    return (_ui)strtoul(hex_sting,NULL,16);
}


// 定义一个结构体，用来存放section header
typedef unsigned short WORD;
typedef unsigned long DWORD;
struct SECTION_HEADER_STRUCT {
    DWORD name_high;
    DWORD name_low;
    DWORD virtual_size;
    DWORD virtual_address;
    DWORD size_of_raw_data;
    DWORD pointer_to_raw_data;
    DWORD pointer_to_relocations;
    DWORD pointer_to_linenumbers;
    WORD number_of_relocations;
    WORD number_of_linenumbers;
    DWORD flag;
} section_header, *p_section_header;

void flag_display(std::map<_ui, motherfucker_string> fucking_map, _ui flag_value) {
    cout("下面输出启用了的标志位：\n");
    std::map<_ui, motherfucker_string>::iterator iter;
    iter = fucking_map.begin();
    while(iter != fucking_map.end()) {
        _ui fuckyou=flag_value&(iter->first);
        if(fuckyou>0){
            acout("\t");
            pout(iter->second);
            acout("\n");
        }
        iter++;
    }
}
struct DATA_DIRECTORY_STRUCT {
    DWORD addr;
    DWORD size;
} data_directory, *p_data_directory;
std::map<motherfucker_string, struct DATA_DIRECTORY_STRUCT> data_directory_map ;
_ui convert_rva_to_file_pointer(_ui rva, struct SECTION_HEADER_STRUCT* _p_section_header, _ui number_of_sections) {
    _ui time_stamp_umber_of_sections=rva;
    for(int i=0;i<number_of_sections;i++) {
        FUCK("section virtual address : 0x%0x\n",_p_section_header[i].virtual_address);
        FUCK("section raw file pointer: 0x%0x\n",_p_section_header[i].pointer_to_raw_data);
        _ui fuckyou = _p_section_header[i].virtual_address + _p_section_header[i].virtual_size;
        FUCK("fuckyou: 0x%x\n",fuckyou);
        if(fuckyou >= time_stamp_umber_of_sections) {
            // cout("小伙子你怎么回事？\n");
            // cout("小伙子你怎么回事？\n");
            FUCK("0x%x\n",time_stamp_umber_of_sections);
            // cout("小伙子你怎么回事？\n");
            FUCK("0x%x\n",_p_section_header[i].virtual_address);
            FUCK("%x\n",(_ui)_p_section_header[i].virtual_address);
            FUCK("%x\n", _p_section_header[i].pointer_to_raw_data);
            return time_stamp_umber_of_sections - _p_section_header[i].virtual_address+_p_section_header[i].pointer_to_raw_data;
        }
    }
}

int _tmain(int argc, TCHAR *argv[]){
	*stdout = *fopen("motherfuckerout.txt","w"); 
    // LPCTSTR _fucking_final_name = _TEXT("C:\\users\\public\\downloads\\Final.gif");
    // CopyFile(argv[1],"",0)
    
    std::map<_ui, std::string> machine_type_my_map ;

machine_type_my_map.insert(std::pair<_ui,std::string>(0x8664,"IMAGE_FILE_MACHINE_AMD64"));
    //我电脑的cmd总是把中文输出成乱码，所以在执行之前，先执行一下chcp，让他能正常输出中文
	// 、、如果在你的电脑上，chcp 936出现invalid page，那么你可能需要修改一些设置
	// https://social.msdn.microsoft.com/Forums/ie/zh-TW/61f4f0bc-b7d6-4010-a4a9-2359cd2b9991/invalid-code-page?forum=237
	// https://ibb.co/KVnkzJc
 system("chcp 936");    //LPCTSTR szError = "有内扣的";
 SetConsoleTitle(L"My Console Window - 你好");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    char* a = setlocale(LC_ALL, "chinese");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
	// 此时ascii会被当做ascii进行编译
	/*、*
	 error C2440: 'initializing' : cannot convert from 'const wchar_t [5]' to 'LPCTSTR'
	 可以看到，报错了，说是无法将宽字节字符数组转换成LPCTSTR
	 哦哦哦。sorry，我忘了保存文件了，这个时候编译应该不会报错的，因为我没有定义UNICODE宏
	  error C2440: 'initializing' : cannot convert from 'const char [6]' to 'LPCTSTR'
	  可以看到，出现了意料之内的报错，就是说他没有办法吧ascii字符串转换成unicode字符串
	  因为这时候我们的LPCTSTR由于UNICODE宏的出现，已经变成了LPCWSTR,
	  此时如果想消除错误，我们就需要显式地告诉编译器，这个字符串是一个UNICODE字符串
	  可以使用  L
	  : error C2440: 'initializing' : cannot convert from 'const wchar_t [6]' to 'LPCTSTR'
	  可以看到，又报错了，这回是因为没有了UNICODE宏，LPCTSTR变成了 char指针，而不是wchar了
	  而此时又使用了L表明字符串应该是UNICODE字符串，即wchar，因此就出现了错误，其实就是无法将wchar转换成char
	  那该如何解决呢？

	  答案就是使用_TEXT
	  他可以根据UNICODE是否定义来判断是否使用L
	  其实_TEXT的定义就是
	  #ifdef UNICODE
	  typedef _TEXT(x) L ## x
	  #else
	  typedef _TEXT(x) x
	#endif
	差不多就是这个样子
	*/
//	LPCTSTR szError = _TEXT("有内扣的");

//    MessageBox(NULL, szError, NULL, 0);

//LPCTSTR pszName = _TEXT("Path");
//TCHAR pszValue[4096] = {0};
//GetEnvironmentVariable(pszName, pszValue, 4096);
////std::wcout << pszValue;
////printf("%s\n", pszValue);
//cout(pszValue);
//让我来写一个PE Parser
//功能就是对PE文件进行解析，将各个区段给解析出来
//根据之前对PE格式的了解，大致分为以下几个部分
//DOS header
//dos stub
//NT header
////section
//好的，下面就开始撸
//首先要读取文件，而且还要以二进制的形式读取文件

//随便在网上搜了一本PE格式相关标准的pdf   http://www.osdever.net/documents/PECOFF.pdf
//    首先是一些基本的概念
//
//    image file 翻译过来就是镜像文件，其实就是可执行文件，exe dll sys等等
//    之所以叫作镜像文件是因为，这个文件就像是内存的镜像一样，
//    而且一般情况下我们不称其为可执行文件，是因为可执行文件一般指exe后缀的文件
//    还有其他一起文件虽然不可以直接执行，但也是PE格式的，统称为image file镜像文件
//
//    Object file，就是使用cl编译器编译出来的一个文件，一定要区别于面向对象编程语言，这个对象文件
//    跟面向对象编程中的对象没有任何关系
//    object file是linnker（链接器）的输入文件，linker会把他给链接成image file（不一定是exe）
//
//    RVA  相对虚拟地址，就是相对虚拟地址的一个地址，相对的是image base
//    image base地址是VA，也就是绝对虚拟地址，比如说image base是0x4000,那么RVA=0x100，换算成VA就是0x4100
//
//    VA  不用多介绍了，上面已经说过了，只不过有一点，就是VA的值并不一定准确，因为此时还没有加载到内存中，
//    操作系统指不定会把image加载到哪个内存地址上
//
//    file pointer，就像是VA和RVA，只不过VA和RVA是针对内存而言的地址，file ponter是针对磁盘文件而言的
//    其实说白了都是类似偏移量的东西
//
//    time stamp 时间戳，没什么好说的
//
//    section   概念有点像8086汇编中的segment（段）
//
//    一个典型32位PE结构图
//    https://ibb.co/rshJqNr

//这个PDF版的标准有一部分丢了，不见了，又重新找了一个，
//https://formats.kaitai.io/microsoft_pe/microsoft_pe.svg
//    这个svg版本的挺不错的
//    直接在浏览器里打开查看就行了
//开撸，
//先把PE文件读到一个buffer中
//std::ifstream input( "C:\\Final.gif", std::ios::binary );
//
//    // copies all data into buffer
//    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
char buffer[64] = {0};
std::ifstream strm;
strm.open (argv[1],std::ifstream::binary);
// strm.open ( _TEXT("C:\\Users\\x\\Documents\\Visual Studio 2012\\Projects\\ConsoleApplication1\\ConsoleApplication1\\ConsoleApplication1.exe") );

strm.seekg (0);
strm.read (buffer, 2);
//cout((unsigned char)buffer[60]);
//cout(_TEXT("Hello渔 Worn\n"));
//cout(_TEXT("Hello渔 Worn\n"));
// MessageBox(NULL, _TEXT("渔鸥内科"), NULL, 0);//首先是magic字符串，也就是MZ，两个字节
//cout(_TEXT("这他妈根本就不是一个PE文件\n"));

if(buffer[0]!='M' && buffer[1] != 'Z') {
    cout("这他妈根本就不是一个PE文件\n");
}
else{
    cout("检测到魔术字符MZ，可能是一个PE文件，继续解析。。。\n");
}
//直接略过58字节，因为这些事为了dos系统兼容的一些东西，对我们没啥用，跳过
strm.seekg (60);
//通过设置偏移量我们跳过了58字节，然后我们再读取出来4个字节，来获取PE header的偏移量
//就是NT header
memset(buffer,0,64);
strm.read (buffer, 4);
//由于小段序的原因，我们需要对这四个字节进行反序
char  _tmnp_string[2+1]={0};
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
char* hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
cout("定位到PE header偏移量为： ");
//acout(hex_sting);acout("\n");
_ui pe_header_offset=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
printf("0x%08x\n", pe_header_offset);

//然后我们把文件指针定位到pe_header_offset
//定位置后，先读取出4字节的pe签名，就是PE\0\0
strm.seekg (pe_header_offset);
memset(buffer,0,64);
strm.read (buffer, 4);
cout("PE签名：");acout(buffer);acout("\n");
//然后是20个字节的coff header，COFF header里面存了很多重要的信息
//在PEbear里面，coff header被称作 file header
//首先是machine type 2bytes
//machine type的完整列表
/*、*
Constant	Value	Description
IMAGE_FILE_MACHINE_UNKNOWN
0x0
The content of this field is assumed to be applicable to any machine type
IMAGE_FILE_MACHINE_AM33
0x1d3
Matsushita AM33
IMAGE_FILE_MACHINE_AMD64
0x8664
x64
IMAGE_FILE_MACHINE_ARM
0x1c0
ARM little endian
IMAGE_FILE_MACHINE_ARM64
0xaa64
ARM64 little endian
IMAGE_FILE_MACHINE_ARMNT
0x1c4
ARM Thumb-2 little endian
IMAGE_FILE_MACHINE_EBC
0xebc
EFI byte code
IMAGE_FILE_MACHINE_I386
0x14c
Intel 386 or later processors and compatible processors
IMAGE_FILE_MACHINE_IA64
0x200
Intel Itanium processor family
IMAGE_FILE_MACHINE_LOONGARCH32
0x6232
LoongArch 32-bit processor family
IMAGE_FILE_MACHINE_LOONGARCH64
0x6264
LoongArch 64-bit processor family
IMAGE_FILE_MACHINE_M32R
0x9041
Mitsubishi M32R little endian
IMAGE_FILE_MACHINE_MIPS16
0x266
MIPS16
IMAGE_FILE_MACHINE_MIPSFPU
0x366
MIPS with FPU
IMAGE_FILE_MACHINE_MIPSFPU16
0x466
MIPS16 with FPU
IMAGE_FILE_MACHINE_POWERPC
0x1f0
Power PC little endian
IMAGE_FILE_MACHINE_POWERPCFP
0x1f1
Power PC with floating point support
IMAGE_FILE_MACHINE_R4000
0x166
MIPS little endian
IMAGE_FILE_MACHINE_RISCV32
0x5032
RISC-V 32-bit address space
IMAGE_FILE_MACHINE_RISCV64
0x5064
RISC-V 64-bit address space
IMAGE_FILE_MACHINE_RISCV128
0x5128
RISC-V 128-bit address space
IMAGE_FILE_MACHINE_SH3
0x1a2
Hitachi SH3
IMAGE_FILE_MACHINE_SH3DSP
0x1a3
Hitachi SH3 DSP
IMAGE_FILE_MACHINE_SH4
0x1a6
Hitachi SH4
IMAGE_FILE_MACHINE_SH5
0x1a8
Hitachi SH5
IMAGE_FILE_MACHINE_THUMB
0x1c2
Thumb
IMAGE_FILE_MACHINE_WCEMIPSV2
0x169
MIPS little-endian WCE v2
*/
strm.seekg (pe_header_offset+4);
memset(buffer,0,64);
strm.read (buffer, 2);
//同样需要进行翻转 小端序

memset(_tmnp_string,0,3);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);

_ui machine_type_value=(_ui)strtoul(hex_sting,NULL,16);cout("machine type(处理器)：");
acout(machine_type_value);acout("    ");
free(hex_sting);
acout(machine_type_my_map[machine_type_value]);acout("\n");
//然后是number of sections，即扇区数量  2bytes
_ui number_of_sections;
strm.seekg (pe_header_offset+4+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//同样需要进行翻转 小端序

memset(_tmnp_string,0,3);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
number_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(处理器)：");
// _ui section_number = number_of_sections;
free(hex_sting);
cout("扇区数量：");
acout(number_of_sections);acout("\n");
//下面是时间戳，不过这个时间戳是谁的时间戳？PE文件的吗？   4bytes

// 看了官方文档，这个时间戳是link的时间戳，也就是exe生成的时间，但是不知道为啥系统PE文件的时间戳都是千奇百怪的，
//显示的是未来的时间
_ui time_stamp_umber_of_sections;
strm.seekg (pe_header_offset+4+2+2);
memset(buffer,0,64);
strm.read (buffer, 4);
//同样需要进行翻转 小端序

memset(_tmnp_string,0,3);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(处理器)：");
free(hex_sting);
cout("PE文件生成时间（link)：");
//acout(time_stamp_umber_of_sections);acout("\n");
//、*
//下面这一段对时间戳进行处理
////////////////////////////////////////////////////////////
static const time_t default_time = 1230728833;
static const char default_format[] = "%a %b %d %Y";


        time_t rawtime =(time_t)time_stamp_umber_of_sections;
	struct tm timeinfo;
	char timebuf[26];

	errno_t error;
	error = localtime_s( &timeinfo,&rawtime );
	if (error)
	{
		printf("Invalid argument to _localtime64_s.");
		return(1);
	}

	error = asctime_s (timebuf,26,&timeinfo);
	if (error)
	{
		printf("Invalid argument to asctime_s.");
		return(1);
	}

	printf( "%s \n", timebuf );
////////////////////////////////////////////////////////////
////然后再读取4bytes获取符号表的偏移量

strm.seekg (pe_header_offset+4+2+2+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(处理器)：");
free(hex_sting);
cout("符号表偏移量（symbol table)：");
//如果结果是0，那就是说明没有符号表
printf("0x%08x\n",time_stamp_umber_of_sections);


//然后再读取4个字节，获取符号的数量
strm.seekg (pe_header_offset+4+2+2+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
hex_sting = (char*)malloc(8+1);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(处理器)：");
free(hex_sting);
cout("符号数量（symbol number)：");printf("%d\n",time_stamp_umber_of_sections);

//再读取2bytes获取optional header的size
strm.seekg (pe_header_offset+4+2+2+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 2);
//翻转
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(4+1);memset(hex_sting,0,4+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
acout(hex_sting);acout("\n");
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(处理器)：");
free(hex_sting);
cout("optional header size：");printf("%d\n",time_stamp_umber_of_sections);

//再然后就是characteristic，就是一堆标志位  2bytes
//下面是完整的characteristic列表
/*
Flag    Value   Description
IMAGE_FILE_RELOCS_STRIPPED
0x0001
Image only, Windows CE, and Microsoft Windows NT and later. This indicates that the file does not contain base relocations and must therefore be loaded at its preferred base address. If the base address is not available, the loader reports an error. The default behavior of the linker is to strip base relocations from executable (EXE) files.
IMAGE_FILE_EXECUTABLE_IMAGE

0x0002
Image only. This indicates that the image file is valid and can be run. If this flag is not set, it indicates a linker error.
IMAGE_FILE_LINE_NUMS_STRIPPED
仅适用于

0x0004
COFF line numbers have been removed. This flag is deprecated and should be zero.
IMAGE_FILE_LOCAL_SYMS_STRIPPED

0x0008
COFF symbol table entries for local symbols have been removed. This flag is deprecated and should be zero.
IMAGE_FILE_AGGRESSIVE_WS_TRIM

0x0010
Obsolete. Aggressively trim working set. This flag is deprecated for Windows 2000 and later and must be zero.
IMAGE_FILE_LARGE_ADDRESS_ AWARE

0x0020
Application can handle > 2-GB addresses.

0x0040
This flag is reserved for future use.

IMAGE_FILE_BYTES_REVERSED_LO
0x0080
Little endian: the least significant bit (LSB) precedes the most significant bit (MSB) in memory. This flag is deprecated and should be zero.

IMAGE_FILE_32BIT_MACHINE
0x0100
Machine is based on a 32-bit-word architecture.
IMAGE_FILE_DEBUG_STRIPPED

0x0200
Debugging information is removed from the image file.
IMAGE_FILE_REMOVABLE_RUN_ FROM_SWAP
0x0400

If the image is on removable media, fully load it and copy it to the swap file.
IMAGE_FILE_NET_RUN_FROM_SWAP
0x0800
If the image is on network media, fully load it and copy it to the swap file.
IMAGE_FILE_SYSTEM
0x1000
The image file is a system file, not a user program.
IMAGE_FILE_DLL
0x2000
The image file is a dynamic-link library (DLL). Such files are considered executable files for almost all purposes, although they cannot be directly run.
IMAGE_FILE_UP_SYSTEM_ONLY
0x4000
The file should be run only on a uniprocessor machine.
IMAGE_FILE_BYTES_REVERSED_HI
0x8000
Big endian: the MSB precedes the LSB in memory. This flag is deprecated and should be zero.
*/

std::map<_ui, motherfucker_string> characteritics_flags_machine_type_my_map ;
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x2000,_TEXT("The image file is a dynamic-link library (DLL). Such files are considered executable files for almost all purposes, although they cannot be directly run.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x1000,_TEXT("The image file is a system file, not a user program.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0800,_TEXT("If the image is on network media, fully load it and copy it to the swap file.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0400,_TEXT("If the image is on removable media, fully load it and copy it to the swap file.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0200,_TEXT("Debugging information is removed from the image file.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0100,_TEXT("Machine is based on a 32-bit-word architecture.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0001,_TEXT("Image only, Windows CE, and Microsoft Windows NT and later. This indicates that the file does not contain base relocations and must therefore be loaded at its preferred base address. If the base address is not available, the loader reports an error. The default behavior of the linker is to strip base relocations from executable (EXE) files.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0002,_TEXT("cao草你妈吗Image only. This indicates that the image file is valid and can be run. If this flag is not set, it indicates a linker error.仅适用于镜像文件，这个标志位表明了该镜像文件是合法的，可以正常运行，如果这个标志位没有启用，则说明存在链接器错误")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0004,_TEXT("COFF line numbers have been removed. This flag is deprecated and should be zero.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0008,_TEXT("COFF symbol table entries for local symbols have been removed. This flag is deprecated and should be zero.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0010,_TEXT("Obsolete. Aggressively trim working set. This flag is deprecated for Windows 2000 and later and must be zero.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0020,_TEXT("Application can handle > 2-GB addresses.此程序能够处理>2GB的地址")));
//IMAGE_FILE_BYTES_REVERSED_LO
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0040,_TEXT("This flag is reserved for future use.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0080,_TEXT("Little endian: the least significant bit (LSB) precedes the most significant bit (MSB) in memory. This flag is deprecated and should be zero.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x8000,_TEXT("Big endian: the MSB precedes the LSB in memory. This flag is deprecated and should be zero.")));
characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x4000,_TEXT("The file should be run only on a uniprocessor machine.")));
strm.seekg (pe_header_offset+4+2+2+4+4+4+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//翻转
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(4+1);memset(hex_sting,0,4+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
acout(hex_sting);acout("\n");
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(处理器)：");
free(hex_sting);
cout("characteristic value：");printf("%d\n",time_stamp_umber_of_sections);
cout("下面输出启用了的标志位：\n");
std::map<_ui, motherfucker_string>::iterator iter;
    iter = characteritics_flags_machine_type_my_map.begin();
    while(iter != characteritics_flags_machine_type_my_map.end()) {
//            cout<<typeid(time_stamp_umber_of_sections&(iter->first)).name();
            _ui fuckyou=time_stamp_umber_of_sections&(iter->first);
//    printf("and op %u\n",fuckyou==0);
        if(fuckyou>0){
//            cout("进来了\n");
           acout("\t");pout(iter->second);acout("\n");
        }
        iter++;
    }

//    好了，这些都读取完毕后，就该读取optional header了

//前面我们已经获取到了optional header 的大小
//在读取完上面的coff header之后，optional header就是紧挨着的

//根据这个svg上的说明。optional header可以被分为三部分
//OptionalHeaderStd           std
//OptionalHeaderWindows           widnows
//OptionalHeaderDataDirs          datadirectory
//至于为什么会分成三部分，在官方文档https://docs.microsoft.com/en-us/windows/win32/debug/pe-format网页中
 //    ctrl+f搜索The optional header itself has three major parts.就会找到答案
//我们先来解析std部分
//两个字节的format
cout("\n？？？？？？？？？？？？？？？？？？？？？？？？？？？？？开始----OPTIONAL HEADER----开始？？？？？？？？？？？？？？？？？？？？？？？？？？？？？");acout("\n");
cout("==================================开始----STD部分----开始==================================");acout("\n");
//2bytes的format，在PEbear中format对应的是magic，这里我们和pebear保持一致  毕竟PEbear是个相对知名的工具
// 在官方文档中也是称作magic，而不是format
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//翻转
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(4+1);memset(hex_sting,0,4+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
acout(hex_sting);acout("\n");
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);//cout("machine type(处理器)：");
free(hex_sting);
//在微软官方文档中，magic的值一共就俩0x10b对应32bit  0x20b对应64bit
//这个值的优先级比machine type要高，如果两者出现矛盾，则以magic的值为准，不过正常情况下两者应该是一致的
cout("magic：");
_ui magic_numberrr = time_stamp_umber_of_sections;
if(time_stamp_umber_of_sections==0x10b)
    cout("PE32，也就是32位");
if(time_stamp_umber_of_sections==0x20b)
    cout("PE32+，也就是64位");
cout("\n");
//然后是major linker version和minor linker version
//不知道这两个东西有啥用
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//翻转
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(4+1);memset(hex_sting,0,4+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
time_stamp_umber_of_sections=(_ui)strtoul(_tmnp_string,NULL,16);
cout("链接器主版本号：");acout(time_stamp_umber_of_sections);acout("\n");
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
time_stamp_umber_of_sections=(_ui)strtoul(_tmnp_string,NULL,16);
cout("链接器次版本号：");acout(time_stamp_umber_of_sections);acout("\n");
free(hex_sting);

//然后是size_of_code，就是PE文件中代码的大小 4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(8+1);


sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("PE文件中.text扇区的大小：");
acout(time_stamp_umber_of_sections);acout(" bytes\n");

//size_of_initialized_data，其实就是.data扇区
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4);
memset(buffer,0,64);
FUCK("read return value %d\n",strm.read (buffer, 4));
strm.read (buffer, 4);
 int bytesRead = (int)strm.gcount();
FUCK("bytesRead %d\n",bytesRead);
FUCK("offset%x\n",pe_header_offset+4+2+2+4+4+4+2+2+2+2+4);
FUCK("buffer %s\n",buffer);
FUCK("buffer %d\n",buffer[3]);
FUCK("buffer %d\n",buffer[2]);
FUCK("buffer %d\n",buffer[1]);
FUCK("buffer %d\n",buffer[0]);
// qnmd;
time_stamp_umber_of_sections=_4_bytes_deal(buffer);

cout("PE文件中.data扇区的大小：");
acout(time_stamp_umber_of_sections);acout(" bytes\n");
qnmd;

//size_of_uninitialized_data，其实就是.bss扇区
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(8+1);


sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("PE文件中.bss扇区的大小：");
acout(time_stamp_umber_of_sections);acout(" bytes\n");

//然后是entrypoint   address_of_entry_point  4bytes
//这个是一个相对地址，就是相对于镜像文件加载到内存之后的image base的偏移量
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(8+1);


sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("entry point（RVA）地址：");
printf("0x%08x",time_stamp_umber_of_sections);acout("\n");

//然后是base_of_code，4bytes
// code扇区相对于镜像文件加载如内存后image base的RVA
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(8+1);


sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("base of code（RVA）地址：");
printf("0x%08x",time_stamp_umber_of_sections);acout("\n");

//如果magic的值是pe32，那么在base of code之后，还有一个base of data
//data扇区相对于image base的RVA
_ui seek_offset  = 0;
_ui image_bse_sizeof  = 8;
if(magic_numberrr==0x10b){
        seek_offset=4;
        image_bse_sizeof=4;
    strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);
hex_sting = (char*)malloc(8+1);


sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("base of data（RVA）地址：");
printf("0x%08x",time_stamp_umber_of_sections);acout("\n");
}
//到这里，std部分就算是结束了
cout("\n==================================结束----STD部分----结束==================================");acout("\n");



cout("\n==================================开始----windows部分----开始==================================");acout("\n");


////image base,这个是pe文件加载入内存的首选地址，默认是0x00400000
//但是由于ASLR机制的存在，这个地址大部分情况下都不会被应用，因为可能已经被别的程序给占了
//第一个地方就需要区分pe32和pe32+，pe32只占用4bytes，pe32+占用8bytes
//我们使用上面定义的image_bse_sizeof
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset);
memset(buffer,0,64);
strm.read (buffer, image_bse_sizeof);
//翻转
memset(_tmnp_string,0,3);


if(image_bse_sizeof==8) {
//        cout("你是64位对吧？\n");
       unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");

time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
// cout("低16bit");

free(hex_sting);
//printf("0x%x\n", time_stamp_umber_of_sections);
 hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[7]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[6]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[5]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[4]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections2=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("image base地址：");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//我知道为什么这里我的64bit的变量总是会丢弃一般的数据编程32bit了
//因为我们用的是32bit的编译器，需要修改一下build oiptions里面的pre step，环境变量脚本应该是、
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// 我的这个编译器可能就不支持64bit的整数，我放弃了，分开显示算了
printf("0x%x",time_stamp_umber_of_sections2);printf("%08x",time_stamp_umber_of_sections);acout("\n");
}else{

    hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("image base地址：");
printf("0x%08x",time_stamp_umber_of_sections);acout("\n");
}
//然后是section_alignment  4bytes
// 这个就是在加载入内存之后，给各个扇区对齐用的，一般情况下，他的值就是当前处理器架构的一个page的大小
//page是内存分页相关技术
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("section_alignment：");
printf("%u bytes", time_stamp_umber_of_sections);
cout("\n");

// 下面是file alignment，默认值是512  4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("file _alignment：");
printf("%u bytes", time_stamp_umber_of_sections);
cout("\n");

// 下面是操作系统主版本号 2bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4);
memset(buffer,0,64);
strm.read (buffer, 2);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("操作系统主版本号：");
printf("%u ", time_stamp_umber_of_sections);
cout("\n");


// 下面是操作系统次版本号 2bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("操作系统次版本号：");
printf("%u ", time_stamp_umber_of_sections);
cout("\n");

// 镜像文件朱版本号和次版本号
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("镜像文件主版本号：");printf("%u ", time_stamp_umber_of_sections);
cout("\n");
hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("镜像文件次版本号：");
printf("%u ", time_stamp_umber_of_sections);
cout("\n");


// 子系统的主版本号和次版本号
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("子系统主版本号：");printf("%u ", time_stamp_umber_of_sections);
cout("\n");
hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("子系统次版本号：");
printf("%u ", time_stamp_umber_of_sections);
cout("\n");

// 再往下
// win32_version_value  这个字段是保留的，因此我们直接掠过即可
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
 
// size_of_image  image加载入内存之后的大小，是filealignment的倍数  4bytes
// 这个是内存对齐之后的大小，是比实际的image文件要大的
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("镜像加载到内存之后的大小：");printf("%u bytes", time_stamp_umber_of_sections);
cout("\n");


// sizeofheader，所有的头部加起来然后向上取整到file alignment的倍数

strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("header总大小（向上取整filealignment）：");printf("%u bytes", time_stamp_umber_of_sections);
cout("\n");


// check_sum  镜像文件的校验和
// 该校验和的计算算法位于IMAGHELP.DLL.

strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("checksum：");printf("%u ", time_stamp_umber_of_sections);
cout("\n");

// 2bytes的子系统，gui、cli等
// 完成列表

std::map<_ui, motherfucker_string> characteritics_flags_machine_sub_ssytem_type_my_map ;
characteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(2,_TEXT("图形化子系统")));
characteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(3,_TEXT("字符（命令行）子系统")));
/*、*
Constant	Value	Description
IMAGE_SUBSYSTEM_UNKNOWN
0
An unknown subsystem
IMAGE_SUBSYSTEM_NATIVE
1
Device drivers and native Windows processes
IMAGE_SUBSYSTEM_WINDOWS_GUI
2
The Windows graphical user interface (GUI) subsystem
IMAGE_SUBSYSTEM_WINDOWS_CUI
3
The Windows character subsystem
IMAGE_SUBSYSTEM_OS2_CUI
5
The OS/2 character subsystem
IMAGE_SUBSYSTEM_POSIX_CUI
7
The Posix character subsystem
IMAGE_SUBSYSTEM_NATIVE_WINDOWS
8
Native Win9x driver
IMAGE_SUBSYSTEM_WINDOWS_CE_GUI
9
Windows CE
IMAGE_SUBSYSTEM_EFI_APPLICATION
10
An Extensible Firmware Interface (EFI) application
IMAGE_SUBSYSTEM_EFI_BOOT_ SERVICE_DRIVER
11
An EFI driver with boot services
IMAGE_SUBSYSTEM_EFI_RUNTIME_ DRIVER
12
An EFI driver with run-time services
IMAGE_SUBSYSTEM_EFI_ROM
13
An EFI ROM image
IMAGE_SUBSYSTEM_XBOX
14
XBOX
IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION
16
Windows boot application.
*、/*/
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4);
memset(buffer,0,64);
strm.read (buffer, 2);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);

sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("子系统：");cout("\n");
    iter = characteritics_flags_machine_sub_ssytem_type_my_map.begin();
    while(iter != characteritics_flags_machine_sub_ssytem_type_my_map.end()) {
//            cout<<typeid(time_stamp_umber_of_sections&(iter->first)).name();
            _ui fuckyou=time_stamp_umber_of_sections==iter->first;
//    printf("and op %u\n",fuckyou==0);
        if(fuckyou>0){
//            cout("进来了\n");
           acout("\t");pout(iter->second);acout("\n");
        }
        iter++;
    }

// dll_characteristics
// 也是一堆flag
// 完整列表如下
std::map<_ui, motherfucker_string> dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map ;
dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0040,_TEXT("DLL can be relocated at load time.DLL在加载的时候可以被重新定位")));
dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x0100,_TEXT("Image is NX compatible。 NX意为no-execute是一种内存保护措施")));
dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x4000,_TEXT("Image supports Control Flow Guard.。 简称CFG，可以在cl编译选择中指定，用于抵抗内存损坏漏洞")));
dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x8000,_TEXT("Terminal Server aware.我不知道这个到底是什么意思")));
/*
Constant	Value	Description
0x0001
Reserved, must be zero.
0x0002
Reserved, must be zero.
0x0004
Reserved, must be zero.
0x0008
Reserved, must be zero.
IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA
0x0020
Image can handle a high entropy 64-bit virtual address space.
IMAGE_DLLCHARACTERISTICS_
DYNAMIC_BASE
0x0040
DLL can be relocated at load time.
IMAGE_DLLCHARACTERISTICS_
FORCE_INTEGRITY
0x0080
Code Integrity checks are enforced.
IMAGE_DLLCHARACTERISTICS_
NX_COMPAT
0x0100
Image is NX compatible.
IMAGE_DLLCHARACTERISTICS_ NO_ISOLATION
0x0200
Isolation aware, but do not isolate the image.
IMAGE_DLLCHARACTERISTICS_ NO_SEH
0x0400
Does not use structured exception (SE) handling. No SE handler may be called in this image.
IMAGE_DLLCHARACTERISTICS_ NO_BIND
0x0800
Do not bind the image.
IMAGE_DLLCHARACTERISTICS_APPCONTAINER
0x1000
Image must execute in an AppContainer.
IMAGE_DLLCHARACTERISTICS_ WDM_DRIVER
0x2000
A WDM driver.
IMAGE_DLLCHARACTERISTICS_GUARD_CF
0x4000
Image supports Control Flow Guard.
IMAGE_DLLCHARACTERISTICS_ TERMINAL_SERVER_AWARE
0x8000
Terminal Server aware.
*/
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2);
memset(buffer,0,64);
strm.read (buffer, 2);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
      
           hex_sting = (char*)malloc(8+1);

sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("dll chacacteristic：");cout("\n");
    iter = dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.begin();
    while(iter != dll_characteristicscharacteritics_flags_machine_sub_ssytem_type_my_map.end()) {
//            cout<<typeid(time_stamp_umber_of_sections&(iter->first)).name();
            _ui fuckyou=time_stamp_umber_of_sections&(iter->first);
//    printf("and op %u\n",fuckyou==0);
        if(fuckyou>0){
//            cout("进来了\n");
           acout("\t");pout(iter->second);acout("\n");
        }
        iter++;
    }


// size_of_stack_reserve_32
// 我在这个地方找打了https://stackoverflow.com/questions/1858053/when-does-the-stack-really-overflow
// 这个回答对size_of_stack_reserve_32和SizeOfStackCommit的解释还是比较透彻的
// 这两个都是用来限制栈内存的，但是前者限制的是虚拟内存，后者限制的是物理内存
// 当你使用的栈空间大于物理内存时，就会开始使用虚拟内存，即磁盘（页交换）
//这两个字段有pe32和pe32+的区别，前者占用4bytes，后者占用8bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2);
memset(buffer,0,64);
strm.read (buffer, image_bse_sizeof);
//翻转
memset(_tmnp_string,0,3);


if(image_bse_sizeof==8) {
//        cout("你是64位对吧？\n");
       unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");

time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
// cout("低16bit");

free(hex_sting);
//printf("0x%x\n", time_stamp_umber_of_sections);
 hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[7]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[6]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[5]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[4]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections2=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("size_of_stack_reserve_64：");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//我知道为什么这里我的64bit的变量总是会丢弃一般的数据编程32bit了
//因为我们用的是32bit的编译器，需要修改一下build oiptions里面的pre step，环境变量脚本应该是、
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// 我的这个编译器可能就不支持64bit的整数，我放弃了，分开显示算了
printf("0x%x",time_stamp_umber_of_sections2);printf("%08x bytes",time_stamp_umber_of_sections);acout("\n");
}else{

    hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("size_of_stack_reserve_32：");
printf("0x%08x bytes",time_stamp_umber_of_sections);acout("\n");
}
// commit size
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof);
memset(buffer,0,64);
strm.read (buffer, image_bse_sizeof);
//翻转
memset(_tmnp_string,0,3);


if(image_bse_sizeof==8) {
//        cout("你是64位对吧？\n");
       unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");

time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
// cout("低16bit");

free(hex_sting);
//printf("0x%x\n", time_stamp_umber_of_sections);
 hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[7]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[6]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[5]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[4]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections2=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("size_of_stack_commit_64：");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//我知道为什么这里我的64bit的变量总是会丢弃一般的数据编程32bit了
//因为我们用的是32bit的编译器，需要修改一下build oiptions里面的pre step，环境变量脚本应该是、
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// 我的这个编译器可能就不支持64bit的整数，我放弃了，分开显示算了
printf("0x%x",time_stamp_umber_of_sections2);printf("%08x bytes",time_stamp_umber_of_sections);acout("\n");
}else{

    hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("size_of_stack_commit_32：");
printf("0x%08x bytes",time_stamp_umber_of_sections);acout("\n");
}

// 下面是sizeofheaporeserver和commit，和上面的stack概念一样
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof);
memset(buffer,0,64);
strm.read (buffer, image_bse_sizeof);
//翻转
memset(_tmnp_string,0,3);


if(image_bse_sizeof==8) {
//        cout("你是64位对吧？\n");
       unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");

time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
// cout("低16bit");

free(hex_sting);
//printf("0x%x\n", time_stamp_umber_of_sections);
 hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[7]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[6]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[5]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[4]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections2=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("size_of_heap_reserve_64：");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//我知道为什么这里我的64bit的变量总是会丢弃一般的数据编程32bit了
//因为我们用的是32bit的编译器，需要修改一下build oiptions里面的pre step，环境变量脚本应该是、
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// 我的这个编译器可能就不支持64bit的整数，我放弃了，分开显示算了
printf("0x%x",time_stamp_umber_of_sections2);printf("%08x bytes",time_stamp_umber_of_sections);acout("\n");
}else{

    hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("size_of_heap_reserve_32：");
printf("0x%08x bytes",time_stamp_umber_of_sections);acout("\n");
}
// commit
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof);
memset(buffer,0,64);
strm.read (buffer, image_bse_sizeof);
//翻转
memset(_tmnp_string,0,3);


if(image_bse_sizeof==8) {
//        cout("你是64位对吧？\n");
       unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");

time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
// cout("低16bit");

free(hex_sting);
//printf("0x%x\n", time_stamp_umber_of_sections);
 hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[7]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[6]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[5]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[4]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections2=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("size_of_heap_commit_64：");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//我知道为什么这里我的64bit的变量总是会丢弃一般的数据编程32bit了
//因为我们用的是32bit的编译器，需要修改一下build oiptions里面的pre step，环境变量脚本应该是、
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// 我的这个编译器可能就不支持64bit的整数，我放弃了，分开显示算了
printf("0x%x",time_stamp_umber_of_sections2);printf("%08x bytes",time_stamp_umber_of_sections);acout("\n");
}else{

    hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
time_stamp_umber_of_sections=(_ui)strtoul(hex_sting,NULL,16);
free(hex_sting);
cout("size_of_heap_commit_32：");
printf("0x%08x bytes",time_stamp_umber_of_sections);acout("\n");
}
// 再往下，是4bytes的loader flag，保留字段，直接略过
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof);

// 最后是number_of_rva_and_sizes
//  data-directory 的数量 4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4);
memset(buffer,0,64);
strm.read (buffer, 4);
//翻转
memset(_tmnp_string,0,3);



//        cout("你是64位对吧？\n");
    //    unsigned __int64 time_stamp_umber_of_sections2=0;
           hex_sting = (char*)malloc(8+1);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
strcpy(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
strcat(hex_sting, _tmnp_string);
sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
strcat(hex_sting, _tmnp_string);
//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");


//cout("16进制字符串");
//pout(hex_sting);
//cout("\n");
time_stamp_umber_of_sections=(_ul long)strtoul(hex_sting,NULL,16);
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=18446744073709551615;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//printf("%dll\n\n",sizeof(time_stamp_umber_of_sections2));
free(hex_sting);

//time_stamp_umber_of_sections2=time_stamp_umber_of_sections2<<32;
//printf("%ull\n\n",time_stamp_umber_of_sections2);
//time_stamp_umber_of_sections2=(unsigned __int64);
cout("data directory数量：");
//std::cout<<sizeof(_strtoui64(hex_sting,NULL,16))<<std::endl;
//我知道为什么这里我的64bit的变量总是会丢弃一般的数据编程32bit了
//因为我们用的是32bit的编译器，需要修改一下build oiptions里面的pre step，环境变量脚本应该是、
//C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin\amd64\vcvars64.bat
// 我的这个编译器可能就不支持64bit的整数，我放弃了，分开显示算了
printf("%u",time_stamp_umber_of_sections);acout("\n");


cout("\n==================================结束----windows部分----结束==================================");acout("\n");

cout("\n==================================开始----data directory部分----开始==================================");acout("\n");
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4);

// 我们需要连续读取15个8字节数据，每一个8字节数据都是一个data directory，包含了一个地址和size

char buffer2[15*8] = {0};
memset(buffer2,0,15*8);
strm.read (buffer2, 15*8);
//翻转
memset(_tmnp_string,0,3);

std::map<_ui, motherfucker_string> data_directory_characteritics_flags_machine_type_my_map ;
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0,_TEXT("export_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(1,_TEXT("import_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(2,_TEXT("resource_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(3,_TEXT("exception_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(4,_TEXT("certificate_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(5,_TEXT("base_relocation_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(6,_TEXT("debug")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(7,_TEXT("architecture")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(8,_TEXT("global_ptr")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(9,_TEXT("tls_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(10,_TEXT("load_config_table")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(11,_TEXT("bound_import")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(12,_TEXT("iat")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(13,_TEXT("delay_import_descriptor")));
data_directory_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(14,_TEXT("clr_runtime_header")));





for(int i=0;i<15;i++){
    pout(data_directory_characteritics_flags_machine_type_my_map[i]);
    hex_sting = (char*)malloc(8+1);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+3]);
    strcpy(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+2]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+1]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+0]);
    strcat(hex_sting, _tmnp_string);
    time_stamp_umber_of_sections=(_ul long)strtoul(hex_sting,NULL,16);
    free(hex_sting);
    cout("：\n\t");
    cout("地址（RVA）：");
    printf("\t0x%08x\n",time_stamp_umber_of_sections);
    data_directory.addr = time_stamp_umber_of_sections;
    hex_sting = (char*)malloc(8+1);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+7]);
    strcpy(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+6]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+5]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer2[i*8+4]);
    strcat(hex_sting, _tmnp_string);
    time_stamp_umber_of_sections=(_ul long)strtoul(hex_sting,NULL,16);
    free(hex_sting);
    data_directory.size = time_stamp_umber_of_sections;
    cout("\t");
    cout("size：");
    printf("\t\t%u bytes\n\n",time_stamp_umber_of_sections);
    data_directory_map.insert(std::pair<motherfucker_string, struct DATA_DIRECTORY_STRUCT>(data_directory_characteritics_flags_machine_type_my_map[i], data_directory));
}

FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);

cout("\n==================================结束----data directory部分----结束==================================");acout("\n");
cout("\n？？？？？？？？？？？？？？？？？？？？？？？？？？？？？结束----OPTIONAL HEADER----结束？？？？？？？？？？？？？？？？？？？？？？？？？？？？？");acout("\n");

// 接下来是seciton 部分
cout("\n￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥开始----SECTION HEADERs----开始￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥");acout("\n");
// 由于存在file alignment，即文件对齐，在开始处理下一部分的时候的，需要检查此时的偏移量是否是file alignment的倍数
// 当前的偏移量是pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8



// section的parse可以通过循环来完成
// 先来8bytres的name
// 注意跳过optional header中datadirectory 的最后一个8bytes保留位
_ui section_offset_counter = 0;
p_section_header = (struct SECTION_HEADER_STRUCT*)malloc(number_of_sections);
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
while(number_of_sections>(section_offset_counter/40)){
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 8);
char _tmnp_string2[1+1]={0};
hex_sting = (char*)malloc(8+1);
char* for_dword_string = (char*)malloc(8+1);
sprintf(_tmnp_string2,"%c",buffer[0]);
strcpy(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[0]);
strcpy(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[1]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[1]);
strcat(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[2]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[2]);
strcat(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[3]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[3]);
strcat(for_dword_string, _tmnp_string);
p_section_header[section_offset_counter/40].name_high=(DWORD)strtoul(for_dword_string,NULL,16);
free(for_dword_string);
for_dword_string = (char*)malloc(8+1);
sprintf(_tmnp_string2,"%c",buffer[4]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[4]);
strcpy(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[5]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[5]);
strcat(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[6]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[6]);
strcat(for_dword_string, _tmnp_string);
sprintf(_tmnp_string2,"%c",buffer[7]);
strcat(hex_sting, _tmnp_string2);
sprintf(_tmnp_string,"%02x",buffer[7]);
strcat(for_dword_string, _tmnp_string);
p_section_header[section_offset_counter/40].name_low=(DWORD)strtoul(for_dword_string,NULL,16);
free(for_dword_string);
cout("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n扇区(section)m名称：");
pout(hex_sting);cout("\n");
free(hex_sting);

// virtual_size  4bytes
// 在虚拟内存中的大小，同样是因为存在内存对齐，导致raw size和进入内存之后的size存在差异
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);

time_stamp_umber_of_sections = _4_bytes_deal(buffer);

p_section_header[section_offset_counter/40].virtual_size = time_stamp_umber_of_sections;
cout("virtual size：");
printf("%u bytes\n", time_stamp_umber_of_sections);

// virtual_address  RVA   4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].virtual_address = time_stamp_umber_of_sections;
cout("virtual_address（RVA）：");
printf("0x%08x\n", time_stamp_umber_of_sections);

// size_of_raw_data  4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);
time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].size_of_raw_data = time_stamp_umber_of_sections;
cout("size_of_raw_data：");
printf("%u bytes\n", time_stamp_umber_of_sections);

// pointer_to_raw_data  4bytes
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);
time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].pointer_to_raw_data = time_stamp_umber_of_sections;
cout("pointer_to_raw_data（在PE文件中的地址）：");
printf("0x%08x\n", time_stamp_umber_of_sections);

// pointer_to_relocations  4bytes
// 这个字段对于可执行文件没有意义，所以为0，但是对于dll等文件是有意义的，我们这里就老老实实获它的值就行了
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);



time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].pointer_to_relocations = time_stamp_umber_of_sections;
cout("pointer_to_relocations：");
printf("0x%08x\n", time_stamp_umber_of_sections);

// pointer_to_relocations  4bytes
// 这个字段对于可执行文件没有意义，所以为0，但是对于dll等文件是有意义的，我们这里就老老实实获它的值就行了
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+4+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);
time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].pointer_to_linenumbers = time_stamp_umber_of_sections;
cout("pointer_to_linenumbers：");
printf("0x%08x\n", time_stamp_umber_of_sections);

FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
// number_of_relocations
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+4+4+4+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 2);
time_stamp_umber_of_sections = _2_bytes_deal(buffer);
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
p_section_header[section_offset_counter/40].number_of_relocations = (WORD)time_stamp_umber_of_sections;
// 可能是发生了栈溢出，尝试把变量放在堆中
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
cout("number_of_relocations：");
printf("0x%08x\n", time_stamp_umber_of_sections);
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
// number_of_linenumbers
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+4+4+4+2+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 2);
time_stamp_umber_of_sections = _2_bytes_deal(buffer);
p_section_header[section_offset_counter/40].number_of_linenumbers = (WORD)time_stamp_umber_of_sections;
cout("number_of_linenumbers：");
printf("0x%08x\n", time_stamp_umber_of_sections);
// characteristics  又是一堆flag
strm.seekg (pe_header_offset+4+2+2+4+4+4+2+2+2+2+4+4+4+4+4+seek_offset+image_bse_sizeof+4+4+2+2+4+4+4+4+4+4+2+2+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+image_bse_sizeof+4+4+15*8+8+8+4+4+4+4+4+4+2+2+section_offset_counter);
memset(buffer,0,64);
strm.read(buffer, 4);
time_stamp_umber_of_sections = _4_bytes_deal(buffer);
p_section_header[section_offset_counter/40].flag = time_stamp_umber_of_sections;
std::map<_ui, motherfucker_string> section_characteritics_flags_machine_type_my_map ;
// 完整列表参考微软官方文档https://docs.microsoft.com/en-us/windows/win32/debug/pe-format#section-flags
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000000,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000001,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000002,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000004,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000008,_TEXT("The section should not be padded to the next boundary. This flag is obsolete and is replaced by This is valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000010,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000020,_TEXT("The section contains executable code.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000040,_TEXT("The section contains initialized data.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000080,_TEXT("The section contains uninitialized data.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000100,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000200,_TEXT("The section contains comments or other information. The .drectve section has this type. This is valid for object files only.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000400,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00000800,_TEXT("The section will not become part of the image. This is valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00001000,_TEXT("The section contains COMDAT data. For more information, see [COMDAT Sections (Object Only)](https://docs.microsoft.com/en-us/windows/win32/debug/pe-format#comdat-sections-object-only). This is valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00008000,_TEXT("The section contains data referenced through the global pointer (GP).")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00020000,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00020000,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00040000,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00080000,_TEXT("Reserved for future use.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00100000,_TEXT("Align data on a 1-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00200000,_TEXT("Align data on a 2-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00300000,_TEXT("Align data on a 4-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00400000,_TEXT("Align data on an 8-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00500000,_TEXT("Align data on a 16-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00600000,_TEXT("Align data on a 32-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00700000,_TEXT("Align data on a 64-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00800000,_TEXT("Align data on a 128-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00900000,_TEXT("Align data on a 256-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00A00000,_TEXT("Align data on a 512-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00B00000,_TEXT("Align data on a 1024-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00C00000,_TEXT("Align data on a 2048-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00D00000,_TEXT("Align data on a 4096-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x00E00000,_TEXT("Align data on an 8192-byte boundary. Valid only for object files.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x01000000,_TEXT("The section contains extended relocations.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x02000000,_TEXT("The section can be discarded as needed.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x04000000,_TEXT("The section cannot be cached.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x08000000,_TEXT("The section is not pageable.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x10000000,_TEXT("The section can be shared in memory.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x20000000,_TEXT("The section can be executed as code.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x40000000,_TEXT("The section can be read.")));
section_characteritics_flags_machine_type_my_map.insert(std::pair<_ui,motherfucker_string>(0x80000000,_TEXT("The section can be written to.")));
cout("扇区（section）characteristic flag：\n\t");
flag_display(section_characteritics_flags_machine_type_my_map,time_stamp_umber_of_sections);
section_offset_counter+=40;acout("\n");
FUCK("0x%x\n",data_directory_map[_TEXT("import_table")].addr);
}
cout("\n￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥结束----SECTION HEADERs----结束￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥￥");acout("\n");

// 最后，我们需要对其中的一部分data directory进行解析
// 首先是import directory
// 其格式如下：https://docs.microsoft.com/en-us/windows/win32/debug/pe-format#the-idata-section
// 之前我们也已经讲过了，rva和raw addr的转换规则
// 需要section jheader中的一些数据来帮助我们进行判断

// 先获取到import directory的偏移量
_ui raw_offset = 0;
FUCK("import table RVA: 0x%0x\n",data_directory_map[_TEXT("import_table")].addr);
for(int i=0;i<number_of_sections;i++) {
    FUCK("section virtual address : 0x%0x\n",p_section_header[i].virtual_address);
    FUCK("section raw file pointer: 0x%0x\n",p_section_header[i].pointer_to_raw_data);
    _ui fuckyou = p_section_header[i].virtual_address + p_section_header[i].virtual_size;
    FUCK("fuckyou: 0x%x\n",fuckyou);
    if(fuckyou >= data_directory_map[_TEXT("import_table")].addr) {
        raw_offset =    data_directory_map[_TEXT("import_table")].addr- p_section_header[i].virtual_address+p_section_header[i].pointer_to_raw_data;break;
    }
}
FUCK("raw offset disk addr 0x%08x", raw_offset);
// 现在我们只需要使用seek就能定位到文件中import table的位置
cout("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@开始----解析data directory----开始@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");acout("\n");



// 其实import table也是拥有多个项的，需要循环读取，结束标志就是你读取出来的20个字节全为空
// 但是我不想写了，因为一开始写这个的时候就咩有好好规划，现在写到两千多行，再想重构就比要麻烦了
// 重要的是能够理解相関概念就行了
_ui _boss_break_flag=0;
_ui _boss_up_value = raw_offset;
while(1){
    strm.seekg (raw_offset);
memset(buffer,0,64);
strm.read(buffer, 20);

  for(int i=0;i<20;i++) {
            _boss_break_flag = 0;
            unsigned char _asd = 0;
            _asd = (unsigned char)buffer[i];
            if(_asd > 0) {break;}
            if(i+2>20) _boss_break_flag = 1;
        }
        if(_boss_break_flag>0) break;
strm.seekg (raw_offset);
memset(buffer,0,64);
strm.read(buffer, 4);
cout("--------------------------import table");

// Import Lookup Table RVA 4bytes
// 这个字段存储的是lookp uptable的rva
time_stamp_umber_of_sections= _4_bytes_deal(buffer);
_ui _ila_rva = time_stamp_umber_of_sections;
cout("\n\tImport Lookup Table RVA：");
printf("0x%x\n",time_stamp_umber_of_sections);
// 4bytes 时间戳
strm.seekg (raw_offset+4);
memset(buffer,0,64);
strm.read(buffer, 4);


time_stamp_umber_of_sections= _4_bytes_deal(buffer);
cout("\t时间戳：");
int _is_bound = time_stamp_umber_of_sections;
printf("0x%x\n",time_stamp_umber_of_sections);

// forward chain。这个我还暂时不了解是个什么东西
strm.seekg (raw_offset+4+4);
memset(buffer,0,64);
strm.read(buffer, 4);


time_stamp_umber_of_sections= _4_bytes_deal(buffer);
cout("\tforward chain：");
printf("0x%x\n",time_stamp_umber_of_sections);


// Name RVA
strm.seekg (raw_offset+4+4+4);
memset(buffer,0,64);
strm.read(buffer, 4);


time_stamp_umber_of_sections= _4_bytes_deal(buffer);
cout("\tDLL name address(RVA)：");
printf("0x%x\n",time_stamp_umber_of_sections);
// 通过name addr rva获取到dll的用户名
// 通过rva获取file pointer的方式和上面的一样，那我就把这一部分代码重写城函数把
// 算了，懒得写了，直接写在这里算了
// 栈好像溢出了，因为我把所有东西都写在main函数里了，感觉要爆炸了都
// 一点东西都输不出来了
_ui name_raw_offset;
for(int i=0;i<number_of_sections;i++) {
    FUCK("section virtual address : 0x%0x\n",p_section_header[i].virtual_address);
    FUCK("section raw file pointer: 0x%0x\n",p_section_header[i].pointer_to_raw_data);
    _ui fuckyou = p_section_header[i].virtual_address + p_section_header[i].virtual_size;
    FUCK("fuckyou: 0x%x\n",fuckyou);
    if(fuckyou >= time_stamp_umber_of_sections) {
        cout("小伙子你怎么回事？\n");
        cout("小伙子你怎么回事？\n");
        FUCK("0x%x\n",time_stamp_umber_of_sections);
        cout("小伙子你怎么回事？\n");
         FUCK("0x%x\n",p_section_header[i].virtual_address);
        FUCK("%x\n",(_ui)p_section_header[i].virtual_address);
        FUCK("%x\n", p_section_header[i].pointer_to_raw_data);
     name_raw_offset =   time_stamp_umber_of_sections - p_section_header[i].virtual_address+p_section_header[i].pointer_to_raw_data;
        break;
    }
}
        FUCK("name_raw_offset  %x\n", name_raw_offset);
         FUCK("name_raw_offset  %x\n", name_raw_offset);
// dll名字，反正我是没见过用unicode，所以我这里直接当做ascii进行解析
hex_sting =(char*)malloc(4096);
memset(hex_sting,0,4096);

  FUCK("name_raw_offset  %x\n", name_raw_offset);
for(int i=0;;i++){
    memset(buffer,0,64);
    strm.seekg (name_raw_offset+i);
    strm.read(buffer, 1);
    FUCK("%u\n",(unsigned char)buffer[0]);
    strcat(hex_sting,buffer);
    if(strlen(buffer)==0)break;
   
}

cout("DLL的名字是：");
pout(hex_sting);cout("\n");
free(hex_sting);


// Import Address Table RVA (Thunk Table)
strm.seekg (raw_offset+4+4+4+4);
memset(buffer,0,64);
strm.read(buffer, 4);


time_stamp_umber_of_sections= _4_bytes_deal(buffer);
cout("\tImport Address Table RVA：");
printf("0x%x\n",time_stamp_umber_of_sections);

// Import Lookup Table RVA和Import Address Table RVA：指向的结构是一样的
// 只有当file是bound的时候，才会不一样，我不知道这个bound是啥意思
// 我猜这个bound可能值的是静态编译？就是把DLL和可执行文件弄到一起了，而不是在加载的时候再讲DLL的函数地址填充到IAT中
// 在不bound的情况下，ILT和IAT的内容是一样的
// 我现在也搞不清楚bound是啥意思了，因为我自己这个测试PE就是静态编译的
// 我在编译的时候使用了/MT，就是静态编译，但是PE-bear解析依然显示unbound
// 我们可以通过时间戳来判断是否是bound的
// 根据官方文档：The stamp that is set to zero until the image is bound.
// 因此如果时间戳是0，那么就说明这个PE文件是unbound的
_ila_rva = convert_rva_to_file_pointer(_ila_rva, p_section_header, number_of_sections);
if(_is_bound>0) {
    // 是bound，先不管
} else {
    
    cout("没有绑定\n");
    int _break_flag=0;
    _ui _up_value = 0;
    while(1) {
        // cout("发生神魔是了？");
         
        FUCK("_ila_rva 0x%x\n", _ila_rva);
        // 因为这是一个表，所以我们要一直不停地读，直到读取出来的image_bse_sizeof全都是空
        // unbound
        // 直接看ILT（import loookup table）即可
        // 存在PE32和PE32+的区别，前者为32bit，后者为64bit
        // 通过image_bse_sizeof我们可以确定他是pe32还是pe32+
        _ui _hint_name_table_rva;
        _ui _ordinal;
        FUCK("_ila_rva 0x%x\n", _ila_rva);
        
        strm.seekg (_ila_rva+_up_value);
        memset(buffer,0,64);
        // PE32+占用64bit，即8bytes
        strm.read(buffer, image_bse_sizeof);
        _up_value+=image_bse_sizeof;
        for(int i=0;i<image_bse_sizeof;i++) {
            _break_flag = 0;
            unsigned char _asd = 0;
            _asd = (unsigned char)buffer[i];
            if(_asd > 0) {break;}
            if(i+2>image_bse_sizeof) _break_flag = 1;
        }
        if(_break_flag>0) break;
        // Ordinal Number，这个字段只有在Ordinal/Name标志位启用的时候才会有意义
        // 因此我们需要先查看最后一个bit位，因为最后一个bit位决定了Ordinal/Name标志位是否启用
        _ui _temp_fucking_value;
        if(image_bse_sizeof>4)
            _temp_fucking_value = (_ui)buffer[7];
        else
            _temp_fucking_value = (_ui)buffer[3];
        if(_temp_fucking_value>0) {
            // 启用ordinal
            hex_sting = (char*)malloc(4+1);memset(hex_sting,0,4+1);
            sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
            strcpy(hex_sting, _tmnp_string);
            sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
            strcat(hex_sting, _tmnp_string);
            FUCK("hex_sting: %s",hex_sting);
            free(hex_sting);
            _ordinal = (_ui)strtoul(hex_sting,NULL,16);
        } else {
            _hint_name_table_rva = _4_bytes_deal(buffer);
        
            cout("HINT/NAME table RVA：");
            printf("\n\t0x%x\n", _hint_name_table_rva);
            // 将RVA转换成disk file pointer

            _hint_name_table_rva = convert_rva_to_file_pointer(_hint_name_table_rva, p_section_header, number_of_sections);
            
            // 然年根据_hint_name_table_rva来读取HINT/NAME Table
            strm.seekg (_hint_name_table_rva);
            memset(buffer,0,64);
            // 2bytes的hint，我暂时还不清楚这个hint有啥用
            strm.read(buffer, 2);
          // 、、 _up_value+=2;
            _ui _hint = _2_bytes_deal(buffer);
            cout("HINT：");
            printf("0x%x\n", _hint);
            
            // 然后后面是要导入的函数的名称，ascii字符串，以NULL结尾，所以就一直读取就完事了
            char function_name[4086]={0};
            _read_ascii(_hint_name_table_rva+2, &strm, function_name);
            // _up_value=_up_value+strlen(function_name)+1;
            cout("函数名：");
            printf("\t%s\n", function_name);
        }
    }

}raw_offset+=20;
}
// raw_offset = _boss_up_value;


// 再解析一个data directory  base reloc
// 对应.reloc   之前的import table对应.idata
//return 0;
//stdout.close();
fclose(stdout);
cout("--------------------------base relocation table\n");
exit( 0);
// 这个结构跟上面的import table差不多，也是套娃结构，只不过没有结束标志，是通过size来判断是否结束
// 首先需要获取reloca trable的rva和size，这个可以直接使用我们的data_directory_map获取
 data_directory_map[_TEXT("base_relocation_table")].addr;
 data_directory_map[_TEXT("base_relocation_table")].size;

//  通过RVA计算file pointer
_ui _file_pointer_to_relocation_table = convert_rva_to_file_pointer(data_directory_map[_TEXT("base_relocation_table")].addr, p_section_header, number_of_sections);

// 下面这个太浪费时间了，感觉也没啥用，先注释掉
//
_boss_up_value=_file_pointer_to_relocation_table;
while(1){
    _ui _temp_fuck_value = _file_pointer_to_relocation_table-_boss_up_value;
    if(_temp_fuck_value>= data_directory_map[_TEXT("base_relocation_table")].size) break;
    strm.seekg (_file_pointer_to_relocation_table);
    memset(buffer,0,64);
    // 读取page rva
    strm.read(buffer, 4);
    time_stamp_umber_of_sections = _4_bytes_deal(buffer);
    cout("\npage RVA：");
    printf("\t0x%x\n", time_stamp_umber_of_sections);
    acout("\n");
    strm.seekg (_file_pointer_to_relocation_table+4);
    memset(buffer,0,64);
    // 读取block size
    strm.read(buffer, 4);
    time_stamp_umber_of_sections = _4_bytes_deal(buffer);
    cout("size：");
    _ui __block_size = time_stamp_umber_of_sections;
    printf("\t0x%x\n++++++++++++++++++++++++++++++++++", time_stamp_umber_of_sections);
    acout("\n");
    _ui _up_value = 0;
    while((_up_value)<(__block_size-8)) {
        strm.seekg (_file_pointer_to_relocation_table+4+4+_up_value);
        memset(buffer,0,64);
        // 读取block size
        strm.read(buffer, 2);
        unsigned short _fuck_you = _2_bytes_deal(buffer);
        // 获取最高4bit
        _ui _high_4_bit = (_ui)(_fuck_you >> 12);
        cout("base relocation 类型：");
        printf("\t0x%x\n", _high_4_bit);
        _ui _offset_value = _fuck_you & 0xFFF;
        cout("偏移量：");
        printf("\t0x%x\n", _offset_value);
        _up_value+=2;
    }
    _file_pointer_to_relocation_table+=__block_size;
}
cout("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@结束----解析data directory----结束@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");



return 0;


}

////???????????
//#include <Windows.h>
//#include <iostream>
//#include <io.h>
//#include <fcntl.h>
//#include <locale.h>
//#include <wincon.h>
//
//int wmain(int argc, wchar_t* argv[])
//{
//char* hex_sting= "82E1734B";
//signed int number_of_sections=(signed int)strtoul(hex_sting,NULL,16);
//printf("%d\n",number_of_sections);
//    return 0;
//}

/*
_ui _4_bytes_deal(char* buffer) {
    char  _tmnp_string[2+1]={0};
    char hex_sting[8+1] = {0};
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[3]);
    strcpy(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[2]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[1]);
    strcat(hex_sting, _tmnp_string);
    sprintf(_tmnp_string,"%02x",(unsigned char)buffer[0]);
    strcat(hex_sting, _tmnp_string);
    FUCK("hex_sting: %s",hex_sting);
    return (_ui)strtoul(hex_sting,NULL,16);
*/
