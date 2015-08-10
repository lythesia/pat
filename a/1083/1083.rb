#!/usr/bin/env ruby

class Stu
  attr_accessor :n, :id, :g
  def initialize(s)
    @n, @id, @g = s.split
    @g = @g.to_i
  end

  def to_s
    "#{@n} #{@id}"
  end
end
stu = []
n = gets.to_i
n.times { stu << Stu.new(gets) }
stu.sort_by! { |x| -x.g }
a, b = gets.split.map &:to_i
a, b = b, a if a > b
ans = stu.select { |x| x.g >= a && x.g <= b }
ans << 'NONE' if ans.empty?
puts ans
