#!/usr/bin/env ruby

class Sign
  attr_accessor :id, :time
  def initialize(id, time)
    @id = id
    @time = time.split(':').map(&:to_i)
  end
end
s = []
m = gets.chomp.to_i
m.times do
  id, t1, t2 = gets.chomp.split
  s << Sign.new(id, t1) << Sign.new(id, t2)
end
ans = s.minmax_by { |x| x.time }
puts ans.map(&:id) * ' '
