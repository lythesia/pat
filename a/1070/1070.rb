#!/usr/bin/env ruby

class Cake
  attr_accessor :a, :p, :w
  def initialize(a, p)
    @a = a; @p = p; @w = @p / @a
  end
end
n, d = gets.chomp.split
n = n.to_i; d = d.to_f
a = gets.split.map &:to_f
p = gets.split.map &:to_f
c = []
n.times { |i| c << Cake.new(a[i], p[i]) }
c.sort! { |x, y| y.w <=> x.w }
ans = 0.0
c.each do |x|
  if d >= x.a
    ans += x.p; d -= x.a
  else
    ans += d * x.w
    break
  end
end
printf "%.2f\n", ans
