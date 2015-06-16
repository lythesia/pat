#!/usr/bin/env ruby

def order(p, i, d)
  return if p.empty? or i.empty?
  len, root = p.length, p.last
  r = i.index root
  $lv[d] << root
  order(p[0...r], i[0...r], d + 1)
  order(p[r...(len-1)], i[(r+1)...len], d + 1)
end
n = gets.chomp.to_i
post = gets.split.map &:to_i
infix = gets.split.map &:to_i
$lv = Array.new(30) { Array.new }
order(post, infix, 0)
puts $lv.reduce(:+) * ' '
