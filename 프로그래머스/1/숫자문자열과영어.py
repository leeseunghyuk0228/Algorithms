s="one4seveneight"
print('처음s: ',s)
trans={'zero': '0',
       'one' : '1',
       'two' : '2',
       'three': '3',
       'four' : '4',
       'five' : '5',
       'six' : '6',
       'seven' : '7',
       'eight' : '8',
       'nine' : '9',
       'ten' : '10'}
for eng in trans.keys():
    s=s.replace(eng,trans[eng])
print('변환s: ',s)