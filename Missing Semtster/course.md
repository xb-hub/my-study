1. < > << >> 输入输出重定向
- < > : 覆盖
- 2>重定向标准错误流
```
// 从右往左执行命令
(base) ➜  Missing Semtster git:(master) ✗ cat <(ls) <(ls ..)  
course.md
mcd.sh
test
algorithms
C++
CMake
csapp
Make
Missing Semtster
MySQL
README.md
Redis
Socket
Unix
操作系统
计算机网络
设计模式
```
- << >>: 添加

2. | 管道
- 取左侧程序输出当作右侧程序输入。
- tail：打印出它输入的最后n行

3. 通配符

# shell
- $? : 获取上条命令的错误代码（返回值）
```
(base) ➜  test git:(master) ✗ echo "hello"                  
hello
(base) ➜  test git:(master) ✗ echo $?     
0   // 正确返回
(base) ➜  Missing Semtster git:(master) ✗ grep foobar mcd.sh
(base) ➜  Missing Semtster git:(master) ✗ echo $?
1   // 错误返回
```
- $_ : 获取上条命令的最后一个参数
```
(base) ➜  Missing Semtster git:(master) ✗ rmdir test  
(base) ➜  Missing Semtster git:(master) ✗ mkdir test             
(base) ➜  Missing Semtster git:(master) ✗ cd $_
```
- !! : 替换成上一条命令
```
(base) ➜  Missing Semtster git:(master) ✗ cd $_
(base) ➜  test git:(master) ✗ sudo !!                    
(base) ➜  test git:(master) ✗ sudo cd $_
```
- && || : 与c++类似
```
(base) ➜  Missing Semtster git:(master) ✗ true || echo "hello"
(base) ➜  Missing Semtster git:(master) ✗ false || echo "hello"
hello
(base) ➜  Missing Semtster git:(master) ✗ false && echo "hello"
(base) ➜  Missing Semtster git:(master) ✗ true && echo "hello"
hello
```
- 命令的输出存入变量，双引号解析变量，单引号纯字符串
```
(base) ➜  Missing Semtster path=$(pwd)
(base) ➜  Missing Semtster echo $path          
/home/xubin/Desktop/my_study/Missing Semtster
(base) ➜  Missing Semtster echo "We are in $path"
We are in /home/xubin/Desktop/my_study/Missing Semtster
```

# Vim
- 模式:
```
normal:
insert: i、I、o、O、a、A
i: 从光标所在处插入，I: 在目前所在行第一个非空格字符处开始插入
a: 从光标后一个字符处插入  A: 从光标所在行最后一个字符处插入
o: 在光标下一行插入新的一行，O: 在光标上一行插入新的一行

replace: r、R 
r: 替换光标所在字符一次，R: 一直替换光标所在文字

visual: v=shift+v: 选择行、ctrl+v: 选择块
```
- 按键:
```
h,j,k,l: 左上下右
w,b: 向前向后移动一个单词   e: 移动到单词末尾
sp: 创建窗口   qa: 退出所有窗口
0: 移动到行首   $: 移动到行末   ^: 移动到行首的第一个非空字符
ctrl+u: 向上翻半页   ctrl+d: 向下翻半页
H，M，L: 移动到屏幕最上方、中间、最下面一行
d,c: 删除，c进入insert模式 d2w c2w ci( ca( i(inside) a(at) 
u: 撤销   ctrl+r: 恢复
y: 复制   p: 粘贴
.: 重复上一次编辑操作
/word、?word: 向光标之下和光标之上查找word   n,N: 查找结果向下、向上移动
```
# tmux
```
tmux   创建一个新session
ctrl+b + % 左右平分
ctrl+b + " 上下平分
ctrl+b  关闭当前pane
ctrl+b + 方向键   切换pane
ctrl+b + z  pane全屏/取消全屏
ctrl+b + d  挂起当前session
ctrl+b + s  选择其他session
ctrl+b + c  在当前session创建新的window
ctrl+b + w  选择其他windows
```

# git
- 常用命令
```
git rm --cached XX    将文件从仓库索引目录删除
git status	      查看仓库状态
git diff XX	      查看XX文件相较于暂存区修改了哪些内容
git log               查看当前分支所有版本
git reflog	      查看HEAD指针移动历史
git reset --hard HEAD^/HEAD~      代码回滚到上一个版本    ^^两次    ~100一百次
git reset --hard 版本号		  回滚到指定版本
git checkout - XX   git restore XX    将XX文件尚未加入暂存区的部分全部撤销
git branch -d origin XX  删除本地XX分支 
git push -d origin XX    删除远程仓库XX分支
git merge 分支名      将XX分支合并到当前分支
git stash             将工作区和暂存区尚未提交的修改存入栈中
git stash apply       将栈顶存储的修改恢复到当前分支
git stash drop        删除栈顶存储的修改
git stash pop         将栈顶存储的修改恢复到当前分支并删除
git stash list	      查看栈内元素
```

# 命令
- tldr : 类似man，获取命令调用方式
- find : -name 名字 -path 路径 -type 文件类型 -mtime 修改时间 -exec 执行命令
```
(base) ➜  Missing Semtster git:(master) ✗ find . -name "foo*" -type f
./foo2
./foo1
./foo3
./foo4
./foo
(base) ➜  Missing Semtster git:(master) ✗ find . -name "foo*" -type f -exec rm {} \;
(base) ➜  Missing Semtster git:(master) ✗ find . -name "foo*" -type f
```
- locate : 查找文件系统中具有指定子串的路径

- grep rg fzf: 
```
(base) ➜  Missing Semtster git:(master) ✗ grep foobar mcd.sh 
# foobar
(base) ➜  Missing Semtster git:(master) ✗ grep -R foobar
example.sh:	grep foobar "$file" > /dev/null 2> /dev/null
example.sh:		echo "File $file does not have any foobar, adding one"
example.sh:		echo "# foobar" >> "$file"
course.md:(base) ➜  Missing Semtster git:(master) ✗ grep foobar mcd.sh
mcd.sh:# foobar
(base) ➜  Missing Semtster git:(master) ✗ rg "foobar" 
mcd.sh
6:# foobar

course.md
40:(base) ➜  Missing Semtster git:(master) ✗ grep foobar mcd.sh
92:(base) ➜  Missing Semtster git:(master) ✗ grep foobar mcd.sh 
93:# foobar
94:(base) ➜  Missing Semtster git:(master) ✗ grep -R foobar
95:example.sh:	grep foobar "$file" > /dev/null 2> /dev/null
96:example.sh:		echo "File $file does not have any foobar, adding one"
97:example.sh:		echo "# foobar" >> "$file"
98:course.md:(base) ➜  Missing Semtster git:(master) ✗ grep foobar mcd.sh
99:mcd.sh:# foobar

example.sh
8:	grep foobar "$file" > /dev/null 2> /dev/null
11:		echo "File $file does not have any foobar, adding one"
12:		echo "# foobar" >> "$file"
```

- history
```
(base) ➜  Missing Semtster git:(master) ✗ history | grep mkdir 
   17  mkdir build
   21  mkdir build && cd build
   44  mkdir build && cd build
   80  mkdir build && cd build
   89  mkdir build && cd build
```
