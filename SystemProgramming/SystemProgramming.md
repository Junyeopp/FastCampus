NOTE for System Programming
=====

![capture](/img/cap1.PNG)

## Class1

- OT

## Class2

- LINUX : 서버에 많이 사용되는 운영체제, ANSI C (C언어 표준) 프로그래밍이 가능

## Class3

- LINUX : 다중 사용자, 다중 작업(시분할 시스템)을 지원하는 UNIX와 유사한 운영체제
- GNU : Gnu is Not Unix

## Class4-7

- Amazon Web Service
    - EC2 or instance 생성
    - Elastic IP 생성

## Class8

- Linux
    - 모든 것은 파일이라는 철학을 따름
        - 모든 인터렉션은 파일을 읽고 쓰는 것으로 되어있음
        - I/O와 같은 모든 device관련 기술도 파일과 같이 다루어짐
        - 모든 자원에 대한 추상화 인터페이스로 파일 인터페이스를 활용
    - 전역 네임스페이스 사용
    - 파일은 inode 고유값과 자료구조에 의해 주요 정보 관리
    - 실행 파일 포멧 : ELF(Executable and Linkable Format)
        - 콜스택, 코드, 데이터 및 BSS section 등
    - 가상 메모리 지원
    - 각 프로세스는 pid(process id) 고유값으로 구분
    - init process(첫 번째 프로세스)를 기반으로 fork() 시스템콜을 사용해서 신규 프로세스가 생성됨
    - 파일마다 사용자/그룹으로 권한을 관리
    - root는 슈퍼관리자

## Class9-11

- Shell : 사용자와 하드웨어 또는 운영체제간 인터페이스
    - Bourne-Again Shell(bash) : 거의 리눅스의 default
- bash 명령어
    - ```whoami``` : 로그인한 사용자의 ID를 알려줌
    - ```passwd``` : 로그인한 사용자ID의 암호변경
    - ```useradd``` : 사용자 기본 설정을 자동으로 하지 않음
    - ```adduser``` : 사용자 가본 설정을 자동으로 수행함
    - ```sudo``` : root 권한으로 실행
        - /etc/sudoers 설정파일에서 sudo 관련 설정을 변경할 수 있음
    - ```su``` : 사용자 변경
        - ```su root``` : 현재 사용자의 환경설정 기반, root로 변경
        - ```su - root``` : 변경되는 사용자의 환경설정을 기반으로 root로 전환
    - ```pwd``` : 현재 디렉토리 위치
    - ```cd``` : 디렉토리 이동
        - ```~``` : home 
        - ```-``` : 이전 디렉토리
        - ```..``` : 상위 디렉토리
        - ```.``` : 현재 디렉토리
    - ```ls``` : 파일 목록 출력
        - ```*``` : 임의 문자열
        - ```?``` : 문자 하나
        - ```-i``` : inode 정보 확인
    - ```man``` : 명령어의 메뉴얼을 볼 수 있음
    - ```chmod``` : change mode, 파일 권한 변경
        - ```-R``` : recursive, 하위 디렉토리의 권한을 함께 변경
    - ```chown``` : 소유자 변경
    - ```cat``` : 파일 보기
    - ```head``` : 파일 앞부분(기본적으로 10줄) 보기
    - ```tail``` : 파일 뒷부분(기본적으로 10줄) 보기
    - ```more``` : 파일 보기(화면이 넘어갈 경우, 그 전까지 먼저 보여줌)
    - ```rm``` : 파일 및 폴더 삭제
        - ```-r``` : 하위 디렉토리를 포함해서 삭제
        - ```-f``` : 강제로 삭제
    - ```grep``` : 특정한 키워드와 관련된 파일을 찾음
- ls와 파일권한
    - 리눅스는 파일마다 소유자, 소유자 그룹, 모든 사용자에 대해 읽고, 쓰고, 실행하는 권한을 설정함. 소유자 접근 권한 정보는 inode에 저장
    - 첫글자 : 해당 데이터의 종류를 구분
        - ```-``` : file
        - ```d``` : directory
        - ```l``` : soft link
        - ```c``` : character device
        - ```b``` : block device
    - 그 후는 소유자, 그룹, 기타사용자의 권한 순으로 표시함
        - 데이터가 파일일 때 / 폴더일 때
        - r(읽기, 4) : 읽고 카피 / ls 명령어 가능
        - w(쓰기, 2) : 수정 / 파일생성가능
        - x(실행, 1) : 실행 / cd 접근가능

## Class12

- Standard Stream(표준 입출력) : command로 실행되는 프로세스는 세 가지 스트림을 가지고 있음
    - 표준 입력 스트림(Standard Input Stream) : stdin
    - 표준 출력 스트림(Standard Output Stream) : stdout
    - 오류 출력 스트림(Standard Error Stream) : stderr
- Redirection : 표준 스트림의 흐름을 바꿔줄 수 있다.
    - ```>```, ```<```
    - 주로 명령어 표준 출력을 파일에 쓸 때 사용
    - 기존 파일에 추가는 ```>>```, ```<<``` 사용
- Pipe : 두 프로세스 사이에서 한 프로세스의 출력 스트림을 다른 프로세스의 입력 스트림으로 사용할 때 사용
    - ```|```

## Class13-14

- foreground process : shell에서 프로세스를 실행 한 후, 프로세스 종료까지 사용자가 다른 입력을 못하는 프로세스
    - ```[CTRL] + z``` : 실행 중인 프로세스를 실행중지상태(suspend mode)로 변경
    - ```[CTRL] + c``` : 프로세스 작업 취소
- background process : 사용자 입력과 상관없이 실행되는 프로세스, shell에서 실행 시 맨 뒤에 ```&```를 붙여줌
    - ex> 결과로 [1] 17651 이 출력됨 : [1]은 작업번호(job number), 17651은 pid를 나타냄
    - ```jobs``` : background로 실행 또는 중지된 상태의 프로세스들을 보여줌
    - ```bg``` : 가장 마지막에 suspend mode가 된 프로세스를 background process로 실행시킴
        - ```bg``` 뒤에 job number를 쓰면 해당 프로세스를 실행시킬 수 있음
    - ```ps``` : 프로세스 상태 확인
        - ```-e``` : 시스템상의 모든 프로세스에 대한 정보 출력
        - ```-f``` : UID, PID, PPID, CPU%, STIME, TTY, TIME, CMD 출력
    - ```kill``` : 프로세스 중지
        - ```kill % job number```
        - ```kill pid```
        - ```-9``` : 강제 종료 옵션
- daemon process : 사용자 모르게 시스템 관리를 위해 실행되는 프로세스, 보통 시스템 부팅 시 자동 실행, ex> ftpd, inetd

## Class15-18

- ```cp``` : copy, 파일 복사
    - ```-r``` : 하위 디렉토리를 포함해서 복사
    - ```-f``` : 강제로 복사
- Hard Link
    - ```ln``` : link
    - inode number가 동일함 -> 동일한 inode structure를 가리킴
    - ```rm```으로 원본 파일을 삭제해도 hardlink된 파일이 있으면(inode의 link_count 값을 보고 확인) 해당 inode structure은 삭제되지 않고 원본 파일의 inode number만 삭제됨, 따라서 hardlink된 파일의 inode number와 inode structure은 그대로 유지됨
- Soft Link(or Symbolic Link)
    - ```ln -s```
    - inode number가 다름 -> 별도의 inode structure를 가짐, inode structure의 address는 원본파일의 inode structure를 가리키는 redirected path를 가짐
- Device
    - Block Device : HDD, CD와 같이 block 또는 sector 등 정해진 단위로 데이터 전송, IO 송수신 속도가 높음
    - Character Device : 키보드, 마우스 등 byte 단위로 데이터 전송, IO 송수신 속도가 낮음

## Class19-20

- API(Application Programming Interface) : 응용 프로그램과 분리된 하위 호환 인터페이스
    - ex> 시스템 콜 래퍼, 입출력 라이브러리 등
- C Library
    - Linux C library : GNU libc - glibc : 시스템콜, 시스템콜 래퍼, 기본 응용 프로그램 기능을 포함
- C Compiler
    - Linux C compiler : GNUcc - gcc
- ABI(Application Binary Interface) : 함수 실행, 레지스터 활용, 시스템콜 실행, 라이브러리 링크 방식 들을 정의해 놓음
    - ABI가 호환되면 재컴파일없이 동작

## Class21-25

- 각 프로세스는 각 시점에 unique한 pid값을 가짐, 일반적으로 1씩 증가하며 pid가 할당되며 max(보통 signed 16bit interger : 2^15 = 32768)이 지나면 다시 1부터 할당됨
- 프로세스 계층
    - 최초 프로세스 : init process, pid 1 : OS가 생성
    - 다른 프로세스는 또 다른 프로세스로부터 생성
    - ppid : 부모 프로세스의 pid
- owner 관리
    - Linux 내부에서는 프로세스의 owner(user)와 group을 UID/GID(integer)로 관리
    - 사용자에게 보여줄 때만 UID와 사용자이름 매핑 정보를 기반으로 사용자 이름으로 제공
    - cf> ```sudo vi /etc/passwd```, ```sudo vi /etc/shadow```
- ```getpid()``` : pid얻음, 함수형 : pid_t
- ```getppid()``` : ppid얻음, 함수형 : pid_t
- ```fork()``` : system call
    - 새로운 프로세스 공간을 별도로 만들고, fork()를 호출한 부모프로세스 공간을 모두 복사
    - return값으로 부모프로세스는 자신의 PID, 자식프로세스는 0을 받음
    - 실행 후 부모, 자식 프로세스 모두 fork()의 다음 코드를 PC가 가리킴
- ```exec()``` : system call
    - exec()를 호출한 프로세스의 TEXT, DATA, BSS영역을 새로운 프로세스의 이미지로 덮어씌움
    - 실행방법에 따라 execl, execlp, execle, execv, execvp, execvpe가 있음
- ```wait()``` : system call
    - ```pid_t wait(int *status)```
    - return값은 종료된 자식 프로세스의 pid
    - 실행되면 status값에 자식프로세스의 종료상태번호가 들어감
    - wait()를 사용하면, fork()호출 시 자식프로세스가 종료되고 SIGCHLD signal을 보낼 때까지 부모프로세스가 기다림
    - 자식프로세스가 종료된 후 메모리에 남아있는 자식프로세스의 정보를 지워야함, 부모프로세스가 해당 정보를 확인하면 메모리에서 없어짐
- ```int WIFEXITED(status)``` : 자식 프로세스가 정상 종료 시 리턴값은 0이 아닌 값이 됨

## Class26

- copy-on-write
    - fork()는 새로운 프로세스 공간 생성 후, 기존 프로세스 공간 복사 -> 프로세스 생성 시간이 오래 걸림 -> copy-on-write
    - 자식 프로세스 생성시, 부모 프로세스 페이지를 우선 사용
    - 해당 페이지를 읽기가 아닌 쓰기를 할 때 페이지를 복사하고 분리함

## Class27-28

- ```exit()``` : system call
    - ```void exit(int status);```
    - status : 프로세스 종료상태번호
        - 0 : EXIT_SUCCESS
        - 1 : EXIT_FAILURE
    - main함수에서 ```return 0;```과 ```exit(0);```은 큰 차이가 없음
        - ```exit(0)``` : 즉시 프로세스를 종료함
        - ```return 0``` : C 실행파일에 기본으로 포함된 ```_start()```함수를 호출하고 해당 함수에서 결국 ```exit()```를 호출함
    - 실행순서
        1. ```atexit()```에 등록된 함수 실행
            - 프로세스 종료시 실행될 함수를 등록하기 위해 사용
            - 등록된 역순서대로 실행됨
        2. 열려있는 모든 입츌력 스트림 버퍼(stdin,stdout,strerr) 삭제
        3. 프로세스가 오픈한 파일을 모두 닫음;
        4. ```tmpfile()```함수를 통해 생성한 임시파일 삭제

## Class29

- ```int nice(int inc)``` : system call
    - 프로세스 중 사실상 root가 소유한 프로세스만 우선순위를 높일 수 있음
    - 다른 프로세스는 우선순위를 낮출 수만 있음
    - 스케쥴링 방식에 따라 우선순위가 적용이 될 수도 있고, 안될 수도 있음
    - inc : 우선순위 값
- ```int getpriority(int which, id_t who)``` : system call, 우선순위값을 가져옴
- ```int setpriority(int which, id_t who, int value)``` : system call, 우선순위값을 매김
    - which : 프로세스(PRIO_PROCESS), 프로세스 그룹(PRIO_PGRP), 사용자(PRIO_USER) 별로 우선순위를 가져올 수 있음
    - who : pid, 0이면 현재 프로세스
    - value : 우선순위 값

## Class30-32

- IPC(InterProcess Communication)
    - file
    - Message Queue
        - 양방향 통신 가능, kernel space 사용
        - ```msqid = msgget(key, msgflg)``` : message queue 생성
            - key : key지정
            - msgflg : 옵션, ex> IPC_CREAT : 새로운 키면 식별자를 새로 생성
        - ```msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT)```
            - IPC_NOWAIT : 데이터를 읽을 때까지 기다릴지 말지 결정
        - ```ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)```
            - msgtyp : 0이면 첫번째 메세지, 양수이면 타입이 일치하는 첫번째 메시지
            - msgflg : 블록 모드(0), 메세지가 없으면 기다림 / 비블록 모드(IPC_NOWAIT), 메세지가 없으면 넘어감
        - ```key_t ftok(const char *path, int id)``` : path경로명의 inode값과 id값을 기반으로 키 생성, 경로 삭제 후 재생성시 inode값이 달라짐으로 다른 키가 리턴됨
        - ```msgctl(msgid, IPC_RMID, 0)``` : 해당 message queue를 삭제
    - Shared Memory
        - kernel space에 메모리 공간을 만들고 해당 공간을 변수처럼 쓰는 방식
        - ```int shmget(key_t key, size_t size, int shmflg)```
            - key : 임의 숫자 또는 ftok로 생성한 키 값
            - size : 공유메모리 크기
            - shmflg : 공유메모리 속성
            - return value : 공유메모리 식별자 리턴
        - ```void *shmat(int shmid, const void *shmaddr, int shmflg)```
            - shmid : 공유메모리 식별자
            - shmaddr : 공유메모리 연결주소, (char *)NULL로 설정하면 알아서 적절한 주소로 설정됨
            - shmflg : 공유메모리 권한(0 : 읽기/쓰기, SHM_RDONLY : 읽기만 가능)
            - return value : 성공시 연결된 공유메모리의 시작 주소를 리턴
            - ex> ```shmaddr = (char *)shmat(shmid, (char *)NULL, 0)```
        - ```int shmdt(char *shmaddr)```
            - 공유메모리 해제
        - 읽기, 쓰기는 포인터 변수처럼 ```(char *)shmadder```를 사용하면 됨
        - ```int shmctl(int shmid, int cmd, struct shmid_ds *buf)```
            - shmid : 공유메모리 식별자
            - cmd : 수행할 제어기능, IPC_RMID : 공유메모리 제거
            - buf : 공유메모리 구조체의 종류, 보통 NULL로 씀
    - Pipe
        - fork()로 자식 프로세스를 만들었을 때 부모->자식으로의 단방향 통신, kernel space사용
        - pipe(fd) : kernel 영역에 pipe를 생성함
        - 부모프로세스에서 write로 fd[1]에 씀
        - 자식프로세스에서 read로 fd[0]을 읽음
    - Signal
        - 종류 : ```kill -l```로 확인할 수 있음
            - ```SIGHILL``` : 프로세스를 죽여라
            - ```SIGALARM``` : 알람발생
            - ```SIGSTP``` : ```CTRL + z```, 프로세스 멈춤
            - ```SIGCONT``` : 멈춰진 프로세스를 실행
            - ```SIGINT``` : ```CTRL + c```
            - ```SIGSEGV``` : 프로세스가 다른 메모리영역을 침범함
        - ```int kill(pid_t pid, int sig)``` : signal 보내기
            - pid : PID
            - sig : signal number
        - ```signal```함수로 signal에 따른 동작을 재정의할 수 있음
        - PCB에 해당 프로세스가 블록 또는 처리해야하는 signal 관련 정보 관리
        - kernel mode에서 user mode 전환시 signal 정보를 확인함
    - Semaphore
    - Socket
- ```ipcs``` : Message Queues, Shared Memory Segments, Semaphore Arrays의 상태를 보여줌

## Class33-36

- Shell Script
    - ```#!/bin/bash```로 시작
    - ```echo``` : 화면에 출력
    - ```#``` : 주석
    - 변수
        - 선언 : '변수명=데이터', 띄어쓰기는 허용되지 않음
        - 사용 : '$변수명'으로 사용
    - 리스트변수
        - 선언 : '변수명=(데이터1 데이터2 데이터3)'
        - 사용 : '${변수명[인덱스번호]}'
            - ```${val[@]}``` : val배열의 모든 데이터 출력
            - ```${val[*]}``` : val배열의 모든 데이터 출력
            - ```${#val[@]}``` : val배열 크기 출력
            - ```$(shell instruction)``` : 해당 쉘명령어의 출력값 리스트를 받음
    - 사전에 정의된 지역 변수
        - ```$$``` : 쉘의 프로세스 번호
        - ```$0``` : 쉘스크립트 이름
        - ```$1```~```$9``` : 명령줄 인수
        - ```#*``` : 모든 명령줄 인수리스트
        - ```$#``` : 인수의 개수
        - ```$?``` : 최근 실행한 명령어의 종료값
    - 연산자
        - ```expr``` : 숫자계산
            - ``` ` ```로 묶어줌
            - ```*```와 ```()``` 앞에는 ```\```를 같이사용
            - 연산자와 숫자, 변수, 기호 사이에는 space를 넣어야 함
    - 조건문
        - ```
          if [ condition ] //[]앞뒤로 공백필요
          then
              statement
          fi
          ```
        - ```
          if [ condition ]
          then
              statement
          else
              statement
          fi
          ```
        - 한 줄에 작성하려면 ```;```사용
            - ex> ``` if [ condition ]; then statement; fi```
        - ```A==B``` : A와 B가 일치
        - ```A!=B``` : A와 B가 일치하지 않음
        - ```-z A``` : A가 null이면 참
        - ```-n A``` : A가 null이 아니면 참
        - 수치비교 : ```-eq```, ```-ne```, ```-lt```, ```-le```, ```-gt```, ```-ge```
            - e : equal, n : not, l : less, g : greater, t : than
        - 파일검사 : ```-e```, ```-d```, ```-r```, etc
        - 논리연산 : ```-a``` or ```&&```, ```-o``` or ```||```, ```!```, ```true```, ```false```
    - 반복문
        - ```
          for var in var1 var2 ...
          do
              statement
          done
          ```
        - 한 줄에 작성하려면 ```;```사용
        - ```
          while [ condition ]
          do
              statement
          done
          ```
    - 압축
        - ```tar```
            - -x : 묶음을 해제
            - -c : 파일을 묶음
            - -v : 묶음/해제 과정을 화면에 표시
            - -z : gunzip을 사용
            - -f : 파일 이름을 지정
    - 검색
        - ```find```

## Class37-38

- POSIX thread(or Pthread)  : thread 표준 API, UNIX 시스템 핵심 threading library
    - ```<pthread.h>```에 정의, compile시 ```-pthread```옵션 필요
    - thread 관리
        - ```pthread_create``` : thread 생성
        - ```pthread_exit``` : thread 종료
        - ```pthread_join``` : 해당 thread 종료 때까지 기다린 후 resource free 및 main thread에서 추가처리
        - ```pthread_detach``` : 해당 thread 종료 때까지 기다리지 않고, 종료될 경우 즉시 resource free 처리함
    - synchronize
        - mutex
            - ```pthread_mutex_t mutex_lock = PTHREAD_MUTEX_INITIALIZER``` : mutex 선언
            - ```pthread_mutex_lock``` : lock
            - ```pthread_mutex_unlock``` : unlock

## Class39-40

- ```void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset)```
    - [start+offset] ~ [start+offset+length] 만큼의 물리 메로기 공간을 mapping할 것을 요청
    - 메모리 주소를 리턴받음
    - 보통 start : NULL or 0 사용, offset : mapping되기 원하는 물리 메모리 주소로 지정
    - prot : 보호 모드 설정
        - PROT_READ : 읽기가능, PROT_WRITE : 쓰기가능, PROT_EXEC : 실행가능, PROT_NONE : 접근불가
    - flags : 메모리 주소 공간 설정
        - MAP_SHARED : 다른 프로세스와 공유가능, MAP_PRIVATE : 프로세스 내에서만 사용가능, MAP_FIXED : 지정된 주소로 공간지정
    - fd : device file에 대한 file descriptor
    - 동작방식 :
        1. mmap 실행 시 가상 메모리 주소에 file 주소 매핑
        2. 해당 메모리 접근 시(요구페이징, lazy allocation), 페이지 폴트 인터럽트 발생, OS에서 file data를 복사해서 물리 메모리 페이지에 넣어줌
        3. 메모리 read -> 해당 물리 페이지 데이터를 읽음
        4. 메모리 write -> 해당 물리 페이지 데이터 수정 후 페이지 상태 flag 중 dirty bit를 1로 수정
        5. 파일 close -> 물리 페이지 데이터가 file에 업데이트됨
    - 장점
        - ```read()```, ```write()``` 할 때 반복적인 파일 접근을 방지하여 성능 개선
        - mapping 된 영역은 파일 처리를 위한 ```lseek()```를 사용하지 않고 간단한 포인터 조작으로 탐색 가능
    - 단점
        - mmap은 페이지 사이즈 단위로 
- ```int munmap(void *addr, size_t length)```
    - *addr에 mapping된 물리 메모리 주소를 해제함
    - length : mapping된 메모리의 크기
- ```int msync(vodi *start, size_t length, int flags)```
    - start : ```mmap()```를 통해 리턴된 메모리 맵의 시작주소
    - length : 동기화할 길이
    - flags
        - MS_ASYNC : 비동기 방식, 동기화(memory->file)명령만 내리고 다음 코드 실행
        - MS_SYNC : 동기 방식, 동기화(memory->file)명령이 다 실행될 때까지 블럭 상태로 대기
        - MS_INVALIDATE : 현재 메모리 맵을 무효화하고 파일 데이터로 갱신(file->memory)

## Class41

- ```int stat(const char *path, struct stat *buf)```
- ```int fstat(int filedes, struct stat *buf)```