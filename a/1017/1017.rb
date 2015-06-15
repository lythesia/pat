#!/usr/bin/env ruby

# case 5 TLE
require 'set'
class Cust
  attr_accessor :time, :wait
  def initialize(s)
    t = s[0].split(":").map(&:to_i)
    @time = t[0] * 3600 + t[1] * 60 + t[2]
    @wait = s[1].to_i * 60
  end
end
OPEN, CLOSE = 8 * 3600, 17 * 3600
n, k = gets.split.map(&:to_i)
c = []
n.times do
  s = gets.chomp.split
  c << Cust.new(s)
end
q = SortedSet.new
ans = []
0.upto(k-1) { |i| q << [OPEN, i] }
c.sort_by { |x| x.time }.each do |x|
  break if x.time > CLOSE
  t = q.first
  ans << (x.time < t[0] ? t[0] - x.time : 0)
  q = q.delete(t) << [[x.time, t[0]].max + x.wait, t[1]]
end
puts (ans.reduce(:+) / 60.0 / ans.length).round(1)
