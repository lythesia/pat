#!/usr/bin/env ruby

# case 4 TLE
class Edge
  attr_accessor :x, :y
  def initialize(a)
    @x, @y = *a
  end
end

def fnd(f, x)
  f[x] == x ? x : (f[x] = fnd(f, f[x]))
end

def mrg(f, x, y)
  fx, fy = fnd(f, x), fnd(f, y)
  f[fy] = fx if fx != fy
end

n, m, k = gets.split.map(&:to_i)
e = []
m.times { e << Edge.new(gets.split.map(&:to_i)) }
gets.split.map(&:to_i).each do |c|
  f = (0..n).to_a
  e.each { |i| mrg(f, i.x, i.y) if i.x != c and i.y != c }
  ans = 0
  (1..n).each { |i| ans += 1 if f[i] == i }
  puts "#{ans - 2}"
end
