#!/usr/bin/env ruby

require 'set'
SLIM = 60 * (17 - 8)
n, m, k, q = gets.split.map(&:to_i)
cap = n * m
win = Array.new 20, 0
ans = Array.new 1000, 0
queue = SortedSet.new
gets.split.map(&:to_i).each_with_index do |c, i|
  if i < cap
    p = i % n
    win[p], ans[i] = win[p] + c, (win[p] < SLIM ? win[p] + c : -1)
    queue << [win[p], p]
  else
    t = queue.first
    win[t[1]], ans[i] = win[t[1]] + c, (win[t[1]] < SLIM ? win[t[1]] + c : -1)
    # queue << [win[t[1]], t[1]]; queue.delete t  # 97 ms
    queue = queue.drop(1) << [win[t[1]], t[1]]    # 23 ms
  end
end
gets.split.map(&:to_i).each do |c|
  ans[c-1] < 0 ? puts("Sorry") : puts("%02d:%02d" % [ans[c-1] / 60 + 8, ans[c-1] % 60])
end
