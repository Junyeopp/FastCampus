NOTE for Python and Web
=====

![capture](/img/cap1.PNG)

## Class1-3

- Python
    - 인터프리터
    - 동적타이핑

## Class4-10

- ```split()```
- ```join()```
- ```format()```
- list : ```[]```, ```list()```
- tuple : ```()```, ```tuple()```
- ```append()```
- ```extend()```
- ```insert()```
- ```remove()```
- ```del```
- ```len()```
- ```count()```
- ```index()```
- ```sort()```
- dictionary : ```{}```, ```dict()```
    - ```.keys()```
    - ```.values()```
    - ```.items()```
    - ```.clear()```
    - ```.get()```
- ```update()```
- set : ```{}```, ```set()```
    - ```|, &, -, ^```

## Class11-14

- ```for var in iterable obj :```
    - ```enumerate()```
- ```while condition :```
- ```
  if condition :
  else :
  ```
- ```
  if condition :
  elif condition :
  else :
  ```
- ```pass()```
- ```eval()```

## Class15

- list comprehension : ```[expression for item in iterable object]```
- set comprehension : ```[expression for item in iterable object]```
- dict comprehension : ```{key:value for key,value in zip(iter1,iter2)}```

## Class16-28

- iterator
    - ```for```문이 순회하는 동안 내부에서 임시로 iterable object를 iterator로 자동변환 해줌
    - ```iter()```
- generator : a function which returns an iterator, 메모리 효율적, lazy evaluation
    - ```(expression for item in iterable ebject)```
- function : return이 없으면 기본적으로 None을 반환함
    - ```*args```, tuple type
    - ```**kwargs```, keywords arguments, dictionary type
    - docstring : ```.__doc__```
    - ```
      def function():
      """
      blabla
      """
      ```
- lambda expression
    - ```lambda var1, var2, var3... : expression```
    - ```map```, ```filter```, ```reduce```, ```sort``` 등과 함께 주로 쓰임
    - ```map``` : generator
- class
    - attribute : class 내부 variable
    - method : class 내부 function
    - ```dir()```
- ```open()```
    - ```with open() as f:```
- ```
  try:
  except some_error as error_msg_var:
  else:, finally:
  ```

## Class 29-31

- GIT

## Class 32-33

- GIL(Global Interpreter Lock)
- ```
  from multiprocessing import Process:
  proc1 = Process(target=실행할 함수,args=(함수에 전달할 인자))
  proc1.start()
  proc1.join()
  ```
- ```
  from threading import Thread:
  th1 = Thread(target=실행할 함수,args=(함수에 전달할 인자))
  th1.start()
  th1.join()
  ```

## Class 34

- ```_async```

## Class 35-37

- Crawling
    - robots.txt

## Class 38-40

- POSTMAN
- API
    - REST : URL & Method
        - POST, GET, PUT, DELETE
    - SOAP
    - Graphql
- django
    - https://docs.djangoproject.com/ko/2.2/
    - https://tutorial.djangogirls.org/ko/