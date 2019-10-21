import time
from urllib.request import urlopen

URL_LIST = ['https://google.com' for _ in range(1, 101)]

def main():
    result = []
    for url in URL_LIST:
        res = urlopen(url)
        result.append(res.status)
    result_len = len(result)
    success_count = result.count(200)
    print('상태 반환 리스트 갯수 : {}'.format(result_len))
    print('요청 성공 : {}'.format(success_count))
    print('요청 실패 : {}'.format(result_len - success_count))

start_ = time.time()
main()
end_ = time.time()
print('time : {}'.format(end_ - start_))