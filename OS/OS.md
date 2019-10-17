NOTE for Operating System
=====

![capture](/img/cap1.PNG)

## Class1

- OT

## Class2

- OS : Operating System, 시스템 자원 관리자
    - 시스템 자원 : CPU, Memory, I/O Devices, SSD, HDD

## Class3

- 운영체제는 응용프로그램을 관리

## Class4-10

- History
- 1950
    - 운영체제가 없음
    - 응용 프로그램이 직접 시스템 자원을 제어
- 1960 초
    - batch processing system 출현
        - 여러 응용 프로그램을 등록시켜놓으면, 순차적으로 실행하는 시스템
        - 이를 기반으로 운영체제가 출현

- 1960 후
    - 시분할 시스템(Time Sharing System)
        - 목적 : 다중 사용자 지원, 컴퓨터 응답 시간 최소화
    - 멀티 태스킹(Multi Tasking)
        - 목적 : 단일 CPU에서 여러 응용 프로그램의 병렬 실행
    - cf. 멀티 프로그래밍(Multi Programming) : 최대한 CPU 활용도를 높임

- 1970
    - UNIX OS : 벨 연구소에서 나옴, 현대 운영체제의 기본 기술을 포함한 최초의 운영체제

- 1980
    - 개인용 컴퓨터
    - Command LIne Interface -> Graphical User Interface

- 1990
    - 엑셀, 워드 등 응용 프로그램 시대, Killer Application
    - 네트워크 기술 발전, WWW
    - 오픈 소스 운동 활성화 시작, LINUX

- 2000
    - 오픈 소스 활성화 : LINUX, Apache, MySQL
    - 가상 머신, 대용량 병렬 처리 등 활성화

## Class11

- 운영체제는 사용자 인터페이스 제공
    - Shell
        - 사용자가 운영체제 기능과 서비스를 조작할 수 있도록 인터페이스를 제공하는 프로그램
- 운영체제는 응용 프로그램을 위한 인터페이스 제공
    - API (Application Programming Interface)
        - 함수로 제공
        - 보통은 library 형태로 제공
        - 내부에는 시스템콜을 호출하는 형태로 만들어짐
    - 시스템 콜
        - 운영체제가 각 기능을 사용할 수 있도록 제공하는 명령 또는 함수

## Class12

- CPU Protectoin Rings
    - user mode : 응용 프로그램이 사용
    - kernel mode : 특권 명령어 실행과 원하는 작업 수행을 위한 자원 접근을 가능하게 하는 모드, OS가 사용
    -> 응용 프로그램이 전체 시스템을 헤치지 못함

- 시스템 콜은 커널 모드로 실행
- 커널 모드에서만 실행 가능한 기능들이 있음
- 커널 모드로 실행하려면, 반드시 시스템 콜을 사용해야 함

## Class13,14

- 프로세스 스케쥴링
    - 배치 처리 시스템 : 큐와 비슷, First in First out
    - 시분할 시스템 : 다중 사용자 지원, 응답시간 최소화
    - 멀티 태스킹 : 여러 응용 프로그램을 동시에 실행하는 것처럼 느끼게 함
    - 멀티 프로세싱 : 여러 CPU로 하나의 프로그램을 병렬 실행

## Class15

- 프로세스 : 메모리에 올려저서 실행 중인 프로그램
    - 응용 프로그램은 여러 개의 프로세스로 이루어질 수 있음
- 코드 이미지(바이러니) : 실행 파일, ex. ELF format
- 스케줄러 : 프로세스 실행을 관리
    - FIFO(First In First Out) Scheduler
        - 프로세스가 저장매체를 읽는 등의 작업 없이 CPU를 계속 사용한다고 가정
        - 요청이 먼저 들어온 프로세스부터 실행
        - 가장 간단한 스케쥴러(배치 처리 시스템), FCFS(First Come First Served) Scheduler
    - SJF(Shortest Job First) Scheduler
        - 프로세스 실행시간이 가장 짧은 프로세스부터 실행
    - Priority-Based Scheduler
        - 우선순위가 높은 프로세스부터 실행
        - 정적 우선순위 : 프로세스마다 우선순위를 미리 지정
        - 동적 우선순위 : 스케쥴러가 상황에 따라 우선순위를 동적으로 변경
    - Round Robin Scheduler
        - 시분할 시스템 기반

- cf.
    - RealTime OS(RTOS) : 응용 프로그램 실시간 성능 보장을 목표로 하는 OS
        - 정확하게 프로그램 시작, 완료 시간을 보장
    - General Purpose OS(GTOS)
        - Windows, Linux 등

## Class16,17

- 프로세스 상태
    - running state : 현재 CPU에서 실행 상태
    - ready state : CPU에서 실행 가능 상태
    - block state : 특정 이벤트 발생 대기 상태

## Class18,19

- 선점형 스케쥴러(Preemptive Scheduler) : 하나의 프로세스가 다른 프로세스 대신 프로세서(CPU)를 차지할 수 있음
- 비선점형 스케쥴러(Non-preemptive Scheduler) : 하나의 프로세스가 끝나지 않으면 다른 프로세서는 CPU를 사용할 수 없음, 프로세스가 자발적으로 blocking 상태로 들어가거나 실행이 끝났을 때만 다른 프로세서로 교체가능

## Class20-22

- 인터럽트 : CPU가 프로그램을 실행하고 있을 때, 다른 장치에서 이벤트가 발생하여 처리가 필요한 경우 CPU에 알려 처리하는 기술. 일종의 이벤트로 불림
    - 내부 인터럽트(소프트웨어 인터럽트) : Divide-by-Zero Interrupt, 사용자 모드에서 허용되지 않은 명령 또는 공간접근, Overflow, Underflow
    - 외부 인터럽트(하드웨어 인터럽트) : Timer Interrupt, I/O Interrupt
    - 인터럽트는 미리 정의되어 각각 번호와 실행 코드를 가리키는 주소가 기록되어 있음
        - IDT에 컴퓨터 부팅시 운영체제가 기록
- 시스템 콜 인터럽트
    - 시스템 콜 실행을 위해서는 코드에 인터럽트 명령을 넣어 CPU에게 실행시켜야 함
    - ```
        mov eax, 1 // eax레지스터에 시스템 콜 번호를 넣고
        mov ebx, 0 // ebx레지스터에 시스템 콜에 해당하는 인자값을 넣고
        int 0x80 // 소프트웨어 시스템콜 인터럽트 번호를 넘겨줌
      ```

        - Detail
            1. CPU는 user mode를 kernel mode로 바꿈
            2. IDT(Interrupt Descriptor Table)에서 0x80에 해당하는 주소(함수)를 찾아 실행
            3. system_call()함수에서 eax로부터 시스템 콜 번호를 찾아서 해당 번호에 맞는 시스템 콜 함수로 이동
            4. 해당 시스템 콜 함수 실행 후 user mode로 변경하고 해당 프로세스 다음 코드 실행

## Class23-25

- Process : Stack, Heap, Data, Code(text) 공간으로 되어 있음
    - Stack : 임시데이터(함수 호출, 로컬 변수 등)를 저장, 코드를 실핼할 때 코드가 끝나면 실행할 return address를 stack 공간에 넣음
    - Heap : malloc()과 같이 동적으로 공간생성이 필요한 경우 Heap 공간에 설정됨
    - Data : 변수, 초기화된 데이터를 넣음
    - Code : compile된 기계어 code
- PC(Program counter), SP(Stack pointer), EBP, EAX

## Class26

- DATA : 두 종류로 볼 수 있음
    - BSS : 초기화되지 않은 전역변수
    - DATA : 초기값이 있은 전역변

## Class27-28

- Context switching : CPU에 실행할 프로세스를 교체하는 기술
    - 실행 중지할 프로세스 정보를 해당 프로세스의 PCB에 업데이트해서 메인 메모리에 저장
    - -> 다음 실행할 프로세스의 메인 메모리에 있는 PCB 정보를 CPU의 레지스터에 넣고 실행
- PCB(Process Control Block / Process Context Block)
    - Process ID
    - Register Value(PC, SP, etc)
    - Scheduling Info(Process State)
    - Memory Info(Memory size limit)
    - etc
- dispatch : ready state의 프로세스를 running state로 바꾸는 것

## Class29-33

- IPC(InterProcess Communication)
    - file
    - Message Queue
    - Shared Memory
    - Pipe
    - Signal
    - Semaphore
    - Socket
    - etc

## Class34-36

- Thread
    - Light Weight Process라고도 함
    - 하나의 프로세스에 여러 개의 스레드 생성 가능, 동시 실행 가능, 프로세스의 데이터를 모두 접근 가능
    - Stack영역에 각 thread를 위한 stack영역이 구성됨
    - 각 thread마다 PC, SP가 있음
    - POSIX Threads : thread 관련 표준 API
    - Synchronization issue
    - ```import threading
        g_count = 0
        def thread_main():
            global g_count
            for i in range(1000000):
                g_count = g_count + 1
        threads = []
        for i in range(50):
            th = threading.Thread(target = thread_main)
            threads.append(th)
        for th in threads:
            th.start()
        for th in threads:
            th.join()
        print('g_count = ', g_count)
      ```
    - issue solution : mutual exclusion
      ```import threading
        g_count = 0
        def thread_main():
            global g_count
            lock.acquire()
            for i in range(1000000):
                g_count = g_count + 1
            lock.release()
        lock = threading.Lock()
        threads = []
        for i in range(50):
            th = threading.Thread(target = thread_main)
            threads.append(th)
        for th in threads:
            th.start()
        for th in threads:
            th.join()
        print('g_count = ', g_count)
      ```
    - 위에서 동시실행하면 안되는 코드 영역를 임계 영역(critical section)이라고 하고, 동시에 수정하면 안되는 변수를 임계 자원(critical resource)라고 한다

## Class37

- Critical Section에 접근을 막기 우해 LOCKING 매커니즘이 필요
    - Mutex(binary semaphore) : critical section에 하나의 thread만 들어갈 수 있음
    - Semaphore : critical section에 여러 thread가 들어갈 수 있음, counter를 두어서 동시에 리소스에 접근 할 수 있는 thread 수를 제어
        - 구성
            - P : 검사(임계영역에 들어갈 때), lock.acquire()
                - S값이 1이상이면, 임게영역 진입 후 S값 1차감(S값이 0이면 대기)
            - V : 증가(임계영역에서 나올 때), lock.release()
                - S값에 1을 더하고, 임계영역을 나옴
            - S : 세마포어값(초기 값만큼 여러 프로세스가 동시에 임계영역에 접근 가능)
        - busy waiting : 임계영역에 들어가기 위해 반복문 수행
            - 대기큐 : 운영체제 기술로 보완. S가 0이하이면 대기큐에 넣고, V에서 큐에 있는 함수를 재실행

## Class38

- Deadlock(교착상태) : 무한대기상태, 두 개이상의 작업이 서로의 작업이 끝나기만을 기다리며 다음단계로 진행하지 못하는 상태, 아래 네 가지 조건이 모두 성립될 때 발생가능성이 있음
    - 상호배재(Mutual exclusion) : 프로세스들이 필요로 하는 자원에 대해 배타적인 통제권을 요구
    - 점유대기(Hold and wait) : 프로세스가 할당된 자원을 가진 상태에서 다른 자원을 기다림
    - 비선점(No preemption) : 프로세스가 어떤 자원의 사용을 끝낼 때가지 그 자원을 뺏을 수 없음
    - 순환대기(Circular wait) : 각 프로세스는 순환적으로 다음 프로세스가 요구하는 자원을가지고 있음
- Starvation(기아상태) : 특정 프로세스의 우선순위가 낮아서 원하는 자원을 계속 할당 받지 못하는  상태

## Class39-41

- Virtual Memory System
    - virtual address : 프로세스가 참조하는 주소
    - physical address : 실제 메모리 주소
    - MMU(Memory Management Unit) : 가상 주소를 물리 주소값으로 변환해주는 하드웨어 장치
- Paging system
    - 크기가 동일한 페이지로 가상 주소 공간과 매칭되는 물리 주소 공간을 관리
    - 하드웨어 지원이 필요, ex> Intel 32bit에서는 4KB, 2MB, 1GB지원
    - 리눅스는 4KB로 paging
    - 페이지 번호를 기반으로 가상-물리 매핑 정보를 기록/사용
    - 프로세스의 PCB에 Page Table 구조체를 가리키는 주소가 들어있음
    - Page Table
        - 가상 주소와 물리 주소간 매핑 정보가 있음
        - valid-invalid bit이 실제로 물리 메모리에 데이터가 올라가 있는지 표시함
    - 프로세스 구동시, 해당 page table base 주소가 CR3 레지스터에 저장됨
    - 가상 주소 v = (p, d)
        - p : 가상 메모리 페이지
        - d : p안에서 참조하는 위치(offset)
    - 프로세스간 동일한 물리 주소를 가리킬 수도 있음
- 다중 단계 페이징 시스템 : 페이징 정보를 단계를 나누어 생성, 리눅스는 4단계
- TLB(Translation Lookaside Buffer) : 최근의 가상-물리 주소 매핑값을 저장하는 캐쉬

## Class42

- 선행페이징(anticipatory paging, prepaging) : 미리 프로세스 관련 모든 데이터를 메모리에 올려놓고 실행하는 개념
- 요구페이징(demand paging, demended paging) : 실행 중 필요한 시점에서만 데이터를 메모리로 적재, 더 이상 필요하지 않은 페이지 프레임은 다시 저장매체에 저장
- page fault : 어떤 페이지가 실제 물리 메모리에 없을 때 일어나는 interrupt, 운영체제는 page fault가 발생하면 해당 페이지를 물리 메모리에 올림

## Class43

- page replacement policy
    - FIFO Page Replacement Algorithm
    - OPT(OPTimal Repalcement Algorithm)
        - 앞으로 가장 오랫동안 사용하지 않을 페이지를 내림
        - 일반 OS에서는 구현 불가
    - LRU(Least Recetly Used) Page Replacement Algorithm
        - 가장 오래 전에 사용된 페이지를 교체
    - LFU(Least Frequently Used) Page Replacement Algorithm
        - 가장 적게 사용된 페이지를 교체
    - NUR(Not Used Recently) Page Replacement Algorithm
        - 최근에 사용하지 않은 페이지부터 교체
        - 각 페이지마다 참조비트(R), 수정비트(M)을 둠 (R,M)
            - (0,0),(0,1),(1,0),(1,1) 순으로 교체
- Thrashing
    - 반복적으로 page fault가 발생해서 과도하게 페이지 교체 작업이 일어나 실제로는 아무일도 하지 못하는 상황

## Class44-45

- Segmentation
    - 가상 메모리를 서로 크기가 다른 논리적 단위인 Segment로 분할
        - ex> x86 realmode : CS(Code Segemnt), DS(Data Segment), SS(Stack Segment), ES(Extra Segment)로 segment를 나누어 메모리 접근

## Class46-47

- file system : 운영체제가 저장매체에 파일을 쓰기 위한 자료구조 또는 알고리즘
    - 보통 4kb크기의 block로 관리
    - 블록 체인 : block을 linked list로 연결, 끝에 있는 블록을 찾으려면 처음 블록부터 주소를 따라가야 함
    - 인덱스 블록 기법 : 각 block에 대한 위치 정보를 기록해서, 한 번에 끝 block를 찾아갈 수 있도록 함
    - Windows : FAT, FAT32, NTFS
        - 블록 위치를 FAT이라는 자료 구조에 기록
    - LINUX : ext2, ext3, ext4
        - 인덱스 블록 기법인 inode 방식 사용
- inode file system
    - 기본구조
        - super block : 파일 시스템 정보 및 파티션 정보 포함
        - inode block : 파일 상세 정보
        - data block : 실제 데이터
    - 파일 : inode 고유값과 자료구조에 의해 주요 정보 관리
        - 'filename:inode'로 파일이름을 inode번호와 매칭
        - inode를 기반으로 파일 엑세스
    - 탐색 : 각 directory entry(dentry)를 탐색, 각 entry는 해당 디렉토리 파일/디렉토리 정보를 가지고 있음
        - ex> ```/home/ubuntu/link.txt``` : '/' dentry에서 'home'을 찾고, 'home'에서 'ubuntu'를 찾고, 'ubuntu'에서 'link.txt'파일이름에 해당하는 inode를 얻음
- VFS(Virtual File System) : Network등 다양한 기기도 동일한 파일 시스템 인터페이스를 통해 관리 가능

## Class48

- Boot : 컴퓨터를 켜서 동작시키는 절치
    - Boot program : OS kernel을 storage에서 특정 주소의 물리 메모리로 복사하고 kernel의 처음 실행위치로 PC를 가져다 놓는 프로그램
    - CPU -> ROM-BIOS로 이동 -> RAM에 BIOS코드 로드 -> 저장매체의 MBR의 부트로더 로드 -> 저장매체의 부트섹터의 부트코드 로드 -> 저장매체의 OS이미지 로드

## Class49-50

- Virtual Machine
    - 하나의 하드웨어에 다수의 OS를 설치하고, 개별 컴퓨터처럼 동작하도록 하는 프로그램
    - 구분 1
        - Virtual Machine Type1(native or bare-metal)
            - Hypervisor or VMM이 Hardware에서 직접 구동, ex> Xen, KVM(AWS에서도 사용)
            - Hypervisor or VMM(Virtual Machine Monitor) : 운영체제와 응용프로그램을 물리적 하드웨어에서 분리하는 프로세스
        - Virtual Machine Type2
            - Hypervisor or VMM이 Host OS 상위에 설치됨, ex> VMWare, Parallels Desktop
    - 구분 2
        - Full Virtualization
            - 각 가상머신이 hypervisor를 통해서 하드웨어와 통신
            - 가상머신은 자신이 가성머신상태인지 모름
        - Half Virtualization
            - 각 가상머신이 직접 하드웨어와 통신
            - 가상머신의 OS는 가성머신임을 인지하고 각 명령어 hypervisor명령을 추가해서 하드웨어와 통신
            - VMM은 각 가상머신의 리소스를 관리함
        - 최근 HW 성능개선으로 전가상화 기술을 선호
- Docker
    - virtual machine은 하드웨어를 가상화(하드웨어 전체를 추상화)
    - docker는 운영체제 레벨에서 별도로 분리된 실행환경을 제공(커널 추상화)
    - 리눅스 컨테이너 기술 기반
- Java Virtual Machine
    - 가상 머신과는 다르게 응용프로그램 레벨의 가상화
    - Java compiler가 생성한 CPU dependency를 가지지 않는 bytecode를 JVM에서 실행함