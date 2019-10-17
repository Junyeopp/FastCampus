NOTE for Architecture
=====

![capture](/img/cap1.PNG)

## Class1

- 튜링 동치 : 컴퓨터 P, Q가 있을 때, P가 할 수 있는 일을 Q가 모두 할 수 있고 Q가 할 수 있는 일을 P가 흉내낼 수 있다면 두 컴퓨터를 튜링 동치라고 한다
- 튜링 완정성 : 컴퓨터 P와 튜링 머신이 튜링 동치라면 P는 튜링 완전하다고 한다

## Class2

- 컴퓨터 구조 분야의 8가지 아이디어
    - 무어의 법칙
    - 설계를 단순화 하는 추상화
    - Common case fast
    - 병렬성을 통한 성능 개선
    - 파이프라이닝을 통한 성능 개선
    - 예측을 통한 성능 개선
    - 메모리 계층구조
    - 여유분을 이용한 신용도 개선

## Class3-4

- 프로세서
    - CU(Control Unit) : 명령어를 순서대로 실행할 수 있도록 제어
    - Register
    - ALU(Arithmetic/Logic Unit)

## Class5

- Clock : 하드웨어 이벤트가 발생하는 시점을 결정
    - Clock cycle : clock의 시간 간격
    - CPI : Clock cycle Per Instruction, 명령어 하나의 실행에 필요한 평균 클럭 사이클 수

## Class6

- 트랜지스터가 0-1을 스위칭 하는 동안 전력을 소비함
- 전압을 낮추면 트랜지스터 누설 전류가 커짐

## Class7

- 80386 CPU : 32bit 아키텍쳐 최초의 CPU, 1클럭당 최대 32bit처리 가능
- 펜티엄 : 슈퍼스칼라 아키텍쳐(파이프라인 2개)
- 코어2 : 멀티코어 프로세서
- 암달의 법칙
- 하이퍼 쓰레딩

## Class8

- Instruction Pointer
    - 현재 실행되고 있는 프로그램의 실행코드가 저장된 메모리의 주소를 가르키는 상태 레지스터
    - 직접접근이 불가능한 레지스터
- Instruction Set Architecture
    - 프로세서가 인식해서 기능을 이해하고 실행할 수 있는 기계어
    - 1대1 대응되는 어셈블리어로 표현가능
    - MIPS, ARM, x86, RISC-V 등
    - 설계할 때 연산의 종류, 데이터 형식, 명령어 형식, 피연산자를 위한 주소지정방식을 고려해야 한다
- 명령어
    - 실행코드(opcode)와 피연산자(operand)로 구성됨

## Class9

- 산술연산 : 사칙연산의 계산을 하는 것
- MIPS 산술명령어
    - 반드시 한 종류의 연산만 지시
    - 항상 변수 세 개를 가짐(간단하게 설계하기 위해서 규칙적으로 함)
- MIPS 레지스터
    - 연산을 위해 MIPS 명령어구조에서 제공하는 레지스터
    - zero : 항상 0을 출력하는 레지스터
    - v : 함수로부터 반환된 값을 저장하는 레지스터
    - t,s : 값을 저장하는 레지스터
    - gp : 전역 포인터의 값을 저장하는 레지스터
    - sp : 스택 포인터의 값을 저장하는 레지스터
    - fp : 프레임 포인터의 값을 저장하는 레지스터
    - ra : 주소 반환값을 저장하는 레지스터
- 스택프레임
    - 함수가 실행될 때마다 자신만의 고유한 stack영역을  가질 수 있음
    - 함수의 스택프레임 시작점은 fp 레지스터가가르킴
    - 함수 종료시 해제되고 리턴 주소로 복귀함

## Class10

- operand(피연산자) : 연산을 하기 위해 사용되는 레지스터, 상수, 레이블, 메모리주소 등을 뜻함
    - 데이터 단위 : word(32bit), half word(16bit), byte(8bit)
- MIPS 명령어 및 레지스터는 32bit(4byte)로 구성되어 있음
- 구조체, 배열과 같은 자료형은 메모리(Heap,Stack)에 저장 후 주소에 접근해서 사용
    - Heap은 동적으로 할당되는 변수에 사용되고, Stack은 정적으로 할당되는 변수에 사용됨
- Data Transfer Instruction : 메모리와 레지스터간 데이터를 주고받는 명령어
    - 적재(Load) 명령어
        - 메모리에서 레지스터로 데이터를 복사해 오는 데이터 전송 명령어
        - 연산자(lw(load word)) + 값을 저장할 레지스터 + 메모리 접근에 사용할 상수 및 레지스터로 구성됨 ex> ```lw $t0, 4($s3)```
            - 상수부분 (4)를 offset이라고 함
            - 자료구조의 시작주소를 가르키는 레지스터 ($s3)을 Base register라고 함
            - MIPS에서 시작주소는 항상 4의 배수여야 함(정렬 제약)
    - 저장(Store) 명령어
        - 레지스터에서 메모리로 데이터를 보내는 명령
        - 연산자(sw(store word)) + 저장할 데이터를 가진 레지스터 + 메모리 주소 레지스터 및 상수(offset)로 구성됨
- 수치연산
    - 연산에서 레지스터가 아닌 상수를 사용하는 경우
    - 상수 필드를 갖는 산술 명령어 사용시 더 효율적(Common case fast) ex> ```addi```

## Class11

- MSB가 1이면(음수) 2의 보수를 취해서 값을 알 수 있음
- 캐리 : 오버플로우는 아니면서 MSB에서 자리올림이 발생한 경우, 2의 보수연산에서는 이를 무시함

## Class12

- 레지스터가 명령어에서 참조되기 때문에 레지스터이름을 숫자로 매핑하는 규칙이 존재함
- 어셈블리어의 기계어 변환
    - 명령어의 각 부분을 field라고 함
    - 각 field는 이름이 존재함
        - op : 명령어가 실행할 연산의 종류, 연산자(opcode)라고 함, 6bit
        - rs : 첫번째 source operand 레지스터, 5bit
        - rt : 두번째 source operand 레지스터, 5bit
        - rd : Destination 레지스터, 연산결과 기억, 5bit
        - shamt : shift amount, 5bit
        - funct : opcode의 구체적인 종류 지정, 6bit
    - field로 구성한 형식을 명령어 형식이라고 함
    - 기계어는 보통 16진수를 사용하여 표현함
    - R타입 : 오른쪽 절반 field가 3개일 경우
    - I타입 : 오른쪽 절반 field가 1개일 경우
    - address : 16bit 주소

## Class13

- 논리명령어
    - 논리연산을 하기위한 명령어
    - bit를 word로 묶는 packing, word를 bit로 나누는 unpacking 작업을 수행
    - sll(shift left logical) : ```<<```, bit를 왼쪽으로 이동
    - srl(shift right logical) : ```>>```, bit를 오른쪽으로 이동
        - 지정된 bit를 넘기면 최하위 bit은 버려짐
    - and, andi : ```&```
    - or, ori : ```|```
    - nor : ```~```

## Class14

- beq(branch if equal)
- bne(branch if not equal)
- j : jump
- loop
- slt(set less than)
- slti(set less than immediate)
- sltu(set less than unsigned)
- sltiu(set less than immediate unsigned)

## Class15

- Procedure
    - 제공되는 인수(parameter)에 따라 특정작업을 수행하는 서브루틴
    - parameter는 procedure에 값을 보내고 결과를 받아옴
    - 관련 레지스터
        - a : 전달할 인수를 가지고 있는 레지스터
        - v : 반환되는 값을 가지고 있는 레지스터
        - ra : return address 를 가지고 있는 레지스터
        - pc(program counter) : 현재 수행 중인 명령어의 주소를 기억하는 레지스터, ra에는 pc+4의 값이 저장됨
    - jal(jump-and-link) : 복귀주소를 ra에 저장하고 프로시저가 할당된 주소로 점프하는 명령어
    - jr(jump register) : ra주소로 복귀할 때 사용하는 명령어
- stack
    - 레지스터가 부족한 경우 사용, 정적인 변수에 활용
    - sp(stack point) register : push, pop에 따라 변경됨
    - 높은 주소에서 낮은 주소로 생성됨, sp에서 값을 감소시키면서 할당함.
    - stack frame
        - 각 프로시저가 저장된 레지스터와 지역변수를 가지고 있는 독립된 스택영역
        - fp(frame pointer)는 procedure의 첫 번째 word를 가리킴
        - fp는 base register의 역할을 하고 sp는 값이 변경되며 stack의 최하단을 가리킴
        - 재귀호출 등에서 ra값이 변경될 여지가 있으므로 복귀주소 저장수단으로 stack frame을 사용함
- segment
    - 메모리는 각각 다른 값을 저장하는 블록으로 나누어져 있음
    - stack : 지역변수 선언, 정적할당, 프로그램 종료시 자동소멸
    - heap : 동적할당, 해제를 해줘야 함
    - data : 전역변수
    - text : mips 기계어
    - Segmentation Fault : 참조할 수 없는 메모리영역을 참조했을 때 나오는 에러

## Class16-17

- MIPS 주소지정 방식
    - 수치 주소지정 : 피연산자는 명령어 내에 있는 상수. immediate(16bit) 등
    - 레지스터 주소지정 : 피연산자는 레지스터
    - 베이스 레지스터 주소지정 : 메모리 주소는 베이스 레지스터 값 + 주소 필드의 offset. lw, sw 등
    - PC 상대 주소지정 : PC값 + 명령어 내 상수. 조건부 분기명령에 사용됨
    - 의사직접 주소지정 : 명령어 내의 26비트를 PC의 상위 비트들과 연접하여 점프주소를 구함. 무조건 분기문에서 주로 사용
- 32bit 상수 operand
    - MIPS는 레지스터를 16bit씩 나누어 상수를 저장할 수 있음
    - lui(load upper immediate) : 레지스터 상위 16bit에 상수를 저장

## Class18

- 곱셈
    - 피승수(multiplicand)
    - 승수(multiplier)
    - 곱(product) : 곱셈의 결과 값
    - MIPS에서는 곱셈의 overflow 방지를 위해 32bit 레지스터 2개(총 64bit)을 지원
- 나눗셈
    - 피제수(dividend)
    - 제수(divisor)
    - 몫(quotient)
    - 나머지(remainder)

## Class19

- 소수
    - fixed point(고정소수점)
        - 고정된 자리수의 소수를 표현
        - 밑수와 지수값을 미리 결정해두고 사용
        - 정수 자료형에 대해서는 연산이 빠름
        - 정밀도가 부족
    - floating point(부동소수점)
        - 부호, 가수, 밑수, 지수로 표현. ex> 132.12234 -> 0.13212234 * 10^3
        - 단정밀도(32bit) 표현 : sign 1bit, exponent 8bit, fraction 23bit
            - IEEE 754 Normalized form : N = (-1)^s 2^(e-127)
            - bias : 127, exponent bit에는 sign bit이 없기 때문에 bias를 사용
        - 64bit 표현 : sign 1bit, exponent 11bit, fraction 52bit
            - bias : 1023

## Class20-21

- 논리회로
    - bool 대수를 물리적 장치에 구현한 것
    - 하나 이상의 논리적 입력값에 대해 연산을 수행하고 하나의 논리적 출력값을 얻는 전자회로
    - 조합회로
        - 입력 신호만으로 출력이 결정되는 회로.
        - AND, NOT, OR, XOR, etc
        - MUX(멀티플렉서) : 입력 신호 중 하나를 선택하여 출력하는 회로
        - DEMUX(디멀티플렉서) : 한 개의 입력신호에 대하여 다수의 데이터 출력선 중 하나를 선택하는 회로, ALU에서 사용
        - Adder(가산기) : 2진수의 덧셈 연산을 수행하는 논리회로
    - 순차회로

## Class22

- 컴파일 과정 : Compiler -> Assembler -> Linker -> Loader -> Memory
- -> 명령어 인출 과정(Instruction fetch) : Memory -> PC -> MAR -> MDR -> CIR
- -> 명령어 해독 과정(Instruction decode) : CIR -> Decoder -> CU(Control Unit)
- -> 명령어 실행 과정(Instruction execute) : CU -> AC(Accumulator) or ALU or MAR 등을 실행

## Class23

- Data pass : 명령어가 프로세서로 가는 통로. 조합소자와 상태소자로 이루어져있음
    - 조합소자 : 같은 입력이 주어지면 항상 같은 출력을 내는 소자
    - 상태소자 : 메모리, 레지스터와 같이 상태를 기억하는 소자

## Class24

- Pipelining
    - 여러 명령어가 중첩되어 실행되는 구현기술
    - 한 데이터 처리단계의 출력이 다음 단계의 입력으로 이어지는 구조
    - 여러 단계가 병렬적으로 수행될 수 있어 효율성이 향상됨
- Hazard
    - 다음 명령어가 다음 클럭 사이클에 실핼될 수 없는 상황, Pipelining에서 지연을 stall이라고 함
    - 구조적 해저드 : 클럭 사이클에 실행하기를 원하는 명령어의 조합을 하드웨어가 지원할 수 없는 상황
    - 데이터 해저드 : 어떤 단계가 다른 단계가 끝나기를 기다려야 하기 때문에 지연이 생기는 경우, 필요한 데이터가 아직 준비되지 않아서 계획된 명령어가 적절한 클럭사이클 시간에 실행될 수 없는 사건
    - 제어 해저드 : 명령어의 주소 흐름이 파이프라인이 기대한 것과 달라서 발생, 주로 brunch나 jump에 의해 발생
    - 해결방안
        - 전방전달(forwarding) : 프로그래머가 확인할 수 있는 레지스터나 메모리에 아직 나타나지 않은 데이터를 기다리기보다 내부 버퍼(ALU 등)로 부터 먼저 가져옴
        - 분기예측(branch prediction) : 조건문이 분기할 것인지 예측하는 CPU기법(현재 성공률 90%이상), 예측대로 명령어를 진행하다가 만약 예측이 틀리면 버리는 방법

## Class25-26

- 메모리 계층구조
    - 서로 다른 속도와 크기를 갖는 여러 계층의 메모리로 구성. 지역성의 원칙
    - 지역성
        - 시간적 지역성(temporal locality) : 참조된 항목은 다시 참조된 가능성이 높음
        - 공간적 지역성(spatial locality) : 참조된 항목 주위에 데이터가 참조될 가능성이 높음
- SRAM
    - 읽고 쓰기 위한 포트가 하나 있는 메모리 배열
    - 어떤 데이터이든지 접근시간이 같음
    - 보통 CPU에 직접연결
- DRAM
    - 한 종류로 정보를 구성하는 개개의 비트를 각기 분리된 Capacitor에 저장
    - Capacitor에 전하를 누전하므로 무한한 저장 불가
    - 주기적인 재생과정(저장된 값을 읽고 다시 쓰는 과정)이 필수적
- Cache Memory
    - SRAM으로 구성
    - 프로세서가 기억장치를 참조할 필요가 있을 경우 Cache를 가장 먼저 조사
    - 검사에 실패(Miss)하면 주기억 장치로부터 정보를 Cache에 저장하고 다시 Cache에서 CPU로 정보를 전송
    - 사상함수 : 주기억 장치와 Cache 사이에 정보를 옮기는 방법
        - 직접사상 : 주소값을 활용하여 Cache block의 특정 라인에만 적재
        - 연관사상 : Cache 아무 라인에나 적재가능
        - 집합 연관사상 : 직접사상 + 연관사상