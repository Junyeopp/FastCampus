NOTE for C/C++/Algorithm
=====

![capture](/img/cap1.PNG)

## Class1

- C++는 C를 포함하고 있어서 C++ 프로젝트 생성해서 확장자만 ```'.c'```로 바꿔주면 C로 사용 가능.

- 만들어진 프로그램을 실행가능한 형태로 내보내기 위해서는 솔루션 빌드를 해줘야함. 그러면 '.exe' 실행파일이 만들어지고 실행할 수 있음.

## Class2

- 정적변수로 선언된 변수는 기본적으로 0으로 값이 초기화됨.
- 정적변수는 ```main```함수 밖에 전역으로 설정된 변수를 말하는 것 같음.
- 음수표현법 :
    1. 부호 절대값 방식 : 가장 왼쪽 비트를 부호비트로 사용.
    2. 2의 보수 : 1의 보수 + 1.
- 실수표현법 : 부호, 지수, 유효숫자를 나누어서 표현.

## Class3

- ```scanf```를 warning없이 사용하기 위해서 ```#define _CRT_SECURE_NO_WARNINGS```를 적용한다.
- 입력받은 것을 한 자리씩 끊어서 받기 : ```scanf("%1d%1d%1d", &a, &b, &c");```

## Class4

- Escape Sequence 중 ```\b``` : 백 스페이스 넣기
- 삼항연산자 : 조건 ? 참일 때 실행 : 거짓일 때 실행
    - ex) ```(a==b) ? 100 : -100```
- 비트연산자 : ```>>``` 은 Shift 연산자로 2의 배수를 처리할 때 효과적

## Class5

- ```switch```문 : 조건에 부합하는 경우 아래쪽의 case도 모두 만족시킨다. 그래서 일반적인 경우 case문의 마지막에 ```break```를 넣어 특정부분만 실행하도록 한다.

## Class6

- 내부적으로 ```for``` 문과 ```while``` 문은 동일하게 작동함.

## Class8

- 배열 초기화 할 때 ```{0,}``` 로 쓰면 전체를 0으로 초기화 할 수 있다.
- ```INT_MIN``` : ```<limit.h>```에 있는 ```int```형 범위의 가장 작은 정수로 약 -20억.
- C언어에서 기본적으로 문자열 자료형을 제공하지않고 문자를 묶은 형태로 문자열을 표현.
- 문자열을 입력, 출력할 때는 ```%s``` 형식지정자를 사용.
- C++에서는 자체적으로 ```string``` 자료형을 제공.

## Class9

- 포인터는 메모리 주소를 저장하는 변수.
- 배열과 포인터는 내부적으로 동일하게 작동한다고 볼 수 있음.
- 배열을 선언한 이후에는 그 이름 자체가 포인터 변수와 동일함.

## Class10

- C언어에서 문자는 내부적으로 아스키 코드 구조를 따름.
- ```getchar()``` : ```<stdio.h>```에 있는 문자를 하나 입력받는 표준입력.
- <pre><code>int main(void) {
    int a;
    char c;
    scanf("%d", &a);
    printf("%d\n", a);
    scanf("%c", &c);
    printf("%c\n", c);
    return 0;
    }
</code></pre>
에서 ```100\n```을 입력하면 오류가 남. ```100```은 ```a```로 ```\n```은 ```b```로 입력됨.
- 이를 해결하기 위해서 첫번째 ```scanf```이후 남아있는 입력버퍼를 지워야 함.
<pre><code>int main(void) {
    int a;
    char c;
    scanf("%d", &a);
    printf("%d\n", a);
    int temp;
    while ((temp = getchar()) != EOF && temp != '\n'){}
    scanf("%c", &c);
    printf("%c\n", c);
    return 0;
    }</code></pre>

## Class11

- 문자열은 컴퓨터 메모리 구조상에서 마지막에 NULL 값을 포함. NULL은 문자열의 끝을 알리는 목적.
- <pre><code>int main(void){
    char *a = "Hello World";
    printf("%s\n", a);
    return 0;
    }</code></pre>
    - 문자열 형태로 포인터를 사용하면 포인터에 특정한 문자열의 주소를 넣음.
    - 이런 문자열을 문자열 리터럴이라고 하고 문자열을 읽기전용(수정불가)로 메모리에 넣음.
- ```scanf()``` : 공백을 만날 때까지 입력받음.
- ```gets()``` : 공백까지 포함하여 한 줄을 입력받음.
- ```gets_s()``` : 보안상의 이유로 사용. 버퍼의 크기를 지키도록 함.
- ```strstr()``` : 긴 문자열에서 짧은 문자열을 찾아 그 위치를 반환. 주소 값 자체를 반환함으로 단순히 출력하면 그 지점 이후 모든 문자열이 반환됨.

## Class12

- 일반적인 OS는 메모리 공간을 네 가지로 구분함.
    - 코드 영역 : 소스코드
    - 데이터 영역 : 전역변수, 정적변수
    - 힙 영역 : 동적할당변수
    - 스택 영역 : 지역변수, 매개변수
- 전역변수 : 프로그램이 실행될 때 메모리에 할당되어 프로그램이 종료되면 메모리에서 해제.
- 지역변수 : 특정 블록에서만 접근가능. 함수가 실행될 때 메모리에 할당되어 함수가 종료되면 메모리에서 해제.
- 정적변수(Static Variable) : 특정 블록에서만 접근가능. 프로그램이 실행될 때 메모리에 할당되어 프로그램이 종료되면 메모리에서 해제.
- 레지스터변수(Register Variable) : 메인 메모리 대신 CPU 레지스터를 사용하는 변수. 실제로 레지스터에서 처리할지는 컴파일러가 결정.

## Class13

- 배열과 포인터의 차이점 : 포인터는 변수이며 배열의 이름은 상수이다. 그래서 다음과 같이 상수의 값을 변경할 수 없다.
    <pre><code>int a = 10;
    int b[10];
    b = &a;</code></pre>
- 포인터는 연산을 통해 자료형의 크기만큼 이동한다.

## Class14

- 스택에 선언된 변수는 따로 메모리 해제를 해주지 않아도 되지만, 동적으로 할당된 변수는 ```free()``` 로 메모리 해제를 해주어야 한다.
- 동적으로 문자열 처리하기 : ```<string.h>```에 있는 ```memset()```사용.

## Class15

- 함수 포인터 : C에서는 함수의 이름을 이용해 특정한 함수를 호출함. 함수의 이름은 메모리 주소를 반환. 특정한 함수의 반환 자료형을 지정하는 방식으로 선언할 수 있음.
    - 반환 자료형 (*이름)(매개변수) = 함수명;
    - <pre><code>int add(int a, int b) {
        return a + b;
        }
        int(*process(char* a))(int, int) {
            printf("%s\n", a);
            return add;
        }
        int main(void) {
            printf("%d\n", process("10 + 20")(10,20));
            return 0;
        }</code></pre>
    - <pre><code>int add(int a, int b) {
        return a + b;
        }
        int(*process(char* a))(int, int) {
            printf("%s\n", a);
            return add;
        }
        int main(void) {
            int(*fp)(int, int) = add;
            printf("%d\n", fp(10,3));
            return 0;
        }</code></pre>
    - 자주 사용되지는 않음.

## Class16

- 하나의 구조체 변수만 사용하는 경우 정의와 동시에 선언을 할 수도 있음. 이 경우 변수는 전역 변수로 사용됨.
- 익명 구조체의 개념이 있어서, 구조체의 이름 부분을 비워 놓아도 됨.
- ```typedef```를 이용해서 임의의 자료형을 만들 수 있음. 선언이 더 짧아짐.
- 구조체가 포인터 변수로 사용되는 경우 내부 변수에 접근할 때 ```->```을 사용함.

## Class17

- 파일 입출력 :
    - <pre><code>FILE *fp;
        fp = fopen(경로, 접근방식);
        //파일처리
        fclose(fp);</code></pre>

## Class18

- 전처리기
    - 전처리기 구문은 다른 프로그램 영역과 독립적으로 처리됨.
    - 전처리기 구문은 소스코드 파일 단위로 효력이 존재함.
    - 파일포함 전처리기 : ```#include <파일이름>```, ```#include "파일이름"```
    - 매크로 전처리기 : ```#define```
    - 조건부 컴파일 : ```#ifndef ~ #endif```
    - 파일 분할 컴파일

## Class19

- Time Complexity : 알고리즘에 사용되는 연산 횟수
- Space Complexity : 알고리즘에 사용되는 메모리의 양

## Class20

- 배열 기반 리스트
    - 특정 위치에 즉시 접근가능한 장점
    - 공간을 미리 메모리에 할당해야 하는 단점
    - 특정 위치로의 삽입이나 삭제가 비효율적
- 연결 리스트
    - 구조체와 포인터로 구현
    - 필요할 때마다 메모리 공간을 동적할당
    - 중간에 노드를 추가하거나 삭제 가능
    - 시작노드는 Head라고 하며 별도 관리함
    - 끝 노드의 다음 위치값은 NULL을 넣음
    - 특정 인덱스로 즉시 접근이 안됨
    - 추가적인 포인터 변수가 사용됨으로 메모리 공간을 소비함

## Class21

- 양방향 연결 리스트

## Class22

- stack

## Class23

- calculator with stack

## Class24

- queue

## Class25

- 선택 정렬 : 가장 작은 것을 선택해서 앞으로 보냄
    - 시간복잡도 : O(N^2)

- 삽입 정렬 : 각 숫자를 적절한 위치에 삽입함
    - 시간복잡도 : O(N^2)

## Class26

- 퀵 정렬 : 피벗을 기준으로 큰 값과 작은 값을 서로 교체
    - 시간복잡도 : 평균적으로 theta(N log N) (반 나누게 되면 log N이 됨) 편향된 분할이 발생할 때는 O(N^2)
    - 실제 정렬할 때는 C++의 Algorithm 라이브러리를 이용해 O(N log N)을 보장하는 정렬을 한다.

## Class27

- 계수 정렬 : 크기를 기준으로 데이터의 개수를 셈. 특정한 상황에서만 사용가능
    - 시간복잡도 : O(N)

## Class28

- 기수 정렬 : 자릿수를 기준으로 차례대로 데이터를 정렬
    - 시간복잡도 : O(DN), D = 가장 큰 자릿수

## Class29
 
- 이진 트리 : 최대 2개의 자식을 가질 수 있는 트리
    - 포화 이진 트리 : 리프 노드를 제외한 모든 노드가 두 자식을 가지고 있는 노드
    - 완전 이진 트리 : 모든 노드가 왼쪽 자식부터 채워진 노드

## Class30

- 포인터로 이진 트리를 만들 수 있음
- 순회
    - 전위 순회 : 자기 출력 -> 왼쪽 자식 방문 -> 오른쪽 자식 방문
    - 중위 순회 : 왼쪽 자식 방문 -> 자기 출력 -> 오른쪽 자식 방문
    - 후위 순회 : 왼쪽 자식 방문 -> 오른쪽 자식 방문 -> 자기 출력
    
## Class31

- 우선순위 큐 : 데이터를 꺼낼 때 우선 순위가 높은 데이터가 가장 먼저 나옴. 트리구조로 볼 수 있음. 일반적으로 최대 힙을 이용해 구현
    - 삽입 : 완전 이진 트리를 유지하는 형태로 순차적으로 삽입 후 루트 노드까지 거슬러 올라가면서 최대 힙을 구성(log N)
    - 삭제 : 루트 노드를 삭제하고, 가장 마지막 원소를 루트 노드로 옮긴 후 리프 노드까지 내려가면서 최대 힙을 구성(log N)
- 최대 힙 : 부모 노드가 자식 노드보다 값이 큰 완전 이진 트리

## Class32

- Sequential Search
    - 시간복잡도 : O(n)
- Binary Search
    - 시간복잡도 : O(log N)

## Class33

- Graph
    - Adjacency Matrix
        - O(V^2)의 공간을 요구, 공간 효율성이 떨어짐
        - 연결확인에 O(1)의 시간을 요구
    - Adjacency List 
        - O(E),의 공간을 요구
        - 연결확인에 O(V)의 시간을 요구

## Class34

- Depth First Search
    - stack
    - 탐색에 O(N)의 시간이 걸림

## Class35

- Breadth First Search
    - queue
    - queue STL을 이용해 구현
    - 탐색에 O(N)의 시간이 걸림
    - 일반적으로 DFS보다 좋은 편

## Class36

- Binary Search Tree
    - Binary Search가 항상 동작하도록 구현해서 탐색 속도를 극대화 시킨 자료구조
    - 이진 탐색 트리에서는 항상 부모 노드가 왼쪽 자식보다는 크고, 오른쪽 자식보다는 작음
    - Complete Binary Tree인 경우 탐색시간이 O(log N)
    - Skewed Binary Tree인 경우 탐색시간이 O(N)

## Class37

- AVL Tree
    - Binary Tree가 Complete Binary Tree에 가까운 형태를 유지할 수 있게 해줌
    - Balance Factor = ```abs(Left child height - Right child height)```
    - 모든 node의 balance factor가 +1, 0, -1인 Tree, 범위를 벗어나면 Rotation을 통해 Tree를 재구성함(LL, LR, RR, RL)
    - 균형잡기는 각 노드가 삽입될 때마다 수행되어야 함. 삽입의 시간복잡도는 O(log N), 삽입시에 거치는 모든 노드에 대해 수행되는 균형잡기는 O(1)의 시간복잡도
    - 탐색에 있어서 O(log N)을 유지할 수 있음

## Class38

- Hash
    - 데이터를 최대한 빠른 속도로 관리하도록 해주는 자료구조
    - 메모리 공간을 많이 소모하지만 처리가 빠름
    - 데이터베이스 등에 사용됨
    - Value를 찾을 때 Key로 O(1)만에 접근할 수 있음
    - Key가 중복되는 경우 Collision이 발생했다고 표현함
        - 충돌을 발생시키는 항목을 해시테이블의 다른 위치에 저장
            - Linear probing : hash table의 충돌이 발생한 key에 1을 더한 key에 value을 저장함
                - 충돌이 발생하기 시작하면 유사한 값을 갖는 데이터끼리 서로 밀집되는 집중 결합 문제가 존재함, 물론 hash table의 크기가 비약적으로 크면 충돌이 적게 발생함
            - Quadratic probing : 선형조사법에서 키 값을 선택할 때 완전 제곱수를 더해 나가는 방식
            - Double hasing
        - 해시테이블의 하나의 bucket에 여러 개의 항목을 저장
            - Chaining : 연결 리스트를 활용해 특정한 key를 가지는 항목들을 연결하여 저장
                - 연결 리스트를 사용해서 삽입과 삭제가 용이함
                - 테이블 크기 재설정은 동적 할당을 이용함, 동적 할당을 위한 추가적인 메모리 공간이 소모됨
    - Division Method가 가장 많이 활용됨
        - 입력 값을 테이블의 크기로 나눈 나머지를 key로 이용하는 방식
        - 테이블의 크기는 Prime number가 효율성이 높음
        
## Class39

- MST(Minimum Spanning Tree)
    - spanning tree : 특정한 그래프에서 모든 정점을 포함하는 그래프
    - MST : spanning tree 중에서 간선의 가중치 합이 가장 작은 트리
- Prim's Algorithm
    - algorithm
        1. 그래프에서 정점 하나를 선택해 트리 T에 포함시킴
        2. T에 포함된 노드와 포함되지 않은 노드 사이의 간선 중 가중치가 가장 작은 간선을 찾음
        3. 해당 간선에 연결된 T에 포함되지 않은 노드를 T에 포함시킴
        4. 2-3을 반복
        - 각 간선에 대한 정보를 우선순위 큐에 담아 처리함
    - O(E logV)의 시간 복잡도를 가짐(모든 간선에 대한 정보를 queue에 넣어서 처리 : E, queue에서 꺼낼 때 : logV)

## Class40

- Dijkstra's Shortest Path Algorhtim
    - 동작원리가 prim과 유사
    - 음의 간선이 없을 때 정상적으로 작동
    - algorithm
        1. 그래프의 시작점을 선택해서 tree T에 포함
        2. T에 포함된 노드와 T에 포함되지 않은 노드 사이의 간선 중 이동거리가 가장 작은 간선을 찾음
        3. 해당 간선에 연결된 T에 포함되지 않은 노드를 T에 포함시킴
        4. 2-3을 반복
    - O(E logV)의 시간 복잡도를 가짐

## Class41

- Segment Tree
    - 구간 합 트리
    - 합 계산 및 원소 수정은 O(log N)의 시간복잡도를 가짐

## Class42

- Index Tree
    - Segment Tree에 비해 구현이 간단하고 메모리 효율성이 높음
    - O(log N) 시간복잡도
    - 특정 숫자 A의 마지막 비트를 구할 때는 A & -A를 구하면 됨
    - 각 인덱스에 대해 마지막 비트를 내가 저장하고 있는 값들의 개수로 계산함
    - 마지막 비트만큼 구간을 앞으로 이동하며 합을 구하면 됨

## Class43

- 단순 비교 string matching
    - O(NM) 시간복잡도
- KMP string matching
    - O(N+M) 시간복잡도

## Class44

- Rabin-Karp string matching
    - ASCII code 기반의 hash function을 이용해 특정한 string에 대한 hash value를 구함
    - 각 문자의 ASCII code value에 2의 제곱 수를 차례대로 곱해서 더한 값을 구함
    - hash function의 눈사태 효과를 활용
    - 평균적으로 O(N+M) 시간복잡도
    - 때로는 KMP보다 빠르지만 특정한 상황에서는 KMP보다 매우 느릴 수 있음

## Class45

- C, C++ 비교
    - C는 절차적 프로그래밍 언어, C++은 객체 지향 패러다임을 따름
    - C는 함수 기반의 언어, C++은 객체 중심의 언어
    - C++은 C의 Struct 대신 Class를 사용함
    - C++은 공식적으로 Exception Handling 기술을 지원함
- ```iostream``` : C++ 표준 입출력 라이브러리
- 형식지정자없이 입출력 가능
- ```<<```,```>>```
- Namespace : 특정한 영역에 이름을 설정할 수 있도록 하는 문법
- ```using```
- ```string```
    - ```to_string()```, ```stoi()```
- ```getline()``` : 공백을 포함하여 한 줄을 모두 문자열 형태로 입력받을 때

## Class46

- Class : C의 struct와 유사하게 동작하지만 내부적으로 함수 등을 포함할 수 있음
    - Inheritance 개념을 이용할 수 있다는 점에서 Object-Oriented Programming을 가능하게 하는 기본적인 단위임
- 객체 지향 프로그래밍
    - 추상화(Abstract)
    - 캡슐화(Encapsulation)
    - 상속성(Inheritance)
    - 정보 은닉(Data Hiding)
    - 다형성(Polymorphism)
- 멤버 변수를 속성 또는 Property라고 부름
- 멤버 함수를 Method라고 부름
- 클래스를 활용해 만든 변수를 Instance라고 부름
- 접근 한정자
    - public : 해당 객체를 사용하는 어떤 곳에서도 접근가능
    - private : 외부에서 해당 객체에 접근할 수 없음, class는 기본적으로 member를 private 형태로 간주함
- 클래스 내부에서 정의된 함수를 불러올 때는 멤버 참조 연산자 `.`을 사용
- ```this``` 포인터, 함수 내에서 인스턴스를 구분하기 위해 사용. 포인터 자료형인 상수로 값을 변경할 수 없음

## Class47

- 생성자(Constructor) : 객체를 생성하고 멤버 변수를 초기화함. 생성자는 특별한 method로 class의 이름과 동일한 이름의 method로 구현됨. 반환 값이 없음
    - Default Constructor : 별도로 생성자를 구현하지 않으면 사용됨. 매개 변수를 가지지 않고 멤버 변수는 0, NULL 등으로 초기화 됨.
    - Copy Constructor : 다른 instance의 Reference를 인수로 받아서 자신의 instance를 초기화함
- 소멸자(Destructor) : 객체의 수명이 끝났을 때 객체를 제거하는 목적. 수명이 끝나면 자동으로 컴파일러가 소멸자 함수를 호출함. 클래스의 이름과 동일하며 ```~```를 이용해 정의함

## Class48-49

- Inheritance : Child Class가 Parent Class의 속성을 물려 받아 사용할 수 있음
    - Child Class는 ```:```으로 Parent와 연결될 수 있음
    - child의 instance를 만들 때 parent의 constructor가 호출되고, 그 후에 child의 constructor가 호출됨. child의 수명이 다하면 child의 destructor가 호출되고 그 후에 parent의 destructor가 호출됨
    - Overriding : parent에서 정의된 함수를 무시하고 child에서 동일한 이름의 함수를 재정의하는 문법. 기존 함수와 동일한 매개변수를 전달받음
    - Multiple Inheritance : 여러 개의 클래스로부터 멤버를 상속 받는 것
    - Overloading : 동일한 이름의 멤버 함수를 다양한 방식으로 활용하기 위해 사용
        - 연산자 오버로딩
            - 기존에 존재하는 연산자만 정의가능
            - ```.```, ```::``` 등은 오버로딩 불가능
            - 기본적인 연산자 규칙을 따라야 함
            - 오버로딩이 된 연산자의 피연산자 중 하나는 사용자 정의 자료형이어야 함

## Class50

- Encapsulation 기법
    - Friend : 특정 객체의 멤버 함수가 아닌데 private 멤버에 접근해야할 때 사용. 기존의 함수 앞에 ```friend``` 키워드를 붙인 형태로 사용
        - friend class의 형태로 사용할 수도 있음
    - Static Member : 클래스에 포함되어 있는 멤버이지만 모든 객체가 공유하는 멤버. 메모리 상에 오직 하나만 할당되어 관리됨. public으로 선언하면 외부의 어떤 클래스에서도 접근가능함. 일반적으로 Singleton Pattrern 등의 기능을 위해서 사용됨
    - Constant Member : 호출된 객체의 데이터를 변경할 수 없는 멤버. 클래스에서 중요한 상수는 Constant Member로 정의해서 사용함

## Class51

- Polymorphism 기법
    - Abstract class
        - 하나 이상의 pure virtual function을 포함하는 class
    - child class에서 overriding에서 포인터 변수로 객체에 접근할 때는 예상치 못한 결과가 발생할 수 있음
        - C++ 컴파일러는 포인터 변수가 가리키고 있는 변수의 타입을 기준으로 변수를 호출하지 않고, 포인터의 타입을 기준으로 함수를 호출함. 따라서 A 객체를 가리키는 포인터 변수는 A 객체의 멤버만 호출할 수 있음
    - Virtual Function
        - child class에서 재정의할 수 있는 멤버 함수. ```virtual``` 키워드를 이용해 선언 가능. child class에서 재정의하면 재정의된 멤버 함수도 가상 함수로 분류됨. child class에서 재정의될 가능성이 있는 멤버 함수를 가상 함수로 선언
        - C++ Compiler는 Virtual Function Table을 이용해 가상 함수를 다루고 compiler는 각각의 객체마다 Virtual Function Table을 가리키는 포인터를 저장하기 위한 멤버를 하나씩 저장함.
        - Virtual Function Table에는 특정한 클래스의 객체들을 위해 선언된 가상 함수들의 주소가 저장됨. 가상 함수가 호출되면 table에서 자신이 필요한 함수의 주소를 찾아 호출함
        - 메모리 해제를 해야 하는 경우 반드시 parent의 destructor를 virtual function으로 선언해야 함, 그렇지 않으면 child의 destructor는 호출되지 않고 parent의 destructor만 호출되어 child 객체는 정상적으로 해제되지 않음
    - Pure Virtual Function
        - child에서 반드시 재정의해야하는 함수
        - ```=0```키워드로 선언가능
    - Binding : C++은 특정한 함수를 호출할 때 해당 함수의 루틴이 기록된 메모리 주소를 알아함. 코드에서 실제로 함수가 정의된 메모리 공간을 찾는 것을 말함
        - Static Binding : 일반적으로 함수의 호출은 컴파일 시기에 고정된 메모리 주소를 이용함.
        - Dynamic Binding : Virtual Function은 프로그램이 실행될 때 객체를 결정하기 때문에 컴파일 과정에서 객체를 특정할 수 없음. 이럴 때에 dynamic binding을 사용

## Class52

- Template
    - Generic Programming을 위해 사용
    - 매개변수의 타입에 따라서 함수 및 클래스를 쉽게 사용할 수 있게 해줌, 타입마다 별도의 함수나 클래스를 만들지 않아도 됨
    - Function Template
        - 각각의 자료형에 대해 처음 호출될 때, C++ compiler가 해당타입의 instance를  생성하고 그 instance는 해당 자료형에 대해 특수화되어 해당 함수 template에 해당 자료형이 사용될 때마다 호출됨
    - 명시적 특수화(Explicit Specialization)
        - 특정한 타입에 대해 특정한 기능을 정의할 수 있음
    - Class Template
        - default template factor

## Class53

- Smart Pointer
    - Memory Leak을 방어하기 위한 수단으로 포인터처럼 동작하는 Class Template
    - 기본적으로 heap영역에 동적 할당된 메모리를 해제하기 위해서는 delete를 사용하여야 한다.
    - ```unique_ptr``` : 하나의 스마트 포인터가 특정한 객체를 처리할 수 있도록 함
        - 특정한 객체의 소유권을 가지고 있을 때 소멸자가 객체 삭제 가능
        - ```move()``` : 소유권 이전
        - ```reset()``` : 메모리 할당 해제
    - ```shared_ptr``` : 특정한 개체를 참조하는 스마트 포인터가 총 몇 개인지를 참조
        - 특정한 객체를 새로운 스마트 포인터가 참조할 때마다 Reference Count가 1증가하며 스마트 포인터의 수명이 다할 때 1감소하여 0이 되면 delete로 메모리에서 데이터를 할당 해제한다
        - ```use_count()``` : reference count 반환
        - Scope를 벗어나면 자동으로 해제됨
    - ```weak_ptr``` : 하나 이상의 shared_ptr instance가 소유하는 객체에 대한 접근을 제공
        - shared_ptr 객체가 참조하고 있는 객체에 reference count 증가없이 접근할 수 있다
        - 순환참조(Circular Reference) 현상을 제거하기 위한 목적으로 사용됨
        - ```lock()``` : 소유하고 있는 객체 반환

## Class54

- C++ STL Container Adaptor
    - 기존 C언어로 구현하기 까다로웠던 다양한 자료구조들을 쉽게 이용할 수 있음
    - C++ Stack STL
        - ```push()``` : 원소 추가
        - ```pop()``` : 삭제
        - ```top()``` : 조회
        - ```empty()``` / ```size()``` : 검사
    - C++ Queue STL
        - ```push()``` : 원소 추가
        - ```pop()``` : 삭제
        - ```front()``` / ```back()``` : 조회
        - ```empty()``` / ```size()``` : 검사
    - C++ Priority Queue STL

## Class55

- C++ STL Sequnce Container
    - 기존 C언어로 구현하기 까다로웠던 다양한 자료구조들을 쉽게 이용할 수 있음
    - ```iterator```로 접근가능 
    - Vector
        - 뒤쪽에서만 데이터를 넣거나 뺄 수 있는 자료구조, 덱보다 일반적인 경우 성능적으로 더 효율적
        - ```push_back```
        - ```pop_back```
        - ```insert```
    - Deque
        - 양 끝에서 데이터를 넣거나 뺼 수 있는 자료구조
        - ```push_front``` : 덱의 앞에서 데이터를 삽입함
        - ```pop_front``` : 덱의 앞에서 데이터를 꺼냄
        - ```push_back``` : 덱의 뒤에서 데이터를 삽입함
        - ```pop_back``` : 덱의 뒤에서 데이터를 꺼냄
        - ```insert``` : 덱의 특정 위치에 데이터를 삽입함
        - ```empty()```, ```begin()```, ```clear()```, ```size()```
    - List
    - Forward List

## Class56

- C++ STL Associate Container
    - Key와 Value 형태의 데이터를 쌍으로 저장하는 컨테이너
    - ```iterator```로 접근가능
    - Set
        - 저장하는 데이터를 key로 사용하는 컨테이너
        - 정렬된 위치에 데이터를 삽입한다는 점에서 검색 속도가 빠름
        - 기본적으로 key의 중복을 허용하지 않음
        - ```begin()```, ```insert()```, ```end()```
    - Multi Set
    - Map
        - 저장하는 데이터를 key와 value 쌍의 형태로 사용하는 컨테이너
        - 정렬된 위치에 데이터를 삽입한다는 점에서 검색 속도가 빠름
        - 기본적으로 key의 중복을 허용하지 않음
        - hash 자료구조를 대신해 많이 사용됨
    - Multi Map

## Class57

- Exception Handling
    - Try-Catch 구문을 이용해서 수행
    - Try : 특정한 코드 블록에서 예외가 발생할 수 있음을 명시
    - Catch : 발생한 예외에 대해서 핸들러가 특정한 내용을 처리
    - Throw : try에서 발생한 오류를 전달

## Class58

- Socket programming
    - 두 개의 컴퓨터가 통신을 할 때 각 컴퓨터의 소켓을 통해서 데이터를 교환함
    - TCP(Transmission Control Protocol)
        - 연결형 프로토콜
        - UDP에 비해 속도는 느리지만 신뢰성 있는 데이터의 송수신을 보장
        - 경로 설정을 효과적으로 수행하기 위해 데이터를 여러 개의 Packet으로 나누어 송수신
    - UDP(User Datagram Protocol)
        - 비연결형 프로토콜
        - TCP에 비해 통신의 신뢰성이 부족하지만 빠른 데이터 송수신이 가능
        - 데이터를 주고 받기 전 사전 통신 절차를 거치지 않음
- Server & Client 구조
    - 가장 대표적인 네트워크 구성 모델, 모든 데이터의 관리 및 처리가 서버에 집중됨
- Port : 16bit로 65536개 사용가능, 1-1024는 시스템포트로 사용

## Class59

- ```socket(네트워크 주소 쳬계, 소켓 타입, 프로토콜)```
    - 네트워크 주소 체계 : IPv4(AF_INET), IPv6(AF_INET6)
    - 소켓 타입 : TCP(SOCK_STREAM), UDP(SOCK_DGRAM)
    - 프로토콜 : TCP(IPPROTO_TCP), UDP(IPPROTO_UDP)
- ```bind(소켓 변수, 서버 주소 구조체, 서버 주소 구조체의 크기)```
    - 서버 측의 소켓에 IP와 포트 번호를 할당해 네트워크 인터페이스와 묶일 수 있게 함
- ```listen(소켓 변수, 백 로그 큐의 크기)```
    - 클라이언트로부터 연결 요청을 기다림, 백 로그는 동시에 연결을 시도하는 최대 클라이언트 수를 의미
- ```connect(소켓 변수, 서버 주소 구조체, 서버 주소 구조체 크기)```
    - 클라이언트 측에서 서버에 연결을 요청
- ```accept(소켓 변수, 클라이언트 주소 구조체, 클라이언트 주소 구조체 크기)```
    - 서버 측에서 클라이언트의 연결을 수락함, 통신에 사용할 클라이언트의 소켓을 반환
- ```send(소켓 변수, 문자열 버퍼, 문자열 버퍼 크기, 플래그)```
    - 특정한 소켓으로 문자열 버퍼에 담긴 내용을 전송
- ```recv(소켓 변수, 문자열 버퍼, 문자열 버퍼 크기, 플래그)```
    - 데이터를 수신하여 특정 문자열 버퍼에 담음
- ```closesocket(소켓 변수)```
    - 열린 소켓을 닫음
- Winsock2
    - Windows Socket API의 준말로 네트워크 프로그래밍을 위한 라이브러리
    - ```WSAStartup()```, ```WSACleanup()```

## Class60

- C++ TCP Echo Program

## Class61

- GitHub

## Class62-64

- C++ Boost.Asio
    - 비동기 IO 프로그램을 포함해 고성능 네트워크 프로그램을 쉽게 구현할 수 있음
    - IO Service
        - 커널에서 발생한 입출력 이벤트를 dispatch 해주는 기능
    - Endpoint
        - 네트워크에 존재하는 특정한 컴퓨터에서 실행되고 있는 하나의 프로그램을 의미
        - 일반적으로 네트워크 통신 기능을 가지고 있는 모듈을 의미, IP 주소와 port번호 한 쌍을 종단점이라고 하기도 함
    - DNS(Domain Name Server)
        - Domain address를 IP address로 변환해주는 server
    - Query Class : domian address와 protocol을 이용해 DNS 질의문을 생성
    - Acceptor : server program이 IO service와 종단점을 이용해 client의 접속을 기다리게 해줌
    - Passive Socket : 연결 수립 요청을 기다리는 소켓을 의미, Acceptor를 통해 만들어질 수 있음
    - Active Socket : 다른 컴퓨터로 데이터를 보내거나 받기 위한 연결 수립 과정에서 사용되는 능동적인 소켓을 의미
    - Iterator : 여러 개의 IP로 여러 개의 종단점이 존재할 때, 개별 종단점에 접근할 때 사용
- C++ Boost.Asio 동기식 TCP 통신 예제

## Class65-70

- Visual C# .NET
- 오목 Server 구현

## Class71

- SSL(Secure Sockets Layer)
    - server와 client간의 패킷을 암호화하기 위한 protocol
    - 과정
        1. server가 client에 public key 정보를 포함한 certificate를 보냄
        2. client는 certificate를 통해 신뢰성을 검증
        3. cliet는 symmetric key를 생성하여 public key로 암호화한 후 server로 전송
        4. server와 client는 symmetric key를 이용해 통신
- symmetric key 암호화
    - server와 client가 하나의 key를 가지고 통신하는 방식
    - 속도가 빠르나 key가 노출되면 보안이 취약해지는 단점이 있음
- public key 암호화
    - server는 public key를 모두 공개하고, 각 client는 public key로 데이터를 암호화해 server에 전송함
    - public key로 암호화된 데이터는 server의 private key로만 해독가능
- Certificate
    - public key와 private key의 정보를 포함하는 인증 도구

## Class72-79

- OpenSSL
- AWS
- Ngrok
- Wireshark
- Packet Sender
- Decompiler
- 난독화
- 토큰 기반 인증
- SSL 인증서

## Class80-82

- Minimax Algorithm
- Alpha-Beta Pruning Algorithm

## Class83

- Balanced Tree
    - example : AVL Tree, Red-black Tree, B Tree, 2-3 Tree, 2-3-4 Tree, etc
- B Tree
    - 자식의 개수가 많아질수록 추가적으로 소모되는 메모리 용량이 많고, 빠르게 데이터에 접근할 가능성이 높음
    - 삽입 및 삭제 이후에도 균형 트리를 유지할 수 있음
    - 자식이 두 개인 이진트리의 단점을 보완
    - 매우 많은 데이터를 포함하는 디스크 기반 솔루션으로 설계됨
    - 규칙
        - 노드의 데이터 수가 최대 N이면, 자식의 수는 N+1
        - 각 노드의 데이터는 정렬된 상태
        - Leaf Node는 모두 같은 레벨에 있으므로 완전한 균형 트리 형태를 유지
        - 특정한 데이터릐 왼쪽 서브 트리는 해당 데이터보다 작고, 오른쪽 서브 트리는 해당 데이터보다 큼
        - Root Node가 자식을 가질 때는 최소한 2개 이상의 자식을 가짐
        - Root, Leaf Node를 제외한 Node는 최소한 {(차수(degree))/2개}의 올림만큼 자식을 가짐
        - 데이터에 중복이 없다고 가정

## Class84-90

- C#
    - .cs 파일만으로 전체 프로젝트가 구성됨
    - 메모리 해제를 GC(Garbage Collector)가 대신함
    - 기본 자료형도 객체 형태로 사용됨
    - C++에 비해 네트워크 라이브러리가 잘 지원됨
    - 인덱스를 벗어나는 경우 Exception을 뱉음
- Namespace
    - 이름 중복을 피하기 위한 이름 공간
    - 동일한 이름의 클래스를 분리된 공간에서 사용가능
- enum
- struct
    - class와 흡사한 형태이지만 상속은 할 수 없음
- class
    - C++과 기본적으로 비슷함
    - Method : 특정한 기능을 수행하는 함수, 앞문자가 대문자로 시작하는 것이 일반적
    - Field : 클래스의 내부 변수, 접근제한자 이용가능
- Generics
    - C++의 Template와 비슷하게 동작
    - int, float, double 등의 데이터 타입을 필요에 따라 적용할 수 있음
    - class, method, interface등에 type parameter를 붙여 구현할 수 있음
- virtual, override, abstract
- interface
    - abstract class와 유사
    - 기본적으로 member 변수를 사용할 수 없음
    - 다중 상속가능
    - 프로그램의 설계 목적으로 사용, 계층적인 구조가 아니더라도 같은 기능을 추가하고 싶을 때 사용
- .NET
    - 윈도우 응용 프로그램 개발 및 실행환경을 의미
    - C#이 동작할 수 있는 plaftform
    - C/C++에 비해 메모리 요구량이 많고 처리속도가 느림
    - .Net 응용 프로그램을 실행하기 위해서는 .Net Framework를 설치해야 함
- CIL(Common Language Runtime)
    - compiler가 Source Code를 변환한 Byte Code 형태인 CIL(Common Intermediate Language)을 읽어 OS가 실행시킬 수 있는 Native Code(기계어)로 변환함
    - .Net 가상 머신의 주요 구성품
    - '소프트웨어는 단 한 번만 작성해 만들어, 어디에서나 그대로 사용할 수 있도록 하자'