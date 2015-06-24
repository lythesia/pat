#!/usr/bin/env ruby

# case 3 TLE
class Testee
  attr_accessor :loc, :no, :mark, :rnk
  def initialize(i, s)
    @loc = i
    @no = s[0]
    @mark = s[1].to_i
    @rnk = [0, 0]
  end

  def to_s
    "#{@no} #{@rnk[1]} #{@loc} #{@rnk[0]}"
  end
end

def rnk(lst, r)
  lst.sort_by! { |x| [-x.mark, x.no] }
  lst.first.rnk[r] = 1
  lst.zip(1..lst.length).each_cons(2) do |(x, i), (y, j)|
    y.rnk[r] = (y.mark == x.mark ? x.rnk[r] : j)
  end
end

n = gets.chomp.to_i
fin, tot = [], 0
n.times do |i|
  k = gets.chomp.to_i
  loc = []
  k.times do
    t = Testee.new(i + 1, gets.chomp.split)
    loc << t
    fin << t
    tot += 1
  end
  rnk loc, 0
end
rnk fin, 1
puts tot
fin.each { |x| puts x }
