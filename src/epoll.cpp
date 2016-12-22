//#include <iostream>
//#include <sys/socket.h>
//#include <sys/epoll.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include <stdio.h>
//#include <errno.h>
//#include <string.h>
//#define PORT 9000
//using namespace std;
//
//int main()
//{
//    struct sockaddr_in clientaddr, serveraddr;
//
//    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
//    memset(&serveraddr, 0, sizeof(serveraddr));
//    serveraddr.sin_family = AF_INET;
//    serveraddr.sin_addr.s_addr = (INADDR_ANY);
//    serveraddr.sin_port = htons(PORT);
//
//    bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
//
//    listen(listenfd, 10);
//    cout << "start listen" <<endl;
//    struct epoll_event ev, events[20];
//
//    int epfd = epoll_create(256);
//    int nfds,connfd,sockfd;
//    socklen_t clilen = sizeof(clientaddr);
//    ev.data.fd = listenfd;
//    ev.events = EPOLLET|EPOLLIN;
//    char line[1024];
//    ssize_t n;
//    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);
//    for(;;)
//    {
//        nfds = epoll_wait(epfd, events, 20, 500);
//        for(int i=0;i<nfds;++i)
//        {
//            if(events[i].data.fd == listenfd)
//            {
//                connfd = accept(listenfd, (sockaddr *)&clientaddr, &clilen);
//
//            
//            cout << "new client" << endl;
//            ev.data.fd = connfd;
//            ev.events = EPOLLIN|EPOLLET;
//            epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);
//            }
//            else if(events[i].events&EPOLLIN)
//            {
//                if((sockfd = events[i].data.fd)<0)
//                    continue;
//                if((n = read(sockfd, line, 1024))<0)
//                {   
//                    if(errno == ECONNRESET)
//                    {
//                        close(sockfd);
//                        events[i].data.fd = -1;
//                    }
//                    line[n] = '/0';
//                    cout << "read" << line << endl;
//                    ev.data.fd = sockfd;
//                    ev.events = EPOLLOUT|EPOLLET;
//                }
//
//            }
//            else if(events[i].events&EPOLLOUT)
//            {
//                sockfd = events[i].data.fd;
//                write(sockfd, line, n);
//                ev.data.fd = sockfd;
//                ev.events = EPOLLIN|EPOLLET;
//                epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);
//            }
//        }
//    }
//    
//    return 0;
//}
