#!/usr/bin/env ruby

require 'thread'
q = [Queue.new, Queue.new]
n, m = gets.split.map(&:to_i)
t = []
(n+1).times { t << [] }
m.times do
  r, _, *c = gets.split.map(&:to_i)
  t[r].concat c
end
ans, cur, cnt = [], 0, 0
q[cur] << 1
while ! q[cur].empty?
  x = q[cur].pop
  if t[x].empty?
    cnt += 1
  else
    t[x].each { |i| q[1-cur] << i }
  end
  if q[cur].empty?
    ans << cnt
    cnt, cur = 0, 1 - cur
  end
end
puts ans * ' '
