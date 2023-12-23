from collections import Counter
import re

def solution(s):
    s = Counter(re.findall('\d+', s))
    data=[int(k) for k, v in sorted(s.items(), key=lambda x: x[1],reverse=True)]
    return data