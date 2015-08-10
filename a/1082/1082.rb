#!/usr/bin/env ruby

Digit = ['ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu']
Unit  = [nil, 'Shi', 'Bai', 'Qian', 'Yi']

def chs(n)
  ans = []
  d = 0
  while n > 0
    x = n % 10
    if x == 0
      ans << Digit[x] if (not ans.empty?) && ans.last != 'ling'
    else
      ans << Unit[d] if d > 0
      ans << Digit[x]
    end
    n /= 10; d += 1
  end
  ans
end
n = gets.to_i
neg, n = true, -n if n < 0
a, b = n % 10000, n / 10000
ans = []
ans += chs(a) if a > 0
if b > 0
  ans << 'ling' if a < 1000
  ans << 'Wan'
  ans += chs(b)
end
if ans.empty?
  ans << 'ling'
else
  ans << 'Fu' if neg
end
puts ans.reverse * ' '
