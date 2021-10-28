# 文件I/O(fcntl.h, unistd.h)
>## int open(const char* __file, int __oflag, ...(mode_t mode));
>## int openat(int fd, const char* __file, int __oflag, ...(mode_t mode));
>* 返回文件描述符fd。
>> 1. __file:文件路径名.
>> 2. __oflag:用常量说明函数选项，通过或运算(|)添加多个选项，文件状态标志。<div id="oflag"></div>
O_RDONLY（0）：只读打开</br>   O_WRONLY（1）：只写打开</br>   O_RDWR（2）：读写打开</br>    O_SEARCH：只搜索打开</br>
O_CLOEXEC：把FD_CLOEXEC常量设置为文件描述符标志。</br>
O_CREAT：若文件不存在则创建他。使用此选项要同时说明第三个参数mode指定文件访问权限</br>
O_EXCL：如果文件已存在，则出错，否则，创建文件，测试与创建成为一个原子操作</br>
O_APPEND：每次写都追加到文件尾端。</br>
O_TRUNC：如果文件存在，且为只写或读写打开，则将其长度截断为0。</br>
O_DIRECTORY：如果__file不是目录，报错。</br>
O_NOFOLLOW：如果__file是一个符号链接则出错</br>
O_NONBLOCK：如果__file是一个块特殊文件或字符特殊文件，则文件本次打开操作和后续I/O操作设置非阻塞方式。</br>
O
>> 3. mode：设置文件发访问权限。</br>
S_IRWXU：用户（所有者）读写执行</br>
S_IRUSR：用户读</br>
S_IWUSR：用户写</br>
S_IXUSR：用户执行</br>
组：GRP</br>
其他：OTH</br>

>## int creat(const char* __file, mode_t mode);
>>* 函数等效于open(__file, O_WRONLY | O_CREAT | OTRUNC, mode);

>## int close(int fd);

>## off_t lseek(const char* __file, off_t offest, int whence);
>* 返回新的文件偏移量。若出错返回-1。
>> 1. offest：文件偏移量。
>> 2. whence：offest解释。</br>
SEEK_SET：文件偏移量设置为距文件开始处offest个字节</br>
SEEK_CUR：文件偏移量设置为其当前值加offest，offest可正可负。</br>
SEEK_END：文件偏移量设置为文件长度加offest，offest可正可负。</br>

>## ssize_t read(int fd, void *buf, size_t nbytes);
>>* 返回读取字节数，若出错返回-1。
>## ssize_t write(int fd, void *buf, size_t nbytes);
>>* 返回写入字节数，若出错返回-1。

>## int dup(int fd);
>## int dup2(int oldfd, int newfd);
>* 若复制成功，返回新的文件描述符，否则返回-1.

>## int fcntl(int fd, int cmd, ...(int arg))l
>* 若成功，返回值依赖arg选项，若出错，返回-1。
>> 1. cmd
F_DUPFD或F_DUPFD_CLOEXEC：复制一个已有的文件描述符。</br>
F_GETFD或F_SETFD：获取/设置文件描述符标志。</br>
F_GETFL或F_SETFL：获取/设置文件状态标志。（读写、添写、同步、非阻塞等，详见见[open函数](#oflag)oflag参数）</br>
F_GETOWN或F_SETOWN：获取/设置异步I/O所有权。</br>
F_GETLK、F_SETLK或F_SETLKW：获取/设置记录锁。</br>
