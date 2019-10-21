import time
from concurrent.futures import ThreadPoolExecutor
from urllib.request import urlopen

URL_LIST = ['https://google.com' for _ in range(1, 101)]

def url_request(url):
    res = urlopen(url)
    return res.status

def main():
    result = []
    for url in URL_LIST:
        res = urlopen(url)
        result.append(res.status)
    

start_ = time.time()
with ThreadPoolExecutor() as th:
    future = [th.submit(url_request, url) for url in URL_LIST]
end_ = time.time()
result_len = len(future)
success_count = 0
for i in future:
    if i.result() == 200:
        success_count += 1
        
print('상태 반환 리스트 갯수 : {}'.format(result_len))
print('요청 성공 : {}'.format(success_count))
print('요청 실패 : {}'.format(result_len - success_count))
print('time : {}'.format(end_ - start_))