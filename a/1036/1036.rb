#!/usr/bin/env ruby 
class Stu
  attr_accessor :name, :sex, :id, :grade
  def initialize(s)
    @name, @sex, @id, @grade = s.split
    @grade = @grade.to_i
  end
  def to_s
    "#{@name} #{@id}"
  end
end
n = gets.chomp.to_i
male, female = [], []
n.times do
  st = Stu.new gets.chomp
  st.sex == 'M' ? male << st : female << st
end
h = female.max_by { |x| x.grade }
l = male.min_by { |x| x.grade }
h.nil? ? puts('Absent') : puts(h)
l.nil? ? puts('Absent') : puts(l)
h.nil? || l.nil? ? puts('NA') : puts(h.grade - l.grade)
