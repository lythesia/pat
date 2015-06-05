#!/usr/bin/env ruby

## last case TLE

class Stu
  attr_accessor :id, :pt, :rk
  def initialize(id, pt)
    @id = id
    @pt = pt.reduce(:+), *pt 
  end
end
CS = "ACME"

st = []
n, m = gets.split.map(&:to_i)
n.times do
  id, *pt = gets.chomp.split
  st << Stu.new(id, pt.map(&:to_i))
end
m.times do
  sid = gets.chomp
  stu = st.find { |s| s.id == sid }
  if stu
    rk = [1,1,1,1]
    st.each do |s|
      4.times { |i| rk[i] += 1 if s.pt[i] > stu.pt[i] }
    end
    minrk, minri = rk.each_with_index.min
    puts "#{minrk} #{CS[minri]}"
  else
    puts "N/A"
  end
end
