#!/usr/bin/env ruby

# case 6 TLE
class Stu
  attr_accessor :id, :name, :grade
  def initialize(s)
    @id, @name = s[0, 2]
    @grade = s[2].to_i
  end
  def to_s
    "#{@id} #{@name} #{@grade}"
  end
end
st = []
n, c = gets.split.map &:to_i
n.times { st << Stu.new(gets.chomp.split) }
case c
when 1
  st.sort_by! { |x| x.id }
when 2
  st.sort_by! { |x| [x.name, x.id] }
when 3
  st.sort_by! { |x| [x.grade, x.id] }
end
puts st
