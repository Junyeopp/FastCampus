class test:
    _data = 10
    @property
    def data(self):
        return self._data
    @data.setter
    def data(self, data):
        self._data = data
    
t = test()
t.data = 11
print(t.data)