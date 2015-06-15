#!/usr/bin/env ruby

EPS = 1e-7
class Cake
  attr_accessor :s, :w, :p
  def initialize(s, w)
    @s, @w, @p = s, w, w / s
  end
end
n, d = gets.split.map(&:to_i)
stk = gets.split.map(&:to_f)
wth = gets.split.map(&:to_f)
cake = stk.zip(wth).map { |s, w| Cake.new(s, w) }
ans = 0.0
cake.sort_by { |x| -x.p }.each do |c|
  used = c.s > d ? d : c.s
  ans += used * c.p
  d -= used
  break if d < EPS
end
puts "%.2f" % ans
