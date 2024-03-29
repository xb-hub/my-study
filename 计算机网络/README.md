# 计算机网络
## HTTP协议
1. HTTP是什么
- 超文本传输协议: 超文本是指文字、图片、视频等混合体。
- 常见状态码
```
2XX: 成功状态码
- 200 OK: 表示一切正常，如果是非head请求。服务器返回响应头都会有body数据
- 204 No Content: 与200 OK基本相同，但响应头没有body数据
- 206 Partial Content: 应用于HTTP分块下载或断点续传，表示响应返回的body数据不是资源的全部，也是服务器处理成功的状态
3XX: 重定向状态码
- 301 Move Permanently: 表示永久重定向，表明资源已经不存在，需要访问新的url
- 302 Found: 表示临时重定向，表明资源还存在，只是暂时需要另一个URL来访问
- 304 Not Modified: 不具有跳转含义，表示资源已修改，重定向到已存在的缓冲文件，告诉客户端可以继续使用缓存资源，也称缓存重定向，
4XX: 错误状态码
- 400 Bad Request: 表示客户端请求报文有错误
- 403 Forbidden: 表示服务器禁止访问资源
- 404 Not Found: 表示服务器未找到请求资源
5XX: 服务端错误状态码
- 500 Internal Server Error: 服务器发生错误
- 501 Not Implemented: 表示客户端请求功能还不支持
- 502 Bad Gateway: 通常是服务器作为网关或代理时返回的错误码，表示服务器自身正常工作，访问服务器发生错误
- 503 Service Unavailable: 表示服务器暂时忙，无法响应客户端
```

2. GET和POST区别:
- 幂等: 多次执行相同操作，结果都是相同的。
- 安全: 请求方法不会破坏服务器上资源。
- GET的语义是从服务器获取指定的资源，GET请求的参数位置一般写在URL中，浏览器会对URL长度有限制，GET方法是安全、幂等、可被缓存的。(只读操作）
- POST的语义是根据请求负荷(报文body)对指定资源作出处理。POST请求携带数据位置一般写在报文body中，浏览器对body大小不会有限制，POST不安全、不幂等、不可缓存。(新增或提交数据请求）

3. HTTP缓存技术
- 强制缓存: 只要浏览器判断缓存没有过期，则直接使用浏览器本地缓存。
- 协商缓存:

4. HTTP/1.1优缺点
- 无状态: 服务器不用去记忆HTTP状态，减轻服务器负担，把更多CPU和内存用来对外服务。但完成关联性操作时很困难，可以使用Cookie解决。
- 不安全: 通信使用明文，内容容易被窃听、窃取。不验证通信方身份，可能遭遇伪装。无法证明报文的完整性，可能遭篡改。可以通过HTTPS解决，引入SSL层。

4. HTTP/1.1性能
- 长连接: 减少TCP连接的重复建立和断开所造成的额外开销，减轻服务器负载
- 管道网络传输: 在一个TCP连接中，客户端可以发起多个请求，只要第一个请求发出去，不必等待其回来就可以发送第二个请求，减少整体响应时间。（服务器必须按照接受请求的顺序发送对这些管道化请求的响应），只解决了请求的队头阻塞，没有解决响应的队头阻塞。
- 队头阻塞: 请求序列中的一个请求因某种原因阻塞，后面排队的请求移动阻塞，会导致客户端请求不到数据。

5. HTTP和HTTPS的区别
- HTTP信息是明文传输，HTTPS在HTTP和TCP之间加入了SSL安全协议，加密传输报文。
- HTTP三次握手后即建立连接，可以进行报文传输，HTTPS三次握手后还需要进行SSL握手过程才可以进行加密传输。
- 两者默认端口不同，HTTP: 80, HTTPS: 443

6. HTTPS解决了HTTP的哪些问题


7. HTTP/1.1优化
- 避免发送HTTP请求(缓存)
- 减少HTTP请求次数(减少重定向、合并请求、延迟发送请求)
- 减少HTTP响应数据大小(无损压缩、有损压缩)
 


 # 网络编程
## 同步、异步、阻塞、非阻塞</br>
1. **同步**: 如果有多个任务或事件发生，这些任务或事件必须逐个进行，一个事件或者任务的执行会导致整个流程的暂时等待无法并行执行。
2. **异步**: 如果有多个任务或事件发生，这些任务或事件可以并发执行。
3. **阻塞**: 如果一个任务发送请求操作，但请求操作所需的条件不满足，一直等待，直到条件满足。
4. **非阻塞**: 如果一个任务发送请求操作，并且所需的条件不满足，立即返回一个标志信息告知条件不满足，不会一直等待。
## IO
- IO读请求两阶段：</br>
(1）查看数据是否就绪。</br>
(2）进行数据拷贝（内核将数据拷贝到用户线程）。</br>
阻塞（blocking IO）和非阻塞（non-blocking IO）的区别就在于第一个阶段，如果数据没有就绪，在查看数据是否就绪的过程中是一直等待，还是直接返回一个标志信息。
1. **阻塞IO**: 如果一个任务发送IO请求，但数据没有就绪，一直等待，直到数据就绪。
2. **非阻塞IO**: 如果一个任务发送IO请求，并且数据没有就绪，立即返回一个标志信息告知条件数据未就绪，不会一直等待。
3. **同步IO**: 当用户发出IO请求之后，如果数据没有就绪，需要通过用户线程或者内核不断地去轮询数据是否就绪，当数据就绪时，再将数据从内核拷贝到用户线程；
4. **异步IO**: 只有IO请求操作的发出是由用户线程来进行的，IO操作的两个阶段都是由内核自动完成，然后发送通知告知用户线程IO操作已经完成。也就是说在异步IO中，不会对用户线程产生任何阻塞。

## IO模型
1. 阻塞IO模型

2. 非阻塞IO模型

3. 多路复用IO模型
