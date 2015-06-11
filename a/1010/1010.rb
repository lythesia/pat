#!/usr/bin/env ruby

d = ('0'..'9').zip(0..9).flatten
c = ('a'..'z').zip(10..35).flatten
$h = Hash[*(d+c)]

def conv(s, r)
  s.chars.inject(0) do |acc, c|
    acc = acc * r + $h[c]
  end
end

n1, n2, tag, radix = gets.chomp.split
n1 ,n2 = n2, n1 if tag != "1"
fnd = false
n = conv(n1, radix.to_i)
l, r, m = n2.chars.map { |c| $h[c] }.max + 1, n + 1, 0
while l <= r do
  m = (l + r) / 2
  t = conv(n2, m)
  if t > n
    r = m - 1
  elsif t < n
    l = m + 1
  else
    fnd = true
    break
  end
end
fnd ? puts(m): puts("Impossible")
