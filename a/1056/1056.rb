#!/usr/bin/env ruby

np, ng = gets.split.map &:to_i
m = gets.split.map &:to_i
p = gets.split.map &:to_i
r = Array.new(np, 0)
while true do
  q = []
  nxt = (p.size + ng - 1) / ng
  index = 0
  p.each_slice(ng) do |g|
    index = g.max_by { |x| m[x] }
    q << index
    r[index] -= 1
  end
  r.map! { |x| x == 0 ? nxt + 1 : (x < 0 ? 0 : x) }
  p = q
  if p.size == 1
    r[index] = 1
    break
  end
end
puts r * ' '
