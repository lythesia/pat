#!/usr/bin/env ruby

class Stu
  attr_accessor :name, :id, :pt
  def initialize(a)
    @name = a[0]
    @id   = a[1]
    @pt   = a[2].to_i
  end
end

n = gets.chomp.to_i
st = []
n.times { st << Stu.new(gets.chomp.split) }
a, b = st.minmax_by { |x| x.pt }
puts "#{b.name} #{b.id}"
puts "#{a.name} #{a.id}"
