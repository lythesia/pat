#!/usr/bin/env ruby

# case 2 exception (maybe memory-related?)
# case 3-4: TLE
# -cl, -tot, -moral, +id
class Stu
  attr_accessor :id, :m, :i
  def initialize(id, m, i)
    @id, @m, @i = id, m, i
  end
end
rk, cnt = [], 0
4.times { rk << [] }
n, l, h = gets.split.map(&:to_i)
n.times do
  id, m, i = gets.split.map(&:to_i)
  if m >= l and i >= l
    cnt += 1
    tot = m + i
    stu = Stu.new id, m, i
    if m >= h and i >= h
      rk[0] << stu
    elsif m >= h
      rk[1] << stu
    elsif m >= i and i >= l
      rk[2] << stu
    else
      rk[3] << stu
    end
  end
end
puts cnt
rk.each do |c|
  c.sort! do |a, b|
    if a.m + a.i != b.m + b.i
      b.m + b.i <=> a.m + a.i
    elsif a.m != b.m
      b.m <=> a.m
    else
      a.id <=> b.id
    end
  end
  c.each { |x| printf "%08d %d %d\n" % [x.id, x.m, x.i] }
end
